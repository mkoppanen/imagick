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
#ifndef PHP_IMAGICK_DEFS_H /* PHP_IMAGICK_DEFS_H */
# define PHP_IMAGICK_DEFS_H

/* Include magic wand header */
#if defined (IM_MAGICKWAND_HEADER_STYLE_SEVEN)
#  include <MagickWand/MagickWand.h>
#elif defined (IM_MAGICKWAND_HEADER_STYLE_OLD)
#  include <wand/magick-wand.h>
#else
#  include <wand/MagickWand.h>
#endif

#if MagickLibVersion >= 0x700
#include "shim_im6_to_im7.h"
#endif

/* Some extra headers */
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"
#include "ext/standard/php_string.h"
#include "ext/standard/info.h"
#include "ext/standard/php_filestat.h"
#include "php_ini.h"
#include "Zend/zend.h"

#if PHP_VERSION_ID >= 80000
	#define HAVE_LOCALE_H
	#define TSRMLS_C
	#define TSRMLS_CC
	#define TSRMLS_D
	#define TSRMLS_DC
	#define TSRMLS_FETCH()
	#define TSRMLS_SET_CTX(ctx)
#endif

/* Include locale header */
#ifdef HAVE_LOCALE_H
# include <locale.h>
#endif

#if MagickLibVersion >= 0x680
	#define IMAGICK_WITH_KERNEL
#endif



#if MagickLibVersion >= 0x700
#if !defined(MaxTextExtent)
# define MaxTextExtent  4096  /* always >= 4096 */
#endif

#endif


#ifdef ZEND_ENGINE_3
	#define im_long zend_long
#else
	#define im_long long
#endif


typedef struct _php_imagick_callback {
	void ***thread_ctx;
#ifdef ZEND_ENGINE_3
	zval user_callback;
#else
	zval *user_callback;
#endif
	struct _php_imagick_callback *previous_callback;
} php_imagick_callback;

/* Globals, needed for the ini settings */
ZEND_BEGIN_MODULE_GLOBALS(imagick)
	zend_bool locale_fix;
	zend_bool progress_monitor;
	zend_bool skip_version_check;

	zend_bool set_single_thread;
	im_long shutdown_sleep_count;

	php_imagick_callback *progress_callback;
#ifdef PHP_IMAGICK_ZEND_MM
	MagickWand *keep_alive;
#endif
ZEND_END_MODULE_GLOBALS(imagick)

#ifdef ZTS
# define IMAGICK_G(v) TSRMG(imagick_globals_id, zend_imagick_globals *, v)
#else
# define IMAGICK_G(v) (imagick_globals.v)
#endif

ZEND_EXTERN_MODULE_GLOBALS(imagick)

#ifdef HAVE_LOCALE_H
# if defined(PHP_WIN32)
#  define IMAGICK_LC_NUMERIC_LOCALE "English"
# else
#  define IMAGICK_LC_NUMERIC_LOCALE "C"
# endif
#endif

#if PHP_MAJOR_VERSION == 5 && PHP_MINOR_VERSION < 3
#define zend_parse_parameters_none() zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "")
#endif


/* Class names */
#define PHP_IMAGICK_SC_NAME "Imagick"
#define PHP_IMAGICK_EXCEPTION_SC_NAME "ImagickException"

#define PHP_IMAGICKDRAW_SC_NAME "ImagickDraw"
#define PHP_IMAGICKDRAW_EXCEPTION_SC_NAME "ImagickDrawException"

#define PHP_IMAGICKPIXEL_SC_NAME "ImagickPixel"
#define PHP_IMAGICKPIXEL_EXCEPTION_SC_NAME "ImagickPixelException"

#define PHP_IMAGICKPIXELITERATOR_SC_NAME "ImagickPixelIterator"
#define PHP_IMAGICKPIXELITERATOR_EXCEPTION_SC_NAME "ImagickPixelIteratorException"

#ifdef IMAGICK_WITH_KERNEL
#define PHP_IMAGICKKERNEL_SC_NAME "ImagickKernel"
#define PHP_IMAGICKKERNEL_EXCEPTION_SC_NAME "ImagickKernelException"
#endif


#ifdef ZEND_ENGINE_3

/* Structure for Imagick object. */
typedef struct _php_imagick_object  {
	MagickWand *magick_wand;
	char *progress_monitor_name;
	zend_bool next_out_of_bound;
	zend_object zo;
} php_imagick_object;

#else

/* Structure for Imagick object. */
typedef struct _php_imagick_object  {
	zend_object zo;
	MagickWand *magick_wand;
	char *progress_monitor_name;
	zend_bool next_out_of_bound;
} php_imagick_object;

#endif


#ifdef ZEND_ENGINE_3

/* Structure for ImagickDraw object. */
typedef struct _php_imagickdraw_object  {
	DrawingWand *drawing_wand;
	zend_object zo;
} php_imagickdraw_object;


#else 


/* Structure for ImagickDraw object. */
typedef struct _php_imagickdraw_object  {
	zend_object zo;
	DrawingWand *drawing_wand;
} php_imagickdraw_object;


#endif

#ifdef ZEND_ENGINE_3

/* Structure for ImagickPixelIterator object. */
typedef struct _php_imagickpixeliterator_object  {
	
	PixelIterator *pixel_iterator;
	zend_bool initialized;

#if MagickLibVersion <= 0x628
	long rows;
	long iterator_position;
#endif

	zend_object zo;
} php_imagickpixeliterator_object;

#else

/* Structure for ImagickPixelIterator object. */
typedef struct _php_imagickpixeliterator_object  {
	zend_object zo;
	PixelIterator *pixel_iterator;
	zend_bool initialized;

#if MagickLibVersion <= 0x628
	long rows;
	long iterator_position;
#endif

} php_imagickpixeliterator_object;

#endif


#ifdef ZEND_ENGINE_3

/* Structure for ImagickPixel object. */
typedef struct _php_imagickpixel_object  {
	PixelWand *pixel_wand;
	zend_bool initialized_via_iterator;
	zend_object zo;
} php_imagickpixel_object;


#else


/* Structure for ImagickPixel object. */
typedef struct _php_imagickpixel_object  {
	zend_object zo;
	PixelWand *pixel_wand;
	zend_bool initialized_via_iterator;
} php_imagickpixel_object;

#endif


