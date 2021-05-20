/*
   +----------------------------------------------------------------------+
   | PHP Version 5 / Imagick											  |
   +----------------------------------------------------------------------+
   | Copyright (c) 2006-2013 Mikko Koppanen, Scott MacVicar				  |
   | ImageMagick (c) ImageMagick Studio LLC								  |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,	  |
   | that is bundled with this package in the file LICENSE, and is		  |
   | available through the world-wide-web at the following url:			  |
   | http://www.php.net/license/3_01.txt								  |
   | If you did not receive a copy of the PHP license and are unable to	  |
   | obtain it through the world-wide-web, please send a note to		  |
   | license@php.net so we can mail you a copy immediately.				  |
   +----------------------------------------------------------------------+
   | Author: Mikko Kopppanen <mkoppanen@php.net>						  |
   |		 Scott MacVicar <scottmac@php.net>							  |
   +----------------------------------------------------------------------+
*/

#include "php_imagick.h"
#include "php_imagick_defs.h"
#include "php_imagick_macros.h"
#include "php_imagick_helpers.h"

MagickBooleanType php_imagick_progress_monitor(const char *text, const MagickOffsetType offset, const MagickSizeType span, void *client_data)
{
	FILE *fp;
	php_imagick_object *intern = (php_imagick_object *)client_data;

	if (!intern) {
		return MagickFalse;
	}

	if (!intern->progress_monitor_name) {
		return MagickFalse;
	}

	fp = fopen(intern->progress_monitor_name, "a+");

	if (!fp) {
		return MagickFalse;
	}

	fprintf(fp, "text: %s, offset: %lld, span: %lld\n", text, offset, span);
	fclose(fp);
	return MagickTrue;
}

void php_imagick_cleanup_progress_callback(php_imagick_callback* progress_callback TSRMLS_DC) {

	if (progress_callback) {
		if (progress_callback->previous_callback) {
			php_imagick_cleanup_progress_callback(progress_callback->previous_callback TSRMLS_CC);
			efree(progress_callback->previous_callback);
		}

#ifdef ZEND_ENGINE_3
		zval_ptr_dtor(&progress_callback->user_callback);
#else
		zval_ptr_dtor(&progress_callback->user_callback);
#endif
	}
}

MagickBooleanType php_imagick_progress_monitor_callable(const char *text, const MagickOffsetType offset, const MagickSizeType span, void *userData)
{
	int error;
	zend_fcall_info fci;
	zend_fcall_info_cache fci_cache;

#ifdef ZEND_ENGINE_3
	zval zargs[2];
	zval retval;
#else
	zval **zargs[2];
	zval *retval_ptr;
#endif

	//We can get the data both via the passed param and via
	//IMAGICK_G(progress_callback) - this should be quicker
	php_imagick_callback *callback = (php_imagick_callback*)userData;

	// This suppresses an 'unused parameter' warning.
	// We could maybe use text.
	(void)text;

#if defined(ZEND_ENGINE_3) && defined(ZTS)
	if( NULL == tsrm_get_ls_cache() ) {
		return MagickTrue;
	}
#endif

#ifndef ZEND_ENGINE_3
	TSRMLS_FETCH_FROM_CTX(callback->thread_ctx);
#endif
	fci_cache = empty_fcall_info_cache;

	fci.size = sizeof(fci);

#if PHP_VERSION_ID >= 80000
	fci.named_params = NULL;
#endif

#if PHP_VERSION_ID < 70100
	fci.function_table = EG(function_table);
#endif
#ifdef ZEND_ENGINE_3
	fci.object = NULL;
	//fci.function_name = *callback->user_callback;
	ZVAL_COPY_VALUE(&fci.function_name, &callback->user_callback);
	fci.retval = &retval;
#else
	retval_ptr = NULL;
	fci.object_ptr = NULL;
	fci.function_name = callback->user_callback;
	fci.retval_ptr_ptr = &retval_ptr;
#endif
	fci.param_count = 2;
	fci.params = zargs;
#if PHP_VERSION_ID < 80000
	fci.no_separation = 0;
#endif
#if PHP_VERSION_ID < 70100
	fci.symbol_table = NULL;
#endif

#ifdef ZEND_ENGINE_3
	ZVAL_LONG(&zargs[0], offset);
    ZVAL_LONG(&zargs[1], span);
#else
	zargs[0] = emalloc(sizeof(zval *));
	MAKE_STD_ZVAL(*zargs[0]);
	ZVAL_LONG(*zargs[0], offset);

	zargs[1] = emalloc(sizeof(zval *));
	MAKE_STD_ZVAL(*zargs[1]);
	ZVAL_LONG(*zargs[1], span);
#endif

	error = zend_call_function(&fci, &fci_cache TSRMLS_CC);

	if (error == FAILURE) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "An error occurred while invoking the callback");
		//Abort processing as user callback is no longer callable
		return MagickFalse;
	}
#ifdef ZEND_ENGINE_3
	if (Z_TYPE(retval) == IS_FALSE) {
		//User returned false - tell Imagick to abort processing.
		return MagickFalse;
	}
#else
	zval_ptr_dtor(zargs[0]);
	zval_ptr_dtor(zargs[1]);

	if (retval_ptr) {
		if (Z_TYPE_P(retval_ptr) == IS_BOOL) {
			if (Z_LVAL_P(retval_ptr) == 0) {
				//User returned false - tell Imagick to abort processing.
				return MagickFalse;
			}
		}
	}
#endif

	return MagickTrue;
}

/* This is not universally safe to use, but is safe enough for values that will 
   be encountered for image dimensions.
*/
static inline double im_round_helper(double value) {
	if (value >= 0.0) {
		// Prevent zero width/height images
		if (value < 1) {
			return 1;
		}
		return floor(value + 0.5);
	} else {
		return ceil(value - 0.5);
	}
}


zend_bool php_imagick_thumbnail_dimensions(MagickWand *magick_wand, zend_bool bestfit, im_long desired_width, im_long desired_height, im_long *new_width, im_long *new_height, zend_bool legacy)
{
	im_long orig_width, orig_height;

	orig_width  = MagickGetImageWidth(magick_wand);
	orig_height = MagickGetImageHeight(magick_wand);

	if ((orig_width == desired_width) && (orig_height == desired_height)) {
		*new_width  = desired_width;
		*new_height = desired_height;
		return 1;
	}

	if (bestfit) {
		double ratio_x, ratio_y;

		if (desired_width <= 0 || desired_height <= 0) {
			return 0;
		}

		ratio_x = (double) desired_width  / (double) orig_width;
		ratio_y = (double) desired_height / (double) orig_height;

		//in the case of square images there should be no rounding error
		if (ratio_x == ratio_y) {
			*new_width  = desired_width;
			*new_height = desired_height;
		} else if (ratio_x < ratio_y) {
			*new_width  = desired_width;
			if (legacy) {
				*new_height = ratio_x * ((double) orig_height);
			}
			else {
				*new_height = im_round_helper(ratio_x * ((double) orig_height));
			}
		} else {
			*new_height = desired_height;
			if (legacy) {
				*new_width  = ratio_y * ((double) orig_width);
			}
			else {
				*new_width  = im_round_helper(ratio_y * ((double) orig_width));
			}
		}
		*new_width  = (*new_width < 1)  ? 1 : *new_width;
		*new_height = (*new_height < 1) ? 1 : *new_height;

	} else {
		double ratio;

		if (desired_width <= 0 && desired_height <= 0) {
			return 0;
		}

		if (desired_width <= 0 || desired_height <= 0) {
			if (desired_width <= 0) {
				ratio       = (double) orig_height / (double) desired_height;
				if (legacy) {
					*new_width  = ((double) orig_width) / ratio;
				}
				else {
					*new_width  = im_round_helper(((double) orig_width) / ratio);
				}
				*new_height = desired_height;
			} else {
				ratio       = (double) orig_width / (double) desired_width;
				if (legacy) {
					*new_height = ((double) orig_height) / ratio;
				}
				else {
					*new_height = im_round_helper(((double) orig_height) / ratio);
				}
				*new_width  = desired_width;
			}
		} else {
			*new_width  = desired_width;
			*new_height = desired_height;
		}
	}
	return 1;
}

zend_bool php_imagick_validate_map(const char *map TSRMLS_DC)
{
	zend_bool match;
	const char *p = map;
	char allow_map[] = { 'R', 'G', 'B',
						 'A', 'O', 'C',
						 'Y', 'M', 'K',
						 'I', 'P' };

	while (*p != '\0') {
		char *it = allow_map;
		match = 0;
		while(*it != '\0') {
			if (*(it++) == *p) {
				match = 1;
				break;
			}
		}
		if (!match) {
			return 0;
		}
		p++;
	}
	return 1;
}

double *php_imagick_zval_to_double_array(zval *param_array, im_long *num_elements TSRMLS_DC)
{
	double *double_array;
	long i = 0;

#ifdef ZEND_ENGINE_3
	zval *pzvalue;
#else
	zval **ppzval;
#endif

	*num_elements = zend_hash_num_elements(Z_ARRVAL_P(param_array));

	if (*num_elements == 0) {
		return NULL;
	}

	double_array = ecalloc(*num_elements, sizeof(double));

#ifdef ZEND_ENGINE_3
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(param_array), pzvalue) {
		ZVAL_DEREF(pzvalue);
		double_array[i] = zval_get_double(pzvalue);
		i++;
	} ZEND_HASH_FOREACH_END();
#else
	for (zend_hash_internal_pointer_reset(Z_ARRVAL_P(param_array));
			zend_hash_get_current_data(Z_ARRVAL_P(param_array), (void **) &ppzval) == SUCCESS;
			zend_hash_move_forward(Z_ARRVAL_P(param_array)), i++)
	{
		zval tmp_zval, *tmp_pzval;
		double value = 0.0;

		if (Z_TYPE_PP(ppzval) == IS_DOUBLE) {
			value = Z_DVAL_PP(ppzval);
		}
		else {
			tmp_zval = **ppzval;
			zval_copy_ctor(&tmp_zval);
			tmp_pzval = &tmp_zval;
			convert_to_double(tmp_pzval);

			value = Z_DVAL_P(tmp_pzval);
			zval_dtor (tmp_pzval);
		}
		double_array[i] = value;
	}
#endif
	return double_array;
}

im_long *php_imagick_zval_to_long_array(zval *param_array, im_long *num_elements TSRMLS_DC)
{
	im_long *long_array;
	im_long i = 0;

#ifdef ZEND_ENGINE_3
	zval *pzvalue;
#else
	zval **ppzval;
#endif

	*num_elements = zend_hash_num_elements(Z_ARRVAL_P(param_array));

	if (*num_elements == 0) {
		return NULL;
	}

	long_array = ecalloc(*num_elements, sizeof(im_long));

#ifdef ZEND_ENGINE_3
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(param_array), pzvalue) {
		ZVAL_DEREF(pzvalue);
		long_array[i] = zval_get_long(pzvalue);
		i++;
	} ZEND_HASH_FOREACH_END();
#else
	for (zend_hash_internal_pointer_reset(Z_ARRVAL_P(param_array));
			zend_hash_get_current_data(Z_ARRVAL_P(param_array), (void **) &ppzval) == SUCCESS;
			zend_hash_move_forward(Z_ARRVAL_P(param_array)), i++)
	{
		zval tmp_zval, *tmp_pzval;
 		im_long value = 0;

		if (Z_TYPE_PP(ppzval) == IS_DOUBLE) {
			value = Z_LVAL_PP(ppzval);
		}
		else {
			tmp_zval = **ppzval;
			zval_copy_ctor(&tmp_zval);
			tmp_pzval = &tmp_zval;
			convert_to_long(tmp_pzval);

			value = Z_LVAL_P(tmp_pzval);
			zval_dtor (tmp_pzval);
		}
		long_array[i] = value;
	}
#endif

	return long_array;
}

unsigned char *php_imagick_zval_to_char_array(zval *param_array, im_long *num_elements TSRMLS_DC)
{
	unsigned char *char_array;
	im_long i = 0;

#ifdef ZEND_ENGINE_3
	zval *pzvalue;
#else
	zval **ppzval;
#endif

	*num_elements = zend_hash_num_elements(Z_ARRVAL_P(param_array));

	if (*num_elements == 0) {
		return NULL;
	}

	char_array = ecalloc(*num_elements, sizeof(unsigned char));

#ifdef ZEND_ENGINE_3
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(param_array), pzvalue) {
		ZVAL_DEREF(pzvalue);
		char_array[i] = zval_get_long(pzvalue);
		i++;
	} ZEND_HASH_FOREACH_END();
#else
	for (zend_hash_internal_pointer_reset(Z_ARRVAL_P(param_array));
			zend_hash_get_current_data(Z_ARRVAL_P(param_array), (void **) &ppzval) == SUCCESS;
			zend_hash_move_forward(Z_ARRVAL_P(param_array)), i++)
	{
		zval tmp_zval, *tmp_pzval;
		im_long value = 0;
		if (Z_TYPE_PP(ppzval) == IS_DOUBLE) {
			value = Z_LVAL_PP(ppzval);
		}
		else {
			tmp_zval = **ppzval;
			zval_copy_ctor(&tmp_zval);
			tmp_pzval = &tmp_zval;
			convert_to_long(tmp_pzval);

			value = Z_LVAL_P(tmp_pzval);
			zval_dtor (tmp_pzval);
		}
		char_array[i] = value;
	}
#endif

	return char_array;
}

