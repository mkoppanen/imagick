/*
   +----------------------------------------------------------------------+
   | PHP Version 5 / Imagick	                                          |
   +----------------------------------------------------------------------+
   | Copyright (c) 2006-2013 Mikko Koppanen, Scott MacVicar               |
   | ImageMagick (c) ImageMagick Studio LLC                               |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Author: Mikko Kopppanen <mkoppanen@php.net>                          |
   |         Scott MacVicar <scottmac@php.net>                            |
   +----------------------------------------------------------------------+
*/

#include "php_imagick.h"
#include "php_imagick_defs.h"
#include "php_imagick_macros.h"
#include "php_imagick_helpers.h"

#if MagickLibVersion <= 0x628
static
long s_count_pixeliterator_rows(php_imagickpixeliterator_object *internpix)
{
	long rows = 0, tmp;
	PixelWand **row;
	PixelResetIterator(internpix->pixel_iterator);

	while ((row = PixelGetNextIteratorRow(internpix->pixel_iterator, &tmp)) != NULL)
		rows++;

	return rows;
}
#endif

void php_imagick_pixel_iterator_new (PixelIterator *pixel_it, zval *return_value TSRMLS_DC)
{
	php_imagickpixeliterator_object *internpix;

	object_init_ex(return_value, php_imagickpixeliterator_sc_entry);
	internpix = Z_IMAGICKPIXELITERATOR_P(return_value);

	internpix->pixel_iterator = pixel_it;
	internpix->initialized = 1;

#if MagickLibVersion <= 0x628
	internpix->rows = s_count_pixeliterator_rows (internpix);
#endif
}

/* {{{ proto ImagickPixelIterator ImagickPixelIterator::__construct(Imagick source)
   The ImagickPixelIterator constructor
*/
PHP_METHOD(ImagickPixelIterator, __construct)
{
	zval *magick_object;
	php_imagickpixeliterator_object *internpix;
	php_imagick_object *intern;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "O|llll", &magick_object, php_imagick_sc_entry) == FAILURE) {
		return;
	}

	internpix = Z_IMAGICKPIXELITERATOR_P(getThis());
	intern = Z_IMAGICK_P(magick_object);

	if (!intern->magick_wand) {
		php_imagick_throw_exception (IMAGICKPIXELITERATOR_CLASS, "Invalid Imagick object passed" TSRMLS_CC);
		return;
	}

	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	internpix->pixel_iterator = NewPixelIterator(intern->magick_wand);

	if (!internpix->pixel_iterator) {
		php_imagick_throw_exception (IMAGICKPIXELITERATOR_CLASS, "Can not allocate ImagickPixelIterator" TSRMLS_CC);
		return;
	}

#if MagickLibVersion <= 0x628
	internpix->rows = s_count_pixeliterator_rows (internpix);
#endif

	internpix->initialized = 1;
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickPixelIterator::resetIterator()
	Resets the pixel iterator.  Use it in conjunction with PixelGetNextIteratorRow() to iterate over all the pixels in a pixel container.
