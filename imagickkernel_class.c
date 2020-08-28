/*
   +----------------------------------------------------------------------+
   | PHP Version 5 / Imagick	                                          |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Author: Dan Ackroyd <danack@php.net>                                 |
   +----------------------------------------------------------------------+
*/

#include "php_imagick.h"
#include "php_imagick_defs.h"
#include "php_imagick_macros.h"
#include "php_imagick_helpers.h"

#ifdef IMAGICK_WITH_KERNEL

#if MagickLibVersion < 0x691
// These function defines are required currently as the functions are
// currently not available in the public ImageMagick header files
// This is being fixed for the next version of ImageMagick.
Image
  *MorphologyApply(const Image *,const ChannelType,const MorphologyMethod,
    const ssize_t,const KernelInfo *,const CompositeOperator,const double,
    ExceptionInfo *);

void
  ScaleKernelInfo(KernelInfo *,const double,const GeometryFlags),
  UnityAddKernelInfo(KernelInfo *,const double),
  ZeroKernelNans(KernelInfo *);
#endif


static void php_imagickkernelvalues_to_zval(zval *zv, KernelInfo *kernel_info) {
	int count;
	double value;
	unsigned int x, y;
#ifdef ZEND_ENGINE_3
	zval row;
#else
	zval *row;
#endif

	zval *p_row;

	count = 0;

	for (y=0; y<kernel_info->height ; y++) {
#ifdef ZEND_ENGINE_3
		p_row = &row;
#else
		MAKE_STD_ZVAL(row);
		p_row = row;
#endif

		array_init(p_row);
		for (x=0; x<kernel_info->width ; x++) {
			value = kernel_info->values[count];
			count++;

			//nan is not equal to itself
			if (value != value) {
				//this will be broken by some compilers - need to investigate more...
				add_next_index_bool(p_row, 0);
			}
			else {
				add_next_index_double(p_row, value);
			}
		}

		add_next_index_zval(zv, p_row);
	}
}


#if PHP_VERSION_ID >= 80000
HashTable* php_imagickkernel_get_debug_info(zend_object *obj, int *is_temp TSRMLS_DC) /* {{{ */
#else
HashTable* php_imagickkernel_get_debug_info(zval *obj, int *is_temp TSRMLS_DC) /* {{{ */
#endif
{
	php_imagickkernel_object *internp;
	HashTable *debug_info;
	KernelInfo *kernel_info;
#ifdef ZEND_ENGINE_3
	zval matrix;
#else
	zval *matrix;
#endif

	*is_temp = 1; //var_dump will destroy the hashtable

#if PHP_VERSION_ID >= 80000
	internp = php_imagickkernel_fetch_object(obj);
#else
	internp = Z_IMAGICKKERNEL_P(obj);
#endif
	kernel_info = internp->kernel_info;

	ALLOC_HASHTABLE(debug_info);
	ZEND_INIT_SYMTABLE_EX(debug_info, 1, 0);

	while (kernel_info != NULL) {
#ifdef ZEND_ENGINE_3
		array_init(&matrix);
		php_imagickkernelvalues_to_zval(&matrix, kernel_info);
		zend_hash_next_index_insert(debug_info, &matrix);
#else
		MAKE_STD_ZVAL(matrix);
		array_init(matrix);
		php_imagickkernelvalues_to_zval(matrix, kernel_info);
		zend_hash_next_index_insert(debug_info, &matrix, sizeof(zval *), NULL);
#endif
		kernel_info = kernel_info->next;
	}

	return debug_info;
}


static void im_CalcKernelMetaData(KernelInfo *kernel) {
	size_t i;

	kernel->minimum = kernel->maximum = 0.0;
	kernel->negative_range = kernel->positive_range = 0.0;

	for (i=0; i < (kernel->width*kernel->height); i++) {
		if (fabs(kernel->values[i]) < MagickEpsilon) {
			kernel->values[i] = 0.0;
		}
		if (kernel->values[i] < 0) {
			kernel->negative_range += kernel->values[i];
		}
		else {
			kernel->positive_range += kernel->values[i];
		}
		if (kernel->values[i] < kernel->minimum) {
			kernel->minimum = kernel->values[i];
		}
		
		if (kernel->values[i] > kernel->maximum) {
			kernel->maximum = kernel->values[i];
		}
	}

	return;
}


