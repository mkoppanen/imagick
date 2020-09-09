/* This is a generated file, edit the .stub.php file instead.
* Stub hash: regen with 'sh regen_arginfo.sh' */

#if MagickLibVersion > 0x628

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_optimizeImageLayers, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_optimizeImageLayers, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x628

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Imagick_compareImageLayers, 0, 1, Imagick, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_compareImageLayers, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, method, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, method)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x628

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_pingImageBlob, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_pingImageBlob, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, image, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, image)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x628

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_pingImageFile, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_pingImageFile, 0, 0, 2)
#endif

	ZEND_ARG_OBJ_INFO(0, filehandle, resource, 0)
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, fileName, IS_STRING, 1)
#else
    ZEND_ARG_INFO(0, fileName)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x628
#define arginfo_class_Imagick_transposeImage arginfo_class_Imagick_optimizeImageLayers
#endif

#if MagickLibVersion > 0x628
#define arginfo_class_Imagick_transverseImage arginfo_class_Imagick_optimizeImageLayers
#endif

#if MagickLibVersion > 0x628

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_trimImage, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_trimImage, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, fuzz, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, fuzz)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x628

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_waveImage, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_waveImage, 0, 0, 2)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, amplitude, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, amplitude)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, length, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, length)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x628

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_vignetteImage, 0, 4, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_vignetteImage, 0, 0, 4)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, blackPoint, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, blackPoint)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, whitePoint, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, whitePoint)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, x)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, y)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x628
#define arginfo_class_Imagick_uniqueImageColors arginfo_class_Imagick_optimizeImageLayers
#endif

#if MagickLibVersion > 0x628 && !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_getImageMatte, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getImageMatte, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x628

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImageMatte, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImageMatte, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, matte, _IS_BOOL, 0)
#else
    ZEND_ARG_INFO(0, matte)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x628

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_adaptiveResizeImage, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_adaptiveResizeImage, 0, 0, 2)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, columns, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, columns)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, rows, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, rows)
#endif
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, bestfit, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, legacy, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x628

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_sketchImage, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_sketchImage, 0, 0, 3)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, radius, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, radius)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, sigma, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, sigma)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, angle, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, angle)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x628

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_shadeImage, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_shadeImage, 0, 0, 3)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, gray, _IS_BOOL, 0)
#else
    ZEND_ARG_INFO(0, gray)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, azimuth, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, azimuth)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, elevation, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, elevation)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x628

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_getSizeOffset, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getSizeOffset, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x628

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setSizeOffset, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setSizeOffset, 0, 0, 3)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, columns, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, columns)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, rows, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, rows)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, offset)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x628

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_adaptiveBlurImage, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_adaptiveBlurImage, 0, 0, 2)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, radius, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, radius)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, sigma, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, sigma)
#endif
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, channel, IS_LONG, 0, "Imagick::CHANNEL_DEFAULT")
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x628

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_contrastStretchImage, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_contrastStretchImage, 0, 0, 2)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, black_point, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, black_point)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, white_point, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, white_point)
#endif
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, channel, IS_LONG, 0, "Imagick::CHANNEL_DEFAULT")
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x628
#define arginfo_class_Imagick_adaptiveSharpenImage arginfo_class_Imagick_adaptiveBlurImage
#endif

#if MagickLibVersion > 0x628

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_randomThresholdImage, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_randomThresholdImage, 0, 0, 2)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, low, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, low)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, high, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, high)
#endif
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, channel, IS_LONG, 0, "Imagick::CHANNEL_DEFAULT")
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x628 && MagickLibVersion < 0x700

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_roundCornersImage, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_roundCornersImage, 0, 0, 2)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x_rounding, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, x_rounding)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y_rounding, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, y_rounding)
#endif
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, stroke_width, IS_DOUBLE, 0, "10")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, displace, IS_DOUBLE, 0, "5")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, size_correction, IS_DOUBLE, 0, "-6")
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x628 && MagickLibVersion < 0x700
#define arginfo_class_Imagick_roundCorners arginfo_class_Imagick_roundCornersImage
#endif

#if MagickLibVersion > 0x628

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setIteratorIndex, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setIteratorIndex, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, index)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x628
#define arginfo_class_Imagick_getIteratorIndex arginfo_class_Imagick_getSizeOffset
#endif

#if MagickLibVersion > 0x628 && MagickLibVersion < 0x700

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Imagick_transformImage, 0, 2, Imagick, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_transformImage, 0, 0, 2)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, crop, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, crop)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, geometry, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, geometry)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x630 && MagickLibVersion < 0x700

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImageOpacity, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImageOpacity, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, opacity, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, opacity)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x630 && MagickLibVersion >= 0x700
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_class_Imagick_setImageAlpha, 0, 1, MAY_BE_NULL)
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, alpha, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, alpha)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x630 && MagickLibVersion < 0x700

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_orderedPosterizeImage, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_orderedPosterizeImage, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, threshold_map, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, threshold_map)
#endif
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, channel, IS_LONG, 0, "Imagick::CHANNEL_DEFAULT")
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x631

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_polaroidImage, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_polaroidImage, 0, 0, 2)
#endif

	ZEND_ARG_OBJ_INFO(0, properties, ImagickDraw, 0)
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, angle, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, angle)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x631

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_getImageProperty, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getImageProperty, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x631

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImageProperty, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImageProperty, 0, 0, 2)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, name)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x631

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_deleteImageProperty, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_deleteImageProperty, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x631

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_identifyFormat, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_identifyFormat, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, embedText, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, embedText)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x631

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImageInterpolateMethod, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImageInterpolateMethod, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, method, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, method)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x631

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_getImageInterpolateMethod, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getImageInterpolateMethod, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x631

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_linearStretchImage, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_linearStretchImage, 0, 0, 2)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, blackPoint, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, blackPoint)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, whitePoint, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, whitePoint)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x631
#define arginfo_class_Imagick_getImageLength arginfo_class_Imagick_getImageInterpolateMethod
#endif

#if MagickLibVersion > 0x631

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_extentImage, 0, 4, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_extentImage, 0, 0, 4)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, width)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, height)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, x)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, y)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x633

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_getImageOrientation, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getImageOrientation, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x633

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImageOrientation, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImageOrientation, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, orientation, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, orientation)
#endif
ZEND_END_ARG_INFO()
#endif

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion > 0x634 && MagickLibVersion < 0x700

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_paintFloodfillImage, 0, 5, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_paintFloodfillImage, 0, 0, 5)
#endif

	ZEND_ARG_OBJ_TYPE_MASK(0, fill, ImagickPixel, MAY_BE_STRING, NULL)
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, fuzz, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, fuzz)
#endif
	ZEND_ARG_OBJ_TYPE_MASK(0, bordercolor, ImagickPixel, MAY_BE_STRING, NULL)
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, x)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, y)
#endif
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, channel, IS_LONG, 0, "Imagick::CHANNEL_DEFAULT")
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x635

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_clutImage, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_clutImage, 0, 0, 1)
#endif

	ZEND_ARG_OBJ_INFO(0, lookup_table, imagick, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, channel, IS_LONG, 0, "Imagick::CHANNEL_DEFAULT")
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x635

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_getImageProperties, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getImageProperties, 0, 0, 0)
#endif

	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pattern, IS_STRING, 0, "\"*\"")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, include_values, _IS_BOOL, 0, "true")
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x635
#define arginfo_class_Imagick_getImageProfiles arginfo_class_Imagick_getImageProperties
#endif

#if MagickLibVersion > 0x635

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_distortImage, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_distortImage, 0, 0, 3)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, method, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, method)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, arguments, IS_ARRAY, 0)
#else
    ZEND_ARG_INFO(0, arguments)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, bestfit, _IS_BOOL, 0)
#else
    ZEND_ARG_INFO(0, bestfit)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x635

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_writeImageFile, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_writeImageFile, 0, 0, 2)
#endif

	ZEND_ARG_OBJ_INFO(0, filehandle, resource, 0)
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, format, IS_STRING, 1)
#else
    ZEND_ARG_INFO(0, format)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x635
#define arginfo_class_Imagick_writeImagesFile arginfo_class_Imagick_writeImageFile
#endif

#if MagickLibVersion > 0x635

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_resetImagePage, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_resetImagePage, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, page, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, page)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x635 && MagickLibVersion < 0x700

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImageClipMask, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImageClipMask, 0, 0, 1)
#endif

	ZEND_ARG_OBJ_INFO(0, clip_mask, imagick, 0)
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x635 && MagickLibVersion < 0x700

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Imagick_getImageClipMask, 0, 0, Imagick, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getImageClipMask, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x635

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_animateImages, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_animateImages, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x_server, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, x_server)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x635 && !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_recolorImage, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_recolorImage, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, matrix, IS_ARRAY, 0)
#else
    ZEND_ARG_INFO(0, matrix)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x636

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setFont, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setFont, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, font, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, font)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x636

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_getFont, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getFont, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x636

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setPointSize, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setPointSize, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, point_size, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, point_size)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x636

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_getPointSize, 0, 0, IS_DOUBLE, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getPointSize, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x636

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Imagick_mergeImageLayers, 0, 1, Imagick, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_mergeImageLayers, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, layer_method, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, layer_method)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x637

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImageAlphaChannel, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImageAlphaChannel, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, mode)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x637

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_floodfillPaintImage, 0, 6, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_floodfillPaintImage, 0, 0, 6)
#endif

	ZEND_ARG_OBJ_TYPE_MASK(0, fill, ImagickPixel, MAY_BE_STRING, NULL)
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, fuzz, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, fuzz)
#endif
	ZEND_ARG_OBJ_TYPE_MASK(0, target, ImagickPixel, MAY_BE_STRING, NULL)
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, x)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, y)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, invert, _IS_BOOL, 0)
#else
    ZEND_ARG_INFO(0, invert)
#endif
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, channel, IS_LONG, 1, "Imagick::CHANNEL_DEFAULT")
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x637

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_opaquePaintImage, 0, 4, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_opaquePaintImage, 0, 0, 4)
#endif

	ZEND_ARG_OBJ_TYPE_MASK(0, target, ImagickPixel, MAY_BE_STRING, NULL)
	ZEND_ARG_OBJ_TYPE_MASK(0, fill, ImagickPixel, MAY_BE_STRING, NULL)
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, fuzz, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, fuzz)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, invert, _IS_BOOL, 0)
#else
    ZEND_ARG_INFO(0, invert)
#endif
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, channel, IS_LONG, 0, "Imagick::CHANNEL_DEFAULT")
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x637

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_transparentPaintImage, 0, 4, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_transparentPaintImage, 0, 0, 4)
#endif

	ZEND_ARG_OBJ_TYPE_MASK(0, target, ImagickPixel, MAY_BE_STRING, NULL)
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, alpha, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, alpha)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, fuzz, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, fuzz)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, invert, _IS_BOOL, 0)
#else
    ZEND_ARG_INFO(0, invert)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x638

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_liquidRescaleImage, 0, 4, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_liquidRescaleImage, 0, 0, 4)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, width)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, height)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, delta_x, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, delta_x)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, rigidity, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, rigidity)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x638

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_encipherImage, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_encipherImage, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, passphrase, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, passphrase)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x638
#define arginfo_class_Imagick_decipherImage arginfo_class_Imagick_encipherImage
#endif

#if MagickLibVersion > 0x639

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setGravity, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setGravity, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, gravity, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, gravity)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x639

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_getGravity, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getGravity, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x639

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_getImageChannelRange, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getImageChannelRange, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, channel, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, channel)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x639
#define arginfo_class_Imagick_getImageAlphaChannel arginfo_class_Imagick_getGravity
#endif

#if MagickLibVersion > 0x642

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_getImageChannelDistortions, 0, 2, IS_DOUBLE, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getImageChannelDistortions, 0, 0, 2)
#endif

	ZEND_ARG_OBJ_INFO(0, reference, Imagick, 0)
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, metric, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, metric)
#endif
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, channel, IS_LONG, 0, "Imagick::CHANNEL_DEFAULT")
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x643

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImageGravity, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImageGravity, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, gravity, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, gravity)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x643

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_getImageGravity, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getImageGravity, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x645

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_importImagePixels, 0, 7, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_importImagePixels, 0, 0, 7)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, x)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, y)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, width)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, height)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, map, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, map)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, storage, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, storage)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, pixels, IS_ARRAY, 0)
#else
    ZEND_ARG_INFO(0, pixels)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x645

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_deskewImage, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_deskewImage, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, threshold, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, threshold)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x645

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_segmentImage, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_segmentImage, 0, 0, 3)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, COLORSPACE, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, COLORSPACE)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, cluster_threshold, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, cluster_threshold)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, smooth_threshold, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, smooth_threshold)
#endif
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, verbose, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x645

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_sparseColorImage, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_sparseColorImage, 0, 0, 2)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, SPARSE_METHOD, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, SPARSE_METHOD)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, arguments, IS_ARRAY, 0)
#else
    ZEND_ARG_INFO(0, arguments)
#endif
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, channel, IS_LONG, 0, "Imagick::CHANNEL_DEFAULT")
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x645

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_remapImage, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_remapImage, 0, 0, 2)
#endif

	ZEND_ARG_OBJ_INFO(0, replacement, imagick, 0)
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, DITHER, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, DITHER)
#endif
ZEND_END_ARG_INFO()
#endif

#if PHP_IMAGICK_HAVE_HOUGHLINE

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_houghLineImage, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_houghLineImage, 0, 0, 3)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, width)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, height)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, threshold, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, threshold)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x646

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_exportImagePixels, 0, 6, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_exportImagePixels, 0, 0, 6)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, x)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, y)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, width)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, height)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, map, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, map)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, STORAGE, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, STORAGE)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x648

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_getImageChannelKurtosis, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getImageChannelKurtosis, 0, 0, 0)
#endif

	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, channel, IS_LONG, 0, "Imagick::CHANNEL_DEFAULT")
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x648

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_functionImage, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_functionImage, 0, 0, 2)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, function, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, function)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, arguments, IS_ARRAY, 0)
#else
    ZEND_ARG_INFO(0, arguments)
#endif
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, channel, IS_LONG, 0, "Imagick::CHANNEL_DEFAULT")
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x651

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_transformImageColorspace, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_transformImageColorspace, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, colorspace, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, colorspace)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x652

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_haldClutImage, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_haldClutImage, 0, 0, 1)
#endif

	ZEND_ARG_OBJ_INFO(0, clut, Imagick, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, channel, IS_LONG, 0, "Imagick::CHANNEL_DEFAULT")
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x655

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_autoLevelImage, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_autoLevelImage, 0, 0, 0)
#endif

	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, channel, IS_LONG, 0, "Imagick::CHANNEL_DEFAULT")
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x655

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_blueShiftImage, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_blueShiftImage, 0, 0, 0)
#endif

	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, factor, IS_DOUBLE, 0, "1.5")
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x656

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_getImageArtifact, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getImageArtifact, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, artifact, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, artifact)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x656

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImageArtifact, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImageArtifact, 0, 0, 2)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, artifact, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, artifact)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x656

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_deleteImageArtifact, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_deleteImageArtifact, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, artifact, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, artifact)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x656

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_getColorspace, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getColorspace, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x656

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setColorspace, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setColorspace, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, COLORSPACE, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, COLORSPACE)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x656

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_clampImage, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_clampImage, 0, 0, 0)
#endif

	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, channel, IS_LONG, 0, "Imagick::CHANNEL_DEFAULT")
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x667

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Imagick_smushImages, 0, 2, Imagick, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_smushImages, 0, 0, 2)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, stack, _IS_BOOL, 0)
#else
    ZEND_ARG_INFO(0, stack)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, offset)