*/
PHP_METHOD(ImagickPixelIterator, resetIterator)
{
	php_imagickpixeliterator_object *internpix;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	internpix = Z_IMAGICKPIXELITERATOR_P(getThis());

	if (!internpix->initialized) {
		php_imagick_throw_exception (IMAGICKPIXELITERATOR_CLASS, "ImagickPixelIterator is not initialized correctly" TSRMLS_CC);
		return;
	}

	PixelResetIterator(internpix->pixel_iterator);
#if MagickLibVersion <= 0x628
	internpix->iterator_position = 0;
#endif
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickPixelIterator::syncIterator()
	Syncs the pixel iterator.
*/
PHP_METHOD(ImagickPixelIterator, syncIterator)
{
	php_imagickpixeliterator_object *internpix;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	internpix = Z_IMAGICKPIXELITERATOR_P(getThis());

	if (!internpix->initialized) {
		php_imagick_throw_exception (IMAGICKPIXELITERATOR_CLASS, "ImagickPixelIterator is not initialized correctly" TSRMLS_CC);
		return;
	}

	PixelSyncIterator(internpix->pixel_iterator);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickPixelIterator::setIteratorFirstRow()
	Sets the pixel iterator to the first pixel row.
*/
PHP_METHOD(ImagickPixelIterator, setIteratorFirstRow)
{
	php_imagickpixeliterator_object *internpix;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	internpix = Z_IMAGICKPIXELITERATOR_P(getThis());

	if (!internpix->initialized) {
		php_imagick_throw_exception (IMAGICKPIXELITERATOR_CLASS, "ImagickPixelIterator is not initialized correctly" TSRMLS_CC);
		return;
	}

	PixelSetFirstIteratorRow(internpix->pixel_iterator);
#if MagickLibVersion <= 0x628
	internpix->iterator_position = 0;
#endif
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickPixelIterator::setIteratorLastRow()
	Sets the pixel iterator to the last pixel row.
*/
PHP_METHOD(ImagickPixelIterator, setIteratorLastRow)
{
	php_imagickpixeliterator_object *internpix;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	internpix = Z_IMAGICKPIXELITERATOR_P(getThis());

	if (!internpix->initialized) {
		php_imagick_throw_exception (IMAGICKPIXELITERATOR_CLASS, "ImagickPixelIterator is not initialized correctly" TSRMLS_CC);
		return;
	}

	PixelSetLastIteratorRow(internpix->pixel_iterator);
#if MagickLibVersion <= 0x628
	internpix->iterator_position = (internpix->rows - 1);
#endif
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto ImagickPixelIterator ImagickPixelIterator::getPixelIterator(Imagick source)
	Returns a new pixel iterator, static method. This is equivalent to Imagick::getPixelIterator
	which probably ought to be used in preference to this method.
*/
PHP_METHOD(ImagickPixelIterator, getPixelIterator)
{
	PixelIterator *pixel_it;
	zval *magick_object;
	php_imagick_object *intern;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "O", &magick_object, php_imagick_sc_entry) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(magick_object);

	if (!intern->magick_wand) {
		php_imagick_throw_exception (IMAGICKPIXELITERATOR_CLASS, "Invalid Imagick object passed" TSRMLS_CC);
		return;
	}

	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	pixel_it = NewPixelIterator (intern->magick_wand);
	if (!pixel_it) {
		php_imagick_throw_exception (IMAGICKPIXELITERATOR_CLASS, "Can not allocate ImagickPixelIterator" TSRMLS_CC);
		return;
	}

	php_imagick_pixel_iterator_new (pixel_it, return_value TSRMLS_CC);
	return;
}
/* }}} */

/* {{{ proto ImagickPixelIterator ImagickPixelIterator::newPixelIterator(Imagick source)
	Returns a new pixel iterator.
*/
PHP_METHOD(ImagickPixelIterator, newPixelIterator)
{
	PixelIterator *pixel_it;
	zval *magick_object;
	php_imagickpixeliterator_object *internpix;
	php_imagick_object *intern;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "O", &magick_object, php_imagick_sc_entry) == FAILURE) {
		return;
	}

	IMAGICK_METHOD_DEPRECATED_USE_INSTEAD("ImagickPixelIterator", "newPixelIterator", "ImagickPixelIterator", "getPixelIterator");

	internpix = Z_IMAGICKPIXELITERATOR_P(getThis() );
	intern = Z_IMAGICK_P(magick_object);

	if (!intern->magick_wand) {
		php_imagick_throw_exception (IMAGICKPIXELITERATOR_CLASS, "Invalid Imagick object passed" TSRMLS_CC);
		return;
	}

	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	pixel_it = NewPixelIterator(intern->magick_wand);

	if (!pixel_it) {
		php_imagick_throw_exception (IMAGICKPIXELITERATOR_CLASS, "Can not allocate ImagickPixelIterator" TSRMLS_CC);
		return;
	}

	if (internpix->initialized && internpix->pixel_iterator)
		DestroyPixelIterator (internpix->pixel_iterator);

	internpix->pixel_iterator = pixel_it;
#if MagickLibVersion <= 0x628
	internpix->rows = s_count_pixeliterator_rows (internpix);
#endif

	internpix->initialized = 1;
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto ImagickPixelIterator ImagickPixelIterator::getPixelRegionIterator(Imagick source, int x, int y, int columns, int rows)
	Returns a new pixel region iterator, static method. This is equivalent to the non-static
	Imagick::getPixelRegionIterator which ought to be used in preference to this method.
*/
PHP_METHOD(ImagickPixelIterator, getPixelRegionIterator)
{
	PixelIterator *pixel_it;
	zval *magick_object;
	php_imagick_object *intern;
	long x, y, columns, rows;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "Ollll", &magick_object, php_imagick_sc_entry, &x, &y, &columns, &rows) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(magick_object);

	if (!intern->magick_wand) {
		php_imagick_throw_exception (IMAGICKPIXELITERATOR_CLASS, "Invalid Imagick object passed" TSRMLS_CC);
		return;
	}

	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	pixel_it = NewPixelRegionIterator(intern->magick_wand, x, y, columns, rows);
	if (!pixel_it) {
		php_imagick_throw_exception (IMAGICKPIXELITERATOR_CLASS, "Can not allocate ImagickPixelIterator" TSRMLS_CC);
		return;
	}

	php_imagick_pixel_iterator_new (pixel_it, return_value TSRMLS_CC);
	return;
}
/* }}} */

/* {{{ proto bool ImagickPixelIterator::newPixelRegionIterator(Imagick source, int x, int y, int columns, int rows)
	Returns a new pixel iterator.
*/
PHP_METHOD(ImagickPixelIterator, newPixelRegionIterator)
{
	PixelIterator *pixel_it;
	zval *magick_object;
	php_imagickpixeliterator_object *internpix;
	php_imagick_object *intern;
	long x, y, columns, rows;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "Ollll", &magick_object, php_imagick_sc_entry, &x, &y, &columns, &rows) == FAILURE) {
		return;
	}

	IMAGICK_METHOD_DEPRECATED_USE_INSTEAD("ImagickPixelIterator", "newPixelRegionIterator", "ImagickPixelIterator", "getPixelRegionIterator");

	internpix = Z_IMAGICKPIXELITERATOR_P(getThis());
	intern = Z_IMAGICK_P(magick_object);

	if (!intern->magick_wand) {
		php_imagick_throw_exception (IMAGICKPIXELITERATOR_CLASS, "Invalid Imagick object passed" TSRMLS_CC);
		return;
	}

	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	pixel_it = NewPixelRegionIterator(intern->magick_wand, x, y, columns, rows);

	if (!pixel_it) {
		php_imagick_throw_exception (IMAGICKPIXELITERATOR_CLASS, "Can not allocate ImagickPixelIterator" TSRMLS_CC);
		return;
	}

	if (internpix->initialized && internpix->pixel_iterator)
		DestroyPixelIterator (internpix->pixel_iterator);

	internpix->pixel_iterator = pixel_it;

