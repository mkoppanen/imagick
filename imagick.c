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
#include "php_imagick_shared.h"

#ifdef ZEND_ENGINE_3
#include "ext/standard/php_smart_string.h"
#else
#include "ext/standard/php_smart_str.h"
#endif

/* For the countable interface */
#if defined(HAVE_SPL)
#include "ext/spl/spl_iterators.h"
#endif

#include "shim_php7_to_php8.h"

ZEND_DECLARE_MODULE_GLOBALS(imagick)

#ifdef IMAGICK_WITH_KERNEL
	#if PHP_VERSION_ID >= 80000
	HashTable* php_imagickkernel_get_debug_info(zend_object *obj, int *is_temp TSRMLS_DC); /* {{{ */
	#else
	HashTable* php_imagickkernel_get_debug_info(zval *obj, int *is_temp TSRMLS_DC); /* {{{ */
	#endif
#endif

#if MAGICKCORE_HDRI_ENABLE
	#define IMAGICK_QUANTUM_TYPE IS_DOUBLE
#else
	#define IMAGICK_QUANTUM_TYPE IS_LONG
#endif

zend_class_entry *php_imagick_sc_entry;
zend_class_entry *php_imagick_exception_class_entry;
zend_class_entry *php_imagickdraw_sc_entry;
zend_class_entry *php_imagickdraw_exception_class_entry;
zend_class_entry *php_imagickpixel_sc_entry;
zend_class_entry *php_imagickpixel_exception_class_entry;
zend_class_entry *php_imagickpixeliterator_sc_entry;
zend_class_entry *php_imagickpixeliterator_exception_class_entry;
#ifdef IMAGICK_WITH_KERNEL
zend_class_entry *php_imagickkernel_sc_entry;
zend_class_entry *php_imagickkernel_exception_class_entry;
#endif

#if defined(ZTS) && defined(PHP_WIN32)
static MUTEX_T imagick_mutex;
static THREAD_T imagick_thread_id;
#endif

/* Handlers */
static zend_object_handlers imagick_object_handlers;
static zend_object_handlers imagickdraw_object_handlers;
static zend_object_handlers imagickpixel_object_handlers;
static zend_object_handlers imagickpixeliterator_object_handlers;
#ifdef IMAGICK_WITH_KERNEL
static zend_object_handlers imagickkernel_object_handlers;
#endif

/* External API */
PHP_IMAGICK_API zend_class_entry *php_imagick_get_class_entry()
{
	return php_imagick_sc_entry;
}



PHP_IMAGICK_API zend_class_entry *php_imagickdraw_get_class_entry()
{
	return php_imagickdraw_sc_entry;
}

PHP_IMAGICK_API zend_class_entry *php_imagickpixel_get_class_entry()
{
	return php_imagickdraw_sc_entry;
}

/* Imagick */
#if MagickLibVersion > 0x628
	ZEND_BEGIN_ARG_INFO_EX(imagick_shadeimage_args, 0, 0, 3)
		ZEND_ARG_INFO(0, gray)
		ZEND_ARG_INFO(0, azimuth)
		ZEND_ARG_INFO(0, elevation)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setimagematte_args, 0, 0, 1)
		ZEND_ARG_INFO(0, enable)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_sketchimage_args, 0, 0, 3)
		ZEND_ARG_INFO(0, radius)
		ZEND_ARG_INFO(0, sigma)
		ZEND_ARG_INFO(0, angle)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_pingimageblob_args, 0, 0, 1)
		ZEND_ARG_INFO(0, imageContents)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_pingimagefile_args, 0, 0, 1)
		ZEND_ARG_INFO(0, fp)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_trimimage_args, 0, 0, 1)
		ZEND_ARG_INFO(0, fuzz)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_waveimage_args, 0, 0, 2)
		ZEND_ARG_INFO(0, amplitude)
		ZEND_ARG_INFO(0, waveLenght)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_vignetteimage_args, 0, 0, 4)
		ZEND_ARG_INFO(0, blackPoint)
		ZEND_ARG_INFO(0, whitePoint)
		ZEND_ARG_INFO(0, x)
		ZEND_ARG_INFO(0, y)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_adaptiveresizeimage_args, 0, 0, 2)
		ZEND_ARG_INFO(0, columns)
		ZEND_ARG_INFO(0, rows)
		ZEND_ARG_INFO(0, bestfit)
		ZEND_ARG_INFO(0, legacy)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_contraststretchimage_args, 0, 0, 2)
		ZEND_ARG_INFO(0, blackPoint)
		ZEND_ARG_INFO(0, whitePoint)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_adaptiveblurimage_args, 0, 0, 2)
		ZEND_ARG_INFO(0, radius)
		ZEND_ARG_INFO(0, sigma)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_adaptivesharpenimage_args, 0, 0, 2)
		ZEND_ARG_INFO(0, radius)
		ZEND_ARG_INFO(0, sigma)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setsizeoffset_args, 0, 0, 3)
		ZEND_ARG_INFO(0, columns)
		ZEND_ARG_INFO(0, rows)
		ZEND_ARG_INFO(0, offset)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_randomthresholdimage_args, 0, 0, 2)
		ZEND_ARG_INFO(0, low)
		ZEND_ARG_INFO(0, high)
		ZEND_ARG_INFO(0, CHANNELTYPE)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_compareimagelayers_args, 0, 0, 1)
		ZEND_ARG_INFO(0, LAYER)
	ZEND_END_ARG_INFO()

#if MagickLibVersion < 0x700
	ZEND_BEGIN_ARG_INFO_EX(imagick_roundcornersimage_args, 0, 0, 2)
		ZEND_ARG_INFO(0, xRounding)
		ZEND_ARG_INFO(0, yRounding)
		ZEND_ARG_INFO(0, strokeWidth)
		ZEND_ARG_INFO(0, displace)
		ZEND_ARG_INFO(0, sizeCorrection)
	ZEND_END_ARG_INFO()
#endif

	ZEND_BEGIN_ARG_INFO_EX(imagick_setiteratorindex_args, 0, 0, 1)
		ZEND_ARG_INFO(0, index)
	ZEND_END_ARG_INFO()

#if MagickLibVersion < 0x700
	ZEND_BEGIN_ARG_INFO_EX(imagick_transformimage_args, 0, 0, 2)
		ZEND_ARG_INFO(0, crop)
		ZEND_ARG_INFO(0, geometry)
	ZEND_END_ARG_INFO()
#endif
#endif

#if MagickLibVersion > 0x631
	ZEND_BEGIN_ARG_INFO_EX(imagick_polaroidimage_args, 0, 0, 2)
		ZEND_ARG_OBJ_INFO(0, ImagickDraw, ImagickDraw, 0)
		ZEND_ARG_INFO(0, angle)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_getimageproperty_args, 0, 0, 1)
		ZEND_ARG_INFO(0, name)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setimageproperty_args, 0, 0, 2)
		ZEND_ARG_INFO(0, name)
		ZEND_ARG_INFO(0, value)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_deleteimageproperty_args, 0, 0, 1)
		ZEND_ARG_INFO(0, name)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_identifyformat_args, 0, 0, 1)
		ZEND_ARG_INFO(0, embedText)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setimageinterpolatemethod_args, 0, 0, 1)
		ZEND_ARG_INFO(0, INTERPOLATE)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_linearstretchimage_args, 0, 0, 2)
		ZEND_ARG_INFO(0, blackPoint)
		ZEND_ARG_INFO(0, whitePoint)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_extentimage_args, 0, 0, 4)
		ZEND_ARG_INFO(0, width)
		ZEND_ARG_INFO(0, height)
		ZEND_ARG_INFO(0, x)
		ZEND_ARG_INFO(0, y)
	ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x633
	ZEND_BEGIN_ARG_INFO_EX(imagick_setimageorientation_args, 0, 0, 1)
		ZEND_ARG_INFO(0, ORIENTATION)
	ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x634 && MagickLibVersion < 0x700
	ZEND_BEGIN_ARG_INFO_EX(imagick_paintfloodfillimage_args, 0, 0, 6)
		ZEND_ARG_INFO(0, CHANNEL)
		ZEND_ARG_INFO(0, fill)
		ZEND_ARG_INFO(0, fuzz)
		ZEND_ARG_INFO(0, bordercolor)
		ZEND_ARG_INFO(0, x)
		ZEND_ARG_INFO(0, y)
	ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x630
#if MagickLibVersion < 0x700
	ZEND_BEGIN_ARG_INFO_EX(imagick_setimageopacity_args, 0, 0, 1)
		ZEND_ARG_INFO(0, opacity)
	ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion < 0x700
	ZEND_BEGIN_ARG_INFO_EX(imagick_orderedposterizeimage_args, 0, 0, 1)
		ZEND_ARG_INFO(0, threshold_map)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()
#endif
#endif

#if MagickLibVersion > 0x700
	ZEND_BEGIN_ARG_INFO_EX(imagick_setimagealpha_args, 0, 0, 1)
		ZEND_ARG_INFO(0, alpha)
	ZEND_END_ARG_INFO()
#endif


#if MagickLibVersion > 0x635
	ZEND_BEGIN_ARG_INFO_EX(imagick_clutimage_args, 0, 0, 1)
		ZEND_ARG_OBJ_INFO(0, Imagick, Imagick, 0)
		ZEND_ARG_INFO(0, CHANNELTYPE)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_getimageproperties_args, 0, 0, 0)
		ZEND_ARG_INFO(0, pattern)
		ZEND_ARG_INFO(0, values)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_getimageprofiles_args, 0, 0, 0)
		ZEND_ARG_INFO(0, pattern)
		ZEND_ARG_INFO(0, values)
	ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x635
	ZEND_BEGIN_ARG_INFO_EX(imagick_distortimage_args, 0, 0, 3)
		ZEND_ARG_INFO(0, method)
		ZEND_ARG_INFO(0, arguments)
		ZEND_ARG_INFO(0, bestfit)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_writeimagefile_args, 0, 0, 1)
		ZEND_ARG_INFO(0, handle)
		ZEND_ARG_INFO(0, format)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_writeimagesfile_args, 0, 0, 1)
		ZEND_ARG_INFO(0, handle)
		ZEND_ARG_INFO(0, format)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_resetimagepage_args, 0, 0, 1)
		ZEND_ARG_INFO(0, page)
	ZEND_END_ARG_INFO()

#if MagickLibVersion < 0x700
	ZEND_BEGIN_ARG_INFO_EX(imagick_setimageclipmask_args, 0, 0, 1)
		ZEND_ARG_OBJ_INFO(0, Imagick, Imagick, 0)
	ZEND_END_ARG_INFO()
#endif

	ZEND_BEGIN_ARG_INFO_EX(imagick_animateimages_args, 0, 0, 1)
		ZEND_ARG_INFO(0, server_name)
	ZEND_END_ARG_INFO()
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
	ZEND_BEGIN_ARG_INFO_EX(imagick_recolorimage_args, 0, 0, 1)
		ZEND_ARG_INFO(0, matrix)
	ZEND_END_ARG_INFO()
#endif
#endif
#endif

#if MagickLibVersion > 0x636
	ZEND_BEGIN_ARG_INFO_EX(imagick_setfont_args, 0, 0, 1)
		ZEND_ARG_INFO(0, font)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setpointsize_args, 0, 0, 1)
		ZEND_ARG_INFO(0, pointsize)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_mergeimagelayers_args, 0, 0, 1)
		ZEND_ARG_INFO(0, LAYERMETHOD)
	ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x637
	ZEND_BEGIN_ARG_INFO_EX(imagick_setimagealphachannel_args, 0, 0, 1)
		ZEND_ARG_INFO(0, ALPHACHANNELTYPE)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_floodfillpaintimage_args, 0, 0, 6)
		ZEND_ARG_INFO(0, fill)
		ZEND_ARG_INFO(0, fuzz)
		ZEND_ARG_INFO(0, bordercolor)
		ZEND_ARG_INFO(0, x)
		ZEND_ARG_INFO(0, y)
		ZEND_ARG_INFO(0, invert)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_opaquepaintimage_args, 0, 0, 4)
		ZEND_ARG_INFO(0, target)
		ZEND_ARG_INFO(0, fill)
		ZEND_ARG_INFO(0, fuzz)
		ZEND_ARG_INFO(0, invert)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_transparentpaintimage_args, 0, 0, 4)
		ZEND_ARG_INFO(0, target)
		ZEND_ARG_INFO(0, alpha)
		ZEND_ARG_INFO(0, fuzz)
		ZEND_ARG_INFO(0, invert)
	ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x638
	ZEND_BEGIN_ARG_INFO_EX(imagick_liquidrescaleimage_args, 0, 0, 4)
		ZEND_ARG_INFO(0, columns)
		ZEND_ARG_INFO(0, rows)
		ZEND_ARG_INFO(0, delta_x)
		ZEND_ARG_INFO(0, rigidity)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_encipherimage_args, 0, 0, 1)
		ZEND_ARG_INFO(0, passphrase)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_decipherimage_args, 0, 0, 1)
		ZEND_ARG_INFO(0, passphrase)
	ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x639
	ZEND_BEGIN_ARG_INFO_EX(imagick_setgravity_args, 0, 0, 1)
		ZEND_ARG_INFO(0, GRAVITY)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_getimagechannelrange_args, 0, 0, 1)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x642
	ZEND_BEGIN_ARG_INFO_EX(imagick_getimagechanneldistortions_args, 0, 0, 1)
		ZEND_ARG_OBJ_INFO(0, Imagick, Imagick, 0)
		ZEND_ARG_INFO(0, METRICTYPE)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x643
	ZEND_BEGIN_ARG_INFO_EX(imagick_setimagegravity_args, 0, 0, 1)
		ZEND_ARG_INFO(0, GRAVITY)
	ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion >= 0x645
	ZEND_BEGIN_ARG_INFO_EX(imagick_importimagepixels_args, 0, 0, 7)
		ZEND_ARG_INFO(0, x)
		ZEND_ARG_INFO(0, y)
		ZEND_ARG_INFO(0, width)
		ZEND_ARG_INFO(0, height)
		ZEND_ARG_INFO(0, map)
		ZEND_ARG_INFO(0, storage)
		ZEND_ARG_INFO(0, PIXEL)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_deskewimage_args, 0, 0, 1)
		ZEND_ARG_INFO(0, threshold)
	ZEND_END_ARG_INFO()

#if PHP_IMAGICK_HAVE_HOUGHLINE
	ZEND_BEGIN_ARG_INFO_EX(imagick_houghlineimage_args, 0, 0, 3)
		ZEND_ARG_INFO(0, width)
		ZEND_ARG_INFO(0, height)
	    ZEND_ARG_INFO(0, threshold)
	ZEND_END_ARG_INFO()
#endif

	ZEND_BEGIN_ARG_INFO_EX(imagick_segmentimage_args, 0, 0, 3)
		ZEND_ARG_INFO(0, COLORSPACE)
		ZEND_ARG_INFO(0, cluster_threshold)
		ZEND_ARG_INFO(0, smooth_threshold)
		ZEND_ARG_INFO(0, verbose)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_sparsecolorimage_args, 0, 0, 2)
		ZEND_ARG_INFO(0, SPARSE_METHOD)
		ZEND_ARG_INFO(0, arguments)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_remapimage_args, 0, 0, 2)
		ZEND_ARG_OBJ_INFO(0, Imagick, Imagick, 0)
		ZEND_ARG_INFO(0, DITHER)
	ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x646
	ZEND_BEGIN_ARG_INFO_EX(imagick_exportimagepixels_args, 0, 0, 6)
		ZEND_ARG_INFO(0, x)
		ZEND_ARG_INFO(0, y)
		ZEND_ARG_INFO(0, width)
		ZEND_ARG_INFO(0, height)
		ZEND_ARG_INFO(0, map)
		ZEND_ARG_INFO(0, STORAGE)
	ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x648
	ZEND_BEGIN_ARG_INFO_EX(imagick_getimagechannelkurtosis_args, 0, 0, 0)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_functionimage_args, 0, 0, 2)
		ZEND_ARG_INFO(0, FUNCTION)
		ZEND_ARG_INFO(0, arguments)
	ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x652
	ZEND_BEGIN_ARG_INFO_EX(imagick_haldclutimage_args, 0, 0, 1)
		ZEND_ARG_OBJ_INFO(0, Imagick, Imagick, 0)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()
	
	ZEND_BEGIN_ARG_INFO_EX(imagick_transformimagecolorspace_args, 0, 0, 1)
		ZEND_ARG_INFO(0, COLORSPACE)
	ZEND_END_ARG_INFO()	
#endif

#if MagickLibVersion > 0x655
	ZEND_BEGIN_ARG_INFO_EX(imagick_autolevelimage_args, 0, 0, 0)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_blueshiftimage_args, 0, 0, 0)
		ZEND_ARG_INFO(0, factor)
	ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x656
	ZEND_BEGIN_ARG_INFO_EX(imagick_setimageartifact_args, 0, 0, 2)
		ZEND_ARG_INFO(0, artifact)
		ZEND_ARG_INFO(0, value)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_getimageartifact_args, 0, 0, 1)
		ZEND_ARG_INFO(0, artifact)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_deleteimageartifact_args, 0, 0, 1)
		ZEND_ARG_INFO(0, artifact)
	ZEND_END_ARG_INFO()
	
	ZEND_BEGIN_ARG_INFO_EX(imagick_setcolorspace_args, 0, 0, 1)
		ZEND_ARG_INFO(0, COLORSPACE)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_clampimage_args, 0, 0, 0)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()
#endif
#if MagickLibVersion > 0x667
	ZEND_BEGIN_ARG_INFO_EX(imagick_smushimages_args, 0, 0, 2)
		ZEND_ARG_INFO(0, stack)
		ZEND_ARG_INFO(0, offset)
	ZEND_END_ARG_INFO()
