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
#include "php_imagick_file.h"


#if MagickLibVersion > 0x628
/* {{{ proto bool Imagick::pingImageFile(resource filehandle)
    Query image information without reading the whole image to memory
*/
PHP_METHOD(Imagick, pingImageFile)
{
	char *filename = NULL;
	IM_LEN_TYPE filename_len;
	php_imagick_object *intern;
	zval *zstream;
	php_stream *stream;
	zend_bool result;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "r|s!", &zstream, &filename, &filename_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

#ifdef ZEND_ENGINE_3
	php_stream_from_zval(stream, zstream);
#else
	php_stream_from_zval(stream, &zstream);
#endif
	result = php_imagick_stream_handler(intern, stream, ImagickPingImageFile TSRMLS_CC);

	if (result == 0) {
		if (!EG(exception)) {
			php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to ping image from the filehandle" TSRMLS_CC);
		}
		return;
	}

	if (filename) {
		MagickSetImageFilename(intern->magick_wand, filename);
		MagickSetLastIterator(intern->magick_wand);
	}
	RETURN_TRUE;
}
/* }}} */


/* {{{ proto bool Imagick::pingImageBlob(string image )
	Query image information without reading the whole image to memory
*/
PHP_METHOD(Imagick, pingImageBlob)
{
	char *image_string;
	IM_LEN_TYPE image_string_len;
	MagickBooleanType status;
	php_imagick_object *intern;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &image_string, &image_string_len) == FAILURE) {
		return;
	}

	if (image_string_len == 0) {
		php_imagick_throw_exception(IMAGICK_CLASS, "Empty image string passed" TSRMLS_CC);
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	status = MagickPingImageBlob(intern->magick_wand, image_string, image_string_len);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to ping image blob" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::vignetteImage(float blackPoint, float whitePoint, int x, int y )
	Adds vignette filter to the image
*/
PHP_METHOD(Imagick, vignetteImage)
{
	double black_point, white_point;
	im_long x, y;
	php_imagick_object *intern;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ddll", &black_point, &white_point, &x, &y) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickVignetteImage(intern->magick_wand, black_point, white_point, x, y);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to apply vignette filter" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::transposeImage()
	Creates a vertical mirror image
*/
PHP_METHOD(Imagick, transposeImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickTransposeImage(intern->magick_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to transpose image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::transverseImage()
	Creates a horizontal mirror image
*/
PHP_METHOD(Imagick, transverseImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickTransverseImage(intern->magick_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to transverse image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::adaptiveBlurImage(float radius, float sigma[, int channel] )
	Adds adaptive blur filter to image
*/
PHP_METHOD(Imagick, adaptiveBlurImage)
{
	double radius, sigma;
	php_imagick_object *intern;
	MagickBooleanType status;
	im_long channel = IM_DEFAULT_CHANNEL;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dd|l", &radius, &sigma, &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickAdaptiveBlurImageChannel(intern->magick_wand, channel, radius, sigma);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to adaptive blur image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::uniqueImageColors()
	Discards all but one of any pixel color
*/
PHP_METHOD(Imagick, uniqueImageColors)
{
	php_imagick_object *intern;
	MagickBooleanType status;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickUniqueImageColors(intern->magick_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to get unique image colors" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::contrastStretchImage(float black_point, float white_point[, int channel])
	Enhances the contrast of a color image
*/
PHP_METHOD(Imagick, contrastStretchImage)
{
	php_imagick_object *intern;
	double black_point, white_point;
	MagickBooleanType status;
	im_long channel = IM_DEFAULT_CHANNEL;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dd|l", &black_point, &white_point, &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickContrastStretchImageChannel(intern->magick_wand, channel, black_point, white_point);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to contrast strech image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
/* {{{ proto int Imagick::getImageMatte()
	Returns true if the image has a matte channel otherwise false
*/
PHP_METHOD(Imagick, getImageMatte)
{
	php_imagick_object *intern;
	MagickBooleanType matte;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	IMAGICK_METHOD_DEPRECATED ("Imagick", "getImageMatte");

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	matte = MagickGetImageMatte(intern->magick_wand);

	if (matte == MagickTrue) {
		RETURN_TRUE;
	} else {
		RETURN_FALSE;
	}
}
/* }}} */
#endif //#if MagickLibVersion < 0x700
#endif

/* {{{ proto bool Imagick::setImageMatte(bool matte)
	Sets the image matte channel
*/
PHP_METHOD(Imagick, setImageMatte)
{
	php_imagick_object *intern;
	zend_bool matte;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "b", &matte) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSetImageMatte(intern->magick_wand, matte);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image matte" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::adaptiveResizeImage(int width, int height[, bool bestfit[, bool legacy]]])
	Adaptively resize image with data dependent triangulation
	If legacy is true, the calculations are done with the small rounding bug that existed in
	Imagick before 3.4.0. If false, the calculations should produce the same results as 
	ImageMagick CLI does.
*/
PHP_METHOD(Imagick, adaptiveResizeImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	im_long width, height, new_width, new_height;
	zend_bool bestfit = 0;
	zend_bool legacy = 0;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll|bb", &width, &height, &bestfit, &legacy) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	if (!php_imagick_thumbnail_dimensions(intern->magick_wand, bestfit, width, height, &new_width, &new_height, legacy)) {
		php_imagick_throw_exception(IMAGICK_CLASS, "Invalid image geometry" TSRMLS_CC);
		return;
	}

	status = MagickAdaptiveResizeImage(intern->magick_wand, new_width, new_height);

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to adaptive resize image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */
/* {{{ proto bool Imagick::sketchImage(float radius, float sigma, float angle)
	Simulates a pencil sketch
*/
PHP_METHOD(Imagick, sketchImage)
{
	double radius, sigma, angle;
	MagickBooleanType status;
	php_imagick_object *intern;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ddd", &radius, &sigma, &angle) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSketchImage(intern->magick_wand, sigma, radius, angle);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to sketch image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::shadeImage(bool gray, float azimuth, float elevation)
	Shines a distant light on an image
*/
PHP_METHOD(Imagick, shadeImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	double azimuth, elevation;
	zend_bool gray;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "bdd", &gray, &azimuth, &elevation) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickShadeImage(intern->magick_wand, gray, azimuth, elevation);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to shade image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto int Imagick::getSizeOffset()
	Returns the size offset associated with the Imagick object
*/
PHP_METHOD(Imagick, getSizeOffset)
{
	php_imagick_object *intern;
	ssize_t offset;
	MagickBooleanType status;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	status = MagickGetSizeOffset(intern->magick_wand, &offset);

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to get size offset" TSRMLS_CC);
		return;
	}

	RETVAL_LONG(offset);
}
/* }}} */

/* {{{ proto bool Imagick::setSizeOffset(int columns, int rows, int offset)
	Sets the size and offset of the Imagick object
*/
PHP_METHOD(Imagick, setSizeOffset)
{
	php_imagick_object *intern;
	im_long columns, rows, offset;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "lll", &columns, &rows, &offset) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	status = MagickSetSizeOffset(intern->magick_wand, columns, rows, offset);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set size offset" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::adaptiveSharpenImage(float radius, float sigma[, int channel])
	Adaptively sharpen image with data dependent triangulation
*/
PHP_METHOD(Imagick, adaptiveSharpenImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	double radius, sigma;
	im_long channel = IM_DEFAULT_CHANNEL;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dd|l", &radius, &sigma, &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickAdaptiveSharpenImageChannel(intern->magick_wand, channel, radius, sigma);

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to adaptive sharpen image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */


/* {{{ proto bool Imagick::randomThresholdImage(float low, float high[, int channel])
	Changes the value of individual pixels
*/
PHP_METHOD(Imagick, randomThresholdImage)
{
	php_imagick_object *intern;
	double low, high;
	MagickBooleanType status;
	im_long channel = IM_DEFAULT_CHANNEL;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dd|l", &low, &high, &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickRandomThresholdImageChannel(intern->magick_wand, channel, low, high);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to random threshold image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto string Imagick::roundCornersImage(float x_rounding, float y_rounding[, float stroke_width = 10[, float displace = 5[, float size_correction = -6]]] )
   Rounds image corners
*/
#if MagickLibVersion < 0x700
PHP_METHOD(Imagick, roundCornersImage)
{
	char *old_locale;
	double x_rounding, y_rounding;
	DrawingWand *draw;
	MagickWand *mask_image;
	PixelWand *color;
	php_imagick_object *intern;
	long image_width, image_height;
	MagickBooleanType status;
	double stroke_width = 10, displace = 5, correction = -6;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dd|ddd", &x_rounding, &y_rounding, &stroke_width, &displace, &correction) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	image_width = MagickGetImageWidth(intern->magick_wand);
	image_height = MagickGetImageHeight(intern->magick_wand);

	if (!image_width || !image_height) {
	    php_imagick_throw_exception(IMAGICK_CLASS, "Unable to round corners on empty image" TSRMLS_CC);
		return;
	}

	status = MagickSetImageMatte(intern->magick_wand, MagickTrue);

	if (status == MagickFalse) {
		php_imagick_throw_exception(IMAGICK_CLASS, "Unable to set image matte" TSRMLS_CC);
		return;
	}

	/* Here we go.. */
	color = NewPixelWand();
	if (!color) {
		php_imagick_throw_exception (IMAGICK_CLASS, "Failed to allocate PixelWand structure" TSRMLS_CC);
		return;
	}

	draw = NewDrawingWand();
	if (!draw) {
		DestroyPixelWand (color);
		php_imagick_throw_exception (IMAGICK_CLASS, "Failed to allocate DrawingWand structure" TSRMLS_CC);
		return;
	}

	mask_image = NewMagickWand();
	if (!mask_image) {
		DestroyPixelWand (color);
		DestroyDrawingWand (draw);
		php_imagick_throw_exception (IMAGICK_CLASS, "Failed to allocate MagickWand structure" TSRMLS_CC);
		return;
	}


#define exit_cleanup() \
	if (color != NULL) color = DestroyPixelWand(color); \
	if (draw != NULL) draw = DestroyDrawingWand(draw); \
	if (mask_image != NULL) mask_image = DestroyMagickWand(mask_image);

	status = PixelSetColor(color, "transparent");

	if (status == MagickFalse) {
        exit_cleanup();
		php_imagick_throw_exception(IMAGICK_CLASS, "Unable to set pixel color" TSRMLS_CC);
		return;
	}

	status = MagickNewImage(mask_image, image_width, image_height, color);

	if (status == MagickFalse) {
		exit_cleanup();
		php_imagick_throw_exception(IMAGICK_CLASS, "Unable to allocate mask image" TSRMLS_CC);
		return;
	}

	MagickSetImageBackgroundColor(mask_image, color);
	status = PixelSetColor(color, "white");

	if (status == MagickFalse) {
		exit_cleanup();
		php_imagick_throw_exception(IMAGICK_CLASS, "Unable to set pixel color" TSRMLS_CC);
		return;
	}

	DrawSetFillColor(draw, color);
	status = PixelSetColor(color, "black");

	if (status == MagickFalse) {
		exit_cleanup();
		php_imagick_throw_exception(IMAGICK_CLASS, "Unable to set pixel color" TSRMLS_CC);
		return;
	}

	DrawSetStrokeColor(draw, color);
	DrawSetStrokeWidth(draw, stroke_width);
	DrawRoundRectangle(draw, displace, displace, image_width + correction, image_height + correction, x_rounding, y_rounding);

	old_locale = php_imagick_set_locale (TSRMLS_C);

	status = MagickDrawImage(mask_image, draw);

	php_imagick_restore_locale (old_locale);

	if (old_locale)
		efree (old_locale);

	if (status == MagickFalse) {
		exit_cleanup();
		php_imagick_throw_exception(IMAGICK_CLASS, "Unable to draw on image" TSRMLS_CC);
		return;
	}

	status = MagickCompositeImage(intern->magick_wand, mask_image, DstInCompositeOp, 0, 0);

	if (status == MagickFalse) {
		exit_cleanup();
		php_imagick_throw_exception(IMAGICK_CLASS, "Unable to composite image" TSRMLS_CC);
		return;
	}

	exit_cleanup();
	RETURN_TRUE;
#undef exit_cleanup
}
/* }}} */
#endif

/* {{{ proto int Imagick::getIteratorIndex()
	Returns the index of the current active image
*/
PHP_METHOD(Imagick, getIteratorIndex)
{
	MagickBooleanType status;
	php_imagick_object *intern;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	status = MagickGetIteratorIndex(intern->magick_wand);
	ZVAL_LONG(return_value, (long)status);
	return;
}
/* }}} */

/* {{{ proto bool Imagick::setIteratorIndex(int index)
	Sets the index of the Imagick object
*/
PHP_METHOD(Imagick, setIteratorIndex)
{
	const im_long index;
	MagickBooleanType status;
	php_imagick_object *intern;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &index) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	status = MagickSetIteratorIndex(intern->magick_wand, index);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set iterator index" TSRMLS_CC);
		return;
	}

	intern->next_out_of_bound = 0;
	RETURN_TRUE;
}
/* }}} */

#if MagickLibVersion < 0x700
/* {{{ proto Imagick Imagick::transformImage(string crop, string geometry )
	Comfortability method for crop and resize
*/
PHP_METHOD(Imagick, transformImage)
{
	char *crop, *geometry;
	IM_LEN_TYPE crop_len, geometry_len;
	MagickWand *transformed;
	php_imagick_object *intern, *intern_return;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss", &crop, &crop_len, &geometry, &geometry_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	transformed = MagickTransformImage(intern->magick_wand, crop, geometry);

	if (!transformed) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Transforming image failed" TSRMLS_CC);
		return;
	}

	object_init_ex(return_value, php_imagick_sc_entry);
	intern_return = Z_IMAGICK_P(return_value);

	php_imagick_replace_magickwand(intern_return, transformed);
	return;
}
#endif //#if MagickLibVersion < 0x700

/* }}} */
#endif

#if MagickLibVersion > 0x630
#if MagickLibVersion < 0x700
/* {{{ proto bool Imagick::setImageOpacity(float opacity)
	Sets the image to the specified opacity level
*/
PHP_METHOD(Imagick, setImageOpacity)
{
	double opacity;
	MagickBooleanType status;
	php_imagick_object *intern;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d", &opacity) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSetImageOpacity(intern->magick_wand, opacity);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image opacity" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */
#endif



#if MagickLibVersion >= 0x700
/* {{{ proto bool Imagick::setImageAlpha(float alpha)
	Sets the image to the specified alpha level
*/
PHP_METHOD(Imagick, setImageAlpha)
{
	double alpha;
	MagickBooleanType status;
	php_imagick_object *intern;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d", &alpha) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSetImageAlpha(intern->magick_wand, alpha);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image alpha" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */
#endif 



#if MagickLibVersion < 0x700
/* {{{ proto bool Imagick::orderedPosterizeImage(string threshold_map[, int CHANNEL])
	Performs an ordered dither
*/
PHP_METHOD(Imagick, orderedPosterizeImage)
{
	char *map;
	IM_LEN_TYPE map_len;
	MagickBooleanType status;
	php_imagick_object *intern;
	im_long channel = IM_DEFAULT_CHANNEL;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|l", &map, &map_len, &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickOrderedPosterizeImageChannel(intern->magick_wand, channel, map);

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to posterize image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */
#endif //#if MagickLibVersion < 0x700
#endif //#if MagickLibVersion > 0x630

#if MagickLibVersion > 0x631
/* {{{ proto bool Imagick::polaroidImage(ImagickDraw properties, double angle )
	Simulates a Polaroid picture
*/
PHP_METHOD(Imagick, polaroidImage)
{
	zval *objvar;
	php_imagick_object *intern;
	MagickBooleanType status;
	php_imagickdraw_object *internd;
	double angle;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "Od", &objvar, php_imagickdraw_sc_entry, &angle) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;	

	internd = Z_IMAGICKDRAW_P(objvar);
#if MagickLibVersion >= 0x700
	{
		PixelInterpolateMethod method = BilinearInterpolatePixel;
		char *caption = "TODO FIXME";
		status = MagickPolaroidImage(intern->magick_wand,internd->drawing_wand,caption,angle,method);
	}
#else
	status = MagickPolaroidImage(intern->magick_wand, internd->drawing_wand, angle);
#endif

	
	

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to polaroid image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto string Imagick::getImageProperty(string name )
	Eeturns a value associated with the specified property
*/
PHP_METHOD(Imagick, getImageProperty)
{
	php_imagick_object *intern;
	char *name, *value;
	IM_LEN_TYPE name_len;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &name, &name_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	value = MagickGetImageProperty(intern->magick_wand, name);

	if (value) {
		IM_ZVAL_STRING(return_value, (char *)value);
		IMAGICK_FREE_MAGICK_MEMORY(value);
		return;
	}
	RETURN_FALSE;
}
/* }}} */

/* {{{ proto bool Imagick::setImageProperty(string name, string value )
	returns a value associated with the specified property
*/
PHP_METHOD(Imagick, setImageProperty)
{
	php_imagick_object *intern;
	char *name, *value;
	IM_LEN_TYPE name_len, value_len;
	MagickBooleanType status;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss", &name, &name_len, &value, &value_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;
	status = MagickSetImageProperty(intern->magick_wand, name, value);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image property" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::deleteImageProperty(string name)
	Deletes an image property.
*/
PHP_METHOD(Imagick, deleteImageProperty)
{
	php_imagick_object *intern;
	char *name;
	IM_LEN_TYPE name_len;
	MagickBooleanType status;

	Image *image;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &name, &name_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	image = GetImageFromMagickWand(intern->magick_wand);
	status = DeleteImageProperty(image, name);

	if (status == MagickFalse) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */


/* {{{ proto bool Imagick::identifyFormat(string embedText)
	Replaces any embedded formatting characters with the appropriate image property and returns the interpreted text. See http://www.imagemagick.org/script/escape.php for escape sequences.
*/
PHP_METHOD(Imagick, identifyFormat)
{
	php_imagick_object *intern;
	char *embedText;
	IM_LEN_TYPE embedText_len;
	char *result;

	ImageInfo *image_info;
	Image *image;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &embedText, &embedText_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0) {
		return;
	}

	image_info = AcquireImageInfo();
	image = GetImageFromMagickWand(intern->magick_wand);
	
#if MagickLibVersion >= 0x700
	{
		//TODO - handle exception info.
		ExceptionInfo *exception = NULL;
		result = InterpretImageProperties(image_info, image, embedText, exception);
	}
#else
	result = InterpretImageProperties(image_info, image, embedText);
#endif
	image_info = DestroyImageInfo(image_info);

	if (result) {
#ifdef ZEND_ENGINE_3 
		RETVAL_STRING(result);
#else
		RETVAL_STRING(result, 1);
#endif
		IMAGICK_FREE_MAGICK_MEMORY(result);

		return;
	}

	RETURN_FALSE;
}
/* }}} */

/* {{{ proto int Imagick::getImageInterpolateMethod()
	Returns the interpolation method for the sepcified image.
*/
PHP_METHOD(Imagick, getImageInterpolateMethod)
{
	php_imagick_object *intern;
	long interpolate;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	interpolate = MagickGetImageInterpolateMethod(intern->magick_wand);
	RETVAL_LONG(interpolate);
}
/* }}} */

#if MagickLibVersion >= 0x631
/* {{{ proto bool Imagick::setImageInterpolateMethod(int method)
	Sets the image interpolate pixel method.
*/
PHP_METHOD(Imagick, setImageInterpolateMethod)
{
	php_imagick_object *intern;
	im_long interpolate;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &interpolate) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSetImageInterpolateMethod(intern->magick_wand, interpolate);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set the image interpolate method" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */
#endif // #if MagickLibVersion >= 0x631

/* {{{ proto bool Imagick::linearStretchImage(float blackPoint, float whitePoint)
	Stretches with saturation the image intensity.
*/
PHP_METHOD(Imagick, linearStretchImage)
{
	php_imagick_object *intern;
	double blackPoint, whitePoint;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dd", &blackPoint, &whitePoint) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickLinearStretchImage(intern->magick_wand, blackPoint, whitePoint);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to linear strech image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto int Imagick::getImageLength()
	returns the image length in bytes
*/
PHP_METHOD(Imagick, getImageLength)
{
	php_imagick_object *intern;
	MagickSizeType length;
	MagickBooleanType status;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickGetImageLength(intern->magick_wand, &length);

	if (status == MagickFalse) {
		php_imagick_throw_exception(IMAGICK_CLASS, "Unable to acquire image length" TSRMLS_CC);
		return;
	}

	RETVAL_LONG(length);
}
/* }}} */

/* {{{ proto bool Imagick::extentImage(int width, int height, int x, int y )
	Sets the image size
*/
PHP_METHOD(Imagick, extentImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	im_long width, height, x, y;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "llll", &width, &height, &x, &y) == FAILURE)
	{
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickExtentImage(intern->magick_wand, width, height, x, y);

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to extent image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */
#endif

#if MagickLibVersion > 0x633
/* {{{ proto Imagick Imagick::getImageOrientation(void)
   Gets the image orientation
*/
PHP_METHOD(Imagick, getImageOrientation)
{
	php_imagick_object *intern;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	RETVAL_LONG(MagickGetImageOrientation(intern->magick_wand));
}
/* }}} */

/* {{{ proto Imagick Imagick::setImageOrientation(int orientation)
   Sets the image orientation
*/
PHP_METHOD(Imagick, setImageOrientation)
{
	php_imagick_object *intern;
	im_long orientation;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &orientation) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSetImageOrientation(intern->magick_wand, orientation);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image orientation" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */
#endif

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion > 0x634
#if MagickLibVersion < 0x700
/* {{{ proto Imagick Imagick::paintFloodfillImage(mixed fill, float fuzz, mixed bordercolor, int x, int y[, int channel])
   Sets the image orientation
*/
PHP_METHOD(Imagick, paintFloodfillImage)
{
	php_imagick_object *intern;
	zval *fill_param, *border_param;
	im_long x, y, channel = DefaultChannels;
	double fuzz;
	MagickBooleanType status;
	PixelWand *fill_wand, *border_wand = NULL;
	zend_bool fill_allocated = 0, border_allocated = 0;

	IMAGICK_METHOD_DEPRECATED ("Imagick", "paintFloodfillImage");

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zdzll|l", &fill_param, &fuzz, &border_param, &x, &y, &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	fill_wand = php_imagick_zval_to_pixelwand (fill_param, IMAGICK_CLASS, &fill_allocated TSRMLS_CC);
	if (!fill_wand)
		return;

	if (Z_TYPE_P(border_param) == IS_NULL) {
		status = MagickPaintFloodfillImage(intern->magick_wand, channel, fill_wand, fuzz, NULL, x, y);
	} else {
		border_wand = php_imagick_zval_to_pixelwand (border_param, IMAGICK_CLASS, &border_allocated TSRMLS_CC);
		if (!border_wand) {
			if (fill_allocated)
				DestroyPixelWand (fill_wand);
			return;
		}
		status = MagickPaintFloodfillImage(intern->magick_wand, channel, fill_wand, fuzz, border_wand, x, y);
	}

	if (fill_allocated)
		DestroyPixelWand (fill_wand);

	if (border_wand)
		DestroyPixelWand (border_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to paint floodfill image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */
#endif // #if MagickLibVersion < 0x700
#endif
#endif

#if MagickLibVersion > 0x635
/* {{{ proto Imagick Imagick::clutImage(Imagick lookup[, int channel] )
   Replaces colors in the image from a color lookup table
*/
PHP_METHOD(Imagick, clutImage)
{
	zval *objvar;
	php_imagick_object *intern, *lookup;
	MagickBooleanType status;
	im_long channel = IM_DEFAULT_CHANNEL;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "O|l", &objvar, php_imagick_sc_entry, &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	lookup = Z_IMAGICK_P(objvar);
	if (php_imagick_ensure_not_empty (lookup->magick_wand) == 0)
		return;

	status = MagickClutImageChannel(intern->magick_wand, channel, lookup->magick_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to replace colors in the image from a color lookup table" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto Imagick Imagick::getImageProperties([string pattern, bool values] )
  	Returns all the property names that match the specified pattern
*/
PHP_METHOD(Imagick, getImageProperties)
{
	zend_bool values = 1;
	char *pattern = "*", **properties, *property;
	IM_LEN_TYPE pattern_len;
	unsigned long i;
	size_t properties_count;
	php_imagick_object *intern;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|sb", &pattern, &pattern_len, &values) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	properties = MagickGetImageProperties(intern->magick_wand, pattern, &properties_count);

	if (!properties) {
		php_imagick_throw_exception(IMAGICK_CLASS, "Unable to get image properties" TSRMLS_CC);
		return;
	}

	array_init(return_value);

	if (values) {

		for (i = 0; i < properties_count; i++) {
			property = MagickGetImageProperty(intern->magick_wand, properties[i]);
			IM_add_assoc_string(return_value, properties[i], property);
			IMAGICK_FREE_MAGICK_MEMORY(property);
		}

	} else {

		for (i = 0; i < properties_count; i++) {
			IM_add_next_index_string(return_value, properties[i]);
		}
	}

	IMAGICK_FREE_MAGICK_MEMORY(properties);
	return;
}
/* }}} */

/* {{{ proto Imagick Imagick::getImageProfiles([string pattern, bool values] )
  	Returns all the profile names that match the specified pattern
*/
PHP_METHOD(Imagick, getImageProfiles)
{
	zend_bool values = 1;
	char *pattern = "*", **profiles, *profile;
	IM_LEN_TYPE pattern_len;
	unsigned long i;
	php_imagick_object *intern;
	size_t length, profiles_count;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|sb", &pattern, &pattern_len, &values) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	profiles = MagickGetImageProfiles(intern->magick_wand, pattern, &profiles_count);

	if (!profiles) {
		php_imagick_throw_exception(IMAGICK_CLASS, "Unable to get image profiles" TSRMLS_CC);
		return;
	}

	array_init(return_value);

	if (values) {

		for (i = 0; i < profiles_count; i++) {

			profile = (char *)MagickGetImageProfile(intern->magick_wand, profiles[i], &length);
#ifdef ZEND_ENGINE_3
			add_assoc_stringl(return_value, profiles[i], profile, length);
#else
			add_assoc_stringl(return_value, profiles[i], profile, length, 1);
#endif
			IMAGICK_FREE_MAGICK_MEMORY(profile);
		}

	} else {

		for (i = 0; i < profiles_count; i++) {
			IM_add_next_index_string(return_value, profiles[i]);
		}
	}

	IMAGICK_FREE_MAGICK_MEMORY(profiles);
	return;
}
/* }}} */
#endif

#if MagickLibVersion > 0x635
/* {{{ proto Imagick Imagick::distortImage(int distortMethod, array arguments, bool bestfit )
   Distorts an image using various distortion methods
*/
PHP_METHOD(Imagick, distortImage)
{
	php_imagick_object *intern;
	double *arguments;
	im_long distort_method, elements;
	zend_bool bestfit;
	zval *arg_array;
	MagickBooleanType status;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "lab", &distort_method, &arg_array, &bestfit) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	arguments = php_imagick_zval_to_double_array(arg_array, &elements TSRMLS_CC);

	if (!arguments) {
		php_imagick_throw_exception (IMAGICK_CLASS, "Can't read argument array" TSRMLS_CC);
		return;
	}

	status = MagickDistortImage(intern->magick_wand, distort_method, elements, arguments, bestfit);
	efree(arguments);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to distort the image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::writeImageFile(resource $handle[, string $format])
	Writes image to an open filehandle. Optional parameter format defines the format the file
	is stored with
*/
PHP_METHOD(Imagick, writeImageFile)
{
	php_imagick_object *intern;
	zval *zstream;
	php_stream *stream;
	zend_bool result;
	char *format = NULL;
	IM_LEN_TYPE format_len;
	char *orig_name = NULL, *buffer;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "r|s!", &zstream, &format, &format_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	// Get the current name
	if (format) {
		orig_name = MagickGetImageFilename (intern->magick_wand);

		spprintf (&buffer, 0, "%s:", format);
		MagickSetImageFilename (intern->magick_wand, buffer);
		efree (buffer);
	}

#ifdef ZEND_ENGINE_3
	php_stream_from_zval(stream, zstream);
#else
	php_stream_from_zval(stream, &zstream);
#endif
	result = php_imagick_stream_handler(intern, stream, ImagickWriteImageFile TSRMLS_CC);

	/* Restore the original name after write */
	if (orig_name) {
		MagickSetImageFilename (intern->magick_wand, orig_name);
		MagickRelinquishMemory (orig_name);
	}

	if (result == 0) {
		/* php_stream_cast returns warning on some streams but still does not return FAILURE */
		if (!EG(exception)) {
			php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to write image to the filehandle" TSRMLS_CC);
			return;
		}
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::writeImagesFile(resource $handle[, string $format])
	Writes images to an open filehandle
*/
PHP_METHOD(Imagick, writeImagesFile)
{
	php_imagick_object *intern;
	zval *zstream;
	php_stream *stream;
	zend_bool result;
	char *format = NULL;
	IM_LEN_TYPE format_len;
	char *orig_name = NULL, *buffer;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "r|s!", &zstream, &format, &format_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	// Get the current name
	if (format) {
		orig_name = MagickGetImageFilename (intern->magick_wand);

		spprintf (&buffer, 0, "%s:", format);
		MagickSetImageFilename (intern->magick_wand, buffer);
		efree (buffer);
	}

#ifdef ZEND_ENGINE_3
	php_stream_from_zval(stream, zstream);
#else
	php_stream_from_zval(stream, &zstream);
#endif
	result = php_imagick_stream_handler(intern, stream, ImagickWriteImagesFile TSRMLS_CC);

	/* Restore the original name after write */
	if (orig_name) {
		MagickSetImageFilename (intern->magick_wand, orig_name);
		MagickRelinquishMemory (orig_name);
	}

	if (result == 0) {
		if (!EG(exception)) {
			php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to write images to the filehandle" TSRMLS_CC);
			return;
		}
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::resetImagePage(string page)
	Resets the page canvas and position
*/
PHP_METHOD(Imagick, resetImagePage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	char *page;
	IM_LEN_TYPE page_len;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &page, &page_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickResetImagePage(intern->magick_wand, page);

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to reset image page" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */


/* {{{ proto Imagick Imagick::getImageClipMask()
	Gets image clip mask
*/
#if MagickLibVersion < 0x700
PHP_METHOD(Imagick, getImageClipMask)
{
	MagickWand *tmp_wand;
	php_imagick_object *intern;
	php_imagick_object *intern_return;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	tmp_wand = MagickGetImageClipMask(intern->magick_wand);

	/* No magick is going to happen */
	if (!tmp_wand) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to get image clip mask" TSRMLS_CC);
		return;
	}

	object_init_ex(return_value, php_imagick_sc_entry);
	intern_return = Z_IMAGICK_P(return_value);

	php_imagick_replace_magickwand(intern_return, tmp_wand);
	return;
}
#endif
/* }}} */

/* {{{ proto bool Imagick::setImageClipMask(Imagick clip_mask)
	Sets the image clip mask
*/
#if MagickLibVersion < 0x700
PHP_METHOD(Imagick, setImageClipMask)
{
	php_imagick_object *intern;
	php_imagick_object *clip_mask;
	MagickBooleanType status;
	zval *objvar;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "O", &objvar, php_imagick_sc_entry) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	clip_mask = Z_IMAGICK_P(objvar);
	if (php_imagick_ensure_not_empty (clip_mask->magick_wand) == 0)
		return;

	status = MagickSetImageClipMask(intern->magick_wand, clip_mask->magick_wand);

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image clip mask" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
#endif
/* }}} */

/* {{{ proto bool Imagick::animateImages(string server_name)
	Animates an image or image sequence
*/
PHP_METHOD(Imagick, animateImages)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	char *server_name;
	IM_LEN_TYPE server_name_len;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &server_name, &server_name_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	/* TODO: should this call be there? Not sure */
	(void)MagickSetFirstIterator(intern->magick_wand);
	status = MagickAnimateImages(intern->magick_wand, server_name);

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to animate images" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
/* {{{ proto bool Imagick::recolorImage(array matrix)
	Translate, scale, shear, or rotate image colors
*/
PHP_METHOD(Imagick, recolorImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	im_long num_elements;
	zval *matrix;
	double *array;
	unsigned long order;

	IMAGICK_METHOD_DEPRECATED ("Imagick", "recolorImage");

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "a", &matrix) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	array = php_imagick_zval_to_double_array(matrix, &num_elements TSRMLS_CC);

	if (!array) {
		php_imagick_throw_exception (IMAGICK_CLASS, "The map contains disallowed characters" TSRMLS_CC);
		return;
	}

	order = (unsigned long)sqrt(num_elements);

	if ((order * order) != num_elements) {
		efree(array);
		php_imagick_throw_exception(IMAGICK_CLASS, "The color matrix must contain a square number of elements" TSRMLS_CC);
		return;
	}

	status = MagickRecolorImage(intern->magick_wand, order, array);
	efree(array);

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to recolor image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */
#endif
#endif
#endif

#if MagickLibVersion > 0x636
PHP_METHOD(Imagick, setFont)
{
	php_imagick_object *intern;
	char *font, *absolute;
	IM_LEN_TYPE font_len;
	MagickBooleanType status;
	php_imagick_rw_result_t rc;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &font, &font_len) == FAILURE) {
		return;
	}

	/* Check that no empty string is passed */
	if (font_len == 0) {
		php_imagick_throw_exception(IMAGICK_CLASS, "Can not set empty font" TSRMLS_CC);
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	/* And if it wasn't */
	if (!php_imagick_check_font(font, font_len TSRMLS_CC)) {

		if (!(absolute = expand_filepath(font, NULL TSRMLS_CC))) {
			php_imagick_throw_exception(IMAGICK_CLASS, "Unable to set font" TSRMLS_CC);
			return;
		}

		if ((rc = php_imagick_file_access_check (absolute TSRMLS_CC)) != IMAGICK_RW_OK) {
			php_imagick_rw_fail_to_exception (intern->magick_wand, rc, absolute TSRMLS_CC);
			efree(absolute);
			return;
		}
		status = MagickSetFont(intern->magick_wand, absolute);
		efree(absolute);
	} else {
		status = MagickSetFont(intern->magick_wand, font);
	}

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set font" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}

PHP_METHOD(Imagick, getFont)
{
	char *font;
	php_imagick_object *intern;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	font   = MagickGetFont(intern->magick_wand);

	if (font) {
		IM_ZVAL_STRING(return_value, font);
		IMAGICK_FREE_MAGICK_MEMORY(font);
		return;
	}
	RETURN_FALSE;
}

PHP_METHOD(Imagick, setPointSize)
{
	php_imagick_object *intern;
	double point_size;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d", &point_size) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	status = MagickSetPointsize(intern->magick_wand, point_size);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set point size" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}

PHP_METHOD(Imagick, getPointSize)
{
	php_imagick_object *intern;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	RETVAL_DOUBLE(MagickGetPointsize(intern->magick_wand));
}

PHP_METHOD(Imagick, mergeImageLayers)
{
	php_imagick_object *intern, *intern_return;
	im_long layer_method;
	MagickWand *merged;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &layer_method) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	/* TODO: SHOULD THIS BE HERE? 
	   Reset the iterator */
	(void)MagickSetFirstIterator(intern->magick_wand);

	merged = MagickMergeImageLayers(intern->magick_wand, layer_method);

	/* No magick is going to happen */
	if (!merged) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to merge image layers" TSRMLS_CC);
		return;
	}

	object_init_ex(return_value, php_imagick_sc_entry);
	intern_return = Z_IMAGICK_P(return_value);

	php_imagick_replace_magickwand(intern_return, merged);
	return;
}
#endif

#if MagickLibVersion > 0x637
/* {{{ proto bool Imagick::floodfillPaintImage(mixed fill, float fuzz, mixed bordercolor, int x, int y, bool invert[, int CHANNEL])
	Changes the color value of any pixel that matches target
*/
PHP_METHOD(Imagick, floodfillPaintImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	zval *fill_param, *border_param;
	im_long x, y, channel = IM_DEFAULT_CHANNEL;
	zend_bool invert;
	double fuzz;
	PixelWand *fill_wand, *border_wand;
	zend_bool fill_allocated = 0, border_allocated = 0;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zdzllb|l",
		&fill_param, &fuzz, &border_param, &x, &y, &invert, &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	fill_wand = php_imagick_zval_to_pixelwand (fill_param, IMAGICK_CLASS, &fill_allocated TSRMLS_CC);
	if (!fill_wand)
		return;

	border_wand = php_imagick_zval_to_pixelwand (border_param, IMAGICK_CLASS, &border_allocated TSRMLS_CC);
	if (!border_wand) {
		if (fill_allocated)
			fill_wand = DestroyPixelWand (fill_wand);

		return;
	}
	
#if MagickLibVersion >= 0x700
	status = MagickFloodfillPaintImageChannel(intern->magick_wand, channel, fill_wand, fuzz, border_wand, x, y, invert);
#else
	status = MagickFloodfillPaintImage(intern->magick_wand, channel, fill_wand, fuzz, border_wand, x, y, invert);
#endif

	if (fill_allocated)
		fill_wand = DestroyPixelWand (fill_wand);

	if (border_allocated)
		border_wand = DestroyPixelWand (border_wand);

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception (intern->magick_wand, "Unable to floodfill paint image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::opaquePaintImage(mixed target, mixed fill, float fuzz, bool invert[, int CHANNEL])
	Changes any pixel that matches color with the color defined by fill.
*/
PHP_METHOD(Imagick, opaquePaintImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	zval *fill_param, *target_param;
	zend_bool invert;
	double fuzz;
	im_long channel = IM_DEFAULT_CHANNEL;
	PixelWand *fill_wand, *target_wand;
	zend_bool fill_allocated = 0, target_allocated = 0;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzdb|l", &fill_param, &target_param, &fuzz, &invert, &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	fill_wand = php_imagick_zval_to_pixelwand (fill_param, IMAGICK_CLASS, &fill_allocated TSRMLS_CC);
	if (!fill_wand)
		return;

	target_wand = php_imagick_zval_to_pixelwand (target_param, IMAGICK_CLASS, &target_allocated TSRMLS_CC);
	if (!target_wand) {
		if (fill_allocated)
			DestroyPixelWand (fill_wand);
		return;
	}

	status = MagickOpaquePaintImageChannel(intern->magick_wand, channel, fill_wand, target_wand, fuzz, invert);

	if (fill_allocated)
		DestroyPixelWand (fill_wand);

	if (target_allocated)
		DestroyPixelWand (target_wand);

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to opaque paint image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::transparentPaintImage(mixed target, float alpha, float fuzz, bool invert)
	Changes any pixel that matches color with the color defined by fill
*/
PHP_METHOD(Imagick, transparentPaintImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	zval *target_param;
	zend_bool invert;
	double fuzz, alpha;
	PixelWand *target_wand;
	zend_bool target_allocated;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zddb", &target_param, &alpha, &fuzz, &invert) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	target_wand = php_imagick_zval_to_pixelwand (target_param, IMAGICK_CLASS, &target_allocated TSRMLS_CC);
	if (!target_wand)
		return;

	status = MagickTransparentPaintImage(intern->magick_wand, target_wand, alpha, fuzz, invert);

	if (target_allocated)
		target_wand = DestroyPixelWand (target_wand);

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to paint transparent image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto Imagick Imagick::setImageAlphaChannel(int ALPHACHANNEL )
   Activates, deactivates, resets, or sets the alpha channel
*/
PHP_METHOD(Imagick, setImageAlphaChannel)
{
	php_imagick_object *intern;
	im_long alpha_channel;
	MagickBooleanType status;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &alpha_channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSetImageAlphaChannel(intern->magick_wand, alpha_channel);

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image alpha channel" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
#endif

#if MagickLibVersion > 0x638
/* {{{ proto Imagick Imagick::liquidRescaleImage(int cols, int rows, float delta_x, float rigidity )
   Rescales image with seam carving
*/
PHP_METHOD(Imagick, liquidRescaleImage)
{
	php_imagick_object *intern;
	im_long cols, rows;
	double delta_x, rigidity;
	MagickBooleanType status;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "lldd", &cols, &rows, &delta_x, &rigidity) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickLiquidRescaleImage(intern->magick_wand, cols, rows, delta_x, rigidity);

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to liquid rescale image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::decipherImage(string passphrase)
	Converts cipher pixels to plain pixels
*/
PHP_METHOD(Imagick, decipherImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	char *passphrase;
	IM_LEN_TYPE passphrase_len;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &passphrase, &passphrase_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickDecipherImage(intern->magick_wand, passphrase);

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to decipher image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::encipherImage(string passphrase)
	Converts plain pixels to cipher pixels
*/
PHP_METHOD(Imagick, encipherImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	char *passphrase;
	IM_LEN_TYPE passphrase_len;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &passphrase, &passphrase_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickEncipherImage(intern->magick_wand, passphrase);

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to encipher image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */
#endif

#if MagickLibVersion > 0x639
/* {{ proto bool Imagick::setGravity(int GRAVITY)
		Sets the gravity value
*/
PHP_METHOD(Imagick, setGravity)
{
	php_imagick_object *intern;
	im_long gravity;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &gravity) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	if (MagickSetGravity(intern->magick_wand, gravity) == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set gravity" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{ proto int Imagick::getGravity()
		Gets the gravity value
*/
PHP_METHOD(Imagick, getGravity)
{
	php_imagick_object *intern;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	RETVAL_LONG(MagickGetGravity(intern->magick_wand));
}
/* }}} */

/* {{ proto Imagick Imagick::getImageChannelRange(int CHANNEL)
		Gets the image channel's range
 */
PHP_METHOD(Imagick, getImageChannelRange)
{
	php_imagick_object *intern;
	im_long channel;
	double maxima, minima;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	if (MagickGetImageChannelRange(intern->magick_wand, channel, &minima, &maxima) == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to get channel range" TSRMLS_CC);
		return;
	}

	array_init(return_value);

	add_assoc_double(return_value, "minima", minima);
	add_assoc_double(return_value, "maxima", maxima);

	return;
}
/* }}} */

/* {{{ proto int Imagick::getImageAlphaChannel()
	Gets the image alpha channel value
*/
PHP_METHOD(Imagick, getImageAlphaChannel)
{
	php_imagick_object *intern;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	RETVAL_LONG(MagickGetImageAlphaChannel(intern->magick_wand));
}
/* }}} */
#endif

#if MagickLibVersion > 0x642
/* {{{ proto float Imagick::getImageChannelDistortions(Imagick reference, int METRICTYPE[, int CHANNEL])
	Compares one or more image channels of an image to a reconstructed image and returns the specified distortion metrics
*/
PHP_METHOD(Imagick, getImageChannelDistortions)
{
	php_imagick_object *intern;
	php_imagick_object *intern_reference;
	zval *reference_param;
	double distortion;
	im_long metric, channel = DefaultChannels;
	MagickBooleanType status;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "Ol|l", &reference_param, php_imagick_sc_entry, &metric, &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	intern_reference = Z_IMAGICK_P(reference_param);
	if (php_imagick_ensure_not_empty (intern_reference->magick_wand) == 0)
		return;

	status = MagickGetImageChannelDistortion(intern->magick_wand, intern_reference->magick_wand, channel, metric, &distortion);

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to get image channel distortion metrics" TSRMLS_CC);
		return;
	}

	RETVAL_DOUBLE(distortion);
}
/* }}} */
#endif

#if MagickLibVersion > 0x643
/* {{{ proto int Imagick::getImageGravity()
	Gets the image gravity
*/
PHP_METHOD(Imagick, getImageGravity)
{
	php_imagick_object *intern;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	RETVAL_LONG(MagickGetImageGravity(intern->magick_wand));
}
/* }}} */

/* {{{ proto bool Imagick::setImageGravity(int GRAVITY)
	Sets the image gravity
*/
PHP_METHOD(Imagick, setImageGravity)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	im_long gravity;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &gravity) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSetImageGravity(intern->magick_wand, gravity);

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image gravity" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */
#endif

#if MagickLibVersion > 0x645
/* {{ proto Imagick Imagick::importImagePixels(int x, int y, int width, int height, string map, int STORAGE, array pixels)
	Accepts pixel data and stores it in the image at the location you specify
 */
PHP_METHOD(Imagick, importImagePixels)
{
	double        *double_array;
	im_long       *long_array;
	unsigned char *char_array;

	php_imagick_object *intern;
	MagickBooleanType status;

	im_long storage, num_elements;
	im_long x, y, width, height;
	IM_LEN_TYPE map_len;
	char *map;
	zval *pixels;
	HashTable *array;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "llllsla", &x, &y, &width, &height, &map, &map_len, &storage, &pixels) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	if (x < 0 || y < 0) {
		php_imagick_throw_exception (IMAGICK_CLASS, "The coordinates must be non-negative" TSRMLS_CC);
		return;
	}

	if (width <= 0 || height <= 0) {
		php_imagick_throw_exception(IMAGICK_CLASS, "The width and height must be greater than zero" TSRMLS_CC);
		return;
	}

	array = Z_ARRVAL_P(pixels);

	if (zend_hash_num_elements(array) != ((width * height) * map_len)) {
		php_imagick_throw_exception(IMAGICK_CLASS, "The map contains incorrect number of elements" TSRMLS_CC);
		return;
	} else {
		if (!php_imagick_validate_map(map TSRMLS_CC)) {
			php_imagick_throw_exception(IMAGICK_CLASS, "The map contains disallowed characters" TSRMLS_CC);
			return;
		}
	}

	switch (storage) {
		case FloatPixel:
		case DoublePixel:
			/* Use doubles */
			storage = DoublePixel;
			double_array = php_imagick_zval_to_double_array(pixels, &num_elements TSRMLS_CC);
			if (!double_array) {
				php_imagick_throw_exception(IMAGICK_CLASS, "The map must contain only numeric values" TSRMLS_CC);
				return;
			}
			status = MagickImportImagePixels(intern->magick_wand, x, y, width, height, map, storage, double_array);
			efree(double_array);
		break;

		case ShortPixel:
#if MagickLibVersion < 0x700
		case IntegerPixel:
#endif
		case LongPixel:
			/* Use longs */
			storage = LongPixel;
			long_array = php_imagick_zval_to_long_array(pixels, &num_elements TSRMLS_CC);
			if (!long_array) {
				php_imagick_throw_exception(IMAGICK_CLASS, "The map must contain only numeric values" TSRMLS_CC);
				return;
			}
			status = MagickImportImagePixels(intern->magick_wand, x, y, width, height, map, storage, long_array);
			efree(long_array);
		break;

		case CharPixel:
			char_array = php_imagick_zval_to_char_array(pixels, &num_elements TSRMLS_CC);
			if (!char_array) {
				php_imagick_throw_exception(IMAGICK_CLASS, "The character array contains incorrect values" TSRMLS_CC);
				return;
			}
			status = MagickImportImagePixels(intern->magick_wand, x, y, width, height, map, storage, char_array);
			efree(char_array);
		break;

		default:
			php_imagick_throw_exception(IMAGICK_CLASS, "Unknown storage format" TSRMLS_CC);
			return;
		break;
	}

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to import image pixels" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

PHP_METHOD(Imagick, deskewImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	double threshold;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d", &threshold) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickDeskewImage(intern->magick_wand, threshold);
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to deskew image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}


#if PHP_IMAGICK_HAVE_HOUGHLINE
/* {{{ proto bool Imagick::houghLineImage(int width, int height, float threshold)
        Draw hough lines for the image

*/
PHP_METHOD(Imagick, houghLineImage)
{
        php_imagick_object *intern;
        MagickBooleanType status;
        double threshold;
        im_long width, height;

        if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "lld", &width, &height, &threshold) == FAILURE) {
                return;
        }

        intern = Z_IMAGICK_P(getThis());
        if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
                return;

        status = MagickHoughLineImage(intern->magick_wand, width, height, threshold);
        if (status == MagickFalse) {
                php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to Hough line image" TSRMLS_CC);
                return;
        }
        RETURN_TRUE;
}
/* }}} */
#endif

PHP_METHOD(Imagick, segmentImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	im_long colorspace;
	zend_bool verbose = 0;
	double cluster_threshold, smooth_threshold;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ldd|b", &colorspace, &cluster_threshold, &smooth_threshold, &verbose) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSegmentImage(intern->magick_wand, colorspace, verbose, cluster_threshold, smooth_threshold);

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to segment image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}

PHP_METHOD(Imagick, sparseColorImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	im_long num_elements, sparse_method, channel = IM_DEFAULT_CHANNEL;
	zval *arguments;
	double *double_array;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "la|l", &sparse_method, &arguments, &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	double_array = php_imagick_zval_to_double_array(arguments, &num_elements TSRMLS_CC);

	if (!double_array) {
		php_imagick_throw_exception(IMAGICK_CLASS, "The map must contain only numeric values" TSRMLS_CC);
		return;
	}
	
#if MagickLibVersion >= 0x700
	status = MagickSparseColorImageChannel(intern->magick_wand, channel, sparse_method, num_elements, double_array);
#else
	status = MagickSparseColorImage(intern->magick_wand, channel, sparse_method, num_elements, double_array);
#endif
	
	efree(double_array);

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to sparse color image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}

/* {{{ proto bool Imagick::remapImage(Imagick remap, int DITHERMETHOD)
	replaces the colors of an image with the closest color from a reference image
*/
PHP_METHOD(Imagick, remapImage)
{
	php_imagick_object *intern;
	php_imagick_object *intern_remap;
	MagickBooleanType status;
	im_long dither_method;
	zval *remap_param;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "Ol", &remap_param, php_imagick_sc_entry, &dither_method) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	intern_remap = Z_IMAGICK_P(remap_param);
	if (php_imagick_ensure_not_empty (intern_remap->magick_wand) == 0)
		return;

	status = MagickRemapImage(intern->magick_wand, intern_remap->magick_wand, dither_method);

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to remap image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */
#endif

#if MagickLibVersion > 0x646
/* {{{ proto bool Imagick::exportImagePixels(int x, int y, int width, int height, string map, INT STORAGE)

The types for the PixelStorage types are:

CharPixel - unsigned 1 byte integer
DoublePixel - 8 byte floating point
FloatPixel - 4 byte floating point
IntegerPixel - Removed in IM7 unsigned 4 byte integer
LongPixel - unsigned 4 byte integer
QuantumPixel - Quantum, use the defined type from the IM headers.
ShortPixel - unsigned 2 byte integer


*/
PHP_METHOD(Imagick, exportImagePixels)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	im_long x, y, width, height, storage;
	char *map;
	int map_size, i = 0;
	IM_LEN_TYPE map_len;
	double *double_array;
	float *float_array;
	unsigned char *char_array;
	unsigned short *short_array;
	unsigned int *long_array; // The long pixel type is implemented in ImageMagick as 'unsigned int'
	Quantum *quantum_array;
#if MagickLibVersion >= 0x700
	unsigned long long int *longlong_array;
#endif

#if INT_MAX != 0x7FFFFFFF
	#error "INT_MAX is not 0x7FFFFFFF, the code below assumes it is, as does the ImageMagick code"
	// If this happens, you will need to figure out how to make long_array be an array of
	// 4 byte unsigned ints
#endif


	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "llllsl", &x, &y, &width, &height, &map, &map_len, &storage) == FAILURE) {
		return;
	}

	if ((x < 0) || (y < 0)) {
		php_imagick_throw_exception(IMAGICK_CLASS, "The coordinates must be non-negative" TSRMLS_CC);
		return;
	}

	if (width <= 0 || height <= 0) {
		php_imagick_throw_exception(IMAGICK_CLASS, "The width and height must be greater than zero" TSRMLS_CC);
		return;
	}

	if (!php_imagick_validate_map(map TSRMLS_CC)) {
		php_imagick_throw_exception(IMAGICK_CLASS, "The map contains disallowed characters" TSRMLS_CC);
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	map_size = (map_len * width * height);

	switch (storage) {
		case FloatPixel:
			float_array = emalloc(map_size * sizeof(float));
			status = MagickExportImagePixels(intern->magick_wand, x, y, width, height, map, FloatPixel, (void *)float_array);

			if (status != MagickFalse) {
				array_init(return_value);
				for (i = 0; i < map_size; i++) {
					add_next_index_double(return_value, float_array[i]);
				}
				efree(float_array);
				return;
			}
		break;

		case DoublePixel:
			double_array = emalloc(map_size * sizeof(double));
			status = MagickExportImagePixels(intern->magick_wand, x, y, width, height, map, DoublePixel, (void *)double_array);

			if (status != MagickFalse) {
				array_init(return_value);
				for (i = 0; i < map_size; i++) {
					add_next_index_double(return_value, double_array[i]);
				}
				efree(double_array);
				return;
			}
		break;

		case ShortPixel:
			short_array = emalloc(map_size * sizeof(unsigned short));
			status = MagickExportImagePixels(intern->magick_wand, x, y, width, height, map, ShortPixel, (void *)short_array);

			if (status != MagickFalse) {
				array_init(return_value);
				for (i = 0; i < map_size; i++) {
					add_next_index_long(return_value, short_array[i]);
				}
				efree(short_array);
				return;
			}
		break;

#if MagickLibVersion >= 0x700
		case LongLongPixel:
			longlong_array = emalloc(map_size * sizeof(unsigned long long int));
			status = MagickExportImagePixels(intern->magick_wand, x, y, width, height, map, LongLongPixel, (void *)longlong_array);

			if (status != MagickFalse) {
				array_init(return_value);
				for (i = 0; i < map_size; i++) {
					//TODO - think about this.
					// on 32bit platforms this will be truncating data
					// on 64bit platforms where sizeof(longlong) > 64bits, it will be truncating
					// on 64bit platforms where sizeof(longlong) = 64bits, PHP will be
					// converting values close to 64bit to be floats...
					add_next_index_long(return_value, longlong_array[i]);
				}
				efree(longlong_array);
				return;
			}
		break;
#endif

#if MagickLibVersion < 0x700
		case IntegerPixel:
#endif
		case LongPixel:
			long_array = emalloc(map_size * sizeof(unsigned int));
			status = MagickExportImagePixels(intern->magick_wand, x, y, width, height, map, LongPixel, (void *)long_array);

			if (status != MagickFalse) {
				array_init(return_value);
				for (i = 0; i < map_size; i++) {
					add_next_index_long(return_value, long_array[i]);
				}
				efree(long_array);
				return;
			}
		break;

		case CharPixel:
			char_array = emalloc(map_size * sizeof(char));
			status = MagickExportImagePixels(intern->magick_wand, x, y, width, height, map, CharPixel, (void *)char_array);

			if (status != MagickFalse) {
				array_init(return_value);
				for (i = 0; i < map_size; i++) {
					add_next_index_long(return_value, (int)char_array[i]);
				}
				efree(char_array);
				return;
			}
		break;

		case QuantumPixel:
			quantum_array = emalloc(map_size * sizeof(Quantum));
			status = MagickExportImagePixels(intern->magick_wand, x, y, width, height, map, QuantumPixel, (void *)quantum_array);

			if (status != MagickFalse) {
				array_init(return_value);
				for (i = 0; i < map_size; i++) {
#if MAGICKCORE_HDRI_ENABLE
					add_next_index_double(return_value, quantum_array[i]);
#else
					add_next_index_long(return_value, quantum_array[i]);
#endif
				}
				efree(quantum_array);
				return;
			}
		break;

		default:
			php_imagick_throw_exception(IMAGICK_CLASS, "Unknown pixel type " TSRMLS_CC);
			return;
		break;
	}

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to export image pixels" TSRMLS_CC);
		return;
	}
	return;
}
/* }}} */
#endif

#if MagickLibVersion > 0x648
/* {{{ proto array Imagick::getImageChannelKurtosis([int CHANNEL])
	Gets the kurtosis and skewness of one or more image channels
*/
PHP_METHOD(Imagick, getImageChannelKurtosis)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	double kurtosis, skewness;
	im_long channel = DefaultChannels;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|l", &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickGetImageChannelKurtosis(intern->magick_wand, channel, &kurtosis, &skewness);

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to get image channel kurtosis" TSRMLS_CC);
		return;
	}

	array_init(return_value);
	add_assoc_double(return_value, "kurtosis", kurtosis);
	add_assoc_double(return_value, "skewness", skewness);
	return;
}
/* }}} */

/* {{{ proto bool Imagick::functionImage(int FUNCTION, array arguments[, int CHANNEL])
	Applies an arithmetic, relational, or logical expression to an image
*/
PHP_METHOD(Imagick, functionImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	zval *arguments;
	im_long func, num_elements, channel = IM_DEFAULT_CHANNEL;
	double *array;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "la|l", &func, &arguments, &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	array = php_imagick_zval_to_double_array(arguments, &num_elements TSRMLS_CC);

	if (!array) {
		php_imagick_throw_exception(IMAGICK_CLASS, "The arguments array contains disallowed characters or is empty." TSRMLS_CC);
		return;
	}

	status = MagickFunctionImageChannel(intern->magick_wand, channel, func, num_elements, array);
	efree(array);

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to execute function on the image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */
#endif

#if MagickLibVersion > 0x651
/* {{{ proto boolean Imagick::transformImageColorspace(int COLORSPACE)
	Transform image colorspace
*/
PHP_METHOD(Imagick, transformImageColorspace)
{
	php_imagick_object *intern;
	im_long colorspace;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &colorspace) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickTransformImageColorspace(intern->magick_wand, colorspace);

    /* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to transform image colorspace" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */
#endif

#if MagickLibVersion > 0x652
/* {{{ proto boolean Imagick::haldClutImage(Imagick hald[, int CHANNEL])
   Replaces colors in the image from a Hald color lookup table
*/
PHP_METHOD(Imagick, haldClutImage)
{
	zval *objvar;
	MagickBooleanType status;
	php_imagick_object *intern, *hald;
	im_long channel = IM_DEFAULT_CHANNEL;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "O|l", &objvar, php_imagick_sc_entry, &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	hald = Z_IMAGICK_P(objvar);
	if (php_imagick_ensure_not_empty (hald->magick_wand) == 0)
		return;

	status = MagickHaldClutImageChannel(intern->magick_wand, channel, hald->magick_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to hald clut image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */
#endif

#if MagickLibVersion > 0x655
/* {{{ proto boolean Imagick::autoLevelImage([int CHANNEL])
   Adjusts the levels of a particular image channel by scaling the minimum and maximum values to the full quantum range.
*/
PHP_METHOD(Imagick, autoLevelImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	im_long channel = IM_DEFAULT_CHANNEL;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|l", &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickAutoLevelImageChannel(intern->magick_wand, channel);
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to autolevel image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto boolean Imagick::blueShiftImage([float $factor = 1.5])
   Mutes the colors of the image to simulate a scene at nighttime in the moonlight.
*/
PHP_METHOD(Imagick, blueShiftImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	double factor = 1.5;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|d", &factor) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickBlueShiftImage(intern->magick_wand, factor);
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to blue shift image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */
#endif

#if MagickLibVersion > 0x656
PHP_METHOD(Imagick, setImageArtifact)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	char *artifact, *value;
	IM_LEN_TYPE artifact_len, value_len;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss", &artifact, &artifact_len, &value, &value_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSetImageArtifact(intern->magick_wand, artifact, value);
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image artifact" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}


PHP_METHOD(Imagick, getImageArtifact)
{
	php_imagick_object *intern;
	char *artifact, *value;
	IM_LEN_TYPE artifact_len;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &artifact, &artifact_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	value = MagickGetImageArtifact(intern->magick_wand, artifact);

	if (!value) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to get image artifact" TSRMLS_CC);
		return;
	}
#ifdef ZEND_ENGINE_3 
	RETVAL_STRING(value);
#else
	RETVAL_STRING(value, 1);
#endif
	IMAGICK_FREE_MAGICK_MEMORY(value);
	return;
}

/* {{{ proto boolean Imagick::deleteImageArtifact(string $artifact)
   Delete image artifact
*/
PHP_METHOD(Imagick, deleteImageArtifact)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	char *artifact;
	IM_LEN_TYPE artifact_len;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &artifact, &artifact_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickDeleteImageArtifact(intern->magick_wand, artifact);

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to delete image artifact" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto integer Imagick::getColorspace()
   Get the object colorspace property
*/
PHP_METHOD(Imagick, getColorspace)
{
	php_imagick_object *intern;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	RETURN_LONG(MagickGetColorspace(intern->magick_wand));
}
/* }}} */

/* {{{ proto boolean Imagick::setColorspace([int COLORSPACE])
   Set the object colorspace property
*/
PHP_METHOD(Imagick, setColorspace)
{
	php_imagick_object *intern;
	im_long colorspace;
	MagickBooleanType status;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &colorspace) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	status = MagickSetColorspace(intern->magick_wand, colorspace);

	RETURN_BOOL(status == MagickTrue);
}
/* }}} */

/* {{{ proto boolean Imagick::clampImage([int CHANNEL])
   Restricts the color range from 0 to the quantum depth.
*/
PHP_METHOD(Imagick, clampImage)
{
	php_imagick_object *intern;
	im_long channel = IM_DEFAULT_CHANNEL;
	MagickBooleanType status;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|l", &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickClampImageChannel(intern->magick_wand, channel);

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to clamp image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */
#endif

#if MagickLibVersion > 0x667
/* {{{ proto Imagick Imagick::smushImages(boolean stack, int offset)
   Takes all images from the current image pointer to the end of the image list and smushs
   them to each other top-to-bottom if the stack parameter is true, otherwise left-to-right.
*/
PHP_METHOD(Imagick, smushImages)
{
	php_imagick_object *intern, *intern_return;
	zend_bool stack;
	long offset;
	MagickWand *retwand;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "bl", &stack, &offset) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	retwand = MagickSmushImages(intern->magick_wand, (stack ? MagickTrue : MagickFalse), offset);

	if (!retwand) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to smush images" TSRMLS_CC);
		return;
	}

	object_init_ex(return_value, php_imagick_sc_entry);
	intern_return = Z_IMAGICK_P(return_value);
	php_imagick_replace_magickwand(intern_return, retwand);
	return;
}
/* }}} */
#endif

/* {{{ proto Imagick Imagick::__construct([mixed files] )
   The Imagick constructor
*/
#ifdef ZEND_ENGINE_3
PHP_METHOD(Imagick, __construct)
{
	php_imagick_object *intern;
	zval *files = NULL;

	zval *pzval;
	php_imagick_rw_result_t rc;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z!/", &files) == FAILURE) {
		return;
	}

	/* No files given.. or null passed */
	if (!files) {
		return;
	}
	intern = Z_IMAGICK_P(getThis());

	if (Z_TYPE_P (files) == IS_LONG || Z_TYPE_P (files) == IS_DOUBLE) {
		convert_to_string (files);
	}

	/* A single file was given */
	if (Z_TYPE_P(files) == IS_STRING) {
		struct php_imagick_file_t file = {0};

		if (!php_imagick_file_init(&file, Z_STRVAL_P(files), Z_STRLEN_P(files) TSRMLS_CC)) {
			php_imagick_throw_exception(IMAGICK_CLASS, "Invalid filename provided" TSRMLS_CC);
			return;
		}
		rc = php_imagick_read_file(intern, &file, ImagickReadImage TSRMLS_CC);
		php_imagick_file_deinit(&file);

		if (rc != IMAGICK_RW_OK) {
			php_imagick_rw_fail_to_exception (intern->magick_wand, rc, Z_STRVAL_P(files) TSRMLS_CC);
			return;
		}
	}

	/* an array of filenames was given */
	else
	if (Z_TYPE_P(files) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(files), pzval) {
			struct php_imagick_file_t file = {0};
			ZVAL_DEREF(pzval);

			if (!php_imagick_file_init(&file, Z_STRVAL_P(pzval), Z_STRLEN_P(pzval) TSRMLS_CC)) {
				php_imagick_throw_exception(IMAGICK_CLASS, "Invalid filename provided" TSRMLS_CC);
				return;
			}

			rc = php_imagick_read_file(intern, &file, ImagickReadImage TSRMLS_CC);
			php_imagick_file_deinit(&file);

			if (rc != IMAGICK_RW_OK) {
				php_imagick_rw_fail_to_exception (intern->magick_wand, rc, Z_STRVAL_P(pzval) TSRMLS_CC);
				return;
			}
		} ZEND_HASH_FOREACH_END();
	}
	if (Z_TYPE_P(files) == IS_FALSE || Z_TYPE_P(files) == IS_TRUE) {
		php_imagick_throw_exception(IMAGICK_CLASS, "Constructor shouldn't be called with a boolean as the filename");
	}

	RETURN_TRUE;
}
#else
PHP_METHOD(Imagick, __construct)
{
	php_imagick_object *intern;
	zval *files = NULL;
	HashPosition pos;
	php_imagick_rw_result_t rc;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z!/", &files) == FAILURE) {
		return;
	}

	/* No files given.. or null passed */
	if (!files) {
		return;
	}
	intern = Z_IMAGICK_P(getThis());

	if (Z_TYPE_P (files) == IS_LONG || Z_TYPE_P (files) == IS_DOUBLE) {
		convert_to_string (files);
	}

	/* A single file was given */
	if (Z_TYPE_P(files) == IS_STRING) {
		struct php_imagick_file_t file = {0};

		if (!php_imagick_file_init(&file, Z_STRVAL_P(files), Z_STRLEN_P(files) TSRMLS_CC)) {
			php_imagick_throw_exception(IMAGICK_CLASS, "Invalid filename provided" TSRMLS_CC);
			return;
		}
		rc = php_imagick_read_file(intern, &file, ImagickReadImage TSRMLS_CC);
		php_imagick_file_deinit(&file);

		if (rc != IMAGICK_RW_OK) {
			php_imagick_rw_fail_to_exception (intern->magick_wand, rc, Z_STRVAL_P(files) TSRMLS_CC);
			return;
		}
	}

	/* an array of filenames was given */
	else
	if (Z_TYPE_P(files) == IS_ARRAY) {
		for(zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(files), &pos);
			zend_hash_has_more_elements_ex(Z_ARRVAL_P(files), &pos) == SUCCESS;
			zend_hash_move_forward_ex(Z_ARRVAL_P(files), &pos)) {

			struct php_imagick_file_t file = {0};
			zval **ppzval;

			if (zend_hash_get_current_data_ex(Z_ARRVAL_P(files), (void**)&ppzval, &pos) == FAILURE) {
				continue;
			}

			if (!php_imagick_file_init(&file, Z_STRVAL_PP(ppzval), Z_STRLEN_PP(ppzval) TSRMLS_CC)) {
				php_imagick_throw_exception(IMAGICK_CLASS, "Invalid filename provided" TSRMLS_CC);
				return;
			}

			rc = php_imagick_read_file(intern, &file, ImagickReadImage TSRMLS_CC);
			php_imagick_file_deinit(&file);

			if (rc != IMAGICK_RW_OK) {
				php_imagick_rw_fail_to_exception (intern->magick_wand, rc, Z_STRVAL_PP(ppzval) TSRMLS_CC);
				return;
			}
		}
	}

	if (Z_TYPE_P(files) == IS_BOOL) {
		php_imagick_throw_exception(IMAGICK_CLASS, "Constructor shouldn't be called with a boolean as the filename" TSRMLS_CC);
	}

	RETURN_TRUE;
}
#endif
/* }}} */

/* {{{ proto string Imagick::__toString()
   Returns the current image as string
*/
PHP_METHOD(Imagick, __toString)
{
	php_imagick_object *intern;
	unsigned char *image;
	char *buffer;
	size_t image_size;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	if (MagickGetNumberImages(intern->magick_wand) == 0) {
		IM_ZVAL_STRING(return_value, "");
		return;
	}

	buffer = MagickGetImageFormat(intern->magick_wand);

	if (!buffer) {
		IM_ZVAL_STRING(return_value, "");
		return;
	} else {
		IMAGICK_FREE_MAGICK_MEMORY(buffer);
	}

	image = MagickGetImageBlob(intern->magick_wand, &image_size);
	IM_ZVAL_STRINGL(return_value, (char *)image, image_size);
	IMAGICK_FREE_MAGICK_MEMORY(image);
	return;
}
/* }}} */

/* {{{ proto string Imagick::count()
   Returns the number of images
*/
PHP_METHOD(Imagick, count)
{
	php_imagick_object *intern;
	im_long mode = 0;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|l", &mode) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	RETVAL_LONG (MagickGetNumberImages(intern->magick_wand));
}
/* }}} */

/* {{{ proto array Imagick::queryFormats([string pattern] )
   Returns formats supported by ImageMagick
*/
PHP_METHOD(Imagick, queryFormats)
{
	char **supported_formats;
	unsigned long i;
	char *pattern = "*";
	IM_LEN_TYPE pattern_len = 1;
	size_t num_formats = 0;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|s", &pattern, &pattern_len) == FAILURE) {
		return;
	}

	supported_formats = (char **) MagickQueryFormats(pattern, &num_formats);
	array_init(return_value);

	for (i = 0 ; i < num_formats ; i++) {
		IM_add_next_index_string(return_value, supported_formats[i]);
		IMAGICK_FREE_MAGICK_MEMORY(supported_formats[i]);
	}

	IMAGICK_FREE_MAGICK_MEMORY(supported_formats);
	return;
}
/* }}} */

/* {{{ proto array Imagick::queryFonts([string pattern] )
   Returns fonts supported by ImageMagick
*/
PHP_METHOD(Imagick, queryFonts)
{
	char **fonts;
	unsigned long i;
	char *pattern = "*";
	IM_LEN_TYPE pattern_len = 1;
	size_t num_fonts;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|s", &pattern, &pattern_len) == FAILURE) {
		return;
	}

	fonts = (char **) MagickQueryFonts(pattern, &num_fonts);
	array_init(return_value);

	for (i = 0 ; i < num_fonts ; i++) {
		IM_add_next_index_string(return_value, fonts[i]);
		IMAGICK_FREE_MAGICK_MEMORY(fonts[i]);
	}

	IMAGICK_FREE_MAGICK_MEMORY(fonts);
	return;
}
/* }}} */

/* {{{ proto array Imagick::queryFontMetrics(ImagickDraw draw, string text[, bool multiline] )
   Returns a 13 element array representing the font metrics
*/
PHP_METHOD(Imagick, queryFontMetrics)
{
	zval *objvar, *multiline;
	zend_bool remove_canvas, query_multiline;
	php_imagick_object *intern;
	php_imagickdraw_object *internd;
	char *text;
	IM_LEN_TYPE text_len;
	double *metrics;

	multiline = NULL;
	remove_canvas = 0;
	query_multiline = 0;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "Os|z!", &objvar, php_imagickdraw_sc_entry, &text, &text_len, &multiline) == FAILURE) {
		return;
	}

	/* No parameter passed, this means we should autodetect */
	if (!multiline) {
		if (strchr (text, '\n') != NULL) {
			query_multiline = 1;
		}
	} else {
		convert_to_boolean(multiline);
#ifdef ZEND_ENGINE_3
		if (Z_TYPE_P(multiline) == IS_TRUE) {
			query_multiline = 1;
		}
#else
		query_multiline = Z_BVAL_P(multiline);
#endif
	}

	/* fetch the objects */
	intern  = Z_IMAGICK_P(getThis());
	internd = Z_IMAGICKDRAW_P(objvar);

	/* If wand is empty, create a 1x1 pixel image to use as a temporary canvas */
	if (MagickGetNumberImages(intern->magick_wand) < 1) {
		PixelWand *pixel_wand;
		MagickBooleanType status;

		/* Empty bg color */
		pixel_wand = NewPixelWand();

		if (!pixel_wand) {
			php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to allocate background color for the temporary canvas" TSRMLS_CC);
			return;
		}

		/* 1x1 should be enough to get the metrics */
		status     = MagickNewImage(intern->magick_wand, 1, 1, pixel_wand);
		pixel_wand = DestroyPixelWand(pixel_wand);

		if (status == MagickFalse) {
			php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to allocate temporary canvas" TSRMLS_CC);
			return;
		}
		remove_canvas = 1;
	}

	/* Multiline testing */
	if (query_multiline) {
		metrics = MagickQueryMultilineFontMetrics(intern->magick_wand, internd->drawing_wand, text);
	} else {
		metrics = MagickQueryFontMetrics(intern->magick_wand, internd->drawing_wand, text);
	}

	/* Remove the image from the stack*/
	if (remove_canvas) {
		MagickRemoveImage(intern->magick_wand);
	}

	if (!metrics) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Failed to query the font metrics" TSRMLS_CC);
		return;
	} else {
		zval *pbounding;
#ifdef ZEND_ENGINE_3
		zval bounding;
		pbounding = &bounding;
#else
		MAKE_STD_ZVAL(pbounding)
#endif

		array_init(return_value);
		add_assoc_double(return_value, "characterWidth", metrics[0]);
		add_assoc_double(return_value, "characterHeight", metrics[1]);
		add_assoc_double(return_value, "ascender", metrics[2]);
		add_assoc_double(return_value, "descender", metrics[3]);
		add_assoc_double(return_value, "textWidth", metrics[4]);
		add_assoc_double(return_value, "textHeight", metrics[5]);
		add_assoc_double(return_value, "maxHorizontalAdvance", metrics[6]);

		array_init(pbounding);
		add_assoc_double(pbounding, "x1", metrics[7]);
		add_assoc_double(pbounding, "y1", metrics[8]);
		add_assoc_double(pbounding, "x2", metrics[9]);
		add_assoc_double(pbounding, "y2", metrics[10]);
		add_assoc_zval(return_value, "boundingBox", pbounding);
		add_assoc_double(return_value, "originX", metrics[11]);
		add_assoc_double(return_value, "originY", metrics[12]);

		IMAGICK_FREE_MAGICK_MEMORY(metrics);
		return;
	}
}
/* }}} */

/* {{{ proto bool Imagick::valid()
    Checks if the current item is valid
*/
PHP_METHOD(Imagick, valid)
{
	php_imagick_object *intern;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	if (intern->next_out_of_bound) {
		RETURN_FALSE;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto Imagick Imagick::current()
    Returns reference to the current imagick object with image pointer at the correct sequence.
*/
PHP_METHOD(Imagick, current)
{
	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	RETURN_ZVAL(getThis(), 1, 0);
}
/* }}} */

/* {{{ proto bool Imagick::readImage(string filename)
    Reads image from filename
*/
PHP_METHOD(Imagick, readImage)
{
	char *filename;
	IM_LEN_TYPE filename_len;
	php_imagick_object *intern;
	struct php_imagick_file_t file = {0};
	php_imagick_rw_result_t rc;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &filename, &filename_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	if (!php_imagick_file_init(&file, filename, filename_len TSRMLS_CC)) {
		php_imagick_throw_exception(IMAGICK_CLASS, "Invalid filename provided" TSRMLS_CC);
		return;
	}

	rc = php_imagick_read_file(intern, &file, ImagickReadImage TSRMLS_CC);
	php_imagick_file_deinit(&file);

	if (rc != IMAGICK_RW_OK) {
		php_imagick_rw_fail_to_exception (intern->magick_wand, rc, filename TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::readImages(array files )
    Reads image from an array of filenames
*/
#ifdef ZEND_ENGINE_3
PHP_METHOD(Imagick, readImages)
{

	zval *value;
	zval *files;
	php_imagick_object *intern;
	php_imagick_rw_result_t rc;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "a", &files) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(files), value) {
		struct php_imagick_file_t file = {0};
		ZVAL_DEREF(value);

		if (!php_imagick_file_init(&file, Z_STRVAL_P(value), Z_STRLEN_P(value) TSRMLS_CC)) {
			php_imagick_throw_exception(IMAGICK_CLASS, "Invalid filename provided" TSRMLS_CC);
			return;
		}

		rc = php_imagick_read_file(intern, &file, ImagickReadImage TSRMLS_CC);
		php_imagick_file_deinit(&file);

		if (rc != IMAGICK_RW_OK) {
			php_imagick_rw_fail_to_exception (intern->magick_wand, rc, Z_STRVAL_P(value) TSRMLS_CC);
			return;
		}
	} ZEND_HASH_FOREACH_END();
	RETURN_TRUE;
}
#else
PHP_METHOD(Imagick, readImages)
{
	zval *files;
	php_imagick_object *intern;
	HashPosition pos;
	php_imagick_rw_result_t rc;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "a", &files) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	for(zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(files), &pos);
		zend_hash_has_more_elements_ex(Z_ARRVAL_P(files), &pos) == SUCCESS;
		zend_hash_move_forward_ex(Z_ARRVAL_P(files), &pos)) {

		struct php_imagick_file_t file = {0};
		zval **ppzval;

		if (zend_hash_get_current_data_ex(Z_ARRVAL_P(files), (void**)&ppzval, &pos) == FAILURE) {
			continue;
		}

		if (!php_imagick_file_init(&file, Z_STRVAL_PP(ppzval), Z_STRLEN_PP(ppzval) TSRMLS_CC)) {
			php_imagick_throw_exception(IMAGICK_CLASS, "Invalid filename provided" TSRMLS_CC);
			return;
		}

		rc = php_imagick_read_file(intern, &file, ImagickReadImage TSRMLS_CC);
		php_imagick_file_deinit(&file);

		if (rc != IMAGICK_RW_OK) {
			php_imagick_rw_fail_to_exception (intern->magick_wand, rc, Z_STRVAL_PP(ppzval) TSRMLS_CC);
			return;
		}
	}
	RETURN_TRUE;
}
#endif


/* {{{ proto bool Imagick::pingImage(string filename )
    This method can be used to query image width, height, size, and format without reading the whole image in to memory.
*/
PHP_METHOD(Imagick, pingImage)
{
	char *filename;
	IM_LEN_TYPE filename_len;
	php_imagick_object *intern;
	struct php_imagick_file_t file = {0};
	php_imagick_rw_result_t rc;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &filename, &filename_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	if (!php_imagick_file_init(&file, filename, filename_len TSRMLS_CC)) {
		php_imagick_throw_exception(IMAGICK_CLASS, "Invalid filename provided" TSRMLS_CC);
		return;
	}
	rc = php_imagick_read_file(intern, &file, ImagickPingImage TSRMLS_CC);
	php_imagick_file_deinit(&file);

	if (rc != IMAGICK_RW_OK) {
		php_imagick_rw_fail_to_exception (intern->magick_wand, rc, filename TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::readImageFile(resource filehandle[, string filename])
    Reads image from open filehandle
*/
PHP_METHOD(Imagick, readImageFile)
{
	char *filename = NULL;
	IM_LEN_TYPE filename_len;
	php_imagick_object *intern;
	zval *zstream;
	zend_bool result;
	php_stream *stream;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "r|s!", &zstream, &filename, &filename_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

#ifdef ZEND_ENGINE_3
	php_stream_from_zval(stream, zstream);
#else
	php_stream_from_zval(stream, &zstream);
#endif
	result = php_imagick_stream_handler(intern, stream, ImagickReadImageFile TSRMLS_CC);

	if (result == 0) {
		if (!EG(exception)) {
			php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to read image from the filehandle" TSRMLS_CC);
			return;
		}
		return;
	}

	if (filename) {
		MagickSetImageFilename(intern->magick_wand, filename);
		MagickSetLastIterator(intern->magick_wand);
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::displayImage(string serverName )
	Displays an image
*/
PHP_METHOD(Imagick, displayImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	char *server_name;
	IM_LEN_TYPE server_name_len;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &server_name, &server_name_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickDisplayImage(intern->magick_wand, server_name);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to display image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::displayImages(string serverName )
	displays an image or image sequence
*/
PHP_METHOD(Imagick, displayImages)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	char *server_name;
	IM_LEN_TYPE server_name_len;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &server_name, &server_name_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickDisplayImages(intern->magick_wand, server_name);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to display images" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::readBlob(string image )
    Reads image from a binary string
*/
PHP_METHOD(Imagick, readImageBlob)
{
	char *image_string;
	char *filename = NULL;
	long filename_len;
	IM_LEN_TYPE image_string_len;
	MagickBooleanType status;
	php_imagick_object *intern;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|s!", &image_string, &image_string_len, &filename, &filename_len) == FAILURE) {
		return;
	}

	if (!image_string_len) {
		php_imagick_throw_exception(IMAGICK_CLASS, "Zero size image string passed" TSRMLS_CC);
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	status = MagickReadImageBlob(intern->magick_wand, image_string, image_string_len);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to read image blob" TSRMLS_CC);
		return;
	}

	/* Even if filename is null we need to give a name here. Otherwise segfaults will happen */
	MagickSetImageFilename(intern->magick_wand, filename);
	MagickSetLastIterator(intern->magick_wand);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::blurImage(float radius, float sigma[, int channel ] )
	Adds blur filter to image. Optional third parameter to blur a specific channel.
*/
PHP_METHOD(Imagick, blurImage)
{
	double radius, sigma;
	php_imagick_object *intern;
	MagickBooleanType status;
	/* Initialize channel type to all channels*/
	im_long channel = IM_DEFAULT_CHANNEL;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dd|l", &radius, &sigma, &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickBlurImageChannel(intern->magick_wand, channel, radius, sigma);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to blur image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::waveImage(float amplitude, float length )
	Adds wave filter to the image.
*/
PHP_METHOD(Imagick, waveImage)
{
	double amplitude, wave_length;
	php_imagick_object *intern;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dd", &amplitude, &wave_length) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

#if MagickLibVersion >= 0x700
	{
	//TODO allow PixelInterpolateMethod be set
	PixelInterpolateMethod method = BilinearInterpolatePixel;
	status = MagickWaveImage(intern->magick_wand, amplitude, wave_length, method);
	}
#else
	status = MagickWaveImage(intern->magick_wand, amplitude, wave_length);
#endif

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to wave image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::clear()
	Clears all resources associated to Imagick object
*/
PHP_METHOD(Imagick, clear)
{
	php_imagick_object *intern;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	if (!intern->magick_wand) {
		RETURN_FALSE;
	}

	ClearMagickWand(intern->magick_wand);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::scaleImage(int width, int height[, bool bestfit = false[, bool legacy]] )
	Scales the size of an image to the given dimensions. Passing zero as either of
	the arguments will preserve dimension while scaling.
	If legacy is true, the calculations are done with the small rounding bug that existed in
	Imagick before 3.4.0. If false, the calculations should produce the same results as 
	ImageMagick CLI does.
*/
PHP_METHOD(Imagick, scaleImage)
{
	im_long width, height, new_width, new_height;
	php_imagick_object *intern;
	MagickBooleanType status;
	zend_bool bestfit = 0;
	zend_bool legacy = 0;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll|bb", &width, &height, &bestfit, &legacy) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	if (!php_imagick_thumbnail_dimensions(intern->magick_wand, bestfit, width, height, &new_width, &new_height, legacy)) {
		php_imagick_throw_exception(IMAGICK_CLASS, "Invalid image geometry" TSRMLS_CC);
		return;
	}

	status = MagickScaleImage(intern->magick_wand, new_width, new_height);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to scale image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::cropImage(int width, height, int x, int y )
	Extracts a region of the image.
*/
PHP_METHOD(Imagick, cropImage)
{
	im_long width, height, x, y;
	php_imagick_object *intern;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "llll", &width, &height, &x, &y) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickCropImage(intern->magick_wand, width, height, x, y);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to crop image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::spreadImage(float radius )
	Special effects method that randomly displaces each pixel in a block defined by the radius parameter.
*/
PHP_METHOD(Imagick, spreadImage)
{
	double radius;
	php_imagick_object *intern;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d", &radius) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

#if MagickLibVersion >= 0x700
	{
	//TODO allow PixelInterpolateMethod be set
	PixelInterpolateMethod method = BilinearInterpolatePixel;
	status = MagickSpreadImage(intern->magick_wand, radius, method);
	}
#else
	status = MagickSpreadImage(intern->magick_wand, radius);
#endif

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to spread image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::swirlImage(float degrees )
	Swirls the pixels about the center of the image, where degrees indicates the sweep of the arc through which each pixel is moved. You get a more dramatic effect as the degrees move from 1 to 360.
*/
PHP_METHOD(Imagick, swirlImage)
{
	double degrees;
	php_imagick_object *intern;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d", &degrees) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

#if MagickLibVersion >= 0x700
	{
	//TODO allow PixelInterpolateMethod be set
	PixelInterpolateMethod method = BilinearInterpolatePixel;
	status = MagickSwirlImage(intern->magick_wand, degrees, method);
	}
#else
	status = MagickSwirlImage(intern->magick_wand, degrees);
#endif

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to swirl image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::stripImage()
	Strips an image of all profiles and comments.
*/
PHP_METHOD(Imagick, stripImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickStripImage(intern->magick_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to strip image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::trimImage(double fuzz)
	Remove edges that are the background color from the image.
*/
PHP_METHOD(Imagick, trimImage)
{
	double fuzz;
	php_imagick_object *intern;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d", &fuzz) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickTrimImage(intern->magick_wand, fuzz);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to trim image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::chopImage(int width, int height, int x, int y)
	Removes a region of an image and collapses the image to occupy the removed portion
*/
PHP_METHOD(Imagick, chopImage)
{
	php_imagick_object *intern;
	im_long width, height, x, y;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "llll", &width, &height, &x, &y) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickChopImage(intern->magick_wand, width, height, x, y);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to chop image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;

}
/* }}} */

/* {{{ proto bool Imagick::clipImage()
	Clips along the first path from the 8BIM profile, if present.
*/
PHP_METHOD(Imagick, clipImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;
	status = MagickClipImage(intern->magick_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to clip image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::clipPathImage(string pathname, bool inside)
	Clips along the named paths from the 8BIM profile, if present. Later operations take effect inside the path.  Id may be a number if preceded with #, to work on a numbered path, e.g., "#1" to use the first path.
*/
PHP_METHOD(Imagick, clipPathImage)
{
	php_imagick_object *intern;
	char *clip_path;
	IM_LEN_TYPE clip_path_len;
	zend_bool inside;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sb", &clip_path, &clip_path_len, &inside) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;
#if MagickLibVersion > 0x636
	status = MagickClipImagePath(intern->magick_wand, clip_path, inside);
#else
	status = MagickClipPathImage(intern->magick_wand, clip_path, inside);
#endif

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to clip path image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;

}
/* }}} */

/* {{{ proto Imagick Imagick::coalesceImages()
	Composites a set of images while respecting any page offsets and disposal methods.  GIF, MIFF, and MNG animation sequences typically start with an image background and each subsequent image varies in size and offset.  returns a new sequence where each image in the sequence is the same size as the first and composited with the next image in the sequence.
*/
PHP_METHOD(Imagick, coalesceImages)
{
	MagickWand *tmp_wand;
	php_imagick_object *intern, *intern_return;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	tmp_wand = MagickCoalesceImages(intern->magick_wand);

	if (tmp_wand == NULL) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Coalesce image failed" TSRMLS_CC);
		return;
	}

	object_init_ex(return_value, php_imagick_sc_entry);
	intern_return = Z_IMAGICK_P(return_value);
	php_imagick_replace_magickwand(intern_return, tmp_wand);
	return;

}
/* }}} */

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
/* {{{ proto bool Imagick::colorFloodfillImage(ImagickPixel fill, double fuzz, ImagickPixel bordercolor, int x, int y)
	Changes the color value of any pixel that matches target and is an immediate neighbor.
*/
PHP_METHOD(Imagick, colorFloodfillImage)
{
	php_imagick_object *intern;
	zval *fill_param, *border_param;
	im_long x, y;
	double fuzz;
	MagickBooleanType status;
	PixelWand *fill_wand, *border_wand;
	zend_bool fill_allocated = 0, border_allocated = 0;

	IMAGICK_METHOD_DEPRECATED("Imagick", "colorFloodFillImage");

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zdzll", &fill_param, &fuzz, &border_param, &x, &y) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	fill_wand = php_imagick_zval_to_pixelwand (fill_param, IMAGICK_CLASS, &fill_allocated TSRMLS_CC);
	if (!fill_wand)
		return;

	border_wand = php_imagick_zval_to_pixelwand (border_param, IMAGICK_CLASS, &border_allocated TSRMLS_CC);
	if (!border_wand) {
		if (fill_allocated)
			fill_wand = DestroyPixelWand (fill_wand);
		return;
	}

	status = MagickColorFloodfillImage(intern->magick_wand, fill_wand, fuzz, border_wand, x, y);

	if (fill_allocated)
		fill_wand = DestroyPixelWand (fill_wand);

	if (border_allocated)
		border_wand = DestroyPixelWand (border_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to color floodfill image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */
#endif // #if MagickLibVersion < 0x700
#endif

/* {{{ proto Imagick Imagick::combineImages()
	Combines one or more images into a single image. The grayscale value of the pixels of each image in the sequence is assigned in order to the specified channels of the combined image. The typical ordering would be image 1 => Red, 2 => Green, 3 => Blue, etc.
*/
PHP_METHOD(Imagick, combineImages)
{
	MagickWand *tmp_wand;
	php_imagick_object *intern, *intern_return;
	im_long channel_type;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &channel_type) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;
	tmp_wand = MagickCombineImages(intern->magick_wand, channel_type);

	if (tmp_wand == NULL) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Combine images failed" TSRMLS_CC);
		return;
	}

	object_init_ex(return_value, php_imagick_sc_entry);
	intern_return = Z_IMAGICK_P(return_value);
	php_imagick_replace_magickwand(intern_return, tmp_wand);

	return;
}
/* }}} */

/* {{{ proto Imagick Imagick::setImage(Imagick replace )
	Replaces the current sequence
*/
PHP_METHOD(Imagick, setImage)
{
	zval *objvar;
	MagickBooleanType status;
	php_imagick_object *intern, *replace;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "O", &objvar, php_imagick_sc_entry) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	replace = Z_IMAGICK_P(objvar);
	if (php_imagick_ensure_not_empty (replace->magick_wand) == 0)
		return;

	status = MagickSetImage(intern->magick_wand, replace->magick_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set the image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;

}
/* }}} */

/* {{{ proto Imagick Imagick::getImage()
	Returns a new Imagick object with the current image sequence.
*/
PHP_METHOD(Imagick, getImage)
{
	MagickWand *tmp_wand;
	php_imagick_object *intern, *intern_return;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	tmp_wand = MagickGetImage(intern->magick_wand);

	if (tmp_wand == NULL) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Get image failed" TSRMLS_CC);
		return;
	}

	object_init_ex(return_value, php_imagick_sc_entry);
	intern_return = Z_IMAGICK_P(return_value);
	php_imagick_replace_magickwand(intern_return, tmp_wand);

	return;
}
/* }}} */

/* {{{ proto bool Imagick::addImage(Imagick source )
	Adds new image to Imagick object from the current position of the source object.
*/
PHP_METHOD(Imagick, addImage)
{
	php_imagick_object *intern, *intern_add;
	zval *add_obj;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "O", &add_obj, php_imagick_sc_entry) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	intern_add = Z_IMAGICK_P(add_obj);

	if (php_imagick_ensure_not_empty (intern_add->magick_wand) == 0)
		return;

	status = MagickAddImage(intern->magick_wand, intern_add->magick_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to add image" TSRMLS_CC);
		return;
	}

	MagickSetLastIterator(intern->magick_wand);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::newImage(int cols, int rows, ImagickPixel background[, string format] )
	Creates a new image and associates ImagickPixel value as background color
*/
PHP_METHOD(Imagick, newImage)
{
	php_imagick_object *intern;
	zval *param;
	MagickBooleanType status;
	im_long columns, rows;
	char *format = NULL;
	IM_LEN_TYPE format_len = 0;
	PixelWand *color_wand;
	zend_bool allocated;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "llz|s", &columns, &rows, &param, &format, &format_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	color_wand = php_imagick_zval_to_pixelwand (param, IMAGICK_CLASS, &allocated TSRMLS_CC);
	if (!color_wand)
		return;

	status = MagickNewImage(intern->magick_wand, columns, rows, color_wand);

	if (allocated)
		color_wand = DestroyPixelWand (color_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to create new image" TSRMLS_CC);
		return;
	}

	/* If the optional fourth parameter was given
		set the image format here */
	if (format != NULL && format_len > 0) {

		status = MagickSetImageFormat(intern->magick_wand, format);

		/* No magick is going to happen */
		if (status == MagickFalse) {
			php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set the image format" TSRMLS_CC);
			return;
		}
	}

	MagickSetLastIterator(intern->magick_wand);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::newPseudoImage(int cols, int rows, string pseudoString )
	Creates a new image using pseudo format
*/
PHP_METHOD(Imagick, newPseudoImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	im_long columns, rows;
	char *pseudo_string;
	IM_LEN_TYPE pseudo_string_len;
	struct php_imagick_file_t file = {0};
	php_imagick_rw_result_t rc;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "lls", &columns, &rows, &pseudo_string, &pseudo_string_len) == FAILURE) {
		return;
	}

	/* Allow only pseudo formats in this method */
	if (strchr (pseudo_string, ':') == NULL) {
		php_imagick_throw_exception(IMAGICK_CLASS, "Invalid pseudo format string" TSRMLS_CC);
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	/* Pseudo image needs a size set manually */
	status = MagickSetSize(intern->magick_wand, columns, rows);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to create new pseudo image" TSRMLS_CC);
		return;
	}

	if (!php_imagick_file_init(&file, pseudo_string, pseudo_string_len TSRMLS_CC)) {
		php_imagick_throw_exception(IMAGICK_CLASS, "Invalid filename provided" TSRMLS_CC);
		return;
	}
	rc = php_imagick_read_file(intern, &file, ImagickReadImage TSRMLS_CC);
	php_imagick_file_deinit(&file);

	if (rc != IMAGICK_RW_OK) {
		php_imagick_rw_fail_to_exception (intern->magick_wand, rc, pseudo_string TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::getImageTotalInkDensity()
	Gets the image total ink density.
*/
PHP_METHOD(Imagick, getImageTotalInkDensity)
{
	php_imagick_object *intern;
	double ink_density;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	ink_density = MagickGetImageTotalInkDensity(intern->magick_wand);
	RETVAL_DOUBLE(ink_density);
}
/* }}} */

/* {{{ proto bool Imagick::implodeImage(float radius )
	Creates a new image that is a copy of an existing one with the image pixels "implode" by the specified percentage. It allocates the memory necessary for the new Image structure and returns a pointer to the new image.
*/
PHP_METHOD(Imagick, implodeImage)
{
	php_imagick_object *intern;
	double radius;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d", &radius) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

#if MagickLibVersion >= 0x700
	{
	//TODO allow PixelInterpolateMethod be set
	PixelInterpolateMethod method = BilinearInterpolatePixel;
	status = MagickImplodeImage(intern->magick_wand, radius, method);
	}
#else
	status = MagickImplodeImage(intern->magick_wand, radius);
#endif

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to implode image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

#if MagickLibVersion >= 0x658
//Only stable as of 658
//http://upstream-tracker.org/compat_reports/imagemagick/6.5.7.7_to_6.5.7.8/abi_compat_report.html

/* {{{ proto bool Imagick::inverseFourierTransformImage(Imagick complement, bool magnitude)
*/
PHP_METHOD(Imagick, inverseFourierTransformImage)
{
	php_imagick_object *intern, *intern_complement;
	zval *complement_obj;
	zend_bool magnitude;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "Ob", &complement_obj, php_imagick_sc_entry, &magnitude) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	intern_complement = Z_IMAGICK_P(complement_obj);
	status =  MagickInverseFourierTransformImage(intern->magick_wand, intern_complement->magick_wand, magnitude);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to inversefouriertransformimage image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */
#endif

/* {{{ proto bool Imagick::levelImage(float blackPoint, float gamma, float whitePoint[, int channel] )
	Adjusts the levels of an image by scaling the colors falling between specified white and black points to the full available quantum range. The parameters provided represent the black, mid, and white points. The black point specifies the darkest color in the image. Colors darker than the black point are set to zero. Mid point specifies a gamma correction to apply to the image.  White point specifies the lightest color in the image. Colors brighter than the white point are set to the maximum quantum value.
*/
PHP_METHOD(Imagick, levelImage)
{
	php_imagick_object *intern;
	double black_point, gamma, white_point;
	MagickBooleanType status;
	im_long channel = IM_DEFAULT_CHANNEL;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ddd|l", &black_point, &gamma, &white_point, &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickLevelImageChannel(intern->magick_wand, channel, black_point, gamma, white_point);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to level image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::magnifyImage()
	Is a convenience method that scales an image proportionally to twice its original size.
*/
PHP_METHOD(Imagick, magnifyImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickMagnifyImage(intern->magick_wand);
		
	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to magnify image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
/* {{{ proto bool Imagick::cycleColormapImage(Imagick map, bool dither)
	Replaces the colors of an image with the closest color from a reference image.
*/
PHP_METHOD(Imagick, mapImage)
{
	php_imagick_object *intern, *intern_map;
	zval *map_obj;
	zend_bool dither;
	MagickBooleanType status;

	IMAGICK_METHOD_DEPRECATED ("Imagick", "mapImage");

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "Ob", &map_obj, php_imagick_sc_entry, &dither) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	intern_map = Z_IMAGICK_P(map_obj);
	status = MagickMapImage(intern->magick_wand, intern_map->magick_wand, dither);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to map image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */
#endif // #if MagickLibVersion < 0x700

#if MagickLibVersion < 0x700
/* {{{ proto bool Imagick::matteFloodfillImage(float alpha,float fuzz,ImagickPixel bordercolor, int x, int y)
	Changes the transparency value of any pixel that matches target and is an immediate neighbor
*/
PHP_METHOD(Imagick, matteFloodfillImage)
{
	php_imagick_object *intern;
	zval *param;
	im_long x, y;
	double alpha, fuzz;
	MagickBooleanType status;
	PixelWand *color_wand;
	zend_bool allocated;

	IMAGICK_METHOD_DEPRECATED("Imagick", "matteFloodfillImage");

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ddzll", &alpha, &fuzz, &param, &x, &y) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	color_wand = php_imagick_zval_to_pixelwand (param, IMAGICK_CLASS, &allocated TSRMLS_CC);
	if (!color_wand)
		return;

	status = MagickMatteFloodfillImage(intern->magick_wand, alpha, fuzz, color_wand, x, y);

	if (allocated)
		color_wand = DestroyPixelWand (color_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to matte floodfill image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */
#endif // #if MagickLibVersion < 0x700
#endif

#if MagickLibVersion < 0x700
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
/* {{{ proto bool Imagick::medianFilterImage(float radius)
	Applies a digital filter that improves the quality of a noisy image.  Each pixel is replaced by the median in a set of neighboring pixels as defined by radius.
*/
PHP_METHOD(Imagick, medianFilterImage)
{
	php_imagick_object *intern;
	double radius;
	MagickBooleanType status;

	IMAGICK_METHOD_DEPRECATED ("Imagick", "medianFilterImage");

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d", &radius) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickMedianFilterImage(intern->magick_wand, radius);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to median filter image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */
#endif
#endif

/* {{{ proto bool Imagick::negateImage(bool gray[, int channel] )
	Negates the colors in the reference image.  The Grayscale option means that only grayscale values within the image are negated.
*/
PHP_METHOD(Imagick, negateImage)
{
	php_imagick_object *intern;
	zend_bool gray;
	MagickBooleanType status;
	im_long channel = IM_DEFAULT_CHANNEL;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "b|l", &gray, &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickNegateImageChannel(intern->magick_wand, channel, gray);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to negate image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
/* {{{ proto bool Imagick::paintOpaqueImage(ImagickPixel target, ImagickPixel fill, float fuzz[, int channel])
	Changes any pixel that matches color with the color defined by fill. Channel argument is supported in ImageMagick 6.2.8+.
*/
PHP_METHOD(Imagick, paintOpaqueImage)
{
	php_imagick_object *intern;
	zval *target_param, *fill_param;
	double fuzz;
	MagickBooleanType status;
	im_long channel = DefaultChannels;
	PixelWand *target_wand, *fill_wand;
	zend_bool target_allocated = 0, fill_allocated = 0;

	IMAGICK_METHOD_DEPRECATED ("Imagick", "paintOpaqueImage");

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzd|l", &target_param, &fill_param, &fuzz, &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	target_wand = php_imagick_zval_to_pixelwand (target_param, IMAGICK_CLASS, &target_allocated TSRMLS_CC);
	if (!target_wand)
		return;

	fill_wand = php_imagick_zval_to_pixelwand (fill_param, IMAGICK_CLASS, &fill_allocated TSRMLS_CC);
	if (!fill_wand) {
		if (target_allocated)
			target_wand = DestroyPixelWand (target_wand);
		return;
	}

#if MagickLibVersion > 0x628
	status = MagickPaintOpaqueImageChannel(intern->magick_wand, channel, target_wand, fill_wand, fuzz);
#else
	status = MagickPaintOpaqueImage(intern->magick_wand, target_wand, fill_wand, fuzz);
#endif

	if (fill_allocated)
		fill_wand = DestroyPixelWand (fill_wand);

	if (target_allocated)
		target_wand = DestroyPixelWand (target_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable paint opaque image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */
#endif // #if MagickLibVersion < 0x700
#endif

#if MagickLibVersion > 0x628
/* {{{ proto Imagick Imagick::optimizeImageLayers()
	Compares each image the GIF disposed forms of the previous image in the sequence.  From this it attempts to select the smallest cropped image to replace each frame, while preserving the results of the animation.
*/
PHP_METHOD(Imagick, optimizeImageLayers)
{
	MagickWand *tmp_wand;
	php_imagick_object *intern, *intern_return;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	tmp_wand = MagickOptimizeImageLayers(intern->magick_wand);

	if (tmp_wand == NULL) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Optimize image layers failed" TSRMLS_CC);
		return;
	}

	object_init_ex(return_value, php_imagick_sc_entry);
	intern_return = Z_IMAGICK_P(return_value);
	php_imagick_replace_magickwand(intern_return, tmp_wand);

	return;
}
/* }}} */

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
/* {{{ proto bool Imagick::paintTransparentImage(ImagickPixel target, float alpha, float fuzz)
	Changes any pixel that matches color with the color defined by fill.
*/
PHP_METHOD(Imagick, paintTransparentImage)
{
	php_imagick_object *intern;
	zval *param;
	double alpha, fuzz;
	MagickBooleanType status;
	PixelWand *color_wand;
	zend_bool allocated;

	IMAGICK_METHOD_DEPRECATED ("Imagick", "paintTransparentImage");

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zdd", &param, &alpha, &fuzz) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	color_wand = php_imagick_zval_to_pixelwand (param, IMAGICK_CLASS, &allocated TSRMLS_CC);
	if (!color_wand)
		return;

	status = MagickPaintTransparentImage(intern->magick_wand, color_wand, alpha, fuzz);

	if (allocated)
		color_wand = DestroyPixelWand (color_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to paint transparent image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */
#endif // #if MagickLibVersion < 0x700
#endif
#endif

/* {{{ proto Imagick Imagick::previewImages(int preview )
	Tiles 9 thumbnails of the specified image with an image processing operation applied at varying strengths.
	This is helpful to quickly pin-point an appropriate parameter for an image processing operation.
*/
PHP_METHOD(Imagick, previewImages)
{
	php_imagick_object *intern, *intern_return;
	im_long preview;
	MagickWand *tmp_wand;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &preview) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	tmp_wand = MagickPreviewImages(intern->magick_wand, preview);

	if (tmp_wand == NULL) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Preview images failed" TSRMLS_CC);
		return;
	}

	object_init_ex(return_value, php_imagick_sc_entry);
	intern_return = Z_IMAGICK_P(return_value);
	php_imagick_replace_magickwand(intern_return, tmp_wand);
	return;
}
/* }}} */

/* {{{ proto bool Imagick::profileImage(string name,string profile)
	Adds or removes a ICC, IPTC, or generic profile from an image.  If the profile is NULL, it is removed from the image otherwise added.  Use a name of '*' and a profile of NULL to remove all profiles from the image.
*/
PHP_METHOD(Imagick, profileImage)
{
	php_imagick_object *intern;
	char *name, *profile;
	IM_LEN_TYPE name_len, profile_len;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss", &name, &name_len, &profile, &profile_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickProfileImage(intern->magick_wand, name, profile, profile_len);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to profile image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::quantizeImage(int numberColors, int colorspace, int treedepth, bool dither,
    bool measureError)
	Analyzes the colors within a reference image
*/
PHP_METHOD(Imagick, quantizeImage)
{
	php_imagick_object *intern;
	long number_colors, colorspace, tree_depth;
	zend_bool dither, measure_error;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "lllbb", &number_colors, &colorspace, &tree_depth, &dither, &measure_error) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickQuantizeImage(intern->magick_wand, number_colors, colorspace, tree_depth, dither, measure_error);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to quantize image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::quantizeImages(int number_colors, int colorspace, int treedepth, bool dither,
    bool measure_error)
	Analyzes the colors within a sequence of images
*/
PHP_METHOD(Imagick, quantizeImages)
{
	php_imagick_object *intern;
	im_long number_colors, colorspace, tree_depth;
	zend_bool dither, measure_error;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "lllbb", &number_colors, &colorspace, &tree_depth, &dither, &measure_error) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickQuantizeImages(intern->magick_wand, number_colors, colorspace, tree_depth, dither, measure_error);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to quantize images" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
/* {{{ proto bool Imagick::reduceNoiseImage(float radius)
	Smooths the contours of an image
*/
PHP_METHOD(Imagick, reduceNoiseImage)
{
	php_imagick_object *intern;
	double radius;
	MagickBooleanType status;

	IMAGICK_METHOD_DEPRECATED ("Imagick", "reduceNoiseImage");

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d", &radius) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickReduceNoiseImage(intern->magick_wand, radius);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to reduce image noise" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */
#endif
#endif

/* {{{ proto string Imagick::removeImageProfile(string name)
	Removes the named image profile and returns it
*/
PHP_METHOD(Imagick, removeImageProfile)
{
	php_imagick_object *intern;
	char *name;
	unsigned char *profile;
	IM_LEN_TYPE name_len;
#if MagickLibVersion < 0x628
	long profile_len;
#else
	size_t profile_len;
#endif

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &name, &name_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	profile = MagickRemoveImageProfile(intern->magick_wand, name, &profile_len);

	if (!profile) {
		php_imagick_throw_exception(IMAGICK_CLASS, "The image profile does not exist" TSRMLS_CC);
		return;
	}

	IM_ZVAL_STRING(return_value, (char *)profile);
	IMAGICK_FREE_MAGICK_MEMORY(profile);
	return;
}
/* }}} */

/* {{{ proto bool Imagick::separateImageChannel(int channel)
	Separates a channel from the image
*/
PHP_METHOD(Imagick, separateImageChannel)
{
	php_imagick_object *intern;
	im_long channel;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

#if MagickLibVersion >= 0x700
	status = MagickSeparateImage(intern->magick_wand, channel);
#else
	status = MagickSeparateImageChannel(intern->magick_wand, channel);
#endif

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to separate image channel" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::sepiaToneImage(float threshold)
	Applies a special effect to the image
*/
PHP_METHOD(Imagick, sepiaToneImage)
{
	php_imagick_object *intern;
	double threshold;
	double c_opacity;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d", &threshold) == FAILURE) {
		return;
	}

	c_opacity = (threshold * QuantumRange) / 100;

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSepiaToneImage(intern->magick_wand, c_opacity);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to sepia tone image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

#if MagickLibVersion < 0x700
/* {{{ proto bool Imagick::setImageBias(float bias)
	Sets the image bias
*/
static
void s_set_image_bias(INTERNAL_FUNCTION_PARAMETERS, zend_bool use_quantum)
{
	php_imagick_object *intern;
	double bias;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d", &bias) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	if (use_quantum) {
		bias *= QuantumRange;
	}

	status = MagickSetImageBias(intern->magick_wand, bias);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image bias" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */
#endif // #if MagickLibVersion < 0x700


/* {{{ proto bool Imagick::setImageBiasQuantum(float bias)
	Sets the image bias. Bias should be scaled with 0 = no adjustment, 1 = quantum value
*/
#if MagickLibVersion < 0x700
PHP_METHOD(Imagick, setImageBiasQuantum)
{
	s_set_image_bias (INTERNAL_FUNCTION_PARAM_PASSTHRU, 1);
}
#endif
/* }}} */


/* {{{ proto bool Imagick::setImageBias(float bias)
	Sets the image bias. Bias should be scaled with 0 = no adjustment, 2^^x = adjust black to white
	where x = the quantum depth ImageMagick was compiled with
*/
#if MagickLibVersion < 0x700
PHP_METHOD(Imagick, setImageBias)
{
	s_set_image_bias (INTERNAL_FUNCTION_PARAM_PASSTHRU, 0);
}
#endif
/* }}} */



/* {{{ proto bool Imagick::setImageBluePrimary(float x,float y)
For IM7 the prototype is 
proto bool Imagick::setImageBluePrimary(float x, float y, float z)

	Sets the image chromaticity blue primary point
*/
PHP_METHOD(Imagick, setImageBluePrimary)
{
	php_imagick_object *intern;
	double x, y;
#if MagickLibVersion >= 0x700
	double z;
#endif
	MagickBooleanType status;

	/* Parse parameters given to function */
#if MagickLibVersion >= 0x700
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ddd", &x, &y, &z) == FAILURE) {
#else 
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dd", &x, &y) == FAILURE) {
#endif
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

#if MagickLibVersion >= 0x700
	status = MagickSetImageBluePrimary(intern->magick_wand, x, y, z);
#else
	status = MagickSetImageBluePrimary(intern->magick_wand, x, y);
#endif

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image blue primary" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::setImageBorderColor(ImagickPixel border)
	Sets the image border color
*/
PHP_METHOD(Imagick, setImageBorderColor)
{
	zval *param;
	php_imagick_object *intern;
	MagickBooleanType status;
	PixelWand *color_wand;
	zend_bool allocated;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &param) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	color_wand = php_imagick_zval_to_pixelwand (param, IMAGICK_CLASS, &allocated TSRMLS_CC);
	if (!color_wand)
		return;

	status = MagickSetImageBorderColor(intern->magick_wand, color_wand);

	if (allocated)
		color_wand = DestroyPixelWand (color_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image border color" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::setImageChannelDepth(int channel, int depth)
	Sets the depth of a particular image channel
*/
PHP_METHOD(Imagick, setImageChannelDepth)
{
	php_imagick_object *intern;
	im_long channel_type, depth;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll", &channel_type, &depth) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSetImageChannelDepth(intern->magick_wand, channel_type, depth);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image channel depth" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::setImageColormapColor(int index, ImagickPixel color)
	Sets the color of the specified colormap index
*/
PHP_METHOD(Imagick, setImageColormapColor)
{
	php_imagick_object *intern;
	zval *param;
	long index;
	MagickBooleanType status;
	PixelWand *color_wand;
	zend_bool allocated;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "lz", &index, &param) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	color_wand = php_imagick_zval_to_pixelwand (param, IMAGICK_CLASS, &allocated TSRMLS_CC);
	if (!color_wand)
		return;

	status = MagickSetImageColormapColor(intern->magick_wand, index, color_wand);

	if (allocated)
		color_wand = DestroyPixelWand (color_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image color map color" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;

}
/* }}} */

/* {{{ proto bool Imagick::setImageColorspace(int colorspace)
	Sets the image colorspace
*/
PHP_METHOD(Imagick, setImageColorspace)
{
	php_imagick_object *intern;
	im_long colorspace;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &colorspace) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSetImageColorspace(intern->magick_wand, colorspace);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image colorspace" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::setImageDispose(int dispose)
	Sets the image disposal method
*/
PHP_METHOD(Imagick, setImageDispose)
{
	php_imagick_object *intern;
	im_long dispose;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &dispose) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSetImageDispose(intern->magick_wand, dispose);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image dispose" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::setImageExtent(int columns, int rows)
	Sets the image size
*/
PHP_METHOD(Imagick, setImageExtent)
{
	php_imagick_object *intern;
	im_long rows, columns;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll", &rows, &columns) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSetImageExtent(intern->magick_wand, rows, columns);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image extent" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::setImageGreenPrimary(float x, float y)
For IM7 the prototype is 
proto bool Imagick::setImageGreenPrimary(float x, float y, float z)
	Sets the image chromaticity green primary point
*/
PHP_METHOD(Imagick, setImageGreenPrimary)
{
	php_imagick_object *intern;
	double x, y;
#if MagickLibVersion >= 0x700
	double z;
#endif
	MagickBooleanType status;


	/* Parse parameters given to function */
#if MagickLibVersion >= 0x700
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ddd", &x, &y, &z) == FAILURE) {
#else
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dd", &x, &y) == FAILURE) {
#endif
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

#if MagickLibVersion >= 0x700
	status = MagickSetImageGreenPrimary(intern->magick_wand, x, y, z);
#else
	status = MagickSetImageGreenPrimary(intern->magick_wand, x, y);
#endif

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image green primary" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::setImageInterlaceScheme(int interlace_scheme)
	Sets the image interlace scheme
*/
PHP_METHOD(Imagick, setImageInterlaceScheme)
{
	php_imagick_object *intern;
	im_long interlace;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &interlace) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSetImageInterlaceScheme(intern->magick_wand, interlace);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image interlace scheme" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::setImageProfile(string name, string profile)
	Adds a named profile to the Imagick object
*/
PHP_METHOD(Imagick, setImageProfile)
{
	php_imagick_object *intern;
	char *name, *profile;
	IM_LEN_TYPE profile_len, name_len;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss", &name, &name_len, &profile, &profile_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSetImageProfile(intern->magick_wand, name, profile, profile_len);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image profile" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::setImageRedPrimary(float x,float y)
For IM7 the prototype is 
proto bool Imagick::setImageRedPrimary(float x, float y, float z)

	Sets the image chromaticity red primary point.
*/
PHP_METHOD(Imagick, setImageRedPrimary)
{
	php_imagick_object *intern;
	double x, y;
#if MagickLibVersion >= 0x700
	double z;
#endif
	MagickBooleanType status;

	/* Parse parameters given to function */
#if MagickLibVersion >= 0x700
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ddd", &x, &y, &z) == FAILURE) {
#else 
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dd", &x, &y) == FAILURE) {
#endif
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

#if MagickLibVersion >= 0x700
	status = MagickSetImageRedPrimary(intern->magick_wand, x, y, z);
#else
	status = MagickSetImageRedPrimary(intern->magick_wand, x, y);
#endif

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image red primary" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::setImageRenderingIntent(int rendering_intent)
	Sets the image rendering intent.
*/
PHP_METHOD(Imagick, setImageRenderingIntent)
{
	php_imagick_object *intern;
	im_long rendering_intent;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &rendering_intent) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSetImageRenderingIntent(intern->magick_wand, rendering_intent);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image rendering intent" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::setImageVirtualPixelMethod(int method)
	Sets the image virtual pixel method.
*/
PHP_METHOD(Imagick, setImageVirtualPixelMethod)
{
	php_imagick_object *intern;
	im_long virtual_pixel;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &virtual_pixel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	MagickSetImageVirtualPixelMethod(intern->magick_wand, virtual_pixel);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::setImageWhitePoint(float x, float y)

For IM7 the prototype is 
proto bool Imagick::setImageWhitePoint(float x, float y, float z)

	Sets the image chromaticity white point.
*/
PHP_METHOD(Imagick, setImageWhitePoint)
{
	php_imagick_object *intern;
	double x, y;
#if MagickLibVersion >= 0x700
	double z;
#endif
	MagickBooleanType status;

	/* Parse parameters given to function */
#if MagickLibVersion >= 0x700
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ddd", &x, &y, &z) == FAILURE) {
#else
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dd", &x, &y) == FAILURE) {
#endif
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

#if MagickLibVersion >= 0x700
	status = MagickSetImageWhitePoint(intern->magick_wand, x, y, z);
#else
	status = MagickSetImageWhitePoint(intern->magick_wand, x, y);
#endif

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image white point" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::sigmoidalContrastImage(bool sharpen, float contrast, float midpoint[, int channel])
	Adjusts the contrast of an image with a non-linear sigmoidal contrast algorithm.  Increase the contrast of the image using a sigmoidal transfer function without saturating highlights or shadows.  Contrast indicates how much to increase the contrast (0 is none; 3 is typical; 20 is pushing it); mid-point indicates where midtones fall in the resultant image (0 is white; 50 is middle-gray; 100 is black).  Set sharpen to true to increase the image contrast otherwise the contrast is reduced.
*/
PHP_METHOD(Imagick, sigmoidalContrastImage)
{
	php_imagick_object *intern;
	zend_bool sharpen;
	double contrast, midpoint;
	MagickBooleanType status;
	im_long channel = IM_DEFAULT_CHANNEL;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "bdd|l", &sharpen, &contrast, &midpoint, &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSigmoidalContrastImageChannel(intern->magick_wand, channel, sharpen, contrast, midpoint);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to sigmoidal contrast image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::stereoImage(Imagick offset_wand)
	Composites two images and produces a single image that is the composite of a left and right image of a stereo pair
*/
PHP_METHOD(Imagick, stereoImage)
{
	MagickWand *tmp_wand;
	zval *magick_object;
	php_imagick_object *intern, *intern_second, *intern_return;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "O", &magick_object, php_imagick_sc_entry) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	intern_second = Z_IMAGICK_P(magick_object);
	if (php_imagick_ensure_not_empty (intern_second->magick_wand) == 0)
		return;

	tmp_wand = MagickStereoImage(intern->magick_wand, intern_second->magick_wand);

	if (tmp_wand == NULL) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Stereo image failed" TSRMLS_CC);
		return;
	}

	object_init_ex(return_value, php_imagick_sc_entry);
	intern_return = Z_IMAGICK_P(return_value);
	php_imagick_replace_magickwand(intern_return, tmp_wand);

	return;
}
/* }}} */

/* {{{ proto Imagick Imagick::textureImage(Imagick texture_wand)
	Repeatedly tiles the texture image across and down the image canvas.
*/
PHP_METHOD(Imagick, textureImage)
{
	MagickWand *tmp_wand;
	zval *magick_object;
	php_imagick_object *intern, *intern_second, *intern_return;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "O", &magick_object, php_imagick_sc_entry) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	intern_second = Z_IMAGICK_P(magick_object);
	if (php_imagick_ensure_not_empty (intern_second->magick_wand) == 0)
		return;

	tmp_wand = MagickTextureImage(intern->magick_wand, intern_second->magick_wand);

	if (!tmp_wand) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Texture image failed" TSRMLS_CC);
		return;
	}

	object_init_ex(return_value, php_imagick_sc_entry);
	intern_return = Z_IMAGICK_P(return_value);
	php_imagick_replace_magickwand(intern_return, tmp_wand);

	return;
}
/* }}} */

/* {{{ proto bool Imagick::tintImage(ImagickPixel tint, ImagickPixel opacity, bool legacy = false)
	Applies a color vector to each pixel in the image. The 'opacity' color is a per channel
	strength factor for how strongly the color should be applied. If legacy is true, the behaviour
	of this function is incorrect, but consistent with how it behaved before Imagick version 3.4.0
*/
PHP_METHOD(Imagick, tintImage)
{
	php_imagick_object *intern;
	zval *tint_param, *opacity_param;
	MagickBooleanType status;
	PixelWand *tint_wand, *opacity_wand;
	zend_bool tint_allocated, opacity_allocated;
	zend_bool legacy = 0;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|b", &tint_param, &opacity_param, &legacy) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	tint_wand = php_imagick_zval_to_pixelwand (tint_param, IMAGICK_CLASS, &tint_allocated TSRMLS_CC);
	if (!tint_wand)
		return;

	if (legacy) {
		opacity_wand = php_imagick_zval_to_opacity(opacity_param, IMAGICK_CLASS, &opacity_allocated TSRMLS_CC);
		}
	else {
		opacity_wand = php_imagick_zval_to_pixelwand(opacity_param, IMAGICK_CLASS, &opacity_allocated TSRMLS_CC);
	}
	
	
	if (!opacity_wand) {
		if (tint_allocated)
			tint_wand = DestroyPixelWand (tint_wand);
		return;
	}

	status = MagickTintImage(intern->magick_wand, tint_wand, opacity_wand);

	if (tint_allocated)
		tint_wand = DestroyPixelWand (tint_wand);

	if (opacity_allocated)
		opacity_wand = DestroyPixelWand (opacity_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable tint image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::unsharpMaskImage(float radius, float sigma, float amount, float threshold[, int channel])
	Sharpens an image.  We convolve the image with a Gaussian operator of the given radius and standard deviation (sigma). For reasonable results, radius should be larger than sigma.  Use a radius of 0 and Imagick::UnsharpMaskImage() selects a suitable radius for you.
*/
PHP_METHOD(Imagick, unsharpMaskImage)
{
	php_imagick_object *intern;
	double radius, sigma, amount, threshold;
	MagickBooleanType status;
	im_long channel = IM_DEFAULT_CHANNEL;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dddd|l", &radius, &sigma, &amount, &threshold, &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickUnsharpMaskImageChannel(intern->magick_wand, channel, radius, sigma, amount, threshold);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to unsharp mask image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

	


#if MagickLibVersion >= 0x700

/* {{{ proto bool Imagick::convolveImage(array kernel[, int channel])
	Applies a custom convolution kernel to the image.
*/
PHP_METHOD(Imagick, convolveImage)
{
	zval *objvar;
	php_imagick_object *intern;
	php_imagickkernel_object *kernel;
	MagickBooleanType status;
	im_long channel = IM_DEFAULT_CHANNEL;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "O|l", &objvar, php_imagickkernel_sc_entry, &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	kernel = Z_IMAGICKKERNEL_P(objvar);

	IMAGICK_KERNEL_NOT_NULL_EMPTY(kernel);
	status = MagickConvolveImageChannel(intern->magick_wand, channel, kernel->kernel_info);

	// No magick is going to happen
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Failed to filter image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}

#else

/* {{{ proto bool Imagick::convolveImage(array kernel[, int channel])
	Applies a custom convolution kernel to the image.
*/
PHP_METHOD(Imagick, convolveImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	zval *kernel_array;
	double *kernel;
	im_long channel = DefaultChannels;
	unsigned long order = 0;
	im_long num_elements = 0;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "a|l",  &kernel_array, &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	kernel = php_imagick_zval_to_double_array(kernel_array, &num_elements TSRMLS_CC);

	if (!kernel) {
		php_imagick_throw_exception(IMAGICK_CLASS, "Unable to read matrix array" TSRMLS_CC);
		return;
	}

	order = (unsigned long) sqrt(num_elements);
	status = MagickConvolveImageChannel(intern->magick_wand, channel, order, kernel);
	efree(kernel);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to convolve image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */
#endif

/* {{{ proto bool Imagick::cycleColormapImage(int displace)
	Displaces an image's colormap by a given number of positions.  If you cycle the colormap a number of times you can produce a psychodelic effect.
*/
PHP_METHOD(Imagick, cycleColormapImage)
{
	php_imagick_object *intern;
	im_long displace;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &displace) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickCycleColormapImage(intern->magick_wand, displace);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to cycle image colormap" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto Imagick Imagick::deconstructImages()
	Compares each image with the next in a sequence and returns the maximum bounding region of any pixel differences it discovers.
*/
PHP_METHOD(Imagick, deconstructImages)
{
	MagickWand *tmp_wand;
	php_imagick_object *intern, *intern_return;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	tmp_wand = MagickDeconstructImages(intern->magick_wand);

	if (tmp_wand == NULL) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Deconstruct image failed" TSRMLS_CC);
		return;
	}

	object_init_ex(return_value, php_imagick_sc_entry);
	intern_return = Z_IMAGICK_P(return_value);
	php_imagick_replace_magickwand(intern_return, tmp_wand);

	return;
}
/* }}} */

/* {{{ proto Imagick Imagick::getImageRegion(int width, int height, int x, int y)
	Extracts a region of the image and returns it as a new image.
*/
PHP_METHOD(Imagick, getImageRegion)
{
	MagickWand *tmp_wand;
	php_imagick_object *intern, *intern_return;
	im_long width, height, x, y;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "llll", &width, &height, &x, &y) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	tmp_wand = MagickGetImageRegion(intern->magick_wand, width, height, x, y);

	if (tmp_wand == NULL) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Get image region failed" TSRMLS_CC);
		return;
	}

	object_init_ex(return_value, php_imagick_sc_entry);
	intern_return = Z_IMAGICK_P(return_value);
	php_imagick_replace_magickwand(intern_return, tmp_wand);

	return;

}
/* }}} */

/* {{{ proto bool Imagick::despeckleImage()
	Reduces the speckle noise in an image while perserving the edges of the original image.
*/
PHP_METHOD(Imagick, despeckleImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickDespeckleImage(intern->magick_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to despeckle image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::edgeImage(float radius)
	Enhance edges within the image with a convolution filter of the given radius.  Use a radius of 0 and Edge() selects a suitable radius for you.
*/
PHP_METHOD(Imagick, edgeImage)
{
	php_imagick_object *intern;
	double radius;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d", &radius) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickEdgeImage(intern->magick_wand, radius);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to edge image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;

}
/* }}} */

/* {{{ proto bool Imagick::embossImage(float radius, float sigma)
	Returns a grayscale image with a three-dimensional effect.  We convolve the image with a Gaussian operator of the given radius and standard deviation (sigma).  For reasonable results, radius should be larger than sigma.  Use a radius of 0 and it will choose a suitable radius for you.
*/
PHP_METHOD(Imagick, embossImage)
{
	php_imagick_object *intern;
	double radius, sigma;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dd", &radius, &sigma) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickEmbossImage(intern->magick_wand, radius, sigma);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to emboss image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::enhanceImage()
	Applies a digital filter that improves the quality of a noisy image.
*/
PHP_METHOD(Imagick, enhanceImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickEnhanceImage(intern->magick_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to enchance image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::equalizeImage()
	Equalizes the image histogram.
*/
PHP_METHOD(Imagick, equalizeImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickEqualizeImage(intern->magick_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to equalize image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::evaluateImage(int op, float constant[, int channel])
	Applys an arithmetic, relational, or logical expression to an image.  Use these operators to lighten or darken an image, to increase or decrease contrast in an image, or to produce the "negative" of an image.
*/
PHP_METHOD(Imagick, evaluateImage)
{
	php_imagick_object *intern;
	im_long evaluate_operator;
	double constant;
	MagickBooleanType status;
	im_long channel = IM_DEFAULT_CHANNEL;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ld|l", &evaluate_operator, &constant, &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickEvaluateImageChannel(intern->magick_wand, channel, evaluate_operator, constant);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to evaluate image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */


#if MagickLibVersion >= 0x687
/* {{{ proto bool Imagick::evaluateImages(int EVALUATE_CONSTANT)
	Merge multiple images of the same size together with the selected operator.
http://www.imagemagick.org/Usage/layers/#evaluate-sequence
*/
PHP_METHOD(Imagick, evaluateImages)
{
	php_imagick_object *intern, *intern_return;
	im_long evaluate_operator;
	MagickBooleanType status;
	MagickWand *evaluated_wand;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &evaluate_operator) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

// MagickEvaluateImages appears to crash if index is not zero.
#if MagickLibVersion > 0x628
	/* Get the current iterator position */
	status = MagickSetIteratorIndex(intern->magick_wand, 0);
#else
	status = MagickSetImageIndex(intern->magick_wand, 0);
#endif

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set iterator index" TSRMLS_CC);
		return;
	}

	evaluated_wand = MagickEvaluateImages(intern->magick_wand, evaluate_operator);

	object_init_ex(return_value, php_imagick_sc_entry);
	intern_return = Z_IMAGICK_P(return_value);
	php_imagick_replace_magickwand(intern_return, evaluated_wand);
	return;
}
/* }}} */
#endif //MagickLibVersion >= 0x687

#if MagickLibVersion > 0x655

/* {{{ proto bool Imagick::forwardfouriertransformimage(bool magnitude)
	//http://www.fftw.org/
	yum install fftw-devel fftw
	./configure --enable-hdri
*/
PHP_METHOD(Imagick, forwardFourierTransformImage)
{
	php_imagick_object *intern;
	zend_bool magnitude;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "b", &magnitude) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickForwardFourierTransformImage(intern->magick_wand, magnitude);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to forwardfouriertransformimage image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

#endif


/* {{{ proto array Imagick::getImageGeometry()
	Returns the width and height as an associative array.
*/
PHP_METHOD(Imagick, getImageGeometry)
{
	long width,height;
	php_imagick_object *intern;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	width = MagickGetImageWidth(intern->magick_wand);
	height = MagickGetImageHeight(intern->magick_wand);

	array_init(return_value);
	add_assoc_long(return_value, "width", width);
	add_assoc_long(return_value, "height", height);

	return;
}
/* }}} */

#if MagickLibVersion < 0x700
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
/* {{{ proto ImagickPixel Imagick::getImageAttribute(string key )
	Returns a named attribute
*/
PHP_METHOD(Imagick, getImageAttribute)
{
	php_imagick_object *intern;
	char *key, *attribute;
	IM_LEN_TYPE key_len;

	IMAGICK_METHOD_DEPRECATED("Imagick", "getImageAttribute");

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &key, &key_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	attribute = MagickGetImageAttribute(intern->magick_wand, key);

	if (!attribute) {
		RETURN_FALSE;
	}

	IM_ZVAL_STRING(return_value, attribute);
	IMAGICK_FREE_MAGICK_MEMORY(attribute);

	return;
}
/* }}} */
#endif
#endif

/* {{{ proto ImagickPixel Imagick::getImageBackgroundColor()
	Returns the image background color.
*/
PHP_METHOD(Imagick, getImageBackgroundColor)
{
	php_imagick_object *intern;
	php_imagickpixel_object *internp;
	MagickBooleanType status;
	PixelWand *tmp_wand;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	tmp_wand = NewPixelWand();
	status = MagickGetImageBackgroundColor(intern->magick_wand, tmp_wand);

	if (tmp_wand == (PixelWand *)NULL) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to get image background color" TSRMLS_CC);
		return;
	}

	if (status == MagickFalse) {
		tmp_wand = DestroyPixelWand(tmp_wand);
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to get image background color" TSRMLS_CC);
		return;
	}

	object_init_ex(return_value, php_imagickpixel_sc_entry);
	internp = Z_IMAGICKPIXEL_P(return_value);
	php_imagick_replace_pixelwand(internp, tmp_wand);

	return;
}
/* }}} */

/* {{{ proto array Imagick::getImageBluePrimary()
	Returns the chromaticy green primary point. IM6: Returns an array with the keys "x" and "y".
	IM7: Returns an array with the keys "x", "y" and "z".
*/
PHP_METHOD(Imagick, getImageBluePrimary)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	double x, y;
#if MagickLibVersion >= 0x700
	double z;
#endif

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

#if MagickLibVersion >= 0x700
	status = MagickGetImageBluePrimary(intern->magick_wand, &x, &y, &z);
#else
	status = MagickGetImageBluePrimary(intern->magick_wand, &x, &y);
#endif

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to get image blue primary" TSRMLS_CC);
		return;
	}

	array_init(return_value);
	add_assoc_double(return_value, "x", x);
	add_assoc_double(return_value, "y", y);
#if MagickLibVersion >= 0x700
	add_assoc_double(return_value, "z", z);
#endif

	return;
}
/* }}} */

/* {{{ proto ImagickPixel Imagick::getImageBorderColor()
	Returns the image border color.
*/
PHP_METHOD(Imagick, getImageBorderColor)
{
	php_imagick_object *intern;
	php_imagickpixel_object *internp;
	MagickBooleanType status;
	PixelWand *tmp_wand;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	tmp_wand = NewPixelWand();
	status = MagickGetImageBorderColor(intern->magick_wand, tmp_wand);

	if (tmp_wand == (PixelWand *)NULL) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to get image border color" TSRMLS_CC);
		return;
	}

	if (status == MagickFalse) {
		tmp_wand = DestroyPixelWand(tmp_wand);
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to get image border color" TSRMLS_CC);
		return;
	}

	object_init_ex(return_value, php_imagickpixel_sc_entry);
	internp = Z_IMAGICKPIXEL_P(return_value);
	php_imagick_replace_pixelwand(internp, tmp_wand);

	return;
}
/* }}} */

/* {{{ proto int Imagick::getImageChannelDepth()
	Gets the depth for a particular image channel.
*/
PHP_METHOD(Imagick, getImageChannelDepth)
{
	php_imagick_object *intern;
	im_long channel_type, channel_depth;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &channel_type) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	channel_depth = MagickGetImageChannelDepth(intern->magick_wand, channel_type);
	RETVAL_LONG(channel_depth);
}
/* }}} */

/* {{{ proto float Imagick::getImageChannelDistortion(Imagick reference, int channel, int metric)
	Compares one or more image channels of an image to a reconstructed image and returns the specified distortion metric.
*/
PHP_METHOD(Imagick, getImageChannelDistortion)
{
	zval *objvar;
	php_imagick_object *intern, *intern_second;
	im_long channel_type, metric_type;
	double distortion;
	MagickBooleanType status;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "Oll", &objvar, php_imagick_sc_entry, &channel_type, &metric_type) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	intern_second = Z_IMAGICK_P(objvar);
	if (php_imagick_ensure_not_empty (intern_second->magick_wand) == 0)
		return;

	status = MagickGetImageChannelDistortion(intern->magick_wand, intern_second->magick_wand, channel_type, metric_type, &distortion);

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to get image channel distortion" TSRMLS_CC);
		return;
	}

	RETVAL_DOUBLE(distortion);

}
/* }}} */

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
/* {{{ proto array Imagick::getImageChannelExtrema(int channel)
	Gets the extrema for one or more image channels.  Return value is an associative array with the keys "minima" and "maxima".
*/
PHP_METHOD(Imagick, getImageChannelExtrema)
{
	php_imagick_object *intern;
	im_long channel_type;
	size_t minima, maxima;
	MagickBooleanType status;

	IMAGICK_METHOD_DEPRECATED ("Imagick", "getImageChannelExtrema");

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &channel_type) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickGetImageChannelExtrema(intern->magick_wand, channel_type, &minima, &maxima);

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to get image channel extrema" TSRMLS_CC);
		return;
	}

	array_init(return_value);
	add_assoc_long(return_value, "minima", minima);
	add_assoc_long(return_value, "maxima", maxima);

	return;
}
/* }}} */
#endif //#if MagickLibVersion < 0x700
#endif

/* {{{ proto array Imagick::getImageChannelMean(int channel)
	Gets the mean and standard deviation of one or more image channels.  Return value is an associative array with the keys "mean" and "standardDeviation".
*/
PHP_METHOD(Imagick, getImageChannelMean)
{
	php_imagick_object *intern;
	im_long channel_type;
	double mean, standard_deviation;
	MagickBooleanType status;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &channel_type) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickGetImageChannelMean(intern->magick_wand, channel_type, &mean, &standard_deviation);

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to get image channel mean" TSRMLS_CC);
		return;
	}

	array_init(return_value);
	add_assoc_double(return_value, "mean", mean);
	add_assoc_double(return_value, "standardDeviation", standard_deviation);

	return;
}
/* }}} */

/* {{{ proto array Imagick::getImageChannelStatistics()
	Returns statistics for each channel in the image.  The statistics incude the channel depth, its minima and maxima, the mean, and the standard deviation.  You can access the red channel mean, for example, like this:
*/
PHP_METHOD(Imagick, getImageChannelStatistics)
{
#ifdef ZEND_ENGINE_3
	zval tmp;
#else
 	zval *tmp;
#endif

	const long channels[] = { 
		UndefinedChannel, RedChannel, CyanChannel,
		GreenChannel, MagentaChannel, BlueChannel,
		YellowChannel, OpacityChannel, BlackChannel,
#if MagickLibVersion < 0x700
		 MatteChannel
#endif
	};
	php_imagick_object *intern;
	ChannelStatistics *statistics;
	unsigned int i;
#if MagickLibVersion < 0x700
	unsigned int elements = 10;
#endif // #if MagickLibVersion >= 0x700

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

#if MagickLibVersion >= 0x700
	statistics = MagickGetImageStatistics(intern->magick_wand);
#else
	statistics = MagickGetImageChannelStatistics(intern->magick_wand);
#endif

	array_init(return_value);

#if MagickLibVersion >= 0x700
	for (i=0; i < sizeof(channels)/sizeof(channels[0]); i++) {
#ifdef ZEND_ENGINE_3
		ZVAL_NEW_ARR(&tmp);
		array_init(&tmp);
		add_assoc_double(&tmp, "mean", statistics[i].mean);
		add_assoc_double(&tmp, "minima", statistics[i].minima);
		add_assoc_double(&tmp, "maxima", statistics[i].maxima);
		add_assoc_double(&tmp, "standardDeviation", statistics[i].standard_deviation);
#if MagickLibVersion < 0x635
		add_assoc_long(&tmp, "scale", statistics[i].scale);
#endif //0x635
		add_assoc_long(&tmp, "depth", statistics[i].depth);
		add_index_zval(return_value, i, &tmp);
#else //not ZE3
		MAKE_STD_ZVAL(tmp);
		array_init(tmp);
		add_assoc_double(tmp, "mean", statistics[i].mean);
		add_assoc_double(tmp, "minima", statistics[i].minima);
		add_assoc_double(tmp, "maxima", statistics[i].maxima);
		add_assoc_double(tmp, "standardDeviation", statistics[i].standard_deviation);
#if MagickLibVersion < 0x635
		add_assoc_long(&tmp, "scale", statistics[i].scale);
#endif //0x635
		add_assoc_long(tmp, "depth", statistics[i].depth);
		add_index_zval(return_value, channels[i], tmp);
#endif //end ZE3
	}
#else //below MagickLibVersion>= 0x700
	for (i = 0; i < elements ; i++) {
#ifdef ZEND_ENGINE_3
		ZVAL_NEW_ARR(&tmp);
		array_init(&tmp);
		add_assoc_double(&tmp, "mean", statistics[channels[i]].mean);
		add_assoc_double(&tmp, "minima", statistics[channels[i]].minima);
		add_assoc_double(&tmp, "maxima", statistics[channels[i]].maxima);
		add_assoc_double(&tmp, "standardDeviation", statistics[channels[i]].standard_deviation);
#if MagickLibVersion < 0x635
		add_assoc_long(&tmp, "scale", statistics[channels[i]].scale);
#endif
		add_assoc_long(&tmp, "depth", statistics[channels[i]].depth);
		add_index_zval(return_value, channels[i], &tmp);
#else
		MAKE_STD_ZVAL(tmp);
		array_init(tmp);
		add_assoc_double(tmp, "mean", statistics[channels[i]].mean);
		add_assoc_double(tmp, "minima", statistics[channels[i]].minima);
		add_assoc_double(tmp, "maxima", statistics[channels[i]].maxima);
		add_assoc_double(tmp, "standardDeviation", statistics[channels[i]].standard_deviation);
#if MagickLibVersion < 0x635
		add_assoc_long(&tmp, "scale", statistics[channels[i]].scale);
#endif
		add_assoc_long(tmp, "depth", statistics[channels[i]].depth);
		add_index_zval(return_value, channels[i], tmp);
#endif

	}
#endif

//etc.
//    channel_statistics[i].sum_squared*=area;
//    channel_statistics[i].sum_cubed*=area;
//    channel_statistics[i].sum_fourth_power*=area;

	MagickRelinquishMemory(statistics);
	return;
}
/* }}} */

/* {{{ proto ImagickPixel Imagick::getImageColormapColor(int index, ImagickPixel color)
	Returns the color of the specified colormap index.
*/
PHP_METHOD(Imagick, getImageColormapColor)
{
	php_imagick_object *intern;
	php_imagickpixel_object *internp;
	MagickBooleanType status;
	PixelWand *tmp_wand;
	im_long index;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &index) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	tmp_wand = NewPixelWand();
	status = MagickGetImageColormapColor(intern->magick_wand, index , tmp_wand);

	if (tmp_wand == (PixelWand *)NULL) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to get image colormap color" TSRMLS_CC);
		return;
	}

	if (status == MagickFalse) {
		tmp_wand = DestroyPixelWand(tmp_wand);
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to get image colormap color" TSRMLS_CC);
		return;
	}

	object_init_ex(return_value, php_imagickpixel_sc_entry);
	internp = Z_IMAGICKPIXEL_P(return_value);
	php_imagick_replace_pixelwand(internp, tmp_wand);

	return;
}
/* }}} */

/* {{{ proto int Imagick::getImageColorspace()
	Gets the image colorspace.
*/
PHP_METHOD(Imagick, getImageColorspace)
{
	php_imagick_object *intern;
	long colorSpace;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	colorSpace = MagickGetImageColorspace(intern->magick_wand);
	RETVAL_LONG(colorSpace);
}
/* }}} */

/* {{{ proto int Imagick::getImageCompose()
	Returns the composite operator associated with the image.
*/
PHP_METHOD(Imagick, getImageCompose)
{
	php_imagick_object *intern;
	long composite;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	composite = MagickGetImageCompose(intern->magick_wand);
	RETVAL_LONG(composite);
}
/* }}} */

/* {{{ proto int Imagick::getImageDelay()
	Gets the image delay.
*/
PHP_METHOD(Imagick, getImageDelay)
{
	php_imagick_object *intern;
	long delay;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	delay = MagickGetImageDelay(intern->magick_wand);
	RETVAL_LONG(delay);
}
/* }}} */

/* {{{ proto int Imagick::getImageDepth()
	Gets the image depth.
*/
PHP_METHOD(Imagick, getImageDepth)
{
	php_imagick_object *intern;
	long depth;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	depth = MagickGetImageDepth(intern->magick_wand);
	RETVAL_LONG(depth);
}
/* }}} */

/* {{{ proto float Imagick::getImageDistortion(MagickWand reference, int metric)
	Compares an image to a reconstructed image and returns the specified distortion metric.
*/
PHP_METHOD(Imagick, getImageDistortion)
{
	zval *objvar;
	php_imagick_object *intern, *intern_second;
	im_long metric_type;
	double distortion;
	MagickBooleanType status;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "Ol", &objvar, php_imagick_sc_entry, &metric_type) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	intern_second = Z_IMAGICK_P(objvar);
	if (php_imagick_ensure_not_empty (intern_second->magick_wand) == 0)
		return;

	status = MagickGetImageDistortion(intern->magick_wand, intern_second->magick_wand, metric_type, &distortion);

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to get image distortion" TSRMLS_CC);
		return;
	}

	RETVAL_DOUBLE(distortion);
}
/* }}} */

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
/* {{{ proto array Imagick::getImageExtrema()
	Gets the extrema for the image.  Returns an associative array with the keys "min" and "max".
*/
PHP_METHOD(Imagick, getImageExtrema)
{
	php_imagick_object *intern;
	size_t min, max;
	MagickBooleanType status;

	IMAGICK_METHOD_DEPRECATED ("Imagick", "getImageExtrema");

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickGetImageExtrema(intern->magick_wand, &min, &max);

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to get image extrema" TSRMLS_CC);
		return;
	}

	array_init(return_value);
	add_assoc_long(return_value, "min", min);
	add_assoc_long(return_value, "max", max);

	return;
}
/* }}} */
#endif //#if MagickLibVersion < 0x700
#endif

/* {{{ proto long Imagick::getImageDispose()
	Gets the image disposal method.
*/
PHP_METHOD(Imagick, getImageDispose)
{
	php_imagick_object *intern;
	long dispose;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	dispose = MagickGetImageDispose(intern->magick_wand);
	RETVAL_LONG(dispose);
}
/* }}} */

/* {{{ proto float Imagick::getImageGamma()
	Gets the image gamma.
*/
PHP_METHOD(Imagick, getImageGamma)
{
	php_imagick_object *intern;
	double gamma;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	gamma = MagickGetImageGamma(intern->magick_wand);
	RETVAL_DOUBLE(gamma);
}
/* }}} */

/* {{{ proto array Imagick::getImageGreenPrimary()
	Returns the chromaticy green primary point. IM6: Returns an array with the keys "x" and "y".
	IM7: Returns an array with the keys "x", "y" and "z".
*/
PHP_METHOD(Imagick, getImageGreenPrimary)
{
	php_imagick_object *intern;
	double x, y;
#if MagickLibVersion >= 0x700
	double z;
#endif
	MagickBooleanType status;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

#if MagickLibVersion >= 0x700
	status = MagickGetImageGreenPrimary(intern->magick_wand, &x, &y, &z);
#else
	status = MagickGetImageGreenPrimary(intern->magick_wand, &x, &y);
#endif

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to get image green primary" TSRMLS_CC);
		return;
	}

	array_init(return_value);
	add_assoc_double(return_value, "x", x);
	add_assoc_double(return_value, "y", y);
#if MagickLibVersion >= 0x700
	add_assoc_double(return_value, "z", z);
#endif

	return;
}
/* }}} */

/* {{{ proto int Imagick::getImageHeight()
	Returns the image height.
*/
PHP_METHOD(Imagick, getImageHeight)
{
	php_imagick_object *intern;
	long height;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	height = MagickGetImageHeight(intern->magick_wand);
	RETVAL_LONG(height);
}
/* }}} */

/* {{{ proto array Imagick::getImageHistogram()
	Returns the image histogram as an array of ImagickPixel objects.
*/
PHP_METHOD(Imagick, getImageHistogram)
{
	php_imagick_object *intern;
	php_imagickpixel_object *internp;
	PixelWand **wand_array;
	size_t colors = 0;
	unsigned long i;
#ifdef ZEND_ENGINE_3
	zval tmp_pixelwand;
#else
	zval *tmp_pixelwand;
#endif


	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	wand_array = MagickGetImageHistogram(intern->magick_wand, &colors);
	array_init(return_value);

	for (i = 0; i < colors; i++) {
		if (wand_array[i]) {
#ifdef ZEND_ENGINE_3
			object_init_ex(&tmp_pixelwand, php_imagickpixel_sc_entry);
			internp = Z_IMAGICKPIXEL_P(&tmp_pixelwand);
			php_imagick_replace_pixelwand(internp, wand_array[i]);
			add_next_index_zval(return_value, &tmp_pixelwand);
#else
			MAKE_STD_ZVAL(tmp_pixelwand);
			object_init_ex(tmp_pixelwand, php_imagickpixel_sc_entry);
			internp = (php_imagickpixel_object *)zend_object_store_get_object(tmp_pixelwand TSRMLS_CC);
			php_imagick_replace_pixelwand(internp, wand_array[i]);
			add_next_index_zval(return_value, tmp_pixelwand);
#endif
		}
	}

	IMAGICK_FREE_MAGICK_MEMORY(wand_array);
	return;
}
/* }}} */

/* {{{ proto int Imagick::getImageInterlaceScheme()
	Gets the image interlace scheme.
*/
PHP_METHOD(Imagick, getImageInterlaceScheme)
{
	php_imagick_object *intern;
	long interlace;

	IMAGICK_METHOD_DEPRECATED ("Imagick", "getImageInterlaceScheme");

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	interlace = MagickGetImageInterlaceScheme(intern->magick_wand);
	RETVAL_LONG(interlace);
}
/* }}} */

/* {{{ proto int Imagick::getImageIterations()
	Gets the image iterations.
*/
PHP_METHOD(Imagick, getImageIterations)
{
	php_imagick_object *intern;
	long iterations;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	iterations = MagickGetImageIterations(intern->magick_wand);
	RETVAL_LONG(iterations);
}
/* }}} */

#if MagickLibVersion < 0x700
/* {{{ proto ImagickPixel Imagick::getImageMatteColor()
	Returns the image matte color.
*/
PHP_METHOD(Imagick, getImageMatteColor)
{
	php_imagick_object *intern;
	php_imagickpixel_object *internp;
	MagickBooleanType status;
	PixelWand *tmp_wand;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	tmp_wand = NewPixelWand();
	status = MagickGetImageMatteColor(intern->magick_wand, tmp_wand);

	if (tmp_wand == (PixelWand *)NULL) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to get image matte color" TSRMLS_CC);
		return;
	}

	if (status == MagickFalse) {
		tmp_wand = DestroyPixelWand(tmp_wand);
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable get image matter color" TSRMLS_CC);
		return;
	}

	object_init_ex(return_value, php_imagickpixel_sc_entry);
	internp = Z_IMAGICKPIXEL_P(return_value);
	php_imagick_replace_pixelwand(internp, tmp_wand);

	return;
}
/* }}} */
#endif //#if MagickLibVersion < 0x700

/* {{{ proto array Imagick::getImagePage()
	Returns the page geometry associated with the image in an array with the keys "width", "height", "x", and "y".
*/
PHP_METHOD(Imagick, getImagePage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	size_t width, height;
	ssize_t x, y;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickGetImagePage(intern->magick_wand, &width, &height, &x, &y);

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to get image page" TSRMLS_CC);
		return;
	}

	array_init(return_value);

	add_assoc_long(return_value, "width", width);
	add_assoc_long(return_value, "height", height);
	add_assoc_long(return_value, "x", x);
	add_assoc_long(return_value, "y", y);

	return;
}
/* }}} */

/* {{{ proto ImagickPixel Imagick::getImagePixelColor(int x, int y)
	Returns the color of the specified pixel.
*/
PHP_METHOD(Imagick, getImagePixelColor)
{
	php_imagick_object *intern;
	php_imagickpixel_object *internp;
	MagickBooleanType status;
	PixelWand *tmp_wand;
	im_long x, y;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll", &x, &y) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	tmp_wand = NewPixelWand();

	if (!tmp_wand) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Failed to allocate new PixelWand" TSRMLS_CC);
		return;
	}

	status = MagickGetImagePixelColor(intern->magick_wand, x, y , tmp_wand);

	if (status == MagickFalse) {
		tmp_wand = DestroyPixelWand(tmp_wand);
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable get image pixel color" TSRMLS_CC);
		return;
	}

	object_init_ex(return_value, php_imagickpixel_sc_entry);
	internp = Z_IMAGICKPIXEL_P(return_value);
	php_imagick_replace_pixelwand(internp, tmp_wand);

	return;
}
/* }}} */


/* {{{ proto ImagickPixel Imagick::getImagePixelColor(int x, int y)
	Returns the color of the specified pixel.
*/
PHP_METHOD(Imagick, setImagePixelColor)
{
	php_imagick_object *intern;
	zval *param;
	MagickBooleanType status;
	im_long x, y;
	PixelWand *color_wand;
	zend_bool allocated;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "llz", &x, &y, &param) == FAILURE) {
		return;
	}

	color_wand = php_imagick_zval_to_pixelwand (param, IMAGICK_CLASS, &allocated TSRMLS_CC);
	if (!color_wand)
		return;

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSetImagePixelColor(intern->magick_wand, x, y , color_wand);

	if (allocated)
		color_wand = DestroyPixelWand (color_wand);

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image pixel color" TSRMLS_CC);
		return;
	}

	return;
}
/* }}} */


/* {{{ proto string Imagick::getImageProfile(string name)
	Returns the named image profile.
*/
PHP_METHOD(Imagick, getImageProfile)
{
	php_imagick_object *intern;
	char *profile, *name;
	IM_LEN_TYPE name_len;
#if MagickLibVersion < 0x628
	long length;
#else
	size_t length;
#endif

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &name, &name_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	profile = (char *)MagickGetImageProfile(intern->magick_wand, name, &length);

	if (profile) {
		IM_ZVAL_STRINGL(return_value, profile, length);
		IMAGICK_FREE_MAGICK_MEMORY(profile);
		return;
	}

	php_imagick_throw_exception(IMAGICK_CLASS, "Can not get image profile" TSRMLS_CC);
	return;
}
/* }}} */

/* {{{ proto array Imagick::getImageRedPrimary()
	Returns the chromaticy red primary point as an array. IM6: with the keys "x" and "y".
	IM7: Returns an array with the keys "x", "y" and "z".
*/
PHP_METHOD(Imagick, getImageRedPrimary)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	double x, y;
#if MagickLibVersion >= 0x700
	double z;
#endif

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

#if MagickLibVersion >= 0x700
	status = MagickGetImageRedPrimary(intern->magick_wand, &x, &y, &z);
#else
	status = MagickGetImageRedPrimary(intern->magick_wand, &x, &y);
#endif

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to get image red primary" TSRMLS_CC);
		return;
	}

	array_init(return_value);
	add_assoc_double(return_value, "x", x);
	add_assoc_double(return_value, "y", y);
#if MagickLibVersion >= 0x700
	add_assoc_double(return_value, "z", z);
#endif

	return;
}
/* }}} */

/* {{{ proto int Imagick::getImageRenderingIntent()
	Gets the image rendering intent.
*/
PHP_METHOD(Imagick, getImageRenderingIntent)
{
	php_imagick_object *intern;
	long renderingIntent;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	renderingIntent = MagickGetImageRenderingIntent(intern->magick_wand);
	RETVAL_LONG(renderingIntent);
}
/* }}} */

/* {{{ proto array Imagick::getImageResolution()
	Gets the image X and Y resolution.
*/
PHP_METHOD(Imagick, getImageResolution)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	double x, y;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickGetImageResolution(intern->magick_wand, &x, &y);

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to get image resolution" TSRMLS_CC);
		return;
	}

	array_init(return_value);
	add_assoc_double(return_value, "x", x);
	add_assoc_double(return_value, "y", y);

	return;
}
/* }}} */

/* {{{ proto int Imagick::getImageScene()
	Gets the image scene.
*/
PHP_METHOD(Imagick, getImageScene)
{
	php_imagick_object *intern;
	unsigned long scene;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	scene = MagickGetImageScene(intern->magick_wand);
	RETVAL_LONG(scene);
}
/* }}} */

/* {{{ proto string Imagick::getImageSignature()
	Generates an SHA-256 message digest for the image pixel stream.
*/
PHP_METHOD(Imagick, getImageSignature)
{
	php_imagick_object *intern;
	char *signature;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	signature = MagickGetImageSignature(intern->magick_wand);
	IM_ZVAL_STRING(return_value, signature);
	IMAGICK_FREE_MAGICK_MEMORY(signature);
	return;
}
/* }}} */

/* {{{ proto int Imagick::getImageTicksPerSecond()
	Gets the image ticks-per-second.
*/
PHP_METHOD(Imagick, getImageTicksPerSecond)
{
	php_imagick_object *intern;
	unsigned long ticks;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	ticks = MagickGetImageTicksPerSecond(intern->magick_wand);
	RETVAL_LONG(ticks);
}
/* }}} */

/* {{{ proto int Imagick::getImageType()
	Gets the potential image type:
*/
PHP_METHOD(Imagick, getImageType)
{
	php_imagick_object *intern;
	long imageType;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	imageType = MagickGetImageType(intern->magick_wand);
	RETVAL_LONG(imageType);
}
/* }}} */

/* {{{ proto int Imagick::getImageUnits()
	Gets the image units of resolution.
*/
PHP_METHOD(Imagick, getImageUnits)
{
	php_imagick_object *intern;
	long resolutionType;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	resolutionType = MagickGetImageUnits(intern->magick_wand);
	RETVAL_LONG(resolutionType);
}
/* }}} */

/* {{{ proto int Imagick::getImageVirtualPixelMethod()
	Returns the virtual pixel method for the sepcified image.
*/
PHP_METHOD(Imagick, getImageVirtualPixelMethod)
{
	php_imagick_object *intern;
	long pixelMethod;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	pixelMethod = MagickGetImageVirtualPixelMethod(intern->magick_wand);
	RETVAL_LONG(pixelMethod);
}
/* }}} */

/* {{{ proto array Imagick::getImageWhitePoint()
	Returns the chromaticy white point as an associative array. IM6: with the keys "x" and "y".
	IM7: with the keys "x", "y" and "z".
*/
PHP_METHOD(Imagick, getImageWhitePoint)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	double x, y;
#if MagickLibVersion >= 0x700
	double z;
#endif

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

#if MagickLibVersion >= 0x700
	status = MagickGetImageWhitePoint(intern->magick_wand, &x, &y, &z);
#else
	status = MagickGetImageWhitePoint(intern->magick_wand, &x, &y);
#endif

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to get image white point" TSRMLS_CC);
		return;
	}

	array_init(return_value);
	add_assoc_double(return_value, "x", x);
	add_assoc_double(return_value, "y", y);
#if MagickLibVersion >= 0x700
	add_assoc_double(return_value, "z", z);
#endif

	return;
}
/* }}} */

/* {{{ proto int Imagick::getImageWidth()
	Returns the image width.
*/
PHP_METHOD(Imagick, getImageWidth)
{
	php_imagick_object *intern;
	unsigned long width;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	width = MagickGetImageWidth(intern->magick_wand);
	RETVAL_LONG(width);
}
/* }}} */

/* {{{ proto int Imagick::getNumberImages()
	Returns the number of images associated with Imagick object.
*/
PHP_METHOD(Imagick, getNumberImages)
{
	php_imagick_object *intern;
	unsigned long num_images;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	num_images = MagickGetNumberImages(intern->magick_wand);
	RETVAL_LONG(num_images);
}
/* }}} */

/*
	Resizes an image so that it is 'bestfit' for the bounding box
	If the image does not fill the box completely the box is filled with
	image's background color. The background color can be set using MagickSetImageBackgroundColor
*/
#if MagickLibVersion > 0x631
static
zend_bool s_resize_bounding_box(MagickWand *magick_wand, im_long box_width, im_long box_height, zend_bool fill, zend_bool legacy)
{
	im_long new_width, new_height;
	im_long extent_x, extent_y;

	/* Calculate dimensions */
	if (!php_imagick_thumbnail_dimensions(magick_wand, 1, box_width, box_height, &new_width, &new_height, legacy)) {
		return 0;
	}

	/* Resize the image to the new size */
	if (MagickThumbnailImage(magick_wand, new_width, new_height) == MagickFalse) {
		return 0;
	}

	/* If user does not want to fill we are all done here */
	if (!fill) {
		return 1;
	}

	/* In case user wants to fill use extent for it rather than creating a new canvas */
	extent_x = (box_width > new_width)   ? ((box_width - new_width) / 2)   : 0;
	extent_y = (box_height > new_height) ? ((box_height - new_height) / 2) : 0;

	if (MagickExtentImage(magick_wand, box_width, box_height, extent_x * -1, extent_y * -1) == MagickFalse) {
		return 0;
	}
	return 1;
}
#endif

/* {{{ proto bool Imagick::thumbnailImage(int columns, int rows[, bool bestfit = false[, bool fill = false[, bool legacy = false]]])
	Changes the size of an image to the given dimensions and removes any associated profiles.
	If legacy is true, the calculations are done with the small rounding bug that existed in
	Imagick before 3.4.0. If false, the calculations should produce the same results as 
	ImageMagick CLI does.
*/
PHP_METHOD(Imagick, thumbnailImage)
{
	im_long width, height, new_width, new_height;
	php_imagick_object *intern;
	zend_bool bestfit = 0, fill = 0;
	zend_bool legacy = 0;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll|bbb", &width, &height, &bestfit, &fill, &legacy) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	if (bestfit && fill) {
#if MagickLibVersion > 0x631
		if (!s_resize_bounding_box(intern->magick_wand, width, height, fill, legacy)) {
			php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to resize and fill image" TSRMLS_CC);
		return;
		}
#else 
		php_imagick_throw_exception(IMAGICK_CLASS, "Fill parameter is only supported with ImageMagick 6.3.2+" TSRMLS_CC);
		return;
#endif
	} else {
		if (!php_imagick_thumbnail_dimensions(intern->magick_wand, bestfit, width, height, &new_width, &new_height, legacy)) {
			php_imagick_throw_exception(IMAGICK_CLASS, "Invalid image geometry" TSRMLS_CC);
			return;
		}
		/* No magick is going to happen */
		if (MagickThumbnailImage(intern->magick_wand, new_width, new_height) == MagickFalse) {
			php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to thumbnail image" TSRMLS_CC);
		return;
		}
	}
	RETURN_TRUE;
}
/* }}} */

/* This is not universally safe to use, but is safe enough for values that will 
   be encountered for image dimensions.
*/
static inline double im_round_helper_class(double value) {
	if (value >= 0.0) {
		return floor(value + 0.5);
	} else {
		return ceil(value - 0.5);
	}
}

static
void s_calculate_crop(
	im_long orig_width, im_long orig_height,
	im_long desired_width, im_long desired_height,
	im_long *new_width, im_long *new_height,
	im_long *offset_x, im_long *offset_y,
	zend_bool legacy
) {
	double ratio_x, ratio_y;
	long temp_new_width, temp_new_height;

	ratio_x = ((double) desired_width / (double) orig_width);
	ratio_y = ((double) desired_height / (double) orig_height);

	if (ratio_x > ratio_y) {
		temp_new_width  = desired_width;

		if (legacy) {
			temp_new_height = (long)(ratio_x * (double)orig_height);
		}
		else {
			temp_new_height = im_round_helper_class(ratio_x * (double)orig_height);
		}
	} else {
		temp_new_height = desired_height;
		if (legacy) {
			temp_new_width  = (long)(ratio_y * (double)orig_width);
		}
		else {
			temp_new_width  = im_round_helper_class(ratio_y * (double)orig_width);
		}
	}

	*new_width = temp_new_width;
	*new_height = temp_new_height;

	*offset_x = (long) ((temp_new_width - desired_width) / 2);
	*offset_y = (long) ((temp_new_height - desired_height) / 2);
}


/* {{{ proto array Imagick::calculateCrop(long orig_width, long orig_height, long desired_width, long desired_height[, bool legacy = false])
	Calculates the cropping values that will be used by a crop operation.
*/
PHP_METHOD(Imagick, calculateCrop)
{
	im_long orig_width, orig_height;
	im_long desired_width, desired_height;
	im_long new_width, new_height;
	im_long offset_x, offset_y;
	zend_bool legacy = 0;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "llll|b", 
		&orig_width, &orig_height, &desired_width, &desired_height, &legacy) == FAILURE) {
		return;
	}

	if (orig_width <= 0 || orig_height <= 0 ||
		desired_width <= 0 || desired_height <= 0) {
		php_imagick_throw_exception(IMAGICK_CLASS, "All values must be above zero." TSRMLS_CC);
	}

	s_calculate_crop(
		orig_width, orig_height,
		desired_width, desired_height,
		&new_width, &new_height,
		&offset_x, &offset_y,
		legacy
	);

	array_init(return_value);
	add_assoc_long(return_value, "width", new_width);
	add_assoc_long(return_value, "height", new_height);

	add_assoc_long(return_value, "offset_x", offset_x);
	add_assoc_long(return_value, "offset_y", offset_y);

	return;
}
/* }}} */


static
zend_bool s_crop_thumbnail_image(MagickWand *magick_wand, im_long desired_width, im_long desired_height, zend_bool legacy TSRMLS_DC)
{
	im_long offset_x = 0, offset_y = 0, new_width, new_height;
	im_long orig_width  = (im_long)MagickGetImageWidth(magick_wand);
	im_long orig_height = (im_long)MagickGetImageHeight(magick_wand);

	/* Already at the size, just strip profiles */
	if ((orig_width == desired_width) && (orig_height == desired_height)) {
		if (!MagickStripImage(magick_wand)) {
			return 0;
		}
		return 1;
	}

	s_calculate_crop(
		orig_width, orig_height,
		desired_width, desired_height,
		&new_width, &new_height,
		&offset_x, &offset_y,
		legacy
	);

	if (MagickThumbnailImage(magick_wand, new_width, new_height) == MagickFalse) {
		return 0;
	}

	/* all done here */
	if ((new_width == desired_width) && (new_height == desired_height)) {
		return 1;
	}

	if (MagickCropImage(magick_wand, desired_width, desired_height, offset_x, offset_y) == MagickFalse) {
		return 0;
	}

	MagickSetImagePage(magick_wand, desired_width, desired_height, 0, 0);
	return 1;
}

// 
/* {{{ proto bool Imagick::cropthumbnailImage(int columns, int rows[, bool legacy = false] )
	Creates a cropped thumbnail at the requested size. If legacy is true, uses the 
	incorrect behaviour that was present until Imagick 3.4.0. If false it uses the correct
	behaviour.
*/
PHP_METHOD(Imagick, cropThumbnailImage)
{
	im_long crop_width, crop_height;
	zend_bool legacy = 0;
	php_imagick_object *intern;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll|b", &crop_width, &crop_height, &legacy) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	/* The world collapses.. */
	if (!s_crop_thumbnail_image(intern->magick_wand, crop_width, crop_height, legacy TSRMLS_CC)) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to crop-thumbnail image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::resetIterator();
	Resets the iterator.  Use it in conjunction with Imagick::nextImage() to iterate over all the images in a wand container.
*/
PHP_METHOD(Imagick, resetIterator)
{
	php_imagick_object *intern;
	intern = Z_IMAGICK_P(getThis());

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	/* No magick is going to happen */
	if (intern->magick_wand == NULL) {
		RETURN_FALSE;
	}
	intern->next_out_of_bound = 0;
	MagickResetIterator(intern->magick_wand);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::setFirstIterator()
	Sets the wand iterator to the first image.
*/
PHP_METHOD(Imagick, setFirstIterator)
{
	php_imagick_object *intern;
	intern = Z_IMAGICK_P(getThis());

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	/* No magick is going to happen */
	if (intern->magick_wand == NULL) {
		RETURN_FALSE;
	}
	intern->next_out_of_bound = 0;
	MagickSetFirstIterator(intern->magick_wand);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::setLastIterator()
	Sets the wand iterator to the last image.
*/
PHP_METHOD(Imagick, setLastIterator)
{
	php_imagick_object *intern;
	intern = Z_IMAGICK_P(getThis());

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	/* No magick is going to happen */
	if (intern->magick_wand == NULL) {
		RETURN_FALSE;
	}
	intern->next_out_of_bound = 0;
	MagickSetLastIterator(intern->magick_wand);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::previousImage()
	Assocates the previous image in an image list with the Imagick object.
*/
PHP_METHOD(Imagick, previousImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	status = MagickPreviousImage(intern->magick_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		RETURN_FALSE;
	}
	intern->next_out_of_bound = 0;
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::nextImage()
	Associates the next image in the image list with an Imagick object.
*/
PHP_METHOD(Imagick, nextImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	status = MagickNextImage(intern->magick_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		intern->next_out_of_bound = 1;
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::hasPreviousImage()
	Returns true if the wand has more images when traversing the list in the reverse direction
*/
PHP_METHOD(Imagick, hasPreviousImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	status = MagickHasPreviousImage(intern->magick_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::hasNextImage()
	Returns true if the wand has more images when traversing the list in the forward direction
*/
PHP_METHOD(Imagick, hasNextImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	status = MagickHasNextImage(intern->magick_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
/* {{{ proto int Imagick::getImageIndex()
	Returns the index of the current active image, within the Imagick object.
*/
PHP_METHOD(Imagick, getImageIndex)
{
	MagickBooleanType status;
	php_imagick_object *intern;

#if MagickLibVersion > 0x628
	IMAGICK_METHOD_DEPRECATED("Imagick", "getImageindex");
#endif

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	status = MagickGetImageIndex(intern->magick_wand);
	ZVAL_LONG(return_value, (long)status);
	return;
}
/* }}} */
#endif // #if MagickLibVersion < 0x700


#if MagickLibVersion < 0x700

/* {{{ proto bool Imagick::setImageIndex(int index)
	Returns the index of the current active image, within the Imagick object.
*/
PHP_METHOD(Imagick, setImageIndex)
{
	im_long index;
	MagickBooleanType status;
	php_imagick_object *intern;

#if MagickLibVersion > 0x628
	IMAGICK_METHOD_DEPRECATED("Imagick", "setImageIndex");
#endif

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &index) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
#if MagickLibVersion > 0x628
	/* Get the current iterator position */
	status = MagickSetIteratorIndex(intern->magick_wand, index);
#else
	status = MagickSetImageIndex(intern->magick_wand, index);
#endif

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image index" TSRMLS_CC);
		return;
	}
	intern->next_out_of_bound = 0;
	RETURN_TRUE;

}
/* }}} */
#endif // #if MagickLibVersion < 0x700
#endif

/* {{{ proto bool Imagick::removeImage()
	Removes an image from the image list.
*/
PHP_METHOD(Imagick, removeImage)
{
	MagickBooleanType status;
	php_imagick_object *intern;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickRemoveImage(intern->magick_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to remove image" TSRMLS_CC);
		return;
	}
	intern->next_out_of_bound = 0;
	MagickSetLastIterator(intern->magick_wand);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto string Imagick::getImageFilename()
	Returns the filename of a particular image in a sequence
*/
PHP_METHOD(Imagick, getImageFilename)
{
	php_imagick_object *intern;
	char *filename;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	filename = MagickGetImageFilename(intern->magick_wand);

	if (filename == (char *)NULL) {
		return;
	}

	IM_ZVAL_STRING(return_value, filename);
	IMAGICK_FREE_MAGICK_MEMORY(filename);
	return;
}
/* }}} */

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
/* {{{ proto int Imagick::getImageSize()
	returns the image length in bytes
*/
PHP_METHOD(Imagick, getImageSize)
{
	php_imagick_object *intern;

	IMAGICK_METHOD_DEPRECATED_USE_INSTEAD("Imagick", "getImageSize", "Imagick", "getImageLength");

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	ZVAL_LONG(return_value, (long)MagickGetImageSize(intern->magick_wand));
	return;
}
/* }}} */
#endif
#endif

static
zend_bool s_image_has_format (MagickWand *magick_wand)
{
	char *buffer;
	zend_bool ret;
	buffer = MagickGetImageFormat(magick_wand);
	ret = buffer && *buffer != '\0';
	if (buffer) {
		MagickRelinquishMemory (buffer);
	}
	return ret;
}

/* {{{ proto string Imagick::getImageBlob()
	Returns the current image sequence as a string
*/
PHP_METHOD(Imagick, getImageBlob)
{
	php_imagick_object *intern;
	unsigned char *image_contents;
	size_t image_size;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	if (!s_image_has_format (intern->magick_wand)) {
		php_imagick_throw_exception(IMAGICK_CLASS, "Image has no format" TSRMLS_CC);
		return;
	}

	image_contents = MagickGetImageBlob(intern->magick_wand, &image_size);
	if (!image_contents) {
		return;
	}

	IM_ZVAL_STRINGL(return_value, (char *)image_contents, image_size);
	IMAGICK_FREE_MAGICK_MEMORY(image_contents);
	return;
}
/* }}} */

/* {{{ proto string Imagick::getImagesBlob()
	Returns all image sequences as a string
*/
PHP_METHOD(Imagick, getImagesBlob)
{
	php_imagick_object *intern;
	unsigned char *image_contents;
	size_t image_size;
	int current;
	MagickBooleanType status;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

#if MagickLibVersion > 0x628
	/* Get the current iterator position */
	current = MagickGetIteratorIndex(intern->magick_wand);
#else
	/* Get the current iterator position */
	current = MagickGetImageIndex(intern->magick_wand);
#endif

	/* Reset the iterator */
	MagickResetIterator(intern->magick_wand);

	/* Loop all images to make sure they have a format */
	while (MagickNextImage(intern->magick_wand)) {
		if (!s_image_has_format (intern->magick_wand)) {
			php_imagick_throw_exception(IMAGICK_CLASS, "Image has no format" TSRMLS_CC);
			return;
		}
	}

#if MagickLibVersion > 0x628
	/* Get the current iterator position */
	status = MagickSetIteratorIndex(intern->magick_wand, current);
#else
	/* Get the current iterator position */
	status = MagickSetImageIndex(intern->magick_wand, current);
#endif

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set the iterator index" TSRMLS_CC);
		return;
	}

	image_contents = MagickGetImagesBlob(intern->magick_wand, &image_size);
	if (!image_contents) {
		return;
	}

	IM_ZVAL_STRINGL(return_value, (char *)image_contents, image_size);
	IMAGICK_FREE_MAGICK_MEMORY(image_contents);
	return;
}
/* }}} */

/* {{{ proto string Imagick::getImageFormat()
	Returns the format of a particular image in a sequence.
*/
PHP_METHOD(Imagick, getImageFormat)
{
	php_imagick_object *intern;
	char *format;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	intern = Z_IMAGICK_P(getThis());

	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;
	if (!s_image_has_format (intern->magick_wand)) {
		php_imagick_throw_exception(IMAGICK_CLASS, "Image has no format" TSRMLS_CC);
		return;
	}

	format = MagickGetImageFormat (intern->magick_wand);
	IM_ZVAL_STRING(return_value, format);
	IMAGICK_FREE_MAGICK_MEMORY(format);
	return;
}
/* }}} */

/* {{{ proto string Imagick::getImageMimeType()
	Returns the image mime-type
*/
PHP_METHOD(Imagick, getImageMimeType)
{
	php_imagick_object *intern;
	char *format = NULL, *mime_type = NULL;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;
	if (!s_image_has_format (intern->magick_wand)) {
		php_imagick_throw_exception(IMAGICK_CLASS, "Image has no format" TSRMLS_CC);
		return;
	}

	format = MagickGetImageFormat (intern->magick_wand);

	mime_type = (char *) MagickToMime(format);
	IMAGICK_FREE_MAGICK_MEMORY(format);

	if (!mime_type) {
		php_imagick_throw_exception(IMAGICK_CLASS, "Unable to get image mime-type" TSRMLS_CC);
		return;
	}

	IM_ZVAL_STRING(return_value, mime_type);
	IMAGICK_FREE_MAGICK_MEMORY(mime_type);
	return;
}
/* }}} */


static
void s_add_assoc_str (zval *array, const char *key, const char *value)
{
    //add_assoc_string (array, key, (char *)(value ? value : ""), copy);
    IM_add_assoc_string (array, key, (char *)(value ? value : ""));
    //TODO - if copy == 0 free the string?
}

static
void s_add_named_strings (zval *array, const char *haystack TSRMLS_DC)
{
	unsigned int i, found;
	char *last_ptr = NULL, *buffer;
	size_t num_keys;

#ifdef ZEND_ENGINE_3
	zend_string    *trim;
	zend_string    *line_string;
#else
	char *trim;
#endif

	char *line;

	const char *str_keys [] = {
		"Format: ",
		"Units: ",
		"Type: ",
		"Colorspace: ",
		"Filesize: ",
		"Compression: "
	};

	const char *arr_keys [] = {
		"format",
		"units",
		"type",
		"colorSpace",
		"fileSize",
		"compression"
	};

	found = 0;


	buffer = estrdup (haystack);

	num_keys = sizeof (str_keys) / sizeof (str_keys[0]);
	line = php_strtok_r (buffer, "\r\n", &last_ptr);

	while ((found < num_keys) && line) {
		// Break the line further into tokens

#ifdef ZEND_ENGINE_3
		line_string = zend_string_init(line, strlen(line), 0);
		//str, what, what_len, mode
		trim = php_trim(line_string, NULL, 0, 3);
		for (i = 0; i < num_keys; i++) {
			if (trim->val) {
				if (strncmp (trim->val, str_keys [i], strlen (str_keys [i])) == 0) {
					// This should be our line
					IM_add_assoc_string (array, arr_keys [i], trim->val + strlen (str_keys [i]));
					found++;
				}
			}
		}
		// zend_string_release(line_string); - 0 in zend_string_init means no need to free?
		zend_string_release(trim);
		line = php_strtok_r (NULL, "\r\n", &last_ptr);
#else
		trim = php_trim(line, strlen(line), NULL, 0, NULL, 3 TSRMLS_CC);
		for (i = 0; i < num_keys; i++) {
			if (strncmp (trim, str_keys [i], strlen (str_keys [i])) == 0) {
				// This should be our line
				IM_add_assoc_string (array, arr_keys [i], trim + strlen (str_keys [i]));
				found++;
			}
		}
		efree (trim);
		line = php_strtok_r (NULL, "\r\n", &last_ptr);
#endif
	}
	efree (buffer);
}

/* {{{ proto array Imagick::identifyImage([bool appendRawOutput] )
	Identifies an image and returns the attributes.  Attributes include the image width, height, size, and others.
	If true is passed as argument, then the raw output is appended to the array.
*/
PHP_METHOD(Imagick, identifyImage)
{
	char *format, *identify, *filename, *signature;
	php_imagick_object *intern;
	zend_bool append_raw_string = 0;
	double x, y;

#ifdef ZEND_ENGINE_3
	zval array;
#else
	zval *array;
#endif
    
    zval *pArray;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|b", &append_raw_string) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	// This is to parse some string options, ugly hack but easier than using CommandOptionToMNemonic
	// or MagickOptionToMnemonic and FormatMagickSize, which have changed names and signatures between
	// versions that we support
	identify = MagickIdentifyImage (intern->magick_wand);

	// Actually generate the array ourselves
	array_init(return_value);

    // Name of the image
	filename = MagickGetImageFilename (intern->magick_wand);
	s_add_assoc_str (return_value, "imageName", filename);
	IMAGICK_FREE_MAGICK_MEMORY(filename);

	format = MagickGetImageFormat (intern->magick_wand);
	if (format) {
		char *mime_type = MagickToMime(format);
		if (mime_type) {
			s_add_assoc_str (return_value, "mimetype", mime_type);
			IMAGICK_FREE_MAGICK_MEMORY(mime_type);
		} else
			s_add_assoc_str (return_value, "mimetype", "unknown");

		IMAGICK_FREE_MAGICK_MEMORY(format);
	}
	else
		s_add_assoc_str (return_value, "mimetype", "unknown");

	s_add_named_strings (return_value, identify TSRMLS_CC);

	// Geometry is an associative array
	
#ifdef ZEND_ENGINE_3
	ZVAL_NEW_ARR(&array);
	pArray = &array;
#else
	MAKE_STD_ZVAL(array);
	pArray = array;
#endif

	array_init(pArray);

	add_assoc_long (pArray, "width", MagickGetImageWidth (intern->magick_wand));
	add_assoc_long (pArray, "height", MagickGetImageHeight (intern->magick_wand));
	add_assoc_zval (return_value, "geometry", pArray);

	if (MagickGetImageResolution(intern->magick_wand, &x, &y) == MagickTrue) {
#ifdef ZEND_ENGINE_3
		zval geometry_array;
		array_init(&geometry_array);
		add_assoc_double(&geometry_array, "x", x);
		add_assoc_double(&geometry_array, "y", y);
		add_assoc_zval(return_value, "resolution", &geometry_array);
#else
		zval *p_geometry_array;
		MAKE_STD_ZVAL(p_geometry_array);
		array_init(p_geometry_array);
		add_assoc_double(p_geometry_array, "x", x);
		add_assoc_double(p_geometry_array, "y", y);
		add_assoc_zval(return_value, "resolution", p_geometry_array);
#endif
	}

	signature = MagickGetImageSignature(intern->magick_wand);
	s_add_assoc_str (return_value, "signature", signature);
	IMAGICK_FREE_MAGICK_MEMORY(signature);

	if (append_raw_string == 1)
		IM_add_assoc_string (return_value, "rawOutput", identify);

	IMAGICK_FREE_MAGICK_MEMORY(identify);
	return;
}
/* }}} */

#undef imagick_option_to_string

/* {{{ proto int Imagick::getImageColors()
	Gets the number of unique colors in the image.
*/
PHP_METHOD(Imagick, getImageColors)
{
	php_imagick_object *intern;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	ZVAL_LONG(return_value, (long)MagickGetImageColors(intern->magick_wand));
	return;
}
/* }}} */

/* {{{ proto bool Imagick::commentImage(string comment)
	Adds a comment to your image.
*/
PHP_METHOD(Imagick, commentImage)
{
	php_imagick_object *intern;
	char *comment;
	IM_LEN_TYPE comment_len;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &comment, &comment_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickCommentImage(intern->magick_wand, comment);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to comment image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::setImageFilename(string filename)
	Sets the filename of a particular image in a sequence.
*/
PHP_METHOD(Imagick, setImageFilename)
{
	php_imagick_object *intern;
	char *filename;
	IM_LEN_TYPE filename_len;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &filename, &filename_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSetImageFilename(intern->magick_wand, filename);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image filename" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
/* PS, DEPRECATED please remove: http://www.imagemagick.org/discourse-server/viewtopic.php?f=6&t=8196 */
PHP_METHOD(Imagick, setImageAttribute)
{
	php_imagick_object *intern;
	char *key, *attribute;
	IM_LEN_TYPE key_len, attribute_len;
	MagickBooleanType status;

	/* Tell user that this method has been deprecated. */
	IMAGICK_METHOD_DEPRECATED("Imagick", "setImageAttribute");

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss", &key, &key_len, &attribute, &attribute_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSetImageAttribute(intern->magick_wand, key, attribute);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image attribute" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
#endif // #if MagickLibVersion < 0x700
#endif

/* {{{ proto bool Imagick::setImageBackgroundColor(ImagickPixel background)
	Sets the image background color.
*/
PHP_METHOD(Imagick, setImageBackgroundColor)
{
	zval *param;
	php_imagick_object *intern;
	MagickBooleanType status;
	PixelWand *color_wand;
	zend_bool allocated;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &param) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	color_wand = php_imagick_zval_to_pixelwand (param, IMAGICK_CLASS, &allocated TSRMLS_CC);
	if (!color_wand)
		return;

	status = MagickSetImageBackgroundColor(intern->magick_wand, color_wand);

	if (allocated)
		color_wand = DestroyPixelWand (color_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image background color" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

#if MagickLibVersion >= 0x700
/* {{{ proto int Imagick::setImageChannelMask(int channel)
	Sets the image channel mask. Returns the previous set channel mask.
*/
PHP_METHOD(Imagick, setImageChannelMask)
{
	php_imagick_object *intern;
	im_long channel;
	ChannelType previous_channel_type;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	previous_channel_type = MagickSetImageChannelMask(intern->magick_wand, channel);

	RETURN_LONG(previous_channel_type);
}
/* }}} */
#endif


/* {{{ proto bool Imagick::setImageCompose(int compose)
	Sets the image composite operator, useful for specifying how to composite the image thumbnail when using the Imagick::montageImage() method.
*/
PHP_METHOD(Imagick, setImageCompose)
{
	php_imagick_object *intern;
	im_long compose;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &compose) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSetImageCompose(intern->magick_wand, compose);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image composite operator" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto int Imagick::getImageCompression()
        Gets the image compression type
*/
PHP_METHOD(Imagick, getImageCompression)
{
	php_imagick_object *intern;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	RETVAL_LONG(MagickGetImageCompression(intern->magick_wand));
}
/* }}} */

/* {{{ proto bool Imagick::setImageCompression(int compression)
	Sets the image compression.
*/
PHP_METHOD(Imagick, setImageCompression)
{
	php_imagick_object *intern;
	im_long compression;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &compression) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSetImageCompression(intern->magick_wand, compression);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image compression" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::setImageDelay(int delay)
	Sets the image delay.
*/
PHP_METHOD(Imagick, setImageDelay)
{
	php_imagick_object *intern;
	im_long delay;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &delay) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSetImageDelay(intern->magick_wand, delay);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image delay" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::colorizeImage(ImagickPixel colorize, ImagickPixel opacity, bool legacy)
	Blends the fill color with each pixel in the image. The 'opacity' color is a 
	per channel strength factor for how strongly the color should be applied. If
	legacy is true, the behaviour of this function is incorrect, but consistent 
	with how it behaved before Imagick version 3.4.0
*/
PHP_METHOD(Imagick, colorizeImage)
{
	PixelWand *param_wand = NULL;
	php_imagick_object *intern;
	zval *color_param, *opacity_param;
	MagickBooleanType status;
	PixelWand *color_wand, *opacity_wand;
	zend_bool color_allocated, opacity_allocated;
	zend_bool legacy = 0;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|b", &color_param, &opacity_param, &legacy) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	color_wand = php_imagick_zval_to_pixelwand (color_param, IMAGICK_CLASS, &color_allocated TSRMLS_CC);
	if (!color_wand)
		return;

	if (legacy) {
		opacity_wand = php_imagick_zval_to_opacity (opacity_param, IMAGICK_CLASS, &opacity_allocated TSRMLS_CC);
	}
	else {
		opacity_wand = php_imagick_zval_to_pixelwand(opacity_param, IMAGICK_CLASS, &opacity_allocated TSRMLS_CC);
	}

	if (!opacity_wand) {
		if (color_allocated)
			color_wand = DestroyPixelWand (color_wand);

		return;
	}

	if (legacy) {
		/* Colorize wants both wands to be of same instance */
		param_wand = php_imagick_clone_pixelwand (color_wand);
		if (!param_wand) {
			php_imagick_throw_exception (IMAGICK_CLASS, "Failed to allocate" TSRMLS_CC);
			return;
		}
#if MagickLibVersion < 0x700
		PixelSetOpacity(param_wand, PixelGetOpacity(opacity_wand));
#endif
		PixelSetAlpha(param_wand, PixelGetAlpha(opacity_wand));
		status = MagickColorizeImage(intern->magick_wand, param_wand, param_wand);
		param_wand = DestroyPixelWand(param_wand);
	} else {
		status = MagickColorizeImage(intern->magick_wand, color_wand, opacity_wand);
	}

	if (color_allocated)
		color_wand = DestroyPixelWand (color_wand);

	if (opacity_allocated)
		opacity_wand = DestroyPixelWand (opacity_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to colorize image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto Imagick Imagick::compareImageChannels(Imagick reference, int channel, int metric)
	Compares one or more image channels of an image to a reconstructed image and returns the difference image.
*/
PHP_METHOD(Imagick, compareImageChannels)
{
	MagickWand *tmp_wand;
	zval *objvar;
	php_imagick_object *intern, *intern_second, *intern_return;
	im_long channel_type, metric_type;
	double distortion;
#ifdef ZEND_ENGINE_3
	zval new_wand;
#else
	zval *new_wand;
#endif

	zval *pNewWand;


	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "Oll", &objvar, php_imagick_sc_entry, &channel_type, &metric_type) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	intern_second = Z_IMAGICK_P(objvar);
	if (php_imagick_ensure_not_empty (intern_second->magick_wand) == 0)
		return;

	tmp_wand = MagickCompareImageChannels(intern->magick_wand, intern_second->magick_wand, channel_type, metric_type, &distortion);

	if (!tmp_wand) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Compare image channels failed" TSRMLS_CC);
		return;
	}

#ifdef ZEND_ENGINE_3
	pNewWand = &new_wand;
#else
	MAKE_STD_ZVAL(new_wand);
	pNewWand = new_wand;
#endif
	array_init(return_value);

	object_init_ex(pNewWand, php_imagick_sc_entry);
	intern_return = Z_IMAGICK_P(pNewWand);
	php_imagick_replace_magickwand(intern_return, tmp_wand);

	add_next_index_zval(return_value, pNewWand);
	add_next_index_double(return_value, distortion);

	return;
}
/* }}} */
#if MagickLibVersion > 0x628
/* {{{ proto Imagick Imagick::compareImageLayers(int method)
	Compares each image with the next in a sequence and returns the maximum bounding region of any pixel differences it discovers.
*/
PHP_METHOD(Imagick, compareImageLayers)
{
	MagickWand *tmp_wand;
	php_imagick_object *intern, *intern_return;
	im_long compare_method;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &compare_method) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

#if MagickLibVersion >= 0x700
	tmp_wand = (MagickWand *)MagickCompareImagesLayers(intern->magick_wand, compare_method);
#else
	tmp_wand = (MagickWand *)MagickCompareImageLayers(intern->magick_wand, compare_method);
#endif

	if (tmp_wand == NULL) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Compare image layers failed" TSRMLS_CC);
		return;
	}

	object_init_ex(return_value, php_imagick_sc_entry);
	intern_return = Z_IMAGICK_P(return_value);
	php_imagick_replace_magickwand(intern_return, tmp_wand);

	return;
}
/* }}} */
#endif

#if MagickLibVersion < 0x700
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
/* {{{ proto Imagick Imagick::flattenImages()
	Merges a sequence of images.  This is useful for combining Photoshop layers into a single image.
*/
PHP_METHOD(Imagick, flattenImages)
{
	php_imagick_object *intern, *intern_return;
	MagickWand *tmp_wand;

	IMAGICK_METHOD_DEPRECATED ("Imagick", "flattenImages");

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;


	/* TODO: SHOULD THIS BE HERE? */
	MagickSetFirstIterator(intern->magick_wand);

	tmp_wand = MagickFlattenImages(intern->magick_wand);

	if (tmp_wand == NULL) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Flatten images failed" TSRMLS_CC);
		return;
	}

	object_init_ex(return_value, php_imagick_sc_entry);
	intern_return = Z_IMAGICK_P(return_value);
	php_imagick_replace_magickwand(intern_return, tmp_wand);

	return;
}
/* }}} */
#endif
#endif

/* {{{ proto bool Imagick::flipImage()
	Creates a vertical mirror image by reflecting the pixels around the central x-axis.
*/
PHP_METHOD(Imagick, flipImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickFlipImage(intern->magick_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to flip image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::flopImage()
	Creates a horizontal mirror image by reflecting the pixels around the central y-axis.
*/
PHP_METHOD(Imagick, flopImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickFlopImage(intern->magick_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to flop image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::frameImage(ImagickPixel matte_color, int width, int height, int inner_bevel, int outer_bevel)
	Adds a simulated three-dimensional border around the image
*/
PHP_METHOD(Imagick, frameImage)
{
	zval *param;
	php_imagick_object *intern;
	MagickBooleanType status;
	im_long width, height, inner_bevel, outer_bevel;
	PixelWand *color_wand;
	zend_bool allocated;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zllll", &param, &width, &height, &inner_bevel, &outer_bevel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	color_wand = php_imagick_zval_to_pixelwand (param, IMAGICK_CLASS, &allocated TSRMLS_CC);
	if (!color_wand)
		return;

#if MagickLibVersion >= 0x700
	{
	//TODO - understand and allow compose to be set.
	CompositeOperator compose = AtopCompositeOp;
	status = MagickFrameImage(intern->magick_wand, color_wand, width, height, inner_bevel, outer_bevel, compose);
	}
#else
	status = MagickFrameImage(intern->magick_wand, color_wand, width, height, inner_bevel, outer_bevel);
#endif

	if (allocated)
		color_wand = DestroyPixelWand (color_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to frame image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto Imagick Imagick::fxImage(string expression[, int channel])
	Evaluate expression for each pixel in the image.
*/
PHP_METHOD(Imagick, fxImage)
{
	MagickWand *tmp_wand;
	php_imagick_object *intern, *intern_return;
	char *expression;
	IM_LEN_TYPE expression_len;
	im_long channel = IM_DEFAULT_CHANNEL;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|l", &expression, &expression_len, &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	tmp_wand = MagickFxImageChannel(intern->magick_wand, channel, expression);

	if (tmp_wand == NULL) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Fx image failed" TSRMLS_CC);
		return;
	}

	object_init_ex(return_value, php_imagick_sc_entry);
	intern_return = Z_IMAGICK_P(return_value);
	php_imagick_replace_magickwand(intern_return, tmp_wand);

	return;
}
/* }}} */

/* {{{ proto bool Imagick::gammaImage(float gamma[, int channel])
	Gamma-corrects an image.  The same image viewed on different devices will have perceptual differences in the way the image's intensities are represented on the screen.  Specify individual gamma levels for the red, green, and blue channels, or adjust all three with the gamma parameter.  Values typically range from 0.8 to 2.3.
*/
PHP_METHOD(Imagick, gammaImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	double gamma;
	im_long channel = IM_DEFAULT_CHANNEL;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d|l", &gamma, &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickGammaImageChannel(intern->magick_wand, channel, gamma);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to gamma image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::gaussianBlurImage(float radius, float sigma[, int channel])
	Blurs an image.  We convolve the image with a Gaussian operator of the given radius and standard deviation (sigma). For reasonable results, the radius should be larger than sigma.  Use a radius of 0 and selects a suitable radius for you.
*/
PHP_METHOD(Imagick, gaussianBlurImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	double radius, sigma;
	im_long channel = IM_DEFAULT_CHANNEL;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dd|l", &radius, &sigma, &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickGaussianBlurImageChannel(intern->magick_wand, channel, radius, sigma);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to gaussian blur image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto Imagick Imagick::compareImageChannels(int metric, int distortion)
	Compares one or more images and returns the difference image.
*/
PHP_METHOD(Imagick, compareImages)
{
	MagickWand *tmp_wand;
	zval *objvar;
	php_imagick_object *intern, *intern_second, *intern_return;
	im_long metric_type;
	double distortion;
#ifdef ZEND_ENGINE_3
	zval new_wand;
#else
	zval *new_wand;
#endif

	zval *pNewWand;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "Ol", &objvar, php_imagick_sc_entry, &metric_type) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	intern_second = Z_IMAGICK_P(objvar);
	if (php_imagick_ensure_not_empty (intern_second->magick_wand) == 0)
		return;

#ifdef ZEND_ENGINE_3
	pNewWand = &new_wand;
#else
	MAKE_STD_ZVAL(new_wand);
	pNewWand = new_wand;
#endif
	array_init(return_value);

	tmp_wand = MagickCompareImages(intern->magick_wand, intern_second->magick_wand, metric_type, &distortion);

	if (!tmp_wand) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Compare images failed" TSRMLS_CC);
		return;
	}

	object_init_ex(pNewWand, php_imagick_sc_entry);
	intern_return = Z_IMAGICK_P(pNewWand);
	php_imagick_replace_magickwand(intern_return, tmp_wand);

	add_next_index_zval(return_value, pNewWand);
	add_next_index_double(return_value, distortion);

	return;
}
/* }}} */

/* {{{ proto bool Imagick::contrastImage(bool sharpen)
	Enhances the intensity differences between the lighter and darker elements of the image.  Set sharpen to a value other than 0 to increase the image contrast otherwise the contrast is reduced.
*/
PHP_METHOD(Imagick, contrastImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	zend_bool contrast;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "b", &contrast) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickContrastImage(intern->magick_wand, contrast);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to contrast image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::setImageDepth(int depth)
	Sets the image depth.
*/
PHP_METHOD(Imagick, setImageDepth)
{
	php_imagick_object *intern;
	im_long depth;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &depth) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSetImageDepth(intern->magick_wand, depth);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image depth" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::setImageGamma(float gamma)
	Sets the image gamma.
*/
PHP_METHOD(Imagick, setImageGamma)
{
	php_imagick_object *intern;
	double gamma;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d", &gamma) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSetImageGamma(intern->magick_wand, gamma);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image gamma" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::setImageIterations(int iterations)
	Sets the image iterations.
*/
PHP_METHOD(Imagick, setImageIterations)
{
	php_imagick_object *intern;
	im_long iterations;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &iterations) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSetImageIterations(intern->magick_wand, iterations);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image iterations" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

#if MagickLibVersion < 0x700
/* {{{ proto bool Imagick::setImageMatteColor(ImagickPixel matte)
	Sets the image matte color.
*/
PHP_METHOD(Imagick, setImageMatteColor)
{
	zval *param;
	php_imagick_object *intern;
	MagickBooleanType status;
	PixelWand *color_wand;
	zend_bool allocated;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &param) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	color_wand = php_imagick_zval_to_pixelwand (param, IMAGICK_CLASS, &allocated TSRMLS_CC);
	if (!color_wand)
		return;

	status = MagickSetImageMatteColor(intern->magick_wand, color_wand);

	if (allocated)
		color_wand = DestroyPixelWand (color_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image matte color" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */
#endif //#if MagickLibVersion < 0x700

/* {{{ proto bool Imagick::setImagePage(int width, int height, int x, int y)
	Sets the page geometry of the image.
*/
PHP_METHOD(Imagick, setImagePage)
{
	php_imagick_object *intern;
	im_long width, height, x, y;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "llll", &width, &height, &x, &y) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSetImagePage(intern->magick_wand, width, height, x, y);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image page" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::setImageResolution(float x_resolution,const float y_resolution)
	Sets the image resolution.
*/
PHP_METHOD(Imagick, setImageResolution)
{
	php_imagick_object *intern;
	double x_res, y_res;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dd", &x_res, &y_res) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSetImageResolution(intern->magick_wand, x_res, y_res);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image resolution" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::setImageScene(int scene)
	Sets the image scene.
*/
PHP_METHOD(Imagick, setImageScene)
{
	php_imagick_object *intern;
	im_long scene;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &scene) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSetImageScene(intern->magick_wand, scene);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image scene" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::setImageTicksPerSecond(int ticks_per-second)
	Sets the image ticks-per-second.
*/
PHP_METHOD(Imagick, setImageTicksPerSecond)
{
	php_imagick_object *intern;
	im_long ticks_per_second;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &ticks_per_second) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSetImageTicksPerSecond(intern->magick_wand, ticks_per_second);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image ticks per second" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::setImageType(int image_type)
	Sets the image type.
*/
PHP_METHOD(Imagick, setImageType)
{
	php_imagick_object *intern;
	im_long image_type;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &image_type) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSetImageType(intern->magick_wand, image_type);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image type" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::setImageUnits(int units)
	Sets the image units of resolution.
*/
PHP_METHOD(Imagick, setImageUnits)
{
	php_imagick_object *intern;
	im_long units;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &units) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSetImageUnits(intern->magick_wand, units);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image units" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::setImageFormat(string format)
	Sets the format of a particular image in a sequence.
*/
PHP_METHOD(Imagick, setImageFormat)
{
	char *format;
	IM_LEN_TYPE format_len;
	MagickBooleanType status;
	php_imagick_object *intern;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &format, &format_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSetImageFormat(intern->magick_wand, format);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image format" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::charcoalImage(float radius, float sigma)
	Simulates a charcoal drawing.
*/
PHP_METHOD(Imagick, charcoalImage)
{
	double sigma, radius;
	MagickBooleanType status;
	php_imagick_object *intern;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dd", &radius, &sigma) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickCharcoalImage(intern->magick_wand, sigma, radius);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to charcoal image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::oilPaintImage(float radius)
	Applies a special effect filter that simulates an oil painting.  Each pixel is replaced by the most frequent color occurring in a circular region defined by radius.
*/
PHP_METHOD(Imagick, oilPaintImage)
{
	double radius;
	MagickBooleanType status;
	php_imagick_object *intern;
#if MagickLibVersion >= 0x700
	float sigma = 1.0;
	//TODO - allow sigma to be set.
#endif // #if MagickLibVersion >= 0x700

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d", &radius) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

#if MagickLibVersion >= 0x700
	status = MagickOilPaintImage(intern->magick_wand, radius, sigma);
#else
	status = MagickOilPaintImage(intern->magick_wand, radius);
#endif

	/* No magick is going to happen */
	if (status == MagickFalse)
	{
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to oilpaint image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::normalizeImage([int channel])
	Enhances the contrast of a color image by adjusting the pixels color to span the entire range of colors available, Channel parameter is ignored in ImageMagick below 6.2.8
*/
PHP_METHOD(Imagick, normalizeImage)
{
	MagickBooleanType status;
	php_imagick_object *intern;
	im_long channel = IM_DEFAULT_CHANNEL;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|l", &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

#if MagickLibVersion > 0x628
	status = MagickNormalizeImageChannel(intern->magick_wand, channel);
#else
	status = MagickNormalizeImage(intern->magick_wand);
#endif
	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to normalize image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::labelImage(string label)
	Adds a label to your image.
*/
PHP_METHOD(Imagick, labelImage)
{
	char *label;
	IM_LEN_TYPE label_len;
	MagickBooleanType status;
	php_imagick_object *intern;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &label, &label_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;
	status = MagickLabelImage(intern->magick_wand, label);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to label image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::writeImage(string filename)
	Writes an image to the specified filename
*/
PHP_METHOD(Imagick, writeImage)
{
	char *filename = NULL;
	IM_LEN_TYPE filename_len = 0;
	zend_bool free_filename = 0;
	php_imagick_object *intern;
	struct php_imagick_file_t file = {0};
	php_imagick_rw_result_t rc;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|s!", &filename, &filename_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	if (!filename) {
		filename = MagickGetImageFilename(intern->magick_wand);

		if (!filename) {
			php_imagick_throw_exception(IMAGICK_CLASS, "No image filename specified" TSRMLS_CC);
			return;
		}
		filename_len = strlen(filename);
		free_filename = 1;
	}

	if (!filename_len) {
		php_imagick_throw_exception(IMAGICK_CLASS, "Can not use empty string as a filename" TSRMLS_CC);
		return;
	}

	if (!php_imagick_file_init(&file, filename, filename_len TSRMLS_CC)) {
		php_imagick_throw_exception(IMAGICK_CLASS, "Invalid filename provided" TSRMLS_CC);
		return;
	}
	rc = php_imagick_write_file(intern, &file, ImagickWriteImage, 0 TSRMLS_CC);
	php_imagick_file_deinit(&file);

	if (rc != IMAGICK_RW_OK) {
		php_imagick_rw_fail_to_exception (intern->magick_wand, rc, filename TSRMLS_CC);
		if (free_filename) {
			IMAGICK_FREE_MAGICK_MEMORY(filename);
		}
		return;
	}

	if (free_filename) {
		IMAGICK_FREE_MAGICK_MEMORY(filename);
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::writeImages(string filename, bool adjoin)
	Writes an image or image sequence.
*/
PHP_METHOD(Imagick, writeImages)
{
	char *filename;
	zend_bool adjoin;
	IM_LEN_TYPE filename_len;
	php_imagick_object *intern;
	struct php_imagick_file_t file = {0};
	php_imagick_rw_result_t rc;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sb", &filename, &filename_len, &adjoin) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	if (!filename_len) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Can not use empty string as a filename" TSRMLS_CC);
		return;
	}

	if (!php_imagick_file_init(&file, filename, filename_len TSRMLS_CC)) {
		php_imagick_throw_exception(IMAGICK_CLASS, "Invalid filename provided" TSRMLS_CC);
		return;
	}
	rc = php_imagick_write_file(intern, &file, ImagickWriteImages, adjoin TSRMLS_CC);
	php_imagick_file_deinit(&file);

	if (rc != IMAGICK_RW_OK) {
		php_imagick_rw_fail_to_exception (intern->magick_wand, rc, filename TSRMLS_CC);
		return;
	}
	RETURN_TRUE;

}
/* }}} */

/* {{{ proto bool Imagick::drawImage(ImagickDraw drawing_wand)
	Renders the ImagickDrawing object on the current image.
*/
PHP_METHOD(Imagick, drawImage)
{
	zval *objvar;
	php_imagick_object *intern;
	MagickBooleanType status;
	php_imagickdraw_object *internd;
	char *old_locale;

	intern = Z_IMAGICK_P(getThis());

	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "O", &objvar, php_imagickdraw_sc_entry) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(objvar);

	old_locale = php_imagick_set_locale (TSRMLS_C);

	status = MagickDrawImage(intern->magick_wand, internd->drawing_wand);

	php_imagick_restore_locale (old_locale);

	if (old_locale)
		efree (old_locale);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to draw image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::annotateImage(ImagickDraw drawing_wand, float x, float y, float angle, string text)
	Annotates an image with text.
*/
PHP_METHOD(Imagick, annotateImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	php_imagickdraw_object *internd;
	double x, y, angle;
	char *text;
	IM_LEN_TYPE text_len;
	zval *objvar;
#if MagickLibVersion < 0x632
	char *font;
#endif

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "Oddds", &objvar, php_imagickdraw_sc_entry, &x, &y, &angle, &text, &text_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	internd = Z_IMAGICKDRAW_P(objvar);

#if MagickLibVersion < 0x632
	font = DrawGetFont(internd->drawing_wand);

	/* Fixes PECL Bug #11328 */
	if (!font) {
		php_imagick_throw_exception(IMAGICK_CLASS, "Font needs to be set before annotating an image" TSRMLS_CC);
		return;
	}
#endif

	status = MagickAnnotateImage(intern->magick_wand, internd->drawing_wand, x, y, angle, text);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to annotate image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::getImageCompressionQuality(int quality)
        Gets the image compression quality 
*/
PHP_METHOD(Imagick, getImageCompressionQuality)
{
	php_imagick_object *intern;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	RETVAL_LONG(MagickGetImageCompressionQuality(intern->magick_wand));
}
/* }}} */

/* {{{ proto bool Imagick::setImageCompressionQuality(int quality)
	Sets the image compression quality
*/
PHP_METHOD(Imagick, setImageCompressionQuality)
{
	im_long quality;
	php_imagick_object *intern;
	MagickBooleanType status;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &quality) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSetImageCompressionQuality(intern->magick_wand, quality);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set image compression quality" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */


/* {{{ proto bool Imagick::compositeImage(Imagick composite_wand, int compose, int x, int y[, int channel] )
	Composite one image onto another at the specified offset. Channel parameter is ignored in ImageMagick below 6.2.8
*/
PHP_METHOD(Imagick, compositeImage)
{
	zval *objvar;
	php_imagick_object *intern;
	php_imagick_object *intern_second;
	im_long x, y;
	im_long composite_id = 0;
	im_long channel = IM_DEFAULT_CHANNEL;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "Olll|l", &objvar, php_imagick_sc_entry, &composite_id, &x, &y, &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	intern_second = Z_IMAGICK_P(objvar);
	if (php_imagick_ensure_not_empty (intern_second->magick_wand) == 0)
		return;

#if MagickLibVersion > 0x628
	MagickCompositeImageChannel(intern->magick_wand, channel, intern_second->magick_wand, composite_id, x, y);
#else
	MagickCompositeImage(intern->magick_wand, intern_second->magick_wand, composite_id, x, y);
#endif

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::modulateImage(float brightness, float saturation, float hue)
	Lets you control the brightness, saturation, and hue of an image.  Hue is the percentage of absolute rotation from the current position.  For example 50 results in a counter-clockwise rotation of 90 degrees, 150 results in a clockwise rotation of 90 degrees, with 0 and 200 both resulting in a rotation of 180 degrees.
*/
PHP_METHOD(Imagick, modulateImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	double brightness, saturation, hue;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ddd", &brightness, &saturation, &hue) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickModulateImage(intern->magick_wand, brightness, saturation, hue);

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to modulate image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::addNoiseImage(int noise_type[, int channel])
	Adds random noise to the image. Channel parameter is ignored in ImageMagick below 6.2.8
*/
PHP_METHOD(Imagick, addNoiseImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	im_long noise;
	im_long channel = IM_DEFAULT_CHANNEL;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l|l", &noise, &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

#if MagickLibVersion > 0x628
	status = MagickAddNoiseImageChannel(intern->magick_wand, channel, noise);
#else
	status = MagickAddNoiseImage(intern->magick_wand, noise);
#endif

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to add image noise" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto Imagick Imagick::montageImage(ImagickDraw drawing_wand, string tile_geometry, string thumbnail_geometry, int mode, string frame)
	Creates a composite image by combining several separate images. The images are tiled on the composite image with the name of the image optionally appearing just below the individual tile.
*/

PHP_METHOD(Imagick, montageImage)
{
	MagickWand *tmp_wand;
	zval *objvar;
	php_imagick_object *intern, *intern_return;
	php_imagickdraw_object *internd;
	char *tile_geometry, *thumbnail_geometry, *frame;
	IM_LEN_TYPE tile_geometry_len, thumbnail_geometry_len, frame_len;
	im_long montage_mode = 0;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "Ossls", &objvar, php_imagickdraw_sc_entry,
		&tile_geometry, &tile_geometry_len,
		&thumbnail_geometry, &thumbnail_geometry_len,
		&montage_mode,
		&frame, &frame_len) == FAILURE)
	{
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;
	internd = Z_IMAGICKDRAW_P(objvar);

	tmp_wand = MagickMontageImage(intern->magick_wand, internd->drawing_wand, tile_geometry, thumbnail_geometry, montage_mode, frame);

	if (tmp_wand == NULL) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Montage image failed" TSRMLS_CC);
		return;
	}

	object_init_ex(return_value, php_imagick_sc_entry);
	intern_return = Z_IMAGICK_P(return_value);
	php_imagick_replace_magickwand(intern_return, tmp_wand);

	return;
}
/* }}} */

/* {{{ proto bool Imagick::affineTransformImage(ImagickDraw drawing_wand)
	Transforms an image as dictated by the affine matrix of the drawing wand.
*/
PHP_METHOD(Imagick, affineTransformImage)
{
	zval *objvar;
	php_imagick_object *intern;
	php_imagickdraw_object *internd;
	MagickBooleanType status;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "O", &objvar, php_imagickdraw_sc_entry) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	internd = Z_IMAGICKDRAW_P(objvar);
	status = MagickAffineTransformImage(intern->magick_wand, internd->drawing_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to affine transform image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

#if MagickLibVersion < 0x700
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
/* {{{ proto Imagick Imagick::averageImages()
	Average a set of images.
*/
PHP_METHOD(Imagick, averageImages)
{
	MagickWand *tmp_wand;
	php_imagick_object *intern, *intern_return;

	IMAGICK_METHOD_DEPRECATED ("Imagick", "averageImages");

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	tmp_wand = MagickAverageImages(intern->magick_wand);

	if (tmp_wand == NULL) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Averaging images failed" TSRMLS_CC);
		return;
	}

	object_init_ex(return_value, php_imagick_sc_entry);
	intern_return = Z_IMAGICK_P(return_value);
	php_imagick_replace_magickwand(intern_return, tmp_wand);
	return;
}
/* }}} */
#endif
#endif

/* {{{ proto bool Imagick::borderImage(ImagickPixel bordercolor, int width, int height)
	Surrounds the image with a border of the color defined by the bordercolor pixel wand.
*/
PHP_METHOD(Imagick, borderImage)
{
	zval *param;
	php_imagick_object *intern;
	MagickBooleanType status;
	im_long width, height;
	PixelWand *color_wand;
	zend_bool allocated;
	
#if MagickLibVersion >= 0x700
	//TODO - understand and allow compose to be set.
	CompositeOperator compose = AtopCompositeOp; 
#endif // #if MagickLibVersion >= 0x700

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zll", &param, &width, &height) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	color_wand = php_imagick_zval_to_pixelwand (param, IMAGICK_CLASS, &allocated TSRMLS_CC);
	if (!color_wand)
		return;

#if MagickLibVersion >= 0x700 
	status = MagickBorderImage(intern->magick_wand, color_wand, width, height, compose);
#else
	status = MagickBorderImage(intern->magick_wand, color_wand, width, height);
#endif

	if (allocated)
		color_wand = DestroyPixelWand (color_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to border image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::thresholdImage(float threshold[, int channel] )
	Changes the value of individual pixels based on the intensity of each pixel compared to threshold.  The result is a high-contrast, two color image.
*/
PHP_METHOD(Imagick, thresholdImage)
{
	php_imagick_object *intern;
	double threshold;
	MagickBooleanType status;
	im_long channel = DefaultChannels;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d|l", &threshold, &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickThresholdImageChannel(intern->magick_wand, channel, threshold);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to threshold image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::adaptiveThresholdImage(int width, int height, int offset)
	Selects an individual threshold for each pixel based on the range of intensity values in its local neighborhood.  This allows for thresholding of an image whose global intensity histogram doesn't contain distinctive peaks.
*/
PHP_METHOD(Imagick, adaptiveThresholdImage)
{
	php_imagick_object *intern;
	im_long width, height, offset;
	MagickBooleanType status;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "lll", &width, &height, &offset) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickAdaptiveThresholdImage(intern->magick_wand, width, height, offset);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to adaptive threshold image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::sharpenImage(float radius, float sigma[, int channel])
	Sharpens an image.  We convolve the image with a Gaussian operator of the given radius and standard deviation (sigma). For reasonable results, the radius should be larger than sigma.  Use a radius of 0 and selects a suitable radius for you.
*/
PHP_METHOD(Imagick, sharpenImage)
{
	double sigma, radius;
	MagickBooleanType status;
	php_imagick_object *intern;
	im_long channel = IM_DEFAULT_CHANNEL;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dd|l", &radius, &sigma, &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSharpenImageChannel(intern->magick_wand, channel, radius, sigma);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to sharpen image" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::shaveImage(int columns, int rows)
	Shaves pixels from the image edges.  It allocates the memory necessary for the new Image structure and returns a pointer to the new image.
*/
PHP_METHOD(Imagick, shaveImage)
{
	php_imagick_object *intern;
	im_long columns, rows;
	MagickBooleanType status;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll", &columns, &rows) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickShaveImage(intern->magick_wand, columns, rows);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to shave image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::shearImage(ImagickPixel background, float x_shear, float y_shear)
	Slides one edge of an image along the X or Y axis
*/
PHP_METHOD(Imagick, shearImage)
{
	zval *param;
	php_imagick_object *intern;
	double x_shear, y_shear;
	MagickBooleanType status;
	PixelWand *color_wand;
	zend_bool allocated;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zdd", &param, &x_shear, &y_shear) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	color_wand = php_imagick_zval_to_pixelwand (param, IMAGICK_CLASS, &allocated TSRMLS_CC);
	if (!color_wand)
		return;

	status = MagickShearImage(intern->magick_wand, color_wand, x_shear, y_shear);

	if (allocated)
		color_wand = DestroyPixelWand (color_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to shear image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::spliceImage(int width, int height, int x, int y)
	Splices a solid color into the image.
*/
PHP_METHOD(Imagick, spliceImage)
{
	im_long width, height, x, y;
	php_imagick_object *intern;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "llll", &width, &height, &x, &y) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSpliceImage(intern->magick_wand, width, height, x, y);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to splice image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto Imagick Imagick::steganoImage(Imagick watermark_wand, int offset)
	Hides a digital watermark within the image. Recover the hidden watermark later to prove that the authenticity of an image.  Offset defines the start position within the image to hide the watermark.
*/
PHP_METHOD(Imagick, steganoImage)
{
	zval *objvar;
	php_imagick_object *intern, *intern_second, *intern_return;
	im_long offset;
	MagickWand *tmp_wand;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "Ol", &objvar, php_imagick_sc_entry, &offset) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	intern_second = Z_IMAGICK_P(objvar);
	if (php_imagick_ensure_not_empty (intern_second->magick_wand) == 0)
		return;

	tmp_wand = MagickSteganoImage(intern->magick_wand, intern_second->magick_wand, offset);

	if (!tmp_wand) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Stegano image failed" TSRMLS_CC);
		return;
	}

	object_init_ex(return_value, php_imagick_sc_entry);
	intern_return = Z_IMAGICK_P(return_value);
	php_imagick_replace_magickwand(intern_return, tmp_wand);
	return;
}
/* }}} */

/* {{{ proto Imagick Imagick::clone()
	Makes an exact copy of the Imagick object.
*/
PHP_METHOD(Imagick, clone)
{
	php_imagick_object *intern, *intern_return;
	MagickWand *tmp_wand;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	IMAGICK_METHOD_DEPRECATED("Imagick", "clone");
	intern = Z_IMAGICK_P(getThis());
	tmp_wand = CloneMagickWand(intern->magick_wand);

	if (tmp_wand == NULL) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Cloning Imagick object failed" TSRMLS_CC);
		return;
	}

	object_init_ex(return_value, php_imagick_sc_entry);
	intern_return = Z_IMAGICK_P(return_value);
	php_imagick_replace_magickwand(intern_return, tmp_wand);
	return;
}
/* }}} */

/* {{{ proto bool Imagick::rotateImage(ImagickPixel background, float degrees)
	Rotates an image the specified number of degrees. Empty triangles left over from rotating the image are filled with the background color.
*/
PHP_METHOD(Imagick, rotateImage)
{
	zval *param;
	php_imagick_object *intern;
	double degrees;
	MagickBooleanType status;
	PixelWand *color_wand;
	zend_bool allocated;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zd", &param, &degrees) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	color_wand = php_imagick_zval_to_pixelwand (param, IMAGICK_CLASS, &allocated TSRMLS_CC);
	if (!color_wand)
		return;

	status = MagickRotateImage(intern->magick_wand, color_wand, degrees);

	if (allocated)
		color_wand = DestroyPixelWand (color_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to rotate image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::sampleImage(int columns, int rows)
	Scales an image to the desired dimensions with pixel sampling.  Unlike other scaling methods, this method does not introduce any additional color into the scaled image.
*/
PHP_METHOD(Imagick, sampleImage)
{
	php_imagick_object *intern;
	im_long columns, rows;
	MagickBooleanType status;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll", &columns, &rows) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSampleImage(intern->magick_wand, columns, rows);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to sample image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::solarizeImage(float threshold)
	Applies a special effect to the image, similar to the effect achieved in a photo darkroom by selectively exposing areas of photo sensitive paper to light.  Threshold ranges from 0 to QuantumRange and is a measure of the extent of the solarization.
*/
PHP_METHOD(Imagick, solarizeImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	im_long threshold;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &threshold) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSolarizeImage(intern->magick_wand, threshold);

	/* No magick is going to happen */
	if (status == MagickFalse)
	{
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to solarize image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::shadowImage(float opacity, float sigma, int x, int y)
	Simulates an image shadow.
*/
PHP_METHOD(Imagick, shadowImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	double opacity, sigma;
	long x, y;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ddll", &opacity, &sigma, &x, &y) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickShadowImage(intern->magick_wand, opacity, sigma, x, y);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to shadow image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::motionBlurImage(float radius, float sigma, float angle[, int CHANNEL])
	Simulates motion blur.  We convolve the image with a Gaussian operator of the given radius and standard deviation (sigma). For reasonable results, radius should be larger than sigma.  Use a radius of 0 and MotionBlurImage() selects a suitable radius for you. Angle gives the angle of the blurring motion.
*/
PHP_METHOD(Imagick, motionBlurImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	double radius, sigma, angle;
	im_long channel = IM_DEFAULT_CHANNEL;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ddd|l", &radius, &sigma, &angle, &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

#if MagickLibVersion > 0x643
	status = MagickMotionBlurImageChannel(intern->magick_wand, channel, radius, sigma, angle);
#else
	status = MagickMotionBlurImage(intern->magick_wand, radius, sigma, angle);
#endif

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to motion blur image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;


}
/* }}} */

#if MagickLibVersion < 0x700
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
/* {{{ proto Imagick Imagick::mosaicImages()
	Inlays an image sequence to form a single coherent picture.  It returns a wand with each image in the sequence composited at the location defined by the page offset of the image.
*/
PHP_METHOD(Imagick, mosaicImages)
{
	MagickWand *tmp_wand = NULL;
	php_imagick_object *intern, *intern_return;

	IMAGICK_METHOD_DEPRECATED ("Imagick", "mosaicImages");

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	/* TODO: should this be here? */
	MagickSetFirstIterator(intern->magick_wand);
	tmp_wand = MagickMosaicImages(intern->magick_wand);

	if (!tmp_wand) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Mosaic image failed" TSRMLS_CC);
		return;
	}

	object_init_ex(return_value, php_imagick_sc_entry);
	intern_return = Z_IMAGICK_P(return_value);
	php_imagick_replace_magickwand(intern_return, tmp_wand);

	return;

}
/* }}} */
#endif
#endif
/* {{{ proto Imagick Imagick::morphImages(int number_frames)
	Method morphs a set of images.  Both the image pixels and size are linearly interpolated to give the appearance of a meta-morphosis from one image to the next.
*/
PHP_METHOD(Imagick, morphImages)
{
	MagickWand *tmp_wand;
	php_imagick_object *intern, *intern_return;
	im_long frames;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &frames) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	tmp_wand = MagickMorphImages(intern->magick_wand, frames);

	if (!tmp_wand) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Morphing images failed" TSRMLS_CC);
		return;
	}

	object_init_ex(return_value, php_imagick_sc_entry);
	intern_return = Z_IMAGICK_P(return_value);
	php_imagick_replace_magickwand(intern_return, tmp_wand);

	return;

}
/* }}} */

/* {{{ proto bool Imagick::minifyImage()
	Is a convenience method that scales an image proportionally to one-half its original size
*/
PHP_METHOD(Imagick, minifyImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickMinifyImage(intern->magick_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to minify image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;

}
/* }}} */

/* {{{ proto bool Imagick::posterizeImage(int levels, bool dither)
	Reduces the image to a limited number of color level.
*/
PHP_METHOD(Imagick, posterizeImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	im_long levels;
	zend_bool dither;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "lb", &levels, &dither) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickPosterizeImage(intern->magick_wand, levels, dither);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to posterize image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;

}
/* }}} */

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
/* {{{ proto bool Imagick::radialBlurImage(float angle[, int channel])
	Radial blurs an image.
*/
PHP_METHOD(Imagick, radialBlurImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	double angle;
	im_long channel = DefaultChannels;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d|l", &angle, &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickRadialBlurImageChannel(intern->magick_wand, channel, angle);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to radial blur image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */
#endif
#endif

/* {{{ proto bool Imagick::raiseImage(int width, int height, int x, int y, bool raise)
	Creates a simulated three-dimensional button-like effect by lightening and darkening the edges of the image.  Members width and height of raise_info define the width of the vertical and horizontal edge of the effect.
*/
PHP_METHOD(Imagick, raiseImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	im_long width, height, x, y;
	zend_bool raise;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "llllb", &width, &height, &x, &y, &raise) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickRaiseImage(intern->magick_wand, width, height, x, y, raise);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to raise image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::blackThresholdImage(ImagickPixel threshold)
	Is like MagickThresholdImage() but  forces all pixels below the threshold into black while leaving all pixels above the threshold unchanged.
*/
PHP_METHOD(Imagick, blackThresholdImage)
{
	php_imagick_object *intern;
	zval *param;
	MagickBooleanType status;
	PixelWand *color_wand;
	zend_bool allocated;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &param) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	color_wand = php_imagick_zval_to_pixelwand (param, IMAGICK_CLASS, &allocated TSRMLS_CC);
	if (!color_wand)
		return;

	status = MagickBlackThresholdImage(intern->magick_wand, color_wand);

	if (allocated)
		color_wand = DestroyPixelWand (color_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to black threshold image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::resampleImage(float x_resolution, float y_resolution, int filter, float blur)
	Resample image to desired resolution.
*/
PHP_METHOD(Imagick, resampleImage)
{
	double xRes, yRes, blur;
	im_long filter = 0;
	php_imagick_object *intern;
	MagickBooleanType status;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ddld", &xRes, &yRes, &filter, &blur) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;
		
#if MagickLibVersion >= 0x700
	//TODO - allow filter to be set.
	//TODO - figure out what to do about blur.
	status = MagickResampleImage(intern->magick_wand, xRes, yRes, LanczosFilter);
#else
	status = MagickResampleImage(intern->magick_wand, xRes, yRes, filter, blur);
#endif

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to resample image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::resizeImage(int width, int height, int filter, float blur[, bool bestfit = false[, bool legacy]])
	Scales an image to the desired dimensions with one of these filters:
	If legacy is true, the calculations are done with the small rounding bug that existed in
	Imagick before 3.4.0. If false, the calculations should produce the same results as 
	ImageMagick CLI does.
*/
PHP_METHOD(Imagick, resizeImage)
{
	double blur;
	im_long width, height, new_width, new_height, filter = 0;
	php_imagick_object *intern;
	MagickBooleanType status;
	zend_bool bestfit = 0;
	zend_bool legacy = 0;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "llld|bb", &width, &height, &filter, &blur, &bestfit, &legacy) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	if (!php_imagick_thumbnail_dimensions(intern->magick_wand, bestfit, width, height, &new_width, &new_height, legacy)) {
		php_imagick_throw_exception(IMAGICK_CLASS, "Invalid image geometry" TSRMLS_CC);
		return;
	}

#if MagickLibVersion >= 0x700
	//TODO - remove blur from params
	status = MagickResizeImage(intern->magick_wand, new_width, new_height, filter);
#else
	status = MagickResizeImage(intern->magick_wand, new_width, new_height, filter, blur);
#endif

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to resize image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::rollImage(int x, int y)
	Offsets an image as defined by x and y.
*/
PHP_METHOD(Imagick, rollImage)
{
	im_long x, y;
	php_imagick_object *intern;
	MagickBooleanType status;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll", &x, &y) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;
	status = MagickRollImage(intern->magick_wand, x, y);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to roll image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto Imagick Imagick::appendImages(bool stack)
	Append a set of images.
*/
PHP_METHOD(Imagick, appendImages)
{
	php_imagick_object *intern, *intern_return;
	MagickWand *tmp_wand;
	zend_bool stack;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "b", &stack) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;
	tmp_wand = MagickAppendImages(intern->magick_wand, stack);

	if (!tmp_wand) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to append images" TSRMLS_CC);
		return;
	}

	object_init_ex(return_value, php_imagick_sc_entry);
	intern_return = Z_IMAGICK_P(return_value);
	php_imagick_replace_magickwand(intern_return, tmp_wand);
	return;
}
/* }}} */

/* {{{ proto bool Imagick::whiteThresholdImage(ImagickPixel threshold)
	Is like ThresholdImage() but  force all pixels above the threshold into white while leaving all pixels below the threshold unchanged.
*/
PHP_METHOD(Imagick, whiteThresholdImage)
{
	php_imagick_object *intern;
	zval *param;
	MagickBooleanType status;
	PixelWand *color_wand;
	zend_bool allocated;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &param) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	color_wand = php_imagick_zval_to_pixelwand (param, IMAGICK_CLASS, &allocated TSRMLS_CC);
	if (!color_wand)
		return;

	status = MagickWhiteThresholdImage(intern->magick_wand, color_wand);

	if (allocated)
		color_wand = DestroyPixelWand (color_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to white threshold image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto ImagickPixelIterator Imagick::getPixelIterator()
	Returns a MagickPixelIterator.
*/
PHP_METHOD(Imagick, getPixelIterator)
{
	PixelIterator *pixel_it;
	php_imagick_object *intern;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	pixel_it = NewPixelIterator(intern->magick_wand);

	if (!pixel_it) {
		php_imagick_throw_exception (IMAGICKPIXELITERATOR_CLASS, "Can not allocate ImagickPixelIterator" TSRMLS_CC);
		return;
	}

	php_imagick_pixel_iterator_new (pixel_it, return_value TSRMLS_CC);
	return;
}
/* }}} */

/* {{{ proto ImagickPixelIterator Imagick::getPixelRegionIterator(long x, long y, long columns, long rows)
	Returns a subset of pixels in a MagickPixelIterator object.
*/
PHP_METHOD(Imagick, getPixelRegionIterator)
{
	PixelIterator *pixel_it;
	php_imagick_object *intern;
	im_long x, y, columns, rows;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "llll", &x, &y, &columns, &rows) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

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

/* {{{ proto int Imagick::getCompression()
	Gets the wand compression type.
*/
PHP_METHOD(Imagick, getCompression)
{
	php_imagick_object *intern;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
		
	intern = Z_IMAGICK_P(getThis());
	RETVAL_LONG(MagickGetCompression(intern->magick_wand));
}
/* }}} */

/* {{{ proto int Imagick::getCompressionQuality()
	Gets the wand compression quality.
*/
PHP_METHOD(Imagick, getCompressionQuality)
{
	php_imagick_object *intern;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	RETVAL_LONG(MagickGetCompressionQuality(intern->magick_wand));
}
/* }}} */

/* {{{ proto string Imagick::getCopyright()
	Returns the ImageMagick API copyright as a string constant.
*/
PHP_METHOD(Imagick, getCopyright)
{
	char *copyright;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	copyright = (char *)MagickGetCopyright();
	IM_ZVAL_STRING(return_value, copyright);
	return;
}
/* }}} */


/* {{{ proto string Imagick::getConfigureOptions()
	Returns any ImageMagick  configure options that match the specified pattern (e.g. "*" for all). Options include NAME, VERSION, LIB_VERSION, etc.
*/
PHP_METHOD(Imagick, getConfigureOptions)
{
	size_t number_options;

	char *pattern = "*";
	IM_LEN_TYPE pattern_len;
	char **result;
	char *option_value;
	unsigned int i;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|s", &pattern, &pattern_len) == FAILURE) {
		return;
	}

	result = MagickQueryConfigureOptions(pattern, &number_options);

	array_init(return_value);

	for (i=0; i<number_options; i++) {
		option_value = MagickQueryConfigureOption(result[i]);
		IM_add_assoc_string(return_value, result[i], option_value);
	}
}
/* }}} */

#if MagickLibVersion > 0x660
/* {{{ proto string Imagick::getFeatures()
	GetFeatures() returns the ImageMagick features that have been compiled into the runtime.
*/
PHP_METHOD(Imagick, getFeatures)
{
	const char *features;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	features = GetMagickFeatures();

	IM_ZVAL_STRING(return_value, features);
}
/* }}} */
#endif



/* {{{ proto string Imagick::getFilename()
	Returns the filename associated with an image sequence.
*/
PHP_METHOD(Imagick, getFilename)
{
	php_imagick_object *intern;
	char *filename;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	filename = (char *)MagickGetFilename(intern->magick_wand);

	if (filename) {
		IM_ZVAL_STRING(return_value, filename);
		IMAGICK_FREE_MAGICK_MEMORY(filename);
	}
	return;
}
/* }}} */

/* {{{ proto string Imagick::getFormat()
	Returns the format of the Imagick object.
*/
PHP_METHOD(Imagick, getFormat)
{
	php_imagick_object *intern;
	char *format;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	format = (char *)MagickGetFormat(intern->magick_wand);

	if (format) {
		IM_ZVAL_STRING(return_value, format);
		IMAGICK_FREE_MAGICK_MEMORY(format);
	}
	return;
}
/* }}} */

/* {{{ proto string Imagick::getHomeURL()
	Returns the ImageMagick home URL.
*/
PHP_METHOD(Imagick, getHomeURL)
{
	char *home_url;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	home_url = (char *)MagickGetHomeURL();
	if (home_url) {
		IM_ZVAL_STRING(return_value, home_url);
		IMAGICK_FREE_MAGICK_MEMORY(home_url);
	}
	return;
}
/* }}} */

/* {{{ proto int Imagick::getInterlaceScheme()
	Gets the wand interlace scheme.
*/
PHP_METHOD(Imagick, getInterlaceScheme)
{
	php_imagick_object *intern;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	RETVAL_LONG(MagickGetInterlaceScheme(intern->magick_wand));
}
/* }}} */

/* {{{ proto string Imagick::getOption(string key)
	Returns a value associated with a wand and the specified key. Use MagickRelinquishMemory() to free the value when you are finished with it.
*/
PHP_METHOD(Imagick, getOption)
{
	php_imagick_object *intern;
	char *key, *value;
	IM_LEN_TYPE key_len;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &key, &key_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	value = MagickGetOption(intern->magick_wand, key);

	if (value) {	
		IM_ZVAL_STRING(return_value, value);
		IMAGICK_FREE_MAGICK_MEMORY(value);
	}
	return;
}
/* }}} */

/* {{{ proto string Imagick::getPackageName()
	Returns the ImageMagick package name as a string constant.
*/
PHP_METHOD(Imagick, getPackageName)
{
	char *package_name;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	package_name = (char *)MagickGetPackageName();
	IM_ZVAL_STRING(return_value, package_name);
	return;
}
/* }}} */

/* {{{ proto array Imagick::getPage()
	Returns the page geometry associated with the Imagick object in an associative array with the keys "width", "height", "x", and "y".
*/
PHP_METHOD(Imagick, getPage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	size_t width, height;
	ssize_t x, y;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	status = MagickGetPage(intern->magick_wand, &width, &height, &x, &y);

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to get page" TSRMLS_CC);
		return;
	}

	array_init(return_value);
	add_assoc_long(return_value, "width", width);
	add_assoc_long(return_value, "height", height);
	add_assoc_long(return_value, "x", x);
	add_assoc_long(return_value, "y", y);

	return;
}
/* }}} */

/* {{{ proto int Imagick::getHDRIEnabled()
	Returns true if Imagick was compiled against a HDRI verison of ImageMagick.
*/
PHP_METHOD(Imagick, getHdriEnabled)
{
	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

#if MAGICKCORE_HDRI_ENABLE
	RETURN_TRUE;
#else
	RETURN_FALSE;
#endif
	return;
}
/* }}} */


/* {{{ proto int Imagick::getQuantum()
	Returns the ImageMagick quantum range as an integer.
*/
PHP_METHOD(Imagick, getQuantum)
{
	size_t range;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	MagickGetQuantumRange(&range);
	ZVAL_LONG(return_value, range);
	
//#ifdef MAGICKCORE_HDRI_ENABLE
//	RETVAL_DOUBLE(color_value);
//#else
//	RETVAL_LONG(color_value);
//#endif
	return;
}
/* }}} */


/* {{{ proto array Imagick::getQuantumDepth()
	Returns the ImageMagick quantum depth as a string constant.
*/
PHP_METHOD(Imagick, getQuantumDepth)
{
	const char *quantum_depth;
	size_t depth;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	quantum_depth = MagickGetQuantumDepth(&depth);

	array_init(return_value);
	add_assoc_long(return_value, "quantumDepthLong", depth);
	IM_add_assoc_string(return_value, "quantumDepthString", (char *)quantum_depth);

	return;
}
/* }}} */

/* {{{ proto array Imagick::getQuantumRange()
	Returns the ImageMagick quantum range as a string constant.
*/
PHP_METHOD(Imagick, getQuantumRange)
{
	const char *quantum_range;
	size_t range;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	quantum_range = MagickGetQuantumRange(&range);
	array_init(return_value);

	add_assoc_long(return_value, "quantumRangeLong", range);
	IM_add_assoc_string(return_value, "quantumRangeString", (char *)quantum_range);
	return;
}
/* }}} */

/* {{{ proto string Imagick::getReleaseDate()
	Returns the ImageMagick release date as a string constant.
*/
PHP_METHOD(Imagick, getReleaseDate)
{
	char *release_date;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	release_date = (char *)MagickGetReleaseDate();
	IM_ZVAL_STRING(return_value, release_date);
	return;
}
/* }}} */

/* {{{ proto int Imagick::getResource(int type)
	Returns the specified resource in megabytes.
*/
PHP_METHOD(Imagick, getResource)
{
	im_long resource_type;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &resource_type) == FAILURE) {
		return;
	}

	RETVAL_LONG(MagickGetResource(resource_type));
}
/* }}} */

/* {{{ proto Imagick Imagick::getResourceLimit(int type)
	Returns the specified resource limit in megabytes.
*/
PHP_METHOD(Imagick, getResourceLimit)
{
	im_long resource_type;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &resource_type) == FAILURE) {
		return;
	}

	RETVAL_DOUBLE(MagickGetResourceLimit(resource_type));
}
/* }}} */

/* {{{ proto array Imagick::getSamplingFactors()
	Gets the horizontal and vertical sampling factor.
*/
PHP_METHOD(Imagick, getSamplingFactors)
{
	php_imagick_object *intern;
	double *sampling_factors;
	unsigned long i;
	size_t number_factors = 0;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	sampling_factors = (double *)MagickGetSamplingFactors(intern->magick_wand, &number_factors);

	array_init(return_value);

	for (i = 0 ; i < number_factors; i++) {
		add_next_index_double(return_value, sampling_factors[i]);
	}

	MagickRelinquishMemory(sampling_factors);

	return;
}
/* }}} */

/* {{{ proto array Imagick::getSize()
	Returns the size associated with the Imagick object as an array with the keys "columns" and "rows".
*/
PHP_METHOD(Imagick, getSize)
{
	php_imagick_object *intern;
	size_t columns, rows;
	MagickBooleanType status;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	status = MagickGetSize(intern->magick_wand, &columns, &rows);

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to get size" TSRMLS_CC);
		return;
	}

	array_init(return_value);
	add_assoc_long(return_value, "columns", columns);
	add_assoc_long(return_value, "rows", rows);

	return;
}
/* }}} */

/* {{{ proto array Imagick::getVersion()
	Returns the ImageMagick API version as a string constant and as a number.
*/
PHP_METHOD(Imagick, getVersion)
{
	char *version_string;
	size_t version_number;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	version_string = (char *)MagickGetVersion(&version_number);
	array_init(return_value);

	add_assoc_long(return_value, "versionNumber", (long) version_number);
	IM_add_assoc_string(return_value, "versionString", version_string);
	return;
}
/* }}} */

/* {{{ proto bool Imagick::setBackgroundColor(ImagickPixel background)
	Sets the wand background color.
*/
PHP_METHOD(Imagick, setBackgroundColor)
{
	zval *param;
	php_imagick_object *intern;
	MagickBooleanType status;
	PixelWand *background_wand;
	zend_bool allocated = 0;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &param) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	background_wand = php_imagick_zval_to_pixelwand (param, IMAGICK_CLASS, &allocated TSRMLS_CC);
	if (!background_wand)
		return;

	status = MagickSetBackgroundColor(intern->magick_wand, background_wand);

	if (allocated)
		background_wand = DestroyPixelWand (background_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set background color" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::setCompression(COMPRESSIONTYPE compression)
	Sets the wand compression type.
*/
PHP_METHOD(Imagick, setCompression)
{
	php_imagick_object *intern;
	im_long compression;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &compression) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	status = MagickSetCompression(intern->magick_wand, compression);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set compression" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::setCompressionQuality(int quality)
	Sets the wand compression quality.
*/
PHP_METHOD(Imagick, setCompressionQuality)
{
	php_imagick_object *intern;
	im_long quality;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &quality) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	status = MagickSetCompressionQuality(intern->magick_wand, quality);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set compression quality" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::setFilename(string filename)
	Sets the filename before you read or write an image file.
*/
PHP_METHOD(Imagick, setFilename)
{
	php_imagick_object *intern;
	char *filename;
	IM_LEN_TYPE filename_len;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &filename, &filename_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	status = MagickSetFilename(intern->magick_wand, filename);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set filename" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::setFormat(string format)
	Sets the format of the Imagick object.
*/
PHP_METHOD(Imagick, setFormat)
{
	php_imagick_object *intern;
	char *format;
	IM_LEN_TYPE format_len;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &format, &format_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	status = MagickSetFormat(intern->magick_wand, format);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set format" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::setInterlaceScheme(INTERLACETYPE interlace_scheme)
	Sets the image compression.
*/
PHP_METHOD(Imagick, setInterlaceScheme)
{
	php_imagick_object *intern;
	im_long schema;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &schema) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	status = MagickSetInterlaceScheme(intern->magick_wand, schema);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set interlace scheme" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::setOption(string key, string value)
	Associates one or options with the wand (.e.g MagickSetOption(wand,"jpeg:perserve","yes")).
*/
PHP_METHOD(Imagick, setOption)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	char *key, *value;
	IM_LEN_TYPE key_len, value_len;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss", &key, &key_len, &value, &value_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	status = MagickSetOption(intern->magick_wand, key, value);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set option" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::setPage(int width, int height, int x, int y)
	Sets the page geometry of the Imagick object.
*/
PHP_METHOD(Imagick, setPage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	im_long width, height, x, y;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "llll", &width, &height, &x, &y) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	status = MagickSetPage(intern->magick_wand, width, height, x, y);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set page" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

PHP_METHOD(Imagick, setImageProgressMonitor)
{
	char *filename;
	IM_LEN_TYPE filename_len;
	php_imagick_object *intern;
	php_imagick_rw_result_t rc;

	if (!IMAGICK_G(progress_monitor)) {
		php_imagick_throw_exception(IMAGICK_CLASS, "Progress monitoring is disabled in ini-settings" TSRMLS_CC);
		return;
	}

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &filename, &filename_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	if ((rc = php_imagick_file_access_check (filename TSRMLS_CC)) != IMAGICK_RW_OK) {
		php_imagick_rw_fail_to_exception (intern->magick_wand, rc, filename TSRMLS_CC);
		return;
	}

	if (intern->progress_monitor_name) {
		efree(intern->progress_monitor_name);
	}

	intern->progress_monitor_name = estrdup(filename);
	MagickSetImageProgressMonitor(intern->magick_wand, php_imagick_progress_monitor, intern);
	RETURN_TRUE;
}

/* {{{ proto bool Imagick::setProgressMonitor(callable callback)
	Set a callback that will be called during the processing of the Imagick image.
*/
#if MagickLibVersion > 0x653
PHP_METHOD(Imagick, setProgressMonitor)
{
	zval *user_callback;

	php_imagick_object *intern;
	php_imagick_callback *callback;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &user_callback) == FAILURE) {
		RETURN_FALSE;
	}

	// Check whether the callback is valid now, rather than failing later
	if (!user_callback || !zend_is_callable(user_callback, 0, NULL TSRMLS_CC)) {
		php_imagick_throw_exception(IMAGICK_CLASS, "First argument to setProgressMonitor is expected to be a valid callback" TSRMLS_CC);
		RETURN_FALSE;
	}

	callback = (php_imagick_callback *) emalloc(sizeof(php_imagick_callback));

	TSRMLS_SET_CTX(callback->thread_ctx);
	//We can't free the previous callback as we can't guarantee that
	//ImageMagick won't use it at some point. There is no 'unbind' function
	//for previously set 'MagickSetImageProgressMonitor'
	callback->previous_callback = IMAGICK_G(progress_callback);

	//Add a ref and store the user's callback
#ifdef ZEND_ENGINE_3
	Z_TRY_ADDREF_P(user_callback);
	ZVAL_COPY_VALUE(&callback->user_callback, user_callback);
#else
	Z_ADDREF_P(user_callback);
	callback->user_callback = user_callback;
#endif

	//The callback is now valid, store it in the global
	IMAGICK_G(progress_callback) = callback;
	intern = Z_IMAGICK_P(getThis());

	MagickSetImageProgressMonitor(intern->magick_wand, php_imagick_progress_monitor_callable, callback);
	RETURN_TRUE;
}
#endif

/* {{{ proto bool Imagick::setResourceLimit(RESOURCETYPE type, int limit)
	Sets the limit for a particular resource in megabytes.
*/
PHP_METHOD(Imagick, setResourceLimit)
{
	MagickBooleanType status;
	im_long type;
	double limit;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ld", &type, &limit) == FAILURE) {
		return;
	}

	status = MagickSetResourceLimit(type, (MagickSizeType)limit);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_throw_exception(IMAGICK_CLASS, "Unable to set resource limit" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::setResolution(float x_resolution, float y_resolution)
	Sets the image resolution.
*/
PHP_METHOD(Imagick, setResolution)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	double x_resolution, y_resolution;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dd", &x_resolution, &y_resolution) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	status = MagickSetResolution(intern->magick_wand, x_resolution, y_resolution);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set resolution" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::setSamplingFactors(array factors)
	Sets the image sampling factors.
*/
PHP_METHOD(Imagick, setSamplingFactors)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	zval *factors;
	double *double_array;
	im_long elements = 0;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "a", &factors) == FAILURE) {
		return;
	}

	double_array = php_imagick_zval_to_double_array(factors, &elements TSRMLS_CC);

	if (!double_array) {
		php_imagick_throw_exception(IMAGICK_CLASS, "Can't read array" TSRMLS_CC);
		return;
	}

	intern = Z_IMAGICK_P(getThis());

	status = MagickSetSamplingFactors(intern->magick_wand, elements, double_array);
	efree(double_array);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set sampling factors" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::setSize(int columns, int rows)
	Sets the size of the Imagick object.  Set it before you read a raw image format such as RGB, GRAY, or CMYK.
*/
PHP_METHOD(Imagick, setSize)
{
	php_imagick_object *intern;
	im_long columns, rows;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll", &columns, &rows) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	status = MagickSetSize(intern->magick_wand, columns, rows);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set size" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::setType(IMAGETYPE image_type)
	Sets the image type attribute.
*/
PHP_METHOD(Imagick, setType)
{
	php_imagick_object *intern;
	im_long type;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &type) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	status = MagickSetType(intern->magick_wand, type);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to set type" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

#if MagickLibVersion >= 0x659
/* {{{ proto bool Imagick::brightnessContrastImage(float brigthness, float contrast[, int channel])
	Change the brightness and/or contrast of an image. It converts the brightness and contrast parameters into slope and intercept and calls a polynomical function to apply to the image.
*/
PHP_METHOD(Imagick, brightnessContrastImage)
{
	php_imagick_object *intern;
	double brightness, contrast;
	MagickBooleanType status;
	im_long channel = IM_DEFAULT_CHANNEL;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dd|l", &brightness, &contrast, &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickBrightnessContrastImageChannel(intern->magick_wand, channel, brightness, contrast);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to brightnesscontrastimage" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */
#endif


#if MagickLibVersion > 0x661

static KernelInfo *php_imagick_getKernelInfo(const double *color_matrix, const size_t order)
{
	KernelInfo *kernel_info;

#if MagickLibVersion >= 0x700
	ExceptionInfo *ex_info = NULL;
	//TODO - inspect exception info
	kernel_info=AcquireKernelInfo(NULL, ex_info);
#else
	kernel_info=AcquireKernelInfo(NULL);
#endif
	if (kernel_info == (KernelInfo *) NULL) {
		return NULL;
	}

	kernel_info->width = order;
	kernel_info->height = order;
#if MagickLibVersion >= 0x700
	{
		unsigned int i;
		kernel_info->values = (MagickRealType *)AcquireAlignedMemory(order, order*sizeof(MagickRealType));
		for (i=0 ; i<order*order ; i++) {
			kernel_info->values[i] = color_matrix[i];
		}
	}
#else
	kernel_info->values = (double *)AcquireAlignedMemory(order, order*sizeof(double));
	memcpy(kernel_info->values, color_matrix, order * order * sizeof(double));
#endif

	return kernel_info;
}


/* {{{ proto bool Imagick::colorMatrixImage(array kernel)
	apply color transformation to an image. The method permits saturation changes, hue rotation, luminance to alpha, and various other effects. Although variable-sized transformation matrices can be used, typically one uses a 5x5 matrix for an RGBA image and a 6x6 for CMYKA (or RGBA with offsets). The matrix is similar to those used by Adobe Flash except offsets are in column 6 rather than 5 (in support of CMYKA images) and offsets are normalized (divide Flash offset by 255).
*/
PHP_METHOD(Imagick, colorMatrixImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	zval *color_matrix_array;
	double *colors;
	size_t order = 0;
	im_long num_elements = 0;
	KernelInfo *kernel_color_matrix;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "a",  &color_matrix_array) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	colors = php_imagick_zval_to_double_array(color_matrix_array, &num_elements TSRMLS_CC);

	if (!colors) {
		php_imagick_throw_exception(IMAGICK_CLASS, "Unable to read color matrix array" TSRMLS_CC);
		return;
	}
	
	if (num_elements == 25) {
		order = 5;
	}
	else if (num_elements == 36) {
		order = 6;
	}
	else {
		efree(colors);
		php_imagick_throw_exception(IMAGICK_CLASS, "Color matrix array must be 5x5 or 6x6" TSRMLS_CC);
		return;
	}

	kernel_color_matrix = php_imagick_getKernelInfo(colors, order);

	//TODO - add check that matrix is 5x5 or 6x6? 
	status = MagickColorMatrixImage(intern->magick_wand, kernel_color_matrix);

	//Free the memory
#if MagickLibVersion >= 0x700
	kernel_color_matrix->values = (MagickRealType *) NULL;
#else
	kernel_color_matrix->values = (double *) NULL;
#endif
	kernel_color_matrix = DestroyKernelInfo(kernel_color_matrix);
	efree(colors);


	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to colormatriximage" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */
#endif

/* {{{ proto bool Imagick::selectiveBlurImage(float radius, float sigma, float threshold[, int channel])
	Selectively blur an image within a contrast threshold. It is similar to the unsharpen mask that sharpens everything with contrast above a certain threshold.
*/
PHP_METHOD(Imagick, selectiveBlurImage)
{
	php_imagick_object *intern;
	double brightness, contrast, threshold;
	MagickBooleanType status;
	im_long channel = IM_DEFAULT_CHANNEL;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ddd|l", &brightness, &contrast, &threshold, &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickSelectiveBlurImageChannel(intern->magick_wand, channel, brightness, contrast, threshold);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to selectiveblurimage" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */



#if MagickLibVersion >= 0x689
/* {{{ proto bool Imagick::rotationalblurimage(float angle[, int channel])
	Rotational blurs an image.
*/
PHP_METHOD(Imagick, rotationalBlurImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	double angle;
	im_long channel = IM_DEFAULT_CHANNEL;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d|l", &angle, &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickRotationalBlurImageChannel(intern->magick_wand, channel, angle);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to rotational blur image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */
#endif

#if MagickLibVersion >= 0x683

//Technically, this version is available in 0x682. However there was an incompatible 
//change to the methods signature in a bug release. So only expose it for stable
//versions.
//
//6.8.2.8 - MagickStatisticImage ( MagickWand* p1, enum ChannelType const p2, enum StatisticType const p3, size_t const p4, size_t const p5 ) (6) 
//6.8.2.9 - MagickStatisticImage ( MagickWand* p1, enum StatisticType const p2, size_t const p3, size_t const p4 )


/* {{{ proto bool Imagick::statisticImage(int type, int width, int height[, int channel] )
	Replace each pixel with corresponding statistic from the neighborhood of the specified width and height.
*/
PHP_METHOD(Imagick, statisticImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	im_long type;
	im_long width, height;
	im_long channel = IM_DEFAULT_CHANNEL;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "lll|l", &type, &width, &height, &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickStatisticImageChannel(intern->magick_wand, channel, type, width, height);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to statisticImage" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

#endif

#if MagickLibVersion >= 0x652
/* {{{ proto Imagick Imagick::subimageMatch(Imagick subimage[, array &$bestMatch[, float &similarity[, float similarity_threshold = 0[, int metric = ]]]])
	Searches for a subimage in the current image and returns a similarity image such that an exact match location is completely white and if none of the pixels match, black, otherwise some gray level in-between.
	You can also pass in the optional parameters bestMatch and similarity. After calling the function similarity will be
	set to the 'score' of the similarity between the subimage and the matching position in the larger image, bestMatch will
	contain an associative array with elements x, y, width, height that describe the matching region.
*/
PHP_METHOD(Imagick, subimageMatch)
{
	php_imagick_object *intern;
	RectangleInfo best_match_offset;
	double similarity;
	double similarity_threshold = 0.0;

	zval *reference_obj;
	php_imagick_object *reference_intern;
	php_imagick_object *intern_return;
	zval *z_similarity = NULL;
	zval *z_best_match_offset = NULL;

	//http://devzone.zend.com/317/extension-writing-part-ii-parameters-arrays-and-zvals/
	MagickWand *new_wand;

	
#if MagickLibVersion >= 0x700
	im_long metric = RootMeanSquaredErrorMetric;
#else
	im_long metric = 0;
#endif

#ifdef ZEND_ENGINE_3
	char *param_string = "O|z/z/dl";
#else
	char *param_string = "O|zzdl";
	
#endif

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, param_string, &reference_obj, php_imagick_sc_entry, &z_best_match_offset, &z_similarity, &similarity_threshold, &metric) == FAILURE) {
		return;
	}
	reference_intern = Z_IMAGICK_P(reference_obj);

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

#if MagickLibVersion >= 0x700
	new_wand = MagickSimilarityImage(intern->magick_wand, reference_intern->magick_wand,
	metric, similarity_threshold,
  &best_match_offset, &similarity);
#else
	new_wand = MagickSimilarityImage(intern->magick_wand, reference_intern->magick_wand, &best_match_offset, &similarity);
#endif

	if (new_wand == NULL) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "subimagematch failed" TSRMLS_CC);
		return;
	}

	if (z_similarity) {
		ZVAL_DOUBLE(z_similarity, similarity);
	}

	if (z_best_match_offset) {
		array_init(z_best_match_offset);
		add_assoc_long(z_best_match_offset, "x", best_match_offset.x);
		add_assoc_long(z_best_match_offset, "y", best_match_offset.y);
		add_assoc_long(z_best_match_offset, "width", best_match_offset.width);
		add_assoc_long(z_best_match_offset, "height", best_match_offset.height);
	}

	object_init_ex(return_value, php_imagick_sc_entry);
	intern_return = Z_IMAGICK_P(return_value);
	php_imagick_replace_magickwand(intern_return, new_wand);

	return;
}
/* }}} */
#endif


/* {{{ proto bool Imagick::setRegistry(string key, string value)
	Sets the ImageMagick registry entry named key to value. This is most
	useful for setting "temporary-path" which controls where ImageMagick
	creates temporary images e.g. while processing PDFs.
*/
PHP_METHOD(Imagick, setRegistry)
{
	MagickBooleanType status;
	char *key, *value;
	IM_LEN_TYPE key_len, value_len;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss", &key, &key_len, &value, &value_len) == FAILURE) {
		return;
	}

	status = SetImageRegistry(StringRegistryType, key, value, NULL);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
/* }}} */


/* {{{ proto string|false Imagick::getRegistry(string key)
	Get the StringRegistry entry for the named key or false if not set.
*/
PHP_METHOD(Imagick, getRegistry)
{
	char *key, *value;
	IM_LEN_TYPE key_len;
	ExceptionInfo *ex_info;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &key, &key_len) == FAILURE) {
		return;
	}

	ex_info = AcquireExceptionInfo();

	value = GetImageRegistry(StringRegistryType, key, ex_info);

	if (ex_info->severity != 0) {
		zend_throw_exception_ex(php_imagick_exception_class_entry, 1 TSRMLS_CC, "Imagick::getRegistry exception (%s) ", ex_info->reason);
		ex_info = DestroyExceptionInfo(ex_info);
		return;
	}

	ex_info = DestroyExceptionInfo(ex_info);

	if (value != NULL) {
		IM_ZVAL_STRING(return_value, value);
		IMAGICK_FREE_MAGICK_MEMORY(value);
		return;
	}

	RETURN_FALSE;
}
/* }}} */


/* {{{ proto array Imagick::listRegistry()
	List all the registry settings calls GetImageRegistry. returns an array of all the key/value pairs in the registry 
*/
PHP_METHOD(Imagick, listRegistry)
{
	char *registry = NULL;
	char *value = NULL;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	array_init(return_value);

	ResetImageRegistryIterator();
	while ((registry = GetNextImageRegistry())) {
		value = GetImageRegistry(StringRegistryType, registry, NULL);
		//should this be add_assoc_string(return_value, estrdup(registry), value, 1);
		IM_add_assoc_string(return_value, registry, value);
		IMAGICK_FREE_MAGICK_MEMORY(value);
	}

	return;
}
/* }}} */

#if MagickLibVersion >= 0x680
/* {{{ proto bool Imagick::morphology(int morphologyMethod, int iterations, kernel, [int CHANNEL]  )
	Applies a user supplied kernel to the image according to the given morphology method.
	iterations - A value of -1 means loop until no change found. How this is applied may depend on the morphology method. Typically this is a value of 1.
*/
PHP_METHOD(Imagick, morphology)
{
	zval *objvar;
	php_imagick_object *intern;
	php_imagickkernel_object *kernel;
	im_long morphologyMethod, iterations;
	MagickBooleanType status;
	im_long channel = IM_DEFAULT_CHANNEL;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "llO|l", &morphologyMethod, &iterations, &objvar, php_imagickkernel_sc_entry, &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	kernel = Z_IMAGICKKERNEL_P(objvar);
	IMAGICK_KERNEL_NOT_NULL_EMPTY(kernel);

	status = MagickMorphologyImageChannel(intern->magick_wand,
			DefaultChannels, morphologyMethod, iterations, kernel->kernel_info);

	// No magick is going to happen
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to morphology image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */
#endif //#if MagickLibVersion >= 0x680

#ifdef IMAGICK_WITH_KERNEL
#if MagickLibVersion < 0x700
/* {{{ proto bool Imagick::filter(ImagickKernel kernel, [int CHANNEL] )
	Applies a custom convolution kernel to the image.
*/
PHP_METHOD(Imagick, filter)
{
	zval *objvar;
	php_imagick_object *intern;
	php_imagickkernel_object *kernel;
	MagickBooleanType status;
	ChannelType channel = UndefinedChannel;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "O|l", &objvar, php_imagickkernel_sc_entry, &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	kernel = Z_IMAGICKKERNEL_P(objvar);

	if ((kernel->kernel_info->width % 2) != 1) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Only odd-sized, square kernels can be applied as a filter." TSRMLS_CC);
		return;
	}

	if (kernel->kernel_info->width != kernel->kernel_info->height) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Only odd-sized, square kernels can be applied as a filter." TSRMLS_CC);
		return;
	}

	if (channel == 0) {
		status = MagickFilterImage(intern->magick_wand, kernel->kernel_info);
	}
	else {
		status = MagickFilterImageChannel(intern->magick_wand, channel, kernel->kernel_info);
	}

	// No magick is going to happen
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Failed to filter image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */
#endif //#if MagickLibVersion < 0x700
#endif // #ifdef IMAGICK_WITH_KERNEL

/* {{{ proto int Imagick::setAntiAlias(bool antialias)
	Set whether antialiasing should be used for operations. On by default.
*/
PHP_METHOD(Imagick, setAntialias)
{
	php_imagick_object *intern;
	zend_bool antialias;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "b", &antialias) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	status = MagickSetAntialias(intern->magick_wand, antialias);

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to setAntiAlias" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool Imagick::getAntiAlias()
	get whether antialiasing would be used for operations.
*/
PHP_METHOD(Imagick, getAntialias)
{
	php_imagick_object *intern;
	MagickBooleanType antialias;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	antialias = MagickGetAntialias(intern->magick_wand);

	if (antialias == MagickTrue) {
		RETURN_TRUE;
	} else {
		RETURN_FALSE;
	}
}
/* }}} */

#if MagickLibVersion > 0x676
/* {{{ proto bool Imagick::colorDecisionListImage(string color_correction_collection)
	Set whether antialiasing should be used for operations. On by default.
*/
PHP_METHOD(Imagick, colorDecisionListImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;

	char *color_correction_collection;
	IM_LEN_TYPE ccc_len;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &color_correction_collection, &ccc_len) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	status = MagickColorDecisionListImage(intern->magick_wand, color_correction_collection);

	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to colorDecisionListImage" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */
#endif

#if MagickLibVersion >= 0x687
/* {{{ proto Imagick Imagick::optimizeimagetransparency()
       Takes a frame optimized GIF animation, and compares the overlayed pixels against the disposal image resulting fr
*/
PHP_METHOD(Imagick, optimizeImageTransparency)
{
	php_imagick_object *intern;
	MagickBooleanType status;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickOptimizeImageTransparency(intern->magick_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Optimize image transparency failed" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */
#endif

#if MagickLibVersion >= 0x660
/* {{{ proto bool Imagick::autoGammaImage([int channel = CHANNEL_ALL])
	Extracts the 'mean' from the image and adjust the image to try make set its gamma appropriately.
*/
PHP_METHOD(Imagick, autoGammaImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	im_long channel = IM_DEFAULT_CHANNEL;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|l", &channel) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickAutoGammaImageChannel(intern->magick_wand, channel);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "autoGammaImage" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */
#endif //#if MagickLibVersion >= 0x660

#if MagickLibVersion >= 0x692
/* {{{ proto bool Imagick::autoOrient()
	Adjusts an image so that its orientation is suitable $ for viewing (i.e. top-left orientation).
*/
PHP_METHOD(Imagick, autoOrient)
{
	php_imagick_object *intern;
	MagickBooleanType status;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickAutoOrientImage(intern->magick_wand);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable autoOrient image" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */
#endif // #if MagickLibVersion >= 0x692

#if MagickLibVersion >= 0x692
/* {{{ proto bool Imagick::compositeImageGravity(Imagick $image, int COMPOSITE_CONSTANT, int GRAVITY_CONSTANT)
	Composite one image onto another using the specified gravity.
*/
PHP_METHOD(Imagick, compositeImageGravity)
{
	zval *objvar;
	php_imagick_object *intern, *image_to_composite;
	MagickBooleanType status;
	im_long composite, gravity;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "Oll", &objvar, php_imagick_sc_entry, &composite, &gravity) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	image_to_composite = Z_IMAGICK_P(objvar);
	if (php_imagick_ensure_not_empty (image_to_composite->magick_wand) == 0)
		return;

	status = MagickCompositeImageGravity(intern->magick_wand, image_to_composite->magick_wand, composite, gravity);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Unable to compositeImageGravity" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */
#endif

#if MagickLibVersion >= 0x693
/* {{{ proto bool Imagick::localContrastImage(float radius, float strength)
Attempts to increase the appearance of large-scale light-dark transitions. 
Local contrast enhancement works similarly to sharpening with an unsharp mask,
however the mask is instead created using an image with a greater blur distance.
*/
PHP_METHOD(Imagick, localContrastImage)
{
	php_imagick_object *intern;
	MagickBooleanType status;
	double radius, strength;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dd", &radius, &strength) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	status = MagickLocalContrastImage(intern->magick_wand, radius, strength);

	/* No magick is going to happen */
	if (status == MagickFalse) {
		php_imagick_convert_imagick_exception(intern->magick_wand, "Failed to localContrastImage" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */
#endif // #if MagickLibVersion >= 0x693


#if MagickLibVersion >= 0x700
/* {{{ proto int Imagick::identifyImageType()
	Identifies the potential image type, returns one of the Imagick::IMGTYPE_* constants
*/
PHP_METHOD(Imagick, identifyImageType)
{
	php_imagick_object *intern;
	long imageType;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(getThis());
	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	imageType = MagickIdentifyImageType(intern->magick_wand);

	RETVAL_LONG(imageType);
}
/* }}} */
#endif // #if MagickLibVersion >= 0x700

/* end of Imagick */