#ifdef IMAGICK_WITH_KERNEL
#ifdef ZEND_ENGINE_3
/* Structure for ImagickKernel object. */
typedef struct _php_imagickkernel_object  {
	KernelInfo *kernel_info;
	zend_object zo;
} php_imagickkernel_object;
#else

/* Structure for ImagickKernel object. */
typedef struct _php_imagickkernel_object  {
    zend_object zo;
    KernelInfo *kernel_info;
} php_imagickkernel_object;
#endif
#endif

//Object fetching.
#ifdef ZEND_ENGINE_3 

static inline php_imagick_object *php_imagick_fetch_object(zend_object *obj) {
	return (php_imagick_object *)((char*)(obj) - XtOffsetOf(php_imagick_object, zo));
}

static inline php_imagickdraw_object *php_imagickdraw_fetch_object(zend_object *obj) {
	return (php_imagickdraw_object *)((char*)(obj) - XtOffsetOf(php_imagickdraw_object, zo));
}

static inline php_imagickpixel_object *php_imagickpixel_fetch_object(zend_object *obj) {
	return (php_imagickpixel_object *)((char*)(obj) - XtOffsetOf(php_imagickpixel_object, zo));
}

static inline php_imagickpixeliterator_object *php_imagickpixeliterator_fetch_object(zend_object *obj) {
	return (php_imagickpixeliterator_object *)((char*)(obj) - XtOffsetOf(php_imagickpixeliterator_object, zo));
}

#ifdef IMAGICK_WITH_KERNEL
static inline php_imagickkernel_object *php_imagickkernel_fetch_object(zend_object *obj) {
	return (php_imagickkernel_object *)((char*)(obj) - XtOffsetOf(php_imagickkernel_object, zo));
}
#endif

#else 
	#define php_imagick_fetch_object(object) ((php_imagick_object *)object)
	#define php_imagickdraw_fetch_object(object) ((php_imagickdraw_object *)object) 
	#define php_imagickpixel_fetch_object(object) ((php_imagickpixel_object *)object)
	#define php_imagickpixeliterator_fetch_object(object) ((php_imagickpixeliterator_object *)object)
	#define php_imagickkernel_fetch_object(object) ((php_imagickkernel_object *)object)
#endif

// Object access
#ifdef ZEND_ENGINE_3
	#define Z_IMAGICK_P(zv) php_imagick_fetch_object(Z_OBJ_P((zv)))
	#define Z_IMAGICKDRAW_P(zv) php_imagickdraw_fetch_object(Z_OBJ_P((zv)))
	#define Z_IMAGICKPIXEL_P(zv) php_imagickpixel_fetch_object(Z_OBJ_P((zv)))
	#define Z_IMAGICKPIXELITERATOR_P(zv) php_imagickpixeliterator_fetch_object(Z_OBJ_P((zv)))
#ifdef IMAGICK_WITH_KERNEL
	#define Z_IMAGICKKERNEL_P(zv) php_imagickkernel_fetch_object(Z_OBJ_P((zv)))
#endif
#else
	#define Z_IMAGICK_P(zv) (php_imagick_object *)zend_object_store_get_object(zv TSRMLS_CC)
	#define Z_IMAGICKDRAW_P(zv) (php_imagickdraw_object *)zend_object_store_get_object(zv TSRMLS_CC)
	#define Z_IMAGICKPIXEL_P(zv) (php_imagickpixel_object *) zend_object_store_get_object(zv TSRMLS_CC)
	#define Z_IMAGICKPIXELITERATOR_P(zv) (php_imagickpixeliterator_object *)zend_object_store_get_object(zv TSRMLS_CC)
	#define Z_IMAGICKKERNEL_P(zv) (php_imagickkernel_object *)zend_object_store_get_object(zv TSRMLS_CC)
#endif

// String access
#ifdef ZEND_ENGINE_3
	#define IM_ZVAL_STRING(zv, charstar) ZVAL_STRING(zv, charstar);
	#define IM_RETURN_STRING(s) RETURN_STRING(s)
#else
	#define IM_ZVAL_STRING(zv, charstar) ZVAL_STRING(zv, charstar, 1);
	//RETURN_STRING(s, duplicate) 
	#define IM_RETURN_STRING(s) RETURN_STRING(s, 0)
#endif

#ifdef ZEND_ENGINE_3
	#define IM_add_assoc_string(zv, key, charstr) add_assoc_string(zv, key, charstr)
	#define IM_ZVAL_STRINGL(zv, charstr, length) ZVAL_STRINGL(zv, charstr, length)
	#define IM_add_next_index_string(zv, charstr) add_next_index_string(zv, charstr)
	#define IM_LEN_TYPE size_t
#else
	#define IM_add_assoc_string(zv, key, charstr) add_assoc_string(zv, key, charstr, 1)
	#define IM_add_assoc_string(zv, key, charstr) add_assoc_string(zv, key, charstr, 1)
	#define IM_ZVAL_STRINGL(zv, charstr, length) ZVAL_STRINGL(zv, charstr, length, 1)
	#define IM_add_next_index_string(zv, charstr) add_next_index_string(zv, charstr, 1)
	#define IM_add_next_index_zval(zv1, zv2)
	#define IM_LEN_TYPE int
#endif

#ifdef ZEND_ENGINE_3
	#define IM_ZEND_OBJECT zend_object
#else 
	#define IM_ZEND_OBJECT void
#endif





/* Define some color constants */
typedef enum _php_imagick_color_t {
	PHP_IMAGICK_COLOR_MIN = 10,
	PHP_IMAGICK_COLOR_BLACK,
	PHP_IMAGICK_COLOR_BLUE,
	PHP_IMAGICK_COLOR_CYAN,
	PHP_IMAGICK_COLOR_GREEN,
	PHP_IMAGICK_COLOR_RED,
	PHP_IMAGICK_COLOR_YELLOW,
	PHP_IMAGICK_COLOR_MAGENTA,
#if MagickLibVersion < 0x700
	PHP_IMAGICK_COLOR_OPACITY,
#endif
	PHP_IMAGICK_COLOR_ALPHA,
	PHP_IMAGICK_COLOR_FUZZ,
	PHP_IMAGICK_COLOR_MAX,
} php_imagick_color_t;