#endif

	ZEND_BEGIN_ARG_INFO_EX(imagick_zero_args, 0, 0, 0)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_construct_args, 0, 0, 0)
		ZEND_ARG_INFO(0, files)
	ZEND_END_ARG_INFO()
	
	ZEND_BEGIN_ARG_INFO_EX(imagick_getpixelregioniterator_args, 0, 0, 5)
		ZEND_ARG_INFO(0, x)
		ZEND_ARG_INFO(0, y)
		ZEND_ARG_INFO(0, columns)
		ZEND_ARG_INFO(0, rows)
		ZEND_ARG_INFO(0, modify)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_readimage_args, 0, 0, 1)
		ZEND_ARG_INFO(0, filename)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_readimages_args, 0, 0, 1)
		ZEND_ARG_INFO(0, filenames)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_readimageblob_args, 0, 0, 1)
		ZEND_ARG_INFO(0, imageContents)
		ZEND_ARG_INFO(0, filename)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setimageformat_args, 0, 0, 1)
		ZEND_ARG_INFO(0, imageFormat)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_scaleimage_args, 0, 0, 2)
		ZEND_ARG_INFO(0, width)
		ZEND_ARG_INFO(0, height)
		ZEND_ARG_INFO(0, bestfit)
		ZEND_ARG_INFO(0, legacy)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_writeimage_args, 0, 0, 0)
		ZEND_ARG_INFO(0, filename)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_writeimages_args, 0, 0, 2)
		ZEND_ARG_INFO(0, filename)
		ZEND_ARG_INFO(0, adjoin)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_blurimage_args, 0, 0, 2)
		ZEND_ARG_INFO(0, radius)
		ZEND_ARG_INFO(0, sigma)
		ZEND_ARG_INFO(0, CHANNELTYPE)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_thumbnailimage_args, 0, 0, 2)
		ZEND_ARG_INFO(0, width)
		ZEND_ARG_INFO(0, height)
		ZEND_ARG_INFO(0, bestfit)
		ZEND_ARG_INFO(0, fill)
		ZEND_ARG_INFO(0, legacy)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_cropthumbnailimage_args, 0, 0, 2)
		ZEND_ARG_INFO(0, width)
		ZEND_ARG_INFO(0, height)
		ZEND_ARG_INFO(0, legacy)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setimagefilename_args, 0, 0, 1)
		ZEND_ARG_INFO(0, filename)
	ZEND_END_ARG_INFO()

#if MagickLibVersion < 0x700
	ZEND_BEGIN_ARG_INFO_EX(imagick_setimageindex_args, 0, 0, 1)
		ZEND_ARG_INFO(0, index)
	ZEND_END_ARG_INFO()
#endif

	ZEND_BEGIN_ARG_INFO_EX(imagick_commentimage_args, 0, 0, 1)
		ZEND_ARG_INFO(0, comment)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_cropimage_args, 0, 0, 4)
		ZEND_ARG_INFO(0, width)
		ZEND_ARG_INFO(0, height)
		ZEND_ARG_INFO(0, x)
		ZEND_ARG_INFO(0, y)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_labelimage_args, 0, 0, 1)
		ZEND_ARG_INFO(0, label)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_drawimage_args, 0, 0, 1)
		ZEND_ARG_OBJ_INFO(0, ImagickDraw, ImagickDraw, 0)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setimagecompressionquality_args, 0, 0, 1)
		ZEND_ARG_INFO(0, quality)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_annotateimage_args, 0, 0, 5)
		ZEND_ARG_OBJ_INFO(0, ImagickDraw, ImagickDraw, 0)
		ZEND_ARG_INFO(0, x)
		ZEND_ARG_INFO(0, y)
		ZEND_ARG_INFO(0, angle)
		ZEND_ARG_INFO(0, text)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_compositeimage_args, 0, 0, 4)
		ZEND_ARG_OBJ_INFO(0, Imagick, Imagick, 0)
		ZEND_ARG_INFO(0, COMPOSITE)
		ZEND_ARG_INFO(0, x)
		ZEND_ARG_INFO(0, y)
		ZEND_ARG_INFO(0, CHANNELTYPE)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_modulateimage_args, 0, 0, 3)
		ZEND_ARG_INFO(0, brightness)
		ZEND_ARG_INFO(0, saturation)
		ZEND_ARG_INFO(0, hue)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_montageimage_args, 0, 0, 5)
		ZEND_ARG_OBJ_INFO(0, ImagickDraw, ImagickDraw, 0)
		ZEND_ARG_INFO(0, tileGeometry)
		ZEND_ARG_INFO(0, thumbnailGeometry)
		ZEND_ARG_INFO(0, MONTAGEMODE)
		ZEND_ARG_INFO(0, frame)
	ZEND_END_ARG_INFO()

#ifdef IMAGICK_WITH_KERNEL
	ZEND_BEGIN_ARG_INFO_EX(imagick_morphology_args, 0, 0, 3)
		ZEND_ARG_INFO(0, morphologyMethod)
		ZEND_ARG_INFO(0, iterations)
		ZEND_ARG_OBJ_INFO(0, ImagickKernel, ImagickKernel, 0)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()

#if MagickLibVersion < 0x700
	ZEND_BEGIN_ARG_INFO_EX(imagick_filter_args, 0, 0, 1)
		ZEND_ARG_OBJ_INFO(0, ImagickKernel, ImagickKernel, 0)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()
#endif
#endif

	ZEND_BEGIN_ARG_INFO_EX(imagick_identifyimage_args, 0, 0, 0)
		ZEND_ARG_INFO(0, appendRawOutput)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_thresholdimage_args, 0, 0, 1)
		ZEND_ARG_INFO(0, threshold)
		ZEND_ARG_INFO(0, CHANNELTYPE)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_adaptivethresholdimage_args, 0, 0, 3)
		ZEND_ARG_INFO(0, width)
		ZEND_ARG_INFO(0, height)
		ZEND_ARG_INFO(0, offset)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_blackthresholdimage_args, 0, 0, 1)
		ZEND_ARG_INFO(0, color)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_whitethresholdimage_args, 0, 0, 1)
		ZEND_ARG_INFO(0, color)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_appendimages_args, 0, 0, 1)
		ZEND_ARG_INFO(0, stack)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_charcoalimage_args, 0, 0, 2)
		ZEND_ARG_INFO(0, radius)
		ZEND_ARG_INFO(0, sigma)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_normalizeimage_args, 0, 0, 0)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_oilpaintimage_args, 0, 0, 1)
		ZEND_ARG_INFO(0, radius)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_posterizeimage_args, 0, 0, 2)
		ZEND_ARG_INFO(0, levels)
		ZEND_ARG_INFO(0, dither)
	ZEND_END_ARG_INFO()

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
	ZEND_BEGIN_ARG_INFO_EX(imagick_radialblurimage_args, 0, 0, 1)
		ZEND_ARG_INFO(0, angle)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()
#endif
#endif

	ZEND_BEGIN_ARG_INFO_EX(imagick_raiseimage_args, 0, 0, 5)
		ZEND_ARG_INFO(0, width)
		ZEND_ARG_INFO(0, height)
		ZEND_ARG_INFO(0, x)
		ZEND_ARG_INFO(0, y)
		ZEND_ARG_INFO(0, raise)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_resampleimage_args, 0, 0, 4)
		ZEND_ARG_INFO(0, xResolution)
		ZEND_ARG_INFO(0, yResolution)
		ZEND_ARG_INFO(0, FILTER)
		ZEND_ARG_INFO(0, blur)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_resizeimage_args, 0, 0, 2)
		ZEND_ARG_INFO(0, x)
		ZEND_ARG_INFO(0, y)
		ZEND_ARG_INFO(0, filter)
		ZEND_ARG_INFO(0, blur)
		ZEND_ARG_INFO(0, bestfit)
		ZEND_ARG_INFO(0, legacy)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_rollimage_args, 0, 0, 2)
		ZEND_ARG_INFO(0, x)
		ZEND_ARG_INFO(0, y)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_rotateimage_args, 0, 0, 2)
		ZEND_ARG_INFO(0, color)
		ZEND_ARG_INFO(0, degrees)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_sampleimage_args, 0, 0, 2)
		ZEND_ARG_INFO(0, columns)
		ZEND_ARG_INFO(0, rows)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_solarizeimage_args, 0, 0, 1)
		ZEND_ARG_INFO(0, threshold)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_shadowimage_args, 0, 0, 4)
		ZEND_ARG_INFO(0, opacity)
		ZEND_ARG_INFO(0, sigma)
		ZEND_ARG_INFO(0, x)
		ZEND_ARG_INFO(0, y)
	ZEND_END_ARG_INFO()

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
	ZEND_BEGIN_ARG_INFO_EX(imagick_setimageattribute_args, 0, 0, 2)
		ZEND_ARG_INFO(0, key)
		ZEND_ARG_INFO(0, value)
	ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion < 0x700
	ZEND_BEGIN_ARG_INFO_EX(imagick_getimageattribute_args, 0, 0, 1)
		ZEND_ARG_INFO(0, key)
	ZEND_END_ARG_INFO()
#endif
#endif

	ZEND_BEGIN_ARG_INFO_EX(imagick_setimagebackgroundcolor_args, 0, 0, 1)
		ZEND_ARG_INFO(0, color)
	ZEND_END_ARG_INFO()

#if MagickLibVersion >= 0x700
	ZEND_BEGIN_ARG_INFO_EX(imagick_setimagechannelmask_args, 0, 0, 1)
		ZEND_ARG_INFO(0, channel)
	ZEND_END_ARG_INFO()
#endif

	ZEND_BEGIN_ARG_INFO_EX(imagick_setimagecompose_args, 0, 0, 1)
		ZEND_ARG_INFO(0, COMPOSITE)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setimagecompression_args, 0, 0, 1)
		ZEND_ARG_INFO(0, COMPRESSION)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setimagedelay_args, 0, 0, 1)
		ZEND_ARG_INFO(0, delay)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setimagedepth_args, 0, 0, 1)
		ZEND_ARG_INFO(0, depth)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setimagegamma_args, 0, 0, 1)
		ZEND_ARG_INFO(0, gamma)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setimageiterations_args, 0, 0, 1)
		ZEND_ARG_INFO(0, iterations)
	ZEND_END_ARG_INFO()

#if MagickLibVersion < 0x700
	ZEND_BEGIN_ARG_INFO_EX(imagick_setimagemattecolor_args, 0, 0, 1)
		ZEND_ARG_INFO(0, color)
	ZEND_END_ARG_INFO()
#endif

	ZEND_BEGIN_ARG_INFO_EX(imagick_setimagepage_args, 0, 0, 4)
		ZEND_ARG_INFO(0, width)
		ZEND_ARG_INFO(0, height)
		ZEND_ARG_INFO(0, x)
		ZEND_ARG_INFO(0, y)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setimageprogressmonitor_args, 0, 0, 1)
		ZEND_ARG_INFO(0, filename)
	ZEND_END_ARG_INFO()
	
	ZEND_BEGIN_ARG_INFO_EX(imagick_setprogressmonitor_args, 0, 0, 1)
		ZEND_ARG_INFO(0, callback)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setimageresolution_args, 0, 0, 2)
		ZEND_ARG_INFO(0, xResolution)
		ZEND_ARG_INFO(0, yResolution)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setimagescene_args, 0, 0, 1)
		ZEND_ARG_INFO(0, scene)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setimagetickspersecond_args, 0, 0, 1)
		ZEND_ARG_INFO(0, ticksPerSecond)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setimagetype_args, 0, 0, 1)
		ZEND_ARG_INFO(0, IMGTYPE)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setimageunits_args, 0, 0, 1)
		ZEND_ARG_INFO(0, RESOLUTION)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_sharpenimage_args, 0, 0, 2)
		ZEND_ARG_INFO(0, radius)
		ZEND_ARG_INFO(0, sigma)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_shaveimage_args, 0, 0, 2)
		ZEND_ARG_INFO(0, columns)
		ZEND_ARG_INFO(0, rows)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_shearimage_args, 0, 0, 3)
		ZEND_ARG_INFO(0, color)
		ZEND_ARG_INFO(0, xShear)
		ZEND_ARG_INFO(0, yShear)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_spliceimage_args, 0, 0, 4)
		ZEND_ARG_INFO(0, width)
		ZEND_ARG_INFO(0, height)
		ZEND_ARG_INFO(0, x)
		ZEND_ARG_INFO(0, y)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_pingimage_args, 0, 0, 1)
		ZEND_ARG_INFO(0, filename)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_readimagefile_args, 0, 0, 1)
		ZEND_ARG_INFO(0, fp)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_displayimage_args, 0, 0, 1)
		ZEND_ARG_INFO(0, serverName)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_displayimages_args, 0, 0, 1)
		ZEND_ARG_INFO(0, serverName)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_spreadimage_args, 0, 0, 1)
		ZEND_ARG_INFO(0, radius)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_swirlimage_args, 0, 0, 1)
		ZEND_ARG_INFO(0, degrees)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_queryformats_args, 0, 0, 1)
		ZEND_ARG_INFO(0, pattern)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_queryfonts_args, 0, 0, 1)
		ZEND_ARG_INFO(0, pattern)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_queryfontmetrics_args, 0, 0, 2)
		ZEND_ARG_OBJ_INFO(0, ImagickDraw, ImagickDraw, 0)
		ZEND_ARG_INFO(0, text)
		ZEND_ARG_INFO(0, multiline)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_steganoimage_args, 0, 0, 2)
		ZEND_ARG_OBJ_INFO(0, Imagick, Imagick, 0)
		ZEND_ARG_INFO(0, offset)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_addnoiseimage_args, 0, 0, 1)
		ZEND_ARG_INFO(0, NOISE)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_motionblurimage_args, 0, 0, 3)
		ZEND_ARG_INFO(0, radius)
		ZEND_ARG_INFO(0, sigma)
		ZEND_ARG_INFO(0, angle)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_morphimages_args, 0, 0, 1)
		ZEND_ARG_INFO(0, frames)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_affinetransformimage_args, 0, 0, 1)
		ZEND_ARG_OBJ_INFO(0, ImagickDraw, ImagickDraw, 0)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_calculatecrop_args, 0, 0, 4)
		ZEND_ARG_INFO(0, orig_width)
		ZEND_ARG_INFO(0, orig_height)
		ZEND_ARG_INFO(0, desired_width)
		ZEND_ARG_INFO(0, desired_height)
		ZEND_ARG_INFO(0, legacy)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_borderimage_args, 0, 0, 3)
		ZEND_ARG_INFO(0, color)
		ZEND_ARG_INFO(0, width)
		ZEND_ARG_INFO(0, height)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_chopimage_args, 0, 0, 4)
		ZEND_ARG_INFO(0, width)
		ZEND_ARG_INFO(0, height)
		ZEND_ARG_INFO(0, x)
		ZEND_ARG_INFO(0, y)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_clippathimage_args, 0, 0, 2)
		ZEND_ARG_INFO(0, pathname)
		ZEND_ARG_INFO(0, inside)
	ZEND_END_ARG_INFO()

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
	ZEND_BEGIN_ARG_INFO_EX(imagick_colorfloodfillimage_args, 0, 0, 5)
		ZEND_ARG_INFO(0, fill_color)
		ZEND_ARG_INFO(0, fuzz)
		ZEND_ARG_INFO(0, border_color)
		ZEND_ARG_INFO(0, y)
		ZEND_ARG_INFO(0, x)
	ZEND_END_ARG_INFO()
#endif
#endif

	ZEND_BEGIN_ARG_INFO_EX(imagick_colorizeimage_args, 0, 0, 2)
		ZEND_ARG_INFO(0, colorize_color)
		ZEND_ARG_INFO(0, opacity)
		ZEND_ARG_INFO(0, legacy)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_compareimagechannels_args, 0, 0, 3)
		ZEND_ARG_OBJ_INFO(0, Imagick, Imagick, 0)
		ZEND_ARG_INFO(0, CHANNEL)
		ZEND_ARG_INFO(0, METRIC)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_compareimages_args, 0, 0, 2)
		ZEND_ARG_OBJ_INFO(0, Imagick, Imagick, 0)
		ZEND_ARG_INFO(0, METRIC)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_contrastimage_args, 0, 0, 1)
		ZEND_ARG_INFO(0, sharpen)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_convolveimage_args, 0, 0, 1)
		ZEND_ARG_INFO(0, kernel)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_cyclecolormapimage_args, 0, 0, 1)
		ZEND_ARG_INFO(0, displace)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_edgeimage_args, 0, 0, 1)
		ZEND_ARG_INFO(0, radius)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_embossimage_args, 0, 0, 2)
		ZEND_ARG_INFO(0, radius)
		ZEND_ARG_INFO(0, sigma)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_evaluateimage_args, 0, 0, 2)
		ZEND_ARG_INFO(0, EVALUATE)
		ZEND_ARG_INFO(0, constant)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()

#if MagickLibVersion >= 0x687
	ZEND_BEGIN_ARG_INFO_EX(imagick_evaluateimages_args, 0, 0, 1)
		ZEND_ARG_INFO(0, EVALUATE)
	ZEND_END_ARG_INFO()
#endif //MagickLibVersion >= 0x687

#if MagickLibVersion >= 0x655
	ZEND_BEGIN_ARG_INFO_EX(imagick_forwardfouriertransformimage_args, 0, 0, 5)
		ZEND_ARG_INFO(0, magnitude)
	ZEND_END_ARG_INFO()
#endif

	ZEND_BEGIN_ARG_INFO_EX(imagick_frameimage_args, 0, 0, 5)
		ZEND_ARG_INFO(0, color)
		ZEND_ARG_INFO(0, width)
		ZEND_ARG_INFO(0, height)
		ZEND_ARG_INFO(0, innerBevel)
		ZEND_ARG_INFO(0, outerBevel)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_fximage_args, 0, 0, 1)
		ZEND_ARG_INFO(0, expression)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_gammaimage_args, 0, 0, 1)
		ZEND_ARG_INFO(0, gamma)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_gaussianblurimage_args, 0, 0, 2)
		ZEND_ARG_INFO(0, radius)
		ZEND_ARG_INFO(0, sigma)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_getimagechanneldepth_args, 0, 0, 1)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_getimagechanneldistortion_args, 0, 0, 3)
		ZEND_ARG_OBJ_INFO(0, Imagick, Imagick, 0)
		ZEND_ARG_INFO(0, CHANNEL)
		ZEND_ARG_INFO(0, METRIC)
	ZEND_END_ARG_INFO()

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
	ZEND_BEGIN_ARG_INFO_EX(imagick_getimagechannelextrema_args, 0, 0, 1)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()
#endif
#endif

	ZEND_BEGIN_ARG_INFO_EX(imagick_getimagechannelmean_args, 0, 0, 1)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_getimagecolormapcolor_args, 0, 0, 1)
		ZEND_ARG_INFO(0, index)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_getimagedistortion_args, 0, 0, 2)
		ZEND_ARG_OBJ_INFO(0, Imagick, Imagick, 0)
		ZEND_ARG_INFO(0, METRIC)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_getimagepixelcolor_args, 0, 0, 2)
		ZEND_ARG_INFO(0, x)
		ZEND_ARG_INFO(0, y)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_getimageprofile_args, 0, 0, 1)
		ZEND_ARG_INFO(0, name)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_getimagetotalinkdensity_args, 0, 0, 1)
		ZEND_ARG_INFO(0, radius)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_getimageregion_args, 0, 0, 4)
		ZEND_ARG_INFO(0, width)
		ZEND_ARG_INFO(0, height)
		ZEND_ARG_INFO(0, x)
		ZEND_ARG_INFO(0, y)
	ZEND_END_ARG_INFO()

#if MagickLibVersion >= 0x658
	ZEND_BEGIN_ARG_INFO_EX(imagick_inversefouriertransformimage_args, 0, 0, 3)
		ZEND_ARG_INFO(0, complement)
		ZEND_ARG_INFO(0, magnitude)
	ZEND_END_ARG_INFO()
