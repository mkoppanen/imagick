<?php

/** @generate-function-entries */

class Imagick
{
#if MagickLibVersion > 0x628
    //PHP_ME(imagick, optimizeimagelayers, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function optimizeImageLayers(): bool  {}

//    PHP_ME(imagick, compareimagelayers, imagick_compareimagelayers_args, ZEND_ACC_PUBLIC)
    public function compareImageLayers(int $method): Imagick  {}

// PHP_ME(imagick, pingimageblob, imagick_pingimageblob_args, ZEND_ACC_PUBLIC)
    public function pingImageBlob(string $image): bool  {}

//    PHP_ME(imagick, pingimagefile, imagick_pingimagefile_args, ZEND_ACC_PUBLIC)
    public function pingImageFile( resource $filehandle, ?string $fileName): bool  {}

//PHP_ME(imagick, transposeimage, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function transposeImage(): bool  {}

// PHP_ME(imagick, transverseimage, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function transverseImage(): bool  {}

    //PHP_ME(imagick, trimimage, imagick_trimimage_args, ZEND_ACC_PUBLIC)
    public function trimImage(float $fuzz): bool  {}

//    PHP_ME(imagick, waveimage, imagick_waveimage_args, ZEND_ACC_PUBLIC)
    public function waveImage(float $amplitude, float $length): bool  {}

//  PHP_ME(imagick, vignetteimage, imagick_vignetteimage_args, ZEND_ACC_PUBLIC)
    public function vignetteImage(float $black_point, float $white_point, int $x, int $y): bool  {}

//    PHP_ME(imagick, uniqueimagecolors, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function uniqueImageColors(): bool  {}

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
//    PHP_ME(imagick, getimagematte, imagick_zero_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
    /** @deprecated */
    public function getImageMatte(): bool  {}
#endif
#endif

//    PHP_ME(imagick, setimagematte, imagick_setimagematte_args, ZEND_ACC_PUBLIC)
    public function setImageMatte(bool $matte): bool  {}

//    PHP_ME(imagick, adaptiveresizeimage, imagick_adaptiveresizeimage_args, ZEND_ACC_PUBLIC)
    public function adaptiveResizeImage(
        int $columns,
        int $rows,
        bool $bestfit = false,
        bool $legacy = false): bool  {}

//    PHP_ME(imagick, sketchimage, imagick_sketchimage_args, ZEND_ACC_PUBLIC)
    public function sketchImage(float $radius, float $sigma, float $angle): bool  {}

//    PHP_ME(imagick, shadeimage, imagick_shadeimage_args, ZEND_ACC_PUBLIC)
    public function shadeImage(bool $gray, float $azimuth, float $elevation): bool  {}

//  PHP_ME(imagick, getsizeoffset, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getSizeOffset(): int  {}

//  PHP_ME(imagick, setsizeoffset, imagick_setsizeoffset_args, ZEND_ACC_PUBLIC)
    public function setSizeOffset(int $columns, int $rows, int $offset): bool  {}

//  PHP_ME(imagick, adaptiveblurimage, imagick_adaptiveblurimage_args, ZEND_ACC_PUBLIC)
    public function adaptiveBlurImage(float $radius, float $sigma, int $channel = Imagick::CHANNEL_DEFAULT): bool  {}

//    PHP_ME(imagick, contraststretchimage, imagick_contraststretchimage_args, ZEND_ACC_PUBLIC)
    public function contrastStretchImage(
        float $black_point,
        float $white_point,
        int $channel = Imagick::CHANNEL_DEFAULT): bool  {}

//  PHP_ME(imagick, adaptivesharpenimage, imagick_adaptivesharpenimage_args, ZEND_ACC_PUBLIC)
    public function adaptiveSharpenImage(float $radius, float $sigma, int $channel = Imagick::CHANNEL_DEFAULT): bool  {}

//    PHP_ME(imagick, randomthresholdimage, imagick_randomthresholdimage_args, ZEND_ACC_PUBLIC)
    public function randomThresholdImage(float $low, float $high, int $channel = Imagick::CHANNEL_DEFAULT): bool  {}

#if MagickLibVersion < 0x700
//    PHP_ME(imagick, roundcornersimage, imagick_roundcornersimage_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
    /** @deprecated */
    public function roundCornersImage(
        float $x_rounding,
        float $y_rounding,
        float $stroke_width = 10,
        float $displace = 5,
        float $size_correction = -6): bool {}