#if MagickLibVersion <= 0x628
	internpix->rows = s_count_pixeliterator_rows (internpix);
#endif
	internpix->initialized = 1;
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto int ImagickPixelIterator::getIteratorRow()
	Returns the crurent pixel iterator row.
*/
PHP_METHOD(ImagickPixelIterator, getIteratorRow)
{
	php_imagickpixeliterator_object *internpix;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	internpix = Z_IMAGICKPIXELITERATOR_P(getThis());

	if (!internpix->initialized) {
		php_imagick_throw_exception (IMAGICKPIXELITERATOR_CLASS, "ImagickPixelIterator is not initialized correctly" TSRMLS_CC);
		return;
	}

#if MagickLibVersion <= 0x628
	ZVAL_LONG(return_value, internpix->iterator_position);
#else
	ZVAL_LONG(return_value, (long) PixelGetIteratorRow(internpix->pixel_iterator));
#endif
	return;
}
/* }}} */

/* {{{ proto bool ImagickPixelIterator::setIteratorRow(int row)
	Set the pixel iterator row.
*/
PHP_METHOD(ImagickPixelIterator, setIteratorRow)
{
	php_imagickpixeliterator_object *internpix;
	MagickBooleanType status;
	long row;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &row) == FAILURE) {
		return;
	}

	internpix = Z_IMAGICKPIXELITERATOR_P(getThis());

	if (!internpix->initialized) {
		php_imagick_throw_exception (IMAGICKPIXELITERATOR_CLASS, "ImagickPixelIterator is not initialized correctly" TSRMLS_CC);
		return;
	}

	status = PixelSetIteratorRow(internpix->pixel_iterator, row);

	if (status == MagickFalse) {
		php_imagick_convert_imagickpixeliterator_exception(internpix->pixel_iterator, "Unable to set iterator row" TSRMLS_CC);
		return;
	}