/* Class enum */
typedef enum _php_imagick_class_type_t {
	IMAGICK_CLASS,
	IMAGICKDRAW_CLASS,
	IMAGICKPIXELITERATOR_CLASS,
	IMAGICKPIXEL_CLASS,
#ifdef IMAGICK_WITH_KERNEL
	IMAGICKKERNEL_CLASS
#endif
} php_imagick_class_type_t;

/* Read / write constants */
typedef enum _php_imagick_rw_result_t {
	IMAGICK_RW_OK,
	IMAGICK_RW_SAFE_MODE_ERROR,
	IMAGICK_RW_OPEN_BASEDIR_ERROR,
	IMAGICK_RW_UNDERLYING_LIBRARY,
	IMAGICK_RW_PERMISSION_DENIED,
	IMAGICK_RW_FILENAME_TOO_LONG,
	IMAGICK_RW_PATH_DOES_NOT_EXIST,
	IMAGICK_RW_PATH_IS_DIR,
} php_imagick_rw_result_t;

/* Class entries */
extern zend_class_entry *php_imagick_sc_entry;
extern zend_class_entry *php_imagick_exception_class_entry;
extern zend_class_entry *php_imagickdraw_sc_entry;
extern zend_class_entry *php_imagickdraw_exception_class_entry;
extern zend_class_entry *php_imagickpixel_sc_entry;
extern zend_class_entry *php_imagickpixel_exception_class_entry;
extern zend_class_entry *php_imagickpixeliterator_sc_entry;
extern zend_class_entry *php_imagickpixeliterator_exception_class_entry;
#ifdef IMAGICK_WITH_KERNEL
extern zend_class_entry *php_imagickkernel_sc_entry;
extern zend_class_entry *php_imagickkernel_exception_class_entry;
#endif

/* Forward declarations (Imagick) */

#if (MagickLibVersion >= 0x700 && MagickLibVersion >= 0x709)
  #define PHP_IMAGICK_HAVE_HOUGHLINE 1
#else
  #define PHP_IMAGICK_HAVE_HOUGHLINE 0
#endif

/* The conditional methods */
#if MagickLibVersion > 0x628
PHP_METHOD(imagick, pingimageblob);
PHP_METHOD(imagick, pingimagefile);
PHP_METHOD(imagick, transposeimage);
PHP_METHOD(imagick, transverseimage);
PHP_METHOD(imagick, trimimage);
PHP_METHOD(imagick, waveimage);
PHP_METHOD(imagick, vignetteimage);
PHP_METHOD(imagick, compareimagelayers);
PHP_METHOD(imagick, optimizeimagelayers);
PHP_METHOD(imagick, uniqueimagecolors);
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
PHP_METHOD(imagick, getimagematte);
#endif //#if MagickLibVersion < 0x700
#endif
PHP_METHOD(imagick, setimagematte);
PHP_METHOD(imagick, adaptiveresizeimage);
PHP_METHOD(imagick, sketchimage);
PHP_METHOD(imagick, shadeimage);
PHP_METHOD(imagick, getsizeoffset);
PHP_METHOD(imagick, setsizeoffset);
PHP_METHOD(imagick, adaptiveblurimage);
PHP_METHOD(imagick, contraststretchimage);
PHP_METHOD(imagick, adaptivesharpenimage);
PHP_METHOD(imagick, randomthresholdimage);
#if MagickLibVersion < 0x700
PHP_METHOD(imagick, roundcornersimage);
#endif
PHP_METHOD(imagick, setiteratorindex);
PHP_METHOD(imagick, getiteratorindex);
#if MagickLibVersion < 0x700
PHP_METHOD(imagick, transformimage);
#endif // #if MagickLibVersion < 0x700
#endif
#if MagickLibVersion > 0x630
#if MagickLibVersion < 0x700
PHP_METHOD(imagick, setimageopacity);
#endif
#if MagickLibVersion >= 0x700
PHP_METHOD(imagick, setimagealpha);
#endif
#if MagickLibVersion < 0x700
PHP_METHOD(imagick, orderedposterizeimage);
#endif //#if MagickLibVersion < 0x700
#endif
#if MagickLibVersion > 0x631
PHP_METHOD(imagick, polaroidimage);
PHP_METHOD(imagick, getimageproperty);
PHP_METHOD(imagick, setimageproperty);
PHP_METHOD(imagick, deleteimageproperty);
PHP_METHOD(imagick, identifyformat);
PHP_METHOD(imagick, setimageinterpolatemethod);
PHP_METHOD(imagick, getimageinterpolatemethod);
PHP_METHOD(imagick, linearstretchimage);
PHP_METHOD(imagick, getimagelength);
PHP_METHOD(imagick, extentimage);
#endif
#if MagickLibVersion > 0x633
PHP_METHOD(imagick, getimageorientation);
PHP_METHOD(imagick, setimageorientation);
#endif
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion > 0x634
PHP_METHOD(imagick, paintfloodfillimage);
#endif
#endif
#if MagickLibVersion > 0x635
PHP_METHOD(imagick, clutimage);
PHP_METHOD(imagick, getimageproperties);
PHP_METHOD(imagick, getimageprofiles);
PHP_METHOD(imagick, distortimage);
PHP_METHOD(imagick, writeimagefile);
PHP_METHOD(imagick, writeimagesfile);
PHP_METHOD(imagick, resetimagepage);

#if MagickLibVersion < 0x700
PHP_METHOD(imagick, setimageclipmask);
PHP_METHOD(imagick, getimageclipmask);
#endif
PHP_METHOD(imagick, animateimages);
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
PHP_METHOD(imagick, recolorimage);
#endif
#endif
#endif
#if MagickLibVersion > 0x636
PHP_METHOD(imagick, setfont);
PHP_METHOD(imagick, getfont);
PHP_METHOD(imagick, setpointsize);
PHP_METHOD(imagick, getpointsize);
PHP_METHOD(imagick, mergeimagelayers);
#endif
#if MagickLibVersion > 0x637
PHP_METHOD(imagick, floodfillpaintimage);
PHP_METHOD(imagick, opaquepaintimage);
PHP_METHOD(imagick, transparentpaintimage);
PHP_METHOD(imagick, setimagealphachannel);
#endif
#if MagickLibVersion > 0x638
PHP_METHOD(imagick, liquidrescaleimage);
PHP_METHOD(imagick, decipherimage);
PHP_METHOD(imagick, encipherimage);
#endif
#if MagickLibVersion > 0x639
PHP_METHOD(imagick, setgravity);
PHP_METHOD(imagick, getgravity);
PHP_METHOD(imagick, getimagechannelrange);
PHP_METHOD(imagick, getimagealphachannel);
#endif
#if MagickLibVersion > 0x642
PHP_METHOD(imagick, getimagechanneldistortions);
#endif
#if MagickLibVersion > 0x643
PHP_METHOD(imagick, getimagegravity);
PHP_METHOD(imagick, setimagegravity);
#endif
#if MagickLibVersion > 0x645
PHP_METHOD(imagick, importimagepixels);
PHP_METHOD(imagick, deskewimage);