    /* This alias is due to BWC */
//PHP_MALIAS(imagick, roundcorners, roundcornersimage, imagick_roundcornersimage_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
    /**
     * @deprecated
     * @alias Imagick::roundCornersImage
     */
    public function roundCorners(
        float $x_rounding,
        float $y_rounding,
        float $stroke_width = 10,
        float $displace = 5,
        float $size_correction = -6): bool {}

#endif

//    PHP_ME(imagick, setiteratorindex, imagick_setiteratorindex_args, ZEND_ACC_PUBLIC)
    public function setIteratorIndex(int $index): bool  {}

//    PHP_ME(imagick, getiteratorindex, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getIteratorIndex(): int  {}

#if MagickLibVersion < 0x700
//    PHP_ME(imagick, transformimage, imagick_transformimage_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
    /** @deprecated */
    public function transformImage(string $crop, string $geometry): Imagick  {}
#endif
#endif

#if MagickLibVersion > 0x630
#if MagickLibVersion < 0x700
//    PHP_ME(imagick, setimageopacity, imagick_setimageopacity_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
    /** @deprecated */
    public function setImageOpacity(float $opacity): bool  {}
#endif

#if MagickLibVersion >= 0x700
//    PHP_ME(imagick, setimagealpha, imagick_setimagealpha_args, ZEND_ACC_PUBLIC)
    public function setImageAlpha(float $alpha): null {}
#endif

#if MagickLibVersion < 0x700
//    PHP_ME(imagick, orderedposterizeimage, imagick_orderedposterizeimage_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
    /** @deprecated */
    public function orderedPosterizeImage(string $threshold_map, int $channel = Imagick::CHANNEL_DEFAULT): bool  {}
#endif
#endif

#if MagickLibVersion > 0x631
//    PHP_ME(imagick, polaroidimage, imagick_polaroidimage_args, ZEND_ACC_PUBLIC)
    public function polaroidImage(ImagickDraw $properties, float $angle): bool  {}

//    PHP_ME(imagick, getimageproperty, imagick_getimageproperty_args, ZEND_ACC_PUBLIC)
    public function getImageProperty(string $name): string  {}

//    PHP_ME(imagick, setimageproperty, imagick_setimageproperty_args, ZEND_ACC_PUBLIC)
    public function setImageProperty(string $name, string $value): bool  {}

//    PHP_ME(imagick, deleteimageproperty, imagick_deleteimageproperty_args, ZEND_ACC_PUBLIC)
    public function deleteImageProperty(string $name): bool  {}

//    PHP_ME(imagick, identifyformat, imagick_identifyformat_args, ZEND_ACC_PUBLIC)
    public function identifyFormat(string $embedText): string  {}

//    PHP_ME(imagick, setimageinterpolatemethod, imagick_setimageinterpolatemethod_args, ZEND_ACC_PUBLIC)
    public function setImageInterpolateMethod(int $method): bool  {}

//    PHP_ME(imagick, getimageinterpolatemethod, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageInterpolateMethod(): int  {}

//    PHP_ME(imagick, linearstretchimage, imagick_linearstretchimage_args, ZEND_ACC_PUBLIC)
    public function linearStretchImage(float $black_point, float $white_point): bool  {}

//    PHP_ME(imagick, getimagelength, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageLength(): int  {}

//    PHP_ME(imagick, extentimage, imagick_extentimage_args, ZEND_ACC_PUBLIC)
    public function extentImage(int $width, int $height, int $x, int $y): bool  {}
#endif
#if MagickLibVersion > 0x633
//   PHP_ME(imagick, getimageorientation, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageOrientation(): int  {}

//    PHP_ME(imagick, setimageorientation, imagick_setimageorientation_args, ZEND_ACC_PUBLIC)
    public function setImageOrientation(int $orientation): bool  {}
#endif

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion > 0x634
#if MagickLibVersion < 0x700
//    PHP_ME(imagick, paintfloodfillimage, imagick_paintfloodfillimage_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
    /** @deprecated */
    public function paintFloodfillImage(
        ImagickPixel|string $fill,
        float $fuzz,
        ImagickPixel|string $bordercolor,
        int $x,
        int $y,
        int $channel =  Imagick::CHANNEL_DEFAULT): bool {}
#endif
#endif
#endif

#if MagickLibVersion > 0x635
//    PHP_ME(imagick, clutimage, imagick_clutimage_args, ZEND_ACC_PUBLIC)
    public function clutImage(imagick $lookup_table, int $channel = Imagick::CHANNEL_DEFAULT): bool  {}

//    PHP_ME(imagick, getimageproperties, imagick_getimageproperties_args, ZEND_ACC_PUBLIC)
    public function getImageProperties(string $pattern = "*", bool $include_values = true): array  {}

//    PHP_ME(imagick, getimageprofiles, imagick_getimageprofiles_args, ZEND_ACC_PUBLIC)
    public function getImageProfiles(string $pattern = "*", bool $include_values = true): array  {}

//    PHP_ME(imagick, distortimage, imagick_distortimage_args, ZEND_ACC_PUBLIC)
    public function distortImage(int $method, array $arguments, bool $bestfit): bool  {}

//    PHP_ME(imagick, writeimagefile, imagick_writeimagefile_args, ZEND_ACC_PUBLIC)
    public function writeImageFile( resource $filehandle, ?string $format): bool  {}

//   PHP_ME(imagick, writeimagesfile, imagick_writeimagesfile_args, ZEND_ACC_PUBLIC)
    public function writeImagesFile( resource $filehandle, ?string $format): bool  {}

//    PHP_ME(imagick, resetimagepage, imagick_resetimagepage_args, ZEND_ACC_PUBLIC)
    public function resetImagePage(string $page): bool  {}

#if MagickLibVersion < 0x700
//    PHP_ME(imagick, setimageclipmask, imagick_setimageclipmask_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
    /** @deprecated */
    public function setImageClipMask(imagick $clip_mask): bool  {}

//    PHP_ME(imagick, getimageclipmask, imagick_zero_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
    /** @deprecated */
    public function getImageClipMask(): Imagick  {}
#endif

//    PHP_ME(imagick, animateimages, imagick_animateimages_args, ZEND_ACC_PUBLIC)
    // TODO - x server?
    public function animateImages(string $x_server): bool  {}

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
//    PHP_ME(imagick, recolorimage, imagick_recolorimage_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
    /** @deprecated */
    public function recolorImage(array $matrix): bool  {}
#endif
#endif
#endif

#if MagickLibVersion > 0x636
//    PHP_ME(imagick, setfont, imagick_setfont_args, ZEND_ACC_PUBLIC)
    public function setFont(string $font): bool  {}

//    PHP_ME(imagick, getfont, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getFont(): string  {}

//    PHP_ME(imagick, setpointsize, imagick_setpointsize_args, ZEND_ACC_PUBLIC)
    public function setPointSize(float $point_size): bool  {}

//    PHP_ME(imagick, getpointsize, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getPointSize(): float  {}

//    PHP_ME(imagick, mergeimagelayers, imagick_mergeimagelayers_args, ZEND_ACC_PUBLIC)
    public function mergeImageLayers(int $layer_method): Imagick  {}
#endif

#if MagickLibVersion > 0x637
//    PHP_ME(imagick, setimagealphachannel, imagick_setimagealphachannel_args, ZEND_ACC_PUBLIC)
    public function setImageAlphaChannel(int $mode): bool  {}

//    PHP_ME(imagick, floodfillpaintimage, imagick_floodfillpaintimage_args, ZEND_ACC_PUBLIC)
    public function floodfillPaintImage(
        ImagickPixel|string $fill,
        float $fuzz,
        ImagickPixel|string $target,
        int $x,
        int $y,
        bool $invert,
        ?int $channel = Imagick::CHANNEL_DEFAULT): bool{}



//    PHP_ME(imagick, opaquepaintimage, imagick_opaquepaintimage_args, ZEND_ACC_PUBLIC)
    public function opaquePaintImage(
        ImagickPixel|string $target,
        ImagickPixel|string $fill,
        float $fuzz,
        bool $invert,
        int $channel = Imagick::CHANNEL_DEFAULT): bool {}

//    PHP_ME(imagick, transparentpaintimage, imagick_transparentpaintimage_args, ZEND_ACC_PUBLIC)
    public function transparentPaintImage(ImagickPixel|string $target, float $alpha, float $fuzz, bool $invert): bool  {}
#endif
#if MagickLibVersion > 0x638
//    PHP_ME(imagick, liquidrescaleimage, imagick_liquidrescaleimage_args, ZEND_ACC_PUBLIC)
    public function liquidRescaleImage(int $width, int $height, float $delta_x, float $rigidity): bool  {}

//    PHP_ME(imagick, encipherimage, imagick_encipherimage_args, ZEND_ACC_PUBLIC)
    public function encipherImage(string $passphrase): bool  {}

//    PHP_ME(imagick, decipherimage, imagick_decipherimage_args, ZEND_ACC_PUBLIC)
    public function decipherImage(string $passphrase): bool  {}
#endif

#if MagickLibVersion > 0x639
//    PHP_ME(imagick, setgravity, imagick_setgravity_args, ZEND_ACC_PUBLIC)
    public function setGravity(int $gravity): bool  {}

//    PHP_ME(imagick, getgravity, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getGravity(): int  {}

//    PHP_ME(imagick, getimagechannelrange, imagick_getimagechannelrange_args, ZEND_ACC_PUBLIC)
    public function getImageChannelRange(int $channel): array  {}

//    PHP_ME(imagick, getimagealphachannel, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageAlphaChannel(): int  {}
#endif

#if MagickLibVersion > 0x642
//    PHP_ME(imagick, getimagechanneldistortions, imagick_getimagechanneldistortions_args, ZEND_ACC_PUBLIC)
    public function getImageChannelDistortions(
        Imagick $reference,
        int $metric,
        int $channel = Imagick::CHANNEL_DEFAULT): float {}
#endif

#if MagickLibVersion > 0x643
//    PHP_ME(imagick, setimagegravity, imagick_setimagegravity_args, ZEND_ACC_PUBLIC)
    public function setImageGravity(int $gravity): bool  {}

//    PHP_ME(imagick, getimagegravity, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageGravity(): int  {}
#endif

#if MagickLibVersion > 0x645
//    PHP_ME(imagick, importimagepixels, imagick_importimagepixels_args, ZEND_ACC_PUBLIC)
    public function importImagePixels(
        int $x,
        int $y,
        int $width,
        int $height,
        string $map,
        int $storage,
        array $pixels): bool {}

//    PHP_ME(imagick, deskewimage, imagick_deskewimage_args, ZEND_ACC_PUBLIC)
    public function deskewImage(float $threshold): bool  {}

//    PHP_ME(imagick, segmentimage, imagick_segmentimage_args, ZEND_ACC_PUBLIC)
    public function segmentImage(
        int $colorspace,
        float $cluster_threshold,
        float $smooth_threshold,
        bool $verbose = false): bool  {}

//    PHP_ME(imagick, sparsecolorimage, imagick_sparsecolorimage_args, ZEND_ACC_PUBLIC)
    public function sparseColorImage(
        int $SPARSE_METHOD,
        array $arguments,
        int $channel = Imagick::CHANNEL_DEFAULT): bool {}


//    PHP_ME(imagick, remapimage, imagick_remapimage_args, ZEND_ACC_PUBLIC)
    public function remapImage(imagick $replacement, int $DITHER): bool  {}
#endif


#if PHP_IMAGICK_HAVE_HOUGHLINE
//    PHP_ME(imagick, houghlineimage, imagick_houghlineimage_args, ZEND_ACC_PUBLIC)
    public function houghLineImage(int $width, int $height, float $threshold): bool {}
#endif

#if MagickLibVersion > 0x646
//    PHP_ME(imagick, exportimagepixels, imagick_exportimagepixels_args, ZEND_ACC_PUBLIC)
    public function exportImagePixels(int $x, int $y, int $width, int $height, string $map, int $STORAGE): array {}
#endif

#if MagickLibVersion > 0x648
//    PHP_ME(imagick, getimagechannelkurtosis, imagick_getimagechannelkurtosis_args, ZEND_ACC_PUBLIC)
    public function getImageChannelKurtosis(int $channel = Imagick::CHANNEL_DEFAULT): array  {}

//    PHP_ME(imagick, functionimage, imagick_functionimage_args, ZEND_ACC_PUBLIC)
    public function functionImage(int $function, array $arguments, int $channel = Imagick::CHANNEL_DEFAULT): bool {}
#endif

#if MagickLibVersion > 0x651
//    PHP_ME(imagick, transformimagecolorspace, imagick_transformimagecolorspace_args, ZEND_ACC_PUBLIC)
    public function transformImageColorspace(int $colorspace): bool  {}
#endif

#if MagickLibVersion > 0x652
//    PHP_ME(imagick, haldclutimage, imagick_haldclutimage_args, ZEND_ACC_PUBLIC)
    public function haldClutImage(Imagick $clut, int $channel = Imagick::CHANNEL_DEFAULT): bool  {}
#endif

#if MagickLibVersion > 0x655
//    PHP_ME(imagick, autolevelimage, imagick_autolevelimage_args, ZEND_ACC_PUBLIC)
    public function autoLevelImage(int $channel = Imagick::CHANNEL_DEFAULT): bool  {}

//    PHP_ME(imagick, blueshiftimage, imagick_blueshiftimage_args, ZEND_ACC_PUBLIC)
    public function blueShiftImage(float $factor = 1.5): bool  {}
#endif

#if MagickLibVersion > 0x656
//    PHP_ME(imagick, getimageartifact, imagick_getimageartifact_args, ZEND_ACC_PUBLIC)
    public function getImageArtifact(string $artifact): string  {}

//    PHP_ME(imagick, setimageartifact, imagick_setimageartifact_args, ZEND_ACC_PUBLIC)
    public function setImageArtifact(string $artifact, string $value): bool  {}

//    PHP_ME(imagick, deleteimageartifact, imagick_deleteimageartifact_args, ZEND_ACC_PUBLIC)
    public function deleteImageArtifact(string $artifact): bool  {}

//    PHP_ME(imagick, getcolorspace, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getColorspace(): int  {}

//    PHP_ME(imagick, setcolorspace, imagick_setcolorspace_args, ZEND_ACC_PUBLIC)
    public function setColorspace(int $colorspace): bool  {}

//    PHP_ME(imagick, clampimage, imagick_clampimage_args, ZEND_ACC_PUBLIC)
    public function clampImage(int $channel = Imagick::CHANNEL_DEFAULT): bool  {}
#endif

#if MagickLibVersion > 0x667
//    PHP_ME(imagick, smushimages, imagick_smushimages_args, ZEND_ACC_PUBLIC)
    public function smushImages(bool $stack, int $offset): Imagick  {}
#endif

//    PHP_ME(imagick, __construct, imagick_construct_args, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
    // TODO int|float? :spocks_eyebrow.gif:
    public function __construct(string|array|int|float|null $files) {}

//    PHP_ME(imagick, __tostring, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function __toString(): string  {}

#if PHP_VERSION_ID >= 50600
//    PHP_ME(imagick, count, imagick_count_args, ZEND_ACC_PUBLIC)
    public function count(int $mode = 0): int  {}
#else
//    PHP_ME(imagick, count, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function count(): int  {}
#endif


//    PHP_ME(imagick, getpixeliterator, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getPixelIterator(): ImagickPixelIterator  {}

//    PHP_ME(imagick, getpixelregioniterator, imagick_getpixelregioniterator_args, ZEND_ACC_PUBLIC)
    public function getPixelRegionIterator(int $x, int $y, int $columns, int $rows): ImagickPixelIterator  {}

//    PHP_ME(imagick, readimage, imagick_readimage_args, ZEND_ACC_PUBLIC)
    public function readImage(string $filename): bool  {}

//    PHP_ME(imagick, readimages, imagick_readimages_args, ZEND_ACC_PUBLIC)
    public function readImages(array $filenames): bool  {}

//    PHP_ME(imagick, readimageblob, imagick_readimageblob_args, ZEND_ACC_PUBLIC)
    public function readImageBlob(string $image, ?string $filename): bool  {}

//    PHP_ME(imagick, setimageformat, imagick_setimageformat_args, ZEND_ACC_PUBLIC)
    public function setImageFormat(string $format): bool  {}

//    PHP_ME(imagick, scaleimage, imagick_scaleimage_args, ZEND_ACC_PUBLIC)
    public function scaleImage(int $cols, int $rows, bool $bestfit = false, bool $legacy = false): bool  {}

//    PHP_ME(imagick, writeimage, imagick_writeimage_args, ZEND_ACC_PUBLIC)
    public function writeImage(?string $filename): bool  {}

//    PHP_ME(imagick, writeimages, imagick_writeimages_args, ZEND_ACC_PUBLIC)
    public function writeImages(string $filename, bool $adjoin): bool  {}

//    PHP_ME(imagick, blurimage, imagick_blurimage_args, ZEND_ACC_PUBLIC)
    public function blurImage(float $radius, float $sigma, ?int $channel): bool  {}

//    PHP_ME(imagick, thumbnailimage, imagick_thumbnailimage_args, ZEND_ACC_PUBLIC)
    public function thumbnailImage(
        int $columns,
        int $rows,
        bool $bestfit = false,
        bool $fill = false,
        bool $legacy = false): bool {}

//    PHP_ME(imagick, cropthumbnailimage, imagick_cropthumbnailimage_args, ZEND_ACC_PUBLIC)
    public function cropThumbnailImage(int $width, int $height, bool $legacy = false): bool  {}

//    PHP_ME(imagick, getimagefilename, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageFilename(): string  {}

//    PHP_ME(imagick, setimagefilename, imagick_setimagefilename_args, ZEND_ACC_PUBLIC)
    public function setImageFilename(string $filename): bool  {}

//    PHP_ME(imagick, getimageformat, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageFormat(): string  {}

//    PHP_ME(imagick, getimagemimetype, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageMimeType(): string  {}

//    PHP_ME(imagick, removeimage, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function removeImage(): bool  {}

//    ZEND_MALIAS(imagick, destroy, clear, imagick_zero_args, ZEND_ACC_PUBLIC)
    /** @alias Imagick::clear */
    public function destroy(): bool  {}

//    PHP_ME(imagick, clear, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function clear(): bool  {}

//    PHP_ME(imagick, clone, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function clone(): Imagick  {}
        
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
//    PHP_ME(imagick, getimagesize, imagick_zero_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
    /** @deprecated */
    public function getImageSize(): int  {}
#endif
#endif


//    PHP_ME(imagick, getimageblob, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageBlob(): string  {}
    
//    PHP_ME(imagick, getimagesblob, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImagesBlob(): string  {}

//    PHP_ME(imagick, setfirstiterator, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function setFirstIterator(): bool  {}

//    PHP_ME(imagick, setlastiterator, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function setLastIterator(): bool  {}
        
//    PHP_ME(imagick, resetiterator, imagick_zero_args, ZEND_ACC_PUBLIC)
      public function resetIterator(): null {}
        
//    PHP_ME(imagick, previousimage, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function previousImage(): bool  {}
    
//    PHP_ME(imagick, nextimage, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function nextImage(): bool  {}
        
//    PHP_ME(imagick, haspreviousimage, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function hasPreviousImage(): bool  {}

//    PHP_ME(imagick, hasnextimage, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function hasNextImage(): bool  {}

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
//    PHP_ME(imagick, setimageindex, imagick_setimageindex_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
    /** @deprecated */
    public function setImageIndex(int $index): bool  {}
        
//    PHP_ME(imagick, getimageindex, imagick_zero_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
    /** @deprecated */
    public function getImageIndex(): int  {}
#endif
#endif


//    PHP_ME(imagick, commentimage, imagick_commentimage_args, ZEND_ACC_PUBLIC)
    public function commentImage(string $comment): bool  {}
    
//    PHP_ME(imagick, cropimage, imagick_cropimage_args, ZEND_ACC_PUBLIC)
    public function cropImage(int $width, int $height, int $x, int $y): bool  {}

//    PHP_ME(imagick, labelimage, imagick_labelimage_args, ZEND_ACC_PUBLIC)
    public function labelImage(string $label): bool  {}
        
//    PHP_ME(imagick, getimagegeometry, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageGeometry(): array  {}
        
//    PHP_ME(imagick, drawimage, imagick_drawimage_args, ZEND_ACC_PUBLIC)
    public function drawImage(ImagickDraw $draw): bool  {}
        
//    PHP_ME(imagick, setimagecompressionquality, imagick_setimagecompressionquality_args, ZEND_ACC_PUBLIC)
    public function setImageCompressionQuality(int $quality): bool  {}
        
//    PHP_ME(imagick, getimagecompressionquality, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageCompressionQuality(): int  {}
    
//    PHP_ME(imagick, setimagecompression, imagick_setimagecompression_args, ZEND_ACC_PUBLIC)
    public function setImageCompression(int $compression): bool  {}

//    PHP_ME(imagick, getimagecompression, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageCompression(): int  {}

//    PHP_ME(imagick, annotateimage, imagick_annotateimage_args, ZEND_ACC_PUBLIC)
    public function annotateImage(ImagickDraw $draw_settings, float $x, float $y, float $angle, string $text): bool  {}

//    PHP_ME(imagick, compositeimage, imagick_compositeimage_args, ZEND_ACC_PUBLIC)
    public function compositeImage(
        Imagick $composite_object,
        int $composite,
        int $x,
        int $y,
        int $channel = Imagick::CHANNEL_DEFAULT): bool{}

//    PHP_ME(imagick, modulateimage, imagick_modulateimage_args, ZEND_ACC_PUBLIC)
    public function modulateImage(float $brightness, float $saturation, float $hue): bool  {}

//    PHP_ME(imagick, getimagecolors, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageColors(): int  {}

//    PHP_ME(imagick, montageimage, imagick_montageimage_args, ZEND_ACC_PUBLIC)
    public function montageImage(
        ImagickDraw $draw,
        string $tile_geometry,
        string $thumbnail_geometry,
        int $mode, string $frame): Imagick {}

//    PHP_ME(imagick, identifyimage, imagick_identifyimage_args, ZEND_ACC_PUBLIC)
    public function identifyImage(bool $appendRawOutput = false): array  {}

//    PHP_ME(imagick, thresholdimage, imagick_thresholdimage_args, ZEND_ACC_PUBLIC)
    public function thresholdImage(float $threshold, int $channel = Imagick::CHANNEL_DEFAULT): bool  {}

//    PHP_ME(imagick, adaptivethresholdimage, imagick_adaptivethresholdimage_args, ZEND_ACC_PUBLIC)
    public function adaptiveThresholdImage(int $width, int $height, int $offset): bool  {}

//    PHP_ME(imagick, blackthresholdimage, imagick_blackthresholdimage_args, ZEND_ACC_PUBLIC)
    public function blackThresholdImage(ImagickPixel|string $threshold): bool  {}

//    PHP_ME(imagick, whitethresholdimage, imagick_whitethresholdimage_args, ZEND_ACC_PUBLIC)
    public function whiteThresholdImage(ImagickPixel|string $threshold): bool  {}

//    PHP_ME(imagick, appendimages, imagick_appendimages_args, ZEND_ACC_PUBLIC)
    public function appendImages(bool $stack): Imagick  {}

//    PHP_ME(imagick, charcoalimage, imagick_charcoalimage_args, ZEND_ACC_PUBLIC)
    public function charcoalImage(float $radius, float $sigma): bool  {}


//    PHP_ME(imagick, normalizeimage, imagick_normalizeimage_args, ZEND_ACC_PUBLIC)
    public function normalizeImage(int $channel = Imagick::CHANNEL_DEFAULT): bool  {}

//    PHP_ME(imagick, oilpaintimage, imagick_oilpaintimage_args, ZEND_ACC_PUBLIC)
    public function oilPaintImage(float $radius): bool  {}

//    PHP_ME(imagick, posterizeimage, imagick_posterizeimage_args, ZEND_ACC_PUBLIC)
    public function posterizeImage(int $levels, bool $dither): bool  {}

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
//    PHP_ME(imagick, radialblurimage, imagick_radialblurimage_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
    /** @deprecated */
    public function radialBlurImage(float $angle, int $channel = Imagick::CHANNEL_DEFAULT): bool  {}
#endif
#endif

//    PHP_ME(imagick, raiseimage, imagick_raiseimage_args, ZEND_ACC_PUBLIC)
    public function raiseImage(int $width, int $height, int $x, int $y, bool $raise): bool  {}

//    PHP_ME(imagick, resampleimage, imagick_resampleimage_args, ZEND_ACC_PUBLIC)
    public function resampleImage(float $x_resolution, float $y_resolution, int $filter, float $blur): bool  {}

//    PHP_ME(imagick, resizeimage, imagick_resizeimage_args, ZEND_ACC_PUBLIC)
    public function resizeImage(
        int $columns,
        int $rows,
        int $filter,
        float $blur,
        bool $bestfit = false,
        bool $legacy = false): bool {}

//    PHP_ME(imagick, rollimage, imagick_rollimage_args, ZEND_ACC_PUBLIC)
    public function rollImage(int $x, int $y): bool  {}

//    PHP_ME(imagick, rotateimage, imagick_rotateimage_args, ZEND_ACC_PUBLIC)
    public function rotateImage(ImagickPixel|string $background, float $degrees): bool  {}

//    PHP_ME(imagick, sampleimage, imagick_sampleimage_args, ZEND_ACC_PUBLIC)
    public function sampleImage(int $columns, int $rows): bool  {}

//    PHP_ME(imagick, solarizeimage, imagick_solarizeimage_args, ZEND_ACC_PUBLIC)
    public function solarizeImage(int $threshold): bool  {}

//    PHP_ME(imagick, shadowimage, imagick_shadowimage_args, ZEND_ACC_PUBLIC)
    public function shadowImage(float $opacity, float $sigma, int $x, int $y): bool  {}

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
//    PHP_ME(imagick, setimageattribute, imagick_setimageattribute_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
    /** @deprecated */
    public function setImageAttribute(string $key, string $value): bool  {}
#endif
#endif

//    PHP_ME(imagick, setimagebackgroundcolor, imagick_setimagebackgroundcolor_args, ZEND_ACC_PUBLIC)
    public function setImageBackgroundColor(ImagickPixel|string $background): bool  {}

#if MagickLibVersion >= 0x700
//    PHP_ME(imagick, setimagechannelmask, imagick_setimagechannelmask_args, ZEND_ACC_PUBLIC)
    public function setImageChannelMask(int $channel): int {}

#endif
//    PHP_ME(imagick, setimagecompose, imagick_setimagecompose_args, ZEND_ACC_PUBLIC)
    public function setImageCompose(int $compose): bool  {}

//    PHP_ME(imagick, setimagedelay, imagick_setimagedelay_args, ZEND_ACC_PUBLIC)
    public function setImageDelay(int $delay): bool  {}

//    PHP_ME(imagick, setimagedepth, imagick_setimagedepth_args, ZEND_ACC_PUBLIC)
    public function setImageDepth(int $depth): bool  {}

//    PHP_ME(imagick, setimagegamma, imagick_setimagegamma_args, ZEND_ACC_PUBLIC)
    public function setImageGamma(float $gamma): bool  {}

//    PHP_ME(imagick, setimageiterations, imagick_setimageiterations_args, ZEND_ACC_PUBLIC)
    public function setImageIterations(int $iterations): bool  {}

#if MagickLibVersion < 0x700
//    PHP_ME(imagick, setimagemattecolor, imagick_setimagemattecolor_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
    /** @deprecated */
    public function setImageMatteColor(ImagickPixel|string $matte): bool  {}
#endif


//    PHP_ME(imagick, setimagepage, imagick_setimagepage_args, ZEND_ACC_PUBLIC)
    public function setImagePage(int $width, int $height, int $x, int $y): bool  {}


//    PHP_ME(imagick, setimageprogressmonitor, imagick_setimageprogressmonitor_args, ZEND_ACC_PUBLIC)
    // TODO test this.
    public function setImageProgressMonitor(string $filename): bool {}


#if MagickLibVersion > 0x653
//    PHP_ME(imagick, setprogressmonitor, imagick_setprogressmonitor_args, ZEND_ACC_PUBLIC)
    public function setProgressMonitor(callable $callback): bool  {}
#endif


//    PHP_ME(imagick, setimageresolution, imagick_setimageresolution_args, ZEND_ACC_PUBLIC)
    public function setImageResolution(float $x_resolution, float $y_resolution): bool  {}

//    PHP_ME(imagick, setimagescene, imagick_setimagescene_args, ZEND_ACC_PUBLIC)
    public function setImageScene(int $scene): bool  {}

//    PHP_ME(imagick, setimagetickspersecond, imagick_setimagetickspersecond_args, ZEND_ACC_PUBLIC)
    public function setImageTicksPerSecond(int $ticks_per_second): bool  {}

//    PHP_ME(imagick, setimagetype, imagick_setimagetype_args, ZEND_ACC_PUBLIC)
    public function setImageType(int $image_type): bool  {}

//    PHP_ME(imagick, setimageunits, imagick_setimageunits_args, ZEND_ACC_PUBLIC)
    public function setImageUnits(int $units): bool  {}

//    PHP_ME(imagick, sharpenimage, imagick_sharpenimage_args, ZEND_ACC_PUBLIC)
    public function sharpenImage(float $radius, float $sigma, int $channel = Imagick::CHANNEL_DEFAULT): bool  {}

//    PHP_ME(imagick, shaveimage, imagick_shaveimage_args, ZEND_ACC_PUBLIC)
    public function shaveImage(int $columns, int $rows): bool  {}

//    PHP_ME(imagick, shearimage, imagick_shearimage_args, ZEND_ACC_PUBLIC)
    public function shearImage(ImagickPixel|string $background, float $x_shear, float $y_shear): bool  {}

//    PHP_ME(imagick, spliceimage, imagick_spliceimage_args, ZEND_ACC_PUBLIC)
    public function spliceImage(int $width, int $height, int $x, int $y): bool  {}

//    PHP_ME(imagick, pingimage, imagick_pingimage_args, ZEND_ACC_PUBLIC)
    public function pingImage(string $filename): bool  {}

//    PHP_ME(imagick, readimagefile, imagick_readimagefile_args, ZEND_ACC_PUBLIC)
    public function readImageFile(resource $filehandle, ?string $fileName = null): bool  {}

//    PHP_ME(imagick, displayimage, imagick_displayimage_args, ZEND_ACC_PUBLIC)
    public function displayImage(string $servername): bool  {}

//    PHP_ME(imagick, displayimages, imagick_displayimages_args, ZEND_ACC_PUBLIC)
    public function displayImages(string $servername): bool  {}

//    PHP_ME(imagick, spreadimage, imagick_spreadimage_args, ZEND_ACC_PUBLIC)
    public function spreadImage(float $radius): bool  {}

//    PHP_ME(imagick, swirlimage, imagick_swirlimage_args, ZEND_ACC_PUBLIC)
    public function swirlImage(float $degrees): bool  {}

//    PHP_ME(imagick, stripimage, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function stripImage(): bool  {}

//    PHP_ME(imagick, queryformats, imagick_queryformats_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    public static function queryFormats(string $pattern = "*"): array  {}

//    PHP_ME(imagick, queryfonts, imagick_queryfonts_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    public static function queryFonts(string $pattern = "*"): array  {}

//    PHP_ME(imagick, queryfontmetrics, imagick_queryfontmetrics_args, ZEND_ACC_PUBLIC)
    /* TODO  $multiline == null,  means we should autodetect */
    public function queryFontMetrics(ImagickDraw $properties, string $text, ?bool $multiline): array  {}

//    PHP_ME(imagick, steganoimage, imagick_steganoimage_args, ZEND_ACC_PUBLIC)
    public function steganoImage(imagick $watermark_wand, int $offset): Imagick  {}

//    PHP_ME(imagick, addnoiseimage, imagick_addnoiseimage_args, ZEND_ACC_PUBLIC)
    public function addNoiseImage(int $noise_type, int $channel = Imagick::CHANNEL_DEFAULT): bool  {}

//    PHP_ME(imagick, motionblurimage, imagick_motionblurimage_args, ZEND_ACC_PUBLIC)
    public function motionBlurImage(
        float $radius,
        float $sigma,
        float $angle,
        int $channel = Imagick::CHANNEL_DEFAULT):bool {}

#if MagickLibVersion < 0x700
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
//    PHP_ME(imagick, mosaicimages, imagick_zero_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
    /** @deprecated */
    public function mosaicImages(): Imagick  {}
#endif
#endif

//    PHP_ME(imagick, morphimages, imagick_morphimages_args, ZEND_ACC_PUBLIC)
    public function morphImages(int $number_frames): Imagick  {}

//    PHP_ME(imagick, minifyimage, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function minifyImage(): bool  {}

//    PHP_ME(imagick, affinetransformimage, imagick_affinetransformimage_args, ZEND_ACC_PUBLIC)
    public function affineTransformImage(ImagickDraw $matrix): bool  {}

#if MagickLibVersion < 0x700
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
//    PHP_ME(imagick, averageimages, imagick_zero_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
    /** @deprecated */
    public function averageImages(): Imagick  {}
#endif
#endif

//    PHP_ME(imagick, borderimage, imagick_borderimage_args, ZEND_ACC_PUBLIC)
    public function borderImage(ImagickPixel|string $bordercolor, int $width, int $height): bool  {}

//    PHP_ME(imagick, calculatecrop, imagick_calculatecrop_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    public static function calculateCrop(
        int $orig_width,
        int $orig_height,
        int $desired_width,
        int $desired_height,
        bool $legacy = false): array {}