#if MagickLibVersion > 0x661
static KernelInfo *imagick_createKernel(KernelValueType *values, size_t width, size_t height, size_t origin_x, size_t origin_y)
{
	KernelInfo *kernel_info;

#if MagickLibVersion >= 0x700
	unsigned int i;
	ExceptionInfo *_exception_info = (ExceptionInfo *) NULL;
	//TODO - inspect exception info
	kernel_info=AcquireKernelInfo(NULL, _exception_info);
#else
	kernel_info=AcquireKernelInfo(NULL);
#endif
	if (kernel_info == (KernelInfo *) NULL) {
		return NULL;
	}

	kernel_info->width = width;
	kernel_info->height = height;

	kernel_info->x = origin_x;
	kernel_info->y = origin_y;

	//Need to free old values?
	if (kernel_info->values != NULL) {
		RelinquishAlignedMemory(kernel_info->values);
	}

#if MagickLibVersion >= 0x700
	kernel_info->values = (MagickRealType *)AcquireAlignedMemory(width*height, sizeof(MagickRealType));

	for (i=0; i<width*height;i++) {
		kernel_info->values[i] = (MagickRealType)values[i];
	}
	
#else
	kernel_info->values = values;
#endif

	im_CalcKernelMetaData(kernel_info);

	return kernel_info;
}
#endif

static void createKernelZval(zval *pzval, KernelInfo *kernel_info TSRMLS_DC) {
	php_imagickkernel_object *intern_return;

	object_init_ex(pzval, php_imagickkernel_sc_entry);
	intern_return = Z_IMAGICKKERNEL_P(pzval);
	intern_return->kernel_info = kernel_info;
}


/* {{{ proto ImagickKernel ImagickKernel::__construct()
   The ImagickKernel constructor
*/
PHP_METHOD(ImagickKernel, __construct)
{
	// This suppresses an 'unused parameter' warning.
	(void)return_value;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	// this method is private.
}
/* }}} */

#define MATRIX_ERROR_EMPTY "Cannot create kernel, matrix is empty."
#define MATRIX_ERROR_UNEVEN "Values must be matrix, with the same number of columns in each row."
#define MATRIX_ERROR_BAD_VALUE "Only numbers or false are valid values in a kernel matrix."
#define MATRIX_ORIGIN_REQUIRED "For kernels with even numbered rows or columns, the origin position must be specified."

