

#if PHP_VERSION_ID < 80000
// Allow the generated stubs to work on previous versions of PHP

#define ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(pass_by_ref, name, type_hint, allow_null, default_value) \
  ZEND_ARG_INFO(pass_by_ref, name)

#define ZEND_ARG_OBJ_TYPE_MASK(pass_by_ref, name, class_name, type_mask, default_value) \
     ZEND_ARG_INFO(pass_by_ref, name)

#define MAY_BE_STRING ""

#endif