#if MagickLibVersion <= 0x628
	internpix->iterator_position = row;
#endif
	RETURN_TRUE;
}
/* }}} */

static
void s_pixelwands_to_zval (PixelWand **wand_array, unsigned long num_wands, zval *return_value TSRMLS_DC)
{
	php_imagickpixel_object *internp;
#ifdef ZEND_ENGINE_3
	zval obj;
#else
	zval *obj;
#endif

	unsigned long i;

	array_init(return_value);

	for (i = 0; i < num_wands; i++) {
#ifdef ZEND_ENGINE_3
		object_init_ex(&obj, php_imagickpixel_sc_entry);
		internp = Z_IMAGICKPIXEL_P(&obj);
#else 
		MAKE_STD_ZVAL(obj);
		object_init_ex(obj, php_imagickpixel_sc_entry);
		internp = Z_IMAGICKPIXEL_P(obj);
#endif

		internp->initialized_via_iterator = 1;

		php_imagick_replace_pixelwand(internp, wand_array[i]);
#ifdef ZEND_ENGINE_3
		add_next_index_zval(return_value, &obj);
#else
		add_next_index_zval(return_value, obj);
#endif
	}

}

/* {{{ proto array ImagickPixelIterator::getPreviousIteratorRow()
	Returns the previous row as an array of pixel wands from the pixel iterator.
*/
PHP_METHOD(ImagickPixelIterator, getPreviousIteratorRow)
{
	php_imagickpixeliterator_object *internpix;
	PixelWand **wand_array;
	size_t num_wands;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	internpix = Z_IMAGICKPIXELITERATOR_P(getThis());

	if (!internpix->initialized) {
		php_imagick_throw_exception (IMAGICKPIXELITERATOR_CLASS, "ImagickPixelIterator is not initialized correctly" TSRMLS_CC);
		return;
	}

	wand_array = PixelGetPreviousIteratorRow(internpix->pixel_iterator, &num_wands);

#if MagickLibVersion <= 0x628
	if (internpix->iterator_position > 0) {
		internpix->iterator_position--;
	}
#endif

	if (!wand_array) {
		RETURN_NULL();
	}

	s_pixelwands_to_zval (wand_array, num_wands, return_value TSRMLS_CC);
	return;
}
/* }}} */