#if PHP_IMAGICK_HAVE_HOUGHLINE
PHP_METHOD(imagick, houghlineimage);
#endif
PHP_METHOD(imagick, segmentimage);
PHP_METHOD(imagick, sparsecolorimage);
PHP_METHOD(imagick, remapimage);
#endif
#if MagickLibVersion > 0x646
PHP_METHOD(imagick, exportimagepixels);
#endif
#if MagickLibVersion > 0x648
PHP_METHOD(imagick, getimagechannelkurtosis);
PHP_METHOD(imagick, functionimage);
#endif
#if MagickLibVersion > 0x651
PHP_METHOD(imagick, transformimagecolorspace);
#endif
#if MagickLibVersion > 0x652
PHP_METHOD(imagick, haldclutimage);
#endif
#if MagickLibVersion > 0x655
PHP_METHOD(imagick, autolevelimage);
PHP_METHOD(imagick, blueshiftimage);
#endif
#if MagickLibVersion > 0x656
PHP_METHOD(imagick, setimageartifact);
PHP_METHOD(imagick, getimageartifact);
PHP_METHOD(imagick, deleteimageartifact);
PHP_METHOD(imagick, setcolorspace);
PHP_METHOD(imagick, getcolorspace);
PHP_METHOD(imagick, clampimage);
#endif
#if MagickLibVersion > 0x667
PHP_METHOD(imagick, smushimages);
#endif