/* {{{ proto ImagickKernel ImagickKernel::fromMatrix(array matrix, [array origin])
	Create a kernel from an 2d matrix of values. Each value should either be a float 
	(if the element should be used) or 'false' if the element should be skipped. For 
	matrixes that are odd sizes in both dimensions the the origin pixel will default 
	to the centre of the kernel. For all other kernel sizes the origin pixel must be specified.
*/
#ifdef ZEND_ENGINE_3
PHP_METHOD(ImagickKernel, fromMatrix)
{
	zval *kernel_array;
	zval *origin_array;
	HashTable *inner_array;
	KernelInfo *kernel_info;
	unsigned long num_rows, num_columns = 0;
	unsigned int previous_num_columns = (unsigned int)-1;
	unsigned int row, column;

	zval *pzval_outer;
	zval *pzval_inner;

	int count = 0;
	size_t origin_x, origin_y;
	zval *tmp;

	KernelValueType *values = NULL;
	double notanumber = sqrt((double)-1.0);  /* Special Value : Not A Number */

	count = 0;
	row = 0;
	origin_array = NULL;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "a|a", &kernel_array, &origin_array) == FAILURE) {
		return;
	}

	num_rows = zend_hash_num_elements(Z_ARRVAL_P(kernel_array));

	if (num_rows == 0) {
		//error - array has zero elements.
		php_imagick_throw_exception(IMAGICKKERNEL_CLASS, MATRIX_ERROR_EMPTY TSRMLS_CC);
		return;
	}


	for (row=0 ; row<num_rows ; row++) {
		pzval_outer = zend_hash_index_find(Z_ARRVAL_P(kernel_array), row);
		if (pzval_outer == NULL) {
			php_imagick_throw_exception(IMAGICKKERNEL_CLASS, MATRIX_ERROR_UNEVEN TSRMLS_CC);
			goto cleanup;
		}
		ZVAL_DEREF(pzval_outer);

		column = 0;

		if (Z_TYPE_P(pzval_outer) == IS_ARRAY ) {
			inner_array = Z_ARRVAL_P(pzval_outer);
			num_columns = zend_hash_num_elements(inner_array);

			if (num_columns == 0) {
				php_imagick_throw_exception(IMAGICKKERNEL_CLASS, MATRIX_ERROR_EMPTY TSRMLS_CC);
				goto cleanup;
			}

			if (values == NULL) {
				values = (KernelValueType *)AcquireAlignedMemory(num_columns, num_rows*sizeof(KernelValueType));
			}

			if (previous_num_columns != ((unsigned int)-1)) {
				if (previous_num_columns != num_columns) {
					php_imagick_throw_exception(IMAGICKKERNEL_CLASS, MATRIX_ERROR_UNEVEN TSRMLS_CC);
					goto cleanup;
				}
			}

			previous_num_columns = num_columns;

			for (column=0; column<num_columns ; column++) { 
				pzval_inner = zend_hash_index_find(inner_array, column);
				if (pzval_inner == NULL) {
					php_imagick_throw_exception(IMAGICKKERNEL_CLASS, MATRIX_ERROR_UNEVEN TSRMLS_CC);
					goto cleanup;
				}

				ZVAL_DEREF(pzval_inner);
				if (Z_TYPE_P(pzval_inner) == IS_DOUBLE) {
					//It's a float lets use it.
					values[count] = Z_DVAL_P(pzval_inner);
				}
				else if (Z_TYPE_P(pzval_inner) == IS_LONG) {
					//It's a long lets use it.
					values[count] = (float)Z_LVAL_P(pzval_inner);
				}
				else if (Z_TYPE_P(pzval_inner) == IS_FALSE) { 
					//It's false, use nan
					values[count] = notanumber;
				}
				else {
					php_imagick_throw_exception(IMAGICKKERNEL_CLASS, MATRIX_ERROR_BAD_VALUE TSRMLS_CC);
					goto cleanup;
				}
				count++;
			}
		}
		else {
			php_imagick_throw_exception(IMAGICKKERNEL_CLASS, MATRIX_ERROR_UNEVEN TSRMLS_CC);
			goto cleanup;
		}
	}

	if (origin_array == NULL) {
		if (((num_columns%2) == 0) || ((num_rows%2) == 0)) {
			php_imagick_throw_exception(IMAGICKKERNEL_CLASS, MATRIX_ORIGIN_REQUIRED TSRMLS_CC);
			goto cleanup;
		}
		origin_x = (num_columns - 1) >> 1;
		origin_y = (num_rows - 1) >> 1;
	}
	else {
		HashTable *origin_array_ht;
		origin_array_ht = Z_ARRVAL_P(origin_array);

		// parse the origin_x
		tmp = zend_hash_index_find(origin_array_ht, 0);
		if (tmp != NULL) {
			ZVAL_DEREF(tmp);
			origin_x = Z_LVAL_P(tmp);
		}
		else {
			php_imagick_throw_exception(IMAGICKKERNEL_CLASS, MATRIX_ORIGIN_REQUIRED TSRMLS_CC);
			goto cleanup;
		}
		// origin_x is unsigned, so checking for > num_columns, also
		// checks for < 0
		if (origin_x>=num_columns) {
			zend_throw_exception_ex(
				php_imagickkernel_exception_class_entry,
				5 TSRMLS_CC,
				"origin_x for matrix is outside bounds of columns: " ZEND_LONG_FMT,
				origin_x
			);
			goto cleanup;
		}

		// parse the origin_y
		tmp = zend_hash_index_find(origin_array_ht, 1);
		if (tmp != NULL) {
			ZVAL_DEREF(tmp);
			origin_y = Z_LVAL_P(tmp);
		}
		else {
			php_imagick_throw_exception(IMAGICKKERNEL_CLASS, MATRIX_ORIGIN_REQUIRED TSRMLS_CC);
			goto cleanup;
		}
		// origin_y is unsigned, so checking for > num_rows, also
		// checks for < 0
		if (origin_y>=num_rows) {
			zend_throw_exception_ex(
				php_imagickkernel_exception_class_entry,
				5 TSRMLS_CC,
				"origin_y for matrix is outside bounds of rows: " ZEND_LONG_FMT,
				origin_x
			);
			goto cleanup;
		}
	}

	kernel_info = imagick_createKernel(values, num_columns, num_rows, origin_x, origin_y);
	createKernelZval(return_value, kernel_info TSRMLS_CC);

	return;