zend_bool php_imagick_check_font(char *font, int font_len TSRMLS_DC)
{
	zend_bool retval = 0;
	char **fonts;
	unsigned long i = 0;
	size_t num_fonts = 0;

	/* Check that user is only able to set a proper font */
	fonts = MagickQueryFonts("*", &num_fonts);

	for(i = 0 ; i < num_fonts ; i++) {
		/* Let's see if the font is among configured fonts */
		if (strncasecmp(fonts[i], font, font_len) == 0) {
			retval = 1;
			break;
		}
	}

	IMAGICK_FREE_MAGICK_MEMORY(fonts);
	return retval;
}

php_imagick_rw_result_t php_imagick_file_access_check (const char *filename TSRMLS_DC)
{
	if (strlen(filename) >= MAXPATHLEN)
		return IMAGICK_RW_FILENAME_TOO_LONG;

#if defined(CHECKUID_CHECK_FILE_AND_DIR)
	if (PG(safe_mode) && (!php_checkuid_ex(filename, NULL, CHECKUID_CHECK_FILE_AND_DIR, CHECKUID_NO_ERRORS)))
	 	return IMAGICK_RW_SAFE_MODE_ERROR;
#endif

	if (php_check_open_basedir_ex(filename, 0 TSRMLS_CC))
		return IMAGICK_RW_OPEN_BASEDIR_ERROR;

	if (VCWD_ACCESS(filename, F_OK) != 0)
		return IMAGICK_RW_PATH_DOES_NOT_EXIST;

	if (VCWD_ACCESS(filename, R_OK) != 0)
		return IMAGICK_RW_PERMISSION_DENIED;

	return IMAGICK_RW_OK;
}

static
void s_rw_fail_to_exception (php_imagick_rw_result_t rc, const char *filename TSRMLS_DC)
{
	switch (rc) {

		case IMAGICK_RW_SAFE_MODE_ERROR:
			zend_throw_exception_ex(php_imagick_exception_class_entry, 1 TSRMLS_CC, "Safe mode restricts user to read the file: %s", filename);
		break;

		case IMAGICK_RW_OPEN_BASEDIR_ERROR:
			zend_throw_exception_ex(php_imagick_exception_class_entry, 1 TSRMLS_CC, "open_basedir restriction in effect. File(%s) is not within the allowed path(s)", filename);
		break;

		case IMAGICK_RW_PERMISSION_DENIED:
			zend_throw_exception_ex(php_imagick_exception_class_entry, 1 TSRMLS_CC, "Permission denied to: %s", filename);
		break;

		case IMAGICK_RW_FILENAME_TOO_LONG:
			zend_throw_exception_ex(php_imagick_exception_class_entry, 1 TSRMLS_CC, "Filename too long: %s", filename);
		break;

		case IMAGICK_RW_PATH_DOES_NOT_EXIST:
			zend_throw_exception_ex(php_imagick_exception_class_entry, 1 TSRMLS_CC, "The path does not exist: %s", filename);
		break;

		case IMAGICK_RW_PATH_IS_DIR:
			zend_throw_exception_ex(php_imagick_exception_class_entry, 1 TSRMLS_CC, "The path is a directory: %s", filename);
		break;

		default:
			zend_throw_exception_ex(php_imagick_exception_class_entry, 1 TSRMLS_CC, "Unknown error");
		break;
	}
}

void php_imagick_rw_fail_to_exception (MagickWand *magick_wand, php_imagick_rw_result_t rc, const char *filename TSRMLS_DC)
{
	if (rc == IMAGICK_RW_UNDERLYING_LIBRARY) {
		php_imagick_convert_imagick_exception (magick_wand, "Failed to read the file" TSRMLS_CC);
		return;
	}
	s_rw_fail_to_exception (rc, filename TSRMLS_CC);
}

void php_imagick_imagickdraw_rw_fail_to_exception (DrawingWand *drawing_wand, php_imagick_rw_result_t rc, const char *filename TSRMLS_DC)
{
	if (rc == IMAGICK_RW_UNDERLYING_LIBRARY) {
		php_imagick_convert_imagickdraw_exception (drawing_wand, "Failed to read the file" TSRMLS_CC);
		return;
	}
	s_rw_fail_to_exception (rc, filename TSRMLS_CC);
}


PointInfo *php_imagick_zval_to_pointinfo_array(zval *coordinate_array, int *num_elements TSRMLS_DC)
{
	PointInfo *coordinates;
	long elements, sub_elements, i;
	HashTable *sub_array;

#ifdef ZEND_ENGINE_3
	zval *pzvalue;
#else
	HashTable *coords;
	zval **ppzval;
#endif

	i = 0;

	elements = zend_hash_num_elements(Z_ARRVAL_P(coordinate_array));

	if (elements < 1) {
		coordinates = (PointInfo *)NULL;
		*num_elements = 0;
		return coordinates;
	}

	*num_elements = elements;
	coordinates = emalloc(sizeof(PointInfo) * elements);

#ifdef ZEND_ENGINE_3
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(coordinate_array), pzvalue) {
		zval *pz_x, *pz_y;
		ZVAL_DEREF(pzvalue);

		/* If its something than array lets error here */
		if(Z_TYPE_P(pzvalue) != IS_ARRAY) {
			efree(coordinates);
			*num_elements = 0;
			return NULL;
		}

		/* Subarray should have two elements. X and Y */
		sub_elements = zend_hash_num_elements(Z_ARRVAL_P(pzvalue));

		/* Exactly two elements */
		if (sub_elements != 2) {
			efree(coordinates);
			*num_elements = 0;
			return NULL;
		}

		/* Subarray values */
		sub_array = Z_ARRVAL_P(pzvalue);

		/* Get X */
		if ((pz_x = zend_hash_str_find(sub_array, "x", sizeof("x")-1)) == NULL) {
			efree(coordinates);
			*num_elements = 0;
			return NULL;
		}

		/* Get Y */
		if ((pz_y = zend_hash_str_find(sub_array, "y", sizeof("y")-1)) == NULL) {
			efree(coordinates);
			*num_elements = 0;
			return NULL;
		}

		/* Assign X and Y */
		coordinates[i].x = zval_get_double(pz_x);
		coordinates[i].y = zval_get_double(pz_y);
		i++;
	} ZEND_HASH_FOREACH_END();
	
#else
	coords = Z_ARRVAL_P(coordinate_array);
	zend_hash_internal_pointer_reset_ex(coords, (HashPosition *) 0);

	for (i = 0, zend_hash_internal_pointer_reset(coords);
			zend_hash_get_current_data(coords, (void **) &ppzval) == SUCCESS;
			zend_hash_move_forward(coords), i++
	) {
		zval **ppz_x, **ppz_y;
		zval tmp_zx, *tmp_pzx, tmp_zy, *tmp_pzy;

		/* If its something than array lets error here */
		if(Z_TYPE_PP(ppzval) != IS_ARRAY) {
			efree(coordinates);
			*num_elements = 0;
			return NULL;
		}

		/* Subarray should have two elements. X and Y */
		sub_elements = zend_hash_num_elements(Z_ARRVAL_PP(ppzval));

		/* Exactly two elements */
		if (sub_elements != 2) {
			efree(coordinates);
			*num_elements = 0;
			return NULL;
		}

		/* Subarray values */
		sub_array = Z_ARRVAL_PP(ppzval);

		/* Get X */
		if (zend_hash_find(sub_array, "x", sizeof("x"), (void**)&ppz_x) == FAILURE) {
			efree(coordinates);
			*num_elements = 0;
			return NULL;
		}

		tmp_zx = **ppz_x;
		zval_copy_ctor(&tmp_zx);
		tmp_pzx = &tmp_zx;
		convert_to_double(tmp_pzx);

		/* Get Y */
		if (zend_hash_find(sub_array, "y", sizeof("y"), (void**)&ppz_y) == FAILURE) {
			efree(coordinates);
			*num_elements = 0;
			return NULL;
		}

		tmp_zy = **ppz_y;
		zval_copy_ctor(&tmp_zy);
		tmp_pzy = &tmp_zy;
		convert_to_double(tmp_pzy);

		/* Assign X and Y */
		coordinates[i].x = Z_DVAL(tmp_zx);
		coordinates[i].y = Z_DVAL(tmp_zy);
	}
#endif

	return coordinates;
}

void php_imagick_throw_exception (php_imagick_class_type_t type, const char *description TSRMLS_DC)
{
	int code;
	zend_class_entry *ce = NULL;

	switch (type) {
		case IMAGICK_CLASS:
		default:
			ce = php_imagick_exception_class_entry;
			code = 1;
		break;

		case IMAGICKDRAW_CLASS:
			ce = php_imagickdraw_exception_class_entry;
			code = 2;
		break;

		case IMAGICKPIXELITERATOR_CLASS:
			ce = php_imagickpixeliterator_exception_class_entry;
			code = 3;
		break;

		case IMAGICKPIXEL_CLASS:
			ce = php_imagickpixel_exception_class_entry;
			code = 4;
		break;
#ifdef IMAGICK_WITH_KERNEL
		case IMAGICKKERNEL_CLASS:
			ce = php_imagickkernel_exception_class_entry;
			code = 5;
		break;
#endif
	}
	zend_throw_exception(ce, description, code TSRMLS_CC);
}

static
void s_convert_exception (char *description, const char *default_message, long severity, int code TSRMLS_DC)
{
	// No description provided or empty one
	if (!description || (strlen (description) == 0)) {
		if (description) {
			description = MagickRelinquishMemory (description);
		}
		zend_throw_exception(php_imagick_exception_class_entry, default_message, code TSRMLS_CC);
		return;
	}
	zend_throw_exception(php_imagick_exception_class_entry, description, severity TSRMLS_CC);
	MagickRelinquishMemory (description);
}

/**
	Convert ImageMagick MagickWand exception to PHP exception
*/
void php_imagick_convert_imagick_exception (MagickWand *magick_wand, const char *default_message TSRMLS_DC)
{
	ExceptionType severity;
	char *description;

	description = MagickGetException(magick_wand, &severity);
	MagickClearException (magick_wand);

	s_convert_exception (description, default_message, severity, 1 TSRMLS_CC);
}

void php_imagick_convert_imagickdraw_exception (DrawingWand *drawing_wand, const char *default_message TSRMLS_DC)
{
	ExceptionType severity;
	char *description;

	description = DrawGetException(drawing_wand, &severity);
	DrawClearException (drawing_wand);

	s_convert_exception (description, default_message, severity, 2 TSRMLS_CC);
}

void php_imagick_convert_imagickpixeliterator_exception (PixelIterator *pixel_iterator, const char *default_message TSRMLS_DC)
{
	ExceptionType severity;
	char *description;

	description = PixelGetIteratorException(pixel_iterator, &severity);
	PixelClearIteratorException (pixel_iterator);

	s_convert_exception (description, default_message, severity, 3 TSRMLS_CC);
}

void php_imagick_convert_imagickpixel_exception (PixelWand *pixel_wand, const char *default_message TSRMLS_DC)
{
	ExceptionType severity;
	char *description;

	description = PixelGetException(pixel_wand, &severity);
	PixelClearException (pixel_wand);

	s_convert_exception (description, default_message, severity, 4 TSRMLS_CC);
}

PixelWand *php_imagick_zval_to_pixelwand (zval *param, php_imagick_class_type_t caller, zend_bool *allocated TSRMLS_DC)
{
	PixelWand *pixel_wand = NULL;
	*allocated = 0;

#ifdef ZEND_ENGINE_3
	ZVAL_DEREF(param);
#endif 
	if (Z_TYPE_P (param) == IS_LONG || Z_TYPE_P (param) == IS_DOUBLE) {
		zval var;
		var = *param;

		zval_copy_ctor(&var);
		convert_to_string(&var);
		param = &var;
	}

	switch (Z_TYPE_P(param)) {
		case IS_STRING:
		{
			pixel_wand = NewPixelWand();
			if (!pixel_wand) {
				zend_error(E_ERROR, "Failed to allocate PixelWand structure");
			}
			*allocated = 1;

			if (PixelSetColor (pixel_wand, Z_STRVAL_P(param)) == MagickFalse) {
				pixel_wand = DestroyPixelWand(pixel_wand);
				php_imagick_throw_exception (caller, "Unrecognized color string" TSRMLS_CC);
				return NULL;
			}
		}
		break;

		case IS_OBJECT:
			if (instanceof_function(Z_OBJCE_P(param), php_imagickpixel_sc_entry TSRMLS_CC)) {
				php_imagickpixel_object *intern = Z_IMAGICKPIXEL_P(param);
				pixel_wand = intern->pixel_wand;
			} else
				php_imagick_throw_exception(caller, "The parameter must be an instance of ImagickPixel or a string" TSRMLS_CC);
		break;

		default:
			php_imagick_throw_exception(caller, "Invalid color parameter provided" TSRMLS_CC);
	}
	return pixel_wand;
}