#endif

	ZEND_BEGIN_ARG_INFO_EX(imagick_levelimage_args, 0, 0, 3)
		ZEND_ARG_INFO(0, blackPoint)
		ZEND_ARG_INFO(0, gamma)
		ZEND_ARG_INFO(0, whitePoint)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
	ZEND_BEGIN_ARG_INFO_EX(imagick_mapimage_args, 0, 0, 2)
		ZEND_ARG_OBJ_INFO(0, Imagick, Imagick, 0)
		ZEND_ARG_INFO(0, dither)
	ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion < 0x700
	ZEND_BEGIN_ARG_INFO_EX(imagick_mattefloodfillimage_args, 0, 0, 5)
		ZEND_ARG_INFO(0, alpha)
		ZEND_ARG_INFO(0, fuzz)
		ZEND_ARG_INFO(0, color)
		ZEND_ARG_INFO(0, x)
		ZEND_ARG_INFO(0, y)
	ZEND_END_ARG_INFO()
#endif
#endif

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
	ZEND_BEGIN_ARG_INFO_EX(imagick_medianfilterimage_args, 0, 0, 1)
		ZEND_ARG_INFO(0, radius)
	ZEND_END_ARG_INFO()
#endif
#endif

	ZEND_BEGIN_ARG_INFO_EX(imagick_negateimage_args, 0, 0, 1)
		ZEND_ARG_INFO(0, gray)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
	ZEND_BEGIN_ARG_INFO_EX(imagick_paintopaqueimage_args, 0, 0, 3)
		ZEND_ARG_INFO(0, target_color)
		ZEND_ARG_INFO(0, fill_color)
		ZEND_ARG_INFO(0, fuzz)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion < 0x700
	ZEND_BEGIN_ARG_INFO_EX(imagick_painttransparentimage_args, 0, 0, 3)
		ZEND_ARG_INFO(0, target_color)
		ZEND_ARG_INFO(0, alpha)
		ZEND_ARG_INFO(0, fuzz)
	ZEND_END_ARG_INFO()
#endif
#endif

	ZEND_BEGIN_ARG_INFO_EX(imagick_previewimages_args, 0, 0, 1)
		ZEND_ARG_INFO(0, PREVIEW)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_profileimage_args, 0, 0, 2)
		ZEND_ARG_INFO(0, name)
		ZEND_ARG_INFO(0, profile)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_quantizeimage_args, 0, 0, 5)
		ZEND_ARG_INFO(0, numColors)
		ZEND_ARG_INFO(0, COLORSPACE)
		ZEND_ARG_INFO(0, treeDepth)
		ZEND_ARG_INFO(0, dither)
		ZEND_ARG_INFO(0, measureError)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_quantizeimages_args, 0, 0, 5)
		ZEND_ARG_INFO(0, numColors)
		ZEND_ARG_INFO(0, COLORSPACE)
		ZEND_ARG_INFO(0, treeDepth)
		ZEND_ARG_INFO(0, dither)
		ZEND_ARG_INFO(0, measureError)
	ZEND_END_ARG_INFO()

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
	ZEND_BEGIN_ARG_INFO_EX(imagick_reducenoiseimage_args, 0, 0, 1)
		ZEND_ARG_INFO(0, radius)
	ZEND_END_ARG_INFO()
#endif
#endif

	ZEND_BEGIN_ARG_INFO_EX(imagick_removeimageprofile_args, 0, 0, 1)
		ZEND_ARG_INFO(0, name)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_separateimagechannel_args, 0, 0, 1)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_sepiatoneimage_args, 0, 0, 1)
		ZEND_ARG_INFO(0, threshold)
	ZEND_END_ARG_INFO()

#if MagickLibVersion < 0x700
	ZEND_BEGIN_ARG_INFO_EX(imagick_setimagebias_args, 0, 0, 1)
		ZEND_ARG_INFO(0, bias)
	ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion < 0x700
	ZEND_BEGIN_ARG_INFO_EX(imagick_setimagebiasquantum_args, 0, 0, 1)
		ZEND_ARG_INFO(0, bias)
	ZEND_END_ARG_INFO()
#endif

	ZEND_BEGIN_ARG_INFO_EX(imagick_setimageblueprimary_args, 0, 0, 2)
		ZEND_ARG_INFO(0, x)
		ZEND_ARG_INFO(0, y)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setimagebordercolor_args, 0, 0, 1)
		ZEND_ARG_INFO(0, color)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setimagechanneldepth_args, 0, 0, 2)
		ZEND_ARG_INFO(0, CHANNEL)
		ZEND_ARG_INFO(0, depth)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setimagecolormapcolor_args, 0, 0, 2)
		ZEND_ARG_INFO(0, index)
		ZEND_ARG_INFO(0, color)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setimagecolorspace_args, 0, 0, 1)
		ZEND_ARG_INFO(0, COLORSPACE)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setimagedispose_args, 0, 0, 1)
		ZEND_ARG_INFO(0, DISPOSETYPE)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setimageextent_args, 0, 0, 2)
		ZEND_ARG_INFO(0, columns)
		ZEND_ARG_INFO(0, rows)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setimagegreenprimary_args, 0, 0, 2)
		ZEND_ARG_INFO(0, x)
		ZEND_ARG_INFO(0, y)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setimageinterlacescheme_args, 0, 0, 1)
		ZEND_ARG_INFO(0, INTERLACE)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setimageprofile_args, 0, 0, 2)
		ZEND_ARG_INFO(0, name)
		ZEND_ARG_INFO(0, profile)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setimageredprimary_args, 0, 0, 2)
		ZEND_ARG_INFO(0, x)
		ZEND_ARG_INFO(0, y)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setimagerenderingintent_args, 0, 0, 1)
		ZEND_ARG_INFO(0, RENDERINGINTENT)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setimagevirtualpixelmethod_args, 0, 0, 1)
		ZEND_ARG_INFO(0, VIRTUALPIXELMETHOD)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setimagewhitepoint_args, 0, 0, 2)
		ZEND_ARG_INFO(0, x)
		ZEND_ARG_INFO(0, y)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_sigmoidalcontrastimage_args, 0, 0, 3)
		ZEND_ARG_INFO(0, sharpen)
		ZEND_ARG_INFO(0, contrast)
		ZEND_ARG_INFO(0, midpoint)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_stereoimage_args, 0, 0, 1)
		ZEND_ARG_OBJ_INFO(0, Imagick, Imagick, 0)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_textureimage_args, 0, 0, 1)
		ZEND_ARG_OBJ_INFO(0, Imagick, Imagick, 0)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_tintimage_args, 0, 0, 2)
		ZEND_ARG_INFO(0, tint_color)
		ZEND_ARG_INFO(0, opacity)
		ZEND_ARG_INFO(0, legacy)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_unsharpmaskimage_args, 0, 0, 4)
		ZEND_ARG_INFO(0, radius)
		ZEND_ARG_INFO(0, sigma)
		ZEND_ARG_INFO(0, amount)
		ZEND_ARG_INFO(0, threshold)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_addimage_args, 0, 0, 1)
		ZEND_ARG_OBJ_INFO(0, Imagick, Imagick, 0)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setimage_args, 0, 0, 1)
		ZEND_ARG_OBJ_INFO(0, Imagick, Imagick, 0)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_newimage_args, 0, 0, 3)
		ZEND_ARG_INFO(0, columns)
		ZEND_ARG_INFO(0, rows)
		ZEND_ARG_INFO(0, background_color)
		ZEND_ARG_INFO(0, format)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_newpseudoimage_args, 0, 0, 3)
		ZEND_ARG_INFO(0, columns)
		ZEND_ARG_INFO(0, rows)
		ZEND_ARG_INFO(0, pseudoString)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_getoption_args, 0, 0, 1)
		ZEND_ARG_INFO(0, key)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_getconfigureoptions_args, 0, 0, 0)
		ZEND_ARG_INFO(0, pattern)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_getresource_args, 0, 0, 1)
		ZEND_ARG_INFO(0, resource_type)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_getresourcelimit_args, 0, 0, 1)
		ZEND_ARG_INFO(0, resource_type)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setbackgroundcolor_args, 0, 0, 1)
		ZEND_ARG_INFO(0, color)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setcompression_args, 0, 0, 1)
		ZEND_ARG_INFO(0, compression)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setcompressionquality_args, 0, 0, 1)
		ZEND_ARG_INFO(0, compressionquality)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setfilename_args, 0, 0, 1)
		ZEND_ARG_INFO(0, filename)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setformat_args, 0, 0, 1)
		ZEND_ARG_INFO(0, format)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setinterlacescheme_args, 0, 0, 1)
		ZEND_ARG_INFO(0, INTERLACE)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setoption_args, 0, 0, 2)
		ZEND_ARG_INFO(0, key)
		ZEND_ARG_INFO(0, value)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setpage_args, 0, 0, 4)
		ZEND_ARG_INFO(0, width)
		ZEND_ARG_INFO(0, height)
		ZEND_ARG_INFO(0, x)
		ZEND_ARG_INFO(0, y)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setresourcelimit_args, 0, 0, 2)
		ZEND_ARG_INFO(0, RESOURCETYPE)
		ZEND_ARG_INFO(0, limit)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setresolution_args, 0, 0, 2)
		ZEND_ARG_INFO(0, xResolution)
		ZEND_ARG_INFO(0, yResolution)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setsamplingfactors_args, 0, 0, 1)
		ZEND_ARG_INFO(0, factors)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setsize_args, 0, 0, 2)
		ZEND_ARG_INFO(0, columns)
		ZEND_ARG_INFO(0, rows)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_settype_args, 0, 0, 1)
		ZEND_ARG_INFO(0, IMGTYPE)
	ZEND_END_ARG_INFO()

#if MagickLibVersion >= 0x659
	ZEND_BEGIN_ARG_INFO_EX(imagick_brightnesscontrastimage_args, 0, 0, 2)
		ZEND_ARG_INFO(0, brightness)
		ZEND_ARG_INFO(0, contrast)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion > 0x661
	ZEND_BEGIN_ARG_INFO_EX(imagick_colormatriximage_args, 0, 0, 1)
		ZEND_ARG_INFO(0, color_matrix)
	ZEND_END_ARG_INFO()
#endif

	ZEND_BEGIN_ARG_INFO_EX(imagick_selectiveblurimage_args, 0, 0, 4)
		ZEND_ARG_INFO(0, radius)
		ZEND_ARG_INFO(0, sigma)
		ZEND_ARG_INFO(0, threshold)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()

#if MagickLibVersion >= 0x689
	ZEND_BEGIN_ARG_INFO_EX(imagick_rotationalblurimage_args, 0, 0, 1)
		ZEND_ARG_INFO(0, angle)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion >= 0x683
	ZEND_BEGIN_ARG_INFO_EX(imagick_statisticimage_args, 0, 0, 3)
		ZEND_ARG_INFO(0, type)
		ZEND_ARG_INFO(0, width)
		ZEND_ARG_INFO(0, height)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()
#endif

#if MagickLibVersion >= 0x652
	ZEND_BEGIN_ARG_INFO_EX(imagick_subimagematch_args, 0, 0, 1)
		ZEND_ARG_OBJ_INFO(0, Imagick, Imagick, 0)
		ZEND_ARG_INFO(1, offset)
		ZEND_ARG_INFO(1, similarity)
		ZEND_ARG_INFO(1, similarity_threshold) // the minimum similarity to match?
		ZEND_ARG_INFO(1, metric) //Which comparison to use METRIC_*
	ZEND_END_ARG_INFO()
#endif

#if PHP_VERSION_ID >= 50600
	ZEND_BEGIN_ARG_INFO_EX(imagick_count_args, 0, 0, 0)
		ZEND_ARG_INFO(0, mode)
	ZEND_END_ARG_INFO()
#endif

	ZEND_BEGIN_ARG_INFO_EX(imagick_setregistry_args, 0, 0, 2)
		ZEND_ARG_INFO(0, key)
		ZEND_ARG_INFO(0, value)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_getregistry_args, 0, 0, 1)
		ZEND_ARG_INFO(0, key)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_setantialias_args, 0, 0, 1)
		ZEND_ARG_INFO(0, antialias)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_colordecisionlistimage_args, 0, 0, 1)
		ZEND_ARG_INFO(0, antialias)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_autogammaimage_args, 0, 0, 1)
		ZEND_ARG_INFO(0, CHANNEL)
	ZEND_END_ARG_INFO()

	ZEND_BEGIN_ARG_INFO_EX(imagick_compositeimagegravity_args, 0, 0, 3)
		ZEND_ARG_OBJ_INFO(0, Imagick, Imagick, 0)
		ZEND_ARG_INFO(0, COMPOSITE)
		ZEND_ARG_INFO(0, GRAVITY)
	ZEND_END_ARG_INFO()

#if MagickLibVersion >= 0x693
	ZEND_BEGIN_ARG_INFO_EX(imagick_localContrastImage_args, 0, 0, 2)
		ZEND_ARG_INFO(0, radius)
		ZEND_ARG_INFO(0, strength)
	ZEND_END_ARG_INFO()
#endif // MagickLibVersion >= 0x693

//
///* ImagickDraw */
//#if MagickLibVersion > 0x649
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_settextkerning_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, kerning)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_settextinterwordspacing_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, spacing)
//	ZEND_END_ARG_INFO()
//#endif
//#if MagickLibVersion > 0x655
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_settextinterlinespacing_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, spacing)
//	ZEND_END_ARG_INFO()
//#endif
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_zero_args, 0, 0, 0)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_setfillcolor_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, color)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_setfillalpha_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, alpha)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_setstrokecolor_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, color)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_setresolution_args, 0, 0, 2)
//		ZEND_ARG_INFO(0, x_resolution)
//		ZEND_ARG_INFO(0, y_resolution)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_setstrokealpha_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, alpha)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_setstrokewidth_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, width)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_circle_args, 0, 0, 4)
//		ZEND_ARG_INFO(0, ox)
//		ZEND_ARG_INFO(0, oy)
//		ZEND_ARG_INFO(0, px)
//		ZEND_ARG_INFO(0, py)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_annotation_args, 0, 0, 3)
//		ZEND_ARG_INFO(0, x)
//		ZEND_ARG_INFO(0, y)
//		ZEND_ARG_INFO(0, text)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_settextantialias_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, antialias)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_settextencoding_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, encoding)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_setfont_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, font)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_setfontfamily_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, fontfamily)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_setfontsize_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, pointsize)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_setfontstyle_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, STYLE)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_setfontweight_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, weight)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_rectangle_args, 0, 0, 4)
//		ZEND_ARG_INFO(0, x1)
//		ZEND_ARG_INFO(0, y1)
//		ZEND_ARG_INFO(0, x2)
//		ZEND_ARG_INFO(0, y2)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_roundrectangle_args, 0, 0, 6)
//		ZEND_ARG_INFO(0, x1)
//		ZEND_ARG_INFO(0, y1)
//		ZEND_ARG_INFO(0, x2)
//		ZEND_ARG_INFO(0, y2)
//		ZEND_ARG_INFO(0, rx)
//		ZEND_ARG_INFO(0, ry)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_ellipse_args, 0, 0, 6)
//		ZEND_ARG_INFO(0, ox)
//		ZEND_ARG_INFO(0, oy)
//		ZEND_ARG_INFO(0, px)
//		ZEND_ARG_INFO(0, py)
//		ZEND_ARG_INFO(0, start)
//		ZEND_ARG_INFO(0, end)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_skewx_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, degrees)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_skewy_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, degrees)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_translate_args, 0, 0, 2)
//		ZEND_ARG_INFO(0, x)
//		ZEND_ARG_INFO(0, y)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_line_args, 0, 0, 4)
//		ZEND_ARG_INFO(0, sx)
//		ZEND_ARG_INFO(0, sy)
//		ZEND_ARG_INFO(0, ex)
//		ZEND_ARG_INFO(0, ey)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_arc_args, 0, 0, 6)
//		ZEND_ARG_INFO(0, sx)
//		ZEND_ARG_INFO(0, sy)
//		ZEND_ARG_INFO(0, ex)
//		ZEND_ARG_INFO(0, ey)
//		ZEND_ARG_INFO(0, sd)
//		ZEND_ARG_INFO(0, ed)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_matte_args, 0, 0, 3)
//		ZEND_ARG_INFO(0, x)
//		ZEND_ARG_INFO(0, y)
//		ZEND_ARG_INFO(0, METHOD)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_polygon_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, coordinates)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_point_args, 0, 0, 2)
//		ZEND_ARG_INFO(0, x)
//		ZEND_ARG_INFO(0, y)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_setfontstretch_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, STRETCH)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_setstrokeantialias_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, antialias)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_setfontalignment_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, ALIGN)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_settextdecoration_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, DECORATION)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_settextundercolor_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, color)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_setviewbox_args, 0, 0, 4)
//		ZEND_ARG_INFO(0, sx)
//		ZEND_ARG_INFO(0, sy)
//		ZEND_ARG_INFO(0, ex)
//		ZEND_ARG_INFO(0, ey)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_affine_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, affineMatrix)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_bezier_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, coordinateArray)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_composite_args, 0, 0, 6)
//		ZEND_ARG_INFO(0, COMPOSE)
//		ZEND_ARG_INFO(0, x)
//		ZEND_ARG_INFO(0, y)
//		ZEND_ARG_INFO(0, width)
//		ZEND_ARG_INFO(0, height)
//		ZEND_ARG_OBJ_INFO(0, Imagick, Imagick, 0)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_color_args, 0, 0, 3)
//		ZEND_ARG_INFO(0, x)
//		ZEND_ARG_INFO(0, y)
//		ZEND_ARG_INFO(0, PAINTMETHOD)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_comment_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, comment)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_pathcurvetoabsolute_args, 0, 0, 6)
//		ZEND_ARG_INFO(0, x1)
//		ZEND_ARG_INFO(0, y1)
//		ZEND_ARG_INFO(0, x2)
//		ZEND_ARG_INFO(0, y2)
//		ZEND_ARG_INFO(0, x)
//		ZEND_ARG_INFO(0, y)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_pathcurvetorelative_args, 0, 0, 6)
//		ZEND_ARG_INFO(0, x1)
//		ZEND_ARG_INFO(0, y1)
//		ZEND_ARG_INFO(0, x2)
//		ZEND_ARG_INFO(0, y2)
//		ZEND_ARG_INFO(0, x)
//		ZEND_ARG_INFO(0, y)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_pathcurvetoquadraticbezierabsolute_args, 0, 0, 4)
//		ZEND_ARG_INFO(0, x1)
//		ZEND_ARG_INFO(0, y1)
//		ZEND_ARG_INFO(0, x)
//		ZEND_ARG_INFO(0, y)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_pathcurvetoquadraticbezierrelative_args, 0, 0, 4)
//		ZEND_ARG_INFO(0, x1)
//		ZEND_ARG_INFO(0, y1)
//		ZEND_ARG_INFO(0, x)
//		ZEND_ARG_INFO(0, y)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_pathcurvetoquadraticbeziersmoothabsolute_args, 0, 0, 2)
//		ZEND_ARG_INFO(0, x)
//		ZEND_ARG_INFO(0, y)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_pathcurvetoquadraticbeziersmoothrelative_args, 0, 0, 2)
//		ZEND_ARG_INFO(0, x)
//		ZEND_ARG_INFO(0, y)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_pathcurvetosmoothabsolute_args, 0, 0, 4)
//		ZEND_ARG_INFO(0, x1)
//		ZEND_ARG_INFO(0, y1)
//		ZEND_ARG_INFO(0, x)
//		ZEND_ARG_INFO(0, y)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_pathcurvetosmoothrelative_args, 0, 0, 4)
//		ZEND_ARG_INFO(0, x1)
//		ZEND_ARG_INFO(0, y1)
//		ZEND_ARG_INFO(0, x)
//		ZEND_ARG_INFO(0, y)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_pathellipticarcabsolute_args, 0, 0, 7)
//		ZEND_ARG_INFO(0, rx)
//		ZEND_ARG_INFO(0, ry)
//		ZEND_ARG_INFO(0, xAxisRotation)
//		ZEND_ARG_INFO(0, largeArc)
//		ZEND_ARG_INFO(0, sweep)
//		ZEND_ARG_INFO(0, x)
//		ZEND_ARG_INFO(0, y)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_pathellipticarcrelative_args, 0, 0, 7)
//		ZEND_ARG_INFO(0, rx)
//		ZEND_ARG_INFO(0, ry)
//		ZEND_ARG_INFO(0, xAxisRotation)
//		ZEND_ARG_INFO(0, largeArc)
//		ZEND_ARG_INFO(0, sweep)
//		ZEND_ARG_INFO(0, x)
//		ZEND_ARG_INFO(0, y)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_pathlinetoabsolute_args, 0, 0, 2)
//		ZEND_ARG_INFO(0, x)
//		ZEND_ARG_INFO(0, y)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_pathlinetorelative_args, 0, 0, 2)
//		ZEND_ARG_INFO(0, x)
//		ZEND_ARG_INFO(0, y)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_pathlinetohorizontalabsolute_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, y)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_pathlinetohorizontalrelative_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, x)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_pathlinetoverticalabsolute_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, y)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_pathlinetoverticalrelative_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, x)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_pathmovetoabsolute_args, 0, 0, 2)
//		ZEND_ARG_INFO(0, x)
//		ZEND_ARG_INFO(0, y)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_pathmovetorelative_args, 0, 0, 2)
//		ZEND_ARG_INFO(0, x)
//		ZEND_ARG_INFO(0, y)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_polyline_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, coordinateArray)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_pushclippath_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, clipMask)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_pushpattern_args, 0, 0, 5)
//		ZEND_ARG_INFO(0, pattern_id)
//		ZEND_ARG_INFO(0, x)
//		ZEND_ARG_INFO(0, y)
//		ZEND_ARG_INFO(0, width)
//		ZEND_ARG_INFO(0, height)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_rotate_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, degrees)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_scale_args, 0, 0, 2)
//		ZEND_ARG_INFO(0, x)
//		ZEND_ARG_INFO(0, y)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_setclippath_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, clipMask)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_setcliprule_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, FILLRULE)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_setclipunits_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, PATHUNITS)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_setfillopacity_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, fillOpacity)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_setfillpatternurl_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, url)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_setfillrule_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, FILLRULE)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_setgravity_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, GRAVITY)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_setstrokepatternurl_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, url)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_setstrokedashoffset_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, offset)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_setstrokelinecap_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, LINECAP)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_setstrokelinejoin_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, LINEJOIN)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_setstrokemiterlimit_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, miterLimit)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_setstrokeopacity_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, strokeOpacity)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_setvectorgraphics_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, xml)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_setstrokedasharray_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, dashArray)
//	ZEND_END_ARG_INFO()
//
//#if MagickLibVersion >= 0x693
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_setopacity_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, opacity)
//	ZEND_END_ARG_INFO()
//#endif // MagickLibVersion >= 0x693
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_setfontresolution_args, 0, 0, 2)
//		ZEND_ARG_INFO(0, x)
//		ZEND_ARG_INFO(0, y)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_setbordercolor_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, bordercolor)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_settextdirection_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, direction)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickdraw_setdensity_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, density)
//	ZEND_END_ARG_INFO()