cleanup:
	if (values != NULL) {
		RelinquishAlignedMemory(values);
	}
}

#else //not ZEND_ENGINE_3


PHP_METHOD(ImagickKernel, fromMatrix)
{
	zval *kernel_array;
	zval *origin_array;
	HashTable *inner_array;
	KernelInfo *kernel_info;
	unsigned long num_rows, num_columns = 0;
	unsigned int previous_num_columns = (unsigned int)-1;
	unsigned int row, column;

	HashTable *origin_array_ht;
	zval **ppzval_outer;
	zval **ppzval_inner;

	int count = 0;
	size_t origin_x, origin_y;
	zval **tmp;

	KernelValueType *values = NULL;
	double notanumber = sqrt((double)-1.0);  /* Special Value : Not A Number */

	previous_num_columns = -1;
	count = 0;
	row = 0;
	origin_array = NULL;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "a|a", &kernel_array, &origin_array) == FAILURE) {
		return;
	}

	num_rows = zend_hash_num_elements(Z_ARRVAL_P(kernel_array));

	if (num_rows == 0) {
		//error - array has zero elements.
		php_imagick_throw_exception(IMAGICKKERNEL_CLASS, MATRIX_ERROR_EMPTY TSRMLS_CC);
		return;
	}

	for (row=0 ; row<num_rows ; row++) {
		if (zend_hash_index_find(Z_ARRVAL_P(kernel_array), row, (void **) &ppzval_outer) != SUCCESS) {
			php_imagick_throw_exception(IMAGICKKERNEL_CLASS, MATRIX_ERROR_UNEVEN TSRMLS_CC);
			goto cleanup;
		}

		column = 0;

		if (Z_TYPE_PP(ppzval_outer) == IS_ARRAY ) {
			//parse this row
			inner_array = Z_ARRVAL_PP(ppzval_outer);
			num_columns = zend_hash_num_elements(inner_array);

			if (num_columns == 0) {
				php_imagick_throw_exception(IMAGICKKERNEL_CLASS, MATRIX_ERROR_EMPTY TSRMLS_CC);
				goto cleanup;
			}

			if (values == NULL) {
				values = (KernelValueType *)AcquireAlignedMemory(num_columns, num_rows*sizeof(KernelValueType));
			}

			if (previous_num_columns != ((unsigned int)-1)) {
				if (previous_num_columns != num_columns) {
					php_imagick_throw_exception(IMAGICKKERNEL_CLASS, MATRIX_ERROR_UNEVEN TSRMLS_CC);
					goto cleanup;
				}
			}

			previous_num_columns = num_columns;

			for (column=0; column<num_columns ; column++) { 
				if (zend_hash_index_find(inner_array, column, (void **) &ppzval_inner) != SUCCESS) {
					php_imagick_throw_exception(IMAGICKKERNEL_CLASS, MATRIX_ERROR_UNEVEN TSRMLS_CC);
					goto cleanup;
				}

				if (Z_TYPE_PP(ppzval_inner) == IS_DOUBLE) {
					//It's a float lets use it.
					values[count] = Z_DVAL_PP(ppzval_inner);
				}
				else if (Z_TYPE_PP(ppzval_inner) == IS_LONG) {
					//It's a long lets use it.
					values[count] = (float)Z_LVAL_PP(ppzval_inner);
				}
				else if (Z_TYPE_PP(ppzval_inner) == IS_BOOL && Z_BVAL_PP(ppzval_inner) == 0) { 
					//It's false, use nan
					values[count] = notanumber;
				}
				else {
					php_imagick_throw_exception(IMAGICKKERNEL_CLASS, MATRIX_ERROR_BAD_VALUE TSRMLS_CC);
					goto cleanup;
				}
				count++;
			}
		}
		else {
			php_imagick_throw_exception(IMAGICKKERNEL_CLASS, MATRIX_ERROR_UNEVEN TSRMLS_CC);
			goto cleanup;
		}
	}

	if (origin_array == NULL) {
		if (((num_columns%2) == 0) || ((num_rows%2) == 0)) {
			php_imagick_throw_exception(IMAGICKKERNEL_CLASS, MATRIX_ORIGIN_REQUIRED TSRMLS_CC);
			goto cleanup;
		}
		origin_x = (num_columns - 1) >> 1;
		origin_y = (num_rows - 1) >> 1;
	}
	else {
		origin_array_ht = Z_ARRVAL_P(origin_array);

		// parse and check the origin_x
		if (zend_hash_index_find(origin_array_ht, 0, (void**)&tmp) == SUCCESS) {
			origin_x = Z_LVAL_PP(tmp);
		}
		else {
			php_imagick_throw_exception(IMAGICKKERNEL_CLASS, MATRIX_ORIGIN_REQUIRED TSRMLS_CC);
			goto cleanup;
		}

		// origin_x is unsigned, so checking for > num_columns, also
		// checks for < 0
		if (origin_x>=num_columns) {
			zend_throw_exception_ex(
				php_imagickkernel_exception_class_entry,
				5 TSRMLS_CC,
				"origin_x for matrix is outside bounds of columns: %d",
				origin_x
			);
			goto cleanup;
		}

        // parse and check the origin_y
		if (zend_hash_index_find(origin_array_ht, 1, (void**)&tmp) == SUCCESS) {
			origin_y = Z_LVAL_PP(tmp);
		}
		else {
			php_imagick_throw_exception(IMAGICKKERNEL_CLASS, MATRIX_ORIGIN_REQUIRED TSRMLS_CC);
			goto cleanup;
		}

		// origin_y is unsigned, so checking for > num_rows, also
		// checks for < 0
		if (origin_y>=num_rows) {
			zend_throw_exception_ex(
				php_imagickkernel_exception_class_entry,
				5 TSRMLS_CC,
				"origin_y for matrix is outside bounds of rows: %d",
				origin_y
			);
			goto cleanup;
		}
	}

	kernel_info = imagick_createKernel(values, num_columns, num_rows, origin_x, origin_y);
	createKernelZval(return_value, kernel_info TSRMLS_CC);

	return;