//    PHP_ME(imagick, chopimage, imagick_chopimage_args, ZEND_ACC_PUBLIC)
    public function chopImage(int $width, int $height, int $x, int $y): bool  {}

//    PHP_ME(imagick, clipimage, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function clipImage(): bool  {}

//    PHP_ME(imagick, clippathimage, imagick_clippathimage_args, ZEND_ACC_PUBLIC)
//    public function clipPathImage(string $pathname, string $inside): void  {}
    public function clipPathImage(string $pathname, bool $inside): bool  {}

    /* clippathimage has been deprecated. Create alias here and use the newer API function if present */
//    PHP_MALIAS(imagick, clipimagepath, clippathimage, imagick_clippathimage_args, ZEND_ACC_PUBLIC)
    /** @alias Imagick::clipPathImage */
    public function clipImagePath(string $pathname, string $inside): void  {}

//    PHP_ME(imagick, coalesceimages, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function coalesceImages(): Imagick  {}

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
//    PHP_ME(imagick, colorfloodfillimage, imagick_colorfloodfillimage_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
    /** @deprecated */
    public function colorFloodfillImage(ImagickPixel|string $fill, float $fuzz, ImagickPixel|string $bordercolor, int $x, int $y): bool  {}
#endif
#endif

//    PHP_ME(imagick, colorizeimage, imagick_colorizeimage_args, ZEND_ACC_PUBLIC)

    // TODO - opacity is actually float if legacy is true...
    public function colorizeImage(
        ImagickPixel|string $colorize,
        ImagickPixel|string $opacity,
        ?bool $legacy = false ): bool  {}