PixelWand *php_imagick_zval_to_opacity (zval *param, php_imagick_class_type_t caller, zend_bool *allocated TSRMLS_DC)
{
	PixelWand *pixel_wand = NULL;
	*allocated = 0;

#ifdef ZEND_ENGINE_3
	ZVAL_DEREF(param);
#endif
	if (Z_TYPE_P (param) == IS_STRING) {
		zval var;
		var = *param;

		zval_copy_ctor(&var);
		convert_to_double(&var);
		param = &var;
	}

	switch (Z_TYPE_P(param)) {
		case IS_LONG:
		case IS_DOUBLE:
		{
			pixel_wand = NewPixelWand();
			if (!pixel_wand) {
				zend_error(E_ERROR, "Failed to allocate PixelWand structure");
			}
#if MagickLibVersion >= 0x700
			//TOOD - this should be one minus? Or should we just make a BC break
			// and make users do it in user land?
			PixelSetAlpha(pixel_wand, Z_DVAL_P(param));
#else
			PixelSetOpacity(pixel_wand, Z_DVAL_P(param));
#endif
			*allocated = 1;
		}
		break;

		case IS_OBJECT:
			if (instanceof_function(Z_OBJCE_P(param), php_imagickpixel_sc_entry TSRMLS_CC)) {
				php_imagickpixel_object *intern = Z_IMAGICKPIXEL_P(param);
				pixel_wand = intern->pixel_wand;
			} else
				php_imagick_throw_exception(caller, "The parameter must be an instance of ImagickPixel or a string"  TSRMLS_CC);
		break;

		default:
			php_imagick_throw_exception(caller, "Invalid color parameter provided" TSRMLS_CC);
	}
	return pixel_wand;
}

/**
 * Changes the locale to IMAGICK_LC_NUMERIC_LOCALE if imagick.locale_fix is on
 * and returns the locale set before calling this function.
 * If locale is not changed, NULL is returned
 *
 */
char *php_imagick_set_locale (TSRMLS_D)
{
	char *current_locale;

	if (!IMAGICK_G(locale_fix))
		return NULL;

	current_locale = setlocale(LC_NUMERIC, NULL);
	if (current_locale != NULL) {
		if (strcmp (current_locale, IMAGICK_LC_NUMERIC_LOCALE) != 0) {
			setlocale (LC_NUMERIC, IMAGICK_LC_NUMERIC_LOCALE);
			return estrdup (current_locale);
		}
	}
	return NULL;
}

void php_imagick_restore_locale (const char *old_locale)
{
	if (!old_locale)
		return;

	if (strcmp (old_locale, IMAGICK_LC_NUMERIC_LOCALE) != 0)
		setlocale (LC_NUMERIC, old_locale);
}

PixelWand *php_imagick_clone_pixelwand (PixelWand *source)
{
#if MagickLibVersion >= 0x635
	return ClonePixelWand(source);
#else
	PixelWand *target = NewPixelWand ();
	if (!target)
		return NULL;

	PixelSetColorCount (target, PixelGetColorCount (source));
	PixelSetRed (target, PixelGetRed (source));
	PixelSetGreen (target, PixelGetGreen (source));
	PixelSetBlue (target, PixelGetBlue (source));
	PixelSetOpacity (target, PixelGetOpacity (source));
	PixelSetAlpha (target, PixelGetAlpha (source));

	return target;
#endif
}

void php_imagick_replace_magickwand (php_imagick_object *obj, MagickWand *new_wand)
{
	if (!obj->magick_wand)
		obj->magick_wand = new_wand;
	else {
		obj->magick_wand = DestroyMagickWand(obj->magick_wand);
		obj->magick_wand = new_wand;
	}
}

void php_imagick_replace_drawingwand (php_imagickdraw_object *obj, DrawingWand *new_wand)
{
	if (!obj->drawing_wand)
		obj->drawing_wand = new_wand;
	else {
		obj->drawing_wand = DestroyDrawingWand(obj->drawing_wand);
		obj->drawing_wand = new_wand;
	}
}

void php_imagick_replace_pixelwand (php_imagickpixel_object *obj, PixelWand *new_wand)
{
	if (obj->pixel_wand && obj->initialized_via_iterator != 1) {
		obj->pixel_wand = DestroyPixelWand(obj->pixel_wand);
		obj->pixel_wand = new_wand;
	} else
		obj->pixel_wand = new_wand;
}

zend_bool php_imagick_ensure_not_empty (MagickWand *magick_wand)
{
	if (MagickGetNumberImages(magick_wand) == 0) {
		TSRMLS_FETCH ();
		php_imagick_throw_exception (IMAGICK_CLASS, "Can not process empty Imagick object" TSRMLS_CC);
		return 0;
	}
	return 1;
}

zend_bool php_imagickpixel_ensure_not_null(PixelWand *pixel_wand)
{
	if (pixel_wand == NULL) {
		TSRMLS_FETCH ();
		php_imagick_throw_exception (IMAGICKPIXEL_CLASS, "Can not process empty ImagickPixel object" TSRMLS_CC);
		return 0;
	}
	return 1;
}

void php_imagick_initialize_constants(TSRMLS_D)
{
#define IMAGICK_REGISTER_CONST_LONG(const_name, value)\
	zend_declare_class_constant_long(php_imagick_sc_entry, const_name, sizeof(const_name)-1, (long)value TSRMLS_CC);

#define IMAGICK_REGISTER_CONST_STRING(const_name, value)\
	zend_declare_class_constant_string(php_imagick_sc_entry, const_name, sizeof(const_name)-1, value TSRMLS_CC);

	/* Constants defined in php_imagick.h */
	IMAGICK_REGISTER_CONST_LONG("COLOR_BLACK", PHP_IMAGICK_COLOR_BLACK);
	IMAGICK_REGISTER_CONST_LONG("COLOR_BLUE", PHP_IMAGICK_COLOR_BLUE);
	IMAGICK_REGISTER_CONST_LONG("COLOR_CYAN", PHP_IMAGICK_COLOR_CYAN);
	IMAGICK_REGISTER_CONST_LONG("COLOR_GREEN", PHP_IMAGICK_COLOR_GREEN);
	IMAGICK_REGISTER_CONST_LONG("COLOR_RED", PHP_IMAGICK_COLOR_RED);
	IMAGICK_REGISTER_CONST_LONG("COLOR_YELLOW", PHP_IMAGICK_COLOR_YELLOW);
	IMAGICK_REGISTER_CONST_LONG("COLOR_MAGENTA", PHP_IMAGICK_COLOR_MAGENTA);
#if MagickLibVersion < 0x700
	IMAGICK_REGISTER_CONST_LONG("COLOR_OPACITY", PHP_IMAGICK_COLOR_OPACITY);
#endif
	IMAGICK_REGISTER_CONST_LONG("COLOR_ALPHA", PHP_IMAGICK_COLOR_ALPHA);
	IMAGICK_REGISTER_CONST_LONG("COLOR_FUZZ", PHP_IMAGICK_COLOR_FUZZ);

	/* Returning the version as a constant string */
	IMAGICK_REGISTER_CONST_LONG("IMAGICK_EXTNUM", PHP_IMAGICK_EXTNUM);
	IMAGICK_REGISTER_CONST_STRING("IMAGICK_EXTVER", PHP_IMAGICK_VERSION);

#if defined(MagickQuantumRange)
	IMAGICK_REGISTER_CONST_LONG("QUANTUM_RANGE", atoi (MagickQuantumRange));
#endif

	/* Are we using PHP allocations */
#ifdef PHP_IMAGICK_ZEND_MM
	IMAGICK_REGISTER_CONST_LONG("USE_ZEND_MM", 1);
#else
	IMAGICK_REGISTER_CONST_LONG("USE_ZEND_MM", 0);
#endif

	/* ImageMagick defined constants */
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_DEFAULT", OverCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_UNDEFINED", UndefinedCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_NO", NoCompositeOp);
#if MagickLibVersion < 0x700
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_ADD", AddCompositeOp);
#endif
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_ATOP", AtopCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_BLEND", BlendCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_BUMPMAP", BumpmapCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_CLEAR", ClearCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_COLORBURN", ColorBurnCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_COLORDODGE", ColorDodgeCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_COLORIZE", ColorizeCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_COPYBLACK", CopyBlackCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_COPYBLUE", CopyBlueCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_COPY", CopyCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_COPYCYAN", CopyCyanCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_COPYGREEN", CopyGreenCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_COPYMAGENTA", CopyMagentaCompositeOp);
#if MagickLibVersion >= 0x700
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_COPYALPHA", CopyAlphaCompositeOp);
	//TOOD - is this semantically correct?
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_COPYOPACITY", CopyAlphaCompositeOp);
#else
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_COPYOPACITY", CopyOpacityCompositeOp);
#endif
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_COPYRED", CopyRedCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_COPYYELLOW", CopyYellowCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_DARKEN", DarkenCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_DSTATOP", DstAtopCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_DST", DstCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_DSTIN", DstInCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_DSTOUT", DstOutCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_DSTOVER", DstOverCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_DIFFERENCE", DifferenceCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_DISPLACE", DisplaceCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_DISSOLVE", DissolveCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_EXCLUSION", ExclusionCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_HARDLIGHT", HardLightCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_HUE", HueCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_IN", InCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_LIGHTEN", LightenCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_LUMINIZE", LuminizeCompositeOp);
#if MagickLibVersion < 0x700
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_MINUS", MinusCompositeOp);
#endif
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_MODULATE", ModulateCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_MULTIPLY", MultiplyCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_OUT", OutCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_OVER", OverCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_OVERLAY", OverlayCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_PLUS", PlusCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_REPLACE", ReplaceCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_SATURATE", SaturateCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_SCREEN", ScreenCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_SOFTLIGHT", SoftLightCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_SRCATOP", SrcAtopCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_SRC", SrcCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_SRCIN", SrcInCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_SRCOUT", SrcOutCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_SRCOVER", SrcOverCompositeOp);
#if MagickLibVersion < 0x700
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_SUBTRACT", SubtractCompositeOp);
#endif
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_THRESHOLD", ThresholdCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_XOR", XorCompositeOp);
#if MagickLibVersion >= 0x634
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_CHANGEMASK", ChangeMaskCompositeOp);
#endif
#if MagickLibVersion >= 0x636
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_LINEARLIGHT", LinearLightCompositeOp);
#if MagickLibVersion < 0x700
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_DIVIDE", DivideCompositeOp);
#endif
#endif
#if MagickLibVersion >= 0x654
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_DISTORT", DistortCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_BLUR", BlurCompositeOp);
#endif
#if MagickLibVersion >= 0x655
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_PEGTOPLIGHT", PegtopLightCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_VIVIDLIGHT", VividLightCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_PINLIGHT", PinLightCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_LINEARDODGE", LinearDodgeCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_LINEARBURN", LinearBurnCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_MATHEMATICS", MathematicsCompositeOp);
#endif
#if MagickLibVersion >= 0x662
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_MODULUSADD", ModulusAddCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_MODULUSSUBTRACT", ModulusSubtractCompositeOp);
#endif
#if MagickLibVersion >= 0x670
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_MINUSDST", MinusDstCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_DIVIDEDST", DivideDstCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_DIVIDESRC", DivideSrcCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_MINUSSRC", MinusSrcCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_DARKENINTENSITY", DarkenIntensityCompositeOp);
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_LIGHTENINTENSITY", LightenIntensityCompositeOp);
#endif
#if MagickLibVersion >= 0x690
	IMAGICK_REGISTER_CONST_LONG("COMPOSITE_HARDMIX", HardMixCompositeOp);
#endif

#if (MagickLibVersion >= 0x700 && MagickLibVersion >= 0x708) || (MagickLibVersion < 0x700 && MagickLibVersion >= 0x69A)
    IMAGICK_REGISTER_CONST_LONG("COMPOSITE_STEREO", StereoCompositeOp);
#endif

	IMAGICK_REGISTER_CONST_LONG("MONTAGEMODE_FRAME", FrameMode);
	IMAGICK_REGISTER_CONST_LONG("MONTAGEMODE_UNFRAME", UnframeMode);
	IMAGICK_REGISTER_CONST_LONG("MONTAGEMODE_CONCATENATE", ConcatenateMode);
	IMAGICK_REGISTER_CONST_LONG("STYLE_NORMAL", NormalStyle);
	IMAGICK_REGISTER_CONST_LONG("STYLE_ITALIC", ItalicStyle);
	IMAGICK_REGISTER_CONST_LONG("STYLE_OBLIQUE", ObliqueStyle);
	IMAGICK_REGISTER_CONST_LONG("STYLE_ANY", AnyStyle);
#if (MagickLibVersion >= 0x700 && MagickLibVersion >= 0x709) || (MagickLibVersion < 0x700 && MagickLibVersion >= 0x69B)
    IMAGICK_REGISTER_CONST_LONG("STYLE_BOLD", BoldStyle);
#endif

	IMAGICK_REGISTER_CONST_LONG("FILTER_UNDEFINED", UndefinedFilter);
	IMAGICK_REGISTER_CONST_LONG("FILTER_POINT", PointFilter);
	IMAGICK_REGISTER_CONST_LONG("FILTER_BOX", BoxFilter);
	IMAGICK_REGISTER_CONST_LONG("FILTER_TRIANGLE", TriangleFilter);
	IMAGICK_REGISTER_CONST_LONG("FILTER_HERMITE", HermiteFilter);
#if MagickLibVersion >= 0x701
	IMAGICK_REGISTER_CONST_LONG("FILTER_HANNING", HannFilter);
	IMAGICK_REGISTER_CONST_LONG("FILTER_HANN", HannFilter);
#else
	IMAGICK_REGISTER_CONST_LONG("FILTER_HANNING", HanningFilter);
#endif
	IMAGICK_REGISTER_CONST_LONG("FILTER_HAMMING", HammingFilter);
	IMAGICK_REGISTER_CONST_LONG("FILTER_BLACKMAN", BlackmanFilter);
	IMAGICK_REGISTER_CONST_LONG("FILTER_GAUSSIAN", GaussianFilter);
	IMAGICK_REGISTER_CONST_LONG("FILTER_QUADRATIC", QuadraticFilter);
	IMAGICK_REGISTER_CONST_LONG("FILTER_CUBIC", CubicFilter);
	IMAGICK_REGISTER_CONST_LONG("FILTER_CATROM", CatromFilter);
	IMAGICK_REGISTER_CONST_LONG("FILTER_MITCHELL", MitchellFilter);
	IMAGICK_REGISTER_CONST_LONG("FILTER_LANCZOS", LanczosFilter);
	IMAGICK_REGISTER_CONST_LONG("FILTER_BESSEL", BesselFilter);
	IMAGICK_REGISTER_CONST_LONG("FILTER_SINC", SincFilter);
