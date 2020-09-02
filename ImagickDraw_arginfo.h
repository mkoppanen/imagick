/* This is a generated file, edit the .stub.php file instead.
* Stub hash: regen with 'sh regen_arginfo.sh' */

#if MagickLibVersion > 0x628

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_resetVectorGraphics, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_resetVectorGraphics, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x649

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_getTextKerning, 0, 0, IS_DOUBLE, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_getTextKerning, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x649

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setTextKerning, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setTextKerning, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, kerning, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, kerning)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x649
#define arginfo_class_ImagickDraw_getTextInterwordSpacing arginfo_class_ImagickDraw_getTextKerning
#endif

#if MagickLibVersion > 0x649

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setTextInterwordSpacing, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setTextInterwordSpacing, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, spacing, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, spacing)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x655

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_getTextInterlineSpacing, 0, 0, IS_DOUBLE, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_getTextInterlineSpacing, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x655

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setTextInterlineSpacing, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setTextInterlineSpacing, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, spacing, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, spacing)
#endif
ZEND_END_ARG_INFO()
#endif

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw___construct, 0, 0, 0)
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setFillColor, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setFillColor, 0, 0, 1)
#endif

	ZEND_ARG_OBJ_TYPE_MASK(0, fill_pixel, ImagickPixel, MAY_BE_STRING, NULL)
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setFillAlpha, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setFillAlpha, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, opacity, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, opacity)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setResolution, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setResolution, 0, 0, 2)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x_resolution, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, x_resolution)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y_resolution, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, y_resolution)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setStrokeColor, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setStrokeColor, 0, 0, 1)
#endif

	ZEND_ARG_OBJ_TYPE_MASK(0, stroke_pixel, ImagickPixel, MAY_BE_STRING, NULL)
ZEND_END_ARG_INFO()

#define arginfo_class_ImagickDraw_setStrokeAlpha arginfo_class_ImagickDraw_setFillAlpha


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setStrokeWidth, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setStrokeWidth, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, stroke_width, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, stroke_width)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_clear, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_clear, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_circle, 0, 4, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_circle, 0, 0, 4)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, ox, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, ox)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, oy, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, oy)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, px, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, px)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, py, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, py)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_annotation, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_annotation, 0, 0, 3)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, x)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, y)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, text)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setTextAntialias, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setTextAntialias, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, antialias, _IS_BOOL, 0)
#else
    ZEND_ARG_INFO(0, antialias)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setTextEncoding, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setTextEncoding, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, encoding, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, encoding)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setFont, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setFont, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, font_name, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, font_name)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setFontFamily, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setFontFamily, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, font_family, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, font_family)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setFontSize, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setFontSize, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, pointsize, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, pointsize)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setFontStyle, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setFontStyle, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, style, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, style)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setFontWeight, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setFontWeight, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, font_weight, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, font_weight)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_getFont, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_getFont, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()

#define arginfo_class_ImagickDraw_getFontFamily arginfo_class_ImagickDraw_getFont


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_getFontSize, 0, 0, IS_DOUBLE, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_getFontSize, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_getFontStyle, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_getFontStyle, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()

#define arginfo_class_ImagickDraw_getFontWeight arginfo_class_ImagickDraw_getFontStyle

#define arginfo_class_ImagickDraw_destroy arginfo_class_ImagickDraw_clear


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_rectangle, 0, 4, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_rectangle, 0, 0, 4)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x1, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, x1)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y1, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, y1)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x2, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, x2)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y2, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, y2)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_roundRectangle, 0, 6, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_roundRectangle, 0, 0, 6)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x1, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, x1)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y1, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, y1)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x2, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, x2)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y2, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, y2)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, rx, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, rx)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, ry, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, ry)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_ellipse, 0, 6, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_ellipse, 0, 0, 6)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, ox, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, ox)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, oy, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, oy)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, rx, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, rx)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, ry, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, ry)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, start, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, start)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, end, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, end)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_skewX, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_skewX, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, degrees, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, degrees)
#endif
ZEND_END_ARG_INFO()

#define arginfo_class_ImagickDraw_skewY arginfo_class_ImagickDraw_skewX


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_translate, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_translate, 0, 0, 2)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, x)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, y)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_line, 0, 4, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_line, 0, 0, 4)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, sx, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, sx)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, sy, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, sy)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, ex, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, ex)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, ey, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, ey)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_arc, 0, 6, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_arc, 0, 0, 6)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, sx, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, sx)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, sy, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, sy)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, ex, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, ex)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, ey, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, ey)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, sd, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, sd)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, ed, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, ed)
#endif
ZEND_END_ARG_INFO()

#if MagickLibVersion >= 0x700

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_alpha, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_alpha, 0, 0, 3)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, x)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, y)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, paintMethod, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, paintMethod)
#endif
ZEND_END_ARG_INFO()
#endif