//    PHP_ME(imagick, compareimagechannels, imagick_compareimagechannels_args, ZEND_ACC_PUBLIC)
    public function compareImageChannels(imagick $image, int $channelType, int $metricType): array  {}

//    PHP_ME(imagick, compareimages, imagick_compareimages_args, ZEND_ACC_PUBLIC)
    public function compareImages(imagick $compare, int $metric): array  {}

//    PHP_ME(imagick, contrastimage, imagick_contrastimage_args, ZEND_ACC_PUBLIC)
    public function contrastImage(bool $sharpen): bool  {}

//    PHP_ME(imagick, combineimages, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function combineImages(int $channelType): Imagick  {}

//    PHP_ME(imagick, convolveimage, imagick_convolveimage_args, ZEND_ACC_PUBLIC)
    public function convolveImage(array $kernel, int $channel = Imagick::CHANNEL_DEFAULT): bool  {}

//    PHP_ME(imagick, cyclecolormapimage, imagick_cyclecolormapimage_args, ZEND_ACC_PUBLIC)
    public function cycleColormapImage(int $displace): bool  {}


//    PHP_ME(imagick, deconstructimages, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function deconstructImages(): Imagick  {}

//    PHP_ME(imagick, despeckleimage, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function despeckleImage(): bool  {}

