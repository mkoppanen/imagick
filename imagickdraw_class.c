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

#if MagickLibVersion > 0x628
/* {{{ proto bool ImagickDraw::resetvectorgraphics()
	Resets the vector graphics
*/
PHP_METHOD(ImagickDraw, resetVectorGraphics)
{
	php_imagickdraw_object *internd;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());
	DrawResetVectorGraphics(internd->drawing_wand);
	RETURN_TRUE;
}
/* }}} */
#endif

#if MagickLibVersion > 0x649
/* {{{ proto bool ImagickDraw::getTextKerning()
	Gets the text kerning
*/
PHP_METHOD(ImagickDraw, getTextKerning)
{
	php_imagickdraw_object *internd;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());;
	RETURN_DOUBLE(DrawGetTextKerning(internd->drawing_wand));
}
/* }}} */

/* {{{ proto bool ImagickDraw::setTextKerning(float kerning)
	Sets the text kerning
*/
PHP_METHOD(ImagickDraw, setTextKerning)
{
	php_imagickdraw_object *internd;
	double kerning;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d", &kerning) == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());;
	DrawSetTextKerning(internd->drawing_wand, kerning);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::getTextInterwordSpacing()
	Gets the text interword spacing
*/
PHP_METHOD(ImagickDraw, getTextInterwordSpacing)
{
	php_imagickdraw_object *internd;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());;
	RETURN_DOUBLE(DrawGetTextInterwordSpacing(internd->drawing_wand));
}
/* }}} */

/* {{{ proto bool ImagickDraw::setTextInterwordSpacing(float spacing)
	Sets the text interword spacing
*/
PHP_METHOD(ImagickDraw, setTextInterwordSpacing)
{
	php_imagickdraw_object *internd;
	double spacing;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d", &spacing) == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());;
	DrawSetTextInterwordSpacing(internd->drawing_wand, spacing);
	RETURN_TRUE;
}
/* }}} */
#endif

#if MagickLibVersion > 0x655
/* {{{ proto bool ImagickDraw::getTextInterlineSpacing()
	Gets the text interword spacing
*/
PHP_METHOD(ImagickDraw, getTextInterlineSpacing)
{
	php_imagickdraw_object *internd;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;
	RETURN_DOUBLE(DrawGetTextInterlineSpacing(internd->drawing_wand));
}
/* }}} */

/* {{{ proto bool ImagickDraw::setTextInterlineSpacing(float spacing)
	Sets the text interword spacing
*/
PHP_METHOD(ImagickDraw, setTextInterlineSpacing)
{
	php_imagickdraw_object *internd;
	double spacing;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d", &spacing) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;
	DrawSetTextInterlineSpacing(internd->drawing_wand, spacing);
	RETURN_TRUE;
}
/* }}} */
#endif

/* {{{ proto ImagickDraw ImagickDraw::__construct()
   The ImagickDraw constructor
*/
PHP_METHOD(ImagickDraw, __construct)
{
	/* Empty constructor for possible future uses */

#ifdef ZEND_ENGINE_3
	// This suppresses an 'unused parameter' warning.
	(void)execute_data;
	(void)return_value;
#endif
}
/* }}} */