#endif
ZEND_END_ARG_INFO()
#endif

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick___construct, 0, 0, 1)
	ZEND_ARG_TYPE_MASK(0, files, MAY_BE_STRING|MAY_BE_ARRAY|MAY_BE_LONG|MAY_BE_DOUBLE|MAY_BE_NULL, NULL)
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick___toString, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick___toString, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 50600

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_count, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_count, 0, 0, 0)
#endif

	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, mode, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()
#endif

#if !(PHP_VERSION_ID >= 50600)

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_count, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_count, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()
#endif


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Imagick_getPixelIterator, 0, 0, ImagickPixelIterator, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getPixelIterator, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Imagick_getPixelRegionIterator, 0, 4, ImagickPixelIterator, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getPixelRegionIterator, 0, 0, 4)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, x)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, y)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, columns, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, columns)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, rows, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, rows)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_readImage, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_readImage, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, filename)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_readImages, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_readImages, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, filenames, IS_ARRAY, 0)
#else
    ZEND_ARG_INFO(0, filenames)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_readImageBlob, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_readImageBlob, 0, 0, 2)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, image, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, image)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 1)
#else
    ZEND_ARG_INFO(0, filename)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImageFormat, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImageFormat, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, format, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, format)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_scaleImage, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_scaleImage, 0, 0, 2)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, cols, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, cols)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, rows, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, rows)
#endif
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, bestfit, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, legacy, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_writeImage, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_writeImage, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 1)
#else
    ZEND_ARG_INFO(0, filename)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_writeImages, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_writeImages, 0, 0, 2)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, filename)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, adjoin, _IS_BOOL, 0)
#else
    ZEND_ARG_INFO(0, adjoin)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_blurImage, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_blurImage, 0, 0, 3)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, radius, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, radius)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, sigma, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, sigma)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, channel, IS_LONG, 1)
#else
    ZEND_ARG_INFO(0, channel)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_thumbnailImage, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_thumbnailImage, 0, 0, 2)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, columns, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, columns)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, rows, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, rows)
#endif
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, bestfit, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, fill, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, legacy, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_cropThumbnailImage, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_cropThumbnailImage, 0, 0, 2)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, width)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, height)
#endif
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, legacy, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

#define arginfo_class_Imagick_getImageFilename arginfo_class_Imagick___toString

#define arginfo_class_Imagick_setImageFilename arginfo_class_Imagick_readImage

#define arginfo_class_Imagick_getImageFormat arginfo_class_Imagick___toString

#define arginfo_class_Imagick_getImageMimeType arginfo_class_Imagick___toString


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_removeImage, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_removeImage, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()

#define arginfo_class_Imagick_destroy arginfo_class_Imagick_removeImage

#define arginfo_class_Imagick_clear arginfo_class_Imagick_removeImage


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Imagick_clone, 0, 0, Imagick, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_clone, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_getImageSize, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getImageSize, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()
#endif

#define arginfo_class_Imagick_getImageBlob arginfo_class_Imagick___toString

#define arginfo_class_Imagick_getImagesBlob arginfo_class_Imagick___toString

#define arginfo_class_Imagick_setFirstIterator arginfo_class_Imagick_removeImage

#define arginfo_class_Imagick_setLastIterator arginfo_class_Imagick_removeImage

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_class_Imagick_resetIterator, 0, 0, MAY_BE_NULL)
ZEND_END_ARG_INFO()

#define arginfo_class_Imagick_previousImage arginfo_class_Imagick_removeImage

#define arginfo_class_Imagick_nextImage arginfo_class_Imagick_removeImage

#define arginfo_class_Imagick_hasPreviousImage arginfo_class_Imagick_removeImage

#define arginfo_class_Imagick_hasNextImage arginfo_class_Imagick_removeImage

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImageIndex, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImageIndex, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, index)
#endif
ZEND_END_ARG_INFO()
#endif

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700
#define arginfo_class_Imagick_getImageIndex arginfo_class_Imagick_getImageSize
#endif


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_commentImage, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_commentImage, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, comment, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, comment)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_cropImage, 0, 4, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_cropImage, 0, 0, 4)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, width)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, height)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, x)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, y)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_labelImage, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_labelImage, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, label, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, label)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_getImageGeometry, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getImageGeometry, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_drawImage, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_drawImage, 0, 0, 1)
#endif

	ZEND_ARG_OBJ_INFO(0, draw, ImagickDraw, 0)
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImageCompressionQuality, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImageCompressionQuality, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, quality, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, quality)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_getImageCompressionQuality, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getImageCompressionQuality, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImageCompression, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImageCompression, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, compression, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, compression)
#endif
ZEND_END_ARG_INFO()

#define arginfo_class_Imagick_getImageCompression arginfo_class_Imagick_getImageCompressionQuality


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_annotateImage, 0, 5, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_annotateImage, 0, 0, 5)
#endif

	ZEND_ARG_OBJ_INFO(0, draw_settings, ImagickDraw, 0)
	
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
    ZEND_ARG_TYPE_INFO(0, angle, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, angle)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, text)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_compositeImage, 0, 4, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_compositeImage, 0, 0, 4)
#endif

	ZEND_ARG_OBJ_INFO(0, composite_object, Imagick, 0)
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, composite, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, composite)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, x)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, y)
#endif
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, channel, IS_LONG, 0, "Imagick::CHANNEL_DEFAULT")
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_modulateImage, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_modulateImage, 0, 0, 3)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, brightness, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, brightness)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, saturation, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, saturation)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, hue, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, hue)
#endif
ZEND_END_ARG_INFO()

#define arginfo_class_Imagick_getImageColors arginfo_class_Imagick_getImageCompressionQuality


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Imagick_montageImage, 0, 5, Imagick, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_montageImage, 0, 0, 5)
#endif

	ZEND_ARG_OBJ_INFO(0, draw, ImagickDraw, 0)
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, tile_geometry, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, tile_geometry)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, thumbnail_geometry, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, thumbnail_geometry)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, mode)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, frame, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, frame)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_identifyImage, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_identifyImage, 0, 0, 0)
#endif

	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, appendRawOutput, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_thresholdImage, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_thresholdImage, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, threshold, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, threshold)
#endif
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, channel, IS_LONG, 0, "Imagick::CHANNEL_DEFAULT")
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_adaptiveThresholdImage, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_adaptiveThresholdImage, 0, 0, 3)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, width)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, height)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, offset)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_blackThresholdImage, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_blackThresholdImage, 0, 0, 1)
#endif

	ZEND_ARG_OBJ_TYPE_MASK(0, threshold, ImagickPixel, MAY_BE_STRING, NULL)
ZEND_END_ARG_INFO()

#define arginfo_class_Imagick_whiteThresholdImage arginfo_class_Imagick_blackThresholdImage


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Imagick_appendImages, 0, 1, Imagick, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_appendImages, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, stack, _IS_BOOL, 0)
#else
    ZEND_ARG_INFO(0, stack)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_charcoalImage, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_charcoalImage, 0, 0, 2)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, radius, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, radius)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, sigma, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, sigma)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_normalizeImage, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_normalizeImage, 0, 0, 0)
#endif

	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, channel, IS_LONG, 0, "Imagick::CHANNEL_DEFAULT")
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_oilPaintImage, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_oilPaintImage, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, radius, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, radius)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_posterizeImage, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_posterizeImage, 0, 0, 2)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, levels, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, levels)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, dither, _IS_BOOL, 0)
#else
    ZEND_ARG_INFO(0, dither)
#endif
ZEND_END_ARG_INFO()

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_radialBlurImage, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_radialBlurImage, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, angle, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, angle)
#endif
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, channel, IS_LONG, 0, "Imagick::CHANNEL_DEFAULT")
ZEND_END_ARG_INFO()
#endif


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_raiseImage, 0, 5, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_raiseImage, 0, 0, 5)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, width)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, height)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, x)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, y)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, raise, _IS_BOOL, 0)
#else
    ZEND_ARG_INFO(0, raise)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_resampleImage, 0, 4, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_resampleImage, 0, 0, 4)
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
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, filter, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, filter)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, blur, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, blur)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_resizeImage, 0, 4, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_resizeImage, 0, 0, 4)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, columns, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, columns)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, rows, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, rows)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, filter, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, filter)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, blur, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, blur)
#endif
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, bestfit, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, legacy, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_rollImage, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_rollImage, 0, 0, 2)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, x)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, y)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_rotateImage, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_rotateImage, 0, 0, 2)
#endif

	ZEND_ARG_OBJ_TYPE_MASK(0, background, ImagickPixel, MAY_BE_STRING, NULL)
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, degrees, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, degrees)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_sampleImage, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_sampleImage, 0, 0, 2)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, columns, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, columns)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, rows, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, rows)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_solarizeImage, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_solarizeImage, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, threshold, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, threshold)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_shadowImage, 0, 4, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_shadowImage, 0, 0, 4)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, opacity, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, opacity)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, sigma, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, sigma)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, x)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, y)
#endif
ZEND_END_ARG_INFO()

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImageAttribute, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImageAttribute, 0, 0, 2)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, key)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()
#endif


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImageBackgroundColor, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImageBackgroundColor, 0, 0, 1)
#endif

	ZEND_ARG_OBJ_TYPE_MASK(0, background, ImagickPixel, MAY_BE_STRING, NULL)
ZEND_END_ARG_INFO()

#if MagickLibVersion >= 0x700

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImageChannelMask, 0, 1, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImageChannelMask, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, channel, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, channel)
#endif
ZEND_END_ARG_INFO()
#endif


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImageCompose, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImageCompose, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, compose, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, compose)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImageDelay, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImageDelay, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, delay, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, delay)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImageDepth, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImageDepth, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, depth, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, depth)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImageGamma, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImageGamma, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, gamma, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, gamma)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImageIterations, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImageIterations, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, iterations, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, iterations)
#endif
ZEND_END_ARG_INFO()

#if MagickLibVersion < 0x700

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImageMatteColor, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImageMatteColor, 0, 0, 1)
#endif

	ZEND_ARG_OBJ_TYPE_MASK(0, matte, ImagickPixel, MAY_BE_STRING, NULL)
ZEND_END_ARG_INFO()
#endif

#define arginfo_class_Imagick_setImagePage arginfo_class_Imagick_cropImage

#define arginfo_class_Imagick_setImageProgressMonitor arginfo_class_Imagick_readImage

#if MagickLibVersion > 0x653

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setProgressMonitor, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setProgressMonitor, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, callback, IS_CALLABLE, 0)
#else
    ZEND_ARG_INFO(0, callback)
#endif
ZEND_END_ARG_INFO()
#endif


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImageResolution, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImageResolution, 0, 0, 2)
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
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImageScene, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImageScene, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, scene, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, scene)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImageTicksPerSecond, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImageTicksPerSecond, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, ticks_per_second, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, ticks_per_second)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImageType, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImageType, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, image_type, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, image_type)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImageUnits, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImageUnits, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, units, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, units)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_sharpenImage, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_sharpenImage, 0, 0, 2)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, radius, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, radius)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, sigma, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, sigma)
#endif
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, channel, IS_LONG, 0, "Imagick::CHANNEL_DEFAULT")
ZEND_END_ARG_INFO()

#define arginfo_class_Imagick_shaveImage arginfo_class_Imagick_sampleImage


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_shearImage, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_shearImage, 0, 0, 3)
#endif

	ZEND_ARG_OBJ_TYPE_MASK(0, background, ImagickPixel, MAY_BE_STRING, NULL)
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x_shear, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, x_shear)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y_shear, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, y_shear)
#endif
ZEND_END_ARG_INFO()

#define arginfo_class_Imagick_spliceImage arginfo_class_Imagick_cropImage

#define arginfo_class_Imagick_pingImage arginfo_class_Imagick_readImage


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_readImageFile, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_readImageFile, 0, 0, 1)
#endif

	ZEND_ARG_OBJ_INFO(0, filehandle, resource, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, fileName, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_displayImage, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_displayImage, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, servername, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, servername)
#endif
ZEND_END_ARG_INFO()

#define arginfo_class_Imagick_displayImages arginfo_class_Imagick_displayImage

#define arginfo_class_Imagick_spreadImage arginfo_class_Imagick_oilPaintImage


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_swirlImage, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_swirlImage, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, degrees, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, degrees)
#endif
ZEND_END_ARG_INFO()

#define arginfo_class_Imagick_stripImage arginfo_class_Imagick_removeImage


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_queryFormats, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_queryFormats, 0, 0, 0)
#endif

	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pattern, IS_STRING, 0, "\"*\"")
ZEND_END_ARG_INFO()

#define arginfo_class_Imagick_queryFonts arginfo_class_Imagick_queryFormats


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_queryFontMetrics, 0, 3, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_queryFontMetrics, 0, 0, 3)
#endif

	ZEND_ARG_OBJ_INFO(0, properties, ImagickDraw, 0)
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, text)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, multiline, _IS_BOOL, 1)
#else
    ZEND_ARG_INFO(0, multiline)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Imagick_steganoImage, 0, 2, Imagick, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_steganoImage, 0, 0, 2)
#endif

	ZEND_ARG_OBJ_INFO(0, watermark_wand, imagick, 0)
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, offset)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_addNoiseImage, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_addNoiseImage, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, noise_type, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, noise_type)
#endif
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, channel, IS_LONG, 0, "Imagick::CHANNEL_DEFAULT")
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_motionBlurImage, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_motionBlurImage, 0, 0, 3)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, radius, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, radius)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, sigma, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, sigma)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, angle, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, angle)
#endif
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, channel, IS_LONG, 0, "Imagick::CHANNEL_DEFAULT")
ZEND_END_ARG_INFO()

#if MagickLibVersion < 0x700 && !defined(MAGICKCORE_EXCLUDE_DEPRECATED)

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Imagick_mosaicImages, 0, 0, Imagick, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_mosaicImages, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()
#endif


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Imagick_morphImages, 0, 1, Imagick, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_morphImages, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, number_frames, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, number_frames)
#endif
ZEND_END_ARG_INFO()

#define arginfo_class_Imagick_minifyImage arginfo_class_Imagick_removeImage


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_affineTransformImage, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_affineTransformImage, 0, 0, 1)
#endif

	ZEND_ARG_OBJ_INFO(0, matrix, ImagickDraw, 0)
ZEND_END_ARG_INFO()

#if MagickLibVersion < 0x700 && !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#define arginfo_class_Imagick_averageImages arginfo_class_Imagick_mosaicImages
#endif


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_borderImage, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_borderImage, 0, 0, 3)
#endif

	ZEND_ARG_OBJ_TYPE_MASK(0, bordercolor, ImagickPixel, MAY_BE_STRING, NULL)
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, width)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, height)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_calculateCrop, 0, 4, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_calculateCrop, 0, 0, 4)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, orig_width, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, orig_width)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, orig_height, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, orig_height)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, desired_width, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, desired_width)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, desired_height, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, desired_height)
#endif
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, legacy, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

#define arginfo_class_Imagick_chopImage arginfo_class_Imagick_cropImage

#define arginfo_class_Imagick_clipImage arginfo_class_Imagick_removeImage


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_clipPathImage, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_clipPathImage, 0, 0, 2)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, pathname, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, pathname)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, inside, _IS_BOOL, 0)
#else
    ZEND_ARG_INFO(0, inside)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_clipImagePath, 0, 2, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_clipImagePath, 0, 0, 2)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, pathname, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, pathname)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, inside, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, inside)
#endif
ZEND_END_ARG_INFO()