///* ImagickPixel */
//#if MagickLibVersion > 0x628
//	ZEND_BEGIN_ARG_INFO_EX(imagickpixel_sethsl_args, 0, 0, 3)
//		ZEND_ARG_INFO(0, hue)
//		ZEND_ARG_INFO(0, saturation)
//		ZEND_ARG_INFO(0, luminosity)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickpixel_setcolorvaluequantum_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, color_value)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickpixel_setindex_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, index)
//	ZEND_END_ARG_INFO()
//#endif
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickpixel_zero_args, 0, 0, 0)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickpixel_construct_args, 0, 0, 0)
//		ZEND_ARG_INFO(0, color)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickpixel_setcolor_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, color)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickpixel_ispixelsimilarquantum_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, color)
//		ZEND_ARG_INFO(0, fuzz)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickpixel_ispixelsimilar_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, color)
//		ZEND_ARG_INFO(0, fuzz)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickpixel_setcolorvalue_args, 0, 0, 2)
//		ZEND_ARG_INFO(0, color)
//		ZEND_ARG_INFO(0, value)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickpixel_getcolorvalue_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, color)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickpixel_setcolorcount_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, colorCount)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickpixel_getcolor_args, 0, 0, 0)
//		ZEND_ARG_INFO(0, normalized)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickpixel_setcolorfrompixel_args, 0, 0, 1)
//		ZEND_ARG_OBJ_INFO(0, srcPixel, ImagickPixel, 0)
//	ZEND_END_ARG_INFO()

/* ImagickPixelIterator */

//	ZEND_BEGIN_ARG_INFO_EX(imagickpixeliterator_zero_args, 0, 0, 0)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickpixeliterator_construct_args, 0, 0, 1)
//		ZEND_ARG_OBJ_INFO(0, Imagick, Imagick, 0)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickpixeliterator_setiteratorrow_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, row)
//	ZEND_END_ARG_INFO()

//#ifdef IMAGICK_WITH_KERNEL
//	ZEND_BEGIN_ARG_INFO_EX(imagickkernel_frommatrix_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, array)
//		ZEND_ARG_INFO(0, array)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickkernel_frombuiltin_args, 0, 0, 2)
//		ZEND_ARG_INFO(0, kerneltype)
//		ZEND_ARG_INFO(0, paramstring)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickkernel_addkernel_args, 0, 0, 1)
//		ZEND_ARG_OBJ_INFO(0, ImagickKernel, ImagickKernel, 0)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickkernel_scale_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, scale)
//		ZEND_ARG_INFO(0, normalize_flag)
//	ZEND_END_ARG_INFO()
//
//	ZEND_BEGIN_ARG_INFO_EX(imagickkernel_addunitykernel_args, 0, 0, 1)
//		ZEND_ARG_INFO(0, scale)
//	ZEND_END_ARG_INFO()
//#endif

static zend_function_entry php_imagick_functions[] =
{
	{ NULL, NULL, NULL, 0, 0 }
};

//static zend_function_entry php_imagickdraw_class_methods[] =
//{
//#if MagickLibVersion > 0x628
//	PHP_ME(imagickdraw, resetvectorgraphics, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//#endif
//#if MagickLibVersion > 0x649
//	PHP_ME(imagickdraw, gettextkerning, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, settextkerning, imagickdraw_settextkerning_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, gettextinterwordspacing, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, settextinterwordspacing, imagickdraw_settextinterwordspacing_args, ZEND_ACC_PUBLIC)
//#endif
//#if MagickLibVersion > 0x655
//	PHP_ME(imagickdraw, gettextinterlinespacing, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, settextinterlinespacing, imagickdraw_settextinterlinespacing_args, ZEND_ACC_PUBLIC)
//#endif
//	PHP_ME(imagickdraw, __construct, imagickdraw_zero_args, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
//	PHP_ME(imagickdraw, setfillcolor, imagickdraw_setfillcolor_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, setfillalpha, imagickdraw_setfillalpha_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, setresolution, imagickdraw_setresolution_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, setstrokecolor, imagickdraw_setstrokecolor_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, setstrokealpha, imagickdraw_setstrokealpha_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, setstrokewidth, imagickdraw_setstrokewidth_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, clear, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, circle, imagickdraw_circle_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, annotation, imagickdraw_annotation_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, settextantialias, imagickdraw_settextantialias_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, settextencoding, imagickdraw_settextencoding_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, setfont, imagickdraw_setfont_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, setfontfamily, imagickdraw_setfontfamily_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, setfontsize, imagickdraw_setfontsize_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, setfontstyle, imagickdraw_setfontstyle_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, setfontweight, imagickdraw_setfontweight_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, getfont, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, getfontfamily, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, getfontsize, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, getfontstyle, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, getfontweight, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	ZEND_MALIAS(imagickdraw, destroy, clear, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, rectangle, imagickdraw_rectangle_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, roundrectangle, imagickdraw_roundrectangle_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, ellipse, imagickdraw_ellipse_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, skewx, imagickdraw_skewx_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, skewy, imagickdraw_skewy_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, translate, imagickdraw_translate_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, line, imagickdraw_line_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, arc, imagickdraw_arc_args, ZEND_ACC_PUBLIC)
//#if MagickLibVersion >= 0x700
//	PHP_ME(imagickdraw, alpha, imagickdraw_matte_args, ZEND_ACC_PUBLIC)
//#else
//	PHP_ME(imagickdraw, matte, imagickdraw_matte_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
//#endif
//	PHP_ME(imagickdraw, polygon, imagickdraw_polygon_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, point, imagickdraw_point_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, gettextdecoration, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, gettextencoding, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, getfontstretch, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, setfontstretch, imagickdraw_setfontstretch_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, setstrokeantialias, imagickdraw_setstrokeantialias_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, settextalignment, imagickdraw_setfontalignment_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, settextdecoration, imagickdraw_settextdecoration_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, settextundercolor, imagickdraw_settextundercolor_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, setviewbox, imagickdraw_setviewbox_args, ZEND_ACC_PUBLIC)
//  	PHP_ME(imagickdraw, clone, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, affine, imagickdraw_affine_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, bezier, imagickdraw_bezier_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, composite, imagickdraw_composite_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, color, imagickdraw_color_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, comment, imagickdraw_comment_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, getclippath, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, getcliprule, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, getclipunits, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, getfillcolor, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, getfillopacity, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, getfillrule, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, getgravity, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, getstrokeantialias, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, getstrokecolor, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, getstrokedasharray, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, getstrokedashoffset, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, getstrokelinecap, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, getstrokelinejoin, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, getstrokemiterlimit, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, getstrokeopacity, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, getstrokewidth, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, gettextalignment, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, gettextantialias, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, getvectorgraphics, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, gettextundercolor, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, pathclose, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, pathcurvetoabsolute, imagickdraw_pathcurvetoabsolute_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, pathcurvetorelative, imagickdraw_pathcurvetorelative_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, pathcurvetoquadraticbezierabsolute, imagickdraw_pathcurvetoquadraticbezierabsolute_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, pathcurvetoquadraticbezierrelative, imagickdraw_pathcurvetoquadraticbezierrelative_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, pathcurvetoquadraticbeziersmoothabsolute, imagickdraw_pathcurvetoquadraticbeziersmoothabsolute_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, pathcurvetoquadraticbeziersmoothrelative, imagickdraw_pathcurvetoquadraticbeziersmoothrelative_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, pathcurvetosmoothabsolute, imagickdraw_pathcurvetosmoothabsolute_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, pathcurvetosmoothrelative, imagickdraw_pathcurvetosmoothrelative_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, pathellipticarcabsolute, imagickdraw_pathellipticarcabsolute_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, pathellipticarcrelative, imagickdraw_pathellipticarcrelative_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, pathfinish, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, pathlinetoabsolute, imagickdraw_pathlinetoabsolute_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, pathlinetorelative, imagickdraw_pathlinetorelative_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, pathlinetohorizontalabsolute, imagickdraw_pathlinetohorizontalabsolute_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, pathlinetohorizontalrelative, imagickdraw_pathlinetohorizontalrelative_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, pathlinetoverticalabsolute, imagickdraw_pathlinetoverticalabsolute_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, pathlinetoverticalrelative, imagickdraw_pathlinetoverticalrelative_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, pathmovetoabsolute, imagickdraw_pathmovetoabsolute_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, pathmovetorelative, imagickdraw_pathmovetorelative_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, pathstart, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, polyline, imagickdraw_polyline_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, popclippath, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, popdefs, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, poppattern, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, pushclippath, imagickdraw_pushclippath_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, pushdefs, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, pushpattern, imagickdraw_pushpattern_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, render, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, rotate, imagickdraw_rotate_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, scale, imagickdraw_scale_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, setclippath, imagickdraw_setclippath_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, setcliprule, imagickdraw_setcliprule_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, setclipunits, imagickdraw_setclipunits_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, setfillopacity, imagickdraw_setfillopacity_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, setfillpatternurl, imagickdraw_setfillpatternurl_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, setfillrule, imagickdraw_setfillrule_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, setgravity, imagickdraw_setgravity_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, setstrokepatternurl, imagickdraw_setstrokepatternurl_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, setstrokedashoffset, imagickdraw_setstrokedashoffset_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, setstrokelinecap, imagickdraw_setstrokelinecap_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, setstrokelinejoin, imagickdraw_setstrokelinejoin_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, setstrokemiterlimit, imagickdraw_setstrokemiterlimit_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, setstrokeopacity, imagickdraw_setstrokeopacity_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, setvectorgraphics, imagickdraw_setvectorgraphics_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, pop, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, push, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, setstrokedasharray, imagickdraw_setstrokedasharray_args, ZEND_ACC_PUBLIC)
//#if MagickLibVersion >= 0x693
//	PHP_ME(imagickdraw, getopacity, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, setopacity, imagickdraw_setopacity_args, ZEND_ACC_PUBLIC)
//#endif //MagickLibVersion >= 0x693
//#if MagickLibVersion >= 0x675
//	PHP_ME(imagickdraw, getfontresolution, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, setfontresolution, imagickdraw_setfontresolution_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, getbordercolor, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, setbordercolor, imagickdraw_setbordercolor_args, ZEND_ACC_PUBLIC)
//#endif //#if MagickLibVersion >= 0x675
//
//#if MagickLibVersion >= 0x693
//	PHP_ME(imagickdraw, setdensity, imagickdraw_setdensity_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, getdensity, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//#endif// #if MagickLibVersion >= 0x693
//
//#if MagickLibVersion >= 0x692
//	PHP_ME(imagickdraw, gettextdirection, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickdraw, settextdirection, imagickdraw_settextdirection_args, ZEND_ACC_PUBLIC)
//#endif //#if MagickLibVersion >= 0x692
//
//	{ NULL, NULL, NULL, 0, 0 }
//};

#include "ImagickDraw_arginfo.h"

const zend_function_entry *php_imagickdraw_class_methods = class_ImagickDraw_methods;

//ZEND_BEGIN_ARG_INFO_EX(imagickpixeliterator_getpixeliterator_args, 0, 0, 6)
//	ZEND_ARG_OBJ_INFO(0, Imagick, Imagick, 0)
//ZEND_END_ARG_INFO()
//
//ZEND_BEGIN_ARG_INFO_EX(imagickpixeliterator_getpixelregioniterator_args, 0, 0, 6)
//	ZEND_ARG_OBJ_INFO(0, Imagick, Imagick, 0)
//	ZEND_ARG_INFO(0, x)
//	ZEND_ARG_INFO(0, y)
//	ZEND_ARG_INFO(0, columns)
//	ZEND_ARG_INFO(0, rows)
//ZEND_END_ARG_INFO()

//static
//zend_function_entry php_imagickpixeliterator_class_methods[] =
//{
//	PHP_ME(imagickpixeliterator, __construct, imagickpixeliterator_construct_args, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
//	PHP_ME(imagickpixeliterator, newpixeliterator, imagickpixeliterator_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickpixeliterator, newpixelregioniterator, imagickpixeliterator_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickpixeliterator, getiteratorrow, imagickpixeliterator_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickpixeliterator, setiteratorrow, imagickpixeliterator_setiteratorrow_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickpixeliterator, setiteratorfirstrow, imagickpixeliterator_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickpixeliterator, setiteratorlastrow, imagickpixeliterator_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickpixeliterator, getpreviousiteratorrow, imagickpixeliterator_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickpixeliterator, getcurrentiteratorrow, imagickpixeliterator_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickpixeliterator, getnextiteratorrow, imagickpixeliterator_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickpixeliterator, resetiterator, imagickpixeliterator_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickpixeliterator, synciterator, imagickpixeliterator_zero_args, ZEND_ACC_PUBLIC)
//	ZEND_MALIAS(imagickpixeliterator, destroy, clear, imagickpixeliterator_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickpixeliterator, clear, imagickpixeliterator_zero_args, ZEND_ACC_PUBLIC)
//
//	PHP_ME(imagickpixeliterator, getpixeliterator,       imagickpixeliterator_getpixeliterator_args, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
//	PHP_ME(imagickpixeliterator, getpixelregioniterator, imagickpixeliterator_getpixelregioniterator_args, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
//
//	/* Iterator interface */
//	PHP_MALIAS(imagickpixeliterator, key, getiteratorrow, imagickpixeliterator_zero_args, ZEND_ACC_PUBLIC)
//	PHP_MALIAS(imagickpixeliterator, next, getnextiteratorrow, imagickpixeliterator_zero_args, ZEND_ACC_PUBLIC)
//	PHP_MALIAS(imagickpixeliterator, rewind, resetiterator, imagickpixeliterator_zero_args, ZEND_ACC_PUBLIC)
//	PHP_MALIAS(imagickpixeliterator, current, getcurrentiteratorrow, imagickpixeliterator_zero_args, ZEND_ACC_PUBLIC)
//
//	PHP_ME(imagickpixeliterator, valid, imagickpixeliterator_zero_args, ZEND_ACC_PUBLIC)
//	{ NULL, NULL, NULL, 0, 0 }
//};

#include "ImagickPixelIterator_arginfo.h"

const zend_function_entry *php_imagickpixeliterator_class_methods = class_ImagickPixelIterator_methods;