#if !(MagickLibVersion >= 0x700)

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_matte, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_matte, 0, 0, 3)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, x)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, y)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, paintMethod, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, paintMethod)
#endif
ZEND_END_ARG_INFO()
#endif


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_polygon, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_polygon, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, coordinates, IS_ARRAY, 0)
#else
    ZEND_ARG_INFO(0, coordinates)
#endif
ZEND_END_ARG_INFO()

#define arginfo_class_ImagickDraw_point arginfo_class_ImagickDraw_translate

#define arginfo_class_ImagickDraw_getTextDecoration arginfo_class_ImagickDraw_getFontStyle

#define arginfo_class_ImagickDraw_getTextEncoding arginfo_class_ImagickDraw_getFont

#define arginfo_class_ImagickDraw_getFontStretch arginfo_class_ImagickDraw_getFontStyle


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setFontStretch, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setFontStretch, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, fontStretch, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, fontStretch)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setStrokeAntialias, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setStrokeAntialias, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, stroke_antialias, _IS_BOOL, 0)
#else
    ZEND_ARG_INFO(0, stroke_antialias)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setTextAlignment, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setTextAlignment, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, alignment, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, alignment)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setTextDecoration, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setTextDecoration, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, decoration, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, decoration)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setTextUnderColor, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setTextUnderColor, 0, 0, 1)
#endif

	ZEND_ARG_OBJ_TYPE_MASK(0, under_color, ImagickPixel, MAY_BE_STRING, NULL)
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setViewbox, 0, 4, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setViewbox, 0, 0, 4)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x1, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, x1)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y1, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, y1)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x2, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, x2)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y2, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, y2)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_ImagickDraw_clone, 0, 0, ImagickDraw, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_clone, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_affine, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_affine, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, affine, IS_ARRAY, 0)
#else
    ZEND_ARG_INFO(0, affine)
#endif
ZEND_END_ARG_INFO()

#define arginfo_class_ImagickDraw_bezier arginfo_class_ImagickDraw_polygon


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_composite, 0, 6, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_composite, 0, 0, 6)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, compose, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, compose)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, x)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, y)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, width, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, width)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, height, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, height)
#endif
	ZEND_ARG_OBJ_INFO(0, compositeWand, Imagick, 0)
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_color, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_color, 0, 0, 3)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, x)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, y)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, paintMethod, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, paintMethod)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_comment, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_comment, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, comment, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, comment)
#endif
ZEND_END_ARG_INFO()

#define arginfo_class_ImagickDraw_getClipPath arginfo_class_ImagickDraw_getFont

#define arginfo_class_ImagickDraw_getClipRule arginfo_class_ImagickDraw_getFontStyle

#define arginfo_class_ImagickDraw_getClipUnits arginfo_class_ImagickDraw_getFontStyle


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_ImagickDraw_getFillColor, 0, 0, ImagickPixel, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_getFillColor, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()

#define arginfo_class_ImagickDraw_getFillOpacity arginfo_class_ImagickDraw_getFontSize

#define arginfo_class_ImagickDraw_getFillRule arginfo_class_ImagickDraw_getFontStyle

#define arginfo_class_ImagickDraw_getGravity arginfo_class_ImagickDraw_getFontStyle

#define arginfo_class_ImagickDraw_getStrokeAntialias arginfo_class_ImagickDraw_clear

#define arginfo_class_ImagickDraw_getStrokeColor arginfo_class_ImagickDraw_getFillColor


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_getStrokeDashArray, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_getStrokeDashArray, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()

#define arginfo_class_ImagickDraw_getStrokeDashOffset arginfo_class_ImagickDraw_getFontSize

#define arginfo_class_ImagickDraw_getStrokeLineCap arginfo_class_ImagickDraw_getFontStyle

#define arginfo_class_ImagickDraw_getStrokeLineJoin arginfo_class_ImagickDraw_getFontStyle

#define arginfo_class_ImagickDraw_getStrokeMiterLimit arginfo_class_ImagickDraw_getFontStyle

#define arginfo_class_ImagickDraw_getStrokeOpacity arginfo_class_ImagickDraw_getFontSize

#define arginfo_class_ImagickDraw_getStrokeWidth arginfo_class_ImagickDraw_getFontSize

#define arginfo_class_ImagickDraw_getTextAlignment arginfo_class_ImagickDraw_getFontStyle

#define arginfo_class_ImagickDraw_getTextAntialias arginfo_class_ImagickDraw_clear

#define arginfo_class_ImagickDraw_getVectorGraphics arginfo_class_ImagickDraw_getFont

#define arginfo_class_ImagickDraw_getTextUnderColor arginfo_class_ImagickDraw_getFillColor

#define arginfo_class_ImagickDraw_pathClose arginfo_class_ImagickDraw_clear


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_pathCurveToAbsolute, 0, 6, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_pathCurveToAbsolute, 0, 0, 6)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x1, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, x1)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y1, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, y1)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x2, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, x2)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y2, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, y2)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, x)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, y)
#endif
ZEND_END_ARG_INFO()