PHP_METHOD(imagick, __construct);
PHP_METHOD(imagick, __tostring);
PHP_METHOD(imagick, count);
PHP_METHOD(imagick, getpixeliterator);
PHP_METHOD(imagick, getpixelregioniterator);
PHP_METHOD(imagick, readimage);
PHP_METHOD(imagick, readimages);
PHP_METHOD(imagick, pingimage);
PHP_METHOD(imagick, readimageblob);
PHP_METHOD(imagick, readimagefile);
PHP_METHOD(imagick, displayimage);
PHP_METHOD(imagick, displayimages);
PHP_METHOD(imagick, destroy);
PHP_METHOD(imagick, clear);
PHP_METHOD(imagick, clone);
PHP_METHOD(imagick, removeimage);
PHP_METHOD(imagick, writeimage);
PHP_METHOD(imagick, writeimages);
PHP_METHOD(imagick, resetiterator);
PHP_METHOD(imagick, setfirstiterator);
PHP_METHOD(imagick, setlastiterator);
PHP_METHOD(imagick, previousimage);
PHP_METHOD(imagick, nextimage);
PHP_METHOD(imagick, haspreviousimage);
PHP_METHOD(imagick, hasnextimage);
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
PHP_METHOD(imagick, setimageindex);
PHP_METHOD(imagick, getimageindex);
#endif // #if MagickLibVersion < 0x700
#endif
PHP_METHOD(imagick, setimageformat);
PHP_METHOD(imagick, setimagefilename);
PHP_METHOD(imagick, getimagefilename);
PHP_METHOD(imagick, getimageformat);
PHP_METHOD(imagick, getimagemimetype);
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
PHP_METHOD(imagick, getimagesize);
#endif
#endif
PHP_METHOD(imagick, getimagegeometry);
PHP_METHOD(imagick, getimagecolors);
PHP_METHOD(imagick, scaleimage);
PHP_METHOD(imagick, blurimage);
PHP_METHOD(imagick, thumbnailimage);
PHP_METHOD(imagick, cropthumbnailimage);
PHP_METHOD(imagick, commentimage);
PHP_METHOD(imagick, cropimage);
PHP_METHOD(imagick, labelimage);
PHP_METHOD(imagick, valid);
PHP_METHOD(imagick, current);
PHP_METHOD(imagick, drawimage);
PHP_METHOD(imagick, getimageblob);
PHP_METHOD(imagick, getimagesblob);
PHP_METHOD(imagick, setimagecompressionquality);
PHP_METHOD(imagick, getimagecompressionquality);
PHP_METHOD(imagick, setimagecompression);
PHP_METHOD(imagick, getimagecompression);
PHP_METHOD(imagick, annotateimage);
PHP_METHOD(imagick, compositeimage);
PHP_METHOD(imagick, modulateimage);
PHP_METHOD(imagick, montageimage);
PHP_METHOD(imagick, morphology);
PHP_METHOD(imagick, identifyimage);
PHP_METHOD(imagick, thresholdimage);
PHP_METHOD(imagick, adaptivethresholdimage);
PHP_METHOD(imagick, blackthresholdimage);
PHP_METHOD(imagick, whitethresholdimage);
PHP_METHOD(imagick, appendimages);
PHP_METHOD(imagick, charcoalimage);
PHP_METHOD(imagick, normalizeimage);
PHP_METHOD(imagick, oilpaintimage);
PHP_METHOD(imagick, posterizeimage);
#if MagickLibVersion < 0x700
PHP_METHOD(imagick, radialblurimage);
#endif
PHP_METHOD(imagick, raiseimage);
PHP_METHOD(imagick, resampleimage);
PHP_METHOD(imagick, resizeimage);
PHP_METHOD(imagick, rollimage);
PHP_METHOD(imagick, rotateimage);
PHP_METHOD(imagick, sampleimage);
PHP_METHOD(imagick, solarizeimage);
PHP_METHOD(imagick, shadowimage);
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
PHP_METHOD(imagick, setimageattribute);
#endif // #if MagickLibVersion < 0x700
#endif
PHP_METHOD(imagick, setimagebackgroundcolor);
#if MagickLibVersion >= 0x700
PHP_METHOD(imagick, setimagechannelmask);
#endif
PHP_METHOD(imagick, setimagecompose);
PHP_METHOD(imagick, setimagecompression);
PHP_METHOD(imagick, setimagedelay);
PHP_METHOD(imagick, setimagedepth);
PHP_METHOD(imagick, setimagegamma);
PHP_METHOD(imagick, setimageiterations);
#if MagickLibVersion < 0x700
PHP_METHOD(imagick, setimagemattecolor);
#endif // #if MagickLibVersion < 0x700
PHP_METHOD(imagick, setimagepage);
PHP_METHOD(imagick, setimageprogressmonitor);
#if MagickLibVersion > 0x653
PHP_METHOD(imagick, setprogressmonitor);
#endif
PHP_METHOD(imagick, setimageresolution);
PHP_METHOD(imagick, setimagescene);
PHP_METHOD(imagick, setimagetickspersecond);
PHP_METHOD(imagick, setimagetype);
PHP_METHOD(imagick, setimageunits);
PHP_METHOD(imagick, sharpenimage);
PHP_METHOD(imagick, shaveimage);
PHP_METHOD(imagick, shearimage);
PHP_METHOD(imagick, spliceimage);
PHP_METHOD(imagick, spreadimage);
PHP_METHOD(imagick, swirlimage);
PHP_METHOD(imagick, stripimage);
PHP_METHOD(imagick, queryformats);
PHP_METHOD(imagick, queryfonts);
PHP_METHOD(imagick, queryfontmetrics);
PHP_METHOD(imagick, steganoimage);
PHP_METHOD(imagick, motionblurimage);
#if MagickLibVersion < 0x700
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
PHP_METHOD(imagick, mosaicimages);
#endif
#endif
PHP_METHOD(imagick, morphimages);
PHP_METHOD(imagick, minifyimage);
PHP_METHOD(imagick, addnoiseimage);
PHP_METHOD(imagick, affinetransformimage);
#if MagickLibVersion < 0x700
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
PHP_METHOD(imagick, averageimages);
#endif
#endif
PHP_METHOD(imagick, borderimage);
PHP_METHOD(imagick, calculatecrop);
PHP_METHOD(imagick, chopimage);
PHP_METHOD(imagick, clipimage);
PHP_METHOD(imagick, clippathimage);
PHP_METHOD(imagick, coalesceimages);
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
PHP_METHOD(imagick, colorfloodfillimage);
#endif //#if MagickLibVersion < 0x700
#endif
PHP_METHOD(imagick, colorizeimage);
PHP_METHOD(imagick, compareimagechannels);
PHP_METHOD(imagick, compareimages);
PHP_METHOD(imagick, contrastimage);
PHP_METHOD(imagick, combineimages);
PHP_METHOD(imagick, convolveimage);
PHP_METHOD(imagick, cyclecolormapimage);
PHP_METHOD(imagick, deconstructimages);
PHP_METHOD(imagick, despeckleimage);
PHP_METHOD(imagick, edgeimage);
PHP_METHOD(imagick, embossimage);
PHP_METHOD(imagick, enhanceimage);
PHP_METHOD(imagick, equalizeimage);
PHP_METHOD(imagick, evaluateimage);
#if MagickLibVersion >= 0x687
PHP_METHOD(imagick, evaluateimages);
#endif
#if MagickLibVersion < 0x700
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
PHP_METHOD(imagick, flattenimages);
#endif
#endif
PHP_METHOD(imagick, flipimage);
PHP_METHOD(imagick, flopimage);
#if MagickLibVersion >= 0x655
PHP_METHOD(imagick, forwardfouriertransformimage);
#endif
PHP_METHOD(imagick, frameimage);
PHP_METHOD(imagick, fximage);
PHP_METHOD(imagick, gammaimage);
PHP_METHOD(imagick, gaussianblurimage);
#if MagickLibVersion < 0x700
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
PHP_METHOD(imagick, getimageattribute);
#endif
#endif
PHP_METHOD(imagick, getimagebackgroundcolor);
PHP_METHOD(imagick, getimageblueprimary);
PHP_METHOD(imagick, getimagebordercolor);
PHP_METHOD(imagick, getimagechanneldepth);
PHP_METHOD(imagick, getimagechanneldistortion);
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
PHP_METHOD(imagick, getimagechannelextrema);
#endif // #if MagickLibVersion < 0x700
#endif
PHP_METHOD(imagick, getimagechannelmean);
PHP_METHOD(imagick, getimagechannelstatistics);
PHP_METHOD(imagick, getimagecolormapcolor);
PHP_METHOD(imagick, getimagecolorspace);
PHP_METHOD(imagick, getimagecompose);
PHP_METHOD(imagick, getimagedelay);
PHP_METHOD(imagick, getimagedepth);
PHP_METHOD(imagick, getimagedistortion);
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
PHP_METHOD(imagick, getimageextrema);
#endif // #if MagickLibVersion < 0x700
#endif
PHP_METHOD(imagick, getimagedispose);
PHP_METHOD(imagick, getimagegamma);
PHP_METHOD(imagick, getimagegreenprimary);
PHP_METHOD(imagick, getimageheight);
PHP_METHOD(imagick, getimagehistogram);
PHP_METHOD(imagick, getimageinterlacescheme);
PHP_METHOD(imagick, getimageiterations);
#if MagickLibVersion < 0x700
PHP_METHOD(imagick, getimagemattecolor);
#endif //#if MagickLibVersion < 0x700 
PHP_METHOD(imagick, getimagepage);
PHP_METHOD(imagick, getimagepixelcolor);
PHP_METHOD(imagick, setImagePixelColor);
PHP_METHOD(imagick, getimageprofile);
PHP_METHOD(imagick, getimageredprimary);
PHP_METHOD(imagick, getimagerenderingintent);
PHP_METHOD(imagick, getimageresolution);
PHP_METHOD(imagick, getimagescene);
PHP_METHOD(imagick, getimagesignature);
PHP_METHOD(imagick, getimagetickspersecond);
PHP_METHOD(imagick, getimagetype);
PHP_METHOD(imagick, getimageunits);
PHP_METHOD(imagick, getimagevirtualpixelmethod);
PHP_METHOD(imagick, getimagewhitepoint);
PHP_METHOD(imagick, getimagewidth);
PHP_METHOD(imagick, getnumberimages);
PHP_METHOD(imagick, getimagetotalinkdensity);
PHP_METHOD(imagick, getimageregion);
PHP_METHOD(imagick, implodeimage);
#if MagickLibVersion >= 0x658
PHP_METHOD(imagick, inversefouriertransformimage);
#endif
PHP_METHOD(imagick, levelimage);
PHP_METHOD(imagick, magnifyimage);
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
PHP_METHOD(imagick, mapimage);
PHP_METHOD(imagick, mattefloodfillimage);
#endif // #if MagickLibVersion < 0x700
#endif
#if MagickLibVersion < 0x700
PHP_METHOD(imagick, medianfilterimage);
#endif
PHP_METHOD(imagick, negateimage);
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
PHP_METHOD(imagick, paintopaqueimage);
PHP_METHOD(imagick, painttransparentimage);
#endif //#if MagickLibVersion < 0x700
#endif
PHP_METHOD(imagick, previewimages);
PHP_METHOD(imagick, profileimage);
PHP_METHOD(imagick, quantizeimage);
PHP_METHOD(imagick, quantizeimages);
#if MagickLibVersion < 0x700
PHP_METHOD(imagick, reducenoiseimage);
#endif
PHP_METHOD(imagick, removeimageprofile);
PHP_METHOD(imagick, separateimagechannel);
PHP_METHOD(imagick, sepiatoneimage);