cleanup:
	if (values != NULL) {
		RelinquishAlignedMemory(values);
	}
}
#endif //end of zend_engine_3 
/* }}} */

static void imagick_fiddle_with_geometry_info(ssize_t type, GeometryFlags flags, GeometryInfo *geometry_info) {

	/* special handling of missing values in input string */
	switch( type ) {
		/* Shape Kernel Defaults */
		case UnityKernel: {
			if ((flags & WidthValue) == 0)
			geometry_info->rho = 1.0;    /* Default scale = 1.0, zero is valid */
			break;
		}
		case SquareKernel:
		case DiamondKernel:
		case OctagonKernel:
		case DiskKernel:
		case PlusKernel:
		case CrossKernel: {
			if ( (flags & HeightValue) == 0 ) {
				geometry_info->sigma = 1.0;    /* Default scale = 1.0, zero is valid */
			}
			break;
		}
		case RingKernel: {
			if ((flags & XValue) == 0) {
				geometry_info->xi = 1.0;       /* Default scale = 1.0, zero is valid */
			}
			break;
		}
		case RectangleKernel: {    /* Rectangle - set size defaults */
			if ((flags & WidthValue) == 0) { /* if no width then */
				geometry_info->rho = geometry_info->sigma;         /* then  width = height */
			}
			if (geometry_info->rho < 1.0) {            /* if width too small */
				geometry_info->rho = 3;                 /* then  width = 3 */
			}
			if (geometry_info->sigma < 1.0) {          /* if height too small */
				geometry_info->sigma = geometry_info->rho;         /* then  height = width */
			}
			if ((flags & XValue) == 0) {    /* center offset if not defined */
				geometry_info->xi = (double)(((ssize_t)geometry_info->rho-1)/2);
			}
			if ((flags & YValue) == 0) {
				geometry_info->psi = (double)(((ssize_t)geometry_info->sigma-1)/2);
			}
			break;
		}
		/* Distance Kernel Defaults */
		case ChebyshevKernel:
		case ManhattanKernel:
		case OctagonalKernel:
		case EuclideanKernel: {
			if ((flags & HeightValue) == 0) {           /* no distance scale */
				geometry_info->sigma = 100.0;                       /* default distance scaling */
			}
			else if ((flags & AspectValue ) != 0) {     /* '!' flag */
				geometry_info->sigma = QuantumRange/(geometry_info->sigma+1); /* maximum pixel distance */
			}
			else if ((flags & PercentValue ) != 0) {    /* '%' flag */
				geometry_info->sigma *= QuantumRange/100.0;         /* percentage of color range */
			}
			break;
		}
		default: {
			break;
		}
	}
}