#define arginfo_class_ImagickDraw_pathCurveToRelative arginfo_class_ImagickDraw_pathCurveToAbsolute


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_pathCurveToQuadraticBezierAbsolute, 0, 4, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_pathCurveToQuadraticBezierAbsolute, 0, 0, 4)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x1, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, x1)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y1, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, y1)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, x)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, y)
#endif
ZEND_END_ARG_INFO()

#define arginfo_class_ImagickDraw_pathCurveToQuadraticBezierRelative arginfo_class_ImagickDraw_pathCurveToQuadraticBezierAbsolute

#define arginfo_class_ImagickDraw_pathCurveToQuadraticBezierSmoothAbsolute arginfo_class_ImagickDraw_translate

#define arginfo_class_ImagickDraw_pathCurveToQuadraticBezierSmoothRelative arginfo_class_ImagickDraw_translate


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_pathCurveToSmoothAbsolute, 0, 4, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_pathCurveToSmoothAbsolute, 0, 0, 4)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x2, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, x2)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y2, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, y2)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, x)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, y)
#endif
ZEND_END_ARG_INFO()

#define arginfo_class_ImagickDraw_pathCurveToSmoothRelative arginfo_class_ImagickDraw_pathCurveToSmoothAbsolute


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_pathEllipticArcAbsolute, 0, 7, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_pathEllipticArcAbsolute, 0, 0, 7)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, rx, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, rx)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, ry, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, ry)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x_axis_rotation, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, x_axis_rotation)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, large_arc_flag, _IS_BOOL, 0)
#else
    ZEND_ARG_INFO(0, large_arc_flag)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, sweep_flag, _IS_BOOL, 0)
#else
    ZEND_ARG_INFO(0, sweep_flag)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, x)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, y)
#endif
ZEND_END_ARG_INFO()

#define arginfo_class_ImagickDraw_pathEllipticArcRelative arginfo_class_ImagickDraw_pathEllipticArcAbsolute

#define arginfo_class_ImagickDraw_pathFinish arginfo_class_ImagickDraw_clear

#define arginfo_class_ImagickDraw_pathLineToAbsolute arginfo_class_ImagickDraw_translate

#define arginfo_class_ImagickDraw_pathLineToRelative arginfo_class_ImagickDraw_translate


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_pathLineToHorizontalAbsolute, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_pathLineToHorizontalAbsolute, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, x)
#endif
ZEND_END_ARG_INFO()

#define arginfo_class_ImagickDraw_pathLineToHorizontalRelative arginfo_class_ImagickDraw_pathLineToHorizontalAbsolute


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_pathLineToVerticalAbsolute, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_pathLineToVerticalAbsolute, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, y)
#endif
ZEND_END_ARG_INFO()

#define arginfo_class_ImagickDraw_pathLineToVerticalRelative arginfo_class_ImagickDraw_pathLineToVerticalAbsolute

#define arginfo_class_ImagickDraw_pathMoveToAbsolute arginfo_class_ImagickDraw_translate

#define arginfo_class_ImagickDraw_pathMoveToRelative arginfo_class_ImagickDraw_translate

#define arginfo_class_ImagickDraw_pathStart arginfo_class_ImagickDraw_clear

#define arginfo_class_ImagickDraw_polyline arginfo_class_ImagickDraw_polygon

#define arginfo_class_ImagickDraw_popClipPath arginfo_class_ImagickDraw_clear

#define arginfo_class_ImagickDraw_popDefs arginfo_class_ImagickDraw_clear

#define arginfo_class_ImagickDraw_popPattern arginfo_class_ImagickDraw_clear


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_pushClipPath, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_pushClipPath, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, clip_mask_id, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, clip_mask_id)
#endif
ZEND_END_ARG_INFO()

#define arginfo_class_ImagickDraw_pushDefs arginfo_class_ImagickDraw_clear


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_pushPattern, 0, 5, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_pushPattern, 0, 0, 5)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, pattern_id, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, pattern_id)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, x)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, y)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, width, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, width)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, height, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, height)
#endif
ZEND_END_ARG_INFO()

#define arginfo_class_ImagickDraw_render arginfo_class_ImagickDraw_clear

#define arginfo_class_ImagickDraw_rotate arginfo_class_ImagickDraw_skewX

#define arginfo_class_ImagickDraw_scale arginfo_class_ImagickDraw_translate


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setClipPath, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setClipPath, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, clip_mask, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, clip_mask)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setClipRule, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setClipRule, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, fill_rule, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, fill_rule)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setClipUnits, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setClipUnits, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, clip_units, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, clip_units)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setFillOpacity, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setFillOpacity, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, fillOpacity, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, fillOpacity)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setFillPatternUrl, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setFillPatternUrl, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, fill_url, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, fill_url)
#endif
ZEND_END_ARG_INFO()