#if MagickLibVersion >= 0x637
	IMAGICK_REGISTER_CONST_LONG("FILTER_KAISER", KaiserFilter);
#if MagickLibVersion >= 0x701
	IMAGICK_REGISTER_CONST_LONG("FILTER_WELSH", WelshFilter);
	IMAGICK_REGISTER_CONST_LONG("FILTER_WELCH", WelchFilter);
#else
	IMAGICK_REGISTER_CONST_LONG("FILTER_WELSH", WelshFilter);
#endif
	IMAGICK_REGISTER_CONST_LONG("FILTER_PARZEN", ParzenFilter);
	IMAGICK_REGISTER_CONST_LONG("FILTER_LAGRANGE", LagrangeFilter);
	IMAGICK_REGISTER_CONST_LONG("FILTER_SENTINEL", SentinelFilter);
#endif
#if MagickLibVersion >= 0x638
	IMAGICK_REGISTER_CONST_LONG("FILTER_BOHMAN", BohmanFilter);
	IMAGICK_REGISTER_CONST_LONG("FILTER_BARTLETT", BartlettFilter);
#endif
#if MagickLibVersion >= 0x666
	IMAGICK_REGISTER_CONST_LONG("FILTER_JINC", JincFilter);
	IMAGICK_REGISTER_CONST_LONG("FILTER_SINCFAST", SincFastFilter);
	IMAGICK_REGISTER_CONST_LONG("FILTER_ROBIDOUX", RobidouxFilter);
	IMAGICK_REGISTER_CONST_LONG("FILTER_LANCZOSSHARP", LanczosSharpFilter);
	IMAGICK_REGISTER_CONST_LONG("FILTER_LANCZOS2", Lanczos2Filter);
	IMAGICK_REGISTER_CONST_LONG("FILTER_LANCZOS2SHARP", Lanczos2SharpFilter);
#endif
#if MagickLibVersion >= 0x677
	IMAGICK_REGISTER_CONST_LONG("FILTER_ROBIDOUXSHARP", RobidouxSharpFilter);
	IMAGICK_REGISTER_CONST_LONG("FILTER_COSINE", CosineFilter);
#endif
#if MagickLibVersion >= 0x678
	IMAGICK_REGISTER_CONST_LONG("FILTER_SPLINE", SplineFilter);
#endif
#if MagickLibVersion >= 0x681
	IMAGICK_REGISTER_CONST_LONG("FILTER_LANCZOSRADIUS", LanczosRadiusFilter);
#endif
#if MagickLibVersion >= 0x707
	IMAGICK_REGISTER_CONST_LONG("FILTER_CUBIC_SPLINE", CubicSplineFilter);
#endif
	IMAGICK_REGISTER_CONST_LONG("IMGTYPE_UNDEFINED", UndefinedType);
	IMAGICK_REGISTER_CONST_LONG("IMGTYPE_BILEVEL", BilevelType);
	IMAGICK_REGISTER_CONST_LONG("IMGTYPE_GRAYSCALE", GrayscaleType);
#if MagickLibVersion < 0x700
	IMAGICK_REGISTER_CONST_LONG("IMGTYPE_GRAYSCALEMATTE", GrayscaleMatteType);
#else
	IMAGICK_REGISTER_CONST_LONG("IMGTYPE_GRAYSCALEALPHA", GrayscaleAlphaType);
	//@TODO - this is only here for legacy support
	IMAGICK_REGISTER_CONST_LONG("IMGTYPE_GRAYSCALEMATTE", GrayscaleAlphaType);
#endif
	IMAGICK_REGISTER_CONST_LONG("IMGTYPE_PALETTE",  PaletteType);
#if MagickLibVersion < 0x700
	IMAGICK_REGISTER_CONST_LONG("IMGTYPE_PALETTEMATTE", PaletteMatteType);
#else
	IMAGICK_REGISTER_CONST_LONG("IMGTYPE_PALETTEMATTE", PaletteAlphaType);
	//@TODO - this is only here for legacy support
	IMAGICK_REGISTER_CONST_LONG("IMGTYPE_PALETTEALPHA", PaletteAlphaType);
#endif
	IMAGICK_REGISTER_CONST_LONG("IMGTYPE_TRUECOLOR", TrueColorType);
#if MagickLibVersion < 0x700
	IMAGICK_REGISTER_CONST_LONG("IMGTYPE_TRUECOLORMATTE", TrueColorMatteType);
#else
	IMAGICK_REGISTER_CONST_LONG("IMGTYPE_TRUECOLORALPHA", TrueColorAlphaType);
	//@TODO - this is only here for legacy support
	IMAGICK_REGISTER_CONST_LONG("IMGTYPE_TRUECOLORMATTE", TrueColorAlphaType);
	
#endif
	IMAGICK_REGISTER_CONST_LONG("IMGTYPE_COLORSEPARATION", ColorSeparationType);
#if MagickLibVersion < 0x700
	IMAGICK_REGISTER_CONST_LONG("IMGTYPE_COLORSEPARATIONMATTE", ColorSeparationMatteType);
#else
	IMAGICK_REGISTER_CONST_LONG("IMGTYPE_COLORSEPARATIONALPHA", ColorSeparationAlphaType);
	//@TODO - this is only here for legacy support
	IMAGICK_REGISTER_CONST_LONG("IMGTYPE_COLORSEPARATIONMATTE", ColorSeparationAlphaType);
#endif
	IMAGICK_REGISTER_CONST_LONG("IMGTYPE_OPTIMIZE", OptimizeType);
#if MagickLibVersion < 0x700
	IMAGICK_REGISTER_CONST_LONG("IMGTYPE_PALETTEBILEVELMATTE", PaletteBilevelMatteType);
#else
	IMAGICK_REGISTER_CONST_LONG("IMGTYPE_PALETTEBILEVELALPHA", PaletteBilevelAlphaType);
	//@TODO - this is only here for legacy support
	IMAGICK_REGISTER_CONST_LONG("IMGTYPE_PALETTEBILEVELMATTE", PaletteBilevelAlphaType);
#endif
	IMAGICK_REGISTER_CONST_LONG("RESOLUTION_UNDEFINED", UndefinedResolution);
	IMAGICK_REGISTER_CONST_LONG("RESOLUTION_PIXELSPERINCH", PixelsPerInchResolution);
	IMAGICK_REGISTER_CONST_LONG("RESOLUTION_PIXELSPERCENTIMETER", PixelsPerCentimeterResolution);
	IMAGICK_REGISTER_CONST_LONG("COMPRESSION_UNDEFINED", UndefinedCompression);
	IMAGICK_REGISTER_CONST_LONG("COMPRESSION_NO", NoCompression);
	IMAGICK_REGISTER_CONST_LONG("COMPRESSION_BZIP", BZipCompression);
	IMAGICK_REGISTER_CONST_LONG("COMPRESSION_FAX", FaxCompression);
	IMAGICK_REGISTER_CONST_LONG("COMPRESSION_GROUP4", Group4Compression);
	IMAGICK_REGISTER_CONST_LONG("COMPRESSION_JPEG", JPEGCompression);
	IMAGICK_REGISTER_CONST_LONG("COMPRESSION_JPEG2000", JPEG2000Compression);
	IMAGICK_REGISTER_CONST_LONG("COMPRESSION_LOSSLESSJPEG", LosslessJPEGCompression);
	IMAGICK_REGISTER_CONST_LONG("COMPRESSION_LZW", LZWCompression);
	IMAGICK_REGISTER_CONST_LONG("COMPRESSION_RLE", RLECompression);
	IMAGICK_REGISTER_CONST_LONG("COMPRESSION_ZIP", ZipCompression);
#if MagickLibVersion > 0x639
	IMAGICK_REGISTER_CONST_LONG("COMPRESSION_DXT1", DXT1Compression);
	IMAGICK_REGISTER_CONST_LONG("COMPRESSION_DXT3", DXT3Compression);
	IMAGICK_REGISTER_CONST_LONG("COMPRESSION_DXT5", DXT5Compression);
#endif
#if MagickLibVersion >= 0x656
	IMAGICK_REGISTER_CONST_LONG("COMPRESSION_ZIPS", ZipSCompression);
	IMAGICK_REGISTER_CONST_LONG("COMPRESSION_PIZ", PizCompression);
	IMAGICK_REGISTER_CONST_LONG("COMPRESSION_PXR24", Pxr24Compression);
	IMAGICK_REGISTER_CONST_LONG("COMPRESSION_B44", B44Compression);
	IMAGICK_REGISTER_CONST_LONG("COMPRESSION_B44A", B44ACompression);
#endif
#if MagickLibVersion >= 0x667
	IMAGICK_REGISTER_CONST_LONG("COMPRESSION_LZMA", LZMACompression);
#endif
#if MagickLibVersion >= 0x670
	IMAGICK_REGISTER_CONST_LONG("COMPRESSION_JBIG1", JBIG1Compression);
	IMAGICK_REGISTER_CONST_LONG("COMPRESSION_JBIG2", JBIG2Compression);
#endif

#if MagickLibVersion >= 0x709
	IMAGICK_REGISTER_CONST_LONG("COMPRESSION_ZSTD", ZstdCompression);
	IMAGICK_REGISTER_CONST_LONG("COMPRESSION_WEBP", WebPCompression);
#endif

	IMAGICK_REGISTER_CONST_LONG("PAINT_POINT", PointMethod);
	IMAGICK_REGISTER_CONST_LONG("PAINT_REPLACE", ReplaceMethod);
	IMAGICK_REGISTER_CONST_LONG("PAINT_FLOODFILL", FloodfillMethod);
	IMAGICK_REGISTER_CONST_LONG("PAINT_FILLTOBORDER", FillToBorderMethod);
	IMAGICK_REGISTER_CONST_LONG("PAINT_RESET", ResetMethod);
	IMAGICK_REGISTER_CONST_LONG("GRAVITY_NORTHWEST", NorthWestGravity);
	IMAGICK_REGISTER_CONST_LONG("GRAVITY_NORTH", NorthGravity);
	IMAGICK_REGISTER_CONST_LONG("GRAVITY_NORTHEAST", NorthEastGravity);
	IMAGICK_REGISTER_CONST_LONG("GRAVITY_WEST", WestGravity);
	IMAGICK_REGISTER_CONST_LONG("GRAVITY_CENTER", CenterGravity);
	IMAGICK_REGISTER_CONST_LONG("GRAVITY_EAST", EastGravity);
	IMAGICK_REGISTER_CONST_LONG("GRAVITY_SOUTHWEST", SouthWestGravity);
	IMAGICK_REGISTER_CONST_LONG("GRAVITY_SOUTH", SouthGravity);
	IMAGICK_REGISTER_CONST_LONG("GRAVITY_SOUTHEAST", SouthEastGravity);
	IMAGICK_REGISTER_CONST_LONG("GRAVITY_FORGET", ForgetGravity);
#if MagickLibVersion < 0x700
	IMAGICK_REGISTER_CONST_LONG("GRAVITY_STATIC", StaticGravity);
#endif

	IMAGICK_REGISTER_CONST_LONG("STRETCH_NORMAL", NormalStretch);
	IMAGICK_REGISTER_CONST_LONG("STRETCH_ULTRACONDENSED", UltraCondensedStretch);
	IMAGICK_REGISTER_CONST_LONG("STRETCH_EXTRACONDENSED", ExtraCondensedStretch);
	IMAGICK_REGISTER_CONST_LONG("STRETCH_CONDENSED", CondensedStretch);
	IMAGICK_REGISTER_CONST_LONG("STRETCH_SEMICONDENSED", SemiCondensedStretch);
	IMAGICK_REGISTER_CONST_LONG("STRETCH_SEMIEXPANDED", SemiExpandedStretch);
	IMAGICK_REGISTER_CONST_LONG("STRETCH_EXPANDED", ExpandedStretch);
	IMAGICK_REGISTER_CONST_LONG("STRETCH_EXTRAEXPANDED", ExtraExpandedStretch);
	IMAGICK_REGISTER_CONST_LONG("STRETCH_ULTRAEXPANDED", UltraExpandedStretch);
	IMAGICK_REGISTER_CONST_LONG("STRETCH_ANY", AnyStretch);
	IMAGICK_REGISTER_CONST_LONG("ALIGN_UNDEFINED", UndefinedAlign);
	IMAGICK_REGISTER_CONST_LONG("ALIGN_LEFT", LeftAlign);
	IMAGICK_REGISTER_CONST_LONG("ALIGN_CENTER", CenterAlign);
	IMAGICK_REGISTER_CONST_LONG("ALIGN_RIGHT",	RightAlign);
	IMAGICK_REGISTER_CONST_LONG("DECORATION_NO", NoDecoration);
	IMAGICK_REGISTER_CONST_LONG("DECORATION_UNDERLINE", UnderlineDecoration);
	IMAGICK_REGISTER_CONST_LONG("DECORATION_OVERLINE", OverlineDecoration);
	IMAGICK_REGISTER_CONST_LONG("DECORATION_LINETROUGH", LineThroughDecoration); //TODO remove?
	IMAGICK_REGISTER_CONST_LONG("DECORATION_LINETHROUGH", LineThroughDecoration);
	IMAGICK_REGISTER_CONST_LONG("NOISE_UNIFORM", UniformNoise);
	IMAGICK_REGISTER_CONST_LONG("NOISE_GAUSSIAN", GaussianNoise);
	IMAGICK_REGISTER_CONST_LONG("NOISE_MULTIPLICATIVEGAUSSIAN", MultiplicativeGaussianNoise);
	IMAGICK_REGISTER_CONST_LONG("NOISE_IMPULSE", ImpulseNoise);
	IMAGICK_REGISTER_CONST_LONG("NOISE_LAPLACIAN", LaplacianNoise);
	IMAGICK_REGISTER_CONST_LONG("NOISE_POISSON", PoissonNoise);