/* {{{ proto array ImagickPixelIterator::getCurrentIteratorRow()
	Returns the current row as an array of pixel wands from the pixel iterator.
*/
PHP_METHOD(ImagickPixelIterator, getCurrentIteratorRow)
{
	php_imagickpixeliterator_object *internpix;
	PixelWand **wand_array;
	size_t num_wands;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	internpix = Z_IMAGICKPIXELITERATOR_P(getThis());

	if (!internpix->initialized) {
		php_imagick_throw_exception (IMAGICKPIXELITERATOR_CLASS, "ImagickPixelIterator is not initialized correctly" TSRMLS_CC);
		return;
	}

#if MagickLibVersion <= 0x628
	if (internpix->iterator_position >= internpix->rows) {
		RETURN_NULL();
	} else if (internpix->iterator_position != 0) {
		long tmp;
		(void)PixelGetPreviousIteratorRow(internpix->pixel_iterator, &tmp);
	}
	wand_array = PixelGetNextIteratorRow(internpix->pixel_iterator, &num_wands);
#else
	wand_array = PixelGetCurrentIteratorRow(internpix->pixel_iterator, &num_wands);
#endif

	if (!wand_array) {
		RETURN_NULL();
	}

	s_pixelwands_to_zval (wand_array, num_wands, return_value TSRMLS_CC);
	return;
}
/* }}} */

/* {{{ proto array ImagickPixelIterator::getNextIteratorRow()
	Returns the next row as an array of pixel wands from the pixel iterator.
*/
PHP_METHOD(ImagickPixelIterator, getNextIteratorRow)
{
	php_imagickpixeliterator_object *internpix;
	PixelWand **wand_array;
	size_t num_wands;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	internpix = Z_IMAGICKPIXELITERATOR_P(getThis());

	if (!internpix->initialized) {
		php_imagick_throw_exception (IMAGICKPIXELITERATOR_CLASS, "ImagickPixelIterator is not initialized correctly" TSRMLS_CC);
		return;
	}

	wand_array = PixelGetNextIteratorRow(internpix->pixel_iterator, &num_wands);

#if MagickLibVersion <= 0x628
	internpix->iterator_position++;
#endif

	if (!wand_array) {
		RETURN_NULL();
	}

	s_pixelwands_to_zval (wand_array, num_wands, return_value TSRMLS_CC);
	return;
}
/* }}} */

/* {{{ proto bool ImagickPixelIterator::clear()
	Clear resources associated with a PixelIterator.
*/
PHP_METHOD(ImagickPixelIterator, clear)
{
	php_imagickpixeliterator_object *internpix;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	internpix = Z_IMAGICKPIXELITERATOR_P(getThis());

	if (!internpix->initialized) {
		php_imagick_throw_exception (IMAGICKPIXELITERATOR_CLASS, "ImagickPixelIterator is not initialized correctly" TSRMLS_CC);
		return;
	}
/* Assertion failure with earlier versions */
#if MagickLibVersion <= 0x628
	RETURN_TRUE;
#else
	ClearPixelIterator(internpix->pixel_iterator);
	RETURN_TRUE;
#endif
}
/* }}} */

/* {{{ proto bool ImagickPixelIterator::valid()
	The if the current iterator row is valid
*/
PHP_METHOD(ImagickPixelIterator, valid)
{
	php_imagickpixeliterator_object *internpix;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	internpix = Z_IMAGICKPIXELITERATOR_P(getThis());

	if (!internpix->initialized) {
		php_imagick_throw_exception (IMAGICKPIXELITERATOR_CLASS, "ImagickPixelIterator is not initialized correctly" TSRMLS_CC);
		return;
	}
#if MagickLibVersion <= 0x628
	if (internpix->iterator_position < internpix->rows) {
		RETURN_TRUE;
	}
#else
	/* Test if the current row is valid */
	if (PixelSetIteratorRow(internpix->pixel_iterator, PixelGetIteratorRow(internpix->pixel_iterator))) {
		 RETURN_TRUE;
	}
#endif
	RETURN_FALSE;
}
/* }}} */

/* END OF PIXELITERATOR */