//    PHP_ME(imagick, edgeimage, imagick_edgeimage_args, ZEND_ACC_PUBLIC)
    public function edgeImage(float $radius): bool  {}

//    PHP_ME(imagick, embossimage, imagick_embossimage_args, ZEND_ACC_PUBLIC)
    public function embossImage(float $radius, float $sigma): bool  {}

//    PHP_ME(imagick, enhanceimage, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function enhanceImage(): bool  {}

//    PHP_ME(imagick, equalizeimage, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function equalizeImage(): bool  {}

//    PHP_ME(imagick, evaluateimage, imagick_evaluateimage_args, ZEND_ACC_PUBLIC)
    public function evaluateImage(int $op, float $constant, int $channel = Imagick::CHANNEL_DEFAULT): bool  {}

#if MagickLibVersion >= 0x687
//	Merge multiple images of the same size together with the selected operator.
//http://www.imagemagick.org/Usage/layers/#evaluate-sequence

//    PHP_ME(imagick, evaluateimages, imagick_evaluateimages_args, ZEND_ACC_PUBLIC)
    public function evaluateImages(int $EVALUATE_CONSTANT): bool {}

#endif

#if MagickLibVersion < 0x700
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
//    PHP_ME(imagick, flattenimages, imagick_zero_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
    /** @deprecated */
    public function flattenImages(): Imagick  {}
#endif
#endif

//    PHP_ME(imagick, flipimage, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function flipImage(): bool  {}

//    PHP_ME(imagick, flopimage, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function flopImage(): bool  {}

#if MagickLibVersion >= 0x655
//    PHP_ME(imagick, forwardfouriertransformimage, imagick_forwardfouriertransformimage_args, ZEND_ACC_PUBLIC)
    public function forwardFourierTransformImage(bool $magnitude): bool  {}
#endif

//    PHP_ME(imagick, frameimage, imagick_frameimage_args, ZEND_ACC_PUBLIC)
    public function frameImage(
        ImagickPixel|string $matte_color,
        int $width,
        int $height,
        int $inner_bevel,
        int $outer_bevel): bool  {}


//    PHP_ME(imagick, fximage, imagick_fximage_args, ZEND_ACC_PUBLIC)
    public function fxImage(string $expression, int $channel = Imagick::CHANNEL_DEFAULT): Imagick  {}

//    PHP_ME(imagick, gammaimage, imagick_gammaimage_args, ZEND_ACC_PUBLIC)
    public function gammaImage(float $gamma, int $channel = Imagick::CHANNEL_DEFAULT): bool  {}