#if MagickLibVersion > 0x635
	IMAGICK_REGISTER_CONST_LONG("NOISE_RANDOM", RandomNoise);
#endif
	IMAGICK_REGISTER_CONST_LONG("CHANNEL_UNDEFINED", UndefinedChannel);
	IMAGICK_REGISTER_CONST_LONG("CHANNEL_RED", RedChannel);
	IMAGICK_REGISTER_CONST_LONG("CHANNEL_GRAY", GrayChannel);
	IMAGICK_REGISTER_CONST_LONG("CHANNEL_CYAN", CyanChannel);
	IMAGICK_REGISTER_CONST_LONG("CHANNEL_GREEN", GreenChannel);
	IMAGICK_REGISTER_CONST_LONG("CHANNEL_MAGENTA", MagentaChannel);
	IMAGICK_REGISTER_CONST_LONG("CHANNEL_BLUE", BlueChannel);
	IMAGICK_REGISTER_CONST_LONG("CHANNEL_YELLOW", YellowChannel);
	IMAGICK_REGISTER_CONST_LONG("CHANNEL_ALPHA", AlphaChannel);
	IMAGICK_REGISTER_CONST_LONG("CHANNEL_OPACITY", OpacityChannel);
#if MagickLibVersion < 0x700
	IMAGICK_REGISTER_CONST_LONG("CHANNEL_MATTE", MatteChannel); /* deprecated, needs to throw E_STRICT if used */
#endif
	IMAGICK_REGISTER_CONST_LONG("CHANNEL_BLACK", BlackChannel);
	IMAGICK_REGISTER_CONST_LONG("CHANNEL_INDEX", IndexChannel);
	IMAGICK_REGISTER_CONST_LONG("CHANNEL_ALL", AllChannels);
	IMAGICK_REGISTER_CONST_LONG("CHANNEL_DEFAULT", DefaultChannels);
	IMAGICK_REGISTER_CONST_LONG("CHANNEL_RGBA", RedChannel | GreenChannel | BlueChannel | AlphaChannel);
#if MagickLibVersion >= 0x644
	IMAGICK_REGISTER_CONST_LONG("CHANNEL_TRUEALPHA", TrueAlphaChannel);
	IMAGICK_REGISTER_CONST_LONG("CHANNEL_RGBS", RGBChannels);
#endif
#if MagickLibVersion >= 0x655
	IMAGICK_REGISTER_CONST_LONG("CHANNEL_GRAY_CHANNELS", GrayChannels);
#endif
#if MagickLibVersion >= 0x656
	IMAGICK_REGISTER_CONST_LONG("CHANNEL_SYNC", SyncChannels);
#endif

#if MagickLibVersion >= 0x700
	IMAGICK_REGISTER_CONST_LONG("CHANNEL_READ_MASK", ReadMaskChannel);          /* Pixel is Not Readable? */
	IMAGICK_REGISTER_CONST_LONG("CHANNEL_WRITE_MASK", WriteMaskChannel);         /* Pixel is Write Protected? */
	IMAGICK_REGISTER_CONST_LONG("CHANNEL_META", MetaChannel);              /* ???? */
#endif

#if MagickLibVersion >= 0x708
	IMAGICK_REGISTER_CONST_LONG("CHANNEL_COMPOSITE_MASK", CompositeMaskChannel);              /* SVG mask */
#endif

#if MagickLibVersion >= 0x670
	IMAGICK_REGISTER_CONST_LONG("CHANNEL_COMPOSITES", CompositeChannels);
#endif
#if MagickLibVersion < 0x700
	IMAGICK_REGISTER_CONST_LONG("METRIC_UNDEFINED", UndefinedMetric);
#endif
	IMAGICK_REGISTER_CONST_LONG("METRIC_ABSOLUTEERRORMETRIC", AbsoluteErrorMetric);
	IMAGICK_REGISTER_CONST_LONG("METRIC_MEANABSOLUTEERROR", MeanAbsoluteErrorMetric);
#if MagickLibVersion < 0x700
	IMAGICK_REGISTER_CONST_LONG("METRIC_MEANERRORPERPIXELMETRIC", MeanErrorPerPixelMetric);
#else 
	IMAGICK_REGISTER_CONST_LONG("METRIC_MEANERRORPERPIXELMETRIC", MeanErrorPerPixelErrorMetric);
#endif

	IMAGICK_REGISTER_CONST_LONG("METRIC_MEANSQUAREERROR", MeanSquaredErrorMetric);
	IMAGICK_REGISTER_CONST_LONG("METRIC_PEAKABSOLUTEERROR", PeakAbsoluteErrorMetric);
#if MagickLibVersion < 0x700
	IMAGICK_REGISTER_CONST_LONG("METRIC_PEAKSIGNALTONOISERATIO", PeakSignalToNoiseRatioMetric);
#else
	IMAGICK_REGISTER_CONST_LONG("METRIC_PEAKSIGNALTONOISERATIO", PeakSignalToNoiseRatioErrorMetric);
#endif
	IMAGICK_REGISTER_CONST_LONG("METRIC_ROOTMEANSQUAREDERROR", RootMeanSquaredErrorMetric);
#if MagickLibVersion >= 0x687
	IMAGICK_REGISTER_CONST_LONG("METRIC_NORMALIZEDCROSSCORRELATIONERRORMETRIC", NormalizedCrossCorrelationErrorMetric);
	IMAGICK_REGISTER_CONST_LONG("METRIC_FUZZERROR", FuzzErrorMetric);
#endif
#if MagickLibVersion >= 0x690
	IMAGICK_REGISTER_CONST_LONG("METRIC_PERCEPTUALHASH_ERROR", PerceptualHashErrorMetric);
#endif

#if MagickLibVersion >= 0x707
	IMAGICK_REGISTER_CONST_LONG("METRIC_STRUCTURAL_SIMILARITY_ERROR", StructuralSimilarityErrorMetric);
	IMAGICK_REGISTER_CONST_LONG("METRIC_STRUCTURAL_DISSIMILARITY_ERROR", StructuralDissimilarityErrorMetric);
#endif

	IMAGICK_REGISTER_CONST_LONG("PIXEL_CHAR", CharPixel);
	IMAGICK_REGISTER_CONST_LONG("PIXEL_DOUBLE", DoublePixel);
	IMAGICK_REGISTER_CONST_LONG("PIXEL_FLOAT", FloatPixel);
#if MagickLibVersion < 0x700
	IMAGICK_REGISTER_CONST_LONG("PIXEL_INTEGER", IntegerPixel);
#endif
	IMAGICK_REGISTER_CONST_LONG("PIXEL_LONG", LongPixel);
	IMAGICK_REGISTER_CONST_LONG("PIXEL_QUANTUM", QuantumPixel);
	IMAGICK_REGISTER_CONST_LONG("PIXEL_SHORT", ShortPixel);
	//For now we deliberately DO NOT support the longlong pixel type.
	//64 bit integers and PHP do not play nicely.
	//IMAGICK_REGISTER_CONST_LONG("PIXEL_LONGLONG", ..);
	IMAGICK_REGISTER_CONST_LONG("EVALUATE_UNDEFINED", UndefinedEvaluateOperator);
	IMAGICK_REGISTER_CONST_LONG("EVALUATE_ADD", AddEvaluateOperator);
	IMAGICK_REGISTER_CONST_LONG("EVALUATE_AND", AndEvaluateOperator);
	IMAGICK_REGISTER_CONST_LONG("EVALUATE_DIVIDE", DivideEvaluateOperator);
	IMAGICK_REGISTER_CONST_LONG("EVALUATE_LEFTSHIFT", LeftShiftEvaluateOperator);
	IMAGICK_REGISTER_CONST_LONG("EVALUATE_MAX", MaxEvaluateOperator);
	IMAGICK_REGISTER_CONST_LONG("EVALUATE_MIN", MinEvaluateOperator);
	IMAGICK_REGISTER_CONST_LONG("EVALUATE_MULTIPLY", MultiplyEvaluateOperator);
	IMAGICK_REGISTER_CONST_LONG("EVALUATE_OR", OrEvaluateOperator);
	IMAGICK_REGISTER_CONST_LONG("EVALUATE_RIGHTSHIFT", RightShiftEvaluateOperator);
	IMAGICK_REGISTER_CONST_LONG("EVALUATE_SET", SetEvaluateOperator);
	IMAGICK_REGISTER_CONST_LONG("EVALUATE_SUBTRACT", SubtractEvaluateOperator);
	IMAGICK_REGISTER_CONST_LONG("EVALUATE_XOR", XorEvaluateOperator);
#if MagickLibVersion > 0x643
	IMAGICK_REGISTER_CONST_LONG("EVALUATE_POW", PowEvaluateOperator);
	IMAGICK_REGISTER_CONST_LONG("EVALUATE_LOG", LogEvaluateOperator);
	IMAGICK_REGISTER_CONST_LONG("EVALUATE_THRESHOLD", ThresholdEvaluateOperator);
	IMAGICK_REGISTER_CONST_LONG("EVALUATE_THRESHOLDBLACK", ThresholdBlackEvaluateOperator);
	IMAGICK_REGISTER_CONST_LONG("EVALUATE_THRESHOLDWHITE", ThresholdWhiteEvaluateOperator);
	IMAGICK_REGISTER_CONST_LONG("EVALUATE_GAUSSIANNOISE", GaussianNoiseEvaluateOperator);
	IMAGICK_REGISTER_CONST_LONG("EVALUATE_IMPULSENOISE", ImpulseNoiseEvaluateOperator);
	IMAGICK_REGISTER_CONST_LONG("EVALUATE_LAPLACIANNOISE", LaplacianNoiseEvaluateOperator);
	IMAGICK_REGISTER_CONST_LONG("EVALUATE_MULTIPLICATIVENOISE", MultiplicativeNoiseEvaluateOperator);
	IMAGICK_REGISTER_CONST_LONG("EVALUATE_POISSONNOISE", PoissonNoiseEvaluateOperator);
	IMAGICK_REGISTER_CONST_LONG("EVALUATE_UNIFORMNOISE", UniformNoiseEvaluateOperator);
#endif
#if MagickLibVersion > 0x648
	IMAGICK_REGISTER_CONST_LONG("EVALUATE_COSINE", CosineEvaluateOperator);
	IMAGICK_REGISTER_CONST_LONG("EVALUATE_SINE", SineEvaluateOperator);
	IMAGICK_REGISTER_CONST_LONG("EVALUATE_ADDMODULUS", AddModulusEvaluateOperator);
#endif
#if MagickLibVersion >= 0x661
	IMAGICK_REGISTER_CONST_LONG("EVALUATE_MEAN", MeanEvaluateOperator);
#endif
#if MagickLibVersion >= 0x664
	IMAGICK_REGISTER_CONST_LONG("EVALUATE_ABS", AbsEvaluateOperator);
#endif
#if MagickLibVersion >= 0x666
	IMAGICK_REGISTER_CONST_LONG("EVALUATE_EXPONENTIAL", ExponentialEvaluateOperator);
	IMAGICK_REGISTER_CONST_LONG("EVALUATE_MEDIAN", MedianEvaluateOperator);
#endif
#if MagickLibVersion >= 0x676
	IMAGICK_REGISTER_CONST_LONG("EVALUATE_SUM", SumEvaluateOperator);
#endif
#if MagickLibVersion >= 0x690
	IMAGICK_REGISTER_CONST_LONG("EVALUATE_ROOT_MEAN_SQUARE", RootMeanSquareEvaluateOperator);
#endif

	IMAGICK_REGISTER_CONST_LONG("COLORSPACE_UNDEFINED", UndefinedColorspace);
	IMAGICK_REGISTER_CONST_LONG("COLORSPACE_RGB", RGBColorspace);
	IMAGICK_REGISTER_CONST_LONG("COLORSPACE_GRAY", GRAYColorspace);
	IMAGICK_REGISTER_CONST_LONG("COLORSPACE_TRANSPARENT", TransparentColorspace);
	IMAGICK_REGISTER_CONST_LONG("COLORSPACE_OHTA", OHTAColorspace);
#if MagickLibVersion < 0x700
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
	IMAGICK_REGISTER_CONST_LONG("COLORSPACE_LAB", LABColorspace);