/* {{{ proto bool ImagickDraw::circle(float ox, float oy, float px, float py)
	Draws a circle on the image.
*/
PHP_METHOD(ImagickDraw, circle)
{
	double ox, oy, px, py;
	php_imagickdraw_object *internd;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dddd", &ox, &oy, &px, &py) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;

	DrawCircle(internd->drawing_wand, ox, oy, px, py);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::rectangle(float x1, float y1, float x2, float y2)
	Draws a rectangle given two coordinates and using the current stroke, stroke width, and fill settings.
*/
PHP_METHOD(ImagickDraw, rectangle)
{
	double x1, y1, x2, y2;
	php_imagickdraw_object *internd;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dddd", &x1, &y1, &x2, &y2) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;
	DrawRectangle(internd->drawing_wand, x1, y1, x2, y2);

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::roundRectangle(float x1, float y1, float x2, float y2, float rx, float ry)
	Draws a rounted rectangle given two coordinates, x & y corner radiuses and using the current stroke, stroke width, and fill settings.
*/
PHP_METHOD(ImagickDraw, roundRectangle)
{
	double x1, y1, x2, y2, rx, ry;
	php_imagickdraw_object *internd;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dddddd", &x1, &y1, &x2, &y2, &rx, &ry) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;

	DrawRoundRectangle(internd->drawing_wand, x1, y1, x2, y2, rx, ry);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::ellipse(float ox, float oy, float rx, float ry, float start, float end)
	Draws an ellipse on the image.
*/
PHP_METHOD(ImagickDraw, ellipse)
{
	double ox, oy, rx, ry, start, end;
	php_imagickdraw_object *internd;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dddddd", &ox, &oy, &rx, &ry, &start, &end) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;

	DrawEllipse(internd->drawing_wand, ox, oy, rx, ry, start, end);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::skewX(float degrees)
	Skews the current coordinate system in the horizontal direction.
*/
PHP_METHOD(ImagickDraw, skewX)
{
	double degrees;
	php_imagickdraw_object *internd;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d", &degrees) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;

	DrawSkewX(internd->drawing_wand, degrees);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::skewY(float degrees)
	Skews the current coordinate system in the vertical direction.
*/
PHP_METHOD(ImagickDraw, skewY)
{
	double degrees;
	php_imagickdraw_object *internd;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d", &degrees) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;

	DrawSkewY(internd->drawing_wand, degrees);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::translate(float x, float y)
	Applies a translation to the current coordinate system which moves the coordinate system origin to the specified coordinate.
*/
PHP_METHOD(ImagickDraw, translate)
{
	double x, y;
	php_imagickdraw_object *internd;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dd", &x, &y) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;

	DrawTranslate(internd->drawing_wand, x, y);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::setFillColor(PixelWand fill_wand)
	Sets the fill color to be used for drawing filled objects.
*/
PHP_METHOD(ImagickDraw, setFillColor)
{
	zval *param;
	php_imagickdraw_object *internd;
	PixelWand *color_wand;
	zend_bool allocated;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &param) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;

	color_wand = php_imagick_zval_to_pixelwand(param, IMAGICKDRAW_CLASS, &allocated TSRMLS_CC);
	if (!color_wand)
		return;

	DrawSetFillColor(internd->drawing_wand, color_wand);
	if (allocated)
		color_wand = DestroyPixelWand (color_wand);

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::setResolution(float x, float y)
	Sets the resolution
*/
PHP_METHOD(ImagickDraw, setResolution)
{
	char *density, *buf = NULL;
	double x, y;
	php_imagickdraw_object *internd;
	DrawInfo *draw_info;
	DrawingWand *d_wand;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dd", &x, &y) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());

	spprintf(&buf, 512, "%fx%f", x, y);
	density = AcquireString(buf);
	efree (buf);

	if (!density) {
		php_imagick_throw_exception(IMAGICKDRAW_CLASS, "Failed to allocate memory" TSRMLS_CC);
		return;
	}

	draw_info          = PeekDrawingWand(internd->drawing_wand);
	draw_info->density = density;


#if MagickLibVersion >= 0x693
	d_wand = AcquireDrawingWand(draw_info, NULL);
#else
	d_wand = (DrawingWand *) DrawAllocateWand(draw_info, NULL);
#endif

	if (!d_wand) {
		php_imagick_throw_exception(IMAGICKDRAW_CLASS, "Failed to allocate new DrawingWand structure" TSRMLS_CC);
		return;
	}

	php_imagick_replace_drawingwand(internd, d_wand);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::setStrokeColor(PixelWand stroke_wand)
	Sets the color used for stroking object outlines.
*/
PHP_METHOD(ImagickDraw, setStrokeColor)
{
	zval *param;
	php_imagickdraw_object *internd;
	PixelWand *color_wand;
	zend_bool allocated;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &param) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;

	color_wand = php_imagick_zval_to_pixelwand (param, IMAGICKDRAW_CLASS, &allocated TSRMLS_CC);
	if (!color_wand)
		return;

	DrawSetStrokeColor(internd->drawing_wand, color_wand);
	if (allocated)
		color_wand = DestroyPixelWand (color_wand);

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::setFillAlpha(float opacity)
	Sets the opacity to use when drawing using the fill color or fill texture. Fully opaque is 1.0.
*/
PHP_METHOD(ImagickDraw, setFillAlpha)
{
	php_imagickdraw_object *internd;
	double opacity;

	IMAGICK_METHOD_DEPRECATED("ImagickDraw", "setFillAlpha");

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d", &opacity) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;

#if MagickLibVersion >= 0x635
	DrawSetFillOpacity(internd->drawing_wand, opacity);
#else
	DrawSetFillAlpha(internd->drawing_wand, opacity);
#endif
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::settextantialias()
	Returns the antialias property associated with the wand.
*/
PHP_METHOD(ImagickDraw, setTextAntialias)
{
	php_imagickdraw_object *internd;
	zend_bool antialias;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "b", &antialias) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;

	DrawSetTextAntialias(internd->drawing_wand, antialias);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::setTextEncoding(string encoding)
	Specifies specifies the code set to use for text annotations.
	The only character encoding which may be specified at this time is "UTF-8" for representing Unicode as a sequence of bytes.
	Specify an empty string to set text encoding to the system's default. 
	Successful text annotation using Unicode may require fonts designed to support Unicode.
*/
PHP_METHOD(ImagickDraw, setTextEncoding)
{
	php_imagickdraw_object *internd;
	char *encoding;
	IM_LEN_TYPE encoding_len;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &encoding, &encoding_len) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;

	DrawSetTextEncoding(internd->drawing_wand, encoding);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::setStrokeAlpha(float opacity)
	Specifies the opacity of stroked object outlines.
*/
PHP_METHOD(ImagickDraw, setStrokeAlpha)
{
	php_imagickdraw_object *internd;
	double opacity;

	IMAGICK_METHOD_DEPRECATED("ImagickDraw", "setStrokeAlpha");

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d", &opacity) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;

#if MagickLibVersion >= 0x635
	DrawSetStrokeOpacity(internd->drawing_wand, opacity);
#else
	DrawSetStrokeAlpha(internd->drawing_wand, opacity);
#endif
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::setStrokeWidth(float stroke_width)
	Sets the width of the stroke used to draw object outlines.
*/
PHP_METHOD(ImagickDraw, setStrokeWidth)
{
	php_imagickdraw_object *internd;
	double width;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d", &width) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;

	DrawSetStrokeWidth(internd->drawing_wand, width);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::setFont(string font_name)
	Sets the fully-sepecified font to use when annotating with text.
*/
PHP_METHOD(ImagickDraw, setFont)
{
	php_imagickdraw_object *internd;
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
		php_imagick_throw_exception (IMAGICKDRAW_CLASS, "Can not set empty font" TSRMLS_CC);
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;

	/* And if it wasn't */
	if (!php_imagick_check_font(font, font_len TSRMLS_CC)) {

		if ((absolute = expand_filepath(font, NULL TSRMLS_CC)) == NULL) {
			php_imagick_throw_exception (IMAGICKDRAW_CLASS, "Unable to set font, file path expansion failed" TSRMLS_CC);
			return;
		}

		/* Do an access check for the font */
		if ((rc = php_imagick_file_access_check (absolute TSRMLS_CC)) != IMAGICK_RW_OK) {
			// Failed
			php_imagick_imagickdraw_rw_fail_to_exception (internd->drawing_wand, rc, absolute TSRMLS_CC);
			efree(absolute);
			return;
		}
		status = DrawSetFont(internd->drawing_wand, absolute);
		efree(absolute);

	} else {
		status = DrawSetFont(internd->drawing_wand, font);
	}

	if (status == MagickFalse) {
		php_imagick_convert_imagickdraw_exception (internd->drawing_wand, "Unable to set font" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::setFontFamily(string font_family)
	Sets the font family to use when annotating with text.
*/
PHP_METHOD(ImagickDraw, setFontFamily)
{
	php_imagickdraw_object *internd;
	char *font_family;
	IM_LEN_TYPE font_family_len;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &font_family, &font_family_len) == FAILURE) {
		return;
	}

	/* Check that no empty string is passed */
	if (font_family_len == 0) {
		php_imagick_throw_exception(IMAGICKDRAW_CLASS, "Can not set empty font family" TSRMLS_CC);
		return;
	}

	if (!php_imagick_check_font(font_family, font_family_len TSRMLS_CC )) {
		php_imagick_throw_exception(IMAGICKDRAW_CLASS, "Unable to set font family; parameter not found in the list of configured fonts" TSRMLS_CC);
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;
	status = DrawSetFontFamily(internd->drawing_wand, font_family);

	if (status == MagickFalse) {
		php_imagick_convert_imagickdraw_exception (internd->drawing_wand, "Unable to set font family" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::setFontSize(float pointsize)
	Sets the font pointsize to use when annotating with text.
*/
PHP_METHOD(ImagickDraw, setFontSize)
{
	php_imagickdraw_object *internd;
	double font_size;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d", &font_size) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;

	DrawSetFontSize(internd->drawing_wand, font_size);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::setFontStyle(int style)
	Sets the font style to use when annotating with text. The AnyStyle enumeration acts as a wild-card "don't care" option.
*/
PHP_METHOD(ImagickDraw, setFontStyle)
{
	php_imagickdraw_object *internd;
	im_long style_id = AnyStyle;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &style_id) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;

	DrawSetFontStyle(internd->drawing_wand, style_id);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::setFontWeight(int font_weight)
	Sets the font weight to use when annotating with text.
*/
PHP_METHOD(ImagickDraw, setFontWeight)
{
	php_imagickdraw_object *internd;
	im_long weight;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &weight) == FAILURE) {
		return;
	}

	if (weight >= 100 && weight <= 900) {
		internd = Z_IMAGICKDRAW_P(getThis());;
		DrawSetFontWeight(internd->drawing_wand, weight);
		RETURN_TRUE;
	}
	php_imagick_throw_exception(IMAGICKDRAW_CLASS, "Font weight valid range is 100-900" TSRMLS_CC);
	return;
}
/* }}} */

/* {{{ proto int ImagickDraw::getFontStretch(int fontStretch)
	Gets the font stretch to use when annotating with text
*/
PHP_METHOD(ImagickDraw, getFontStretch)
{
	php_imagickdraw_object *internd;

	internd = Z_IMAGICKDRAW_P(getThis());;
	RETVAL_LONG(DrawGetFontStretch(internd->drawing_wand));
}
/* }}} */

/* {{{ proto bool ImagickDraw::setFontStretch(int fontStretch)
	Sets the font stretch to use when annotating with text. The AnyStretch enumeration acts as a wild-card "don't care" option.
*/
PHP_METHOD(ImagickDraw, setFontStretch)
{
	php_imagickdraw_object *internd;
	im_long stretch;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &stretch) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;

	DrawSetFontStretch(internd->drawing_wand, stretch);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::setStrokeAntialias(bool stroke_antialias)
	Controls whether stroked outlines are antialiased. Stroked outlines are antialiased by default.  When antialiasing is disabled stroked pixels are thresholded to determine if the stroke color or underlying canvas color should be used.
*/
PHP_METHOD(ImagickDraw, setStrokeAntialias)
{
	php_imagickdraw_object *internd;
	zend_bool antialias;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "b", &antialias) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;

	DrawSetStrokeAntialias(internd->drawing_wand, antialias);
	RETURN_TRUE;

}
/* }}} */

/* {{{ proto bool ImagickDraw::setTextAlignment(int alignment)
	Specifies a text alignment to be applied when annotating with text.
*/
PHP_METHOD(ImagickDraw, setTextAlignment)
{
	php_imagickdraw_object *internd;
	im_long align;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &align) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;

	DrawSetTextAlignment(internd->drawing_wand, align);
	RETURN_TRUE;

}
/* }}} */

/* {{{ proto bool ImagickDraw::setTextDecoration(int decoration)
	Specifies a decoration to be applied when annotating with text.
*/
PHP_METHOD(ImagickDraw, setTextDecoration)
{
	php_imagickdraw_object *internd;
	im_long decoration;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &decoration) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;

	DrawSetTextDecoration(internd->drawing_wand, decoration);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::setTextUnderColor(PixelWand under_wand)
	Specifies the color of a background rectangle to place under text annotations.
*/
PHP_METHOD(ImagickDraw, setTextUnderColor)
{
	zval *param;
	php_imagickdraw_object *internd;
	PixelWand *color_wand;
	zend_bool allocated;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &param) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;

	color_wand = php_imagick_zval_to_pixelwand (param, IMAGICKDRAW_CLASS, &allocated TSRMLS_CC);
	if (!color_wand)
		return;

	DrawSetTextUnderColor(internd->drawing_wand, color_wand);
	if (allocated)
		color_wand = DestroyPixelWand (color_wand);

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::setViewbox(float x1, float y1, float x2, float y2 )
	Sets the overall canvas size to be recorded with the drawing vector data. Usually this will be specified using the same size as the canvas image. When the vector data is saved to SVG or MVG formats, the viewbox is use to specify the size of the canvas image that a viewer will render the vector data on.
*/
PHP_METHOD(ImagickDraw, setViewbox)
{
	php_imagickdraw_object *internd;
	im_long x1, y1, x2, y2;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "llll", &x1, &y1, &x2, &y2) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;

	DrawSetViewbox(internd->drawing_wand, x1, y1, x2, y2);
	RETURN_TRUE;
}

/* {{{ proto string ImagickDraw::getFont()
	Returns a string specifying the font used when annotating with text
*/
PHP_METHOD(ImagickDraw, getFont)
{
	php_imagickdraw_object *internd;
	char *font;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;

	font = DrawGetFont(internd->drawing_wand);
	
	if (!font) {
		RETURN_FALSE;
	} else {
		IM_ZVAL_STRING(return_value, font);
		IMAGICK_FREE_MAGICK_MEMORY(font);
		return;
	}
}
/* }}} */

/* {{{ proto string ImagickDraw::getFontFamily()
	Returns the font family to use when annotating with text. The value returned must be freed by the user when it is no longer needed.
*/
PHP_METHOD(ImagickDraw, getFontFamily)
{
	php_imagickdraw_object *internd;
	char *font_family;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;

	font_family = DrawGetFontFamily(internd->drawing_wand);
	if (!font_family) {
		RETURN_FALSE;
	} else {
		IM_ZVAL_STRING(return_value, font_family);
		IMAGICK_FREE_MAGICK_MEMORY(font_family);
		return;
	}
}
/* }}} */

/* {{{ proto float ImagickDraw::getFontSize()
	Returns the font pointsize used when annotating with text.
*/
PHP_METHOD(ImagickDraw, getFontSize)
{
	php_imagickdraw_object *internd;
	double font_size;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());

	font_size = DrawGetFontSize(internd->drawing_wand);
	ZVAL_DOUBLE(return_value, font_size);
	return;
}
/* }}} */

/* {{{ proto int ImagickDraw::getFontStyle()
	Returns the font style used when annotating with text.
*/
PHP_METHOD(ImagickDraw, getFontStyle)
{
	php_imagickdraw_object *internd;
	long font_style;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());

	font_style = DrawGetFontStyle(internd->drawing_wand);
	ZVAL_LONG(return_value, font_style);
	return;
}
/* }}} */

/* {{{ proto int ImagickDraw::getFontWeight()
	Returns the font weight used when annotating with text.
*/
PHP_METHOD(ImagickDraw, getFontWeight)
{
	php_imagickdraw_object *internd;
	long weight;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;

	weight = DrawGetFontWeight(internd->drawing_wand);
	ZVAL_LONG(return_value, weight);
	return;
}
/* }}} */

/* {{{ proto bool ImagickDraw::clear()
	Clears a DrawingWand resource of any accumulated commands, and resets the settings it contains to their defaults.
*/
PHP_METHOD(ImagickDraw, clear)
{
	php_imagickdraw_object *internd;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;
	ClearDrawingWand(internd->drawing_wand);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto int ImagickDraw::getTextDecoration()
	Returns the decoration applied when annotating with text.
*/
PHP_METHOD(ImagickDraw, getTextDecoration)
{
	php_imagickdraw_object *internd;
	long decoration;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;

	decoration = DrawGetTextDecoration(internd->drawing_wand);
	ZVAL_LONG(return_value, decoration);
	return;
}
/* }}} */

/* {{{ proto string ImagickDraw::getTextEncoding()
	Returns a null-terminated string which specifies the code set used for text annotations. The string must be freed by the user once it is no longer required.
*/
PHP_METHOD(ImagickDraw, getTextEncoding)
{
	php_imagickdraw_object *internd;
	char *encoding;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;
	encoding = DrawGetTextEncoding(internd->drawing_wand);

	if (!encoding) {
		RETURN_FALSE;
	} else {
		IM_ZVAL_STRING(return_value, encoding);
		IMAGICK_FREE_MAGICK_MEMORY(encoding);
		return;
	}
}
/* }}} */

/* {{{ proto bool ImagickDraw::annotation(float x, float y, string *text)
	Draws text on the image.
*/
PHP_METHOD(ImagickDraw, annotation)
{
	php_imagickdraw_object *internd;
	double x, y;
	unsigned char *text;
	IM_LEN_TYPE text_len;
#if MagickLibVersion < 0x632
	char *font;
#endif

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dds", &x, &y, &text, &text_len) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;
#if MagickLibVersion < 0x632
	font = DrawGetFont(internd->drawing_wand);

	/* Fixes PECL Bug #11328 */
	if (!font) {
		php_imagick_throw_exception(IMAGICKDRAW_CLASS, "Font needs to be set before annotating an image" TSRMLS_CC);
		return;
	}
#endif

	DrawAnnotation(internd->drawing_wand, x, y, text);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::arc(float sx, float sy, float ex, float ey, float sd, float ed)
	Draws an arc falling within a specified bounding rectangle on the image.
*/
PHP_METHOD(ImagickDraw, arc)
{
	double sx, sy, ex, ey, sd, ed;
	php_imagickdraw_object *internd;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dddddd", &sx, &sy, &ex, &ey, &sd, &ed) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;

	DrawArc(internd->drawing_wand, sx, sy, ex, ey, sd, ed);
	RETURN_TRUE;
}
/* }}} */


#if MagickLibVersion < 0x700
/* {{{ proto bool ImagickDraw::matte(float x, float y, int paintMethod)
	Paints on the image's opacity channel in order to set effected pixels to transparent. to influence the opacity of pixels. The available paint methods are:
*/
PHP_METHOD(ImagickDraw, matte)
{
	double x, y;
	php_imagickdraw_object *internd;
	im_long paint_method;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ddl", &x, &y, &paint_method) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;

	DrawMatte(internd->drawing_wand, x, y, paint_method);
	RETURN_TRUE;
}
/* }}} */

#else

/* {{{ proto bool ImagickDraw::alpha(float x, float y, int paintMethod)
	Paints on the image's alpha channel in order to set effected pixels to transparent. to influence the alpha of pixels. The available paint methods are:
    PointMethod: Select the target pixel
    ReplaceMethod: Select any pixel that matches the target pixel.
    FloodfillMethod: Select the target pixel and matching neighbors.
    FillToBorderMethod: Select the target pixel and neighbors not matching
border color.
    ResetMethod: Select all pixels.
*/
PHP_METHOD(ImagickDraw, alpha)
{
	double x, y;
	php_imagickdraw_object *internd;
	im_long paint_method;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ddl", &x, &y, &paint_method) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;

	DrawAlpha(internd->drawing_wand, x, y, paint_method);
	RETURN_TRUE;
}
/* }}} */

#endif


/* {{{ proto bool ImagickDraw::polygon(array coordinates)
	Draws a polygon using the current stroke, stroke width, and fill color or texture, using the specified array of coordinates.
*/
PHP_METHOD(ImagickDraw, polygon)
{
	zval *coordinate_array;
	php_imagickdraw_object *internd;
	PointInfo *coordinates;
	int num_elements = 0;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "a", &coordinate_array) == FAILURE) {
		return;
	}

	coordinates = php_imagick_zval_to_pointinfo_array(coordinate_array, &num_elements TSRMLS_CC);

	if (!coordinates) {
		php_imagick_throw_exception(IMAGICKDRAW_CLASS, "Unable to read coordinate array" TSRMLS_CC);
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;
	DrawPolygon(internd->drawing_wand, num_elements, coordinates);

	efree(coordinates);

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::bezier(array coordinates)
	Draws a bezier curve through a set of points on the image.
*/
PHP_METHOD(ImagickDraw, bezier)
{
	zval *coordinate_array;
	php_imagickdraw_object *internd;
	PointInfo *coordinates;
	int num_elements = 0;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "a", &coordinate_array) == FAILURE) {
		return;
	}

	coordinates = php_imagick_zval_to_pointinfo_array(coordinate_array, &num_elements TSRMLS_CC);

	if (!coordinates) {
		php_imagick_throw_exception(IMAGICKDRAW_CLASS, "Unable to read coordinate array" TSRMLS_CC);
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;
	DrawBezier(internd->drawing_wand, num_elements, coordinates);

	efree(coordinates);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::point(float x, float y)
	Draws a point using the current stroke color and stroke thickness at the specified coordinates.
*/
PHP_METHOD(ImagickDraw, point)
{
	php_imagickdraw_object *internd;
	double x, y;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dd", &x, &y) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;
	DrawPoint(internd->drawing_wand, x, y);

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::line(float sx, float sy, float ex, float ey)
	Draws a line on the image using the current stroke color, stroke opacity, and stroke width.
*/
PHP_METHOD(ImagickDraw, line)
{
	php_imagickdraw_object *internd;
	double sx, sy, ex, ey;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dddd", &sx, &sy, &ex, &ey) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;

	DrawLine(internd->drawing_wand, sx, sy, ex, ey);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto ImagickDraw ImagickDraw::clone()
	Makes an exact copy of the specified wand.
*/
PHP_METHOD(ImagickDraw, clone)
{
	php_imagickdraw_object *internd, *intern_return;
	DrawingWand *tmp_wand;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	IMAGICK_METHOD_DEPRECATED("ImagickDraw", "clone");

	internd = Z_IMAGICKDRAW_P(getThis());;
	tmp_wand = CloneDrawingWand(internd->drawing_wand);

	if (!tmp_wand) {
		php_imagick_throw_exception (IMAGICK_CLASS, "Failed to allocate DrawingWand structure" TSRMLS_CC);
		return;
	}

	object_init_ex(return_value, php_imagickdraw_sc_entry);
	intern_return = Z_IMAGICKDRAW_P(return_value);
	php_imagick_replace_drawingwand(intern_return, tmp_wand);

	return;
}
/* }}} */

/* {{{ proto bool ImagickDraw::affine(array affine)
	Adjusts the current affine transformation matrix with the specified affine transformation matrix. Note that the current affine transform is adjusted rather than replaced.
*/
PHP_METHOD(ImagickDraw, affine)
{
	php_imagickdraw_object *internd;
	zval *affine_matrix;

#ifdef ZEND_ENGINE_3
	zval *pzval;
#else
	HashTable *affine;
	zval **ppzval;
#endif
	char *matrix_elements[] = { "sx", "rx", "ry",
						        "sy", "tx", "ty" };
	int i;
	double value;
	AffineMatrix matrix;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "a", &affine_matrix) == FAILURE) {
		return;
	}

#ifndef ZEND_ENGINE_3
	affine = Z_ARRVAL_P(affine_matrix);
	zend_hash_internal_pointer_reset_ex(affine, (HashPosition *) 0);
#endif


	for (i = 0; i < 6 ; i++) {
#ifdef ZEND_ENGINE_3
		pzval = zend_hash_str_find(HASH_OF(affine_matrix), matrix_elements[i], 2);
		ZVAL_DEREF(pzval);
		if (pzval == NULL) {
			php_imagick_throw_exception(IMAGICKDRAW_CLASS, "AffineMatrix must contain keys: sx, rx, ry, sy, tx and ty" TSRMLS_CC);
			return;
#else
		if (zend_hash_find(affine, matrix_elements[i], 3, (void**)&ppzval) == FAILURE) {
			php_imagick_throw_exception(IMAGICKDRAW_CLASS, "AffineMatrix must contain keys: sx, rx, ry, sy, tx and ty" TSRMLS_CC);
			return;
#endif
		} else {
		
#ifdef ZEND_ENGINE_3
			value = zval_get_double(pzval);
#else
			zval tmp_zval, *tmp_pzval;

			tmp_zval = **ppzval;
			zval_copy_ctor(&tmp_zval);
			tmp_pzval = &tmp_zval;
			convert_to_double(tmp_pzval);
			value = Z_DVAL(tmp_zval);
#endif
			if (strcmp(matrix_elements[i], "sx") == 0) {
				matrix.sx = value;
			} else if (strcmp(matrix_elements[i], "rx") == 0) {
				matrix.rx = value;
			} else if (strcmp(matrix_elements[i], "ry") == 0) {
				matrix.ry = value;
			} else if (strcmp(matrix_elements[i], "sy") == 0) {
				matrix.sy = value;
			} else if (strcmp(matrix_elements[i], "tx") == 0) {
				matrix.tx = value;
			} else if (strcmp(matrix_elements[i], "ty") == 0) {
				matrix.ty = value;
			}
		}
	}

	internd = Z_IMAGICKDRAW_P(getThis());

	DrawAffine(internd->drawing_wand, &matrix);

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::composite(int compose, float x, float y, float width, float height, MagickWand magick_wand)
	Composites an image onto the current image, using the specified composition operator, specified position, and at the specified size.
*/
PHP_METHOD(ImagickDraw, composite)
{
	php_imagickdraw_object *internd;
	php_imagick_object *intern;
	zval *magick_obj;
	im_long compose;
	double x, y, width, height;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "lddddO", &compose, &x, &y, &width, &height, &magick_obj, php_imagick_sc_entry) == FAILURE) {
		return;
	}

	intern = Z_IMAGICK_P(magick_obj);

	if (php_imagick_ensure_not_empty (intern->magick_wand) == 0)
		return;

	internd = Z_IMAGICKDRAW_P(getThis());
	status = DrawComposite(internd->drawing_wand, compose, x, y, width, height, intern->magick_wand);

	if (status == MagickFalse) {
		php_imagick_convert_imagickdraw_exception (internd->drawing_wand, "Compositing image failed" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::color(float x, float y, int paintMethod)
	Draws color on image using the current fill color, starting at specified position, and using specified paint method. The available paint methods are:
*/
PHP_METHOD(ImagickDraw, color)
{
	php_imagickdraw_object *internd;
	double x, y;
	im_long paint_method;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ddl", &x, &y, &paint_method) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());

	DrawColor(internd->drawing_wand, x, y, paint_method);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::comment(string comment)
	Adds a comment to a vector output stream.
*/
PHP_METHOD(ImagickDraw, comment)
{
	php_imagickdraw_object *internd;
	char *comment;
	IM_LEN_TYPE comment_len;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &comment, &comment_len) == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());

	DrawComment(internd->drawing_wand, comment);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto string ImagickDraw::getClipPath()
	Obtains the current clipping path ID. The value returned must be deallocated by the user when it is no longer needed.
*/
PHP_METHOD(ImagickDraw, getClipPath)
{
	php_imagickdraw_object *internd;
	char *clip_path;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());;
	clip_path = DrawGetClipPath(internd->drawing_wand);

	if (!clip_path) {
		RETURN_FALSE;
	} else {
		IM_ZVAL_STRING(return_value, clip_path);
		IMAGICK_FREE_MAGICK_MEMORY(clip_path);
		return;
	}
}
/* }}} */

/* {{{ proto int ImagickDraw::getClipRule()
	Returns the current polygon fill rule to be used by the clipping path.
*/
PHP_METHOD(ImagickDraw, getClipRule)
{
	php_imagickdraw_object *internd;
	long clip_rule;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());;
	clip_rule = DrawGetClipRule(internd->drawing_wand);

	RETVAL_LONG(clip_rule);
}
/* }}} */

/* {{{ proto int ImagickDraw::getClipUnits()
	Returns the interpretation of clip path units.
*/
PHP_METHOD(ImagickDraw, getClipUnits)
{
	php_imagickdraw_object *internd;
	long units;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());;
	units = DrawGetClipUnits(internd->drawing_wand);

	RETVAL_LONG(units);
}
/* }}} */

/* {{{ proto ImagickPixel ImagickDraw::getFillColor()
	Returns the fill color used for drawing filled objects.
*/
PHP_METHOD(ImagickDraw, getFillColor)
{
	php_imagickpixel_object *internp;
	php_imagickdraw_object *internd;
	PixelWand *tmp_wand;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());;

	tmp_wand = NewPixelWand();
	DrawGetFillColor(internd->drawing_wand, tmp_wand);

	object_init_ex(return_value, php_imagickpixel_sc_entry);
	internp = Z_IMAGICKPIXEL_P(return_value);
	php_imagick_replace_pixelwand(internp, tmp_wand);

	return;
}
/* }}} */

/* {{{ proto float ImagickDraw::getFillOpacity()
	Returns the opacity used when drawing using the fill color or fill texture.  Fully opaque is 1.0.
*/
PHP_METHOD(ImagickDraw, getFillOpacity)
{
	php_imagickdraw_object *internd;
	double opacity;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());;
	opacity = DrawGetFillOpacity(internd->drawing_wand);

	RETVAL_DOUBLE(opacity);
}
/* }}} */

/* {{{ proto int ImagickDraw::getFillRule(const DrawingWand *wand)
	Returns the fill rule used while drawing polygons.
*/
PHP_METHOD(ImagickDraw, getFillRule)
{
	php_imagickdraw_object *internd;
	long fill_rule;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());;
	fill_rule = DrawGetFillRule(internd->drawing_wand);

	RETVAL_LONG(fill_rule);
}
/* }}} */

/* {{{ proto int ImagickDraw::getGravity()
	Returns the text placement gravity used when annotating with text.
*/
PHP_METHOD(ImagickDraw, getGravity)
{
	php_imagickdraw_object *internd;
	long gravity;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;
	gravity = DrawGetGravity(internd->drawing_wand);

	RETVAL_LONG(gravity);
}
/* }}} */

/* {{{ proto bool ImagickDraw::getStrokeAntialias()
	Returns the current stroke antialias setting. Stroked outlines are antialiased by default.  When antialiasing is disabled stroked pixels are thresholded to determine if the stroke color or underlying canvas color should be used.
*/
PHP_METHOD(ImagickDraw, getStrokeAntialias)
{
	php_imagickdraw_object *internd;
	MagickBooleanType status;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());;
	status = DrawGetStrokeAntialias(internd->drawing_wand);

	if (status == MagickFalse) {
		RETURN_FALSE;
	} else {
		RETURN_TRUE;
	}
}
/* }}} */

/* {{{ proto ImagickPixel ImagickDraw::getStrokeColor(PixelWand stroke_color)
	Returns the color used for stroking object outlines.
*/
PHP_METHOD(ImagickDraw, getStrokeColor)
{
	php_imagickpixel_object *internp;
	php_imagickdraw_object *internd;
	PixelWand *tmp_wand;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());;

	tmp_wand = NewPixelWand();
	DrawGetStrokeColor(internd->drawing_wand, tmp_wand);

	object_init_ex(return_value, php_imagickpixel_sc_entry);
	internp = Z_IMAGICKPIXEL_P(return_value);
	php_imagick_replace_pixelwand(internp, tmp_wand);

	return;
}
/* }}} */

/* {{{ proto array ImagickDraw::getStrokeDashArray()
	Returns an array representing the pattern of dashes and gaps used to stroke paths (see DrawSetStrokeDashArray). The array must be freed once it is no longer required by the user.
*/
PHP_METHOD(ImagickDraw, getStrokeDashArray)
{
	php_imagickdraw_object *internd;
	double *stroke_array;
	unsigned long i;
	size_t num_elements;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());;

	stroke_array = DrawGetStrokeDashArray(internd->drawing_wand, &num_elements);
	array_init(return_value);

	for (i = 0; i < num_elements ; i++) {
		add_next_index_double(return_value, stroke_array[i]);
	}

	IMAGICK_FREE_MAGICK_MEMORY(stroke_array);
	return;
}
/* }}} */

/* {{{ proto bool ImagickDraw::setStrokeDashArray(array dashArray)
	Specifies the pattern of dashes and gaps used to stroke paths. The strokeDashArray represents an array of numbers that specify the lengths of alternating dashes and gaps in pixels. If an odd number of values is provided, then the list of values is repeated to yield an even number of values. To remove an existing dash array, pass a zero number_elements argument and null dash_array. A typical strokeDashArray_ array might contain the members 5 3 2.
*/
PHP_METHOD(ImagickDraw, setStrokeDashArray)
{
	zval *param_array;
	double *double_array;
	im_long elements;
	php_imagickdraw_object *internd;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "a", &param_array) == FAILURE) {
		return;
	}

	double_array = php_imagick_zval_to_double_array(param_array, &elements TSRMLS_CC);

	if (!double_array) {
		php_imagick_throw_exception(IMAGICKDRAW_CLASS, "Cannot read stroke dash array parameter" TSRMLS_CC);
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());

	DrawSetStrokeDashArray(internd->drawing_wand, elements, double_array);
	efree(double_array);

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto float ImagickDraw::getStrokeDashOffset()
	Returns the offset into the dash pattern to start the dash.
*/
PHP_METHOD(ImagickDraw, getStrokeDashOffset)
{
	php_imagickdraw_object *internd;
	double offset;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());;
	offset = DrawGetStrokeDashOffset(internd->drawing_wand);

	RETVAL_DOUBLE(offset);
}
/* }}} */

/* {{{ proto int ImagickDraw::getStrokeLineCap()
	Returns the shape to be used at the end of open subpaths when they are stroked. Values of LineCap are UndefinedCap, ButtCap, RoundCap, and SquareCap.
*/
PHP_METHOD(ImagickDraw, getStrokeLineCap)
{
	php_imagickdraw_object *internd;
	long line_cap;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());;
	line_cap = DrawGetStrokeLineCap(internd->drawing_wand);

	RETVAL_LONG(line_cap);
}
/* }}} */

/* {{{ proto int ImagickDraw::getStrokeLineJoin()
	Returns the shape to be used at the corners of paths (or other vector shapes) when they are stroked. Values of LineJoin are UndefinedJoin, MiterJoin, RoundJoin, and BevelJoin.
*/
PHP_METHOD(ImagickDraw, getStrokeLineJoin)
{
	php_imagickdraw_object *internd;
	long line_join;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());;
	line_join = DrawGetStrokeLineJoin(internd->drawing_wand);

	RETVAL_LONG(line_join);
}
/* }}} */

/* {{{ proto int ImagickDraw::getStrokeMiterLimit()
	Returns the miter limit. When two line segments meet at a sharp angle and miter joins have been specified for 'lineJoin', it is possible for the miter to extend far beyond the thickness of the line stroking the path. The miterLimit' imposes a limit on the ratio of the miter length to the 'lineWidth'.
*/
PHP_METHOD(ImagickDraw, getStrokeMiterLimit)
{
	php_imagickdraw_object *internd;
	unsigned long miter_limit;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());;
	miter_limit = DrawGetStrokeMiterLimit(internd->drawing_wand);

	RETVAL_LONG(miter_limit);
}
/* }}} */

/* {{{ proto float ImagickDraw::getStrokeOpacity()
	Returns the opacity of stroked object outlines.
*/
PHP_METHOD(ImagickDraw, getStrokeOpacity)
{
	php_imagickdraw_object *internd;
	double opacity;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());;
	opacity = DrawGetStrokeOpacity(internd->drawing_wand);

	RETVAL_DOUBLE(opacity);
}
/* }}} */