//    PHP_ME(imagick, gaussianblurimage, imagick_gaussianblurimage_args, ZEND_ACC_PUBLIC)
    public function gaussianBlurImage(float $radius, float $sigma, int $channel = Imagick::CHANNEL_DEFAULT): bool  {}

#if MagickLibVersion < 0x700
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
//    PHP_ME(imagick, getimageattribute, imagick_getimageattribute_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
    /** @deprecated */
    public function getImageAttribute(string $key): string  {}
#endif
#endif


//    PHP_ME(imagick, getimagebackgroundcolor, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageBackgroundColor(): ImagickPixel  {}

//    PHP_ME(imagick, getimageblueprimary, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageBluePrimary(): array  {}

//    PHP_ME(imagick, getimagebordercolor, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageBorderColor(): ImagickPixel  {}

//    PHP_ME(imagick, getimagechanneldepth, imagick_getimagechanneldepth_args, ZEND_ACC_PUBLIC)
    public function getImageChannelDepth(int $channel): int  {}

//    PHP_ME(imagick, getimagechanneldistortion, imagick_getimagechanneldistortion_args, ZEND_ACC_PUBLIC)
    public function getImageChannelDistortion(imagick $reference, int $channel, int $metric): float  {}

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
//    PHP_ME(imagick, getimagechannelextrema, imagick_getimagechannelextrema_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
    /** @deprecated */
    public function getImageChannelExtrema(int $channel): array  {}

#endif
#endif

//    PHP_ME(imagick, getimagechannelmean, imagick_getimagechannelmean_args, ZEND_ACC_PUBLIC)
    public function getImageChannelMean(int $channel): array  {}

//    PHP_ME(imagick, getimagechannelstatistics, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageChannelStatistics(): array  {}

//    PHP_ME(imagick, getimagecolormapcolor, imagick_getimagecolormapcolor_args, ZEND_ACC_PUBLIC)
    public function getImageColormapColor(int $index): ImagickPixel  {}

//    PHP_ME(imagick, getimagecolorspace, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageColorspace(): int  {}

//    PHP_ME(imagick, getimagecompose, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageCompose(): int  {}

//    PHP_ME(imagick, getimagedelay, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageDelay(): int  {}

//    PHP_ME(imagick, getimagedepth, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageDepth(): int  {}

//    PHP_ME(imagick, getimagedistortion, imagick_getimagedistortion_args, ZEND_ACC_PUBLIC)
    public function getImageDistortion(Imagick $reference, int $metric): float  {}

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
//    PHP_ME(imagick, getimageextrema, imagick_zero_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
    /** @deprecated */
    public function getImageExtrema(): array  {}
#endif
#endif

//    PHP_ME(imagick, getimagedispose, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageDispose(): int  {}

//    PHP_ME(imagick, getimagegamma, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageGamma(): float  {}

//    PHP_ME(imagick, getimagegreenprimary, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageGreenPrimary(): array  {}

//    PHP_ME(imagick, getimageheight, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageHeight(): int  {}

//    PHP_ME(imagick, getimagehistogram, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageHistogram(): array  {}

//    PHP_ME(imagick, getimageinterlacescheme, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageInterlaceScheme(): int  {}

//    PHP_ME(imagick, getimageiterations, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageIterations(): int  {}

#if MagickLibVersion < 0x700
//    PHP_ME(imagick, getimagemattecolor, imagick_zero_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
    /** @deprecated */
    public function getImageMatteColor(): ImagickPixel  {}
#endif

//    PHP_ME(imagick, getimagepage, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImagePage(): array  {}

//    PHP_ME(imagick, getimagepixelcolor, imagick_getimagepixelcolor_args, ZEND_ACC_PUBLIC)
    public function getImagePixelColor(int $x, int $y): ImagickPixel  {}

//    PHP_ME(imagick, getimageprofile, imagick_getimageprofile_args, ZEND_ACC_PUBLIC)
    public function getImageProfile(string $name): string  {}

//    PHP_ME(imagick, getimageredprimary, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageRedPrimary(): array  {}

//    PHP_ME(imagick, getimagerenderingintent, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageRenderingIntent(): int  {}

//    PHP_ME(imagick, getimageresolution, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageResolution(): array  {}

//    PHP_ME(imagick, getimagescene, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageScene(): int  {}

//    PHP_ME(imagick, getimagesignature, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageSignature(): string  {}

//    PHP_ME(imagick, getimagetickspersecond, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageTicksPerSecond(): int  {}

//    PHP_ME(imagick, getimagetype, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageType(): int  {}

//    PHP_ME(imagick, getimageunits, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageUnits(): int  {}

//    PHP_ME(imagick, getimagevirtualpixelmethod, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageVirtualPixelMethod(): int  {}

//    PHP_ME(imagick, getimagewhitepoint, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageWhitePoint(): array  {}

//    PHP_ME(imagick, getimagewidth, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageWidth(): int  {}

//    PHP_ME(imagick, getnumberimages, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getNumberImages(): int  {}

//    PHP_ME(imagick, getimagetotalinkdensity, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImageTotalInkDensity(): float  {}

//    PHP_ME(imagick, getimageregion, imagick_getimageregion_args, ZEND_ACC_PUBLIC)
    public function getImageRegion(int $width, int $height, int $x, int $y): Imagick  {}

//    PHP_ME(imagick, implodeimage, imagick_getimagetotalinkdensity_args, ZEND_ACC_PUBLIC)
    public function implodeImage(float $radius): bool  {}

#if MagickLibVersion >= 0x658
//    PHP_ME(imagick, inversefouriertransformimage, imagick_inversefouriertransformimage_args, ZEND_ACC_PUBLIC)
    public function inverseFourierTransformImage(imagick $complement, bool $magnitude): bool  {}
#endif

//    PHP_ME(imagick, levelimage, imagick_levelimage_args, ZEND_ACC_PUBLIC)
    public function levelImage(
        float $black_point,
        float $gamma,
        float $white_point,
        int $channel = Imagick::CHANNEL_DEFAULT): bool    {}

//    PHP_ME(imagick, magnifyimage, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function magnifyImage(): bool  {}

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
//    PHP_ME(imagick, mapimage, imagick_mapimage_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
    /** @deprecated */
    public function mapImage(imagick $map, bool $dither): bool  {}

//    PHP_ME(imagick, mattefloodfillimage, imagick_mattefloodfillimage_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
    /** @deprecated */
    public function matteFloodfillImage(float $alpha, float $fuzz, ImagickPixel|string $bordercolor, int $x, int $y): bool  {}

#endif
#endif

#if MagickLibVersion < 0x700
#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
//    PHP_ME(imagick, medianfilterimage, imagick_medianfilterimage_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
    /** @deprecated */
    public function medianFilterImage(float $radius): bool  {}
#endif
#endif

//    PHP_ME(imagick, negateimage, imagick_negateimage_args, ZEND_ACC_PUBLIC)
    public function negateImage(bool $gray, int $channel = Imagick::CHANNEL_DEFAULT): bool  {}

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
//    PHP_ME(imagick, paintopaqueimage, imagick_paintopaqueimage_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
    /** @deprecated */
    public function paintOpaqueImage(
        ImagickPixel|string $target,
        ImagickPixel|string $fill,
        float $fuzz,
        int $channel = Imagick::CHANNEL_DEFAULT): bool  {}

//    PHP_ME(imagick, painttransparentimage, imagick_painttransparentimage_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
    /** @deprecated */
    public function paintTransparentImage(ImagickPixel|string $target, float $alpha, float $fuzz): bool  {}
#endif
#endif

//    PHP_ME(imagick, previewimages, imagick_previewimages_args, ZEND_ACC_PUBLIC)
    public function previewImages(int $preview): bool  {}

//    PHP_ME(imagick, profileimage, imagick_profileimage_args, ZEND_ACC_PUBLIC)
    public function profileImage(string $name, string $profile): bool  {}

//    PHP_ME(imagick, quantizeimage, imagick_quantizeimage_args, ZEND_ACC_PUBLIC)
    public function  quantizeImage(int $numberColors, int $colorspace, int $treedepth, bool $dither, bool $measureError):  bool {}

//    PHP_ME(imagick, quantizeimages, imagick_quantizeimages_args, ZEND_ACC_PUBLIC)
    public function quantizeImages(
        int $numberColors,
        int $colorspace,
        int $treedepth,
        bool $dither,
        bool $measureError): bool {}

#if !defined(MAGICKCORE_EXCLUDE_DEPRECATED)
#if MagickLibVersion < 0x700
//    PHP_ME(imagick, reducenoiseimage, imagick_reducenoiseimage_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
    /** @deprecated */
    public function reduceNoiseImage(float $radius): bool  {}