#endif
#endif
	IMAGICK_REGISTER_CONST_LONG("COLORSPACE_XYZ", XYZColorspace);
	IMAGICK_REGISTER_CONST_LONG("COLORSPACE_YCBCR", YCbCrColorspace);
	IMAGICK_REGISTER_CONST_LONG("COLORSPACE_YCC", YCCColorspace);
	IMAGICK_REGISTER_CONST_LONG("COLORSPACE_YIQ", YIQColorspace);
	IMAGICK_REGISTER_CONST_LONG("COLORSPACE_YPBPR", YPbPrColorspace);
	IMAGICK_REGISTER_CONST_LONG("COLORSPACE_YUV", YUVColorspace);
	IMAGICK_REGISTER_CONST_LONG("COLORSPACE_CMYK", CMYKColorspace);
	IMAGICK_REGISTER_CONST_LONG("COLORSPACE_SRGB", sRGBColorspace);
	IMAGICK_REGISTER_CONST_LONG("COLORSPACE_HSB", HSBColorspace);
	IMAGICK_REGISTER_CONST_LONG("COLORSPACE_HSL", HSLColorspace);
	IMAGICK_REGISTER_CONST_LONG("COLORSPACE_HWB", HWBColorspace);
#if MagickLibVersion < 0x700
	IMAGICK_REGISTER_CONST_LONG("COLORSPACE_REC601LUMA", Rec601LumaColorspace);
	IMAGICK_REGISTER_CONST_LONG("COLORSPACE_REC709LUMA", Rec709LumaColorspace);
#endif
	IMAGICK_REGISTER_CONST_LONG("COLORSPACE_LOG", LogColorspace);
#if MagickLibVersion >= 0x642
	IMAGICK_REGISTER_CONST_LONG("COLORSPACE_CMY", CMYColorspace);
#endif
#if MagickLibVersion >= 0X679
	IMAGICK_REGISTER_CONST_LONG("COLORSPACE_LUV", LuvColorspace);
	IMAGICK_REGISTER_CONST_LONG("COLORSPACE_HCL", HCLColorspace);
#endif
#if MagickLibVersion >= 0x680
	IMAGICK_REGISTER_CONST_LONG("COLORSPACE_LCH", LCHColorspace);
	IMAGICK_REGISTER_CONST_LONG("COLORSPACE_LMS", LMSColorspace);
#endif
#if MagickLibVersion >= 0x686
	IMAGICK_REGISTER_CONST_LONG("COLORSPACE_LCHAB", LCHabColorspace);
	IMAGICK_REGISTER_CONST_LONG("COLORSPACE_LCHUV", LCHuvColorspace);
	IMAGICK_REGISTER_CONST_LONG("COLORSPACE_SCRGB", scRGBColorspace);
	IMAGICK_REGISTER_CONST_LONG("COLORSPACE_HSI", HSIColorspace);
	IMAGICK_REGISTER_CONST_LONG("COLORSPACE_HSV", HSVColorspace);
	IMAGICK_REGISTER_CONST_LONG("COLORSPACE_HCLP", HCLpColorspace);
	IMAGICK_REGISTER_CONST_LONG("COLORSPACE_YDBDR", YDbDrColorspace);
#endif

	IMAGICK_REGISTER_CONST_LONG("COLORSPACE_REC601YCBCR", Rec601YCbCrColorspace);
	IMAGICK_REGISTER_CONST_LONG("COLORSPACE_REC709YCBCR", Rec709YCbCrColorspace);
#if MagickLibVersion >= 0x690
	IMAGICK_REGISTER_CONST_LONG("COLORSPACE_XYY", xyYColorspace);
#endif


#if (MagickLibVersion >= 0x700 && MagickLibVersion >= 0x708) || (MagickLibVersion < 0x700 && MagickLibVersion >= 0x699)
	IMAGICK_REGISTER_CONST_LONG("COLORSPACE_LINEARGRAY", LinearGRAYColorspace);
#endif

	IMAGICK_REGISTER_CONST_LONG("VIRTUALPIXELMETHOD_UNDEFINED", UndefinedVirtualPixelMethod);
	IMAGICK_REGISTER_CONST_LONG("VIRTUALPIXELMETHOD_BACKGROUND", BackgroundVirtualPixelMethod);
#if MagickLibVersion < 0x700
	IMAGICK_REGISTER_CONST_LONG("VIRTUALPIXELMETHOD_CONSTANT", ConstantVirtualPixelMethod);  /* deprecated */
#endif
	IMAGICK_REGISTER_CONST_LONG("VIRTUALPIXELMETHOD_EDGE", EdgeVirtualPixelMethod);
	IMAGICK_REGISTER_CONST_LONG("VIRTUALPIXELMETHOD_MIRROR", MirrorVirtualPixelMethod);
	IMAGICK_REGISTER_CONST_LONG("VIRTUALPIXELMETHOD_TILE", TileVirtualPixelMethod);
	IMAGICK_REGISTER_CONST_LONG("VIRTUALPIXELMETHOD_TRANSPARENT", TransparentVirtualPixelMethod);
#if MagickLibVersion > 0x641
	IMAGICK_REGISTER_CONST_LONG("VIRTUALPIXELMETHOD_MASK", MaskVirtualPixelMethod);
	IMAGICK_REGISTER_CONST_LONG("VIRTUALPIXELMETHOD_BLACK", BlackVirtualPixelMethod);
	IMAGICK_REGISTER_CONST_LONG("VIRTUALPIXELMETHOD_GRAY", GrayVirtualPixelMethod);
	IMAGICK_REGISTER_CONST_LONG("VIRTUALPIXELMETHOD_WHITE", WhiteVirtualPixelMethod);
#endif
#if MagickLibVersion > 0x642
	IMAGICK_REGISTER_CONST_LONG("VIRTUALPIXELMETHOD_HORIZONTALTILE", HorizontalTileVirtualPixelMethod);
	IMAGICK_REGISTER_CONST_LONG("VIRTUALPIXELMETHOD_VERTICALTILE", VerticalTileVirtualPixelMethod);
#endif
#if MagickLibVersion >= 0x651
	IMAGICK_REGISTER_CONST_LONG("VIRTUALPIXELMETHOD_HORIZONTALTILEEDGE", HorizontalTileEdgeVirtualPixelMethod);
	IMAGICK_REGISTER_CONST_LONG("VIRTUALPIXELMETHOD_VERTICALTILEEDGE", VerticalTileEdgeVirtualPixelMethod);
	IMAGICK_REGISTER_CONST_LONG("VIRTUALPIXELMETHOD_CHECKERTILE", CheckerTileVirtualPixelMethod);
#endif
	IMAGICK_REGISTER_CONST_LONG("PREVIEW_UNDEFINED", UndefinedPreview);
	IMAGICK_REGISTER_CONST_LONG("PREVIEW_ROTATE", RotatePreview);
	IMAGICK_REGISTER_CONST_LONG("PREVIEW_SHEAR", ShearPreview);
	IMAGICK_REGISTER_CONST_LONG("PREVIEW_ROLL", RollPreview);
	IMAGICK_REGISTER_CONST_LONG("PREVIEW_HUE", HuePreview);
	IMAGICK_REGISTER_CONST_LONG("PREVIEW_SATURATION", SaturationPreview);
	IMAGICK_REGISTER_CONST_LONG("PREVIEW_BRIGHTNESS", BrightnessPreview);
	IMAGICK_REGISTER_CONST_LONG("PREVIEW_GAMMA", GammaPreview);
	IMAGICK_REGISTER_CONST_LONG("PREVIEW_SPIFF", SpiffPreview);
	IMAGICK_REGISTER_CONST_LONG("PREVIEW_DULL", DullPreview);
	IMAGICK_REGISTER_CONST_LONG("PREVIEW_GRAYSCALE", GrayscalePreview);
	IMAGICK_REGISTER_CONST_LONG("PREVIEW_QUANTIZE", QuantizePreview);
	IMAGICK_REGISTER_CONST_LONG("PREVIEW_DESPECKLE", DespecklePreview);
	IMAGICK_REGISTER_CONST_LONG("PREVIEW_REDUCENOISE", ReduceNoisePreview);
	IMAGICK_REGISTER_CONST_LONG("PREVIEW_ADDNOISE", AddNoisePreview);
	IMAGICK_REGISTER_CONST_LONG("PREVIEW_SHARPEN", SharpenPreview);
	IMAGICK_REGISTER_CONST_LONG("PREVIEW_BLUR", BlurPreview);
	IMAGICK_REGISTER_CONST_LONG("PREVIEW_THRESHOLD", ThresholdPreview);
	IMAGICK_REGISTER_CONST_LONG("PREVIEW_EDGEDETECT", EdgeDetectPreview);
	IMAGICK_REGISTER_CONST_LONG("PREVIEW_SPREAD", SpreadPreview);
	IMAGICK_REGISTER_CONST_LONG("PREVIEW_SOLARIZE", SolarizePreview);
	IMAGICK_REGISTER_CONST_LONG("PREVIEW_SHADE", ShadePreview);
	IMAGICK_REGISTER_CONST_LONG("PREVIEW_RAISE", RaisePreview);
	IMAGICK_REGISTER_CONST_LONG("PREVIEW_SEGMENT", SegmentPreview);
	IMAGICK_REGISTER_CONST_LONG("PREVIEW_SWIRL", SwirlPreview);
	IMAGICK_REGISTER_CONST_LONG("PREVIEW_IMPLODE", ImplodePreview);
	IMAGICK_REGISTER_CONST_LONG("PREVIEW_WAVE", WavePreview);
	IMAGICK_REGISTER_CONST_LONG("PREVIEW_OILPAINT", OilPaintPreview);
	IMAGICK_REGISTER_CONST_LONG("PREVIEW_CHARCOALDRAWING", CharcoalDrawingPreview);
	IMAGICK_REGISTER_CONST_LONG("PREVIEW_JPEG", JPEGPreview);
	IMAGICK_REGISTER_CONST_LONG("RENDERINGINTENT_UNDEFINED", UndefinedIntent);
	IMAGICK_REGISTER_CONST_LONG("RENDERINGINTENT_SATURATION", SaturationIntent);
	IMAGICK_REGISTER_CONST_LONG("RENDERINGINTENT_PERCEPTUAL", PerceptualIntent);
	IMAGICK_REGISTER_CONST_LONG("RENDERINGINTENT_ABSOLUTE", AbsoluteIntent);
	IMAGICK_REGISTER_CONST_LONG("RENDERINGINTENT_RELATIVE", RelativeIntent);
	IMAGICK_REGISTER_CONST_LONG("INTERLACE_UNDEFINED", UndefinedInterlace);
	IMAGICK_REGISTER_CONST_LONG("INTERLACE_NO", NoInterlace);
	IMAGICK_REGISTER_CONST_LONG("INTERLACE_LINE", LineInterlace);
	IMAGICK_REGISTER_CONST_LONG("INTERLACE_PLANE", PlaneInterlace);
	IMAGICK_REGISTER_CONST_LONG("INTERLACE_PARTITION", PartitionInterlace);
#if MagickLibVersion > 0x633
	IMAGICK_REGISTER_CONST_LONG("INTERLACE_GIF", GIFInterlace);
	IMAGICK_REGISTER_CONST_LONG("INTERLACE_JPEG", JPEGInterlace);
	IMAGICK_REGISTER_CONST_LONG("INTERLACE_PNG", PNGInterlace);
#endif
	IMAGICK_REGISTER_CONST_LONG("FILLRULE_UNDEFINED", UndefinedRule);
	IMAGICK_REGISTER_CONST_LONG("FILLRULE_EVENODD", EvenOddRule);
	IMAGICK_REGISTER_CONST_LONG("FILLRULE_NONZERO", NonZeroRule);
	IMAGICK_REGISTER_CONST_LONG("PATHUNITS_UNDEFINED", UndefinedPathUnits);
	IMAGICK_REGISTER_CONST_LONG("PATHUNITS_USERSPACE", UserSpace);
	IMAGICK_REGISTER_CONST_LONG("PATHUNITS_USERSPACEONUSE", UserSpaceOnUse);
	IMAGICK_REGISTER_CONST_LONG("PATHUNITS_OBJECTBOUNDINGBOX", ObjectBoundingBox);
	IMAGICK_REGISTER_CONST_LONG("LINECAP_UNDEFINED", UndefinedCap);
	IMAGICK_REGISTER_CONST_LONG("LINECAP_BUTT", ButtCap);
	IMAGICK_REGISTER_CONST_LONG("LINECAP_ROUND", RoundCap);
	IMAGICK_REGISTER_CONST_LONG("LINECAP_SQUARE", SquareCap);
	IMAGICK_REGISTER_CONST_LONG("LINEJOIN_UNDEFINED", UndefinedJoin);
	IMAGICK_REGISTER_CONST_LONG("LINEJOIN_MITER", MiterJoin);
	IMAGICK_REGISTER_CONST_LONG("LINEJOIN_ROUND", RoundJoin);
	IMAGICK_REGISTER_CONST_LONG("LINEJOIN_BEVEL", BevelJoin);
	IMAGICK_REGISTER_CONST_LONG("RESOURCETYPE_UNDEFINED", UndefinedResource);
	IMAGICK_REGISTER_CONST_LONG("RESOURCETYPE_AREA", AreaResource);
	IMAGICK_REGISTER_CONST_LONG("RESOURCETYPE_DISK", DiskResource);
	IMAGICK_REGISTER_CONST_LONG("RESOURCETYPE_FILE", FileResource);
	IMAGICK_REGISTER_CONST_LONG("RESOURCETYPE_MAP", MapResource);
	IMAGICK_REGISTER_CONST_LONG("RESOURCETYPE_MEMORY", MemoryResource);
#if MagickLibVersion >= 0x675
	IMAGICK_REGISTER_CONST_LONG("RESOURCETYPE_TIME", TimeResource);
	IMAGICK_REGISTER_CONST_LONG("RESOURCETYPE_THROTTLE", ThrottleResource);
#endif
#if MagickLibVersion > 0x678
	IMAGICK_REGISTER_CONST_LONG("RESOURCETYPE_THREAD", ThreadResource);
