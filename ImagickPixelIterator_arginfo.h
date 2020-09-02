/* This is a generated file, edit the .stub.php file instead.
* Stub hash: regen with 'sh regen_arginfo.sh' */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickPixelIterator___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, wand, Imagick, 0)
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickPixelIterator_clear, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickPixelIterator_clear, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_ImagickPixelIterator_getPixelIterator, 0, 1, ImagickPixelIterator, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickPixelIterator_getPixelIterator, 0, 0, 1)
#endif

	ZEND_ARG_OBJ_INFO(0, source, Imagick, 0)
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_ImagickPixelIterator_getPixelRegionIterator, 0, 5, ImagickPixelIterator, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickPixelIterator_getPixelRegionIterator, 0, 0, 5)
#endif

	ZEND_ARG_OBJ_INFO(0, source, Imagick, 0)
	
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

#define arginfo_class_ImagickPixelIterator_destroy arginfo_class_ImagickPixelIterator_clear


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickPixelIterator_getCurrentIteratorRow, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickPixelIterator_getCurrentIteratorRow, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickPixelIterator_getIteratorRow, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickPixelIterator_getIteratorRow, 0, 0, 0)
#endif

ZEND_END_ARG_INFO()

#define arginfo_class_ImagickPixelIterator_getNextIteratorRow arginfo_class_ImagickPixelIterator_getCurrentIteratorRow

#define arginfo_class_ImagickPixelIterator_getPreviousIteratorRow arginfo_class_ImagickPixelIterator_getCurrentIteratorRow

#define arginfo_class_ImagickPixelIterator_key arginfo_class_ImagickPixelIterator_getIteratorRow

#define arginfo_class_ImagickPixelIterator_next arginfo_class_ImagickPixelIterator_getCurrentIteratorRow

#define arginfo_class_ImagickPixelIterator_rewind arginfo_class_ImagickPixelIterator_clear

#define arginfo_class_ImagickPixelIterator_current arginfo_class_ImagickPixelIterator_getCurrentIteratorRow


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickPixelIterator_newPixelIterator, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickPixelIterator_newPixelIterator, 0, 0, 1)
#endif

	ZEND_ARG_OBJ_INFO(0, wand, Imagick, 0)
ZEND_END_ARG_INFO()


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickPixelIterator_newPixelRegionIterator, 0, 5, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickPixelIterator_newPixelRegionIterator, 0, 0, 5)
#endif

	ZEND_ARG_OBJ_INFO(0, wand, Imagick, 0)
	
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

#define arginfo_class_ImagickPixelIterator_resetIterator arginfo_class_ImagickPixelIterator_clear

#define arginfo_class_ImagickPixelIterator_setIteratorFirstRow arginfo_class_ImagickPixelIterator_clear

#define arginfo_class_ImagickPixelIterator_setIteratorLastRow arginfo_class_ImagickPixelIterator_clear


#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ImagickPixelIterator_setIteratorRow, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ImagickPixelIterator_setIteratorRow, 0, 0, 1)
#endif

	
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO(0, row, IS_LONG, 0)
#else
    ZEND_ARG_INFO(0, row)
#endif
ZEND_END_ARG_INFO()

#define arginfo_class_ImagickPixelIterator_syncIterator arginfo_class_ImagickPixelIterator_clear

#define arginfo_class_ImagickPixelIterator_valid arginfo_class_ImagickPixelIterator_clear


ZEND_METHOD(ImagickPixelIterator, __construct);
ZEND_METHOD(ImagickPixelIterator, clear);
ZEND_METHOD(ImagickPixelIterator, getPixelIterator);
ZEND_METHOD(ImagickPixelIterator, getPixelRegionIterator);
ZEND_METHOD(ImagickPixelIterator, getCurrentIteratorRow);
ZEND_METHOD(ImagickPixelIterator, getIteratorRow);
ZEND_METHOD(ImagickPixelIterator, getNextIteratorRow);
ZEND_METHOD(ImagickPixelIterator, getPreviousIteratorRow);
ZEND_METHOD(ImagickPixelIterator, resetIterator);
ZEND_METHOD(ImagickPixelIterator, newPixelIterator);
ZEND_METHOD(ImagickPixelIterator, newPixelRegionIterator);
ZEND_METHOD(ImagickPixelIterator, setIteratorFirstRow);
ZEND_METHOD(ImagickPixelIterator, setIteratorLastRow);
ZEND_METHOD(ImagickPixelIterator, setIteratorRow);
ZEND_METHOD(ImagickPixelIterator, syncIterator);
ZEND_METHOD(ImagickPixelIterator, valid);


static const zend_function_entry class_ImagickPixelIterator_methods[] = {
	ZEND_ME(ImagickPixelIterator, __construct, arginfo_class_ImagickPixelIterator___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickPixelIterator, clear, arginfo_class_ImagickPixelIterator_clear, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickPixelIterator, getPixelIterator, arginfo_class_ImagickPixelIterator_getPixelIterator, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(ImagickPixelIterator, getPixelRegionIterator, arginfo_class_ImagickPixelIterator_getPixelRegionIterator, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_MALIAS(ImagickPixelIterator, destroy, clear, arginfo_class_ImagickPixelIterator_destroy, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickPixelIterator, getCurrentIteratorRow, arginfo_class_ImagickPixelIterator_getCurrentIteratorRow, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickPixelIterator, getIteratorRow, arginfo_class_ImagickPixelIterator_getIteratorRow, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickPixelIterator, getNextIteratorRow, arginfo_class_ImagickPixelIterator_getNextIteratorRow, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickPixelIterator, getPreviousIteratorRow, arginfo_class_ImagickPixelIterator_getPreviousIteratorRow, ZEND_ACC_PUBLIC)
	ZEND_MALIAS(ImagickPixelIterator, key, getIteratorRow, arginfo_class_ImagickPixelIterator_key, ZEND_ACC_PUBLIC)
	ZEND_MALIAS(ImagickPixelIterator, next, getNextIteratorRow, arginfo_class_ImagickPixelIterator_next, ZEND_ACC_PUBLIC)
	ZEND_MALIAS(ImagickPixelIterator, rewind, resetIterator, arginfo_class_ImagickPixelIterator_rewind, ZEND_ACC_PUBLIC)
	ZEND_MALIAS(ImagickPixelIterator, current, getCurrentIteratorRow, arginfo_class_ImagickPixelIterator_current, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickPixelIterator, newPixelIterator, arginfo_class_ImagickPixelIterator_newPixelIterator, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickPixelIterator, newPixelRegionIterator, arginfo_class_ImagickPixelIterator_newPixelRegionIterator, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickPixelIterator, resetIterator, arginfo_class_ImagickPixelIterator_resetIterator, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickPixelIterator, setIteratorFirstRow, arginfo_class_ImagickPixelIterator_setIteratorFirstRow, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickPixelIterator, setIteratorLastRow, arginfo_class_ImagickPixelIterator_setIteratorLastRow, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickPixelIterator, setIteratorRow, arginfo_class_ImagickPixelIterator_setIteratorRow, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickPixelIterator, syncIterator, arginfo_class_ImagickPixelIterator_syncIterator, ZEND_ACC_PUBLIC)
	ZEND_ME(ImagickPixelIterator, valid, arginfo_class_ImagickPixelIterator_valid, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};