/* {{{ proto float ImagickDraw::getStrokeWidth()
	Returns the width of the stroke used to draw object outlines.
*/
PHP_METHOD(ImagickDraw, getStrokeWidth)
{
	php_imagickdraw_object *internd;
	double width;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());;
	width = DrawGetStrokeWidth(internd->drawing_wand);

	RETVAL_DOUBLE(width);
}
/* }}} */

/* {{{ proto int ImagickDraw::getTextAlignment()
	Returns the alignment applied when annotating with text.
*/
PHP_METHOD(ImagickDraw, getTextAlignment)
{
	php_imagickdraw_object *internd;
	long align_type;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());;
	align_type = DrawGetTextAlignment(internd->drawing_wand);

	RETVAL_LONG(align_type);
}
/* }}} */

/* {{{ proto bool ImagickDraw::getTextAntialias()
	Returns the current text antialias setting, which determines whether text is antialiased.  Text is antialiased by default.
*/
PHP_METHOD(ImagickDraw, getTextAntialias)
{
	php_imagickdraw_object *internd;
	MagickBooleanType status;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());;
	status = DrawGetTextAntialias(internd->drawing_wand);

	if (status == MagickFalse) {
		RETURN_FALSE;
	} else {
		RETURN_TRUE;
	}
}
/* }}} */