#endif
#if MagickLibVersion > 0x691
	IMAGICK_REGISTER_CONST_LONG("RESOURCETYPE_WIDTH", WidthResource);
	IMAGICK_REGISTER_CONST_LONG("RESOURCETYPE_HEIGHT", HeightResource);
#endif

#if (MagickLibVersion >= 0x700 && MagickLibVersion >= 0x708) || (MagickLibVersion < 0x700 && MagickLibVersion >= 0x69A)
    IMAGICK_REGISTER_CONST_LONG("RESOURCETYPE_LISTLENGTH", ListLengthResource);
#endif

	IMAGICK_REGISTER_CONST_LONG("DISPOSE_UNRECOGNIZED", UnrecognizedDispose);
	IMAGICK_REGISTER_CONST_LONG("DISPOSE_UNDEFINED", UndefinedDispose);
	IMAGICK_REGISTER_CONST_LONG("DISPOSE_NONE", NoneDispose);
	IMAGICK_REGISTER_CONST_LONG("DISPOSE_BACKGROUND", BackgroundDispose);
	IMAGICK_REGISTER_CONST_LONG("DISPOSE_PREVIOUS", PreviousDispose);
#if MagickLibVersion > 0x631
	IMAGICK_REGISTER_CONST_LONG("INTERPOLATE_UNDEFINED", UndefinedInterpolatePixel);

	IMAGICK_REGISTER_CONST_LONG("INTERPOLATE_AVERAGE", AverageInterpolatePixel); /* Average 4 nearest neighbours */
#if MagickLibVersion < 0x700
	IMAGICK_REGISTER_CONST_LONG("INTERPOLATE_BICUBIC", BicubicInterpolatePixel); /* Catmull-Rom interpolation */
#endif
	IMAGICK_REGISTER_CONST_LONG("INTERPOLATE_BILINEAR", BilinearInterpolatePixel); /* Triangular filter interpolation */
#if MagickLibVersion < 0x700
	IMAGICK_REGISTER_CONST_LONG("INTERPOLATE_FILTER", FilterInterpolatePixel); /* Use resize filter - (very slow) */
#endif
	IMAGICK_REGISTER_CONST_LONG("INTERPOLATE_INTEGER", IntegerInterpolatePixel); /* Integer (floor) interpolation */
	IMAGICK_REGISTER_CONST_LONG("INTERPOLATE_MESH", MeshInterpolatePixel); /* Triangular mesh interpolation */
#if MagickLibVersion < 0x700
	IMAGICK_REGISTER_CONST_LONG("INTERPOLATE_NEARESTNEIGHBOR", NearestNeighborInterpolatePixel);
#endif
#endif
#if MagickLibVersion > 0x634
	IMAGICK_REGISTER_CONST_LONG("INTERPOLATE_SPLINE", SplineInterpolatePixel); /* Cubic Spline (blurred) interpolation */
#endif
#if MagickLibVersion > 0x690
	IMAGICK_REGISTER_CONST_LONG("INTERPOLATE_AVERAGE_9", Average9InterpolatePixel); /* Average 9 nearest neighbours */
	IMAGICK_REGISTER_CONST_LONG("INTERPOLATE_AVERAGE_16", Average16InterpolatePixel); /* Average 16 nearest neighbours */
	IMAGICK_REGISTER_CONST_LONG("INTERPOLATE_BLEND", BlendInterpolatePixel); /* blend of nearest 1, 2 or 4 pixels */
	IMAGICK_REGISTER_CONST_LONG("INTERPOLATE_BACKGROUND_COLOR", BackgroundInterpolatePixel); /* just return background color */
#if MagickLibVersion >= 0x687
	IMAGICK_REGISTER_CONST_LONG("INTERPOLATE_CATROM", CatromInterpolatePixel); /* Catmull-Rom interpolation */
#endif
#endif

#if MagickLibVersion >= 0x701
	IMAGICK_REGISTER_CONST_LONG("INTERPOLATE_NEAREST_PIXEL", NearestInterpolatePixel); /* NearestInterpolatePixel */
#endif

#if MagickLibVersion > 0x628
	IMAGICK_REGISTER_CONST_LONG("LAYERMETHOD_UNDEFINED", UndefinedLayer);
	IMAGICK_REGISTER_CONST_LONG("LAYERMETHOD_COALESCE", CoalesceLayer);
	IMAGICK_REGISTER_CONST_LONG("LAYERMETHOD_COMPAREANY", CompareAnyLayer);
	IMAGICK_REGISTER_CONST_LONG("LAYERMETHOD_COMPARECLEAR", CompareClearLayer);
	IMAGICK_REGISTER_CONST_LONG("LAYERMETHOD_COMPAREOVERLAY", CompareOverlayLayer);
	IMAGICK_REGISTER_CONST_LONG("LAYERMETHOD_DISPOSE", DisposeLayer);
	IMAGICK_REGISTER_CONST_LONG("LAYERMETHOD_OPTIMIZE", OptimizeLayer);
	IMAGICK_REGISTER_CONST_LONG("LAYERMETHOD_OPTIMIZEPLUS", OptimizePlusLayer);
#endif
#if MagickLibVersion > 0x632
	IMAGICK_REGISTER_CONST_LONG("LAYERMETHOD_OPTIMIZETRANS", OptimizeTransLayer);
	IMAGICK_REGISTER_CONST_LONG("LAYERMETHOD_COMPOSITE", CompositeLayer);
	IMAGICK_REGISTER_CONST_LONG("LAYERMETHOD_OPTIMIZEIMAGE", OptimizeImageLayer);
	IMAGICK_REGISTER_CONST_LONG("LAYERMETHOD_REMOVEDUPS", RemoveDupsLayer);
	IMAGICK_REGISTER_CONST_LONG("LAYERMETHOD_REMOVEZERO", RemoveZeroLayer);
#endif
#if MagickLibVersion >= 0x644
	IMAGICK_REGISTER_CONST_LONG("LAYERMETHOD_TRIMBOUNDS", TrimBoundsLayer);
#endif
#if MagickLibVersion > 0x629
	IMAGICK_REGISTER_CONST_LONG("ORIENTATION_UNDEFINED", UndefinedOrientation);
	IMAGICK_REGISTER_CONST_LONG("ORIENTATION_TOPLEFT", TopLeftOrientation);
	IMAGICK_REGISTER_CONST_LONG("ORIENTATION_TOPRIGHT", TopRightOrientation);
	IMAGICK_REGISTER_CONST_LONG("ORIENTATION_BOTTOMRIGHT", BottomRightOrientation);
	IMAGICK_REGISTER_CONST_LONG("ORIENTATION_BOTTOMLEFT", BottomLeftOrientation);
	IMAGICK_REGISTER_CONST_LONG("ORIENTATION_LEFTTOP", LeftTopOrientation);
	IMAGICK_REGISTER_CONST_LONG("ORIENTATION_RIGHTTOP", RightTopOrientation);
	IMAGICK_REGISTER_CONST_LONG("ORIENTATION_RIGHTBOTTOM", RightBottomOrientation);
	IMAGICK_REGISTER_CONST_LONG("ORIENTATION_LEFTBOTTOM", LeftBottomOrientation);
#endif
#if MagickLibVersion > 0x635
	IMAGICK_REGISTER_CONST_LONG("DISTORTION_UNDEFINED", UndefinedDistortion);
	IMAGICK_REGISTER_CONST_LONG("DISTORTION_AFFINE", AffineDistortion);
	IMAGICK_REGISTER_CONST_LONG("DISTORTION_AFFINEPROJECTION", AffineProjectionDistortion);
	IMAGICK_REGISTER_CONST_LONG("DISTORTION_ARC", ArcDistortion);
	IMAGICK_REGISTER_CONST_LONG("DISTORTION_BILINEAR", BilinearDistortion);
	IMAGICK_REGISTER_CONST_LONG("DISTORTION_PERSPECTIVE", PerspectiveDistortion);
	IMAGICK_REGISTER_CONST_LONG("DISTORTION_PERSPECTIVEPROJECTION", PerspectiveProjectionDistortion);
	IMAGICK_REGISTER_CONST_LONG("DISTORTION_SCALEROTATETRANSLATE", ScaleRotateTranslateDistortion);
#endif
#if MagickLibVersion > 0x645
	IMAGICK_REGISTER_CONST_LONG("DISTORTION_POLYNOMIAL", PolynomialDistortion);
	IMAGICK_REGISTER_CONST_LONG("DISTORTION_POLAR", PolarDistortion);
	IMAGICK_REGISTER_CONST_LONG("DISTORTION_DEPOLAR", DePolarDistortion);
	IMAGICK_REGISTER_CONST_LONG("DISTORTION_BARREL", BarrelDistortion);
	IMAGICK_REGISTER_CONST_LONG("DISTORTION_SHEPARDS", ShepardsDistortion);

	// SentinelDistortion is not a real distortion type. It is a guard value 
	// that shouldn't have been exposed in Imagick. TODO remove at next
	// minor version.
	IMAGICK_REGISTER_CONST_LONG("DISTORTION_SENTINEL", SentinelDistortion);
#endif
#if MagickLibVersion >= 0x644
	IMAGICK_REGISTER_CONST_LONG("DISTORTION_BARRELINVERSE", BarrelInverseDistortion);
#endif
#if MagickLibVersion >= 0x654
	IMAGICK_REGISTER_CONST_LONG("DISTORTION_BILINEARFORWARD", BilinearForwardDistortion);
	IMAGICK_REGISTER_CONST_LONG("DISTORTION_BILINEARREVERSE", BilinearReverseDistortion);
#endif
#if MagickLibVersion >= 0x670
	IMAGICK_REGISTER_CONST_LONG("DISTORTION_RESIZE", ResizeDistortion);
#endif
#if MagickLibVersion >= 0x671
	IMAGICK_REGISTER_CONST_LONG("DISTORTION_CYLINDER2PLANE", Cylinder2PlaneDistortion);
	IMAGICK_REGISTER_CONST_LONG("DISTORTION_PLANE2CYLINDER", Plane2CylinderDistortion);
#endif
#if MagickLibVersion > 0x636
	IMAGICK_REGISTER_CONST_LONG("LAYERMETHOD_MERGE", MergeLayer);
	IMAGICK_REGISTER_CONST_LONG("LAYERMETHOD_FLATTEN", FlattenLayer);
	IMAGICK_REGISTER_CONST_LONG("LAYERMETHOD_MOSAIC", MosaicLayer);
#endif
#if MagickLibVersion > 0x637
	IMAGICK_REGISTER_CONST_LONG("ALPHACHANNEL_ACTIVATE", ActivateAlphaChannel);
#if MagickLibVersion >= 0x700
	IMAGICK_REGISTER_CONST_LONG("ALPHACHANNEL_ON", OnAlphaChannel);
#else
	IMAGICK_REGISTER_CONST_LONG("ALPHACHANNEL_RESET", ResetAlphaChannel);
#endif
	IMAGICK_REGISTER_CONST_LONG("ALPHACHANNEL_SET", SetAlphaChannel);
#endif
#if MagickLibVersion > 0x645
	IMAGICK_REGISTER_CONST_LONG("ALPHACHANNEL_UNDEFINED", UndefinedAlphaChannel);
#if MagickLibVersion >= 0x700
	IMAGICK_REGISTER_CONST_LONG("ALPHACHANNEL_DISCRETE", DiscreteAlphaChannel);
#else
	IMAGICK_REGISTER_CONST_LONG("ALPHACHANNEL_COPY", CopyAlphaChannel);
#endif
	IMAGICK_REGISTER_CONST_LONG("ALPHACHANNEL_DEACTIVATE", DeactivateAlphaChannel);
	IMAGICK_REGISTER_CONST_LONG("ALPHACHANNEL_EXTRACT", ExtractAlphaChannel);
#if MagickLibVersion >= 0x700
	IMAGICK_REGISTER_CONST_LONG("ALPHACHANNEL_OFF", OffAlphaChannel);
#else
	IMAGICK_REGISTER_CONST_LONG("ALPHACHANNEL_OPAQUE", OpaqueAlphaChannel);
#endif
	IMAGICK_REGISTER_CONST_LONG("ALPHACHANNEL_SHAPE", ShapeAlphaChannel);
	IMAGICK_REGISTER_CONST_LONG("ALPHACHANNEL_TRANSPARENT", TransparentAlphaChannel);
#if MagickLibVersion >= 0x690
	IMAGICK_REGISTER_CONST_LONG("ALPHACHANNEL_ASSOCIATE", AssociateAlphaChannel);
	IMAGICK_REGISTER_CONST_LONG("ALPHACHANNEL_DISSOCIATE", DisassociateAlphaChannel);
#endif
	/*
	 DiscreteAlphaChannel,                  CopyAlphaChannel,
	 DisassociateAlphaChannel,              DeactivateAlphaChannel,
	 ExtractAlphaChannel,                   ExtractAlphaChannel,
	 OffAlphaChannel,                       OpaqueAlphaChannel,
	 OnAlphaChannel,                        ResetAlphaChannel,  // deprecated
	*/

	IMAGICK_REGISTER_CONST_LONG("SPARSECOLORMETHOD_UNDEFINED", UndefinedColorInterpolate);
	IMAGICK_REGISTER_CONST_LONG("SPARSECOLORMETHOD_BARYCENTRIC", BarycentricColorInterpolate);
	IMAGICK_REGISTER_CONST_LONG("SPARSECOLORMETHOD_BILINEAR", BilinearColorInterpolate);
	IMAGICK_REGISTER_CONST_LONG("SPARSECOLORMETHOD_POLYNOMIAL", PolynomialColorInterpolate);
	IMAGICK_REGISTER_CONST_LONG("SPARSECOLORMETHOD_SPEPARDS", ShepardsColorInterpolate);
	IMAGICK_REGISTER_CONST_LONG("SPARSECOLORMETHOD_VORONOI", VoronoiColorInterpolate);