#define arginfo_class_Imagick_coalesceImages arginfo_class_Imagick_clone

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_colorFloodfillImage, 0, 5, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_colorFloodfillImage, 0, 0, 5)
#endif

	ZEND_ARG_OBJ_TYPE_MASK(0, fill, ImagickPixel, MAY_BE_STRING, NULL)
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, fuzz, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, fuzz)
#endif
	ZEND_ARG_OBJ_TYPE_MASK(0, bordercolor, ImagickPixel, MAY_BE_STRING, NULL)
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, x)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, y)
#endif
ZEND_END_ARG_INFO()
#endif


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_colorizeImage, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_colorizeImage, 0, 0, 2)
#endif

	ZEND_ARG_OBJ_TYPE_MASK(0, colorize, ImagickPixel, MAY_BE_STRING, NULL)
	ZEND_ARG_OBJ_TYPE_MASK(0, opacity, ImagickPixel, MAY_BE_STRING, NULL)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, legacy, _IS_BOOL, 1, "false")
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_compareImageChannels, 0, 3, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_compareImageChannels, 0, 0, 3)
#endif

	ZEND_ARG_OBJ_INFO(0, image, imagick, 0)
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, channelType, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, channelType)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, metricType, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, metricType)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_compareImages, 0, 2, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_compareImages, 0, 0, 2)
#endif

	ZEND_ARG_OBJ_INFO(0, compare, imagick, 0)
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, metric, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, metric)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_contrastImage, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_contrastImage, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, sharpen, _IS_BOOL, 0)
#else
    ZEND_ARG_INFO(0, sharpen)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Imagick_combineImages, 0, 1, Imagick, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_combineImages, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, channelType, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, channelType)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_convolveImage, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_convolveImage, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, kernel, IS_ARRAY, 0)
#else
    ZEND_ARG_INFO(0, kernel)
#endif
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, channel, IS_LONG, 0, "Imagick::CHANNEL_DEFAULT")
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_cycleColormapImage, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_cycleColormapImage, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, displace, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, displace)
#endif
ZEND_END_ARG_INFO()

#define arginfo_class_Imagick_deconstructImages arginfo_class_Imagick_clone

#define arginfo_class_Imagick_despeckleImage arginfo_class_Imagick_removeImage

#define arginfo_class_Imagick_edgeImage arginfo_class_Imagick_oilPaintImage

#define arginfo_class_Imagick_embossImage arginfo_class_Imagick_charcoalImage

#define arginfo_class_Imagick_enhanceImage arginfo_class_Imagick_removeImage

#define arginfo_class_Imagick_equalizeImage arginfo_class_Imagick_removeImage


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_evaluateImage, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_evaluateImage, 0, 0, 2)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, op, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, op)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, constant, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, constant)
#endif
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, channel, IS_LONG, 0, "Imagick::CHANNEL_DEFAULT")
ZEND_END_ARG_INFO()

#if MagickLibVersion >= 0x687

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_evaluateImages, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_evaluateImages, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, EVALUATE_CONSTANT, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, EVALUATE_CONSTANT)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion < 0x700 && !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#define arginfo_class_Imagick_flattenImages arginfo_class_Imagick_mosaicImages
#endif

#define arginfo_class_Imagick_flipImage arginfo_class_Imagick_removeImage

#define arginfo_class_Imagick_flopImage arginfo_class_Imagick_removeImage

#if MagickLibVersion >= 0x655

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_forwardFourierTransformImage, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_forwardFourierTransformImage, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, magnitude, _IS_BOOL, 0)
#else
    ZEND_ARG_INFO(0, magnitude)
#endif
ZEND_END_ARG_INFO()
#endif


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_frameImage, 0, 5, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_frameImage, 0, 0, 5)
#endif

	ZEND_ARG_OBJ_TYPE_MASK(0, matte_color, ImagickPixel, MAY_BE_STRING, NULL)
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, width)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, height)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, inner_bevel, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, inner_bevel)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, outer_bevel, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, outer_bevel)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Imagick_fxImage, 0, 1, Imagick, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_fxImage, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, expression, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, expression)
#endif
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, channel, IS_LONG, 0, "Imagick::CHANNEL_DEFAULT")
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_gammaImage, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_gammaImage, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, gamma, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, gamma)
#endif
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, channel, IS_LONG, 0, "Imagick::CHANNEL_DEFAULT")
ZEND_END_ARG_INFO()

#define arginfo_class_Imagick_gaussianBlurImage arginfo_class_Imagick_sharpenImage

#if MagickLibVersion < 0x700 && !defined(MAGICKCORE_EXCLUDE_DEPRECATED)

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_getImageAttribute, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getImageAttribute, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()
#endif


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Imagick_getImageBackgroundColor, 0, 0, ImagickPixel, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getImageBackgroundColor, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()

#define arginfo_class_Imagick_getImageBluePrimary arginfo_class_Imagick_getImageGeometry

#define arginfo_class_Imagick_getImageBorderColor arginfo_class_Imagick_getImageBackgroundColor


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_getImageChannelDepth, 0, 1, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getImageChannelDepth, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, channel, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, channel)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_getImageChannelDistortion, 0, 3, IS_DOUBLE, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getImageChannelDistortion, 0, 0, 3)
#endif

	ZEND_ARG_OBJ_INFO(0, reference, imagick, 0)
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, channel, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, channel)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, metric, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, metric)
#endif
ZEND_END_ARG_INFO()

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_getImageChannelExtrema, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getImageChannelExtrema, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, channel, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, channel)
#endif
ZEND_END_ARG_INFO()
#endif


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_getImageChannelMean, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getImageChannelMean, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, channel, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, channel)
#endif
ZEND_END_ARG_INFO()

#define arginfo_class_Imagick_getImageChannelStatistics arginfo_class_Imagick_getImageGeometry


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Imagick_getImageColormapColor, 0, 1, ImagickPixel, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getImageColormapColor, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, index)
#endif
ZEND_END_ARG_INFO()

#define arginfo_class_Imagick_getImageColorspace arginfo_class_Imagick_getImageCompressionQuality

#define arginfo_class_Imagick_getImageCompose arginfo_class_Imagick_getImageCompressionQuality

#define arginfo_class_Imagick_getImageDelay arginfo_class_Imagick_getImageCompressionQuality

#define arginfo_class_Imagick_getImageDepth arginfo_class_Imagick_getImageCompressionQuality


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_getImageDistortion, 0, 2, IS_DOUBLE, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getImageDistortion, 0, 0, 2)
#endif

	ZEND_ARG_OBJ_INFO(0, reference, Imagick, 0)
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, metric, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, metric)
#endif
ZEND_END_ARG_INFO()

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_getImageExtrema, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getImageExtrema, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()
#endif

#define arginfo_class_Imagick_getImageDispose arginfo_class_Imagick_getImageCompressionQuality


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_getImageGamma, 0, 0, IS_DOUBLE, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getImageGamma, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()

#define arginfo_class_Imagick_getImageGreenPrimary arginfo_class_Imagick_getImageGeometry

#define arginfo_class_Imagick_getImageHeight arginfo_class_Imagick_getImageCompressionQuality

#define arginfo_class_Imagick_getImageHistogram arginfo_class_Imagick_getImageGeometry

#define arginfo_class_Imagick_getImageInterlaceScheme arginfo_class_Imagick_getImageCompressionQuality

#define arginfo_class_Imagick_getImageIterations arginfo_class_Imagick_getImageCompressionQuality

#if MagickLibVersion < 0x700

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Imagick_getImageMatteColor, 0, 0, ImagickPixel, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getImageMatteColor, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()
#endif

#define arginfo_class_Imagick_getImagePage arginfo_class_Imagick_getImageGeometry


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Imagick_getImagePixelColor, 0, 2, ImagickPixel, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getImagePixelColor, 0, 0, 2)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, x)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, y)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_getImageProfile, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getImageProfile, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#define arginfo_class_Imagick_getImageRedPrimary arginfo_class_Imagick_getImageGeometry

#define arginfo_class_Imagick_getImageRenderingIntent arginfo_class_Imagick_getImageCompressionQuality

#define arginfo_class_Imagick_getImageResolution arginfo_class_Imagick_getImageGeometry

#define arginfo_class_Imagick_getImageScene arginfo_class_Imagick_getImageCompressionQuality

#define arginfo_class_Imagick_getImageSignature arginfo_class_Imagick___toString

#define arginfo_class_Imagick_getImageTicksPerSecond arginfo_class_Imagick_getImageCompressionQuality

#define arginfo_class_Imagick_getImageType arginfo_class_Imagick_getImageCompressionQuality

#define arginfo_class_Imagick_getImageUnits arginfo_class_Imagick_getImageCompressionQuality

#define arginfo_class_Imagick_getImageVirtualPixelMethod arginfo_class_Imagick_getImageCompressionQuality

#define arginfo_class_Imagick_getImageWhitePoint arginfo_class_Imagick_getImageGeometry

#define arginfo_class_Imagick_getImageWidth arginfo_class_Imagick_getImageCompressionQuality

#define arginfo_class_Imagick_getNumberImages arginfo_class_Imagick_getImageCompressionQuality

#define arginfo_class_Imagick_getImageTotalInkDensity arginfo_class_Imagick_getImageGamma


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Imagick_getImageRegion, 0, 4, Imagick, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getImageRegion, 0, 0, 4)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, width)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, height)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, x)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, y)
#endif
ZEND_END_ARG_INFO()

#define arginfo_class_Imagick_implodeImage arginfo_class_Imagick_oilPaintImage

#if MagickLibVersion >= 0x658

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_inverseFourierTransformImage, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_inverseFourierTransformImage, 0, 0, 2)
#endif

	ZEND_ARG_OBJ_INFO(0, complement, imagick, 0)
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, magnitude, _IS_BOOL, 0)
#else
    ZEND_ARG_INFO(0, magnitude)
#endif
ZEND_END_ARG_INFO()
#endif


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_levelImage, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_levelImage, 0, 0, 3)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, blackPoint, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, blackPoint)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, gamma, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, gamma)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, whitePoint, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, whitePoint)
#endif
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, channel, IS_LONG, 0, "Imagick::CHANNEL_DEFAULT")
ZEND_END_ARG_INFO()

#define arginfo_class_Imagick_magnifyImage arginfo_class_Imagick_removeImage

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_mapImage, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_mapImage, 0, 0, 2)
#endif

	ZEND_ARG_OBJ_INFO(0, map, imagick, 0)
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, dither, _IS_BOOL, 0)
#else
    ZEND_ARG_INFO(0, dither)
#endif
ZEND_END_ARG_INFO()
#endif

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_matteFloodfillImage, 0, 5, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_matteFloodfillImage, 0, 0, 5)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, alpha, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, alpha)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, fuzz, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, fuzz)
#endif
	ZEND_ARG_OBJ_TYPE_MASK(0, bordercolor, ImagickPixel, MAY_BE_STRING, NULL)
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, x)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, y)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion < 0x700 && !defined(MAGICKCORE_EXCLUDE_DEPRECATED)

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_medianFilterImage, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_medianFilterImage, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, radius, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, radius)
#endif
ZEND_END_ARG_INFO()
#endif


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_negateImage, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_negateImage, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, gray, _IS_BOOL, 0)
#else
    ZEND_ARG_INFO(0, gray)
#endif
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, channel, IS_LONG, 0, "Imagick::CHANNEL_DEFAULT")
ZEND_END_ARG_INFO()

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_paintOpaqueImage, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_paintOpaqueImage, 0, 0, 3)
#endif

	ZEND_ARG_OBJ_TYPE_MASK(0, target, ImagickPixel, MAY_BE_STRING, NULL)
	ZEND_ARG_OBJ_TYPE_MASK(0, fill, ImagickPixel, MAY_BE_STRING, NULL)
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, fuzz, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, fuzz)
#endif
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, channel, IS_LONG, 0, "Imagick::CHANNEL_DEFAULT")
ZEND_END_ARG_INFO()
#endif

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_paintTransparentImage, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_paintTransparentImage, 0, 0, 3)
#endif

	ZEND_ARG_OBJ_TYPE_MASK(0, target, ImagickPixel, MAY_BE_STRING, NULL)
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, alpha, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, alpha)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, fuzz, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, fuzz)
#endif
ZEND_END_ARG_INFO()
#endif


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_previewImages, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_previewImages, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, preview, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, preview)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_profileImage, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_profileImage, 0, 0, 2)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, name)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, profile, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, profile)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_quantizeImage, 0, 5, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_quantizeImage, 0, 0, 5)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, numberColors, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, numberColors)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, colorspace, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, colorspace)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, treedepth, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, treedepth)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, dither, _IS_BOOL, 0)
#else
    ZEND_ARG_INFO(0, dither)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, measureError, _IS_BOOL, 0)
#else
    ZEND_ARG_INFO(0, measureError)
#endif
ZEND_END_ARG_INFO()

#define arginfo_class_Imagick_quantizeImages arginfo_class_Imagick_quantizeImage

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_reduceNoiseImage, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_reduceNoiseImage, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, radius, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, radius)
#endif
ZEND_END_ARG_INFO()
#endif

#define arginfo_class_Imagick_removeImageProfile arginfo_class_Imagick_getImageProfile


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_separateImageChannel, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_separateImageChannel, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, channel, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, channel)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_sepiaToneImage, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_sepiaToneImage, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, threshold, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, threshold)
#endif
ZEND_END_ARG_INFO()

#if MagickLibVersion < 0x700

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImageBias, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImageBias, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, bias, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, bias)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion < 0x700

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImageBiasQuantum, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImageBiasQuantum, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, bias, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, bias)
#endif
ZEND_END_ARG_INFO()
#endif


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImageBluePrimary, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImageBluePrimary, 0, 0, 2)
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
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImageBorderColor, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImageBorderColor, 0, 0, 1)
#endif

	ZEND_ARG_OBJ_TYPE_MASK(0, border, ImagickPixel, MAY_BE_STRING, NULL)
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImageChannelDepth, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImageChannelDepth, 0, 0, 2)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, channel, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, channel)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, depth, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, depth)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImageColormapColor, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImageColormapColor, 0, 0, 2)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, index)
#endif
	ZEND_ARG_OBJ_INFO(0, color, ImagickPixel, 0)
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImageColorspace, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImageColorspace, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, colorspace, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, colorspace)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImageDispose, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImageDispose, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, dispose, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, dispose)
#endif
ZEND_END_ARG_INFO()

#define arginfo_class_Imagick_setImageExtent arginfo_class_Imagick_sampleImage

#define arginfo_class_Imagick_setImageGreenPrimary arginfo_class_Imagick_setImageBluePrimary


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImageInterlaceScheme, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImageInterlaceScheme, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, interlace_scheme, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, interlace_scheme)
#endif
ZEND_END_ARG_INFO()

#define arginfo_class_Imagick_setImageProfile arginfo_class_Imagick_profileImage

#define arginfo_class_Imagick_setImageRedPrimary arginfo_class_Imagick_setImageBluePrimary


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImageRenderingIntent, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImageRenderingIntent, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, rendering_intent, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, rendering_intent)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImageVirtualPixelMethod, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImageVirtualPixelMethod, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, method, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, method)
#endif
ZEND_END_ARG_INFO()

#define arginfo_class_Imagick_setImageWhitePoint arginfo_class_Imagick_setImageBluePrimary


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_sigmoidalContrastImage, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_sigmoidalContrastImage, 0, 0, 3)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, sharpen, _IS_BOOL, 0)
#else
    ZEND_ARG_INFO(0, sharpen)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, alpha, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, alpha)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, beta, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, beta)
#endif
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, channel, IS_LONG, 0, "Imagick::CHANNEL_DEFAULT")
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_stereoImage, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_stereoImage, 0, 0, 1)
#endif

	ZEND_ARG_OBJ_INFO(0, offset_wand, imagick, 0)
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Imagick_textureImage, 0, 1, Imagick, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_textureImage, 0, 0, 1)
#endif

	ZEND_ARG_OBJ_INFO(0, texture_wand, imagick, 0)
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_tintImage, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_tintImage, 0, 0, 2)
#endif

	ZEND_ARG_OBJ_TYPE_MASK(0, tint, ImagickPixel, MAY_BE_STRING, NULL)
	ZEND_ARG_OBJ_TYPE_MASK(0, opacity, ImagickPixel, MAY_BE_STRING, NULL)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, legacy, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_unsharpMaskImage, 0, 4, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_unsharpMaskImage, 0, 0, 4)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, radius, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, radius)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, sigma, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, sigma)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, amount, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, amount)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, threshold, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, threshold)
