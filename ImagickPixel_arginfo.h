/* This is a generated file, edit the .stub.php file instead.
* Stub hash: always needs regen */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickPixel___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, color, IS_STRING, 1)
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX\(arginfo_class_ImagickPixel_clear, 0, 0, _IS_BOOL, 0\)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickPixel_clear, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()

#define arginfo_class_ImagickPixel_destroy arginfo_class_ImagickPixel_clear


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX\(arginfo_class_ImagickPixel_getColor, 0, 0, IS_ARRAY, 0\)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickPixel_getColor, 0, 0, 0)
#endif

	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, normalized, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX\(arginfo_class_ImagickPixel_getColorAsString, 0, 0, IS_STRING, 0\)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickPixel_getColorAsString, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX\(arginfo_class_ImagickPixel_getColorCount, 0, 0, IS_LONG, 0\)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickPixel_getColorCount, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX\(arginfo_class_ImagickPixel_getColorQuantum, 0, 0, IS_ARRAY, 0\)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickPixel_getColorQuantum, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()


#if MAGICKCORE_HDRI_ENABLE 

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX\(arginfo_class_ImagickPixel_getColorValue, 0, 0, IS_DOUBLE, 0\)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickPixel_getColorValue, 0, 0, 0)
#endif

#else

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX\(arginfo_class_ImagickPixel_getColorValue, 0, 0, IS_LONG, 0\)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickPixel_getColorValue, 0, 0, 0)
#endif

#endif

	ZEND_ARG_TYPE_INFO(0, color, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_ImagickPixel_getColorValueQuantum arginfo_class_ImagickPixel_getColorValue

#define arginfo_class_ImagickPixel_getHSL arginfo_class_ImagickPixel_getColorQuantum

#define arginfo_class_ImagickPixel_getIndex arginfo_class_ImagickPixel_getColorCount


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX\(arginfo_class_ImagickPixel_isPixelSimilar, 0, 2, _IS_BOOL, 0\)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickPixel_isPixelSimilar, 0, 0, 2)
#endif

	ZEND_ARG_OBJ_TYPE_MASK(0, color, ImagickPixel, MAY_BE_STRING, NULL)
	ZEND_ARG_TYPE_INFO(0, fuzz, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_ImagickPixel_isPixelSimilarQuantum arginfo_class_ImagickPixel_isPixelSimilar

#define arginfo_class_ImagickPixel_isSimilar arginfo_class_ImagickPixel_isPixelSimilar


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX\(arginfo_class_ImagickPixel_setColor, 0, 1, _IS_BOOL, 0\)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickPixel_setColor, 0, 0, 1)
#endif

	ZEND_ARG_TYPE_INFO(0, color, IS_STRING, 0)
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX\(arginfo_class_ImagickPixel_setColorCount, 0, 1, _IS_BOOL, 0\)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickPixel_setColorCount, 0, 0, 1)
#endif

	ZEND_ARG_TYPE_INFO(0, colorCount, IS_LONG, 0)
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX\(arginfo_class_ImagickPixel_setColorValue, 0, 2, _IS_BOOL, 0\)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickPixel_setColorValue, 0, 0, 2)
#endif

	ZEND_ARG_TYPE_INFO(0, color, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX\(arginfo_class_ImagickPixel_setColorValueQuantum, 0, 2, _IS_BOOL, 0\)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickPixel_setColorValueQuantum, 0, 0, 2)
#endif

	ZEND_ARG_TYPE_INFO(0, color, IS_LONG, 0)
	
#if MAGICKCORE_HDRI_ENABLE 
	ZEND_ARG_TYPE_INFO(0, value, IS_DOUBLE, 0)
#else
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
#endif

ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX\(arginfo_class_ImagickPixel_setHSL, 0, 3, _IS_BOOL, 0\)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickPixel_setHSL, 0, 0, 3)
#endif

	ZEND_ARG_TYPE_INFO(0, hue, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, saturation, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, luminosity, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX\(arginfo_class_ImagickPixel_setIndex, 0, 1, _IS_BOOL, 0\)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickPixel_setIndex, 0, 0, 1)