#endif
#endif

//    PHP_ME(imagick, removeimageprofile, imagick_removeimageprofile_args, ZEND_ACC_PUBLIC)
    public function removeImageProfile(string $name): string  {}

//    PHP_ME(imagick, separateimagechannel, imagick_separateimagechannel_args, ZEND_ACC_PUBLIC)
    public function separateImageChannel(int $channel): bool  {}

//    PHP_ME(imagick, sepiatoneimage, imagick_sepiatoneimage_args, ZEND_ACC_PUBLIC)
    public function sepiaToneImage(float $threshold): bool  {}

#if MagickLibVersion < 0x700
//    PHP_ME(imagick, setimagebias, imagick_setimagebias_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
    /** @deprecated */
    public function setImageBias(float $bias): bool  {}

//    PHP_ME(imagick, setimagebiasquantum, imagick_setimagebiasquantum_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
    /** @deprecated */
    public function setImageBiasQuantum(string $bias): void  {}
#endif

//    PHP_ME(imagick, setimageblueprimary, imagick_setimageblueprimary_args, ZEND_ACC_PUBLIC)
    public function setImageBluePrimary(float $x, float $y): bool  {}
    /* {{{ proto bool Imagick::setImageBluePrimary(float x,float y)
For IM7 the prototype is
proto bool Imagick::setImageBluePrimary(float x, float y, float z) */


//    PHP_ME(imagick, setimagebordercolor, imagick_setimagebordercolor_args, ZEND_ACC_PUBLIC)
    public function setImageBorderColor(ImagickPixel|string $border): bool  {}

//    PHP_ME(imagick, setimagechanneldepth, imagick_setimagechanneldepth_args, ZEND_ACC_PUBLIC)
    public function setImageChannelDepth(int $channel, int $depth): bool  {}

//    PHP_ME(imagick, setimagecolormapcolor, imagick_setimagecolormapcolor_args, ZEND_ACC_PUBLIC)
    public function setImageColormapColor(int $index, ImagickPixel $color): bool  {}

//    PHP_ME(imagick, setimagecolorspace, imagick_setimagecolorspace_args, ZEND_ACC_PUBLIC)
    public function setImageColorspace(int $colorspace): bool  {}

//    PHP_ME(imagick, setimagedispose, imagick_setimagedispose_args, ZEND_ACC_PUBLIC)
    public function setImageDispose(int $dispose): bool  {}

//    PHP_ME(imagick, setimageextent, imagick_setimageextent_args, ZEND_ACC_PUBLIC)
    public function setImageExtent(int $columns, int $rows): bool  {}

//    PHP_ME(imagick, setimagegreenprimary, imagick_setimagegreenprimary_args, ZEND_ACC_PUBLIC)
    public function setImageGreenPrimary(float $x, float $y): bool  {}


//    PHP_ME(imagick, setimageinterlacescheme, imagick_setimageinterlacescheme_args, ZEND_ACC_PUBLIC)
    public function setImageInterlaceScheme(int $interlace_scheme): bool  {}

//    PHP_ME(imagick, setimageprofile, imagick_setimageprofile_args, ZEND_ACC_PUBLIC)
    public function setImageProfile(string $name, string $profile): bool  {}

//    PHP_ME(imagick, setimageredprimary, imagick_setimageredprimary_args, ZEND_ACC_PUBLIC)
    public function setImageRedPrimary(float $x, float $y): bool  {}

//    PHP_ME(imagick, setimagerenderingintent, imagick_setimagerenderingintent_args, ZEND_ACC_PUBLIC)
    public function setImageRenderingIntent(int $rendering_intent): bool  {}

//    PHP_ME(imagick, setimagevirtualpixelmethod, imagick_setimagevirtualpixelmethod_args, ZEND_ACC_PUBLIC)
    public function setImageVirtualPixelMethod(int $method): bool  {}

//    PHP_ME(imagick, setimagewhitepoint, imagick_setimagewhitepoint_args, ZEND_ACC_PUBLIC)
    public function setImageWhitePoint(float $x, float $y): bool  {}

//    PHP_ME(imagick, sigmoidalcontrastimage, imagick_sigmoidalcontrastimage_args, ZEND_ACC_PUBLIC)
    public function  sigmoidalContrastImage(
        bool $sharpen,
        float $alpha,
        float $beta,
        int $channel = Imagick::CHANNEL_DEFAULT): bool{}

//    PHP_ME(imagick, stereoimage, imagick_stereoimage_args, ZEND_ACC_PUBLIC)
    public function stereoImage(imagick $offset_wand): bool  {}

//    PHP_ME(imagick, textureimage, imagick_textureimage_args, ZEND_ACC_PUBLIC)
    public function textureImage(imagick $texture_wand): Imagick  {}

//    PHP_ME(imagick, tintimage, imagick_tintimage_args, ZEND_ACC_PUBLIC)
    public function tintImage(ImagickPixel|string $tint, ImagickPixel|string $opacity, bool $legacy = false): bool  {}

//    PHP_ME(imagick, unsharpmaskimage, imagick_unsharpmaskimage_args, ZEND_ACC_PUBLIC)
    public function unsharpMaskImage(
        float $radius,
        float $sigma,
        float $amount,
        float $threshold,
        int $channel = Imagick::CHANNEL_DEFAULT): bool {}

//    PHP_ME(imagick, getimage, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getImage(): Imagick  {}

//    PHP_ME(imagick, addimage, imagick_addimage_args, ZEND_ACC_PUBLIC)
    public function addImage(imagick $source): bool  {}

//    PHP_ME(imagick, setimage, imagick_setimage_args, ZEND_ACC_PUBLIC)
    public function setImage(imagick $replace): bool  {}

//    PHP_ME(imagick, newimage, imagick_newimage_args, ZEND_ACC_PUBLIC)
    public function newImage(int $cols, int $rows, ImagickPixel|string $background, ?string $format): bool  {}

//    PHP_ME(imagick, newpseudoimage, imagick_newpseudoimage_args, ZEND_ACC_PUBLIC)
    public function newPseudoImage(int $columns, int $rows, string $pseudoString): bool  {}

//    PHP_ME(imagick, getcompression, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getCompression(): int  {}

//    PHP_ME(imagick, getcompressionquality, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getCompressionQuality(): int  {}

//    PHP_ME(imagick, getcopyright, imagick_zero_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    public static function getCopyright(): string  {}

//    PHP_ME(imagick, getconfigureoptions, imagick_getconfigureoptions_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    public static function getConfigureOptions(?string $pattern): string {}


#if MagickLibVersion > 0x660
//    PHP_ME(imagick, getfeatures, imagick_zero_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    public static function getFeatures(): string {}
#endif

//    PHP_ME(imagick, getfilename, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getFilename(): string  {}

//    PHP_ME(imagick, getformat, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getFormat(): string  {}

//    PHP_ME(imagick, gethomeurl, imagick_zero_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    public static function getHomeURL(): string  {}

//    PHP_ME(imagick, getinterlacescheme, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getInterlaceScheme(): int {}

//    PHP_ME(imagick, getoption, imagick_getoption_args, ZEND_ACC_PUBLIC)
    public function getOption(string $key): string  {}

//    PHP_ME(imagick, getpackagename, imagick_zero_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    public static function getPackageName(): string  {}

//    PHP_ME(imagick, getpage, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getPage(): array  {}

//    PHP_ME(imagick, getquantum, imagick_zero_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    public static function getQuantum(): int  {}

//    PHP_ME(imagick, gethdrienabled, imagick_zero_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    public static function getHdriEnabled(): bool {}

//    PHP_ME(imagick, getquantumdepth, imagick_zero_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    public static function getQuantumDepth(): array  {}

//    PHP_ME(imagick, getquantumrange, imagick_zero_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    public static function getQuantumRange(): array  {}

//    PHP_ME(imagick, getreleasedate, imagick_zero_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    public static function getReleaseDate(): string  {}

//    PHP_ME(imagick, getresource, imagick_getresource_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    public static function getResource(int $type): int  {}

//    PHP_ME(imagick, getresourcelimit, imagick_getresourcelimit_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    public static function getResourceLimit(int $type): int  {}

//    PHP_ME(imagick, getsamplingfactors, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getSamplingFactors(): array  {}

//    PHP_ME(imagick, getsize, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getSize(): array  {}

//    PHP_ME(imagick, getversion, imagick_zero_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    public static function getVersion(): array  {}

//    PHP_ME(imagick, setbackgroundcolor, imagick_setbackgroundcolor_args, ZEND_ACC_PUBLIC)
    public function setBackgroundColor(ImagickPixel|string $background): bool  {}

//    PHP_ME(imagick, setcompression, imagick_setcompression_args, ZEND_ACC_PUBLIC)
    public function setCompression(int $compression): bool  {}