#define arginfo_class_ImagickDraw_setFillRule arginfo_class_ImagickDraw_setClipRule


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setGravity, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setGravity, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, gravity, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, gravity)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setStrokePatternUrl, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setStrokePatternUrl, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, stroke_url, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, stroke_url)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setStrokeDashOffset, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setStrokeDashOffset, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, dash_offset, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, dash_offset)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setStrokeLineCap, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setStrokeLineCap, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, linecap, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, linecap)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setStrokeLineJoin, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setStrokeLineJoin, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, linejoin, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, linejoin)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setStrokeMiterLimit, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setStrokeMiterLimit, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, miterlimit, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, miterlimit)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setStrokeOpacity, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setStrokeOpacity, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, stroke_opacity, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, stroke_opacity)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setVectorGraphics, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setVectorGraphics, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, xml, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, xml)
#endif
ZEND_END_ARG_INFO()

#define arginfo_class_ImagickDraw_pop arginfo_class_ImagickDraw_clear

#define arginfo_class_ImagickDraw_push arginfo_class_ImagickDraw_clear


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setStrokeDashArray, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setStrokeDashArray, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, dashArray, IS_ARRAY, 0)
#else
    ZEND_ARG_INFO(0, dashArray)
#endif
ZEND_END_ARG_INFO()

#if MagickLibVersion >= 0x693

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_getOpacity, 0, 0, IS_DOUBLE, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_getOpacity, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion >= 0x693

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setOpacity, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setOpacity, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, opacity, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, opacity)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion >= 0x675

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_getFontResolution, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_getFontResolution, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion >= 0x675

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setFontResolution, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setFontResolution, 0, 0, 2)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, x)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, y)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion >= 0x675

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_ImagickDraw_getBorderColor, 0, 0, ImagickPixel, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_getBorderColor, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion >= 0x675

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setBorderColor, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setBorderColor, 0, 0, 1)
#endif

	ZEND_ARG_OBJ_TYPE_MASK(0, color, ImagickPixel, MAY_BE_STRING, NULL)
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion >= 0x693

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setDensity, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setDensity, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, density, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, density)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion >= 0x693

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_getDensity, 0, 0, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_getDensity, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion >= 0x692

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_getTextDirection, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_getTextDirection, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion >= 0x692

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickDraw_setTextDirection, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickDraw_setTextDirection, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, direction, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, direction)
#endif
ZEND_END_ARG_INFO()
#endif