//static zend_function_entry php_imagickpixel_class_methods[] =
//{
//#if MagickLibVersion > 0x628
//	PHP_ME(imagickpixel, gethsl, imagickpixel_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickpixel, sethsl, imagickpixel_sethsl_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickpixel, getcolorvaluequantum, imagickpixel_getcolorvalue_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickpixel, setcolorvaluequantum, imagickpixel_setcolorvaluequantum_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickpixel, getindex, imagickpixel_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickpixel, setindex, imagickpixel_setindex_args, ZEND_ACC_PUBLIC)
//#endif
//	PHP_ME(imagickpixel, __construct, imagickpixel_construct_args, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
//	PHP_ME(imagickpixel, setcolor, imagickpixel_setcolor_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickpixel, setcolorvalue, imagickpixel_setcolorvalue_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickpixel, getcolorvalue, imagickpixel_getcolorvalue_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickpixel, clear, imagickpixel_zero_args, ZEND_ACC_PUBLIC)
//	ZEND_MALIAS(imagickpixel, destroy, clear, imagickpixel_zero_args, ZEND_ACC_PUBLIC)
//	PHP_MALIAS(imagickpixel, issimilar, ispixelsimilarquantum, imagickpixel_ispixelsimilarquantum_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickpixel, ispixelsimilarquantum, imagickpixel_ispixelsimilarquantum_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickpixel, ispixelsimilar, imagickpixel_ispixelsimilar_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickpixel, getcolor, imagickpixel_getcolor_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickpixel, getcolorquantum, imagickpixel_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickpixel, getcolorasstring, imagickpixel_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickpixel, getcolorcount, imagickpixel_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickpixel, setcolorcount, imagickpixel_setcolorcount_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickpixel, clone, imagickpixel_zero_args, ZEND_ACC_PUBLIC)
//#if MagickLibVersion >= 0x693
//	PHP_ME(imagickpixel, setcolorfrompixel, imagickpixel_setcolorfrompixel_args, ZEND_ACC_PUBLIC)
//#endif //#if MagickLibVersion >= 0x693
//
//	{ NULL, NULL, NULL, 0, 0 }
//};

#include "ImagickPixel_arginfo.h"

const zend_function_entry *php_imagickpixel_class_methods = class_ImagickPixel_methods;


//
//static zend_function_entry php_imagick_class_methods[] =
//{
//#if MagickLibVersion > 0x628
//	PHP_ME(imagick, optimizeimagelayers, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, compareimagelayers, imagick_compareimagelayers_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, pingimageblob, imagick_pingimageblob_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, pingimagefile, imagick_pingimagefile_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, transposeimage, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, transverseimage, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, trimimage, imagick_trimimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, waveimage, imagick_waveimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, vignetteimage, imagick_vignetteimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, uniqueimagecolors, imagick_zero_args, ZEND_ACC_PUBLIC)
//#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
//#if MagickLibVersion < 0x700
//	PHP_ME(imagick, getimagematte, imagick_zero_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
//#endif // #if MagickLibVersion < 0x700
//#endif
//	PHP_ME(imagick, setimagematte, imagick_setimagematte_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, adaptiveresizeimage, imagick_adaptiveresizeimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, sketchimage, imagick_sketchimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, shadeimage, imagick_shadeimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getsizeoffset, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setsizeoffset, imagick_setsizeoffset_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, adaptiveblurimage, imagick_adaptiveblurimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, contraststretchimage, imagick_contraststretchimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, adaptivesharpenimage, imagick_adaptivesharpenimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, randomthresholdimage, imagick_randomthresholdimage_args, ZEND_ACC_PUBLIC)
//#if MagickLibVersion < 0x700
//	PHP_ME(imagick, roundcornersimage, imagick_roundcornersimage_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
//	/* This alias is due to BWC */
//	PHP_MALIAS(imagick, roundcorners, roundcornersimage, imagick_roundcornersimage_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
//#endif
//	PHP_ME(imagick, setiteratorindex, imagick_setiteratorindex_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getiteratorindex, imagick_zero_args, ZEND_ACC_PUBLIC)
//#if MagickLibVersion < 0x700
//	PHP_ME(imagick, transformimage, imagick_transformimage_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
//#endif // #if MagickLibVersion < 0x700
//#endif
//#if MagickLibVersion > 0x630
//#if MagickLibVersion < 0x700
//	PHP_ME(imagick, setimageopacity, imagick_setimageopacity_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
//#endif
//#if MagickLibVersion >= 0x700
//	PHP_ME(imagick, setimagealpha, imagick_setimagealpha_args, ZEND_ACC_PUBLIC)
//#endif
//#if MagickLibVersion < 0x700
//	PHP_ME(imagick, orderedposterizeimage, imagick_orderedposterizeimage_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
//#endif //#if MagickLibVersion < 0x700
//#endif //#if MagickLibVersion > 0x630
//#if MagickLibVersion > 0x631
//	PHP_ME(imagick, polaroidimage, imagick_polaroidimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimageproperty, imagick_getimageproperty_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setimageproperty, imagick_setimageproperty_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, deleteimageproperty, imagick_deleteimageproperty_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, identifyformat, imagick_identifyformat_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setimageinterpolatemethod, imagick_setimageinterpolatemethod_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimageinterpolatemethod, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, linearstretchimage, imagick_linearstretchimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimagelength, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, extentimage, imagick_extentimage_args, ZEND_ACC_PUBLIC)
//#endif
//#if MagickLibVersion > 0x633
//	PHP_ME(imagick, getimageorientation, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setimageorientation, imagick_setimageorientation_args, ZEND_ACC_PUBLIC)
//#endif
//#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
//#if MagickLibVersion > 0x634
//#if MagickLibVersion < 0x700
//	PHP_ME(imagick, paintfloodfillimage, imagick_paintfloodfillimage_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
//#endif // #if MagickLibVersion < 0x700
//#endif
//#endif
//#if MagickLibVersion > 0x635
//	PHP_ME(imagick, clutimage, imagick_clutimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimageproperties, imagick_getimageproperties_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimageprofiles, imagick_getimageprofiles_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, distortimage, imagick_distortimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, writeimagefile, imagick_writeimagefile_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, writeimagesfile, imagick_writeimagesfile_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, resetimagepage, imagick_resetimagepage_args, ZEND_ACC_PUBLIC)
//#if MagickLibVersion < 0x700
//	PHP_ME(imagick, setimageclipmask, imagick_setimageclipmask_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
//	PHP_ME(imagick, getimageclipmask, imagick_zero_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
//#endif
//	PHP_ME(imagick, animateimages, imagick_animateimages_args, ZEND_ACC_PUBLIC)
//#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
//#if MagickLibVersion < 0x700
//	PHP_ME(imagick, recolorimage, imagick_recolorimage_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
//#endif
//#endif
//#endif
//#if MagickLibVersion > 0x636
//	PHP_ME(imagick, setfont, imagick_setfont_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getfont, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setpointsize, imagick_setpointsize_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getpointsize, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, mergeimagelayers, imagick_mergeimagelayers_args, ZEND_ACC_PUBLIC)
//#endif
//#if MagickLibVersion > 0x637
//	PHP_ME(imagick, setimagealphachannel, imagick_setimagealphachannel_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, floodfillpaintimage, imagick_floodfillpaintimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, opaquepaintimage, imagick_opaquepaintimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, transparentpaintimage, imagick_transparentpaintimage_args, ZEND_ACC_PUBLIC)
//#endif
//#if MagickLibVersion > 0x638
//	PHP_ME(imagick, liquidrescaleimage, imagick_liquidrescaleimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, encipherimage, imagick_encipherimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, decipherimage, imagick_decipherimage_args, ZEND_ACC_PUBLIC)
//#endif
//#if MagickLibVersion > 0x639
//	PHP_ME(imagick, setgravity, imagick_setgravity_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getgravity, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimagechannelrange, imagick_getimagechannelrange_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimagealphachannel, imagick_zero_args, ZEND_ACC_PUBLIC)
//#endif
//#if MagickLibVersion > 0x642
//	PHP_ME(imagick, getimagechanneldistortions, imagick_getimagechanneldistortions_args, ZEND_ACC_PUBLIC)
//#endif
//#if MagickLibVersion > 0x643
//	PHP_ME(imagick, setimagegravity, imagick_setimagegravity_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimagegravity, imagick_zero_args, ZEND_ACC_PUBLIC)
//#endif
//#if MagickLibVersion > 0x645
//	PHP_ME(imagick, importimagepixels, imagick_importimagepixels_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, deskewimage, imagick_deskewimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, segmentimage, imagick_segmentimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, sparsecolorimage, imagick_sparsecolorimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, remapimage, imagick_remapimage_args, ZEND_ACC_PUBLIC)
//#endif
//#if PHP_IMAGICK_HAVE_HOUGHLINE
//	PHP_ME(imagick, houghlineimage, imagick_houghlineimage_args, ZEND_ACC_PUBLIC)
//#endif
//#if MagickLibVersion > 0x646
//	PHP_ME(imagick, exportimagepixels, imagick_exportimagepixels_args, ZEND_ACC_PUBLIC)
//#endif
//#if MagickLibVersion > 0x648
//	PHP_ME(imagick, getimagechannelkurtosis, imagick_getimagechannelkurtosis_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, functionimage, imagick_functionimage_args, ZEND_ACC_PUBLIC)
//#endif
//#if MagickLibVersion > 0x651
//	PHP_ME(imagick, transformimagecolorspace, imagick_transformimagecolorspace_args, ZEND_ACC_PUBLIC)
//#endif
//#if MagickLibVersion > 0x652
//	PHP_ME(imagick, haldclutimage, imagick_haldclutimage_args, ZEND_ACC_PUBLIC)
//#endif
//#if MagickLibVersion > 0x655
//	PHP_ME(imagick, autolevelimage, imagick_autolevelimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, blueshiftimage, imagick_blueshiftimage_args, ZEND_ACC_PUBLIC)
//#endif
//#if MagickLibVersion > 0x656
//	PHP_ME(imagick, getimageartifact, imagick_getimageartifact_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setimageartifact, imagick_setimageartifact_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, deleteimageartifact, imagick_deleteimageartifact_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getcolorspace, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setcolorspace, imagick_setcolorspace_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, clampimage, imagick_clampimage_args, ZEND_ACC_PUBLIC)
//#endif
//#if MagickLibVersion > 0x667
//	PHP_ME(imagick, smushimages, imagick_smushimages_args, ZEND_ACC_PUBLIC)
//#endif
//	PHP_ME(imagick, __construct, imagick_construct_args, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
//	PHP_ME(imagick, __tostring, imagick_zero_args, ZEND_ACC_PUBLIC)
//#if PHP_VERSION_ID >= 50600
//	PHP_ME(imagick, count, imagick_count_args, ZEND_ACC_PUBLIC)
//#else
//	PHP_ME(imagick, count, imagick_zero_args, ZEND_ACC_PUBLIC)
//#endif
//	PHP_ME(imagick, getpixeliterator, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getpixelregioniterator, imagick_getpixelregioniterator_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, readimage, imagick_readimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, readimages, imagick_readimages_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, readimageblob, imagick_readimageblob_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setimageformat, imagick_setimageformat_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, scaleimage, imagick_scaleimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, writeimage, imagick_writeimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, writeimages, imagick_writeimages_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, blurimage, imagick_blurimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, thumbnailimage, imagick_thumbnailimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, cropthumbnailimage, imagick_cropthumbnailimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimagefilename, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setimagefilename, imagick_setimagefilename_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimageformat, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimagemimetype, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, removeimage, imagick_zero_args, ZEND_ACC_PUBLIC)
//	ZEND_MALIAS(imagick, destroy, clear, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, clear, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, clone, imagick_zero_args, ZEND_ACC_PUBLIC)
//#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
//#if MagickLibVersion < 0x700
//	PHP_ME(imagick, getimagesize, imagick_zero_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
//#endif // #if MagickLibVersion < 0x700
//#endif
//	PHP_ME(imagick, getimageblob, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimagesblob, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setfirstiterator, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setlastiterator, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, resetiterator, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, previousimage, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, nextimage, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, haspreviousimage, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, hasnextimage, imagick_zero_args, ZEND_ACC_PUBLIC)
//#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
//#if MagickLibVersion < 0x700
//	PHP_ME(imagick, setimageindex, imagick_setimageindex_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
//	PHP_ME(imagick, getimageindex, imagick_zero_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
//#endif // #if MagickLibVersion < 0x700
//#endif
//	PHP_ME(imagick, commentimage, imagick_commentimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, cropimage, imagick_cropimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, labelimage, imagick_labelimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimagegeometry, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, drawimage, imagick_drawimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setimagecompressionquality, imagick_setimagecompressionquality_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimagecompressionquality, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setimagecompression, imagick_setimagecompression_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimagecompression, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, annotateimage, imagick_annotateimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, compositeimage, imagick_compositeimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, modulateimage, imagick_modulateimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimagecolors, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, montageimage, imagick_montageimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, identifyimage, imagick_identifyimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, thresholdimage, imagick_thresholdimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, adaptivethresholdimage, imagick_adaptivethresholdimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, blackthresholdimage, imagick_blackthresholdimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, whitethresholdimage, imagick_whitethresholdimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, appendimages, imagick_appendimages_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, charcoalimage, imagick_charcoalimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, normalizeimage, imagick_normalizeimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, oilpaintimage, imagick_oilpaintimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, posterizeimage, imagick_posterizeimage_args, ZEND_ACC_PUBLIC)
//#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
//#if MagickLibVersion < 0x700
//	PHP_ME(imagick, radialblurimage, imagick_radialblurimage_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
//#endif
//#endif
//	PHP_ME(imagick, raiseimage, imagick_raiseimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, resampleimage, imagick_resampleimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, resizeimage, imagick_resizeimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, rollimage, imagick_rollimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, rotateimage, imagick_rotateimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, sampleimage, imagick_sampleimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, solarizeimage, imagick_solarizeimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, shadowimage, imagick_shadowimage_args, ZEND_ACC_PUBLIC)
//#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
//#if MagickLibVersion < 0x700
//	PHP_ME(imagick, setimageattribute, imagick_setimageattribute_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
//#endif // #if MagickLibVersion < 0x700
//#endif
//	PHP_ME(imagick, setimagebackgroundcolor, imagick_setimagebackgroundcolor_args, ZEND_ACC_PUBLIC)
//#if MagickLibVersion >= 0x700
//	PHP_ME(imagick, setimagechannelmask, imagick_setimagechannelmask_args, ZEND_ACC_PUBLIC)
//#endif
//	PHP_ME(imagick, setimagecompose, imagick_setimagecompose_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setimagedelay, imagick_setimagedelay_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setimagedepth, imagick_setimagedepth_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setimagegamma, imagick_setimagegamma_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setimageiterations, imagick_setimageiterations_args, ZEND_ACC_PUBLIC)
//#if MagickLibVersion < 0x700
//	PHP_ME(imagick, setimagemattecolor, imagick_setimagemattecolor_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
//#endif // #if MagickLibVersion < 0x700
//	PHP_ME(imagick, setimagepage, imagick_setimagepage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setimageprogressmonitor, imagick_setimageprogressmonitor_args, ZEND_ACC_PUBLIC)
//#if MagickLibVersion > 0x653
//	PHP_ME(imagick, setprogressmonitor, imagick_setprogressmonitor_args, ZEND_ACC_PUBLIC)
//#endif
//	PHP_ME(imagick, setimageresolution, imagick_setimageresolution_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setimagescene, imagick_setimagescene_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setimagetickspersecond, imagick_setimagetickspersecond_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setimagetype, imagick_setimagetype_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setimageunits, imagick_setimageunits_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, sharpenimage, imagick_sharpenimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, shaveimage, imagick_shaveimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, shearimage, imagick_shearimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, spliceimage, imagick_spliceimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, pingimage, imagick_pingimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, readimagefile, imagick_readimagefile_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, displayimage, imagick_displayimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, displayimages, imagick_displayimages_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, spreadimage, imagick_spreadimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, swirlimage, imagick_swirlimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, stripimage, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, queryformats, imagick_queryformats_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, queryfonts, imagick_queryfonts_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, queryfontmetrics, imagick_queryfontmetrics_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, steganoimage, imagick_steganoimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, addnoiseimage, imagick_addnoiseimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, motionblurimage, imagick_motionblurimage_args, ZEND_ACC_PUBLIC)
//#if MagickLibVersion < 0x700
//#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
//	PHP_ME(imagick, mosaicimages, imagick_zero_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
//#endif
//#endif
//	PHP_ME(imagick, morphimages, imagick_morphimages_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, minifyimage, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, affinetransformimage, imagick_affinetransformimage_args, ZEND_ACC_PUBLIC)
//#if MagickLibVersion < 0x700
//#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
//	PHP_ME(imagick, averageimages, imagick_zero_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
//#endif
//#endif
//	PHP_ME(imagick, borderimage, imagick_borderimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, calculatecrop, imagick_calculatecrop_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, chopimage, imagick_chopimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, clipimage, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, clippathimage, imagick_clippathimage_args, ZEND_ACC_PUBLIC)
//	/* clippathimage has been deprecated. Create alias here and use the newer API function if present */
//	PHP_MALIAS(imagick, clipimagepath, clippathimage, imagick_clippathimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, coalesceimages, imagick_zero_args, ZEND_ACC_PUBLIC)
//#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
//#if MagickLibVersion < 0x700
//	PHP_ME(imagick, colorfloodfillimage, imagick_colorfloodfillimage_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
//#endif // #if MagickLibVersion < 0x700
//#endif
//	PHP_ME(imagick, colorizeimage, imagick_colorizeimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, compareimagechannels, imagick_compareimagechannels_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, compareimages, imagick_compareimages_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, contrastimage, imagick_contrastimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, combineimages, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, convolveimage, imagick_convolveimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, cyclecolormapimage, imagick_cyclecolormapimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, deconstructimages, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, despeckleimage, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, edgeimage, imagick_edgeimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, embossimage, imagick_embossimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, enhanceimage, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, equalizeimage, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, evaluateimage, imagick_evaluateimage_args, ZEND_ACC_PUBLIC)
//#if MagickLibVersion >= 0x687
//	PHP_ME(imagick, evaluateimages, imagick_evaluateimages_args, ZEND_ACC_PUBLIC)
//#endif // MagickLibVersion >= 0x687
//#if MagickLibVersion < 0x700
//#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
//	PHP_ME(imagick, flattenimages, imagick_zero_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
//#endif
//#endif
//	PHP_ME(imagick, flipimage, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, flopimage, imagick_zero_args, ZEND_ACC_PUBLIC)
//#if MagickLibVersion >= 0x655
//	PHP_ME(imagick, forwardfouriertransformimage, imagick_forwardfouriertransformimage_args, ZEND_ACC_PUBLIC)
//#endif
//	PHP_ME(imagick, frameimage, imagick_frameimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, fximage, imagick_fximage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, gammaimage, imagick_gammaimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, gaussianblurimage, imagick_gaussianblurimage_args, ZEND_ACC_PUBLIC)
//#if MagickLibVersion < 0x700
//#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
//	PHP_ME(imagick, getimageattribute, imagick_getimageattribute_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
//#endif
//#endif
//	PHP_ME(imagick, getimagebackgroundcolor, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimageblueprimary, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimagebordercolor, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimagechanneldepth, imagick_getimagechanneldepth_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimagechanneldistortion, imagick_getimagechanneldistortion_args, ZEND_ACC_PUBLIC)
//#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
//#if MagickLibVersion < 0x700
//	PHP_ME(imagick, getimagechannelextrema, imagick_getimagechannelextrema_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
//#endif // #if MagickLibVersion < 0x700
//#endif
//	PHP_ME(imagick, getimagechannelmean, imagick_getimagechannelmean_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimagechannelstatistics, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimagecolormapcolor, imagick_getimagecolormapcolor_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimagecolorspace, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimagecompose, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimagedelay, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimagedepth, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimagedistortion, imagick_getimagedistortion_args, ZEND_ACC_PUBLIC)
//#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
//#if MagickLibVersion < 0x700
//	PHP_ME(imagick, getimageextrema, imagick_zero_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
//#endif // #if MagickLibVersion < 0x700
//#endif
//	PHP_ME(imagick, getimagedispose, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimagegamma, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimagegreenprimary, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimageheight, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimagehistogram, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimageinterlacescheme, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimageiterations, imagick_zero_args, ZEND_ACC_PUBLIC)
//#if MagickLibVersion < 0x700
//	PHP_ME(imagick, getimagemattecolor, imagick_zero_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
//#endif //#if MagickLibVersion < 0x700
//	PHP_ME(imagick, getimagepage, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimagepixelcolor, imagick_getimagepixelcolor_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimageprofile, imagick_getimageprofile_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimageredprimary, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimagerenderingintent, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimageresolution, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimagescene, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimagesignature, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimagetickspersecond, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimagetype, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimageunits, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimagevirtualpixelmethod, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimagewhitepoint, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimagewidth, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getnumberimages, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimagetotalinkdensity, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimageregion, imagick_getimageregion_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, implodeimage, imagick_getimagetotalinkdensity_args, ZEND_ACC_PUBLIC)
//#if MagickLibVersion >= 0x658
//	PHP_ME(imagick, inversefouriertransformimage, imagick_inversefouriertransformimage_args, ZEND_ACC_PUBLIC)
//#endif
//	PHP_ME(imagick, levelimage, imagick_levelimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, magnifyimage, imagick_zero_args, ZEND_ACC_PUBLIC)
//#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
//#if MagickLibVersion < 0x700
//	PHP_ME(imagick, mapimage, imagick_mapimage_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
//	PHP_ME(imagick, mattefloodfillimage, imagick_mattefloodfillimage_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
//#endif // #if MagickLibVersion < 0x700
//#endif
//#if MagickLibVersion < 0x700
//#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
//	PHP_ME(imagick, medianfilterimage, imagick_medianfilterimage_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
//#endif
//#endif
//	PHP_ME(imagick, negateimage, imagick_negateimage_args, ZEND_ACC_PUBLIC)
//#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
//#if MagickLibVersion < 0x700
//	PHP_ME(imagick, paintopaqueimage, imagick_paintopaqueimage_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
//	PHP_ME(imagick, painttransparentimage, imagick_painttransparentimage_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
//#endif //#if MagickLibVersion < 0x700
//#endif
//	PHP_ME(imagick, previewimages, imagick_previewimages_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, profileimage, imagick_profileimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, quantizeimage, imagick_quantizeimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, quantizeimages, imagick_quantizeimages_args, ZEND_ACC_PUBLIC)
//#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
//#if MagickLibVersion < 0x700
//	PHP_ME(imagick, reducenoiseimage, imagick_reducenoiseimage_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
//#endif
//#endif
//	PHP_ME(imagick, removeimageprofile, imagick_removeimageprofile_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, separateimagechannel, imagick_separateimagechannel_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, sepiatoneimage, imagick_sepiatoneimage_args, ZEND_ACC_PUBLIC)
//#if MagickLibVersion < 0x700
//	PHP_ME(imagick, setimagebias, imagick_setimagebias_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
//	PHP_ME(imagick, setimagebiasquantum, imagick_setimagebiasquantum_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
//#endif
//	PHP_ME(imagick, setimageblueprimary, imagick_setimageblueprimary_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setimagebordercolor, imagick_setimagebordercolor_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setimagechanneldepth, imagick_setimagechanneldepth_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setimagecolormapcolor, imagick_setimagecolormapcolor_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setimagecolorspace, imagick_setimagecolorspace_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setimagedispose, imagick_setimagedispose_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setimageextent, imagick_setimageextent_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setimagegreenprimary, imagick_setimagegreenprimary_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setimageinterlacescheme, imagick_setimageinterlacescheme_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setimageprofile, imagick_setimageprofile_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setimageredprimary, imagick_setimageredprimary_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setimagerenderingintent, imagick_setimagerenderingintent_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setimagevirtualpixelmethod, imagick_setimagevirtualpixelmethod_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setimagewhitepoint, imagick_setimagewhitepoint_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, sigmoidalcontrastimage, imagick_sigmoidalcontrastimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, stereoimage, imagick_stereoimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, textureimage, imagick_textureimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, tintimage, imagick_tintimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, unsharpmaskimage, imagick_unsharpmaskimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getimage, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, addimage, imagick_addimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setimage, imagick_setimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, newimage, imagick_newimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, newpseudoimage, imagick_newpseudoimage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getcompression, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getcompressionquality, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getcopyright, imagick_zero_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getconfigureoptions, imagick_getconfigureoptions_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
//#if MagickLibVersion > 0x660
//	PHP_ME(imagick, getfeatures, imagick_zero_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
//#endif
//	PHP_ME(imagick, getfilename, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getformat, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, gethomeurl, imagick_zero_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getinterlacescheme, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getoption, imagick_getoption_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getpackagename, imagick_zero_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getpage, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getquantum, imagick_zero_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, gethdrienabled, imagick_zero_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getquantumdepth, imagick_zero_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getquantumrange, imagick_zero_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getreleasedate, imagick_zero_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getresource, imagick_getresource_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getresourcelimit, imagick_getresourcelimit_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getsamplingfactors, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getsize, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getversion, imagick_zero_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setbackgroundcolor, imagick_setbackgroundcolor_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setcompression, imagick_setcompression_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setcompressionquality, imagick_setcompressionquality_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setfilename, imagick_setfilename_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setformat, imagick_setformat_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setinterlacescheme, imagick_setinterlacescheme_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setoption, imagick_setoption_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setpage, imagick_setpage_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setresourcelimit, imagick_setresourcelimit_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setresolution, imagick_setresolution_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setsamplingfactors, imagick_setsamplingfactors_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, setsize, imagick_setsize_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, settype, imagick_settype_args, ZEND_ACC_PUBLIC)
//#if MagickLibVersion > 0x628
//	PHP_MALIAS(imagick, key, getiteratorindex, imagick_zero_args, ZEND_ACC_PUBLIC)
//#else
//# if defined(MAGICKCORE_EXCLUDE_DEPRECATED)
//#  error "MAGICKCORE_EXCLUDE_DEPRECATED should not be defined with ImageMagick version below 6.2.8"
//# else
//	PHP_MALIAS(imagick, key, getimageindex, imagick_zero_args, ZEND_ACC_PUBLIC)
//# endif
//#endif
//	PHP_MALIAS(imagick, next, nextimage, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_MALIAS(imagick, rewind, setfirstiterator, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, valid, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, current, imagick_zero_args, ZEND_ACC_PUBLIC)
//#if MagickLibVersion >= 0x659
//	PHP_ME(imagick, brightnesscontrastimage, imagick_brightnesscontrastimage_args, ZEND_ACC_PUBLIC)
//#endif
//#if MagickLibVersion > 0x661
//	PHP_ME(imagick, colormatriximage, imagick_colormatriximage_args, ZEND_ACC_PUBLIC)
//#endif
//	PHP_ME(imagick, selectiveblurimage, imagick_selectiveblurimage_args, ZEND_ACC_PUBLIC)
//#if MagickLibVersion >= 0x689
//	PHP_ME(imagick, rotationalblurimage, imagick_rotationalblurimage_args, ZEND_ACC_PUBLIC)
//#endif
//#if MagickLibVersion >= 0x683
//	PHP_ME(imagick, statisticimage, imagick_statisticimage_args, ZEND_ACC_PUBLIC)
//#endif
//#if MagickLibVersion >= 0x652
//	PHP_ME(imagick, subimagematch, imagick_subimagematch_args, ZEND_ACC_PUBLIC)
//	ZEND_MALIAS(imagick, similarityimage, subimagematch, imagick_subimagematch_args, ZEND_ACC_PUBLIC)
//#endif
//	PHP_ME(imagick, setregistry, imagick_setregistry_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getregistry, imagick_getregistry_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, listregistry, imagick_zero_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
//#if MagickLibVersion >= 0x680
//	PHP_ME(imagick, morphology, imagick_morphology_args, ZEND_ACC_PUBLIC)
//#if MagickLibVersion < 0x700
//	PHP_ME(imagick, filter, imagick_filter_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
//#endif // #if MagickLibVersion < 0x700
//#endif // #if MagickLibVersion >= 0x680
//	PHP_ME(imagick, setantialias, imagick_setantialias_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, getantialias, imagick_zero_args, ZEND_ACC_PUBLIC)
//#if MagickLibVersion > 0x676
//	PHP_ME(imagick, colordecisionlistimage, imagick_colordecisionlistimage_args, ZEND_ACC_PUBLIC)
//#endif // #if MagickLibVersion > 0x676
//#if MagickLibVersion >= 0x687
//	PHP_ME(imagick, optimizeimagetransparency, imagick_zero_args, ZEND_ACC_PUBLIC)
//#endif // #if MagickLibVersion >= 0x687
//#if MagickLibVersion >= 0x660
//	PHP_ME(imagick, autogammaimage, imagick_autogammaimage_args, ZEND_ACC_PUBLIC)
//#endif // #if MagickLibVersion >= 0x660
//#if MagickLibVersion >= 0x692
//	PHP_ME(imagick, autoorient, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagick, compositeimagegravity, imagick_compositeimagegravity_args, ZEND_ACC_PUBLIC)
//#endif // #if MagickLibVersion >= 0x692
//#if MagickLibVersion >= 0x693
//	PHP_ME(imagick, localcontrastimage, imagick_localContrastImage_args, ZEND_ACC_PUBLIC)
//#endif // #if MagickLibVersion >= 0x692
//#if MagickLibVersion >= 0x700
//	PHP_ME(imagick, identifyimagetype, imagick_zero_args, ZEND_ACC_PUBLIC)
//#endif // #if MagickLibVersion >= 0x700
//
//	{ NULL, NULL, NULL, 0, 0 }
//};