#endif
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, channel, IS_LONG, 0, "Imagick::CHANNEL_DEFAULT")
ZEND_END_ARG_INFO()

#define arginfo_class_Imagick_getImage arginfo_class_Imagick_clone


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_addImage, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_addImage, 0, 0, 1)
#endif

	ZEND_ARG_OBJ_INFO(0, source, imagick, 0)
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setImage, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setImage, 0, 0, 1)
#endif

	ZEND_ARG_OBJ_INFO(0, replace, imagick, 0)
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_newImage, 0, 4, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_newImage, 0, 0, 4)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, cols, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, cols)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, rows, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, rows)
#endif
	ZEND_ARG_OBJ_TYPE_MASK(0, background, ImagickPixel, MAY_BE_STRING, NULL)
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, format, IS_STRING, 1)
#else
    ZEND_ARG_INFO(0, format)
#endif
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_newPseudoImage, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_newPseudoImage, 0, 0, 3)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, columns, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, columns)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, rows, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, rows)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, pseudoString, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, pseudoString)
#endif
ZEND_END_ARG_INFO()

#define arginfo_class_Imagick_getCompression arginfo_class_Imagick_getImageCompressionQuality

#define arginfo_class_Imagick_getCompressionQuality arginfo_class_Imagick_getImageCompressionQuality

#define arginfo_class_Imagick_getCopyright arginfo_class_Imagick___toString


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_getConfigureOptions, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getConfigureOptions, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 1)
#else
    ZEND_ARG_INFO(0, pattern)
#endif
ZEND_END_ARG_INFO()

#if MagickLibVersion > 0x660

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_getFeatures, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getFeatures, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()
#endif

#define arginfo_class_Imagick_getFilename arginfo_class_Imagick___toString

#define arginfo_class_Imagick_getFormat arginfo_class_Imagick___toString

#define arginfo_class_Imagick_getHomeURL arginfo_class_Imagick___toString

#define arginfo_class_Imagick_getInterlaceScheme arginfo_class_Imagick_getImageCompressionQuality


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_getOption, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getOption, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

#define arginfo_class_Imagick_getPackageName arginfo_class_Imagick___toString

#define arginfo_class_Imagick_getPage arginfo_class_Imagick_getImageGeometry

#define arginfo_class_Imagick_getQuantum arginfo_class_Imagick_getImageCompressionQuality

#define arginfo_class_Imagick_getHdriEnabled arginfo_class_Imagick_removeImage

#define arginfo_class_Imagick_getQuantumDepth arginfo_class_Imagick_getImageGeometry

#define arginfo_class_Imagick_getQuantumRange arginfo_class_Imagick_getImageGeometry

#define arginfo_class_Imagick_getReleaseDate arginfo_class_Imagick___toString


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_getResource, 0, 1, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getResource, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, type)
#endif
ZEND_END_ARG_INFO()

#define arginfo_class_Imagick_getResourceLimit arginfo_class_Imagick_getResource

#define arginfo_class_Imagick_getSamplingFactors arginfo_class_Imagick_getImageGeometry

#define arginfo_class_Imagick_getSize arginfo_class_Imagick_getImageGeometry

#define arginfo_class_Imagick_getVersion arginfo_class_Imagick_getImageGeometry

#define arginfo_class_Imagick_setBackgroundColor arginfo_class_Imagick_setImageBackgroundColor

#define arginfo_class_Imagick_setCompression arginfo_class_Imagick_setImageCompression

#define arginfo_class_Imagick_setCompressionQuality arginfo_class_Imagick_setImageCompressionQuality

#define arginfo_class_Imagick_setFilename arginfo_class_Imagick_readImage

#define arginfo_class_Imagick_setFormat arginfo_class_Imagick_setImageFormat

#define arginfo_class_Imagick_setInterlaceScheme arginfo_class_Imagick_setImageInterlaceScheme


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setOption, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setOption, 0, 0, 2)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, key)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

#define arginfo_class_Imagick_setPage arginfo_class_Imagick_cropImage


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setResourceLimit, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setResourceLimit, 0, 0, 2)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, type)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, limit, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, limit)
#endif
ZEND_END_ARG_INFO()

#define arginfo_class_Imagick_setResolution arginfo_class_Imagick_setImageResolution


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setSamplingFactors, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setSamplingFactors, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, factors, IS_ARRAY, 0)
#else
    ZEND_ARG_INFO(0, factors)
#endif
ZEND_END_ARG_INFO()

#define arginfo_class_Imagick_setSize arginfo_class_Imagick_sampleImage

#define arginfo_class_Imagick_setType arginfo_class_Imagick_setImageType

#if MagickLibVersion > 0x628
#define arginfo_class_Imagick_key arginfo_class_Imagick_getSizeOffset
#endif

#if MagickLibVersion > 0x628
#define arginfo_class_Imagick_next arginfo_class_Imagick_optimizeImageLayers
#endif

#if MagickLibVersion > 0x628
#define arginfo_class_Imagick_rewind arginfo_class_Imagick_optimizeImageLayers
#endif

#if MagickLibVersion > 0x628
#define arginfo_class_Imagick_valid arginfo_class_Imagick_optimizeImageLayers
#endif

#if MagickLibVersion > 0x628

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Imagick_current, 0, 0, Imagick, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_current, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x628 && MagickLibVersion >= 0x659

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_brightnessContrastImage, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_brightnessContrastImage, 0, 0, 2)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, brightness, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, brightness)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, contrast, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, contrast)
#endif
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, channel, IS_LONG, 0, "Imagick::CHANNEL_DEFAULT")
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x628 && MagickLibVersion > 0x661

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_colorMatrixImage, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_colorMatrixImage, 0, 0, 0)
#endif

	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, color_matrix, IS_ARRAY, 0, "Imagick::CHANNEL_DEFAULT")
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x628

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_selectiveBlurImage, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_selectiveBlurImage, 0, 0, 3)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, radius, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, radius)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, sigma, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, sigma)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, threshold, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, threshold)
#endif
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, channel, IS_LONG, 0, "Imagick::CHANNEL_DEFAULT")
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x628 && MagickLibVersion >= 0x689

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_rotationalBlurImage, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_rotationalBlurImage, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, angle, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, angle)
#endif
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, channel, IS_LONG, 0, "Imagick::CHANNEL_DEFAULT")
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x628 && MagickLibVersion >= 0x683

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_statisticImage, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_statisticImage, 0, 0, 3)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, type)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, width)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, height)
#endif
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, channel, IS_LONG, 0, "Imagick::CHANNEL_DEFAULT")
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x628 && MagickLibVersion >= 0x652

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Imagick_subimageMatch, 0, 3, Imagick, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_subimageMatch, 0, 0, 3)
#endif

	ZEND_ARG_OBJ_INFO(0, Imagick, imagick, 0)
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(1, offset, IS_ARRAY, 1)
#else
    ZEND_ARG_INFO(1, offset)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(1, similarity, IS_DOUBLE, 1)
#else
    ZEND_ARG_INFO(1, similarity)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x628 && MagickLibVersion >= 0x652
#define arginfo_class_Imagick_similarityimage arginfo_class_Imagick_subimageMatch
#endif

#if MagickLibVersion > 0x628

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_setRegistry, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_setRegistry, 0, 0, 2)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, key)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x628

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_getRegistry, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_getRegistry, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x628

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_listRegistry, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_listRegistry, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x628 && MagickLibVersion >= 0x680

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_morphology, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_morphology, 0, 0, 3)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, morphologyMethod, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, morphologyMethod)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, iterations, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, iterations)
#endif
	ZEND_ARG_OBJ_INFO(0, ImagickKernel, ImagickKernel, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, channel, IS_LONG, 0, "Imagick::CHANNEL_DEFAULT")
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x628 && defined(IMAGICK_WITH_KERNEL) && MagickLibVersion < 0x700

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_filter, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_filter, 0, 0, 1)
#endif

	ZEND_ARG_OBJ_INFO(0, ImagickKernel, ImagickKernel, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, channel, IS_LONG, 0, "Imagick::CHANNEL_UNDEFINED")
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x628
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_class_Imagick_setAntialias, 0, 1, MAY_BE_NULL)
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, antialias, _IS_BOOL, 0)
#else
    ZEND_ARG_INFO(0, antialias)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x628
#define arginfo_class_Imagick_getAntialias arginfo_class_Imagick_optimizeImageLayers
#endif

#if MagickLibVersion > 0x628 && MagickLibVersion > 0x676

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_colorDecisionListImage, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_colorDecisionListImage, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, color_correction_collection, IS_STRING, 0)
#else
    ZEND_ARG_INFO(0, color_correction_collection)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x628 && MagickLibVersion >= 0x687
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_class_Imagick_optimizeImageTransparency, 0, 0, MAY_BE_NULL)
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x628 && MagickLibVersion >= 0x660
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_class_Imagick_autoGammaImage, 0, 0, MAY_BE_NULL)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, channel, IS_LONG, 1, "Imagick::CHANNEL_ALL")
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x628 && MagickLibVersion >= 0x692
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_class_Imagick_autoOrient, 0, 0, MAY_BE_NULL)
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x628 && MagickLibVersion >= 0x692
#define arginfo_class_Imagick_autoOrientate arginfo_class_Imagick_autoOrient
#endif

#if MagickLibVersion > 0x628 && MagickLibVersion >= 0x692

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_compositeImageGravity, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_compositeImageGravity, 0, 0, 3)
#endif

	ZEND_ARG_OBJ_INFO(0, image, Imagick, 0)
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, COMPOSITE_CONSTANT, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, COMPOSITE_CONSTANT)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, GRAVITY_CONSTANT, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, GRAVITY_CONSTANT)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x628 && MagickLibVersion >= 0x693
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_class_Imagick_localContrastImage, 0, 2, MAY_BE_NULL)
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, radius, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, radius)
#endif
	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, strength, IS_DOUBLE, 0)
#else
    ZEND_ARG_INFO(0, strength)
#endif
ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x628 && MagickLibVersion >= 0x700

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Imagick_identifyImageType, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Imagick_identifyImageType, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()
#endif