#if MagickLibVersion > 0x628
ZEND_METHOD(ImagickDraw, resetVectorGraphics);
#endif
#if MagickLibVersion > 0x649
ZEND_METHOD(ImagickDraw, getTextKerning);
#endif
#if MagickLibVersion > 0x649
ZEND_METHOD(ImagickDraw, setTextKerning);
#endif
#if MagickLibVersion > 0x649
ZEND_METHOD(ImagickDraw, getTextInterwordSpacing);
#endif
#if MagickLibVersion > 0x649
ZEND_METHOD(ImagickDraw, setTextInterwordSpacing);
#endif
#if MagickLibVersion > 0x655
ZEND_METHOD(ImagickDraw, getTextInterlineSpacing);
#endif
#if MagickLibVersion > 0x655
ZEND_METHOD(ImagickDraw, setTextInterlineSpacing);
#endif
ZEND_METHOD(ImagickDraw, __construct);
ZEND_METHOD(ImagickDraw, setFillColor);
ZEND_METHOD(ImagickDraw, setFillAlpha);
ZEND_METHOD(ImagickDraw, setResolution);
ZEND_METHOD(ImagickDraw, setStrokeColor);
ZEND_METHOD(ImagickDraw, setStrokeAlpha);
ZEND_METHOD(ImagickDraw, setStrokeWidth);
ZEND_METHOD(ImagickDraw, clear);
ZEND_METHOD(ImagickDraw, circle);
ZEND_METHOD(ImagickDraw, annotation);
ZEND_METHOD(ImagickDraw, setTextAntialias);
ZEND_METHOD(ImagickDraw, setTextEncoding);
ZEND_METHOD(ImagickDraw, setFont);
ZEND_METHOD(ImagickDraw, setFontFamily);
ZEND_METHOD(ImagickDraw, setFontSize);
ZEND_METHOD(ImagickDraw, setFontStyle);
ZEND_METHOD(ImagickDraw, setFontWeight);
ZEND_METHOD(ImagickDraw, getFont);
ZEND_METHOD(ImagickDraw, getFontFamily);
ZEND_METHOD(ImagickDraw, getFontSize);
ZEND_METHOD(ImagickDraw, getFontStyle);
ZEND_METHOD(ImagickDraw, getFontWeight);
ZEND_METHOD(ImagickDraw, rectangle);
ZEND_METHOD(ImagickDraw, roundRectangle);
ZEND_METHOD(ImagickDraw, ellipse);
ZEND_METHOD(ImagickDraw, skewX);
ZEND_METHOD(ImagickDraw, skewY);
ZEND_METHOD(ImagickDraw, translate);
ZEND_METHOD(ImagickDraw, line);
ZEND_METHOD(ImagickDraw, arc);
#if MagickLibVersion >= 0x700
ZEND_METHOD(ImagickDraw, alpha);
#endif
#if !(MagickLibVersion >= 0x700)
ZEND_METHOD(ImagickDraw, matte);
#endif
ZEND_METHOD(ImagickDraw, polygon);
ZEND_METHOD(ImagickDraw, point);
ZEND_METHOD(ImagickDraw, getTextDecoration);
ZEND_METHOD(ImagickDraw, getTextEncoding);
ZEND_METHOD(ImagickDraw, getFontStretch);
ZEND_METHOD(ImagickDraw, setFontStretch);
ZEND_METHOD(ImagickDraw, setStrokeAntialias);
ZEND_METHOD(ImagickDraw, setTextAlignment);
ZEND_METHOD(ImagickDraw, setTextDecoration);
ZEND_METHOD(ImagickDraw, setTextUnderColor);
ZEND_METHOD(ImagickDraw, setViewbox);
ZEND_METHOD(ImagickDraw, clone);
ZEND_METHOD(ImagickDraw, affine);
ZEND_METHOD(ImagickDraw, bezier);
ZEND_METHOD(ImagickDraw, composite);
ZEND_METHOD(ImagickDraw, color);
ZEND_METHOD(ImagickDraw, comment);
ZEND_METHOD(ImagickDraw, getClipPath);
ZEND_METHOD(ImagickDraw, getClipRule);
ZEND_METHOD(ImagickDraw, getClipUnits);
ZEND_METHOD(ImagickDraw, getFillColor);
ZEND_METHOD(ImagickDraw, getFillOpacity);
ZEND_METHOD(ImagickDraw, getFillRule);
ZEND_METHOD(ImagickDraw, getGravity);
ZEND_METHOD(ImagickDraw, getStrokeAntialias);
ZEND_METHOD(ImagickDraw, getStrokeColor);
ZEND_METHOD(ImagickDraw, getStrokeDashArray);
ZEND_METHOD(ImagickDraw, getStrokeDashOffset);
ZEND_METHOD(ImagickDraw, getStrokeLineCap);
ZEND_METHOD(ImagickDraw, getStrokeLineJoin);
ZEND_METHOD(ImagickDraw, getStrokeMiterLimit);
ZEND_METHOD(ImagickDraw, getStrokeOpacity);
ZEND_METHOD(ImagickDraw, getStrokeWidth);
ZEND_METHOD(ImagickDraw, getTextAlignment);
ZEND_METHOD(ImagickDraw, getTextAntialias);
ZEND_METHOD(ImagickDraw, getVectorGraphics);
ZEND_METHOD(ImagickDraw, getTextUnderColor);
ZEND_METHOD(ImagickDraw, pathClose);
ZEND_METHOD(ImagickDraw, pathCurveToAbsolute);
ZEND_METHOD(ImagickDraw, pathCurveToRelative);
ZEND_METHOD(ImagickDraw, pathCurveToQuadraticBezierAbsolute);
ZEND_METHOD(ImagickDraw, pathCurveToQuadraticBezierRelative);
ZEND_METHOD(ImagickDraw, pathCurveToQuadraticBezierSmoothAbsolute);
ZEND_METHOD(ImagickDraw, pathCurveToQuadraticBezierSmoothRelative);
ZEND_METHOD(ImagickDraw, pathCurveToSmoothAbsolute);
ZEND_METHOD(ImagickDraw, pathCurveToSmoothRelative);
ZEND_METHOD(ImagickDraw, pathEllipticArcAbsolute);
ZEND_METHOD(ImagickDraw, pathEllipticArcRelative);
ZEND_METHOD(ImagickDraw, pathFinish);
ZEND_METHOD(ImagickDraw, pathLineToAbsolute);
ZEND_METHOD(ImagickDraw, pathLineToRelative);
ZEND_METHOD(ImagickDraw, pathLineToHorizontalAbsolute);
ZEND_METHOD(ImagickDraw, pathLineToHorizontalRelative);
ZEND_METHOD(ImagickDraw, pathLineToVerticalAbsolute);
ZEND_METHOD(ImagickDraw, pathLineToVerticalRelative);
ZEND_METHOD(ImagickDraw, pathMoveToAbsolute);
ZEND_METHOD(ImagickDraw, pathMoveToRelative);
ZEND_METHOD(ImagickDraw, pathStart);
ZEND_METHOD(ImagickDraw, polyline);
ZEND_METHOD(ImagickDraw, popClipPath);
ZEND_METHOD(ImagickDraw, popDefs);
ZEND_METHOD(ImagickDraw, popPattern);
ZEND_METHOD(ImagickDraw, pushClipPath);
ZEND_METHOD(ImagickDraw, pushDefs);
ZEND_METHOD(ImagickDraw, pushPattern);
ZEND_METHOD(ImagickDraw, render);
ZEND_METHOD(ImagickDraw, rotate);
ZEND_METHOD(ImagickDraw, scale);
ZEND_METHOD(ImagickDraw, setClipPath);
ZEND_METHOD(ImagickDraw, setClipRule);
ZEND_METHOD(ImagickDraw, setClipUnits);
ZEND_METHOD(ImagickDraw, setFillOpacity);
ZEND_METHOD(ImagickDraw, setFillPatternUrl);
ZEND_METHOD(ImagickDraw, setFillRule);
ZEND_METHOD(ImagickDraw, setGravity);
ZEND_METHOD(ImagickDraw, setStrokePatternUrl);
ZEND_METHOD(ImagickDraw, setStrokeDashOffset);
ZEND_METHOD(ImagickDraw, setStrokeLineCap);
ZEND_METHOD(ImagickDraw, setStrokeLineJoin);
ZEND_METHOD(ImagickDraw, setStrokeMiterLimit);
ZEND_METHOD(ImagickDraw, setStrokeOpacity);
ZEND_METHOD(ImagickDraw, setVectorGraphics);
ZEND_METHOD(ImagickDraw, pop);
ZEND_METHOD(ImagickDraw, push);
ZEND_METHOD(ImagickDraw, setStrokeDashArray);
#if MagickLibVersion >= 0x693
ZEND_METHOD(ImagickDraw, getOpacity);
#endif
#if MagickLibVersion >= 0x693
ZEND_METHOD(ImagickDraw, setOpacity);
#endif
#if MagickLibVersion >= 0x675
ZEND_METHOD(ImagickDraw, getFontResolution);
#endif
#if MagickLibVersion >= 0x675
ZEND_METHOD(ImagickDraw, setFontResolution);
#endif
#if MagickLibVersion >= 0x675
ZEND_METHOD(ImagickDraw, getBorderColor);
#endif
#if MagickLibVersion >= 0x675
ZEND_METHOD(ImagickDraw, setBorderColor);
#endif
#if MagickLibVersion >= 0x693
ZEND_METHOD(ImagickDraw, setDensity);
#endif
#if MagickLibVersion >= 0x693
ZEND_METHOD(ImagickDraw, getDensity);
#endif
#if MagickLibVersion >= 0x692
ZEND_METHOD(ImagickDraw, getTextDirection);
#endif
#if MagickLibVersion >= 0x692
ZEND_METHOD(ImagickDraw, setTextDirection);
#endif