#if MagickLibVersion >= 0x687
	IMAGICK_REGISTER_CONST_LONG("SPARSECOLORMETHOD_INVERSE", InverseColorInterpolate);
#endif
#if MagickLibVersion >= 0x693
	IMAGICK_REGISTER_CONST_LONG("SPARSECOLORMETHOD_MANHATTAN", ManhattanColorInterpolate);
#endif
	IMAGICK_REGISTER_CONST_LONG("DITHERMETHOD_UNDEFINED", UndefinedDitherMethod);
	IMAGICK_REGISTER_CONST_LONG("DITHERMETHOD_NO", NoDitherMethod);
	IMAGICK_REGISTER_CONST_LONG("DITHERMETHOD_RIEMERSMA", RiemersmaDitherMethod);
	IMAGICK_REGISTER_CONST_LONG("DITHERMETHOD_FLOYDSTEINBERG", FloydSteinbergDitherMethod);
#endif
#if MagickLibVersion > 0x648
	IMAGICK_REGISTER_CONST_LONG("FUNCTION_UNDEFINED", UndefinedFunction);
	IMAGICK_REGISTER_CONST_LONG("FUNCTION_POLYNOMIAL", PolynomialFunction);
	IMAGICK_REGISTER_CONST_LONG("FUNCTION_SINUSOID", SinusoidFunction);
#endif
#if MagickLibVersion >= 0x653
	IMAGICK_REGISTER_CONST_LONG("ALPHACHANNEL_BACKGROUND", BackgroundAlphaChannel);
	IMAGICK_REGISTER_CONST_LONG("FUNCTION_ARCSIN", ArcsinFunction);
	IMAGICK_REGISTER_CONST_LONG("FUNCTION_ARCTAN", ArctanFunction);
#endif
#if MagickLibVersion >= 0x678
#if MagickLibVersion < 0x700
	IMAGICK_REGISTER_CONST_LONG("ALPHACHANNEL_FLATTEN", FlattenAlphaChannel);
#endif
	IMAGICK_REGISTER_CONST_LONG("ALPHACHANNEL_REMOVE", RemoveAlphaChannel);
#endif

#if MagickLibVersion > 0x683
	IMAGICK_REGISTER_CONST_LONG("STATISTIC_GRADIENT", GradientStatistic);
	IMAGICK_REGISTER_CONST_LONG("STATISTIC_MAXIMUM", MaximumStatistic);
	IMAGICK_REGISTER_CONST_LONG("STATISTIC_MEAN", MeanStatistic);
	IMAGICK_REGISTER_CONST_LONG("STATISTIC_MEDIAN", MedianStatistic);
	IMAGICK_REGISTER_CONST_LONG("STATISTIC_MINIMUM", MinimumStatistic);
	IMAGICK_REGISTER_CONST_LONG("STATISTIC_MODE", ModeStatistic);
	IMAGICK_REGISTER_CONST_LONG("STATISTIC_NONPEAK", NonpeakStatistic);
	IMAGICK_REGISTER_CONST_LONG("STATISTIC_STANDARD_DEVIATION", StandardDeviationStatistic);
#if MagickLibVersion >= 0x690
	IMAGICK_REGISTER_CONST_LONG("STATISTIC_ROOT_MEAN_SQUARE", RootMeanSquareStatistic);
#endif
#endif

#ifdef IMAGICK_WITH_KERNEL
/* Convolve / Correlate weighted sums */
IMAGICK_REGISTER_CONST_LONG("MORPHOLOGY_CONVOLVE", ConvolveMorphology); /* Weighted Sum with reflected kernel */
IMAGICK_REGISTER_CONST_LONG("MORPHOLOGY_CORRELATE", CorrelateMorphology); /* Weighted Sum using a sliding window */
/* Low-level Morphology methods */
IMAGICK_REGISTER_CONST_LONG("MORPHOLOGY_ERODE", ErodeMorphology);  /* Minimum Value in Neighbourhood */
IMAGICK_REGISTER_CONST_LONG("MORPHOLOGY_DILATE", DilateMorphology);  /* Maximum Value in Neighbourhood */
IMAGICK_REGISTER_CONST_LONG("MORPHOLOGY_ERODE_INTENSITY", ErodeIntensityMorphology); /* Pixel Pick using GreyScale Erode */
IMAGICK_REGISTER_CONST_LONG("MORPHOLOGY_DILATE_INTENSITY", DilateIntensityMorphology); /* Pixel Pick using GreyScale Dialate */
IMAGICK_REGISTER_CONST_LONG("MORPHOLOGY_DISTANCE",  DistanceMorphology); /* Add Kernel Value, take Minimum */
/* Second-level Morphology methods */
IMAGICK_REGISTER_CONST_LONG("MORPHOLOGY_OPEN", OpenMorphology); /* Dilate then Erode */
IMAGICK_REGISTER_CONST_LONG("MORPHOLOGY_CLOSE", CloseMorphology); /* Erode then Dilate */
IMAGICK_REGISTER_CONST_LONG("MORPHOLOGY_OPEN_INTENSITY", OpenIntensityMorphology); /* Pixel Pick using GreyScale Open */
IMAGICK_REGISTER_CONST_LONG("MORPHOLOGY_CLOSE_INTENSITY", CloseIntensityMorphology); /* Pixel Pick using GreyScale Close */
IMAGICK_REGISTER_CONST_LONG("MORPHOLOGY_SMOOTH", SmoothMorphology); /* Open then Close */
/* Difference Morphology methods */
IMAGICK_REGISTER_CONST_LONG("MORPHOLOGY_EDGE_IN", EdgeInMorphology); /* Dilate difference from Original */
IMAGICK_REGISTER_CONST_LONG("MORPHOLOGY_EDGE_OUT", EdgeOutMorphology); /* Erode difference from Original */
IMAGICK_REGISTER_CONST_LONG("MORPHOLOGY_EDGE", EdgeMorphology); /* Dilate difference with Erode */
IMAGICK_REGISTER_CONST_LONG("MORPHOLOGY_TOP_HAT", TopHatMorphology); /* Close difference from Original */
IMAGICK_REGISTER_CONST_LONG("MORPHOLOGY_BOTTOM_HAT", BottomHatMorphology); /* Open difference from Original */
/* Recursive Morphology methods */
IMAGICK_REGISTER_CONST_LONG("MORPHOLOGY_HIT_AND_MISS", HitAndMissMorphology); /* Foreground/Background pattern matching */
IMAGICK_REGISTER_CONST_LONG("MORPHOLOGY_THINNING", ThinningMorphology); /* Remove matching pixels from image */
IMAGICK_REGISTER_CONST_LONG("MORPHOLOGY_THICKEN", ThickenMorphology); /* Add matching pixels from image */
/* Experimental Morphology methods */
IMAGICK_REGISTER_CONST_LONG("MORPHOLOGY_VORONOI", VoronoiMorphology); /* distance matte channel copy nearest color */
IMAGICK_REGISTER_CONST_LONG("MORPHOLOGY_ITERATIVE", IterativeDistanceMorphology); /* Add Kernel Value, take Minimum */


/* The no-op or 'original image' kernel */
IMAGICK_REGISTER_CONST_LONG("KERNEL_UNITY", UnityKernel);
/* Convolution Kernels, Gaussian Based */
IMAGICK_REGISTER_CONST_LONG("KERNEL_GAUSSIAN", GaussianKernel);
IMAGICK_REGISTER_CONST_LONG("KERNEL_DIFFERENCE_OF_GAUSSIANS", DoGKernel);
IMAGICK_REGISTER_CONST_LONG("KERNEL_LAPLACIAN_OF_GAUSSIANS", LoGKernel);
IMAGICK_REGISTER_CONST_LONG("KERNEL_BLUR", BlurKernel);
IMAGICK_REGISTER_CONST_LONG("KERNEL_COMET", CometKernel);
/* Convolution Kernels, by Name */
IMAGICK_REGISTER_CONST_LONG("KERNEL_LAPLACIAN", LaplacianKernel);    
IMAGICK_REGISTER_CONST_LONG("KERNEL_SOBEL", SobelKernel);
IMAGICK_REGISTER_CONST_LONG("KERNEL_FREI_CHEN", FreiChenKernel);
IMAGICK_REGISTER_CONST_LONG("KERNEL_ROBERTS", RobertsKernel);
IMAGICK_REGISTER_CONST_LONG("KERNEL_PREWITT", PrewittKernel);
IMAGICK_REGISTER_CONST_LONG("KERNEL_COMPASS", CompassKernel);
IMAGICK_REGISTER_CONST_LONG("KERNEL_KIRSCH", KirschKernel);
/* Shape Kernels */
IMAGICK_REGISTER_CONST_LONG("KERNEL_DIAMOND", DiamondKernel); 
IMAGICK_REGISTER_CONST_LONG("KERNEL_SQUARE", SquareKernel);
IMAGICK_REGISTER_CONST_LONG("KERNEL_RECTANGLE", RectangleKernel);
IMAGICK_REGISTER_CONST_LONG("KERNEL_OCTAGON", OctagonKernel);
IMAGICK_REGISTER_CONST_LONG("KERNEL_DISK", DiskKernel);
IMAGICK_REGISTER_CONST_LONG("KERNEL_PLUS", PlusKernel);
IMAGICK_REGISTER_CONST_LONG("KERNEL_CROSS", CrossKernel);
IMAGICK_REGISTER_CONST_LONG("KERNEL_RING", RingKernel);
/* Hit And Miss Kernels */
IMAGICK_REGISTER_CONST_LONG("KERNEL_PEAKS", PeaksKernel);
IMAGICK_REGISTER_CONST_LONG("KERNEL_EDGES", EdgesKernel);
IMAGICK_REGISTER_CONST_LONG("KERNEL_CORNERS", CornersKernel);
IMAGICK_REGISTER_CONST_LONG("KERNEL_DIAGONALS", DiagonalsKernel);
IMAGICK_REGISTER_CONST_LONG("KERNEL_LINE_ENDS", LineEndsKernel);
IMAGICK_REGISTER_CONST_LONG("KERNEL_LINE_JUNCTIONS", LineJunctionsKernel);
IMAGICK_REGISTER_CONST_LONG("KERNEL_RIDGES", RidgesKernel);
IMAGICK_REGISTER_CONST_LONG("KERNEL_CONVEX_HULL", ConvexHullKernel);
IMAGICK_REGISTER_CONST_LONG("KERNEL_THIN_SE", ThinSEKernel);
IMAGICK_REGISTER_CONST_LONG("KERNEL_SKELETON", SkeletonKernel);
/* Distance Measuring Kernels */
IMAGICK_REGISTER_CONST_LONG("KERNEL_CHEBYSHEV", ChebyshevKernel);
IMAGICK_REGISTER_CONST_LONG("KERNEL_MANHATTAN", ManhattanKernel);
IMAGICK_REGISTER_CONST_LONG("KERNEL_OCTAGONAL", OctagonalKernel);
IMAGICK_REGISTER_CONST_LONG("KERNEL_EUCLIDEAN", EuclideanKernel);
/* User Specified Kernel Array */
IMAGICK_REGISTER_CONST_LONG("KERNEL_USER_DEFINED", UserDefinedKernel);
IMAGICK_REGISTER_CONST_LONG("KERNEL_BINOMIAL", BinomialKernel);

/* Draw directions */
IMAGICK_REGISTER_CONST_LONG("DIRECTION_LEFT_TO_RIGHT", LeftToRightDirection);
IMAGICK_REGISTER_CONST_LONG("DIRECTION_RIGHT_TO_LEFT", RightToLeftDirection);

// The kernel is scaled directly using given scaling factor without change.
IMAGICK_REGISTER_CONST_LONG("NORMALIZE_KERNEL_NONE", 0);
// Kernel normalization ('normalize_flags' given) is designed to ensure 
// that any use of the kernel scaling factor with 'Convolve' or 'Correlate' 
// morphology methods will fall into -1.0 to +1.0 range.
IMAGICK_REGISTER_CONST_LONG("NORMALIZE_KERNEL_VALUE", NormalizeValue);
// For special kernels designed for locating shapes using 'Correlate', (often 
// only containing +1 and -1 values, representing foreground/brackground 
// matching) a special normalization method is provided to scale the positive
// values separately to those of the negative values, so the kernel will be 
// forced to become a zero-sum kernel better suited to such searches.
IMAGICK_REGISTER_CONST_LONG("NORMALIZE_KERNEL_CORRELATE", CorrelateNormalizeValue);
// Scale the kernel by a percent.
IMAGICK_REGISTER_CONST_LONG("NORMALIZE_KERNEL_PERCENT", PercentValue);
#endif


#if MagickLibVersion >= 0x709
IMAGICK_REGISTER_CONST_LONG("PIXELMASK_READ", ReadPixelMask);
IMAGICK_REGISTER_CONST_LONG("PIXELMASK_WRITE", WritePixelMask);
IMAGICK_REGISTER_CONST_LONG("PIXELMASK_COMPOSITE", CompositePixelMask);
#endif

#undef IMAGICK_REGISTER_CONST_LONG
#undef IMAGICK_REGISTER_CONST_STRING
}