/* {{{ proto ImagickKernel ImagickKernel::fromBuiltin(type, string)
 Create a kernel from a builtin in kernel. See http://www.imagemagick.org/Usage/morphology/#kernel for examples. Currently the 'rotation' symbols are not supported. Example:
 $diamondKernel = ImagickKernel::fromBuiltIn(\Imagick::KERNEL_DIAMOND, "2");
*/
PHP_METHOD(ImagickKernel, fromBuiltin)
{
	im_long kernel_type;
	GeometryInfo geometry_info = {
		0, //rho,
		0, //sigma,
		0, //xi,
		0, //psi,
		0, //chi;
	};
	KernelInfo *kernel_info;
	char *string;
	IM_LEN_TYPE string_len;
	GeometryFlags flags;
#if MagickLibVersion >= 0x700
	ExceptionInfo *_exception_info = NULL;
#endif

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ls", &kernel_type, &string, &string_len) == FAILURE) {
		return;
	}

	flags = ParseGeometry(string, &geometry_info);
	imagick_fiddle_with_geometry_info(kernel_type, flags, &geometry_info);
	
#if MagickLibVersion >= 0x700
	//TODO - inspect exception info
	kernel_info = AcquireKernelBuiltIn(kernel_type, &geometry_info, _exception_info);
#else
	kernel_info = AcquireKernelBuiltIn(kernel_type, &geometry_info);
#endif
	createKernelZval(return_value, kernel_info TSRMLS_CC);

	return;
}

/* }}} */


/* {{{ proto void ImagickKernel::addKernel(ImagickKernel kernel)
	Attach another kernel to this kernel to allow them to both be applied in a single morphology or filter function. Returns the new combined kernel.
*/
PHP_METHOD(ImagickKernel, addKernel)
{
	zval *objvar;
	KernelInfo *kernel_info_add_clone;

	KernelInfo *kernel_info;
	KernelInfo *kernel_info_target;

	php_imagickkernel_object *kernel;
	php_imagickkernel_object *internp;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "O", &objvar, php_imagickkernel_sc_entry) == FAILURE) {
		return;
	}

	kernel = Z_IMAGICKKERNEL_P(objvar);
	internp = Z_IMAGICKKERNEL_P(getThis());

	if (kernel->kernel_info == NULL) {
		zend_throw_exception(php_imagickkernel_exception_class_entry, "ImagickKernel is empty, cannot be used", (long)0 TSRMLS_CC);
		RETURN_NULL();
	}

	kernel_info = internp->kernel_info;
	do {
		kernel_info_target = kernel_info;
		kernel_info = kernel_info->next;
	} while (kernel_info != NULL);

	kernel_info_add_clone = CloneKernelInfo(kernel->kernel_info);
	kernel_info_target->next = kernel_info_add_clone;

	return;
}
/* }}} */