static const zend_function_entry class_ImagickDraw_methods[] = {
#if MagickLibVersion > 0x628
	ZEND_ME(ImagickDraw, resetVectorGraphics, arginfo_class_ImagickDraw_resetVectorGraphics, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x649
	ZEND_ME(ImagickDraw, getTextKerning, arginfo_class_ImagickDraw_getTextKerning, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x649
	ZEND_ME(ImagickDraw, setTextKerning, arginfo_class_ImagickDraw_setTextKerning, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x649
	ZEND_ME(ImagickDraw, getTextInterwordSpacing, arginfo_class_ImagickDraw_getTextInterwordSpacing, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x649
	ZEND_ME(ImagickDraw, setTextInterwordSpacing, arginfo_class_ImagickDraw_setTextInterwordSpacing, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x655
	ZEND_ME(ImagickDraw, getTextInterlineSpacing, arginfo_class_ImagickDraw_getTextInterlineSpacing, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x655
	ZEND_ME(ImagickDraw, setTextInterlineSpacing, arginfo_class_ImagickDraw_setTextInterlineSpacing, ZEND_ACC_PUBLIC)
#endif
	ZEND_ME(ImagickDraw, __construct, arginfo_class_ImagickDraw___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, setFillColor, arginfo_class_ImagickDraw_setFillColor, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, setFillAlpha, arginfo_class_ImagickDraw_setFillAlpha, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, setResolution, arginfo_class_ImagickDraw_setResolution, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, setStrokeColor, arginfo_class_ImagickDraw_setStrokeColor, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, setStrokeAlpha, arginfo_class_ImagickDraw_setStrokeAlpha, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, setStrokeWidth, arginfo_class_ImagickDraw_setStrokeWidth, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, clear, arginfo_class_ImagickDraw_clear, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, circle, arginfo_class_ImagickDraw_circle, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, annotation, arginfo_class_ImagickDraw_annotation, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, setTextAntialias, arginfo_class_ImagickDraw_setTextAntialias, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, setTextEncoding, arginfo_class_ImagickDraw_setTextEncoding, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, setFont, arginfo_class_ImagickDraw_setFont, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, setFontFamily, arginfo_class_ImagickDraw_setFontFamily, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, setFontSize, arginfo_class_ImagickDraw_setFontSize, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, setFontStyle, arginfo_class_ImagickDraw_setFontStyle, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, setFontWeight, arginfo_class_ImagickDraw_setFontWeight, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, getFont, arginfo_class_ImagickDraw_getFont, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, getFontFamily, arginfo_class_ImagickDraw_getFontFamily, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, getFontSize, arginfo_class_ImagickDraw_getFontSize, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, getFontStyle, arginfo_class_ImagickDraw_getFontStyle, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, getFontWeight, arginfo_class_ImagickDraw_getFontWeight, ZEND_ACC_PUBLIC)
	ZEND_MALIAS(ImagickDraw, destroy, clear, arginfo_class_ImagickDraw_destroy, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, rectangle, arginfo_class_ImagickDraw_rectangle, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, roundRectangle, arginfo_class_ImagickDraw_roundRectangle, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, ellipse, arginfo_class_ImagickDraw_ellipse, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, skewX, arginfo_class_ImagickDraw_skewX, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, skewY, arginfo_class_ImagickDraw_skewY, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, translate, arginfo_class_ImagickDraw_translate, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, line, arginfo_class_ImagickDraw_line, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, arc, arginfo_class_ImagickDraw_arc, ZEND_ACC_PUBLIC)
#if MagickLibVersion >= 0x700
	ZEND_ME(ImagickDraw, alpha, arginfo_class_ImagickDraw_alpha, ZEND_ACC_PUBLIC)
#endif
#if !(MagickLibVersion >= 0x700)
	ZEND_ME(ImagickDraw, matte, arginfo_class_ImagickDraw_matte, ZEND_ACC_PUBLIC|ZEND_ACC_DEPRECATED)
#endif
	ZEND_ME(ImagickDraw, polygon, arginfo_class_ImagickDraw_polygon, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, point, arginfo_class_ImagickDraw_point, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, getTextDecoration, arginfo_class_ImagickDraw_getTextDecoration, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, getTextEncoding, arginfo_class_ImagickDraw_getTextEncoding, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, getFontStretch, arginfo_class_ImagickDraw_getFontStretch, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, setFontStretch, arginfo_class_ImagickDraw_setFontStretch, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, setStrokeAntialias, arginfo_class_ImagickDraw_setStrokeAntialias, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, setTextAlignment, arginfo_class_ImagickDraw_setTextAlignment, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, setTextDecoration, arginfo_class_ImagickDraw_setTextDecoration, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, setTextUnderColor, arginfo_class_ImagickDraw_setTextUnderColor, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, setViewbox, arginfo_class_ImagickDraw_setViewbox, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, clone, arginfo_class_ImagickDraw_clone, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, affine, arginfo_class_ImagickDraw_affine, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, bezier, arginfo_class_ImagickDraw_bezier, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, composite, arginfo_class_ImagickDraw_composite, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, color, arginfo_class_ImagickDraw_color, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, comment, arginfo_class_ImagickDraw_comment, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, getClipPath, arginfo_class_ImagickDraw_getClipPath, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, getClipRule, arginfo_class_ImagickDraw_getClipRule, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, getClipUnits, arginfo_class_ImagickDraw_getClipUnits, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, getFillColor, arginfo_class_ImagickDraw_getFillColor, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, getFillOpacity, arginfo_class_ImagickDraw_getFillOpacity, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, getFillRule, arginfo_class_ImagickDraw_getFillRule, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, getGravity, arginfo_class_ImagickDraw_getGravity, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, getStrokeAntialias, arginfo_class_ImagickDraw_getStrokeAntialias, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, getStrokeColor, arginfo_class_ImagickDraw_getStrokeColor, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, getStrokeDashArray, arginfo_class_ImagickDraw_getStrokeDashArray, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, getStrokeDashOffset, arginfo_class_ImagickDraw_getStrokeDashOffset, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, getStrokeLineCap, arginfo_class_ImagickDraw_getStrokeLineCap, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, getStrokeLineJoin, arginfo_class_ImagickDraw_getStrokeLineJoin, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, getStrokeMiterLimit, arginfo_class_ImagickDraw_getStrokeMiterLimit, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, getStrokeOpacity, arginfo_class_ImagickDraw_getStrokeOpacity, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, getStrokeWidth, arginfo_class_ImagickDraw_getStrokeWidth, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, getTextAlignment, arginfo_class_ImagickDraw_getTextAlignment, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, getTextAntialias, arginfo_class_ImagickDraw_getTextAntialias, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, getVectorGraphics, arginfo_class_ImagickDraw_getVectorGraphics, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, getTextUnderColor, arginfo_class_ImagickDraw_getTextUnderColor, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, pathClose, arginfo_class_ImagickDraw_pathClose, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, pathCurveToAbsolute, arginfo_class_ImagickDraw_pathCurveToAbsolute, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, pathCurveToRelative, arginfo_class_ImagickDraw_pathCurveToRelative, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, pathCurveToQuadraticBezierAbsolute, arginfo_class_ImagickDraw_pathCurveToQuadraticBezierAbsolute, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, pathCurveToQuadraticBezierRelative, arginfo_class_ImagickDraw_pathCurveToQuadraticBezierRelative, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, pathCurveToQuadraticBezierSmoothAbsolute, arginfo_class_ImagickDraw_pathCurveToQuadraticBezierSmoothAbsolute, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, pathCurveToQuadraticBezierSmoothRelative, arginfo_class_ImagickDraw_pathCurveToQuadraticBezierSmoothRelative, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, pathCurveToSmoothAbsolute, arginfo_class_ImagickDraw_pathCurveToSmoothAbsolute, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, pathCurveToSmoothRelative, arginfo_class_ImagickDraw_pathCurveToSmoothRelative, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, pathEllipticArcAbsolute, arginfo_class_ImagickDraw_pathEllipticArcAbsolute, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, pathEllipticArcRelative, arginfo_class_ImagickDraw_pathEllipticArcRelative, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, pathFinish, arginfo_class_ImagickDraw_pathFinish, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, pathLineToAbsolute, arginfo_class_ImagickDraw_pathLineToAbsolute, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, pathLineToRelative, arginfo_class_ImagickDraw_pathLineToRelative, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, pathLineToHorizontalAbsolute, arginfo_class_ImagickDraw_pathLineToHorizontalAbsolute, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, pathLineToHorizontalRelative, arginfo_class_ImagickDraw_pathLineToHorizontalRelative, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, pathLineToVerticalAbsolute, arginfo_class_ImagickDraw_pathLineToVerticalAbsolute, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, pathLineToVerticalRelative, arginfo_class_ImagickDraw_pathLineToVerticalRelative, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, pathMoveToAbsolute, arginfo_class_ImagickDraw_pathMoveToAbsolute, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, pathMoveToRelative, arginfo_class_ImagickDraw_pathMoveToRelative, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, pathStart, arginfo_class_ImagickDraw_pathStart, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, polyline, arginfo_class_ImagickDraw_polyline, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, popClipPath, arginfo_class_ImagickDraw_popClipPath, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, popDefs, arginfo_class_ImagickDraw_popDefs, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, popPattern, arginfo_class_ImagickDraw_popPattern, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, pushClipPath, arginfo_class_ImagickDraw_pushClipPath, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, pushDefs, arginfo_class_ImagickDraw_pushDefs, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, pushPattern, arginfo_class_ImagickDraw_pushPattern, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, render, arginfo_class_ImagickDraw_render, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, rotate, arginfo_class_ImagickDraw_rotate, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, scale, arginfo_class_ImagickDraw_scale, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, setClipPath, arginfo_class_ImagickDraw_setClipPath, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, setClipRule, arginfo_class_ImagickDraw_setClipRule, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, setClipUnits, arginfo_class_ImagickDraw_setClipUnits, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, setFillOpacity, arginfo_class_ImagickDraw_setFillOpacity, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, setFillPatternUrl, arginfo_class_ImagickDraw_setFillPatternUrl, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, setFillRule, arginfo_class_ImagickDraw_setFillRule, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, setGravity, arginfo_class_ImagickDraw_setGravity, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, setStrokePatternUrl, arginfo_class_ImagickDraw_setStrokePatternUrl, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, setStrokeDashOffset, arginfo_class_ImagickDraw_setStrokeDashOffset, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, setStrokeLineCap, arginfo_class_ImagickDraw_setStrokeLineCap, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, setStrokeLineJoin, arginfo_class_ImagickDraw_setStrokeLineJoin, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, setStrokeMiterLimit, arginfo_class_ImagickDraw_setStrokeMiterLimit, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, setStrokeOpacity, arginfo_class_ImagickDraw_setStrokeOpacity, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, setVectorGraphics, arginfo_class_ImagickDraw_setVectorGraphics, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, pop, arginfo_class_ImagickDraw_pop, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, push, arginfo_class_ImagickDraw_push, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickDraw, setStrokeDashArray, arginfo_class_ImagickDraw_setStrokeDashArray, ZEND_ACC_PUBLIC)
#if MagickLibVersion >= 0x693
	ZEND_ME(ImagickDraw, getOpacity, arginfo_class_ImagickDraw_getOpacity, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion >= 0x693
	ZEND_ME(ImagickDraw, setOpacity, arginfo_class_ImagickDraw_setOpacity, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion >= 0x675
	ZEND_ME(ImagickDraw, getFontResolution, arginfo_class_ImagickDraw_getFontResolution, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion >= 0x675
	ZEND_ME(ImagickDraw, setFontResolution, arginfo_class_ImagickDraw_setFontResolution, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion >= 0x675
	ZEND_ME(ImagickDraw, getBorderColor, arginfo_class_ImagickDraw_getBorderColor, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion >= 0x675
	ZEND_ME(ImagickDraw, setBorderColor, arginfo_class_ImagickDraw_setBorderColor, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion >= 0x693
	ZEND_ME(ImagickDraw, setDensity, arginfo_class_ImagickDraw_setDensity, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion >= 0x693
	ZEND_ME(ImagickDraw, getDensity, arginfo_class_ImagickDraw_getDensity, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion >= 0x692
	ZEND_ME(ImagickDraw, getTextDirection, arginfo_class_ImagickDraw_getTextDirection, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion >= 0x692
	ZEND_ME(ImagickDraw, setTextDirection, arginfo_class_ImagickDraw_setTextDirection, ZEND_ACC_PUBLIC)
#endif
	ZEND_FE_END
};