#endif

	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
ZEND_END_ARG_INFO()

#if MagickLibVersion >= 0x693

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX\(arginfo_class_ImagickPixel_setColorFromPixel, 0, 1, _IS_BOOL, 0\)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickPixel_setColorFromPixel, 0, 0, 1)
#endif

	ZEND_ARG_OBJ_INFO(0, srcPixel, ImagickPixel, 0)
ZEND_END_ARG_INFO()
#endif


ZEND_METHOD(ImagickPixel, __construct);
ZEND_METHOD(ImagickPixel, clear);
ZEND_METHOD(ImagickPixel, getColor);
ZEND_METHOD(ImagickPixel, getColorAsString);
ZEND_METHOD(ImagickPixel, getColorCount);
ZEND_METHOD(ImagickPixel, getColorQuantum);
ZEND_METHOD(ImagickPixel, getColorValue);
ZEND_METHOD(ImagickPixel, getColorValueQuantum);
ZEND_METHOD(ImagickPixel, getHSL);
ZEND_METHOD(ImagickPixel, getIndex);
ZEND_METHOD(ImagickPixel, isPixelSimilar);
ZEND_METHOD(ImagickPixel, isPixelSimilarQuantum);
ZEND_METHOD(ImagickPixel, setColor);
ZEND_METHOD(ImagickPixel, setColorCount);
ZEND_METHOD(ImagickPixel, setColorValue);
ZEND_METHOD(ImagickPixel, setColorValueQuantum);
ZEND_METHOD(ImagickPixel, setHSL);
ZEND_METHOD(ImagickPixel, setIndex);
#if MagickLibVersion >= 0x693
ZEND_METHOD(ImagickPixel, setColorFromPixel);
#endif


static const zend_function_entry class_ImagickPixel_methods[] = {
	ZEND_ME(ImagickPixel, __construct, arginfo_class_ImagickPixel___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickPixel, clear, arginfo_class_ImagickPixel_clear, ZEND_ACC_PUBLIC)
	ZEND_MALIAS(ImagickPixel, destroy, clear, arginfo_class_ImagickPixel_destroy, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickPixel, getColor, arginfo_class_ImagickPixel_getColor, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickPixel, getColorAsString, arginfo_class_ImagickPixel_getColorAsString, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickPixel, getColorCount, arginfo_class_ImagickPixel_getColorCount, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickPixel, getColorQuantum, arginfo_class_ImagickPixel_getColorQuantum, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickPixel, getColorValue, arginfo_class_ImagickPixel_getColorValue, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickPixel, getColorValueQuantum, arginfo_class_ImagickPixel_getColorValueQuantum, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickPixel, getHSL, arginfo_class_ImagickPixel_getHSL, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickPixel, getIndex, arginfo_class_ImagickPixel_getIndex, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickPixel, isPixelSimilar, arginfo_class_ImagickPixel_isPixelSimilar, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickPixel, isPixelSimilarQuantum, arginfo_class_ImagickPixel_isPixelSimilarQuantum, ZEND_ACC_PUBLIC)
	ZEND_MALIAS(ImagickPixel, isSimilar, isPixelSimilarQuantum, arginfo_class_ImagickPixel_isSimilar, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickPixel, setColor, arginfo_class_ImagickPixel_setColor, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickPixel, setColorCount, arginfo_class_ImagickPixel_setColorCount, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickPixel, setColorValue, arginfo_class_ImagickPixel_setColorValue, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickPixel, setColorValueQuantum, arginfo_class_ImagickPixel_setColorValueQuantum, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickPixel, setHSL, arginfo_class_ImagickPixel_setHSL, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickPixel, setIndex, arginfo_class_ImagickPixel_setIndex, ZEND_ACC_PUBLIC)
#if MagickLibVersion >= 0x693
	ZEND_ME(ImagickPixel, setColorFromPixel, arginfo_class_ImagickPixel_setColorFromPixel, ZEND_ACC_PUBLIC)
#endif
	ZEND_FE_END
};