#include "Imagick_arginfo.h"

const zend_function_entry *php_imagick_class_methods = class_Imagick_methods;

#ifdef IMAGICK_WITH_KERNEL
//static zend_function_entry php_imagickkernel_class_methods[] =
//{
//	PHP_ME(imagickkernel, __construct, imagick_zero_args, ZEND_ACC_PRIVATE|ZEND_ACC_CTOR)
//	PHP_ME(imagickkernel, frommatrix, imagickkernel_frommatrix_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
//	PHP_ME(imagickkernel, frombuiltin, imagickkernel_frombuiltin_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
//	PHP_ME(imagickkernel, addkernel, imagickkernel_addkernel_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickkernel, getmatrix, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickkernel, separate, imagick_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickkernel, scale, imagickkernel_scale_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickkernel, addunitykernel, imagickkernel_addunitykernel_args, ZEND_ACC_PUBLIC)
//	{ NULL, NULL, NULL, 0, 0 }
//};

#include "ImagickKernel_arginfo.h"

const zend_function_entry *php_imagickkernel_class_methods = class_ImagickKernel_methods;

#endif

static void php_imagick_object_free_storage(IM_ZEND_OBJECT *object TSRMLS_DC)
{
	php_imagick_object *intern = php_imagick_fetch_object(object);

	if (!intern) {
		return;
	}

	if (intern->progress_monitor_name) {
		//TODO - is this meant to be free by us? 
		efree(intern->progress_monitor_name);
	}

	if (intern->magick_wand != NULL) {
		intern->magick_wand = DestroyMagickWand(intern->magick_wand);
	}

	zend_object_std_dtor(&intern->zo TSRMLS_CC);
#ifndef ZEND_ENGINE_3
	efree(intern);
#endif
}


static void php_imagickdraw_object_free_storage(IM_ZEND_OBJECT *object TSRMLS_DC)
{
	php_imagickdraw_object *intern = php_imagickdraw_fetch_object(object);

	if (!intern) {
		return;
	}

	if (intern->drawing_wand != NULL) {
		intern->drawing_wand = DestroyDrawingWand(intern->drawing_wand);
	}

	zend_object_std_dtor(&intern->zo TSRMLS_CC);

	#ifndef ZEND_ENGINE_3
		efree(intern);
	#endif
}

static void php_imagickpixeliterator_object_free_storage(IM_ZEND_OBJECT *object TSRMLS_DC)
{
	php_imagickpixeliterator_object *intern = php_imagickpixeliterator_fetch_object(object);

	if (!intern) {
		return;
	}

	if (intern->pixel_iterator != NULL) {
		intern->pixel_iterator = DestroyPixelIterator(intern->pixel_iterator);
	}

	zend_object_std_dtor(&intern->zo TSRMLS_CC);
	#ifndef ZEND_ENGINE_3
		efree(intern);
	#endif
}



static void php_imagickpixel_object_free_storage(IM_ZEND_OBJECT *object TSRMLS_DC)
{
	php_imagickpixel_object *intern = php_imagickpixel_fetch_object(object);

	if (!intern) {
		return;
	}
	if (!intern->initialized_via_iterator && intern->pixel_wand)
		intern->pixel_wand = DestroyPixelWand(intern->pixel_wand);

	zend_object_std_dtor(&intern->zo TSRMLS_CC);
	#ifndef ZEND_ENGINE_3
		efree(intern);
	#endif
}

#ifdef IMAGICK_WITH_KERNEL
static void php_imagickkernel_object_free_storage(IM_ZEND_OBJECT *object TSRMLS_DC)
{
	php_imagickkernel_object *intern = php_imagickkernel_fetch_object(object);

	if (!intern) {
		return;
	}

	if (intern->kernel_info != NULL) {
		// This segfaults in PHP 5.6
		//intern->kernel_info = DestroyKernelInfo(intern->kernel_info);
		intern->kernel_info = NULL;
	}

	zend_object_std_dtor(&intern->zo TSRMLS_CC);
#ifndef ZEND_ENGINE_3
	efree(intern);
#endif
}
#endif


#if PHP_VERSION_ID < 50399
# define object_properties_init(zo, class_type) { \
			zval *tmp; \
			zend_hash_copy((*zo).properties, \
							&class_type->default_properties, \
							(copy_ctor_func_t) zval_add_ref, \
							(void *) &tmp, \
							sizeof(zval *)); \
		 }
#endif

#ifdef ZEND_ENGINE_3
static zend_object * php_imagick_object_new_ex(zend_class_entry *class_type, php_imagick_object **ptr, zend_bool init_wand TSRMLS_DC)
#else
static zend_object_value php_imagick_object_new_ex(zend_class_entry *class_type, php_imagick_object **ptr, zend_bool init_wand TSRMLS_DC)
#endif

{
	php_imagick_object *intern;

	/* Allocate memory for it */
#ifdef ZEND_ENGINE_3
	intern = ecalloc(1,
		sizeof(php_imagick_object) +
		zend_object_properties_size(class_type));
#else
	zend_object_value retval;

	intern = (php_imagick_object *) emalloc(sizeof(php_imagick_object));
	memset(&intern->zo, 0, sizeof(zend_object));
#endif

#if defined(ZTS) && defined(PHP_WIN32)
	/* If its our thread then we already have the lock so no need to lock again */
	if (imagick_thread_id != tsrm_thread_id()) {
		tsrm_mutex_lock(imagick_mutex);
		imagick_thread_id = tsrm_thread_id();
	}
#endif

	if (ptr) {
		*ptr = intern;
	}

	/* Set the magickwand */
	if (init_wand) {
		intern->magick_wand = NewMagickWand();

		if (!intern->magick_wand) {
			zend_error(E_ERROR, "Failed to create Imagick object, could not set magick_wand");
		}
	} else {
		intern->magick_wand = NULL;
	}
	intern->next_out_of_bound = 0;
	intern->progress_monitor_name = NULL;

	zend_object_std_init(&intern->zo, class_type TSRMLS_CC);
	object_properties_init(&intern->zo, class_type);

#ifdef ZEND_ENGINE_3
	intern->zo.handlers = &imagick_object_handlers;
	return &intern->zo;
#else
	retval.handle = zend_objects_store_put(intern, NULL, (zend_objects_free_object_storage_t) php_imagick_object_free_storage, NULL TSRMLS_CC);
    retval.handlers = (zend_object_handlers *) &imagick_object_handlers;
    return retval;
#endif
}


#ifdef ZEND_ENGINE_3
static zend_object * php_imagick_object_new(zend_class_entry *class_type TSRMLS_DC)
#else
static zend_object_value php_imagick_object_new(zend_class_entry *class_type TSRMLS_DC)
#endif
{
	return php_imagick_object_new_ex(class_type, NULL, 1 TSRMLS_CC);
}

#ifdef ZEND_ENGINE_3
static zend_object * php_imagickdraw_object_new_ex(zend_class_entry *class_type, php_imagickdraw_object **ptr, zend_bool init_wand TSRMLS_DC)
#else
static zend_object_value php_imagickdraw_object_new_ex(zend_class_entry *class_type, php_imagickdraw_object **ptr, zend_bool init_wand TSRMLS_DC)
#endif
{
	php_imagickdraw_object *intern;

#ifdef ZEND_ENGINE_3
	/* Allocate memory for it */
	intern = ecalloc(1,
		sizeof(php_imagickdraw_object) +
		zend_object_properties_size(class_type));

	zend_object_std_init(&intern->zo, class_type TSRMLS_CC);
	object_properties_init(&intern->zo, class_type);
	intern->zo.handlers = &imagickdraw_object_handlers;
#else
	zend_object_value retval;
	intern = (php_imagickdraw_object *) emalloc(sizeof(php_imagickdraw_object));
	memset(&intern->zo, 0, sizeof(zend_object));
#endif

	if (ptr) {
		*ptr = intern;
	}

	/* Set the DrawingWand */
	if (init_wand) {
		intern->drawing_wand = NewDrawingWand();

		if (!intern->drawing_wand) {
			zend_error(E_ERROR, "Failed to create ImagickDraw object");
		}
	} else {
		intern->drawing_wand = NULL;
	}
#ifdef ZEND_ENGINE_3
	intern->zo.handlers = &imagickdraw_object_handlers;

	return &intern->zo;
#else
	/* ALLOC_HASHTABLE(intern->zo.properties); */
	zend_object_std_init(&intern->zo, class_type TSRMLS_CC);
	object_properties_init(&intern->zo, class_type);
	retval.handle = zend_objects_store_put(intern, NULL, (zend_objects_free_object_storage_t) php_imagickdraw_object_free_storage, NULL TSRMLS_CC);
	retval.handlers = (zend_object_handlers *) &imagickdraw_object_handlers;

	return retval;
#endif
}