//    PHP_ME(imagick, setcompressionquality, imagick_setcompressionquality_args, ZEND_ACC_PUBLIC)
    public function setCompressionQuality(int $quality): bool  {}

//    PHP_ME(imagick, setfilename, imagick_setfilename_args, ZEND_ACC_PUBLIC)
    public function setFilename(string $filename): bool  {}

//    PHP_ME(imagick, setformat, imagick_setformat_args, ZEND_ACC_PUBLIC)
    public function setFormat(string $format): bool  {}

//    PHP_ME(imagick, setinterlacescheme, imagick_setinterlacescheme_args, ZEND_ACC_PUBLIC)
    public function setInterlaceScheme(int $interlace_scheme): bool  {}

//    PHP_ME(imagick, setoption, imagick_setoption_args, ZEND_ACC_PUBLIC)
    public function setOption(string $key, string $value): bool  {}

//    PHP_ME(imagick, setpage, imagick_setpage_args, ZEND_ACC_PUBLIC)
    public function setPage(int $width, int $height, int $x, int $y): bool  {}

//    PHP_ME(imagick, setresourcelimit, imagick_setresourcelimit_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    public static function setResourceLimit(int $type, int $limit): bool  {}

//    PHP_ME(imagick, setresolution, imagick_setresolution_args, ZEND_ACC_PUBLIC)
    public function setResolution(float $x_resolution, float $y_resolution): bool  {}

//    PHP_ME(imagick, setsamplingfactors, imagick_setsamplingfactors_args, ZEND_ACC_PUBLIC)
    public function setSamplingFactors(array $factors): bool  {}

//    PHP_ME(imagick, setsize, imagick_setsize_args, ZEND_ACC_PUBLIC)
    public function setSize(int $columns, int $rows): bool  {}

//    PHP_ME(imagick, settype, imagick_settype_args, ZEND_ACC_PUBLIC)
    public function setType(int $image_type): bool  {}

#if MagickLibVersion > 0x628
//    PHP_MALIAS(imagick, key, getiteratorindex, imagick_zero_args, ZEND_ACC_PUBLIC)
    /** @alias Imagick::getIteratorIndex */
    public function key(): int  {}

//#else
//# if defined(MAGICKCORE_EXCLUDE_DEPRECATED)
//#  error "MAGICKCORE_EXCLUDE_DEPRECATED should not be defined with ImageMagick version below 6.2.8"
//# else
////    PHP_MALIAS(imagick, key, getimageindex, imagick_zero_args, ZEND_ACC_PUBLIC)
//        /** @alias Imagick::getImageIndex */
//    public function key(): int  {}
//
//# endif
//#endif

//    PHP_MALIAS(imagick, next, nextimage, imagick_zero_args, ZEND_ACC_PUBLIC)
    /** @alias Imagick::nextImage */
    public function next(): bool  {}

//    PHP_MALIAS(imagick, rewind, setfirstiterator, imagick_zero_args, ZEND_ACC_PUBLIC)
    /** @alias Imagick::setFirstIterator */
    public function rewind(): bool  {}

//    PHP_ME(imagick, valid, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function valid(): bool  {}

//    PHP_ME(imagick, current, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function current(): Imagick  {}

#if MagickLibVersion >= 0x659
//    PHP_ME(imagick, brightnesscontrastimage, imagick_brightnesscontrastimage_args, ZEND_ACC_PUBLIC)
    public function brightnessContrastImage(
        float $brightness,
        float $contrast,
        int $channel = Imagick::CHANNEL_DEFAULT): bool {}
#endif

#if MagickLibVersion > 0x661
//    PHP_ME(imagick, colormatriximage, imagick_colormatriximage_args, ZEND_ACC_PUBLIC)
    public function colorMatrixImage(array $color_matrix = Imagick::CHANNEL_DEFAULT): bool  {}
#endif

//    PHP_ME(imagick, selectiveblurimage, imagick_selectiveblurimage_args, ZEND_ACC_PUBLIC)
    public function selectiveBlurImage(
        float $radius,
        float $sigma,
        float $threshold,
        int $channel = Imagick::CHANNEL_DEFAULT): bool {}

#if MagickLibVersion >= 0x689
//    PHP_ME(imagick, rotationalblurimage, imagick_rotationalblurimage_args, ZEND_ACC_PUBLIC)
    public function rotationalBlurImage(float $angle, int $channel = Imagick::CHANNEL_DEFAULT): bool  {}
#endif

#if MagickLibVersion >= 0x683
//    PHP_ME(imagick, statisticimage, imagick_statisticimage_args, ZEND_ACC_PUBLIC)
    public function statisticImage(
        int $type,
        int $width,
        int $height,
        int $channel = Imagick::CHANNEL_DEFAULT): bool {}
#endif

#if MagickLibVersion >= 0x652
//    PHP_ME(imagick, subimagematch, imagick_subimagematch_args, ZEND_ACC_PUBLIC)
    public function subimageMatch(imagick $Imagick, ?array &$offset, ?float &$similarity): Imagick  {}

//    ZEND_MALIAS(imagick, similarityimage, subimagematch, imagick_subimagematch_args, ZEND_ACC_PUBLIC)
    /** @alias Imagick::subimageMatch */
    public function similarityimage(imagick $Imagick, ?array &$offset, ?float &$similarity): Imagick  {}
#endif

//    PHP_ME(imagick, setregistry, imagick_setregistry_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    public static function setRegistry(string $key, string $value): bool  {}

//    PHP_ME(imagick, getregistry, imagick_getregistry_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    public static function getRegistry(string $key): string  {}

//    PHP_ME(imagick, listregistry, imagick_zero_args, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
    public static function listRegistry(): array  {}

#if MagickLibVersion >= 0x680
//    PHP_ME(imagick, morphology, imagick_morphology_args, ZEND_ACC_PUBLIC)
    public function morphology(
        int $morphologyMethod,
        int $iterations,
        ImagickKernel $ImagickKernel,
        int $channel =  Imagick::CHANNEL_DEFAULT): bool {}
#endif

#ifdef IMAGICK_WITH_KERNEL
#if MagickLibVersion < 0x700
//    PHP_ME(imagick, filter, imagick_filter_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
    /** @deprecated */
    public function filter(ImagickKernel $ImagickKernel, int $channel = Imagick::CHANNEL_UNDEFINED): bool  {}
#endif
#endif



//    PHP_ME(imagick, setantialias, imagick_setantialias_args, ZEND_ACC_PUBLIC)
    public function setAntialias(bool $antialias): null {}

//    PHP_ME(imagick, getantialias, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function getAntialias(): bool {}

#if MagickLibVersion > 0x676
//    PHP_ME(imagick, colordecisionlistimage, imagick_colordecisionlistimage_args, ZEND_ACC_PUBLIC)
    public function colorDecisionListImage(string $color_correction_collection): bool {}
#endif

#if MagickLibVersion >= 0x687
//    PHP_ME(imagick, optimizeimagetransparency, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function optimizeImageTransparency(): null {}
#endif

#if MagickLibVersion >= 0x660
//    PHP_ME(imagick, autogammaimage, imagick_autogammaimage_args, ZEND_ACC_PUBLIC)
    public function autoGammaImage(?int $channel = Imagick::CHANNEL_ALL): null {}
#endif

#if MagickLibVersion >= 0x692
//    PHP_ME(imagick, autoorient, imagick_zero_args, ZEND_ACC_PUBLIC)
    public function autoOrient(): null {}

    /** @alias Imagick::autoOrient */
    public function autoOrientate(): null {}


//    PHP_ME(imagick, compositeimagegravity, imagick_compositeimagegravity_args, ZEND_ACC_PUBLIC)
    public function compositeImageGravity(Imagick $image, int $COMPOSITE_CONSTANT, int $gravity): bool {}

#endif

#if MagickLibVersion >= 0x693
//    PHP_ME(imagick, localcontrastimage, imagick_localContrastImage_args, ZEND_ACC_PUBLIC)
    public function localContrastImage(float $radius, float $strength): null {}
#endif

#if MagickLibVersion >= 0x700
    // PHP_ME(imagick, identifyimagetype, imagick_zero_args, ZEND_ACC_PUBLIC)
    // Identifies the potential image type, returns one of the Imagick::IMGTYPE_* constants
    public function identifyImageType(): int {}
#endif


    // TODO - needs deleting from docs.
//    public function getImageMagickLicense(): string  {}

    // TODO - needs deleting from docs.
//    public function render(): bool  {}

//    public function floodfillPaintImage(
//        ImagickPixel|string $fill,
//        float $fuzz,
//        ImagickPixel|string $bordercolor,
//        int $x,
//        int $y,
//        bool $invert,
//        int $channel = Imagick::CHANNEL_DEFAULT): null {}
}