#if MagickLibVersion > 0x628
ZEND_METHOD(Imagick, optimizeImageLayers);
#endif
#if MagickLibVersion > 0x628
ZEND_METHOD(Imagick, compareImageLayers);
#endif
#if MagickLibVersion > 0x628
ZEND_METHOD(Imagick, pingImageBlob);
#endif
#if MagickLibVersion > 0x628
ZEND_METHOD(Imagick, pingImageFile);
#endif
#if MagickLibVersion > 0x628
ZEND_METHOD(Imagick, transposeImage);
#endif
#if MagickLibVersion > 0x628
ZEND_METHOD(Imagick, transverseImage);
#endif
#if MagickLibVersion > 0x628
ZEND_METHOD(Imagick, trimImage);
#endif
#if MagickLibVersion > 0x628
ZEND_METHOD(Imagick, waveImage);
#endif
#if MagickLibVersion > 0x628
ZEND_METHOD(Imagick, vignetteImage);
#endif
#if MagickLibVersion > 0x628
ZEND_METHOD(Imagick, uniqueImageColors);
#endif
#if MagickLibVersion > 0x628 && !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700
ZEND_METHOD(Imagick, getImageMatte);
#endif
#if MagickLibVersion > 0x628
ZEND_METHOD(Imagick, setImageMatte);
#endif
#if MagickLibVersion > 0x628
ZEND_METHOD(Imagick, adaptiveResizeImage);
#endif
#if MagickLibVersion > 0x628
ZEND_METHOD(Imagick, sketchImage);
#endif
#if MagickLibVersion > 0x628
ZEND_METHOD(Imagick, shadeImage);
#endif
#if MagickLibVersion > 0x628
ZEND_METHOD(Imagick, getSizeOffset);
#endif
#if MagickLibVersion > 0x628
ZEND_METHOD(Imagick, setSizeOffset);
#endif
#if MagickLibVersion > 0x628
ZEND_METHOD(Imagick, adaptiveBlurImage);
#endif
#if MagickLibVersion > 0x628
ZEND_METHOD(Imagick, contrastStretchImage);
#endif
#if MagickLibVersion > 0x628
ZEND_METHOD(Imagick, adaptiveSharpenImage);
#endif
#if MagickLibVersion > 0x628
ZEND_METHOD(Imagick, randomThresholdImage);
#endif
#if MagickLibVersion > 0x628 && MagickLibVersion < 0x700
ZEND_METHOD(Imagick, roundCornersImage);
#endif
#if MagickLibVersion > 0x628
ZEND_METHOD(Imagick, setIteratorIndex);
#endif
#if MagickLibVersion > 0x628
ZEND_METHOD(Imagick, getIteratorIndex);
#endif
#if MagickLibVersion > 0x628 && MagickLibVersion < 0x700
ZEND_METHOD(Imagick, transformImage);
#endif
#if MagickLibVersion > 0x630 && MagickLibVersion < 0x700
ZEND_METHOD(Imagick, setImageOpacity);
#endif
#if MagickLibVersion > 0x630 && MagickLibVersion >= 0x700
ZEND_METHOD(Imagick, setImageAlpha);
#endif
#if MagickLibVersion > 0x630 && MagickLibVersion < 0x700
ZEND_METHOD(Imagick, orderedPosterizeImage);
#endif
#if MagickLibVersion > 0x631
ZEND_METHOD(Imagick, polaroidImage);
#endif
#if MagickLibVersion > 0x631
ZEND_METHOD(Imagick, getImageProperty);
#endif
#if MagickLibVersion > 0x631
ZEND_METHOD(Imagick, setImageProperty);
#endif
#if MagickLibVersion > 0x631
ZEND_METHOD(Imagick, deleteImageProperty);
#endif
#if MagickLibVersion > 0x631
ZEND_METHOD(Imagick, identifyFormat);
#endif
#if MagickLibVersion > 0x631
ZEND_METHOD(Imagick, setImageInterpolateMethod);
#endif
#if MagickLibVersion > 0x631
ZEND_METHOD(Imagick, getImageInterpolateMethod);
#endif
#if MagickLibVersion > 0x631
ZEND_METHOD(Imagick, linearStretchImage);
#endif
#if MagickLibVersion > 0x631
ZEND_METHOD(Imagick, getImageLength);
#endif
#if MagickLibVersion > 0x631
ZEND_METHOD(Imagick, extentImage);
#endif
#if MagickLibVersion > 0x633
ZEND_METHOD(Imagick, getImageOrientation);
#endif
#if MagickLibVersion > 0x633
ZEND_METHOD(Imagick, setImageOrientation);
#endif
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion > 0x634 && MagickLibVersion < 0x700
ZEND_METHOD(Imagick, paintFloodfillImage);
#endif
#if MagickLibVersion > 0x635
ZEND_METHOD(Imagick, clutImage);
#endif
#if MagickLibVersion > 0x635
ZEND_METHOD(Imagick, getImageProperties);
#endif
#if MagickLibVersion > 0x635
ZEND_METHOD(Imagick, getImageProfiles);
#endif
#if MagickLibVersion > 0x635
ZEND_METHOD(Imagick, distortImage);
#endif
#if MagickLibVersion > 0x635
ZEND_METHOD(Imagick, writeImageFile);
#endif
#if MagickLibVersion > 0x635
ZEND_METHOD(Imagick, writeImagesFile);
#endif
#if MagickLibVersion > 0x635
ZEND_METHOD(Imagick, resetImagePage);
#endif
#if MagickLibVersion > 0x635 && MagickLibVersion < 0x700
ZEND_METHOD(Imagick, setImageClipMask);
#endif
#if MagickLibVersion > 0x635 && MagickLibVersion < 0x700
ZEND_METHOD(Imagick, getImageClipMask);
#endif
#if MagickLibVersion > 0x635
ZEND_METHOD(Imagick, animateImages);
#endif
#if MagickLibVersion > 0x635 && !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700
ZEND_METHOD(Imagick, recolorImage);
#endif
#if MagickLibVersion > 0x636
ZEND_METHOD(Imagick, setFont);
#endif
#if MagickLibVersion > 0x636
ZEND_METHOD(Imagick, getFont);
#endif
#if MagickLibVersion > 0x636
ZEND_METHOD(Imagick, setPointSize);
#endif
#if MagickLibVersion > 0x636
ZEND_METHOD(Imagick, getPointSize);
#endif
#if MagickLibVersion > 0x636
ZEND_METHOD(Imagick, mergeImageLayers);
#endif
#if MagickLibVersion > 0x637
ZEND_METHOD(Imagick, setImageAlphaChannel);
#endif
#if MagickLibVersion > 0x637
ZEND_METHOD(Imagick, floodfillPaintImage);
#endif
#if MagickLibVersion > 0x637
ZEND_METHOD(Imagick, opaquePaintImage);
#endif
#if MagickLibVersion > 0x637
ZEND_METHOD(Imagick, transparentPaintImage);
#endif
#if MagickLibVersion > 0x638
ZEND_METHOD(Imagick, liquidRescaleImage);
#endif
#if MagickLibVersion > 0x638
ZEND_METHOD(Imagick, encipherImage);
#endif
#if MagickLibVersion > 0x638
ZEND_METHOD(Imagick, decipherImage);
#endif
#if MagickLibVersion > 0x639
ZEND_METHOD(Imagick, setGravity);
#endif
#if MagickLibVersion > 0x639
ZEND_METHOD(Imagick, getGravity);
#endif
#if MagickLibVersion > 0x639
ZEND_METHOD(Imagick, getImageChannelRange);
#endif
#if MagickLibVersion > 0x639
ZEND_METHOD(Imagick, getImageAlphaChannel);
#endif
#if MagickLibVersion > 0x642
ZEND_METHOD(Imagick, getImageChannelDistortions);
#endif
#if MagickLibVersion > 0x643
ZEND_METHOD(Imagick, setImageGravity);
#endif
#if MagickLibVersion > 0x643
ZEND_METHOD(Imagick, getImageGravity);
#endif
#if MagickLibVersion > 0x645
ZEND_METHOD(Imagick, importImagePixels);
#endif
#if MagickLibVersion > 0x645
ZEND_METHOD(Imagick, deskewImage);
#endif
#if MagickLibVersion > 0x645
ZEND_METHOD(Imagick, segmentImage);
#endif
#if MagickLibVersion > 0x645
ZEND_METHOD(Imagick, sparseColorImage);
#endif
#if MagickLibVersion > 0x645
ZEND_METHOD(Imagick, remapImage);
#endif
#if PHP_IMAGICK_HAVE_HOUGHLINE
ZEND_METHOD(Imagick, houghLineImage);
#endif
#if MagickLibVersion > 0x646
ZEND_METHOD(Imagick, exportImagePixels);
#endif
#if MagickLibVersion > 0x648
ZEND_METHOD(Imagick, getImageChannelKurtosis);
#endif
#if MagickLibVersion > 0x648
ZEND_METHOD(Imagick, functionImage);
#endif
#if MagickLibVersion > 0x651
ZEND_METHOD(Imagick, transformImageColorspace);
#endif
#if MagickLibVersion > 0x652
ZEND_METHOD(Imagick, haldClutImage);
#endif
#if MagickLibVersion > 0x655
ZEND_METHOD(Imagick, autoLevelImage);
#endif
#if MagickLibVersion > 0x655
ZEND_METHOD(Imagick, blueShiftImage);
#endif
#if MagickLibVersion > 0x656
ZEND_METHOD(Imagick, getImageArtifact);
#endif
#if MagickLibVersion > 0x656
ZEND_METHOD(Imagick, setImageArtifact);
#endif
#if MagickLibVersion > 0x656
ZEND_METHOD(Imagick, deleteImageArtifact);
#endif
#if MagickLibVersion > 0x656
ZEND_METHOD(Imagick, getColorspace);
#endif
#if MagickLibVersion > 0x656
ZEND_METHOD(Imagick, setColorspace);
#endif
#if MagickLibVersion > 0x656
ZEND_METHOD(Imagick, clampImage);
#endif
#if MagickLibVersion > 0x667
ZEND_METHOD(Imagick, smushImages);
#endif
ZEND_METHOD(Imagick, __construct);
ZEND_METHOD(Imagick, __toString);
#if PHP_VERSION_ID >= 50600
ZEND_METHOD(Imagick, count);
#endif
#if !(PHP_VERSION_ID >= 50600)
ZEND_METHOD(Imagick, count);
#endif
ZEND_METHOD(Imagick, getPixelIterator);
ZEND_METHOD(Imagick, getPixelRegionIterator);
ZEND_METHOD(Imagick, readImage);
ZEND_METHOD(Imagick, readImages);
ZEND_METHOD(Imagick, readImageBlob);
ZEND_METHOD(Imagick, setImageFormat);
ZEND_METHOD(Imagick, scaleImage);
ZEND_METHOD(Imagick, writeImage);
ZEND_METHOD(Imagick, writeImages);
ZEND_METHOD(Imagick, blurImage);
ZEND_METHOD(Imagick, thumbnailImage);
ZEND_METHOD(Imagick, cropThumbnailImage);
ZEND_METHOD(Imagick, getImageFilename);
ZEND_METHOD(Imagick, setImageFilename);
ZEND_METHOD(Imagick, getImageFormat);
ZEND_METHOD(Imagick, getImageMimeType);
ZEND_METHOD(Imagick, removeImage);
ZEND_METHOD(Imagick, clear);
ZEND_METHOD(Imagick, clone);
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700
ZEND_METHOD(Imagick, getImageSize);
#endif
ZEND_METHOD(Imagick, getImageBlob);
ZEND_METHOD(Imagick, getImagesBlob);
ZEND_METHOD(Imagick, setFirstIterator);
ZEND_METHOD(Imagick, setLastIterator);
ZEND_METHOD(Imagick, resetIterator);
ZEND_METHOD(Imagick, previousImage);
ZEND_METHOD(Imagick, nextImage);
ZEND_METHOD(Imagick, hasPreviousImage);
ZEND_METHOD(Imagick, hasNextImage);
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700
ZEND_METHOD(Imagick, setImageIndex);
#endif
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700
ZEND_METHOD(Imagick, getImageIndex);
#endif
ZEND_METHOD(Imagick, commentImage);
ZEND_METHOD(Imagick, cropImage);
ZEND_METHOD(Imagick, labelImage);
ZEND_METHOD(Imagick, getImageGeometry);
ZEND_METHOD(Imagick, drawImage);
ZEND_METHOD(Imagick, setImageCompressionQuality);
ZEND_METHOD(Imagick, getImageCompressionQuality);
ZEND_METHOD(Imagick, setImageCompression);
ZEND_METHOD(Imagick, getImageCompression);
ZEND_METHOD(Imagick, annotateImage);
ZEND_METHOD(Imagick, compositeImage);
ZEND_METHOD(Imagick, modulateImage);
ZEND_METHOD(Imagick, getImageColors);
ZEND_METHOD(Imagick, montageImage);
ZEND_METHOD(Imagick, identifyImage);
ZEND_METHOD(Imagick, thresholdImage);
ZEND_METHOD(Imagick, adaptiveThresholdImage);
ZEND_METHOD(Imagick, blackThresholdImage);
ZEND_METHOD(Imagick, whiteThresholdImage);
ZEND_METHOD(Imagick, appendImages);
ZEND_METHOD(Imagick, charcoalImage);
ZEND_METHOD(Imagick, normalizeImage);
ZEND_METHOD(Imagick, oilPaintImage);
ZEND_METHOD(Imagick, posterizeImage);
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700
ZEND_METHOD(Imagick, radialBlurImage);
#endif
ZEND_METHOD(Imagick, raiseImage);
ZEND_METHOD(Imagick, resampleImage);
ZEND_METHOD(Imagick, resizeImage);
ZEND_METHOD(Imagick, rollImage);
ZEND_METHOD(Imagick, rotateImage);
ZEND_METHOD(Imagick, sampleImage);
ZEND_METHOD(Imagick, solarizeImage);
ZEND_METHOD(Imagick, shadowImage);
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700
ZEND_METHOD(Imagick, setImageAttribute);
#endif
ZEND_METHOD(Imagick, setImageBackgroundColor);
#if MagickLibVersion >= 0x700
ZEND_METHOD(Imagick, setImageChannelMask);
#endif
ZEND_METHOD(Imagick, setImageCompose);
ZEND_METHOD(Imagick, setImageDelay);
ZEND_METHOD(Imagick, setImageDepth);
ZEND_METHOD(Imagick, setImageGamma);
ZEND_METHOD(Imagick, setImageIterations);
#if MagickLibVersion < 0x700
ZEND_METHOD(Imagick, setImageMatteColor);
#endif
ZEND_METHOD(Imagick, setImagePage);
ZEND_METHOD(Imagick, setImageProgressMonitor);
#if MagickLibVersion > 0x653
ZEND_METHOD(Imagick, setProgressMonitor);
#endif
ZEND_METHOD(Imagick, setImageResolution);
ZEND_METHOD(Imagick, setImageScene);
ZEND_METHOD(Imagick, setImageTicksPerSecond);
ZEND_METHOD(Imagick, setImageType);
ZEND_METHOD(Imagick, setImageUnits);
ZEND_METHOD(Imagick, sharpenImage);
ZEND_METHOD(Imagick, shaveImage);
ZEND_METHOD(Imagick, shearImage);
ZEND_METHOD(Imagick, spliceImage);
ZEND_METHOD(Imagick, pingImage);
ZEND_METHOD(Imagick, readImageFile);
ZEND_METHOD(Imagick, displayImage);
ZEND_METHOD(Imagick, displayImages);
ZEND_METHOD(Imagick, spreadImage);
ZEND_METHOD(Imagick, swirlImage);
ZEND_METHOD(Imagick, stripImage);
ZEND_METHOD(Imagick, queryFormats);
ZEND_METHOD(Imagick, queryFonts);
ZEND_METHOD(Imagick, queryFontMetrics);
ZEND_METHOD(Imagick, steganoImage);
ZEND_METHOD(Imagick, addNoiseImage);
ZEND_METHOD(Imagick, motionBlurImage);
#if MagickLibVersion < 0x700 && !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
ZEND_METHOD(Imagick, mosaicImages);
#endif
ZEND_METHOD(Imagick, morphImages);
ZEND_METHOD(Imagick, minifyImage);
ZEND_METHOD(Imagick, affineTransformImage);
#if MagickLibVersion < 0x700 && !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
ZEND_METHOD(Imagick, averageImages);
#endif
ZEND_METHOD(Imagick, borderImage);
ZEND_METHOD(Imagick, calculateCrop);
ZEND_METHOD(Imagick, chopImage);
ZEND_METHOD(Imagick, clipImage);
ZEND_METHOD(Imagick, clipPathImage);
ZEND_METHOD(Imagick, coalesceImages);
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700
ZEND_METHOD(Imagick, colorFloodfillImage);
#endif
ZEND_METHOD(Imagick, colorizeImage);
ZEND_METHOD(Imagick, compareImageChannels);
ZEND_METHOD(Imagick, compareImages);
ZEND_METHOD(Imagick, contrastImage);
ZEND_METHOD(Imagick, combineImages);
ZEND_METHOD(Imagick, convolveImage);
ZEND_METHOD(Imagick, cycleColormapImage);
ZEND_METHOD(Imagick, deconstructImages);
ZEND_METHOD(Imagick, despeckleImage);
ZEND_METHOD(Imagick, edgeImage);
ZEND_METHOD(Imagick, embossImage);
ZEND_METHOD(Imagick, enhanceImage);
ZEND_METHOD(Imagick, equalizeImage);
ZEND_METHOD(Imagick, evaluateImage);
#if MagickLibVersion >= 0x687
ZEND_METHOD(Imagick, evaluateImages);
#endif
#if MagickLibVersion < 0x700 && !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
ZEND_METHOD(Imagick, flattenImages);
#endif
ZEND_METHOD(Imagick, flipImage);
ZEND_METHOD(Imagick, flopImage);
#if MagickLibVersion >= 0x655
ZEND_METHOD(Imagick, forwardFourierTransformImage);
#endif
ZEND_METHOD(Imagick, frameImage);
ZEND_METHOD(Imagick, fxImage);
ZEND_METHOD(Imagick, gammaImage);
ZEND_METHOD(Imagick, gaussianBlurImage);
#if MagickLibVersion < 0x700 && !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
ZEND_METHOD(Imagick, getImageAttribute);
#endif
ZEND_METHOD(Imagick, getImageBackgroundColor);
ZEND_METHOD(Imagick, getImageBluePrimary);
ZEND_METHOD(Imagick, getImageBorderColor);
ZEND_METHOD(Imagick, getImageChannelDepth);
ZEND_METHOD(Imagick, getImageChannelDistortion);
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700
ZEND_METHOD(Imagick, getImageChannelExtrema);
#endif
ZEND_METHOD(Imagick, getImageChannelMean);
ZEND_METHOD(Imagick, getImageChannelStatistics);
ZEND_METHOD(Imagick, getImageColormapColor);
ZEND_METHOD(Imagick, getImageColorspace);
ZEND_METHOD(Imagick, getImageCompose);
ZEND_METHOD(Imagick, getImageDelay);
ZEND_METHOD(Imagick, getImageDepth);
ZEND_METHOD(Imagick, getImageDistortion);
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700
ZEND_METHOD(Imagick, getImageExtrema);
#endif
ZEND_METHOD(Imagick, getImageDispose);
ZEND_METHOD(Imagick, getImageGamma);
ZEND_METHOD(Imagick, getImageGreenPrimary);
ZEND_METHOD(Imagick, getImageHeight);
ZEND_METHOD(Imagick, getImageHistogram);
ZEND_METHOD(Imagick, getImageInterlaceScheme);
ZEND_METHOD(Imagick, getImageIterations);
#if MagickLibVersion < 0x700
ZEND_METHOD(Imagick, getImageMatteColor);
#endif
ZEND_METHOD(Imagick, getImagePage);
ZEND_METHOD(Imagick, getImagePixelColor);
ZEND_METHOD(Imagick, getImageProfile);
ZEND_METHOD(Imagick, getImageRedPrimary);
ZEND_METHOD(Imagick, getImageRenderingIntent);
ZEND_METHOD(Imagick, getImageResolution);
ZEND_METHOD(Imagick, getImageScene);
ZEND_METHOD(Imagick, getImageSignature);
ZEND_METHOD(Imagick, getImageTicksPerSecond);
ZEND_METHOD(Imagick, getImageType);
ZEND_METHOD(Imagick, getImageUnits);
ZEND_METHOD(Imagick, getImageVirtualPixelMethod);
ZEND_METHOD(Imagick, getImageWhitePoint);
ZEND_METHOD(Imagick, getImageWidth);
ZEND_METHOD(Imagick, getNumberImages);
ZEND_METHOD(Imagick, getImageTotalInkDensity);
ZEND_METHOD(Imagick, getImageRegion);
ZEND_METHOD(Imagick, implodeImage);
#if MagickLibVersion >= 0x658
ZEND_METHOD(Imagick, inverseFourierTransformImage);
#endif
ZEND_METHOD(Imagick, levelImage);
ZEND_METHOD(Imagick, magnifyImage);
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700
ZEND_METHOD(Imagick, mapImage);
#endif
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700
ZEND_METHOD(Imagick, matteFloodfillImage);
#endif
#if MagickLibVersion < 0x700 && !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
ZEND_METHOD(Imagick, medianFilterImage);
#endif
ZEND_METHOD(Imagick, negateImage);
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700
ZEND_METHOD(Imagick, paintOpaqueImage);
#endif
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700
ZEND_METHOD(Imagick, paintTransparentImage);
#endif
ZEND_METHOD(Imagick, previewImages);
ZEND_METHOD(Imagick, profileImage);
ZEND_METHOD(Imagick, quantizeImage);
ZEND_METHOD(Imagick, quantizeImages);
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700
ZEND_METHOD(Imagick, reduceNoiseImage);
#endif
ZEND_METHOD(Imagick, removeImageProfile);
ZEND_METHOD(Imagick, separateImageChannel);
ZEND_METHOD(Imagick, sepiaToneImage);
#if MagickLibVersion < 0x700
ZEND_METHOD(Imagick, setImageBias);
#endif
#if MagickLibVersion < 0x700
ZEND_METHOD(Imagick, setImageBiasQuantum);
#endif
ZEND_METHOD(Imagick, setImageBluePrimary);
ZEND_METHOD(Imagick, setImageBorderColor);
ZEND_METHOD(Imagick, setImageChannelDepth);
ZEND_METHOD(Imagick, setImageColormapColor);
ZEND_METHOD(Imagick, setImageColorspace);
ZEND_METHOD(Imagick, setImageDispose);
ZEND_METHOD(Imagick, setImageExtent);
ZEND_METHOD(Imagick, setImageGreenPrimary);
ZEND_METHOD(Imagick, setImageInterlaceScheme);
ZEND_METHOD(Imagick, setImageProfile);
ZEND_METHOD(Imagick, setImageRedPrimary);
ZEND_METHOD(Imagick, setImageRenderingIntent);
ZEND_METHOD(Imagick, setImageVirtualPixelMethod);
ZEND_METHOD(Imagick, setImageWhitePoint);
ZEND_METHOD(Imagick, sigmoidalContrastImage);
ZEND_METHOD(Imagick, stereoImage);
ZEND_METHOD(Imagick, textureImage);
ZEND_METHOD(Imagick, tintImage);
ZEND_METHOD(Imagick, unsharpMaskImage);
ZEND_METHOD(Imagick, getImage);
ZEND_METHOD(Imagick, addImage);
ZEND_METHOD(Imagick, setImage);
ZEND_METHOD(Imagick, newImage);
ZEND_METHOD(Imagick, newPseudoImage);
ZEND_METHOD(Imagick, getCompression);
ZEND_METHOD(Imagick, getCompressionQuality);
ZEND_METHOD(Imagick, getCopyright);
ZEND_METHOD(Imagick, getConfigureOptions);
#if MagickLibVersion > 0x660
ZEND_METHOD(Imagick, getFeatures);
#endif
ZEND_METHOD(Imagick, getFilename);
ZEND_METHOD(Imagick, getFormat);
ZEND_METHOD(Imagick, getHomeURL);
ZEND_METHOD(Imagick, getInterlaceScheme);
ZEND_METHOD(Imagick, getOption);
ZEND_METHOD(Imagick, getPackageName);
ZEND_METHOD(Imagick, getPage);
ZEND_METHOD(Imagick, getQuantum);
ZEND_METHOD(Imagick, getHdriEnabled);
ZEND_METHOD(Imagick, getQuantumDepth);
ZEND_METHOD(Imagick, getQuantumRange);
ZEND_METHOD(Imagick, getReleaseDate);
ZEND_METHOD(Imagick, getResource);
ZEND_METHOD(Imagick, getResourceLimit);
ZEND_METHOD(Imagick, getSamplingFactors);
ZEND_METHOD(Imagick, getSize);
ZEND_METHOD(Imagick, getVersion);
ZEND_METHOD(Imagick, setBackgroundColor);
ZEND_METHOD(Imagick, setCompression);
ZEND_METHOD(Imagick, setCompressionQuality);
ZEND_METHOD(Imagick, setFilename);
ZEND_METHOD(Imagick, setFormat);
ZEND_METHOD(Imagick, setInterlaceScheme);
ZEND_METHOD(Imagick, setOption);
ZEND_METHOD(Imagick, setPage);
ZEND_METHOD(Imagick, setResourceLimit);
ZEND_METHOD(Imagick, setResolution);
ZEND_METHOD(Imagick, setSamplingFactors);
ZEND_METHOD(Imagick, setSize);
ZEND_METHOD(Imagick, setType);
#if MagickLibVersion > 0x628
ZEND_METHOD(Imagick, nextImage);
#endif
#if MagickLibVersion > 0x628
ZEND_METHOD(Imagick, setFirstIterator);
#endif
#if MagickLibVersion > 0x628
ZEND_METHOD(Imagick, valid);
#endif
#if MagickLibVersion > 0x628
ZEND_METHOD(Imagick, current);
#endif
#if MagickLibVersion > 0x628 && MagickLibVersion >= 0x659
ZEND_METHOD(Imagick, brightnessContrastImage);
#endif
#if MagickLibVersion > 0x628 && MagickLibVersion > 0x661
ZEND_METHOD(Imagick, colorMatrixImage);
#endif
#if MagickLibVersion > 0x628
ZEND_METHOD(Imagick, selectiveBlurImage);
#endif
#if MagickLibVersion > 0x628 && MagickLibVersion >= 0x689
ZEND_METHOD(Imagick, rotationalBlurImage);
#endif
#if MagickLibVersion > 0x628 && MagickLibVersion >= 0x683
ZEND_METHOD(Imagick, statisticImage);
#endif
#if MagickLibVersion > 0x628 && MagickLibVersion >= 0x652
ZEND_METHOD(Imagick, subimageMatch);
#endif
#if MagickLibVersion > 0x628
ZEND_METHOD(Imagick, setRegistry);
#endif
#if MagickLibVersion > 0x628
ZEND_METHOD(Imagick, getRegistry);
#endif
#if MagickLibVersion > 0x628
ZEND_METHOD(Imagick, listRegistry);
#endif
#if MagickLibVersion > 0x628 && MagickLibVersion >= 0x680
ZEND_METHOD(Imagick, morphology);
#endif
#if MagickLibVersion > 0x628 && defined(IMAGICK_WITH_KERNEL) && MagickLibVersion < 0x700
ZEND_METHOD(Imagick, filter);
#endif
#if MagickLibVersion > 0x628
ZEND_METHOD(Imagick, setAntialias);
#endif
#if MagickLibVersion > 0x628
ZEND_METHOD(Imagick, getAntialias);
#endif
#if MagickLibVersion > 0x628 && MagickLibVersion > 0x676
ZEND_METHOD(Imagick, colorDecisionListImage);
#endif
#if MagickLibVersion > 0x628 && MagickLibVersion >= 0x687
ZEND_METHOD(Imagick, optimizeImageTransparency);
#endif
#if MagickLibVersion > 0x628 && MagickLibVersion >= 0x660
ZEND_METHOD(Imagick, autoGammaImage);
#endif
#if MagickLibVersion > 0x628 && MagickLibVersion >= 0x692
ZEND_METHOD(Imagick, autoOrient);
#endif
#if MagickLibVersion > 0x628 && MagickLibVersion >= 0x692
ZEND_METHOD(Imagick, compositeImageGravity);
#endif
#if MagickLibVersion > 0x628 && MagickLibVersion >= 0x693
ZEND_METHOD(Imagick, localContrastImage);
#endif
#if MagickLibVersion > 0x628 && MagickLibVersion >= 0x700
ZEND_METHOD(Imagick, identifyImageType);
#endif