#ifdef ZEND_ENGINE_3
static zend_object * php_imagickdraw_object_new(zend_class_entry *class_type TSRMLS_DC)
#else
static zend_object_value php_imagickdraw_object_new(zend_class_entry *class_type TSRMLS_DC)
#endif
{
	return php_imagickdraw_object_new_ex(class_type, NULL, 1 TSRMLS_CC);
}

#ifdef ZEND_ENGINE_3
static zend_object * php_imagickpixeliterator_object_new(zend_class_entry *class_type TSRMLS_DC)
#else
static zend_object_value php_imagickpixeliterator_object_new(zend_class_entry *class_type TSRMLS_DC)
#endif
{
	php_imagickpixeliterator_object *intern;

	/* Allocate memory for it */
#ifdef ZEND_ENGINE_3
	intern = ecalloc(1,
			sizeof(php_imagickpixeliterator_object) +
			zend_object_properties_size(class_type));
#else
	zend_object_value retval;
	intern = (php_imagickpixeliterator_object *) emalloc(sizeof(php_imagickpixeliterator_object));
	memset(&intern->zo, 0, sizeof(zend_object));
#endif

	/* We cant initialize yet */
	intern->pixel_iterator = NULL;
	intern->initialized    = 0;

#if MagickLibVersion <= 0x628
	intern->rows = 0;
	intern->iterator_position = 0;
#endif

	zend_object_std_init(&intern->zo, class_type TSRMLS_CC);
	object_properties_init(&intern->zo, class_type);

#ifdef ZEND_ENGINE_3
	intern->zo.handlers = &imagickpixeliterator_object_handlers;

	return &intern->zo;
#else
	retval.handle = zend_objects_store_put(intern, NULL, (zend_objects_free_object_storage_t) php_imagickpixeliterator_object_free_storage, NULL TSRMLS_CC);
	retval.handlers = (zend_object_handlers *) &imagickpixeliterator_object_handlers;

	return retval;
#endif
}

#ifdef ZEND_ENGINE_3
static zend_object * php_imagickpixel_object_new_ex(zend_class_entry *class_type, php_imagickpixel_object **ptr TSRMLS_DC)
#else
static zend_object_value php_imagickpixel_object_new_ex(zend_class_entry *class_type, php_imagickpixel_object **ptr TSRMLS_DC)
#endif
{
	php_imagickpixel_object *intern;

#ifdef ZEND_ENGINE_3
	/* Allocate memory for it */
	intern = ecalloc(1,
		sizeof(php_imagickpixel_object) +
		zend_object_properties_size(class_type));
#else
	zend_object_value retval;
	intern = (php_imagickpixel_object *) emalloc(sizeof(php_imagickpixel_object));
	memset(&intern->zo, 0, sizeof(zend_object));
#endif

	if (ptr) {
		*ptr = intern;
	}

	/* Set the pixeliterator */
	intern->pixel_wand = NULL;
	intern->initialized_via_iterator = 0;
	zend_object_std_init(&intern->zo, class_type TSRMLS_CC);
	object_properties_init(&intern->zo, class_type);
	
#ifdef ZEND_ENGINE_3
	intern->zo.handlers = &imagickpixel_object_handlers;

	return &intern->zo;
#else
	retval.handle = zend_objects_store_put(intern, NULL, (zend_objects_free_object_storage_t) php_imagickpixel_object_free_storage, NULL TSRMLS_CC);
	retval.handlers = (zend_object_handlers *) &imagickpixel_object_handlers;

	return retval;
#endif

}

#ifdef ZEND_ENGINE_3
static zend_object * php_imagickpixel_object_new(zend_class_entry *class_type TSRMLS_DC)
#else
static zend_object_value php_imagickpixel_object_new(zend_class_entry *class_type TSRMLS_DC)
#endif
{
	return php_imagickpixel_object_new_ex(class_type, NULL TSRMLS_CC);
}

#ifdef IMAGICK_WITH_KERNEL

#ifdef ZEND_ENGINE_3
static zend_object *  php_imagickkernel_object_new_ex(zend_class_entry *class_type, php_imagickkernel_object **ptr TSRMLS_DC)
#else
static zend_object_value php_imagickkernel_object_new_ex(zend_class_entry *class_type, php_imagickkernel_object **ptr TSRMLS_DC)
#endif
{

	php_imagickkernel_object *intern;

	/* Allocate memory for it */
#ifdef ZEND_ENGINE_3
	intern = ecalloc(1,
		sizeof(php_imagickkernel_object) +
		zend_object_properties_size(class_type));
#else
	zend_object_value retval;
	intern = (php_imagickkernel_object *) emalloc(sizeof(php_imagickkernel_object));
		memset(&intern->zo, 0, sizeof(zend_object));
#endif

	if (ptr) {
		*ptr = intern;
	}

	/* Set the kernel */
	intern->kernel_info = NULL;

	/* ALLOC_HASHTABLE(intern->zo.properties); */
	zend_object_std_init(&intern->zo, class_type TSRMLS_CC);
	object_properties_init(&intern->zo, class_type);

#ifdef ZEND_ENGINE_3
	intern->zo.handlers = &imagickkernel_object_handlers;

	return &intern->zo;
#else
	retval.handle = zend_objects_store_put(intern, NULL, (zend_objects_free_object_storage_t) php_imagickkernel_object_free_storage, NULL TSRMLS_CC);
	retval.handlers = (zend_object_handlers *) &imagickkernel_object_handlers;

	return retval;
#endif
}
#endif

#undef object_properties_init

#ifdef IMAGICK_WITH_KERNEL
#ifdef ZEND_ENGINE_3
static zend_object * php_imagickkernel_object_new(zend_class_entry *class_type TSRMLS_DC)
#else
static zend_object_value php_imagickkernel_object_new(zend_class_entry *class_type TSRMLS_DC)
#endif
{
	return php_imagickkernel_object_new_ex(class_type, NULL TSRMLS_CC);
}
#endif



PHP_INI_BEGIN()
	STD_PHP_INI_ENTRY("imagick.locale_fix", "0", PHP_INI_ALL, OnUpdateBool, locale_fix, zend_imagick_globals, imagick_globals)
	STD_PHP_INI_ENTRY("imagick.skip_version_check", "0", PHP_INI_ALL, OnUpdateBool, skip_version_check, zend_imagick_globals, imagick_globals)
	STD_PHP_INI_ENTRY("imagick.progress_monitor", "0", PHP_INI_SYSTEM, OnUpdateBool, progress_monitor, zend_imagick_globals, imagick_globals)

	STD_PHP_INI_ENTRY("imagick.set_single_thread", "0", PHP_INI_SYSTEM, OnUpdateBool, set_single_thread, zend_imagick_globals, imagick_globals)
	STD_PHP_INI_ENTRY("imagick.shutdown_sleep_count",  "10", PHP_INI_ALL, OnUpdateLong, shutdown_sleep_count, zend_imagick_globals, imagick_globals)

PHP_INI_END()

static void php_imagick_init_globals(zend_imagick_globals *imagick_globals)
{
	imagick_globals->locale_fix = 0;
	imagick_globals->progress_monitor = 0;
	imagick_globals->skip_version_check = 0;
	imagick_globals->set_single_thread = 0;
	// 10 is magick number, that seems to be enough.
	imagick_globals->shutdown_sleep_count = 10;
}