#if MagickLibVersion < 0x700
PHP_METHOD(imagick, setimagebias);
PHP_METHOD(imagick, setimagebiasquantum);
#endif

PHP_METHOD(imagick, setimageblueprimary);
PHP_METHOD(imagick, setimagebordercolor);
PHP_METHOD(imagick, setimagechanneldepth);
PHP_METHOD(imagick, setimagecolormapcolor);
PHP_METHOD(imagick, setimagecolorspace);
PHP_METHOD(imagick, setimagedispose);
PHP_METHOD(imagick, setimageextent);
PHP_METHOD(imagick, setimagegreenprimary);
PHP_METHOD(imagick, setimageinterlacescheme);
PHP_METHOD(imagick, setimageprofile);
PHP_METHOD(imagick, setimageredprimary);
PHP_METHOD(imagick, setimagerenderingintent);
PHP_METHOD(imagick, setimagevirtualpixelmethod);
PHP_METHOD(imagick, setimagewhitepoint);
PHP_METHOD(imagick, sigmoidalcontrastimage);
PHP_METHOD(imagick, stereoimage);
PHP_METHOD(imagick, textureimage);
PHP_METHOD(imagick, tintimage);
PHP_METHOD(imagick, unsharpmaskimage);
PHP_METHOD(imagick, getimage);
PHP_METHOD(imagick, setimage);
PHP_METHOD(imagick, addimage);
PHP_METHOD(imagick, newimage);
PHP_METHOD(imagick, newpseudoimage);
PHP_METHOD(imagick, getcompression);
PHP_METHOD(imagick, getcompressionquality);
PHP_METHOD(imagick, getcopyright);
PHP_METHOD(imagick, getconfigureoptions);
#if MagickLibVersion > 0x660
PHP_METHOD(imagick, getfeatures);
#endif
PHP_METHOD(imagick, getfilename);
PHP_METHOD(imagick, getformat);
PHP_METHOD(imagick, gethomeurl);
PHP_METHOD(imagick, getinterlacescheme);
PHP_METHOD(imagick, getoption);
PHP_METHOD(imagick, getpackagename);
PHP_METHOD(imagick, getpage);
PHP_METHOD(imagick, gethdrienabled);
PHP_METHOD(imagick, getquantum);
PHP_METHOD(imagick, getquantumdepth);
PHP_METHOD(imagick, getquantumrange);
PHP_METHOD(imagick, getreleasedate);
PHP_METHOD(imagick, getresource);
PHP_METHOD(imagick, getresourcelimit);
PHP_METHOD(imagick, getsamplingfactors);
PHP_METHOD(imagick, getsize);
PHP_METHOD(imagick, getversion);
PHP_METHOD(imagick, setbackgroundcolor);
PHP_METHOD(imagick, setcompression);
PHP_METHOD(imagick, setcompressionquality);
PHP_METHOD(imagick, setfilename);
PHP_METHOD(imagick, setformat);
PHP_METHOD(imagick, setinterlacescheme);
PHP_METHOD(imagick, setoption);
PHP_METHOD(imagick, setpage);
PHP_METHOD(imagick, setresourcelimit);
PHP_METHOD(imagick, setresolution);
PHP_METHOD(imagick, setsamplingfactors);
PHP_METHOD(imagick, setsize);
PHP_METHOD(imagick, settype);
PHP_METHOD(imagick, brightnesscontrastimage);
#if MagickLibVersion > 0x661
PHP_METHOD(imagick, colormatriximage);
#endif
PHP_METHOD(imagick, selectiveblurimage);
#if MagickLibVersion >= 0x689
PHP_METHOD(imagick, rotationalblurimage);
#endif
#if MagickLibVersion >= 0x687
PHP_METHOD(imagick, optimizeimagetransparency);
#endif
#if MagickLibVersion >= 0x683
PHP_METHOD(imagick, statisticimage);
#endif
#if MagickLibVersion >= 0x652
PHP_METHOD(imagick, subimagematch);
#endif

PHP_METHOD(imagick, setregistry);
PHP_METHOD(imagick, getregistry);
PHP_METHOD(imagick, listregistry);
PHP_METHOD(imagick, morphology);
#if MagickLibVersion < 0x700
PHP_METHOD(imagick, filter);
#endif // #if MagickLibVersion < 0x700
PHP_METHOD(imagick, setantialias);
PHP_METHOD(imagick, getantialias);
#if MagickLibVersion > 0x676
PHP_METHOD(imagick, colordecisionlistimage);
#endif

#if MagickLibVersion >= 0x660
PHP_METHOD(imagick, autogammaimage);
#endif //#if MagickLibVersion >= 0x660
#if MagickLibVersion >= 0x692
PHP_METHOD(imagick, autoorient);
PHP_METHOD(imagick, compositeimagegravity);
#endif // #if MagickLibVersion >= 0x692
#if MagickLibVersion >= 0x692
PHP_METHOD(imagick, localcontrastimage);
#endif // #if MagickLibVersion >= 0x692
#if MagickLibVersion >= 0x700
PHP_METHOD(imagick, identifyimagetype);
#endif // #if MagickLibVersion >= 0x700