static const zend_function_entry class_Imagick_methods[] = {
#if MagickLibVersion > 0x628
	ZEND_ME(Imagick, optimizeImageLayers, arginfo_class_Imagick_optimizeImageLayers, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628
	ZEND_ME(Imagick, compareImageLayers, arginfo_class_Imagick_compareImageLayers, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628
	ZEND_ME(Imagick, pingImageBlob, arginfo_class_Imagick_pingImageBlob, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628
	ZEND_ME(Imagick, pingImageFile, arginfo_class_Imagick_pingImageFile, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628
	ZEND_ME(Imagick, transposeImage, arginfo_class_Imagick_transposeImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628
	ZEND_ME(Imagick, transverseImage, arginfo_class_Imagick_transverseImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628
	ZEND_ME(Imagick, trimImage, arginfo_class_Imagick_trimImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628
	ZEND_ME(Imagick, waveImage, arginfo_class_Imagick_waveImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628
	ZEND_ME(Imagick, vignetteImage, arginfo_class_Imagick_vignetteImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628
	ZEND_ME(Imagick, uniqueImageColors, arginfo_class_Imagick_uniqueImageColors, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628 && !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700
	ZEND_ME(Imagick, getImageMatte, arginfo_class_Imagick_getImageMatte, ZEND_ACC_PUBLIC|ZEND_ACC_DEPRECATED)
#endif
#if MagickLibVersion > 0x628
	ZEND_ME(Imagick, setImageMatte, arginfo_class_Imagick_setImageMatte, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628
	ZEND_ME(Imagick, adaptiveResizeImage, arginfo_class_Imagick_adaptiveResizeImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628
	ZEND_ME(Imagick, sketchImage, arginfo_class_Imagick_sketchImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628
	ZEND_ME(Imagick, shadeImage, arginfo_class_Imagick_shadeImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628
	ZEND_ME(Imagick, getSizeOffset, arginfo_class_Imagick_getSizeOffset, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628
	ZEND_ME(Imagick, setSizeOffset, arginfo_class_Imagick_setSizeOffset, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628
	ZEND_ME(Imagick, adaptiveBlurImage, arginfo_class_Imagick_adaptiveBlurImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628
	ZEND_ME(Imagick, contrastStretchImage, arginfo_class_Imagick_contrastStretchImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628
	ZEND_ME(Imagick, adaptiveSharpenImage, arginfo_class_Imagick_adaptiveSharpenImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628
	ZEND_ME(Imagick, randomThresholdImage, arginfo_class_Imagick_randomThresholdImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628 && MagickLibVersion < 0x700
	ZEND_ME(Imagick, roundCornersImage, arginfo_class_Imagick_roundCornersImage, ZEND_ACC_PUBLIC|ZEND_ACC_DEPRECATED)
#endif
#if MagickLibVersion > 0x628 && MagickLibVersion < 0x700
	ZEND_MALIAS(Imagick, roundCorners, roundCornersImage, arginfo_class_Imagick_roundCorners, ZEND_ACC_PUBLIC|ZEND_ACC_DEPRECATED)
#endif
#if MagickLibVersion > 0x628
	ZEND_ME(Imagick, setIteratorIndex, arginfo_class_Imagick_setIteratorIndex, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628
	ZEND_ME(Imagick, getIteratorIndex, arginfo_class_Imagick_getIteratorIndex, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628 && MagickLibVersion < 0x700
	ZEND_ME(Imagick, transformImage, arginfo_class_Imagick_transformImage, ZEND_ACC_PUBLIC|ZEND_ACC_DEPRECATED)
#endif
#if MagickLibVersion > 0x630 && MagickLibVersion < 0x700
	ZEND_ME(Imagick, setImageOpacity, arginfo_class_Imagick_setImageOpacity, ZEND_ACC_PUBLIC|ZEND_ACC_DEPRECATED)
#endif
#if MagickLibVersion > 0x630 && MagickLibVersion >= 0x700
	ZEND_ME(Imagick, setImageAlpha, arginfo_class_Imagick_setImageAlpha, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x630 && MagickLibVersion < 0x700
	ZEND_ME(Imagick, orderedPosterizeImage, arginfo_class_Imagick_orderedPosterizeImage, ZEND_ACC_PUBLIC|ZEND_ACC_DEPRECATED)
#endif
#if MagickLibVersion > 0x631
	ZEND_ME(Imagick, polaroidImage, arginfo_class_Imagick_polaroidImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x631
	ZEND_ME(Imagick, getImageProperty, arginfo_class_Imagick_getImageProperty, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x631
	ZEND_ME(Imagick, setImageProperty, arginfo_class_Imagick_setImageProperty, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x631
	ZEND_ME(Imagick, deleteImageProperty, arginfo_class_Imagick_deleteImageProperty, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x631
	ZEND_ME(Imagick, identifyFormat, arginfo_class_Imagick_identifyFormat, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x631
	ZEND_ME(Imagick, setImageInterpolateMethod, arginfo_class_Imagick_setImageInterpolateMethod, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x631
	ZEND_ME(Imagick, getImageInterpolateMethod, arginfo_class_Imagick_getImageInterpolateMethod, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x631
	ZEND_ME(Imagick, linearStretchImage, arginfo_class_Imagick_linearStretchImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x631
	ZEND_ME(Imagick, getImageLength, arginfo_class_Imagick_getImageLength, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x631
	ZEND_ME(Imagick, extentImage, arginfo_class_Imagick_extentImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x633
	ZEND_ME(Imagick, getImageOrientation, arginfo_class_Imagick_getImageOrientation, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x633
	ZEND_ME(Imagick, setImageOrientation, arginfo_class_Imagick_setImageOrientation, ZEND_ACC_PUBLIC)
#endif
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion > 0x634 && MagickLibVersion < 0x700
	ZEND_ME(Imagick, paintFloodfillImage, arginfo_class_Imagick_paintFloodfillImage, ZEND_ACC_PUBLIC|ZEND_ACC_DEPRECATED)
#endif
#if MagickLibVersion > 0x635
	ZEND_ME(Imagick, clutImage, arginfo_class_Imagick_clutImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x635
	ZEND_ME(Imagick, getImageProperties, arginfo_class_Imagick_getImageProperties, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x635
	ZEND_ME(Imagick, getImageProfiles, arginfo_class_Imagick_getImageProfiles, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x635
	ZEND_ME(Imagick, distortImage, arginfo_class_Imagick_distortImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x635
	ZEND_ME(Imagick, writeImageFile, arginfo_class_Imagick_writeImageFile, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x635
	ZEND_ME(Imagick, writeImagesFile, arginfo_class_Imagick_writeImagesFile, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x635
	ZEND_ME(Imagick, resetImagePage, arginfo_class_Imagick_resetImagePage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x635 && MagickLibVersion < 0x700
	ZEND_ME(Imagick, setImageClipMask, arginfo_class_Imagick_setImageClipMask, ZEND_ACC_PUBLIC|ZEND_ACC_DEPRECATED)
#endif
#if MagickLibVersion > 0x635 && MagickLibVersion < 0x700
	ZEND_ME(Imagick, getImageClipMask, arginfo_class_Imagick_getImageClipMask, ZEND_ACC_PUBLIC|ZEND_ACC_DEPRECATED)
#endif
#if MagickLibVersion > 0x635
	ZEND_ME(Imagick, animateImages, arginfo_class_Imagick_animateImages, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x635 && !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700
	ZEND_ME(Imagick, recolorImage, arginfo_class_Imagick_recolorImage, ZEND_ACC_PUBLIC|ZEND_ACC_DEPRECATED)
#endif
#if MagickLibVersion > 0x636
	ZEND_ME(Imagick, setFont, arginfo_class_Imagick_setFont, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x636
	ZEND_ME(Imagick, getFont, arginfo_class_Imagick_getFont, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x636
	ZEND_ME(Imagick, setPointSize, arginfo_class_Imagick_setPointSize, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x636
	ZEND_ME(Imagick, getPointSize, arginfo_class_Imagick_getPointSize, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x636
	ZEND_ME(Imagick, mergeImageLayers, arginfo_class_Imagick_mergeImageLayers, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x637
	ZEND_ME(Imagick, setImageAlphaChannel, arginfo_class_Imagick_setImageAlphaChannel, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x637
	ZEND_ME(Imagick, floodfillPaintImage, arginfo_class_Imagick_floodfillPaintImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x637
	ZEND_ME(Imagick, opaquePaintImage, arginfo_class_Imagick_opaquePaintImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x637
	ZEND_ME(Imagick, transparentPaintImage, arginfo_class_Imagick_transparentPaintImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x638
	ZEND_ME(Imagick, liquidRescaleImage, arginfo_class_Imagick_liquidRescaleImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x638
	ZEND_ME(Imagick, encipherImage, arginfo_class_Imagick_encipherImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x638
	ZEND_ME(Imagick, decipherImage, arginfo_class_Imagick_decipherImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x639
	ZEND_ME(Imagick, setGravity, arginfo_class_Imagick_setGravity, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x639
	ZEND_ME(Imagick, getGravity, arginfo_class_Imagick_getGravity, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x639
	ZEND_ME(Imagick, getImageChannelRange, arginfo_class_Imagick_getImageChannelRange, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x639
	ZEND_ME(Imagick, getImageAlphaChannel, arginfo_class_Imagick_getImageAlphaChannel, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x642
	ZEND_ME(Imagick, getImageChannelDistortions, arginfo_class_Imagick_getImageChannelDistortions, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x643
	ZEND_ME(Imagick, setImageGravity, arginfo_class_Imagick_setImageGravity, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x643
	ZEND_ME(Imagick, getImageGravity, arginfo_class_Imagick_getImageGravity, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x645
	ZEND_ME(Imagick, importImagePixels, arginfo_class_Imagick_importImagePixels, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x645
	ZEND_ME(Imagick, deskewImage, arginfo_class_Imagick_deskewImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x645
	ZEND_ME(Imagick, segmentImage, arginfo_class_Imagick_segmentImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x645
	ZEND_ME(Imagick, sparseColorImage, arginfo_class_Imagick_sparseColorImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x645
	ZEND_ME(Imagick, remapImage, arginfo_class_Imagick_remapImage, ZEND_ACC_PUBLIC)
#endif
#if PHP_IMAGICK_HAVE_HOUGHLINE
	ZEND_ME(Imagick, houghLineImage, arginfo_class_Imagick_houghLineImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x646
	ZEND_ME(Imagick, exportImagePixels, arginfo_class_Imagick_exportImagePixels, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x648
	ZEND_ME(Imagick, getImageChannelKurtosis, arginfo_class_Imagick_getImageChannelKurtosis, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x648
	ZEND_ME(Imagick, functionImage, arginfo_class_Imagick_functionImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x651
	ZEND_ME(Imagick, transformImageColorspace, arginfo_class_Imagick_transformImageColorspace, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x652
	ZEND_ME(Imagick, haldClutImage, arginfo_class_Imagick_haldClutImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x655
	ZEND_ME(Imagick, autoLevelImage, arginfo_class_Imagick_autoLevelImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x655
	ZEND_ME(Imagick, blueShiftImage, arginfo_class_Imagick_blueShiftImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x656
	ZEND_ME(Imagick, getImageArtifact, arginfo_class_Imagick_getImageArtifact, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x656
	ZEND_ME(Imagick, setImageArtifact, arginfo_class_Imagick_setImageArtifact, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x656
	ZEND_ME(Imagick, deleteImageArtifact, arginfo_class_Imagick_deleteImageArtifact, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x656
	ZEND_ME(Imagick, getColorspace, arginfo_class_Imagick_getColorspace, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x656
	ZEND_ME(Imagick, setColorspace, arginfo_class_Imagick_setColorspace, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x656
	ZEND_ME(Imagick, clampImage, arginfo_class_Imagick_clampImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x667
	ZEND_ME(Imagick, smushImages, arginfo_class_Imagick_smushImages, ZEND_ACC_PUBLIC)
#endif
	ZEND_ME(Imagick, __construct, arginfo_class_Imagick___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, __toString, arginfo_class_Imagick___toString, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 50600
	ZEND_ME(Imagick, count, arginfo_class_Imagick_count, ZEND_ACC_PUBLIC)
#endif
#if !(PHP_VERSION_ID >= 50600)
	ZEND_ME(Imagick, count, arginfo_class_Imagick_count, ZEND_ACC_PUBLIC)
#endif
	ZEND_ME(Imagick, getPixelIterator, arginfo_class_Imagick_getPixelIterator, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getPixelRegionIterator, arginfo_class_Imagick_getPixelRegionIterator, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, readImage, arginfo_class_Imagick_readImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, readImages, arginfo_class_Imagick_readImages, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, readImageBlob, arginfo_class_Imagick_readImageBlob, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setImageFormat, arginfo_class_Imagick_setImageFormat, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, scaleImage, arginfo_class_Imagick_scaleImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, writeImage, arginfo_class_Imagick_writeImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, writeImages, arginfo_class_Imagick_writeImages, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, blurImage, arginfo_class_Imagick_blurImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, thumbnailImage, arginfo_class_Imagick_thumbnailImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, cropThumbnailImage, arginfo_class_Imagick_cropThumbnailImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImageFilename, arginfo_class_Imagick_getImageFilename, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setImageFilename, arginfo_class_Imagick_setImageFilename, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImageFormat, arginfo_class_Imagick_getImageFormat, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImageMimeType, arginfo_class_Imagick_getImageMimeType, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, removeImage, arginfo_class_Imagick_removeImage, ZEND_ACC_PUBLIC)
	ZEND_MALIAS(Imagick, destroy, clear, arginfo_class_Imagick_destroy, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, clear, arginfo_class_Imagick_clear, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, clone, arginfo_class_Imagick_clone, ZEND_ACC_PUBLIC)
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700
	ZEND_ME(Imagick, getImageSize, arginfo_class_Imagick_getImageSize, ZEND_ACC_PUBLIC|ZEND_ACC_DEPRECATED)
#endif
	ZEND_ME(Imagick, getImageBlob, arginfo_class_Imagick_getImageBlob, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImagesBlob, arginfo_class_Imagick_getImagesBlob, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setFirstIterator, arginfo_class_Imagick_setFirstIterator, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setLastIterator, arginfo_class_Imagick_setLastIterator, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, resetIterator, arginfo_class_Imagick_resetIterator, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, previousImage, arginfo_class_Imagick_previousImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, nextImage, arginfo_class_Imagick_nextImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, hasPreviousImage, arginfo_class_Imagick_hasPreviousImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, hasNextImage, arginfo_class_Imagick_hasNextImage, ZEND_ACC_PUBLIC)
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700
	ZEND_ME(Imagick, setImageIndex, arginfo_class_Imagick_setImageIndex, ZEND_ACC_PUBLIC|ZEND_ACC_DEPRECATED)
#endif
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700
	ZEND_ME(Imagick, getImageIndex, arginfo_class_Imagick_getImageIndex, ZEND_ACC_PUBLIC|ZEND_ACC_DEPRECATED)
#endif
	ZEND_ME(Imagick, commentImage, arginfo_class_Imagick_commentImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, cropImage, arginfo_class_Imagick_cropImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, labelImage, arginfo_class_Imagick_labelImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImageGeometry, arginfo_class_Imagick_getImageGeometry, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, drawImage, arginfo_class_Imagick_drawImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setImageCompressionQuality, arginfo_class_Imagick_setImageCompressionQuality, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImageCompressionQuality, arginfo_class_Imagick_getImageCompressionQuality, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setImageCompression, arginfo_class_Imagick_setImageCompression, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImageCompression, arginfo_class_Imagick_getImageCompression, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, annotateImage, arginfo_class_Imagick_annotateImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, compositeImage, arginfo_class_Imagick_compositeImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, modulateImage, arginfo_class_Imagick_modulateImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImageColors, arginfo_class_Imagick_getImageColors, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, montageImage, arginfo_class_Imagick_montageImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, identifyImage, arginfo_class_Imagick_identifyImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, thresholdImage, arginfo_class_Imagick_thresholdImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, adaptiveThresholdImage, arginfo_class_Imagick_adaptiveThresholdImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, blackThresholdImage, arginfo_class_Imagick_blackThresholdImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, whiteThresholdImage, arginfo_class_Imagick_whiteThresholdImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, appendImages, arginfo_class_Imagick_appendImages, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, charcoalImage, arginfo_class_Imagick_charcoalImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, normalizeImage, arginfo_class_Imagick_normalizeImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, oilPaintImage, arginfo_class_Imagick_oilPaintImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, posterizeImage, arginfo_class_Imagick_posterizeImage, ZEND_ACC_PUBLIC)
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700
	ZEND_ME(Imagick, radialBlurImage, arginfo_class_Imagick_radialBlurImage, ZEND_ACC_PUBLIC|ZEND_ACC_DEPRECATED)
#endif
	ZEND_ME(Imagick, raiseImage, arginfo_class_Imagick_raiseImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, resampleImage, arginfo_class_Imagick_resampleImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, resizeImage, arginfo_class_Imagick_resizeImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, rollImage, arginfo_class_Imagick_rollImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, rotateImage, arginfo_class_Imagick_rotateImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, sampleImage, arginfo_class_Imagick_sampleImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, solarizeImage, arginfo_class_Imagick_solarizeImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, shadowImage, arginfo_class_Imagick_shadowImage, ZEND_ACC_PUBLIC)
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700
	ZEND_ME(Imagick, setImageAttribute, arginfo_class_Imagick_setImageAttribute, ZEND_ACC_PUBLIC|ZEND_ACC_DEPRECATED)
#endif
	ZEND_ME(Imagick, setImageBackgroundColor, arginfo_class_Imagick_setImageBackgroundColor, ZEND_ACC_PUBLIC)
#if MagickLibVersion >= 0x700
	ZEND_ME(Imagick, setImageChannelMask, arginfo_class_Imagick_setImageChannelMask, ZEND_ACC_PUBLIC)
#endif
	ZEND_ME(Imagick, setImageCompose, arginfo_class_Imagick_setImageCompose, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setImageDelay, arginfo_class_Imagick_setImageDelay, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setImageDepth, arginfo_class_Imagick_setImageDepth, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setImageGamma, arginfo_class_Imagick_setImageGamma, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setImageIterations, arginfo_class_Imagick_setImageIterations, ZEND_ACC_PUBLIC)
#if MagickLibVersion < 0x700
	ZEND_ME(Imagick, setImageMatteColor, arginfo_class_Imagick_setImageMatteColor, ZEND_ACC_PUBLIC|ZEND_ACC_DEPRECATED)
#endif
	ZEND_ME(Imagick, setImagePage, arginfo_class_Imagick_setImagePage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setImageProgressMonitor, arginfo_class_Imagick_setImageProgressMonitor, ZEND_ACC_PUBLIC)
#if MagickLibVersion > 0x653
	ZEND_ME(Imagick, setProgressMonitor, arginfo_class_Imagick_setProgressMonitor, ZEND_ACC_PUBLIC)
#endif
	ZEND_ME(Imagick, setImageResolution, arginfo_class_Imagick_setImageResolution, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setImageScene, arginfo_class_Imagick_setImageScene, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setImageTicksPerSecond, arginfo_class_Imagick_setImageTicksPerSecond, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setImageType, arginfo_class_Imagick_setImageType, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setImageUnits, arginfo_class_Imagick_setImageUnits, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, sharpenImage, arginfo_class_Imagick_sharpenImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, shaveImage, arginfo_class_Imagick_shaveImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, shearImage, arginfo_class_Imagick_shearImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, spliceImage, arginfo_class_Imagick_spliceImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, pingImage, arginfo_class_Imagick_pingImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, readImageFile, arginfo_class_Imagick_readImageFile, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, displayImage, arginfo_class_Imagick_displayImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, displayImages, arginfo_class_Imagick_displayImages, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, spreadImage, arginfo_class_Imagick_spreadImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, swirlImage, arginfo_class_Imagick_swirlImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, stripImage, arginfo_class_Imagick_stripImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, queryFormats, arginfo_class_Imagick_queryFormats, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Imagick, queryFonts, arginfo_class_Imagick_queryFonts, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Imagick, queryFontMetrics, arginfo_class_Imagick_queryFontMetrics, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, steganoImage, arginfo_class_Imagick_steganoImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, addNoiseImage, arginfo_class_Imagick_addNoiseImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, motionBlurImage, arginfo_class_Imagick_motionBlurImage, ZEND_ACC_PUBLIC)
#if MagickLibVersion < 0x700 && !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
	ZEND_ME(Imagick, mosaicImages, arginfo_class_Imagick_mosaicImages, ZEND_ACC_PUBLIC|ZEND_ACC_DEPRECATED)
#endif
	ZEND_ME(Imagick, morphImages, arginfo_class_Imagick_morphImages, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, minifyImage, arginfo_class_Imagick_minifyImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, affineTransformImage, arginfo_class_Imagick_affineTransformImage, ZEND_ACC_PUBLIC)
#if MagickLibVersion < 0x700 && !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
	ZEND_ME(Imagick, averageImages, arginfo_class_Imagick_averageImages, ZEND_ACC_PUBLIC|ZEND_ACC_DEPRECATED)
#endif
	ZEND_ME(Imagick, borderImage, arginfo_class_Imagick_borderImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, calculateCrop, arginfo_class_Imagick_calculateCrop, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Imagick, chopImage, arginfo_class_Imagick_chopImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, clipImage, arginfo_class_Imagick_clipImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, clipPathImage, arginfo_class_Imagick_clipPathImage, ZEND_ACC_PUBLIC)
	ZEND_MALIAS(Imagick, clipImagePath, clipPathImage, arginfo_class_Imagick_clipImagePath, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, coalesceImages, arginfo_class_Imagick_coalesceImages, ZEND_ACC_PUBLIC)
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700
	ZEND_ME(Imagick, colorFloodfillImage, arginfo_class_Imagick_colorFloodfillImage, ZEND_ACC_PUBLIC|ZEND_ACC_DEPRECATED)
#endif
	ZEND_ME(Imagick, colorizeImage, arginfo_class_Imagick_colorizeImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, compareImageChannels, arginfo_class_Imagick_compareImageChannels, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, compareImages, arginfo_class_Imagick_compareImages, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, contrastImage, arginfo_class_Imagick_contrastImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, combineImages, arginfo_class_Imagick_combineImages, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, convolveImage, arginfo_class_Imagick_convolveImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, cycleColormapImage, arginfo_class_Imagick_cycleColormapImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, deconstructImages, arginfo_class_Imagick_deconstructImages, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, despeckleImage, arginfo_class_Imagick_despeckleImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, edgeImage, arginfo_class_Imagick_edgeImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, embossImage, arginfo_class_Imagick_embossImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, enhanceImage, arginfo_class_Imagick_enhanceImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, equalizeImage, arginfo_class_Imagick_equalizeImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, evaluateImage, arginfo_class_Imagick_evaluateImage, ZEND_ACC_PUBLIC)
#if MagickLibVersion >= 0x687
	ZEND_ME(Imagick, evaluateImages, arginfo_class_Imagick_evaluateImages, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion < 0x700 && !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
	ZEND_ME(Imagick, flattenImages, arginfo_class_Imagick_flattenImages, ZEND_ACC_PUBLIC|ZEND_ACC_DEPRECATED)
#endif
	ZEND_ME(Imagick, flipImage, arginfo_class_Imagick_flipImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, flopImage, arginfo_class_Imagick_flopImage, ZEND_ACC_PUBLIC)
#if MagickLibVersion >= 0x655
	ZEND_ME(Imagick, forwardFourierTransformImage, arginfo_class_Imagick_forwardFourierTransformImage, ZEND_ACC_PUBLIC)
#endif
	ZEND_ME(Imagick, frameImage, arginfo_class_Imagick_frameImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, fxImage, arginfo_class_Imagick_fxImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, gammaImage, arginfo_class_Imagick_gammaImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, gaussianBlurImage, arginfo_class_Imagick_gaussianBlurImage, ZEND_ACC_PUBLIC)
#if MagickLibVersion < 0x700 && !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
	ZEND_ME(Imagick, getImageAttribute, arginfo_class_Imagick_getImageAttribute, ZEND_ACC_PUBLIC|ZEND_ACC_DEPRECATED)
#endif
	ZEND_ME(Imagick, getImageBackgroundColor, arginfo_class_Imagick_getImageBackgroundColor, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImageBluePrimary, arginfo_class_Imagick_getImageBluePrimary, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImageBorderColor, arginfo_class_Imagick_getImageBorderColor, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImageChannelDepth, arginfo_class_Imagick_getImageChannelDepth, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImageChannelDistortion, arginfo_class_Imagick_getImageChannelDistortion, ZEND_ACC_PUBLIC)
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700
	ZEND_ME(Imagick, getImageChannelExtrema, arginfo_class_Imagick_getImageChannelExtrema, ZEND_ACC_PUBLIC|ZEND_ACC_DEPRECATED)
#endif
	ZEND_ME(Imagick, getImageChannelMean, arginfo_class_Imagick_getImageChannelMean, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImageChannelStatistics, arginfo_class_Imagick_getImageChannelStatistics, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImageColormapColor, arginfo_class_Imagick_getImageColormapColor, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImageColorspace, arginfo_class_Imagick_getImageColorspace, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImageCompose, arginfo_class_Imagick_getImageCompose, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImageDelay, arginfo_class_Imagick_getImageDelay, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImageDepth, arginfo_class_Imagick_getImageDepth, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImageDistortion, arginfo_class_Imagick_getImageDistortion, ZEND_ACC_PUBLIC)
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700
	ZEND_ME(Imagick, getImageExtrema, arginfo_class_Imagick_getImageExtrema, ZEND_ACC_PUBLIC|ZEND_ACC_DEPRECATED)
#endif
	ZEND_ME(Imagick, getImageDispose, arginfo_class_Imagick_getImageDispose, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImageGamma, arginfo_class_Imagick_getImageGamma, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImageGreenPrimary, arginfo_class_Imagick_getImageGreenPrimary, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImageHeight, arginfo_class_Imagick_getImageHeight, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImageHistogram, arginfo_class_Imagick_getImageHistogram, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImageInterlaceScheme, arginfo_class_Imagick_getImageInterlaceScheme, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImageIterations, arginfo_class_Imagick_getImageIterations, ZEND_ACC_PUBLIC)
#if MagickLibVersion < 0x700
	ZEND_ME(Imagick, getImageMatteColor, arginfo_class_Imagick_getImageMatteColor, ZEND_ACC_PUBLIC|ZEND_ACC_DEPRECATED)
#endif
	ZEND_ME(Imagick, getImagePage, arginfo_class_Imagick_getImagePage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImagePixelColor, arginfo_class_Imagick_getImagePixelColor, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImageProfile, arginfo_class_Imagick_getImageProfile, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImageRedPrimary, arginfo_class_Imagick_getImageRedPrimary, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImageRenderingIntent, arginfo_class_Imagick_getImageRenderingIntent, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImageResolution, arginfo_class_Imagick_getImageResolution, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImageScene, arginfo_class_Imagick_getImageScene, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImageSignature, arginfo_class_Imagick_getImageSignature, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImageTicksPerSecond, arginfo_class_Imagick_getImageTicksPerSecond, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImageType, arginfo_class_Imagick_getImageType, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImageUnits, arginfo_class_Imagick_getImageUnits, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImageVirtualPixelMethod, arginfo_class_Imagick_getImageVirtualPixelMethod, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImageWhitePoint, arginfo_class_Imagick_getImageWhitePoint, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImageWidth, arginfo_class_Imagick_getImageWidth, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getNumberImages, arginfo_class_Imagick_getNumberImages, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImageTotalInkDensity, arginfo_class_Imagick_getImageTotalInkDensity, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImageRegion, arginfo_class_Imagick_getImageRegion, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, implodeImage, arginfo_class_Imagick_implodeImage, ZEND_ACC_PUBLIC)
#if MagickLibVersion >= 0x658
	ZEND_ME(Imagick, inverseFourierTransformImage, arginfo_class_Imagick_inverseFourierTransformImage, ZEND_ACC_PUBLIC)
#endif
	ZEND_ME(Imagick, levelImage, arginfo_class_Imagick_levelImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, magnifyImage, arginfo_class_Imagick_magnifyImage, ZEND_ACC_PUBLIC)
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700
	ZEND_ME(Imagick, mapImage, arginfo_class_Imagick_mapImage, ZEND_ACC_PUBLIC|ZEND_ACC_DEPRECATED)
#endif
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700
	ZEND_ME(Imagick, matteFloodfillImage, arginfo_class_Imagick_matteFloodfillImage, ZEND_ACC_PUBLIC|ZEND_ACC_DEPRECATED)
#endif
#if MagickLibVersion < 0x700 && !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
	ZEND_ME(Imagick, medianFilterImage, arginfo_class_Imagick_medianFilterImage, ZEND_ACC_PUBLIC|ZEND_ACC_DEPRECATED)
#endif
	ZEND_ME(Imagick, negateImage, arginfo_class_Imagick_negateImage, ZEND_ACC_PUBLIC)
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700
	ZEND_ME(Imagick, paintOpaqueImage, arginfo_class_Imagick_paintOpaqueImage, ZEND_ACC_PUBLIC|ZEND_ACC_DEPRECATED)
#endif
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700
	ZEND_ME(Imagick, paintTransparentImage, arginfo_class_Imagick_paintTransparentImage, ZEND_ACC_PUBLIC|ZEND_ACC_DEPRECATED)
#endif
	ZEND_ME(Imagick, previewImages, arginfo_class_Imagick_previewImages, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, profileImage, arginfo_class_Imagick_profileImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, quantizeImage, arginfo_class_Imagick_quantizeImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, quantizeImages, arginfo_class_Imagick_quantizeImages, ZEND_ACC_PUBLIC)
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED) && MagickLibVersion < 0x700
	ZEND_ME(Imagick, reduceNoiseImage, arginfo_class_Imagick_reduceNoiseImage, ZEND_ACC_PUBLIC|ZEND_ACC_DEPRECATED)
#endif
	ZEND_ME(Imagick, removeImageProfile, arginfo_class_Imagick_removeImageProfile, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, separateImageChannel, arginfo_class_Imagick_separateImageChannel, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, sepiaToneImage, arginfo_class_Imagick_sepiaToneImage, ZEND_ACC_PUBLIC)
#if MagickLibVersion < 0x700
	ZEND_ME(Imagick, setImageBias, arginfo_class_Imagick_setImageBias, ZEND_ACC_PUBLIC|ZEND_ACC_DEPRECATED)
#endif
#if MagickLibVersion < 0x700
	ZEND_ME(Imagick, setImageBiasQuantum, arginfo_class_Imagick_setImageBiasQuantum, ZEND_ACC_PUBLIC|ZEND_ACC_DEPRECATED)
#endif
	ZEND_ME(Imagick, setImageBluePrimary, arginfo_class_Imagick_setImageBluePrimary, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setImageBorderColor, arginfo_class_Imagick_setImageBorderColor, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setImageChannelDepth, arginfo_class_Imagick_setImageChannelDepth, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setImageColormapColor, arginfo_class_Imagick_setImageColormapColor, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setImageColorspace, arginfo_class_Imagick_setImageColorspace, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setImageDispose, arginfo_class_Imagick_setImageDispose, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setImageExtent, arginfo_class_Imagick_setImageExtent, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setImageGreenPrimary, arginfo_class_Imagick_setImageGreenPrimary, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setImageInterlaceScheme, arginfo_class_Imagick_setImageInterlaceScheme, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setImageProfile, arginfo_class_Imagick_setImageProfile, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setImageRedPrimary, arginfo_class_Imagick_setImageRedPrimary, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setImageRenderingIntent, arginfo_class_Imagick_setImageRenderingIntent, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setImageVirtualPixelMethod, arginfo_class_Imagick_setImageVirtualPixelMethod, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setImageWhitePoint, arginfo_class_Imagick_setImageWhitePoint, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, sigmoidalContrastImage, arginfo_class_Imagick_sigmoidalContrastImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, stereoImage, arginfo_class_Imagick_stereoImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, textureImage, arginfo_class_Imagick_textureImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, tintImage, arginfo_class_Imagick_tintImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, unsharpMaskImage, arginfo_class_Imagick_unsharpMaskImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getImage, arginfo_class_Imagick_getImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, addImage, arginfo_class_Imagick_addImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setImage, arginfo_class_Imagick_setImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, newImage, arginfo_class_Imagick_newImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, newPseudoImage, arginfo_class_Imagick_newPseudoImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getCompression, arginfo_class_Imagick_getCompression, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getCompressionQuality, arginfo_class_Imagick_getCompressionQuality, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getCopyright, arginfo_class_Imagick_getCopyright, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Imagick, getConfigureOptions, arginfo_class_Imagick_getConfigureOptions, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#if MagickLibVersion > 0x660
	ZEND_ME(Imagick, getFeatures, arginfo_class_Imagick_getFeatures, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#endif
	ZEND_ME(Imagick, getFilename, arginfo_class_Imagick_getFilename, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getFormat, arginfo_class_Imagick_getFormat, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getHomeURL, arginfo_class_Imagick_getHomeURL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Imagick, getInterlaceScheme, arginfo_class_Imagick_getInterlaceScheme, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getOption, arginfo_class_Imagick_getOption, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getPackageName, arginfo_class_Imagick_getPackageName, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Imagick, getPage, arginfo_class_Imagick_getPage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getQuantum, arginfo_class_Imagick_getQuantum, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Imagick, getHdriEnabled, arginfo_class_Imagick_getHdriEnabled, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Imagick, getQuantumDepth, arginfo_class_Imagick_getQuantumDepth, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Imagick, getQuantumRange, arginfo_class_Imagick_getQuantumRange, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Imagick, getReleaseDate, arginfo_class_Imagick_getReleaseDate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Imagick, getResource, arginfo_class_Imagick_getResource, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Imagick, getResourceLimit, arginfo_class_Imagick_getResourceLimit, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Imagick, getSamplingFactors, arginfo_class_Imagick_getSamplingFactors, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getSize, arginfo_class_Imagick_getSize, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, getVersion, arginfo_class_Imagick_getVersion, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Imagick, setBackgroundColor, arginfo_class_Imagick_setBackgroundColor, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setCompression, arginfo_class_Imagick_setCompression, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setCompressionQuality, arginfo_class_Imagick_setCompressionQuality, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setFilename, arginfo_class_Imagick_setFilename, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setFormat, arginfo_class_Imagick_setFormat, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setInterlaceScheme, arginfo_class_Imagick_setInterlaceScheme, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setOption, arginfo_class_Imagick_setOption, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setPage, arginfo_class_Imagick_setPage, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setResourceLimit, arginfo_class_Imagick_setResourceLimit, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Imagick, setResolution, arginfo_class_Imagick_setResolution, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setSamplingFactors, arginfo_class_Imagick_setSamplingFactors, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setSize, arginfo_class_Imagick_setSize, ZEND_ACC_PUBLIC)
	ZEND_ME(Imagick, setType, arginfo_class_Imagick_setType, ZEND_ACC_PUBLIC)
#if MagickLibVersion > 0x628
	ZEND_MALIAS(Imagick, key, getIteratorIndex, arginfo_class_Imagick_key, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628
	ZEND_MALIAS(Imagick, next, nextImage, arginfo_class_Imagick_next, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628
	ZEND_MALIAS(Imagick, rewind, setFirstIterator, arginfo_class_Imagick_rewind, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628
	ZEND_ME(Imagick, valid, arginfo_class_Imagick_valid, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628
	ZEND_ME(Imagick, current, arginfo_class_Imagick_current, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628 && MagickLibVersion >= 0x659
	ZEND_ME(Imagick, brightnessContrastImage, arginfo_class_Imagick_brightnessContrastImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628 && MagickLibVersion > 0x661
	ZEND_ME(Imagick, colorMatrixImage, arginfo_class_Imagick_colorMatrixImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628
	ZEND_ME(Imagick, selectiveBlurImage, arginfo_class_Imagick_selectiveBlurImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628 && MagickLibVersion >= 0x689
	ZEND_ME(Imagick, rotationalBlurImage, arginfo_class_Imagick_rotationalBlurImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628 && MagickLibVersion >= 0x683
	ZEND_ME(Imagick, statisticImage, arginfo_class_Imagick_statisticImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628 && MagickLibVersion >= 0x652
	ZEND_ME(Imagick, subimageMatch, arginfo_class_Imagick_subimageMatch, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628 && MagickLibVersion >= 0x652
	ZEND_MALIAS(Imagick, similarityimage, subimageMatch, arginfo_class_Imagick_similarityimage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628
	ZEND_ME(Imagick, setRegistry, arginfo_class_Imagick_setRegistry, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#endif
#if MagickLibVersion > 0x628
	ZEND_ME(Imagick, getRegistry, arginfo_class_Imagick_getRegistry, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#endif
#if MagickLibVersion > 0x628
	ZEND_ME(Imagick, listRegistry, arginfo_class_Imagick_listRegistry, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#endif
#if MagickLibVersion > 0x628 && MagickLibVersion >= 0x680
	ZEND_ME(Imagick, morphology, arginfo_class_Imagick_morphology, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628 && defined(IMAGICK_WITH_KERNEL) && MagickLibVersion < 0x700
	ZEND_ME(Imagick, filter, arginfo_class_Imagick_filter, ZEND_ACC_PUBLIC|ZEND_ACC_DEPRECATED)
#endif
#if MagickLibVersion > 0x628
	ZEND_ME(Imagick, setAntialias, arginfo_class_Imagick_setAntialias, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628
	ZEND_ME(Imagick, getAntialias, arginfo_class_Imagick_getAntialias, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628 && MagickLibVersion > 0x676
	ZEND_ME(Imagick, colorDecisionListImage, arginfo_class_Imagick_colorDecisionListImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628 && MagickLibVersion >= 0x687
	ZEND_ME(Imagick, optimizeImageTransparency, arginfo_class_Imagick_optimizeImageTransparency, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628 && MagickLibVersion >= 0x660
	ZEND_ME(Imagick, autoGammaImage, arginfo_class_Imagick_autoGammaImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628 && MagickLibVersion >= 0x692
	ZEND_ME(Imagick, autoOrient, arginfo_class_Imagick_autoOrient, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628 && MagickLibVersion >= 0x692
	ZEND_MALIAS(Imagick, autoOrientate, autoOrient, arginfo_class_Imagick_autoOrientate, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628 && MagickLibVersion >= 0x692
	ZEND_ME(Imagick, compositeImageGravity, arginfo_class_Imagick_compositeImageGravity, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628 && MagickLibVersion >= 0x693
	ZEND_ME(Imagick, localContrastImage, arginfo_class_Imagick_localContrastImage, ZEND_ACC_PUBLIC)
#endif
#if MagickLibVersion > 0x628 && MagickLibVersion >= 0x700
	ZEND_ME(Imagick, identifyImageType, arginfo_class_Imagick_identifyImageType, ZEND_ACC_PUBLIC)
#endif
	ZEND_FE_END
};