#if PHP_VERSION_ID >= 80000
static int php_imagick_count_elements(zend_object *object, im_long *count) /* {{{ */
{
	php_imagick_object *intern= php_imagick_fetch_object(object);
#else
static int php_imagick_count_elements(zval *object, im_long *count TSRMLS_DC) /* {{{ */
{
	php_imagick_object *intern= Z_IMAGICK_P(object);
#endif

	if (intern->magick_wand) {
		*count = MagickGetNumberImages(intern->magick_wand);
		return SUCCESS;
	}
	return FAILURE;
}


#if PHP_VERSION_ID >= 80000
static zval *php_imagick_read_property(zend_object *object, zend_string *member, int type, void **cache_slot, zval *rv)
{
	int ret;
	php_imagick_object *intern;
	zval *retval = NULL;
    const zend_object_handlers *std_hnd;


	std_hnd = zend_get_std_object_handlers();

	ret = std_hnd->has_property(object, member, type, cache_slot TSRMLS_CC);

	if (ret) {
		//TODO - this would allow better immutability
		//ZVAL_COPY_VALUE(retval, std_hnd->read_property(object, member, type, cache_slot, rv TSRMLS_CC));
		retval = std_hnd->read_property(object, member, type, cache_slot, rv TSRMLS_CC);
	}
	else {

		intern = php_imagick_fetch_object(object);
		/* Do we have any images? */
		if (MagickGetNumberImages(intern->magick_wand)) {

			//TODO - this seems redundant
			/* Is this overloaded? */
			if (!strcmp(ZSTR_VAL(member), "width") ||
				!strcmp(ZSTR_VAL(member), "height") ||
				!strcmp(ZSTR_VAL(member), "format")) {

				if (!strcmp(ZSTR_VAL(member), "width")) {
					retval = rv;
					ZVAL_LONG(retval, MagickGetImageWidth(intern->magick_wand));
				} else if (!strcmp(ZSTR_VAL(member), "height")) {
					retval = rv;
					ZVAL_LONG(retval, MagickGetImageHeight(intern->magick_wand));
				} else if (!strcmp(ZSTR_VAL(member), "format")) {
					char *format = MagickGetImageFormat(intern->magick_wand);

					if (format) {
						retval = rv;
						ZVAL_STRING(retval, format);
						IMAGICK_FREE_MAGICK_MEMORY(format);
					} else {
						retval = rv;
						ZVAL_STRING(retval, "");
					}
				}
			}
		}
	}

	if (!retval) {
		//TODO - why is the error silent - it would be a small BC break
		//to enable the warning. I think it would be the correct thing to do though.
		//zend_error(E_NOTICE,"Undefined property: \Imagick::$%s", Z_STRVAL_P(member));
		retval = &EG(uninitialized_zval);
	}

	return retval;
}

#else // PHP_VERSION_ID >= 80000

#ifdef ZEND_ENGINE_3
static zval *php_imagick_read_property(zval *object, zval *member, int type, void **cache_slot, zval *rv TSRMLS_DC)
{
	int ret;
	php_imagick_object *intern;
	zval *retval = NULL;
	zval tmp_member;
    const zend_object_handlers *std_hnd;

	ZVAL_DEREF(member);
	if (Z_TYPE_P(member) != IS_STRING) {
		tmp_member = *member;
		zval_copy_ctor(&tmp_member);
		convert_to_string(&tmp_member);
		member = &tmp_member;
    }

	std_hnd = zend_get_std_object_handlers();

	ret = std_hnd->has_property(object, member, type, cache_slot TSRMLS_CC);

	if (ret) {
		//TODO - this would allow better immutability
		//ZVAL_COPY_VALUE(retval, std_hnd->read_property(object, member, type, cache_slot, rv TSRMLS_CC));
		retval = std_hnd->read_property(object, member, type, cache_slot, rv TSRMLS_CC);
	}
	else {

		intern = Z_IMAGICK_P(object);
		/* Do we have any images? */
		if (MagickGetNumberImages(intern->magick_wand)) {

			//TODO - this seems redundant
			/* Is this overloaded? */
			if (!strcmp(Z_STRVAL_P(member), "width") ||
				!strcmp(Z_STRVAL_P(member), "height") ||
				!strcmp(Z_STRVAL_P(member), "format")) {

				if (!strcmp(Z_STRVAL_P(member), "width")) {
					retval = rv;
					ZVAL_LONG(retval, MagickGetImageWidth(intern->magick_wand));
				} else if (!strcmp(Z_STRVAL_P(member), "height")) {
					retval = rv;
					ZVAL_LONG(retval, MagickGetImageHeight(intern->magick_wand));
				} else if (!strcmp(Z_STRVAL_P(member), "format")) {
					char *format = MagickGetImageFormat(intern->magick_wand);

					if (format) {
						retval = rv;
						ZVAL_STRING(retval, format);
						IMAGICK_FREE_MAGICK_MEMORY(format);
					} else {
						retval = rv;
						ZVAL_STRING(retval, "");
					}
				}
			}
		}
	}

	if (!retval) {
		//TODO - why is the error silent - it would be a small BC break
		//to enable the warning. I think it would be the correct thing to do though.
		//zend_error(E_NOTICE,"Undefined property: \Imagick::$%s", Z_STRVAL_P(member));
		retval = &EG(uninitialized_zval);
	}

	if (member == &tmp_member) {
		zval_dtor(member);
	}

	return retval;
}

#else

#if PHP_VERSION_ID < 50399
static zval *php_imagick_read_property(zval *object, zval *member, int type TSRMLS_DC)
#else
static zval *php_imagick_read_property(zval *object, zval *member, int type, const zend_literal *key TSRMLS_DC)
#endif
{
	int ret;
	php_imagick_object *intern;
	zval *retval = NULL, tmp_member;
    zend_object_handlers *std_hnd;

	if (Z_TYPE_P(member) != IS_STRING) {
		tmp_member = *member;
		zval_copy_ctor(&tmp_member);
		convert_to_string(&tmp_member);
		member = &tmp_member;
    }

	std_hnd = zend_get_std_object_handlers();
#if PHP_VERSION_ID < 50399
	ret = std_hnd->has_property(object, member, 2 TSRMLS_CC);
#else
	ret = std_hnd->has_property(object, member, 2, key TSRMLS_CC);
#endif	

	if (ret) {
		std_hnd = zend_get_std_object_handlers();
#if PHP_VERSION_ID < 50399
		retval = std_hnd->read_property(object, member, type TSRMLS_CC);
#else
		retval = std_hnd->read_property(object, member, type, key TSRMLS_CC);
#endif
	} else {
		intern = (php_imagick_object *) zend_object_store_get_object(object TSRMLS_CC);
		/* Do we have any images? */
		if (MagickGetNumberImages(intern->magick_wand)) {
			/* Is this overloaded? */
			if (!strcmp(Z_STRVAL_P(member), "width") ||
				!strcmp(Z_STRVAL_P(member), "height") ||
				!strcmp(Z_STRVAL_P(member), "format")) {

				MAKE_STD_ZVAL(retval);
#ifdef Z_SET_REFCOUNT_P
				Z_SET_REFCOUNT_P(retval, 0);
#else
				retval->refcount = 0;
#endif
				if (!strcmp(Z_STRVAL_P(member), "width")) {
					ZVAL_LONG(retval, MagickGetImageWidth(intern->magick_wand));
				} else if (!strcmp(Z_STRVAL_P(member), "height")) {
					ZVAL_LONG(retval, MagickGetImageHeight(intern->magick_wand));
				} else if (!strcmp(Z_STRVAL_P(member), "format")) {
					char *format = MagickGetImageFormat(intern->magick_wand);

					if (format) {
						ZVAL_STRING(retval, format, 1);
						IMAGICK_FREE_MAGICK_MEMORY(format);
					} else {
						ZVAL_STRING(retval, "", 1);
					}
				}
			}
		}
	}
	if (member == &tmp_member) {
    	zval_dtor(member);
    }

	if (!retval) {
		retval = EG(uninitialized_zval_ptr);
	}
	return retval;
}
#endif

#endif

#if PHP_VERSION_ID >= 80000
static zend_object * php_imagick_clone_imagick_object(zend_object *this_ptr)
#elif PHP_VERSION_ID >= 70000
static zend_object * php_imagick_clone_imagick_object(zval *this_ptr TSRMLS_DC)
#else
static zend_object_value php_imagick_clone_imagick_object(zval *this_ptr TSRMLS_DC)
#endif
{
	MagickWand *wand_copy = NULL;
	php_imagick_object *new_obj = NULL;
#if PHP_VERSION_ID >= 80000
	php_imagick_object *old_obj = php_imagick_fetch_object(this_ptr);
	zend_object * new_zo = php_imagick_object_new_ex(old_obj->zo.ce, &new_obj, 0 TSRMLS_CC);
	zend_objects_clone_members(&new_obj->zo, &old_obj->zo TSRMLS_CC);
#elif PHP_VERSION_ID >= 70000
	php_imagick_object *old_obj = Z_IMAGICK_P(this_ptr);
	zend_object * new_zo = php_imagick_object_new_ex(old_obj->zo.ce, &new_obj, 0 TSRMLS_CC);
	zend_objects_clone_members(&new_obj->zo, &old_obj->zo TSRMLS_CC);
#else
	php_imagick_object *old_obj = (php_imagick_object *) zend_object_store_get_object(this_ptr TSRMLS_CC);
	zend_object_value new_zo = php_imagick_object_new_ex(old_obj->zo.ce, &new_obj, 0 TSRMLS_CC);
	zend_objects_clone_members(&new_obj->zo, new_zo, &old_obj->zo, Z_OBJ_HANDLE_P(this_ptr) TSRMLS_CC);
#endif

	wand_copy = CloneMagickWand(old_obj->magick_wand);
	if (!wand_copy) {
		zend_error(E_ERROR, "Failed to clone Imagick object");
	} else {
		php_imagick_replace_magickwand(new_obj, wand_copy);
		new_obj->next_out_of_bound = old_obj->next_out_of_bound;

		if (old_obj->progress_monitor_name) {
			new_obj->progress_monitor_name = estrdup(old_obj->progress_monitor_name);
		}
	}
	return new_zo;
}

#if PHP_VERSION_ID >= 80000
static zend_object * php_imagick_clone_imagickdraw_object(zend_object *this_ptr)
#elif PHP_VERSION_ID >= 70000
static zend_object * php_imagick_clone_imagickdraw_object(zval *this_ptr TSRMLS_DC)
#else
static zend_object_value php_imagick_clone_imagickdraw_object(zval *this_ptr TSRMLS_DC)
#endif
{
	DrawingWand *wand_copy = NULL;
	php_imagickdraw_object *new_obj = NULL;
#if PHP_VERSION_ID >= 80000
	php_imagickdraw_object *old_obj = php_imagickdraw_fetch_object(this_ptr);
	zend_object * new_zo = php_imagickdraw_object_new_ex(old_obj->zo.ce, &new_obj, 0 TSRMLS_CC);
	zend_objects_clone_members(&new_obj->zo, &old_obj->zo TSRMLS_CC);
#elif PHP_VERSION_ID >= 70000
	php_imagickdraw_object *old_obj = Z_IMAGICKDRAW_P(this_ptr);
	zend_object * new_zo = php_imagickdraw_object_new_ex(old_obj->zo.ce, &new_obj, 0 TSRMLS_CC);
	zend_objects_clone_members(&new_obj->zo, &old_obj->zo TSRMLS_CC);
#else
	php_imagickdraw_object *old_obj = (php_imagickdraw_object *) zend_object_store_get_object(this_ptr TSRMLS_CC);
	zend_object_value new_zo = php_imagickdraw_object_new_ex(old_obj->zo.ce, &new_obj, 0 TSRMLS_CC);
	zend_objects_clone_members(&new_obj->zo, new_zo, &old_obj->zo, Z_OBJ_HANDLE_P(this_ptr) TSRMLS_CC);
#endif

	wand_copy = CloneDrawingWand(old_obj->drawing_wand);

	if (!wand_copy) {
		zend_error(E_ERROR, "Failed to clone ImagickDraw object");
	} else {
		php_imagick_replace_drawingwand(new_obj, wand_copy);
	}
	return new_zo;
}


#if PHP_VERSION_ID >= 80000
static zend_object * php_imagick_clone_imagickpixel_object(zend_object *this_ptr)
#elif PHP_VERSION_ID >= 70000
static zend_object * php_imagick_clone_imagickpixel_object(zval *this_ptr TSRMLS_DC)
#else
static zend_object_value php_imagick_clone_imagickpixel_object(zval *this_ptr TSRMLS_DC)
#endif
{
	PixelWand *wand_copy = NULL;
	php_imagickpixel_object *new_obj = NULL;

#if PHP_VERSION_ID >= 80000
	zend_object *new_zo;
	php_imagickpixel_object *old_obj = php_imagickpixel_fetch_object(this_ptr);
	new_zo = php_imagickpixel_object_new_ex(old_obj->zo.ce, &new_obj TSRMLS_CC);
	zend_objects_clone_members(&new_obj->zo, &old_obj->zo TSRMLS_CC);
#elif PHP_VERSION_ID >= 70000
	zend_object *new_zo;
	php_imagickpixel_object *old_obj = Z_IMAGICKPIXEL_P(this_ptr);
	new_zo = php_imagickpixel_object_new_ex(old_obj->zo.ce, &new_obj TSRMLS_CC);
	zend_objects_clone_members(&new_obj->zo, &old_obj->zo TSRMLS_CC);
#else
	php_imagickpixel_object *old_obj = (php_imagickpixel_object *) zend_object_store_get_object(this_ptr TSRMLS_CC);
	zend_object_value new_zo = php_imagickpixel_object_new_ex(old_obj->zo.ce, &new_obj TSRMLS_CC);
	zend_objects_clone_members(&new_obj->zo, new_zo, &old_obj->zo, Z_OBJ_HANDLE_P(this_ptr) TSRMLS_CC);
#endif

	wand_copy = php_imagick_clone_pixelwand (old_obj->pixel_wand);
	if (!wand_copy) {
		zend_error(E_ERROR, "Failed to clone ImagickPixel object");
	} else {
		php_imagick_replace_pixelwand(new_obj, wand_copy);
		new_obj->initialized_via_iterator = 0;
	}
	return new_zo;
}

#ifdef IMAGICK_WITH_KERNEL

#if PHP_VERSION_ID >= 80000
static zend_object * php_imagick_clone_imagickkernel_object(zend_object *this_ptr TSRMLS_DC)
#elif PHP_VERSION_ID >= 70000
static zend_object * php_imagick_clone_imagickkernel_object(zval *this_ptr TSRMLS_DC)
#else
static zend_object_value php_imagick_clone_imagickkernel_object(zval *this_ptr TSRMLS_DC)
#endif
{
	KernelInfo *kernel_info_copy = NULL;
	php_imagickkernel_object *new_obj = NULL;

#if PHP_VERSION_ID >= 80000
	zend_object *new_zo;
	php_imagickkernel_object *old_obj = php_imagickkernel_fetch_object(this_ptr);
	new_zo = php_imagickkernel_object_new_ex(old_obj->zo.ce, &new_obj TSRMLS_CC);
	zend_objects_clone_members(&new_obj->zo, &old_obj->zo TSRMLS_CC);
#elif PHP_VERSION_ID >= 70000
	zend_object *new_zo;
	php_imagickkernel_object *old_obj = Z_IMAGICKKERNEL_P(this_ptr);
	new_zo = php_imagickkernel_object_new_ex(old_obj->zo.ce, &new_obj TSRMLS_CC);
	zend_objects_clone_members(&new_obj->zo, &old_obj->zo TSRMLS_CC);
#else
	zend_object_value new_zo;
	php_imagickkernel_object *old_obj = (php_imagickkernel_object *) zend_object_store_get_object(this_ptr TSRMLS_CC);
	new_zo = php_imagickkernel_object_new_ex(old_obj->zo.ce, &new_obj TSRMLS_CC);
	zend_objects_clone_members(&new_obj->zo, new_zo, &old_obj->zo, Z_OBJ_HANDLE_P(this_ptr) TSRMLS_CC);
#endif

	if (old_obj->kernel_info != NULL) {
		kernel_info_copy = CloneKernelInfo(old_obj->kernel_info);

		if (!kernel_info_copy) {
			zend_error(E_ERROR, "Failed to clone ImagickKernel object");
		}
		else {
			new_obj->kernel_info = kernel_info_copy;
		}
	}

	return new_zo;
}
#endif


static void checkImagickVersion()
{
	//This gets the version that Imagick was compiled against.
	size_t imagickVersion = MagickLibVersion;

	//This gets the version of ImageMagick that has been loaded
	size_t imageMagickLibraryVersion;

	GetMagickVersion(&imageMagickLibraryVersion);

	if (imagickVersion == imageMagickLibraryVersion) {
		return;
	}

	zend_error(
		E_WARNING,
		"Version warning: Imagick was compiled against ImageMagick version %lu but version %lu is loaded. Imagick will run but may behave surprisingly",
		(unsigned long)imagickVersion,
		(unsigned long)imageMagickLibraryVersion
	);
}

PHP_MINIT_FUNCTION(imagick)
{
	zend_class_entry ce;

	/* Initialize globals */
	ZEND_INIT_MODULE_GLOBALS(imagick, php_imagick_init_globals, NULL);


	// This suppresses an 'unused parameter' warning.
	(void)type;

	/*
		Allocate some memory
	*/
	memcpy(&imagick_object_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
	memcpy(&imagickdraw_object_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
	memcpy(&imagickpixeliterator_object_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
	memcpy(&imagickpixel_object_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
#ifdef IMAGICK_WITH_KERNEL
	memcpy(&imagickkernel_object_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
#endif

	/* Set custom allocators */
	MagickWandGenesis();

	/*
		Initialize exceptions (Imagick exception)
	*/
	INIT_CLASS_ENTRY(ce, PHP_IMAGICK_EXCEPTION_SC_NAME, NULL);
#ifdef ZEND_ENGINE_3
	php_imagick_exception_class_entry = zend_register_internal_class_ex(&ce, zend_ce_exception);
#else
	php_imagick_exception_class_entry = zend_register_internal_class_ex(&ce, zend_exception_get_default(TSRMLS_C), NULL TSRMLS_CC);
#endif

	/*
	Initialize exceptions (ImagickDraw exception)
	*/
	INIT_CLASS_ENTRY(ce, PHP_IMAGICKDRAW_EXCEPTION_SC_NAME, NULL);
#ifdef ZEND_ENGINE_3
	php_imagickdraw_exception_class_entry = zend_register_internal_class_ex(&ce, zend_ce_exception);
#else
	php_imagickdraw_exception_class_entry = zend_register_internal_class_ex(&ce, zend_exception_get_default(TSRMLS_C), NULL TSRMLS_CC);
#endif

	/*
	Initialize exceptions (ImagickPixelIterator exception)
	*/
	INIT_CLASS_ENTRY(ce, PHP_IMAGICKPIXELITERATOR_EXCEPTION_SC_NAME, NULL);
#ifdef ZEND_ENGINE_3
	php_imagickpixeliterator_exception_class_entry = zend_register_internal_class_ex(&ce, zend_ce_exception);
#else
	php_imagickpixeliterator_exception_class_entry = zend_register_internal_class_ex(&ce, zend_exception_get_default(TSRMLS_C), NULL TSRMLS_CC);
#endif

	/*
	Initialize exceptions (ImagickPixel exception)
	*/
	INIT_CLASS_ENTRY(ce, PHP_IMAGICKPIXEL_EXCEPTION_SC_NAME, NULL);
#ifdef ZEND_ENGINE_3
	php_imagickpixel_exception_class_entry = zend_register_internal_class_ex(&ce, zend_ce_exception);
#else
	php_imagickpixel_exception_class_entry = zend_register_internal_class_ex(&ce, zend_exception_get_default(TSRMLS_C), NULL TSRMLS_CC);
#endif

#ifdef IMAGICK_WITH_KERNEL
	/*
	Initialize exceptions (ImagickKernel exception)
	*/
	INIT_CLASS_ENTRY(ce, PHP_IMAGICKKERNEL_EXCEPTION_SC_NAME, NULL);
	#ifdef ZEND_ENGINE_3
	php_imagickkernel_exception_class_entry = zend_register_internal_class_ex(&ce, zend_ce_exception);
    #else
	php_imagickkernel_exception_class_entry = zend_register_internal_class_ex(&ce, zend_exception_get_default(TSRMLS_C), NULL TSRMLS_CC);
    #endif

#endif

	/*
		Initialize the class (Imagick)
	*/
	INIT_CLASS_ENTRY(ce, PHP_IMAGICK_SC_NAME, php_imagick_class_methods);
	ce.create_object = php_imagick_object_new;
	imagick_object_handlers.clone_obj = php_imagick_clone_imagick_object;
	imagick_object_handlers.read_property = php_imagick_read_property;
	imagick_object_handlers.count_elements = php_imagick_count_elements;
#ifdef ZEND_ENGINE_3
	imagick_object_handlers.offset = XtOffsetOf(php_imagick_object, zo);
	imagick_object_handlers.free_obj = php_imagick_object_free_storage;
#endif

	php_imagick_sc_entry = zend_register_internal_class(&ce TSRMLS_CC);
#if defined(HAVE_SPL)
	zend_class_implements(php_imagick_sc_entry TSRMLS_CC, 2, zend_ce_iterator, spl_ce_Countable);
#else
	zend_class_implements(php_imagick_sc_entry TSRMLS_CC, 1, zend_ce_iterator);
#endif

	/*
		Initialize the class (ImagickDraw)
	*/
	INIT_CLASS_ENTRY(ce, PHP_IMAGICKDRAW_SC_NAME, php_imagickdraw_class_methods);
	ce.create_object = php_imagickdraw_object_new;
	imagickdraw_object_handlers.clone_obj = php_imagick_clone_imagickdraw_object;
#ifdef ZEND_ENGINE_3
	imagickdraw_object_handlers.offset = XtOffsetOf(php_imagickdraw_object, zo);
	imagickdraw_object_handlers.free_obj = php_imagickdraw_object_free_storage;
#endif
	php_imagickdraw_sc_entry = zend_register_internal_class(&ce TSRMLS_CC);

	/*
		Initialize the class (ImagickPixelIterator)
	*/
	INIT_CLASS_ENTRY(ce, PHP_IMAGICKPIXELITERATOR_SC_NAME, php_imagickpixeliterator_class_methods);
	ce.create_object = php_imagickpixeliterator_object_new;
	imagickpixeliterator_object_handlers.clone_obj = NULL;
#ifdef ZEND_ENGINE_3
	imagickpixeliterator_object_handlers.offset = XtOffsetOf(php_imagickpixeliterator_object, zo);
	imagickpixeliterator_object_handlers.free_obj = php_imagickpixeliterator_object_free_storage;
#endif
	php_imagickpixeliterator_sc_entry = zend_register_internal_class(&ce TSRMLS_CC);
	zend_class_implements(php_imagickpixeliterator_sc_entry TSRMLS_CC, 1, zend_ce_iterator);

	/*
		Initialize the class (ImagickPixel)
	*/
	INIT_CLASS_ENTRY(ce, PHP_IMAGICKPIXEL_SC_NAME, php_imagickpixel_class_methods);
	ce.create_object = php_imagickpixel_object_new;
	imagickpixel_object_handlers.clone_obj = php_imagick_clone_imagickpixel_object;
#ifdef ZEND_ENGINE_3
	imagickpixel_object_handlers.offset = XtOffsetOf(php_imagickpixel_object, zo);
	imagickpixel_object_handlers.free_obj = php_imagickpixel_object_free_storage;
#endif

	php_imagickpixel_sc_entry = zend_register_internal_class(&ce TSRMLS_CC);

#ifdef IMAGICK_WITH_KERNEL
	/*
		Initialize the class (ImagickKernel)
	*/
	INIT_CLASS_ENTRY(ce, PHP_IMAGICKKERNEL_SC_NAME, php_imagickkernel_class_methods);
	ce.create_object = php_imagickkernel_object_new;
	// Disabled until can be compiled under wall correctly
	imagickkernel_object_handlers.get_debug_info = php_imagickkernel_get_debug_info;
	imagickkernel_object_handlers.clone_obj = php_imagick_clone_imagickkernel_object;
	#ifdef ZEND_ENGINE_3
	imagickkernel_object_handlers.offset = XtOffsetOf(php_imagickkernel_object, zo);
	imagickkernel_object_handlers.free_obj = php_imagickkernel_object_free_storage;
    #endif

	php_imagickkernel_sc_entry = zend_register_internal_class(&ce TSRMLS_CC);
#endif

	php_imagick_initialize_constants (TSRMLS_C);

#if defined(ZTS) && defined(PHP_WIN32)
	imagick_mutex = tsrm_mutex_alloc();
#endif

	REGISTER_INI_ENTRIES();

	if (!IMAGICK_G(skip_version_check)) {
		checkImagickVersion();
	}

	if (IMAGICK_G(set_single_thread)) {
		MagickSetResourceLimit(ThreadResource, 1);
	}

	return SUCCESS;
}


PHP_MINFO_FUNCTION(imagick)
{

#ifdef ZEND_ENGINE_3
	smart_string formats = {0};
#else
	smart_str formats = {0};
#endif

	char **supported_formats, *buffer;
	unsigned long i;
	size_t num_formats;
	size_t version_number;

	num_formats = 0;

	supported_formats = MagickQueryFormats("*", &num_formats);
	spprintf(&buffer, 0, "%ld", (long)num_formats);

	php_info_print_table_start();
	php_info_print_table_header(2, "imagick module", "enabled");
	php_info_print_table_row(2, "imagick module version", PHP_IMAGICK_VERSION);
#ifdef IMAGICK_WITH_KERNEL
	php_info_print_table_row(2, "imagick classes", "Imagick, ImagickDraw, ImagickPixel, ImagickPixelIterator, ImagickKernel");
#else
	php_info_print_table_row(2, "imagick classes", "Imagick, ImagickDraw, ImagickPixel, ImagickPixelIterator");
#endif
#ifdef MagickVersion
	php_info_print_table_row(2, "Imagick compiled with ImageMagick version", MagickVersion);
#endif
	php_info_print_table_row(2, "Imagick using ImageMagick library version", MagickGetVersion(&version_number));
	php_info_print_table_row(2, "ImageMagick copyright", MagickGetCopyright());
	php_info_print_table_row(2, "ImageMagick release date", MagickGetReleaseDate());
	php_info_print_table_row(2, "ImageMagick number of supported formats: ", buffer);

	efree (buffer);

	if (supported_formats) {
		for (i = 0; i < num_formats; i++) {
#ifdef ZEND_ENGINE_3
			if (i != 0) {
 				smart_string_appends(&formats, ", ");
			}
			smart_string_appends(&formats, supported_formats[i]);
#else
			smart_str_appends(&formats, supported_formats[i]);
			if (i != (num_formats - 1)) {
				smart_str_appends(&formats, ", ");
			}
#endif
			IMAGICK_FREE_MAGICK_MEMORY(supported_formats[i]);
		}
		
#ifdef ZEND_ENGINE_3
		smart_string_0(&formats);
		php_info_print_table_row(2, "ImageMagick supported formats", formats.c);
		smart_string_free(&formats);
#else
		smart_str_0(&formats);
		php_info_print_table_row(2, "ImageMagick supported formats", formats.c);
		smart_str_free(&formats);
#endif
		IMAGICK_FREE_MAGICK_MEMORY(supported_formats);
	}

	php_info_print_table_end();
	DISPLAY_INI_ENTRIES();
}


PHP_MSHUTDOWN_FUNCTION(imagick)
{
    int i;

// This suppresses an 'unused parameter' warning.
	(void)type;

	MagickWandTerminus();

    // Sleep for a bit to hopefully allow OpenMP to
    // shut down the threads it created, and avoid a segfault
    // This hack won't be needed once everyone is compiling ImageMagick
    // against a version of OpenMP that has omp_pause_resource_all()
	for (i = 0; i < 100 && i < IMAGICK_G(shutdown_sleep_count); i += 1) {
		usleep(1000);
	}

#if defined(ZTS) && defined(PHP_WIN32)
	tsrm_mutex_free(imagick_mutex);
#endif
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}

PHP_RINIT_FUNCTION(imagick)
{
	// This suppresses an 'unused parameter' warning.
	(void)type;
	(void)module_number;

	IMAGICK_G(progress_callback) = NULL;
	return SUCCESS;
}

PHP_RSHUTDOWN_FUNCTION(imagick)
{
	php_imagick_callback* progress_callback = IMAGICK_G(progress_callback);
	// This suppresses an 'unused parameter' warning.
	(void)type;
	(void)module_number;

	if (progress_callback) {
		php_imagick_cleanup_progress_callback(progress_callback TSRMLS_CC);
		efree(progress_callback);
		IMAGICK_G(progress_callback) = NULL;
	}

#if defined(ZTS) && defined(PHP_WIN32)
	/* We have the lock so lets release it */
	if (imagick_thread_id == tsrm_thread_id()) {
		imagick_thread_id = (THREAD_T)NULL;
		tsrm_mutex_unlock(imagick_mutex);
	}
#endif
	return SUCCESS;
}

#if ZEND_MODULE_API_NO >= 20050922
static const zend_module_dep imagick_deps[] = {
    ZEND_MOD_CONFLICTS("gmagick")
    ZEND_MOD_REQUIRED("standard")
#ifdef HAVE_SPL
	ZEND_MOD_REQUIRED("spl")
#endif
	ZEND_MOD_END
};
#endif

zend_module_entry imagick_module_entry =
{
#if ZEND_MODULE_API_NO >= 20050922
        STANDARD_MODULE_HEADER_EX, NULL,
        imagick_deps,
#else
        STANDARD_MODULE_HEADER,
#endif
        PHP_IMAGICK_EXTNAME,
        php_imagick_functions,                  /* Functions */
        PHP_MINIT(imagick),                     /* MINIT */
        PHP_MSHUTDOWN(imagick),                 /* MSHUTDOWN */
        PHP_RINIT(imagick),                     /* RINIT */
        PHP_RSHUTDOWN(imagick),
        PHP_MINFO(imagick),                     /* MINFO */
        PHP_IMAGICK_VERSION,
        STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_IMAGICK
ZEND_GET_MODULE(imagick)
#endif