/* {{{ proto ImagickKernel[] ImagickKernel::separate(void)
	Separates a linked set of kernels and returns an array of ImagickKernels.
*/
PHP_METHOD(ImagickKernel, separate)
{
	php_imagickkernel_object *internp;
	KernelInfo *kernel_info;
	KernelInfo *kernel_info_copy;
	int number_values;
	KernelValueType * values_copy;

#ifdef ZEND_ENGINE_3
	zval separate_object;
#else
	zval *separate_object;
#endif

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	internp = Z_IMAGICKKERNEL_P(getThis());
	IMAGICK_KERNEL_NOT_NULL_EMPTY(internp);
	kernel_info = internp->kernel_info;

	array_init(return_value);

	while (kernel_info != NULL) {
		number_values = kernel_info->width * kernel_info->height;
		values_copy = (KernelValueType *)AcquireAlignedMemory(kernel_info->width, kernel_info->height*sizeof(KernelValueType));
		memcpy(values_copy, kernel_info->values, number_values * sizeof(KernelValueType));

		kernel_info_copy = imagick_createKernel(
			values_copy,
			kernel_info->width,
			kernel_info->height,
			kernel_info->x,
			kernel_info->y
		);

#ifdef ZEND_ENGINE_3
		createKernelZval(&separate_object, kernel_info_copy TSRMLS_CC);
		add_next_index_zval(return_value, &separate_object);
#else 
		MAKE_STD_ZVAL(separate_object);
		createKernelZval(separate_object, kernel_info_copy TSRMLS_CC);
		add_next_index_zval(return_value, separate_object);
#endif
		kernel_info = kernel_info->next;
	}

	return;
}
/* }}} */


/* {{{ proto [] ImagickKernel::getMatrix(void)
	Get the 2d matrix of values used in this kernel. The elements are either 
	float for elements that are used or 'false' if the element should be skipped.
*/
PHP_METHOD(ImagickKernel, getMatrix)
{
	php_imagickkernel_object *internp;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	internp = Z_IMAGICKKERNEL_P(getThis());
	IMAGICK_KERNEL_NOT_NULL_EMPTY(internp);

	array_init(return_value);
	php_imagickkernelvalues_to_zval(return_value, internp->kernel_info);

	return;
}
/* }}} */





/* {{{ proto [] ImagickKernel::scale(float scaling_factor[, int NORMALIZE_KERNEL_FLAG])
	ScaleKernelInfo() scales the given kernel list by the given amount, with or without 
	normalization of the sum of the kernel values (as per given flags).

	The exact behaviour of this function depends on the normalization type being used 
	please see http://www.imagemagick.org/api/morphology.php#ScaleKernelInfo for details.

	Flag should be one of NORMALIZE_KERNEL_VALUE, NORMALIZE_KERNEL_CORRELATE, 
	NORMALIZE_KERNEL_PERCENT or not set.
*/
PHP_METHOD(ImagickKernel, scale)
{
	php_imagickkernel_object *internp;
	double scale;
	im_long normalize_flag;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d|l", &scale, &normalize_flag) == FAILURE) {
		return;
	}

	internp = Z_IMAGICKKERNEL_P(getThis());
	IMAGICK_KERNEL_NOT_NULL_EMPTY(internp);
	ScaleKernelInfo(internp->kernel_info, scale, normalize_flag);

	return;
}
/* }}} */




/* {{{ proto [] ImagickKernel::addUnityKernel(float scale)
	Adds a given amount of the 'Unity' Convolution Kernel to the given pre-scaled
	and normalized Kernel. This in effect adds that amount of the original image 
	into the resulting convolution kernel. The resulting effect is to convert the
	defined kernels into blended soft-blurs, unsharp kernels or into sharpening kernels.
*/
PHP_METHOD(ImagickKernel, addUnityKernel)
{
	php_imagickkernel_object *internp;
	double scale;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d", &scale) == FAILURE) {
		return;
	}

	internp = Z_IMAGICKKERNEL_P(getThis());
	IMAGICK_KERNEL_NOT_NULL_EMPTY(internp);
	UnityAddKernelInfo(internp->kernel_info, scale);

	return;
}
/* }}} */

#endif