/* {{{ proto string ImagickDraw::getVectorGraphics()
	Returns a null-terminated string which specifies the vector graphics generated by any graphics calls made since the wand was instantiated.  The string must be freed by the user once it is no longer required.
*/
PHP_METHOD(ImagickDraw, getVectorGraphics)
{
	php_imagickdraw_object *internd;
	char *vector;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());;
	vector = DrawGetVectorGraphics(internd->drawing_wand);

	IM_ZVAL_STRING(return_value, vector);
	IMAGICK_FREE_MAGICK_MEMORY(vector);

	return;
}
/* }}} */

/* {{{ proto ImagickPixel ImagickDraw::getTextUnderColor(PixelWand under_color)
	Returns the color of a background rectangle to place under text annotations.
*/
PHP_METHOD(ImagickDraw, getTextUnderColor)
{
	php_imagickpixel_object *internp;
	php_imagickdraw_object *internd;
	PixelWand *tmp_wand;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;
	tmp_wand = NewPixelWand();

	if (!tmp_wand) {
		php_imagick_throw_exception(IMAGICKDRAW_CLASS, "Failed to allocate space for new PixelWand" TSRMLS_CC);
		return;
	}

	DrawGetTextUnderColor(internd->drawing_wand, tmp_wand);

	object_init_ex(return_value, php_imagickpixel_sc_entry);
	internp = Z_IMAGICKPIXEL_P(return_value);
	php_imagick_replace_pixelwand(internp, tmp_wand);

	return;
}
/* }}} */