/* Forward declarations (ImagickDraw) */
#if MagickLibVersion > 0x628
PHP_METHOD(imagickdraw, resetvectorgraphics);
#endif
#if MagickLibVersion > 0x649
PHP_METHOD(imagickdraw, gettextkerning);
PHP_METHOD(imagickdraw, settextkerning);
PHP_METHOD(imagickdraw, gettextinterwordspacing);
PHP_METHOD(imagickdraw, settextinterwordspacing);
#endif
#if MagickLibVersion > 0x655
PHP_METHOD(imagickdraw, gettextinterlinespacing);
PHP_METHOD(imagickdraw, settextinterlinespacing);
#endif
PHP_METHOD(imagickdraw, __construct);
PHP_METHOD(imagickdraw, setfillcolor);
PHP_METHOD(imagickdraw, setfillalpha);
PHP_METHOD(imagickdraw, setresolution);
PHP_METHOD(imagickdraw, setstrokecolor);
PHP_METHOD(imagickdraw, setstrokealpha);
PHP_METHOD(imagickdraw, setstrokewidth);
PHP_METHOD(imagickdraw, setfont);
PHP_METHOD(imagickdraw, setfontfamily);
PHP_METHOD(imagickdraw, setfontsize);
PHP_METHOD(imagickdraw, setfontstyle);
PHP_METHOD(imagickdraw, setfontweight);
PHP_METHOD(imagickdraw, getfont);
PHP_METHOD(imagickdraw, getfontfamily);
PHP_METHOD(imagickdraw, getfontsize);
PHP_METHOD(imagickdraw, getfontstyle);
PHP_METHOD(imagickdraw, getfontweight);
PHP_METHOD(imagickdraw, clear);
PHP_METHOD(imagickdraw, destroy);
PHP_METHOD(imagickdraw, annotation);
PHP_METHOD(imagickdraw, settextantialias);
PHP_METHOD(imagickdraw, settextencoding);
PHP_METHOD(imagickdraw, rectangle);
PHP_METHOD(imagickdraw, roundrectangle);
PHP_METHOD(imagickdraw, ellipse);
PHP_METHOD(imagickdraw, circle);
PHP_METHOD(imagickdraw, skewx);
PHP_METHOD(imagickdraw, skewy);
PHP_METHOD(imagickdraw, translate);
PHP_METHOD(imagickdraw, line);
PHP_METHOD(imagickdraw, polygon);
PHP_METHOD(imagickdraw, arc);

#if MagickLibVersion >= 0x700
PHP_METHOD(imagickdraw, alpha);
#else
PHP_METHOD(imagickdraw, matte);
#endif

PHP_METHOD(imagickdraw, point);
PHP_METHOD(imagickdraw, getfontstretch);
PHP_METHOD(imagickdraw, setfontstretch);
PHP_METHOD(imagickdraw, settextalignment);
PHP_METHOD(imagickdraw, settextdecoration);
PHP_METHOD(imagickdraw, settextundercolor);
PHP_METHOD(imagickdraw, setviewbox);
PHP_METHOD(imagickdraw, gettextdecoration);
PHP_METHOD(imagickdraw, gettextencoding);
PHP_METHOD(imagickdraw, clone);
PHP_METHOD(imagickdraw, affine);
PHP_METHOD(imagickdraw, bezier);
PHP_METHOD(imagickdraw, composite);
PHP_METHOD(imagickdraw, color);
PHP_METHOD(imagickdraw, comment);
PHP_METHOD(imagickdraw, getclippath);
PHP_METHOD(imagickdraw, getcliprule);
PHP_METHOD(imagickdraw, getclipunits);
PHP_METHOD(imagickdraw, getfillcolor);
PHP_METHOD(imagickdraw, getfillopacity);
PHP_METHOD(imagickdraw, getfillrule);
PHP_METHOD(imagickdraw, getgravity);
PHP_METHOD(imagickdraw, getstrokeantialias);
PHP_METHOD(imagickdraw, getstrokecolor);
PHP_METHOD(imagickdraw, getstrokedasharray);
PHP_METHOD(imagickdraw, getstrokedashoffset);
PHP_METHOD(imagickdraw, getstrokelinecap);
PHP_METHOD(imagickdraw, getstrokelinejoin);
PHP_METHOD(imagickdraw, getstrokemiterlimit);
PHP_METHOD(imagickdraw, getstrokeopacity);
PHP_METHOD(imagickdraw, getstrokewidth);
PHP_METHOD(imagickdraw, gettextalignment);
PHP_METHOD(imagickdraw, gettextantialias);
PHP_METHOD(imagickdraw, getvectorgraphics);
PHP_METHOD(imagickdraw, gettextundercolor);
PHP_METHOD(imagickdraw, pathclose);
PHP_METHOD(imagickdraw, pathcurvetoabsolute);
PHP_METHOD(imagickdraw, pathcurvetorelative);
PHP_METHOD(imagickdraw, pathcurvetoquadraticbezierabsolute);
PHP_METHOD(imagickdraw, pathcurvetoquadraticbezierrelative);
PHP_METHOD(imagickdraw, pathcurvetoquadraticbeziersmoothabsolute);
PHP_METHOD(imagickdraw, pathcurvetoquadraticbeziersmoothrelative);
PHP_METHOD(imagickdraw, pathcurvetosmoothabsolute);
PHP_METHOD(imagickdraw, pathcurvetosmoothrelative);
PHP_METHOD(imagickdraw, pathellipticarcabsolute);
PHP_METHOD(imagickdraw, pathellipticarcrelative);
PHP_METHOD(imagickdraw, pathfinish);
PHP_METHOD(imagickdraw, pathlinetoabsolute);
PHP_METHOD(imagickdraw, pathlinetorelative);
PHP_METHOD(imagickdraw, pathlinetohorizontalabsolute);
PHP_METHOD(imagickdraw, pathlinetohorizontalrelative);
PHP_METHOD(imagickdraw, pathlinetoverticalabsolute);
PHP_METHOD(imagickdraw, pathlinetoverticalrelative);
PHP_METHOD(imagickdraw, pathmovetoabsolute);
PHP_METHOD(imagickdraw, pathmovetorelative);
PHP_METHOD(imagickdraw, pathstart);
PHP_METHOD(imagickdraw, polyline);
PHP_METHOD(imagickdraw, popclippath);
PHP_METHOD(imagickdraw, popdefs);
PHP_METHOD(imagickdraw, poppattern);
PHP_METHOD(imagickdraw, pushclippath);
PHP_METHOD(imagickdraw, pushdefs);
PHP_METHOD(imagickdraw, pushpattern);
PHP_METHOD(imagickdraw, render);
PHP_METHOD(imagickdraw, rotate);
PHP_METHOD(imagickdraw, scale);
PHP_METHOD(imagickdraw, setclippath);
PHP_METHOD(imagickdraw, setcliprule);
PHP_METHOD(imagickdraw, setclipunits);
PHP_METHOD(imagickdraw, setfillopacity);
PHP_METHOD(imagickdraw, setfillpatternurl);
PHP_METHOD(imagickdraw, setfillrule);
PHP_METHOD(imagickdraw, setgravity);
PHP_METHOD(imagickdraw, setstrokepatternurl);
PHP_METHOD(imagickdraw, setstrokeantialias);
PHP_METHOD(imagickdraw, setstrokedasharray);
PHP_METHOD(imagickdraw, setstrokedashoffset);
PHP_METHOD(imagickdraw, setstrokelinecap);
PHP_METHOD(imagickdraw, setstrokelinejoin);
PHP_METHOD(imagickdraw, setstrokemiterlimit);
PHP_METHOD(imagickdraw, setstrokeopacity);
PHP_METHOD(imagickdraw, setvectorgraphics);
PHP_METHOD(imagickdraw, pop);
PHP_METHOD(imagickdraw, push);
#if MagickLibVersion >= 0x693
PHP_METHOD(imagickdraw, getopacity);
PHP_METHOD(imagickdraw, setopacity);
#endif //MagickLibVersion >= 0x693

#if MagickLibVersion >= 0x675
PHP_METHOD(imagickdraw, getfontresolution);
PHP_METHOD(imagickdraw, setfontresolution);
PHP_METHOD(imagickdraw, getbordercolor);
PHP_METHOD(imagickdraw, setbordercolor);
#endif //#if MagickLibVersion >= 0x675

#if MagickLibVersion >= 0x693
PHP_METHOD(imagickdraw, setdensity);
PHP_METHOD(imagickdraw, getdensity);
#endif// #if MagickLibVersion >= 0x693

#if MagickLibVersion >= 0x692
PHP_METHOD(imagickdraw, gettextdirection);
PHP_METHOD(imagickdraw, settextdirection);
#endif //#if MagickLibVersion >= 0x692

/* Imagick Pixel iterator */
PHP_METHOD(imagickpixeliterator, __construct);
PHP_METHOD(imagickpixeliterator, newpixeliterator);
PHP_METHOD(imagickpixeliterator, newpixelregioniterator);
PHP_METHOD(imagickpixeliterator, getpixeliterator);
PHP_METHOD(imagickpixeliterator, getpixelregioniterator);
PHP_METHOD(imagickpixeliterator, getiteratorrow);
PHP_METHOD(imagickpixeliterator, setiteratorrow);
PHP_METHOD(imagickpixeliterator, getpreviousiteratorrow);
PHP_METHOD(imagickpixeliterator, getcurrentiteratorrow);
PHP_METHOD(imagickpixeliterator, getnextiteratorrow);
PHP_METHOD(imagickpixeliterator, setiteratorfirstrow);
PHP_METHOD(imagickpixeliterator, setiteratorlastrow);
PHP_METHOD(imagickpixeliterator, resetiterator);
PHP_METHOD(imagickpixeliterator, synciterator);
PHP_METHOD(imagickpixeliterator, destroy);
PHP_METHOD(imagickpixeliterator, clear);
PHP_METHOD(imagickpixeliterator, valid);

/* ImagickPixel */
#if MagickLibVersion > 0x628
PHP_METHOD(imagickpixel, gethsl);
PHP_METHOD(imagickpixel, sethsl);
PHP_METHOD(imagickpixel, getcolorvaluequantum);
PHP_METHOD(imagickpixel, setcolorvaluequantum);
PHP_METHOD(imagickpixel, getindex);
PHP_METHOD(imagickpixel, setindex);
#endif
PHP_METHOD(imagickpixel, __construct);
PHP_METHOD(imagickpixel, setcolor);
PHP_METHOD(imagickpixel, clear);
PHP_METHOD(imagickpixel, destroy);
PHP_METHOD(imagickpixel, ispixelsimilarquantum);
PHP_METHOD(imagickpixel, ispixelsimilar);
PHP_METHOD(imagickpixel, getcolorvalue);
PHP_METHOD(imagickpixel, setcolorvalue);
PHP_METHOD(imagickpixel, getcolor);
PHP_METHOD(imagickpixel, getcolorquantum);
PHP_METHOD(imagickpixel, getcolorasstring);
PHP_METHOD(imagickpixel, getcolorcount);
PHP_METHOD(imagickpixel, setcolorcount);
PHP_METHOD(imagickpixel, clone);
#if MagickLibVersion >= 0x693
PHP_METHOD(imagickpixel, setcolorfrompixel);
#endif //#if MagickLibVersion >= 0x693

#ifdef IMAGICK_WITH_KERNEL
PHP_METHOD(imagickkernel, __construct);
PHP_METHOD(imagickkernel, frommatrix);
PHP_METHOD(imagickkernel, frombuiltin);
PHP_METHOD(imagickkernel, addkernel);
PHP_METHOD(imagickkernel, getmatrix);
PHP_METHOD(imagickkernel, separate);
PHP_METHOD(imagickkernel, scale);
PHP_METHOD(imagickkernel, addunitykernel);
#endif

#if MagickLibVersion < 0x700
#define KernelValueType double
#else
#define KernelValueType MagickRealType
#endif

#if MagickLibVersion >= 0x700
// Why is this set to UndefinedChannel, surely it should be AllChannels or DefaultChannels?
#define IM_DEFAULT_CHANNEL UndefinedChannel
#else
#define IM_DEFAULT_CHANNEL DefaultChannels
#endif

#endif /* PHP_IMAGICK_DEFS_H */