/* {{{ proto bool ImagickDraw::pathClose()
	Adds a path element to the current path which closes the current subpath by drawing a straight line from the current point to the current subpath's most recent starting point (usually, the most recent moveto point).
*/
PHP_METHOD(ImagickDraw, pathClose)
{
	php_imagickdraw_object *internd;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());;
	DrawPathClose(internd->drawing_wand);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::pathCurveToAbsolute(float x1, float y1, float x2, float y2, float x, float y)
	Draws a cubic Bezier curve from the current point to (x,y) using (x1,y1) as the control point at the beginning of the curve and (x2,y2) as the control point at the end of the curve using absolute coordinates. At the end of the command, the new current point becomes the final (x,y) coordinate pair used in the polybezier.
*/
PHP_METHOD(ImagickDraw, pathCurveToAbsolute)
{
	php_imagickdraw_object *internd;
	double x1, y1, x2, y2, x, y;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dddddd", &x1, &y1, &x2, &y2, &x, &y) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());

	DrawPathCurveToAbsolute(internd->drawing_wand, x1, y1, x2, y2, x, y);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::pathCurveToRelative(float x1, float y1, float x2, float y2, float x, float y)
	Draws a cubic Bezier curve from the current point to (x,y) using (x1,y1) as the control point at the beginning of the curve and (x2,y2) as the control point at the end of the curve using relative coordinates. At the end of the command, the new current point becomes the final (x,y) coordinate pair used in the polybezier.
*/
PHP_METHOD(ImagickDraw, pathCurveToRelative)
{
	php_imagickdraw_object *internd;
	double x1, y1, x2, y2, x, y;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dddddd", &x1, &y1, &x2, &y2, &x, &y) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());

	DrawPathCurveToRelative(internd->drawing_wand, x1, y1, x2, y2, x, y);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::pathCurveToQuadraticBezierAbsolute(float x1, float y1, float x, float y)
	Draws a quadratic Bezier curve from the current point to (x,y) using (x1,y1) as the control point using absolute coordinates. At the end of the command, the new current point becomes the final (x,y) coordinate pair used in the polybezier.
*/
PHP_METHOD(ImagickDraw, pathCurveToQuadraticBezierAbsolute)
{
	php_imagickdraw_object *internd;
	double x1, y1, x, y;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dddd", &x1, &y1, &x, &y) == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());

	DrawPathCurveToQuadraticBezierAbsolute(internd->drawing_wand, x1, y1, x, y);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::pathCurveToQuadraticBezierRelative(float x1, float y1, float x, float y)
	Draws a quadratic Bezier curve from the current point to (x,y) using (x1,y1) as the control point using relative coordinates. At the end of the command, the new current point becomes the final (x,y) coordinate pair used in the polybezier.
*/
PHP_METHOD(ImagickDraw, pathCurveToQuadraticBezierRelative)
{
	php_imagickdraw_object *internd;
	double x1, y1, x, y;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dddd", &x1, &y1, &x, &y) == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());

	DrawPathCurveToQuadraticBezierRelative(internd->drawing_wand, x1, y1, x, y);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::pathCurveToQuadraticBezierSmoothAbsolute(float x, float y)
	Draws a quadratic Bezier curve (using relative coordinates) from the current point to (x,y). The control point is assumed to be the reflection of the control point on the previous command relative to the current point. (If there is no previous command or if the previous command was not a DrawPathCurveToQuadraticBezierAbsolute, DrawPathCurveToQuadraticBezierRelative, DrawPathCurveToQuadraticBezierSmoothAbsolut or DrawPathCurveToQuadraticBezierSmoothRelative, assume the control point is coincident with the current point.). At the end of the command, the new current point becomes the final (x,y) coordinate pair used in the polybezier.
*/
PHP_METHOD(ImagickDraw, pathCurveToQuadraticBezierSmoothAbsolute)
{
	php_imagickdraw_object *internd;
	double x, y;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dd", &x, &y) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());

	DrawPathCurveToQuadraticBezierSmoothAbsolute(internd->drawing_wand, x, y);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::pathCurveToQuadraticBezierSmoothRelative(float x, float y)
	Draws a quadratic Bezier curve (using relative coordinates) from the current point to (x, y). The control point is assumed to be the reflection of the control point on the previous command relative to the current point. (If there is no previous command or if the previous command was not a DrawPathCurveToQuadraticBezierAbsolute, DrawPathCurveToQuadraticBezierRelative, DrawPathCurveToQuadraticBezierSmoothAbsolut or DrawPathCurveToQuadraticBezierSmoothRelative, assume the control point is coincident with the current point). At the end of the command, the new current point becomes the final (x, y) coordinate pair used in the polybezier.
*/
PHP_METHOD(ImagickDraw, pathCurveToQuadraticBezierSmoothRelative)
{
	php_imagickdraw_object *internd;
	double x, y;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dd", &x, &y) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());

	DrawPathCurveToQuadraticBezierSmoothRelative(internd->drawing_wand, x, y);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::pathCurveToSmoothAbsolute(float x2, float y2, float x, float y)
	Draws a cubic Bezier curve from the current point to (x,y) using absolute coordinates. The first control point is assumed to be the reflection of the second control point on the previous command relative to the current point. (If there is no previous command or if the previous command was not an DrawPathCurveToAbsolute, DrawPathCurveToRelative, DrawPathCurveToSmoothAbsolute or DrawPathCurveToSmoothRelative, assume the first control point is coincident with the current point.) (x2,y2) is the second control point (i.e., the control point at the end of the curve). At the end of the command, the new current point becomes the final (x,y) coordinate pair used in the polybezier.
*/
PHP_METHOD(ImagickDraw, pathCurveToSmoothAbsolute)
{
	php_imagickdraw_object *internd;
	double x1, y1, x, y;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dddd", &x1, &y1, &x, &y) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());

	DrawPathCurveToSmoothAbsolute(internd->drawing_wand, x1, y1, x, y);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::pathCurveToSmoothRelative(float x2, float y2, float x, float y)
	Draws a cubic Bezier curve from the current point to (x,y) using relative coordinates. The first control point is assumed to be the reflection of the second control point on the previous command relative to the current point. (If there is no previous command or if the previous command was not an DrawPathCurveToAbsolute, DrawPathCurveToRelative, DrawPathCurveToSmoothAbsolute or DrawPathCurveToSmoothRelative, assume the first control point is coincident with the current point.) (x2,y2) is the second control point (i.e., the control point at the end of the curve). At the end of the command, the new current point becomes the final (x,y) coordinate pair used in the polybezier.
*/
PHP_METHOD(ImagickDraw, pathCurveToSmoothRelative)
{
	php_imagickdraw_object *internd;
	double x1, y1, x, y;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dddd", &x1, &y1, &x, &y) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());

	DrawPathCurveToSmoothRelative(internd->drawing_wand, x1, y1, x, y);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::pathEllipticArcAbsolute(float rx, float ry, float x_axis_rotation, bool large_arc_flag, bool sweep_flag, float x, float y)
	Draws an elliptical arc from the current point to (x, y) using absolute coordinates. The size and orientation of the ellipse are defined by two radii (rx, ry) and an xAxisRotation, which indicates how the ellipse as a whole is rotated relative to the current coordinate system. The center (cx, cy) of the ellipse is calculated automatically to satisfy the constraints imposed by the other parameters. largeArcFlag and sweepFlag contribute to the automatic calculations and help determine how the arc is drawn. If largeArcFlag is true then draw the larger of the available arcs. If sweepFlag is true, then draw the arc matching a clock-wise rotation.
*/
PHP_METHOD(ImagickDraw, pathEllipticArcAbsolute)
{
	php_imagickdraw_object *internd;
	double rx, ry, x_axis_rotation, x, y;
	zend_bool large_arc, sweep;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dddbbdd", &rx, &ry, &x_axis_rotation, &large_arc, &sweep, &x, &y) == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());
	DrawPathEllipticArcAbsolute(internd->drawing_wand, rx, ry, x_axis_rotation, large_arc, sweep, x, y);

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::pathEllipticArcRelative(float rx, float ry, float x_axis_rotation, bool large_arc_flag, bool sweep_flag, float x, float y)
	Draws an elliptical arc from the current point to (x, y) using relative coordinates. The size and orientation of the ellipse are defined by two radii (rx, ry) and an xAxisRotation, which indicates how the ellipse as a whole is rotated relative to the current coordinate system. The center (cx, cy) of the ellipse is calculated automatically to satisfy the constraints imposed by the other parameters. largeArcFlag and sweepFlag contribute to the automatic calculations and help determine how the arc is drawn. If largeArcFlag is true then draw the larger of the available arcs. If sweepFlag is true, then draw the arc matching a clock-wise rotation.
*/
PHP_METHOD(ImagickDraw, pathEllipticArcRelative)
{
	php_imagickdraw_object *internd;
	double rx, ry, x_axis_rotation, x, y;
	zend_bool large_arc, sweep;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dddbbdd", &rx, &ry, &x_axis_rotation, &large_arc, &sweep, &x, &y) == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());
	DrawPathEllipticArcRelative(internd->drawing_wand, rx, ry, x_axis_rotation, large_arc, sweep, x, y);

	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::pathFinish()
	Terminates the current path.
*/
PHP_METHOD(ImagickDraw, pathFinish)
{
	php_imagickdraw_object *internd;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());;
	DrawPathFinish(internd->drawing_wand);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::pathLineToAbsolute(float x, float y)
	Draws a line path from the current point to the given coordinate using absolute coordinates. The coordinate then becomes the new current point.
*/
PHP_METHOD(ImagickDraw, pathLineToAbsolute)
{
	php_imagickdraw_object *internd;
	double x, y;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dd", &x, &y) == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());

	DrawPathLineToAbsolute(internd->drawing_wand, x, y);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::pathLineToRelative(float x, float y)
	Draws a line path from the current point to the given coordinate using relative coordinates. The coordinate then becomes the new current point.
*/
PHP_METHOD(ImagickDraw, pathLineToRelative)
{
	php_imagickdraw_object *internd;
	double x, y;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dd", &x, &y) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());

	DrawPathLineToRelative(internd->drawing_wand, x, y);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::pathLineToHorizontalAbsolute(float x)
	Draws a horizontal line path from the current point to the target point using absolute coordinates.  The target point then becomes the new current point.
*/
PHP_METHOD(ImagickDraw, pathLineToHorizontalAbsolute)
{
	php_imagickdraw_object *internd;
	double y;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d",  &y) == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());

	DrawPathLineToHorizontalAbsolute(internd->drawing_wand, y);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::pathLineToHorizontalRelative(float x)
	Draws a horizontal line path from the current point to the target point using relative coordinates.  The target point then becomes the new current point.
*/
PHP_METHOD(ImagickDraw, pathLineToHorizontalRelative)
{
	php_imagickdraw_object *internd;
	double x;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d", &x) == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());

	DrawPathLineToHorizontalRelative(internd->drawing_wand, x);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::pathLineToVerticalAbsolute(float y)
	Draws a vertical line path from the current point to the target point using absolute coordinates.  The target point then becomes the new current point.
*/
PHP_METHOD(ImagickDraw, pathLineToVerticalAbsolute)
{
	php_imagickdraw_object *internd;
	double y;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d", &y) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());

	DrawPathLineToVerticalAbsolute(internd->drawing_wand, y);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::pathLineToVerticalRelative(float y)
	Draws a vertical line path from the current point to the target point using relative coordinates.  The target point then becomes the new current point.
*/
PHP_METHOD(ImagickDraw, pathLineToVerticalRelative)
{
	php_imagickdraw_object *internd;
	double y;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d", &y) == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());

	DrawPathLineToVerticalRelative(internd->drawing_wand, y);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::pathMoveToAbsolute(float x, float y)
	Starts a new sub-path at the given coordinate using absolute coordinates. The current point then becomes the specified coordinate.
*/
PHP_METHOD(ImagickDraw, pathMoveToAbsolute)
{
	php_imagickdraw_object *internd;
	double x, y;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dd", &x, &y) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());

	DrawPathMoveToAbsolute(internd->drawing_wand, x, y);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::pathMoveToRelative(float x, float y)
	Starts a new sub-path at the given coordinate using relative coordinates. The current point then becomes the specified coordinate.
*/
PHP_METHOD(ImagickDraw, pathMoveToRelative)
{
	php_imagickdraw_object *internd;
	double x, y;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dd", &x, &y) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());

	DrawPathMoveToRelative(internd->drawing_wand, x, y);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::pathStart()
	Declares the start of a path drawing list which is terminated by a matching DrawPathFinish() command. All other DrawPath commands must be enclosed between a and a DrawPathFinish() command. This is because path drawing commands are subordinate commands and they do not function by themselves.
*/
PHP_METHOD(ImagickDraw, pathStart)
{
	php_imagickdraw_object *internd;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());;
	DrawPathStart(internd->drawing_wand);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::polyline(array coordinates)
	Draws a polyline using the current stroke, stroke width, and fill color or texture, using the specified array of coordinates.
*/
PHP_METHOD(ImagickDraw, polyline)
{
	zval *coordinate_array;
	php_imagickdraw_object *internd;
	PointInfo *coordinates;
	int num_elements = 0;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "a", &coordinate_array) == FAILURE) {
		return;
	}

	coordinates = php_imagick_zval_to_pointinfo_array(coordinate_array, &num_elements TSRMLS_CC);

	if (!coordinates) {
		php_imagick_throw_exception(IMAGICKDRAW_CLASS, "Unable to read coordinate array" TSRMLS_CC);
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;
	DrawPolyline(internd->drawing_wand, num_elements, coordinates);

	efree(coordinates);
	RETURN_TRUE;

}
/* }}} */

/* {{{ proto bool ImagickDraw::popClipPath()
	Terminates a clip path definition.
*/
PHP_METHOD(ImagickDraw, popClipPath)
{
	php_imagickdraw_object *internd;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());;
	DrawPopClipPath(internd->drawing_wand);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::popDefs()
	Terminates a definition list
*/
PHP_METHOD(ImagickDraw, popDefs)
{
	php_imagickdraw_object *internd;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());;
	DrawPopDefs(internd->drawing_wand);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::popPattern()
	Terminates a pattern definition.
*/
PHP_METHOD(ImagickDraw, popPattern)
{
	php_imagickdraw_object *internd;
	MagickBooleanType status;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	internd = Z_IMAGICKDRAW_P(getThis());;
	status = DrawPopPattern(internd->drawing_wand);

	if (status == MagickFalse) {
		php_imagick_convert_imagickdraw_exception (internd->drawing_wand, "Unable to terminate the pattern definition" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::pushClipPath(string clip_mask_id)
	Starts a clip path definition which is comprized of any number of drawing commands and terminated by a DrawPopClipPath() command.
*/
PHP_METHOD(ImagickDraw, pushClipPath)
{
	php_imagickdraw_object *internd;
	char *clip_mask;
	IM_LEN_TYPE clip_mask_len;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &clip_mask, &clip_mask_len) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());

	DrawPushClipPath(internd->drawing_wand, clip_mask);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::pushDefs()
	Indicates that commands up to a terminating DrawPopDefs() command create named elements (e.g. clip-paths, textures, etc.) which may safely be processed earlier for the sake of efficiency.
*/
PHP_METHOD(ImagickDraw, pushDefs)
{
	php_imagickdraw_object *internd;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());;
	DrawPushDefs(internd->drawing_wand);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::pushPattern(string pattern_id, float x, float y, float width, float height)
	Indicates that subsequent commands up to a DrawPopPattern() command comprise the definition of a named pattern. The pattern space is assigned top left corner coordinates, a width and height, and becomes its own drawing space.  Anything which can be drawn may be used in a pattern definition. Named patterns may be used as stroke or brush definitions.
*/
PHP_METHOD(ImagickDraw, pushPattern)
{	
	php_imagickdraw_object *internd;
	char *pattern_id;
	IM_LEN_TYPE pattern_id_len;
	double x, y, width, height;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sdddd", &pattern_id, &pattern_id_len, &x, &y, &width, &height) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());

	DrawPushPattern(internd->drawing_wand, pattern_id, x, y, width, height);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::render()
	Renders all preceding drawing commands.
*/
PHP_METHOD(ImagickDraw, render)
{
	php_imagickdraw_object *internd;
	MagickBooleanType status;
	char *old_locale;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;

	old_locale = php_imagick_set_locale (TSRMLS_C);

	status = DrawRender(internd->drawing_wand);

	php_imagick_restore_locale (old_locale);

	if (old_locale)
		efree (old_locale);

	if (status == MagickFalse) {
		php_imagick_convert_imagickdraw_exception (internd->drawing_wand, "Unable to render the drawing commands" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::rotate(float degrees)
	Applies the specified rotation to the current coordinate space.
*/
PHP_METHOD(ImagickDraw, rotate)
{
	php_imagickdraw_object *internd;
	double degrees;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d", &degrees) == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());

	DrawRotate(internd->drawing_wand, degrees);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::scale(float x, float y)
	Adjusts the scaling factor to apply in the horizontal and vertical directions to the current coordinate space.
*/
PHP_METHOD(ImagickDraw, scale)
{
	php_imagickdraw_object *internd;
	double x, y;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dd", &x, &y) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());

	DrawScale(internd->drawing_wand, x, y);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::setClipPath(string clip_mask)
	Associates a named clipping path with the image.  Only the areas drawn on by the clipping path will be modified as long as it remains in effect.
*/
PHP_METHOD(ImagickDraw, setClipPath)
{
	php_imagickdraw_object *internd;
	char *clip_mask;
	IM_LEN_TYPE clip_mask_len;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &clip_mask, &clip_mask_len) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());
	status = DrawSetClipPath(internd->drawing_wand, clip_mask);

	if (status == MagickFalse) {
		php_imagick_convert_imagickdraw_exception (internd->drawing_wand, "Unable to set clipping path" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::setClipRule(int fill_rule)
	Set the polygon fill rule to be used by the clipping path.
*/
PHP_METHOD(ImagickDraw, setClipRule)
{
	php_imagickdraw_object *internd;
	im_long fill_rule;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &fill_rule) == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());

	DrawSetClipRule(internd->drawing_wand, fill_rule);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::setClipUnits(int clip_units)
	Sets the interpretation of clip path units.
*/
PHP_METHOD(ImagickDraw, setClipUnits)
{	
	php_imagickdraw_object *internd;
	im_long units;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &units) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());

	DrawSetClipUnits(internd->drawing_wand, units);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::setFillOpacity(float fillOpacity)
	Sets the opacity to use when drawing using the fill color or fill texture.  Fully opaque is 1.0.
*/
PHP_METHOD(ImagickDraw, setFillOpacity)
{
	php_imagickdraw_object *internd;
	double fillOpacity;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d", &fillOpacity) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());

	DrawSetFillOpacity(internd->drawing_wand, fillOpacity);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::setFillPatternUrl(string fill_url)
	Sets the URL to use as a fill pattern for filling objects. Only local URLs ("#identifier") are supported at this time.
	These local URLs are normally created by defining a named fill pattern with DrawPushPattern/DrawPopPattern.
*/
PHP_METHOD(ImagickDraw, setFillPatternUrl)
{
	php_imagickdraw_object *internd;
	char *url;
	IM_LEN_TYPE url_len;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &url, &url_len) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());
	status = DrawSetFillPatternURL(internd->drawing_wand, url);

	if (status == MagickFalse) {
		php_imagick_convert_imagickdraw_exception (internd->drawing_wand, "Unable to set fill pattern URL" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::setFillRule(int fill_rule)
	Sets the fill rule to use while drawing polygons.
*/
PHP_METHOD(ImagickDraw, setFillRule)
{
	php_imagickdraw_object *internd;
	im_long fill_rule;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &fill_rule) == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());

	DrawSetFillRule(internd->drawing_wand, fill_rule);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::setGravity(int gravity)
	Sets the text placement gravity to use when annotating with text.
*/
PHP_METHOD(ImagickDraw, setGravity)
{
	php_imagickdraw_object *internd;
	im_long gravity;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &gravity) == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());

	DrawSetGravity(internd->drawing_wand, gravity);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::setStrokePatternUrl(string stroke_url)
	Sets the pattern used for stroking object outlines.
*/
PHP_METHOD(ImagickDraw, setStrokePatternUrl)
{
	php_imagickdraw_object *internd;
	char *url;
	IM_LEN_TYPE url_len;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &url, &url_len) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());
	status = DrawSetStrokePatternURL(internd->drawing_wand, url);

	if (status == MagickFalse) {
		php_imagick_convert_imagickdraw_exception (internd->drawing_wand, "Unable to set stroke pattern URL" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::setStrokeDashOffset(float dash_offset)
	Specifies the offset into the dash pattern to start the dash.
*/
PHP_METHOD(ImagickDraw, setStrokeDashOffset)
{
	php_imagickdraw_object *internd;
	double offset;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d", &offset) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());

	DrawSetStrokeDashOffset(internd->drawing_wand, offset);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::setStrokeLineCap(int linecap)
	Specifies the shape to be used at the end of open subpaths when they are stroked. Values of LineCap are UndefinedCap, ButtCap, RoundCap, and SquareCap.
*/
PHP_METHOD(ImagickDraw, setStrokeLineCap)
{
	php_imagickdraw_object *internd;
	im_long line_cap;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &line_cap) == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());

	DrawSetStrokeLineCap(internd->drawing_wand, line_cap);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::setStrokeLineJoin(int linejoin)
	Specifies the shape to be used at the corners of paths (or other vector shapes) when they are stroked. Values of LineJoin are UndefinedJoin, MiterJoin, RoundJoin, and BevelJoin.
*/
PHP_METHOD(ImagickDraw, setStrokeLineJoin)
{	
	php_imagickdraw_object *internd;
	im_long line_join;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &line_join) == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());

	DrawSetStrokeLineJoin(internd->drawing_wand, line_join);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::setStrokeMiterLimit(int miterlimit)
	Specifies the miter limit. When two line segments meet at a sharp angle and miter joins have been specified for 'lineJoin', it is possible for the miter to extend far beyond the thickness of the line stroking the path. The miterLimit' imposes a limit on the ratio of the miter length to the 'lineWidth'.
*/
PHP_METHOD(ImagickDraw, setStrokeMiterLimit)
{
	php_imagickdraw_object *internd;
	im_long miter_limit;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &miter_limit) == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());

	DrawSetStrokeMiterLimit(internd->drawing_wand, miter_limit);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::setStrokeOpacity(float stroke_opacity)
	Specifies the opacity of stroked object outlines.
*/
PHP_METHOD(ImagickDraw, setStrokeOpacity)
{
	php_imagickdraw_object *internd;
	double opacity;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d", &opacity) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());

	DrawSetStrokeOpacity(internd->drawing_wand, opacity);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::setVectorGraphics(string xml)
	Sets the vector graphics associated with the specified wand.  Use this method with DrawGetVectorGraphics() as a method to persist the vector graphics state.
*/
PHP_METHOD(ImagickDraw, setVectorGraphics)
{
	php_imagickdraw_object *internd;
	char *vector;
	IM_LEN_TYPE vector_len;
	MagickBooleanType status;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &vector, &vector_len) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());
	status = DrawSetVectorGraphics(internd->drawing_wand, vector);

	if (status == MagickFalse) {
		php_imagick_convert_imagickdraw_exception (internd->drawing_wand, "Unable to set the vector graphics" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::pop()
	Destroys the current DrawingWand in the stack, and returns to the previously pushed DrawingWand. Multiple DrawingWands may exist. It is an error to attempt to pop more DrawingWands than have been pushed, and it is proper form to pop all DrawingWands which have been pushed.
*/
PHP_METHOD(ImagickDraw, pop)
{
	php_imagickdraw_object *internd;
	MagickBooleanType status;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;
	status = PopDrawingWand(internd->drawing_wand);

	if (status == MagickFalse) {
		php_imagick_convert_imagickdraw_exception (internd->drawing_wand, "Unable to pop the current ImagickDraw object" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool ImagickDraw::push()
	Clones the current DrawingWand to create a new DrawingWand, which is then added to the DrawingWand stack. The original drawing DrawingWand(s) may be returned to by invoking PopDrawingWand(). The DrawingWands are stored on a DrawingWand stack. For every Pop there must have already been an equivalent Push.
*/
PHP_METHOD(ImagickDraw, push)
{
	php_imagickdraw_object *internd;
	MagickBooleanType status;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;
	status = PushDrawingWand(internd->drawing_wand);

	if (status == MagickFalse) {
		php_imagick_convert_imagickdraw_exception (internd->drawing_wand, "Unable to push the current ImagickDraw object" TSRMLS_CC);
		return;
	}
	RETURN_TRUE;
}
/* }}} */

#if MagickLibVersion >= 0x693
/* {{{ proto float ImagickDraw::getOpacity()
	Returns the opacity used when drawing with the fill or stroke color or texture. Fully opaque is 1.0.
*/
PHP_METHOD(ImagickDraw, getOpacity)
{
	php_imagickdraw_object *internd;
	double opacity;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());
	opacity = DrawGetOpacity(internd->drawing_wand);

	RETURN_DOUBLE(opacity);
}
/* }}} */

/* {{{ proto bool ImagickDraw::setOpacity(float opacity)
	Sets the opacity to use when drawing using the fill or stroke color or texture. Fully opaque is 1.0.
*/
PHP_METHOD(ImagickDraw, setOpacity)
{
	php_imagickdraw_object *internd;
	double opacity;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d", &opacity) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;
	DrawSetOpacity(internd->drawing_wand, opacity);

	RETURN_TRUE;
}
/* }}} */
#endif //#if MagickLibVersion >= 0x693

#if MagickLibVersion >= 0x675
/* {{{ proto array ImagickDraw::getFontResolution() 
	Gets the image X and Y resolution.
*/
PHP_METHOD(ImagickDraw, getFontResolution)
{
	php_imagickdraw_object *internd;
	double x, y;
	MagickBooleanType status;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());
	status = DrawGetFontResolution(internd->drawing_wand, &x, &y);

	if (status == MagickFalse) {
		php_imagick_convert_imagickdraw_exception (internd->drawing_wand, "Unable to push the current ImagickDraw object" TSRMLS_CC);
		return;
	}

	array_init(return_value);
	add_assoc_double(return_value, "x", x);
	add_assoc_double(return_value, "y", y);

	return;
}
/* }}} */
#endif //#if MagickLibVersion >= 0x675


#if MagickLibVersion >= 0x675
/* {{{ proto bool ImagickDraw::setFontResolution(float x, float y)
	Sets the image font resolution.
*/
PHP_METHOD(ImagickDraw, setFontResolution)
{
	php_imagickdraw_object *internd;
	double x, y;

	MagickBooleanType status;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dd", &x, &y) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;
	status = DrawSetFontResolution(internd->drawing_wand, x, y);
	if (status == MagickFalse) {
		php_imagick_convert_imagickdraw_exception (internd->drawing_wand, "Unable to push the current ImagickDraw object" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */
#endif //#if MagickLibVersion >= 0x675


#if MagickLibVersion >= 0x675
/* {{{ proto ImagickPixel ImagickDraw::getBorderColor()
	Returns the border color used for drawing bordered objects.
*/
PHP_METHOD(ImagickDraw, getBorderColor)
{
	php_imagickpixel_object *internp;
	php_imagickdraw_object *internd;
	PixelWand *tmp_wand;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	
	internd = Z_IMAGICKDRAW_P(getThis());

	tmp_wand = NewPixelWand();
	DrawGetBorderColor(internd->drawing_wand, tmp_wand);

	object_init_ex(return_value, php_imagickpixel_sc_entry);
	internp = Z_IMAGICKPIXEL_P(return_value);
	php_imagick_replace_pixelwand(internp, tmp_wand);
	return;
}
/* }}} */
#endif //#if MagickLibVersion >= 0x675



#if MagickLibVersion >= 0x675
/* {{{ proto bool ImagickDraw::setBorderColor(ImagickPixel color)
	Sets the border color to be used for drawing bordered objects.
*/
PHP_METHOD(ImagickDraw, setBorderColor)
{
	zval *param;
	php_imagickdraw_object *internd;
	PixelWand *color_wand;
	zend_bool allocated;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &param) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());;

	color_wand = php_imagick_zval_to_pixelwand(param, IMAGICKDRAW_CLASS, &allocated TSRMLS_CC);
	if (!color_wand)
		return;

	DrawSetBorderColor(internd->drawing_wand, color_wand);
	if (allocated)
		color_wand = DestroyPixelWand (color_wand);

	RETURN_TRUE;
}
/* }}} */
#endif //#if MagickLibVersion >= 0x675

#if MagickLibVersion >= 0x692
/* {{{ proto integer ImagickDraw::getTextDirection()
	Returns the direction that will be used when annotating with text.
*/
PHP_METHOD(ImagickDraw, getTextDirection)
{
	php_imagickdraw_object *internd;
	im_long direction;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());
	direction = DrawGetTextDirection(internd->drawing_wand);

	RETURN_LONG(direction);
}

/* }}} */


/* {{{ proto bool ImagickDraw::setTextDirection(int direction)
	Sets the font style to use when annotating with text. The AnyStyle enumeration acts as a wild-card "don't care" option.
*/
PHP_METHOD(ImagickDraw, setTextDirection)
{
	php_imagickdraw_object *internd;
	im_long direction;

	/* Parse parameters given to function */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &direction) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());

	DrawSetTextDirection(internd->drawing_wand, direction);
	RETURN_TRUE;
}
/* }}} */
#endif //#if MagickLibVersion >= 0x692

#if MagickLibVersion >= 0x692
/* {{{ proto bool ImagickDraw::setDensity(string density_string)
	Sets the vertical and horizontal resolution.
*/
PHP_METHOD(ImagickDraw, setDensity)
{
	php_imagickdraw_object *internd;
	char *density;
	IM_LEN_TYPE density_len;
	MagickBooleanType status;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &density, &density_len) == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());
	status = DrawSetDensity(internd->drawing_wand, density);

	if (status == MagickFalse) {
		php_imagick_convert_imagickdraw_exception (internd->drawing_wand, "Unable to setdensity for ImagickDraw object" TSRMLS_CC);
		return;
	}

	RETURN_TRUE;
}
/* }}} */


/* {{{ proto string|null ImagickDraw::getDensity()
	Obtains the vertical and horizontal resolution. 
*/
PHP_METHOD(ImagickDraw, getDensity)
{
	php_imagickdraw_object *internd;
	char *density;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	internd = Z_IMAGICKDRAW_P(getThis());
	density = DrawGetDensity(internd->drawing_wand);

	if (density == NULL) {
		RETURN_NULL();
	}
	else {
		IM_RETURN_STRING(density);
	}
}
/* }}} */
#endif// #if MagickLibVersion >= 0x692


/* END OF DRAWINGWAND METHODS */
