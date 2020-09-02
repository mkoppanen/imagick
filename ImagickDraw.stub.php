<?php

/** @generate-function-entries */
class ImagickDraw
{
#if MagickLibVersion > 0x628
//	PHP_ME(imagickdraw, resetvectorgraphics, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function resetVectorGraphics(): bool {}
#endif
#if MagickLibVersion > 0x649
//	PHP_ME(imagickdraw, gettextkerning, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function getTextKerning(): float {}
//	PHP_ME(imagickdraw, settextkerning, imagickdraw_settextkerning_args, ZEND_ACC_PUBLIC)
    public function setTextKerning(float $kerning): bool {}
//	PHP_ME(imagickdraw, gettextinterwordspacing, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function getTextInterwordSpacing(): float {}

//	PHP_ME(imagickdraw, settextinterwordspacing, imagickdraw_settextinterwordspacing_args, ZEND_ACC_PUBLIC)
    public function setTextInterwordSpacing(float $spacing): bool {}
#endif
#if MagickLibVersion > 0x655
//	PHP_ME(imagickdraw, gettextinterlinespacing, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function getTextInterlineSpacing(): float {}
//	PHP_ME(imagickdraw, settextinterlinespacing, imagickdraw_settextinterlinespacing_args, ZEND_ACC_PUBLIC)
    public function setTextInterlineSpacing(float $spacing): bool {}
#endif
//	PHP_ME(imagickdraw, __construct, imagickdraw_zero_args, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
    public function __construct() {}
//	PHP_ME(imagickdraw, setfillcolor, imagickdraw_setfillcolor_args, ZEND_ACC_PUBLIC)
    public function setFillColor(ImagickPixel|string $fill_pixel): bool {}
//	PHP_ME(imagickdraw, setfillalpha, imagickdraw_setfillalpha_args, ZEND_ACC_PUBLIC)
    public function setFillAlpha(float $opacity): bool {}
//	PHP_ME(imagickdraw, setresolution, imagickdraw_setresolution_args, ZEND_ACC_PUBLIC)
    public function setResolution(float $x_resolution, float $y_resolution): bool {}

//	PHP_ME(imagickdraw, setstrokecolor, imagickdraw_setstrokecolor_args, ZEND_ACC_PUBLIC)
    public function setStrokeColor(ImagickPixel|string $stroke_pixel): bool {}

//	PHP_ME(imagickdraw, setstrokealpha, imagickdraw_setstrokealpha_args, ZEND_ACC_PUBLIC)
    public function setStrokeAlpha(float $opacity): bool {}

//	PHP_ME(imagickdraw, setstrokewidth, imagickdraw_setstrokewidth_args, ZEND_ACC_PUBLIC)
    public function setStrokeWidth(float $stroke_width): bool {}

//	PHP_ME(imagickdraw, clear, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function clear(): bool {}
//	PHP_ME(imagickdraw, circle, imagickdraw_circle_args, ZEND_ACC_PUBLIC)
    public function circle(float $ox, float $oy, float $px, float $py): bool {}

//	PHP_ME(imagickdraw, annotation, imagickdraw_annotation_args, ZEND_ACC_PUBLIC)
    public function annotation(float $x, float $y, string $text): bool {}

	//PHP_ME(imagickdraw, settextantialias, imagickdraw_settextantialias_args, ZEND_ACC_PUBLIC)
    public function setTextAntialias( bool $antialias): bool {}

//	PHP_ME(imagickdraw, settextencoding, imagickdraw_settextencoding_args, ZEND_ACC_PUBLIC)
    public function setTextEncoding(string $encoding): bool {}

	// PHP_ME(imagickdraw, setfont, imagickdraw_setfont_args, ZEND_ACC_PUBLIC)
    public function setFont(string $font_name): bool {}

//	PHP_ME(imagickdraw, setfontfamily, imagickdraw_setfontfamily_args, ZEND_ACC_PUBLIC)
    public function setFontFamily(string $font_family): bool {}

//	PHP_ME(imagickdraw, setfontsize, imagickdraw_setfontsize_args, ZEND_ACC_PUBLIC)
    public function setFontSize(float $pointsize): bool {}

//	PHP_ME(imagickdraw, setfontstyle, imagickdraw_setfontstyle_args, ZEND_ACC_PUBLIC)
    public function setFontStyle(int $style): bool {}

//	PHP_ME(imagickdraw, setfontweight, imagickdraw_setfontweight_args, ZEND_ACC_PUBLIC)
    public function setFontWeight(int $font_weight): bool {}

//	PHP_ME(imagickdraw, getfont, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function getFont(): string {}

//	PHP_ME(imagickdraw, getfontfamily, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function getFontFamily(): string {}


//	PHP_ME(imagickdraw, getfontsize, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function getFontSize(): float {}

//	PHP_ME(imagickdraw, getfontstyle, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function getFontStyle(): int {}

//	PHP_ME(imagickdraw, getfontweight, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function getFontWeight(): int {}

//	ZEND_MALIAS(imagickdraw, destroy, clear, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    /** @alias ImagickDraw::clear */
    public function destroy(): bool {}

//	PHP_ME(imagickdraw, rectangle, imagickdraw_rectangle_args, ZEND_ACC_PUBLIC)
    public function rectangle(float $x1, float $y1, float $x2, float $y2): bool {}

//	PHP_ME(imagickdraw, roundrectangle, imagickdraw_roundrectangle_args, ZEND_ACC_PUBLIC)
    public function roundRectangle(float $x1, float $y1, float $x2, float $y2, float $rx, float $ry): bool {}

//	PHP_ME(imagickdraw, ellipse, imagickdraw_ellipse_args, ZEND_ACC_PUBLIC)
    public function ellipse(float $ox, float $oy, float $rx, float $ry, float $start, float $end): bool {}

//	PHP_ME(imagickdraw, skewx, imagickdraw_skewx_args, ZEND_ACC_PUBLIC)
    public function skewX(float $degrees): bool {}

//	PHP_ME(imagickdraw, skewy, imagickdraw_skewy_args, ZEND_ACC_PUBLIC)
    public function skewY(float $degrees): bool {}

//	PHP_ME(imagickdraw, translate, imagickdraw_translate_args, ZEND_ACC_PUBLIC)
    public function translate(float $x, float $y): bool {}

//	PHP_ME(imagickdraw, line, imagickdraw_line_args, ZEND_ACC_PUBLIC)
    public function line(float $sx, float $sy, float $ex, float $ey): bool {}

//	PHP_ME(imagickdraw, arc, imagickdraw_arc_args, ZEND_ACC_PUBLIC)
    public function arc(float $sx, float $sy, float $ex, float $ey, float $sd, float $ed): bool {}

#if MagickLibVersion >= 0x700
//	PHP_ME(imagickdraw, alpha, imagickdraw_matte_args, ZEND_ACC_PUBLIC)
    public function alpha(float $x, float $y, int $paintMethod): bool {}
#else
//	PHP_ME(imagickdraw, matte, imagickdraw_matte_args, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
    public function matte(float $x, float $y, int $paintMethod): bool {}
#endif

//	PHP_ME(imagickdraw, polygon, imagickdraw_polygon_args, ZEND_ACC_PUBLIC)
    public function polygon(array $coordinates): bool {}

//	PHP_ME(imagickdraw, point, imagickdraw_point_args, ZEND_ACC_PUBLIC)
    public function point(float $x, float $y): bool {}

//	PHP_ME(imagickdraw, gettextdecoration, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function getTextDecoration(): int {}

//	PHP_ME(imagickdraw, gettextencoding, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function getTextEncoding(): string {}

//	PHP_ME(imagickdraw, getfontstretch, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function getFontStretch(): int {}

//	PHP_ME(imagickdraw, setfontstretch, imagickdraw_setfontstretch_args, ZEND_ACC_PUBLIC)
    public function setFontStretch(int $fontStretch): bool {}

//	PHP_ME(imagickdraw, setstrokeantialias, imagickdraw_setstrokeantialias_args, ZEND_ACC_PUBLIC)
    public function setStrokeAntialias( bool $stroke_antialias): bool {}

//	PHP_ME(imagickdraw, settextalignment, imagickdraw_setfontalignment_args, ZEND_ACC_PUBLIC)
    public function setTextAlignment(int $alignment): bool {}

//	PHP_ME(imagickdraw, settextdecoration, imagickdraw_settextdecoration_args, ZEND_ACC_PUBLIC)
    public function setTextDecoration(int $decoration): bool {}

//	PHP_ME(imagickdraw, settextundercolor, imagickdraw_settextundercolor_args, ZEND_ACC_PUBLIC)
    public function setTextUnderColor(ImagickPixel|string $under_color): bool {}

//	PHP_ME(imagickdraw, setviewbox, imagickdraw_setviewbox_args, ZEND_ACC_PUBLIC)
    public function setViewbox(int $x1, int $y1, int $x2, int $y2): bool {}

  	//PHP_ME(imagickdraw, clone, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function clone(): ImagickDraw {}

//	PHP_ME(imagickdraw, affine, imagickdraw_affine_args, ZEND_ACC_PUBLIC)
    public function affine(array $affine): bool {}

//    PHP_ME(imagickdraw, bezier, imagickdraw_bezier_args, ZEND_ACC_PUBLIC)
    public function bezier(array $coordinates): bool {}

//	PHP_ME(imagickdraw, composite, imagickdraw_composite_args, ZEND_ACC_PUBLIC)
    public function composite(int $compose, float $x, float $y, float $width, float $height, Imagick $compositeWand): bool {}

//	PHP_ME(imagickdraw, color, imagickdraw_color_args, ZEND_ACC_PUBLIC)
    public function color(float $x, float $y, int $paintMethod): bool {}

//	PHP_ME(imagickdraw, comment, imagickdraw_comment_args, ZEND_ACC_PUBLIC)
    public function comment(string $comment): bool {}

//	PHP_ME(imagickdraw, getclippath, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function getClipPath(): string {}

//	PHP_ME(imagickdraw, getcliprule, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function getClipRule(): int {}

//	PHP_ME(imagickdraw, getclipunits, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function getClipUnits(): int {}

//	PHP_ME(imagickdraw, getfillcolor, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function getFillColor(): ImagickPixel {}

//	PHP_ME(imagickdraw, getfillopacity, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function getFillOpacity(): float {}

//	PHP_ME(imagickdraw, getfillrule, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function getFillRule(): int {}

//	PHP_ME(imagickdraw, getgravity, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function getGravity(): int {}

//	PHP_ME(imagickdraw, getstrokeantialias, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function getStrokeAntialias(): bool {}

//	PHP_ME(imagickdraw, getstrokecolor, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function getStrokeColor(): ImagickPixel {}

//	PHP_ME(imagickdraw, getstrokedasharray, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function getStrokeDashArray(): array {}

//	PHP_ME(imagickdraw, getstrokedashoffset, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function getStrokeDashOffset(): float {}

//	PHP_ME(imagickdraw, getstrokelinecap, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function getStrokeLineCap(): int {}

//	PHP_ME(imagickdraw, getstrokelinejoin, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function getStrokeLineJoin(): int {}

//	PHP_ME(imagickdraw, getstrokemiterlimit, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function getStrokeMiterLimit(): int {}

//	PHP_ME(imagickdraw, getstrokeopacity, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function getStrokeOpacity(): float {}

//	PHP_ME(imagickdraw, getstrokewidth, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function getStrokeWidth(): float {}

//	PHP_ME(imagickdraw, gettextalignment, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function getTextAlignment(): int {}

//	PHP_ME(imagickdraw, gettextantialias, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function getTextAntialias(): bool {}

//	PHP_ME(imagickdraw, getvectorgraphics, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function getVectorGraphics(): string {}

//	PHP_ME(imagickdraw, gettextundercolor, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function getTextUnderColor(): ImagickPixel {}

//	PHP_ME(imagickdraw, pathclose, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function pathClose(): bool {}

//	PHP_ME(imagickdraw, pathcurvetoabsolute, imagickdraw_pathcurvetoabsolute_args, ZEND_ACC_PUBLIC)
    public function pathCurveToAbsolute(float $x1, float $y1, float $x2, float $y2, float $x, float $y): bool {}

//	PHP_ME(imagickdraw, pathcurvetorelative, imagickdraw_pathcurvetorelative_args, ZEND_ACC_PUBLIC)
    public function pathCurveToRelative(float $x1, float $y1, float $x2, float $y2, float $x, float $y): bool {}

//	PHP_ME(imagickdraw, pathcurvetoquadraticbezierabsolute, imagickdraw_pathcurvetoquadraticbezierabsolute_args, ZEND_ACC_PUBLIC)
    public function pathCurveToQuadraticBezierAbsolute(float $x1, float $y1, float $x, float $y): bool {}

//	PHP_ME(imagickdraw, pathcurvetoquadraticbezierrelative, imagickdraw_pathcurvetoquadraticbezierrelative_args, ZEND_ACC_PUBLIC)
    public function pathCurveToQuadraticBezierRelative(float $x1, float $y1, float $x, float $y): bool {}

//	PHP_ME(imagickdraw, pathcurvetoquadraticbeziersmoothabsolute, imagickdraw_pathcurvetoquadraticbeziersmoothabsolute_args, ZEND_ACC_PUBLIC)
    public function pathCurveToQuadraticBezierSmoothAbsolute(float $x, float $y): bool {}

//	PHP_ME(imagickdraw, pathcurvetoquadraticbeziersmoothrelative, imagickdraw_pathcurvetoquadraticbeziersmoothrelative_args, ZEND_ACC_PUBLIC)
    public function pathCurveToQuadraticBezierSmoothRelative(float $x, float $y): bool {}

//	PHP_ME(imagickdraw, pathcurvetosmoothabsolute, imagickdraw_pathcurvetosmoothabsolute_args, ZEND_ACC_PUBLIC)
    public function pathCurveToSmoothAbsolute(float $x2, float $y2, float $x, float $y): bool {}

//	PHP_ME(imagickdraw, pathcurvetosmoothrelative, imagickdraw_pathcurvetosmoothrelative_args, ZEND_ACC_PUBLIC)
    public function pathCurveToSmoothRelative(float $x2, float $y2, float $x, float $y): bool {}

//	PHP_ME(imagickdraw, pathellipticarcabsolute, imagickdraw_pathellipticarcabsolute_args, ZEND_ACC_PUBLIC)
    public function pathEllipticArcAbsolute(float $rx, float $ry, float $x_axis_rotation, bool $large_arc_flag, bool $sweep_flag, float $x, float $y): bool {}

//	PHP_ME(imagickdraw, pathellipticarcrelative, imagickdraw_pathellipticarcrelative_args, ZEND_ACC_PUBLIC)
    public function pathEllipticArcRelative(float $rx, float $ry, float $x_axis_rotation, bool $large_arc_flag, bool $sweep_flag, float $x, float $y): bool {}

//	PHP_ME(imagickdraw, pathfinish, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function pathFinish(): bool {}

//	PHP_ME(imagickdraw, pathlinetoabsolute, imagickdraw_pathlinetoabsolute_args, ZEND_ACC_PUBLIC)
    public function pathLineToAbsolute(float $x, float $y): bool {}

//	PHP_ME(imagickdraw, pathlinetorelative, imagickdraw_pathlinetorelative_args, ZEND_ACC_PUBLIC)
    public function pathLineToRelative(float $x, float $y): bool {}

//	PHP_ME(imagickdraw, pathlinetohorizontalabsolute, imagickdraw_pathlinetohorizontalabsolute_args, ZEND_ACC_PUBLIC)
    public function pathLineToHorizontalAbsolute(float $x): bool {}

//	PHP_ME(imagickdraw, pathlinetohorizontalrelative, imagickdraw_pathlinetohorizontalrelative_args, ZEND_ACC_PUBLIC)
    public function pathLineToHorizontalRelative(float $x): bool {}

//	PHP_ME(imagickdraw, pathlinetoverticalabsolute, imagickdraw_pathlinetoverticalabsolute_args, ZEND_ACC_PUBLIC)
    public function pathLineToVerticalAbsolute(float $y): bool {}

//	PHP_ME(imagickdraw, pathlinetoverticalrelative, imagickdraw_pathlinetoverticalrelative_args, ZEND_ACC_PUBLIC)
    public function pathLineToVerticalRelative(float $y): bool {}

//	PHP_ME(imagickdraw, pathmovetoabsolute, imagickdraw_pathmovetoabsolute_args, ZEND_ACC_PUBLIC)
    public function pathMoveToAbsolute(float $x, float $y): bool {}

//	PHP_ME(imagickdraw, pathmovetorelative, imagickdraw_pathmovetorelative_args, ZEND_ACC_PUBLIC)
    public function pathMoveToRelative(float $x, float $y): bool {}

//	PHP_ME(imagickdraw, pathstart, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function pathStart(): bool {}

//	PHP_ME(imagickdraw, polyline, imagickdraw_polyline_args, ZEND_ACC_PUBLIC)
    public function polyline(array $coordinates): bool {}

//	PHP_ME(imagickdraw, popclippath, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function popClipPath(): bool {}

//	PHP_ME(imagickdraw, popdefs, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function popDefs(): bool {}

//	PHP_ME(imagickdraw, poppattern, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function popPattern(): bool {}

//	PHP_ME(imagickdraw, pushclippath, imagickdraw_pushclippath_args, ZEND_ACC_PUBLIC)
    public function pushClipPath(string $clip_mask_id): bool {}

//	PHP_ME(imagickdraw, pushdefs, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function pushDefs(): bool {}


//	PHP_ME(imagickdraw, pushpattern, imagickdraw_pushpattern_args, ZEND_ACC_PUBLIC)
    public function pushPattern(string $pattern_id, float $x, float $y, float $width, float $height): bool {}

//	PHP_ME(imagickdraw, render, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function render(): bool {}

//	PHP_ME(imagickdraw, rotate, imagickdraw_rotate_args, ZEND_ACC_PUBLIC)
    public function rotate(float $degrees): bool {}

//	PHP_ME(imagickdraw, scale, imagickdraw_scale_args, ZEND_ACC_PUBLIC)
    public function scale(float $x, float $y): bool {}

//	PHP_ME(imagickdraw, setclippath, imagickdraw_setclippath_args, ZEND_ACC_PUBLIC)
    public function setClipPath(string $clip_mask): bool {}

//	PHP_ME(imagickdraw, setcliprule, imagickdraw_setcliprule_args, ZEND_ACC_PUBLIC)
    public function setClipRule(int $fill_rule): bool {}

//	PHP_ME(imagickdraw, setclipunits, imagickdraw_setclipunits_args, ZEND_ACC_PUBLIC)
    public function setClipUnits(int $clip_units): bool {}

//	PHP_ME(imagickdraw, setfillopacity, imagickdraw_setfillopacity_args, ZEND_ACC_PUBLIC)
    public function setFillOpacity(float $fillOpacity): bool {}

//	PHP_ME(imagickdraw, setfillpatternurl, imagickdraw_setfillpatternurl_args, ZEND_ACC_PUBLIC)
    public function setFillPatternUrl(string $fill_url): bool {}

//	PHP_ME(imagickdraw, setfillrule, imagickdraw_setfillrule_args, ZEND_ACC_PUBLIC)
    public function setFillRule(int $fill_rule): bool {}

//	PHP_ME(imagickdraw, setgravity, imagickdraw_setgravity_args, ZEND_ACC_PUBLIC)
    public function setGravity(int $gravity): bool {}

//	PHP_ME(imagickdraw, setstrokepatternurl, imagickdraw_setstrokepatternurl_args, ZEND_ACC_PUBLIC)
    public function setStrokePatternUrl(string $stroke_url): bool {}

//	PHP_ME(imagickdraw, setstrokedashoffset, imagickdraw_setstrokedashoffset_args, ZEND_ACC_PUBLIC)
    public function setStrokeDashOffset(float $dash_offset): bool {}

//	PHP_ME(imagickdraw, setstrokelinecap, imagickdraw_setstrokelinecap_args, ZEND_ACC_PUBLIC)
    public function setStrokeLineCap(int $linecap): bool {}

//	PHP_ME(imagickdraw, setstrokelinejoin, imagickdraw_setstrokelinejoin_args, ZEND_ACC_PUBLIC)
    public function setStrokeLineJoin(int $linejoin): bool {}

//	PHP_ME(imagickdraw, setstrokemiterlimit, imagickdraw_setstrokemiterlimit_args, ZEND_ACC_PUBLIC)
    public function setStrokeMiterLimit(int $miterlimit): bool {}

//	PHP_ME(imagickdraw, setstrokeopacity, imagickdraw_setstrokeopacity_args, ZEND_ACC_PUBLIC)
    public function setStrokeOpacity(float $stroke_opacity): bool {}

//	PHP_ME(imagickdraw, setvectorgraphics, imagickdraw_setvectorgraphics_args, ZEND_ACC_PUBLIC)
    public function setVectorGraphics(string $xml): bool {}

//	PHP_ME(imagickdraw, pop, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function pop(): bool {}

//	PHP_ME(imagickdraw, push, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function push(): bool {}

//	PHP_ME(imagickdraw, setstrokedasharray, imagickdraw_setstrokedasharray_args, ZEND_ACC_PUBLIC)
    public function setStrokeDashArray(array $dashArray): bool {}

#if MagickLibVersion >= 0x693
//	PHP_ME(imagickdraw, getopacity, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function getOpacity(): float {}

//	PHP_ME(imagickdraw, setopacity, imagickdraw_setopacity_args, ZEND_ACC_PUBLIC)
    public function setOpacity(float $opacity): bool {}
#endif

#if MagickLibVersion >= 0x675
//	PHP_ME(imagickdraw, getfontresolution, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function getFontResolution(): array {}

//	PHP_ME(imagickdraw, setfontresolution, imagickdraw_setfontresolution_args, ZEND_ACC_PUBLIC)
    public function setFontResolution(float $x, float $y): bool {}

//	PHP_ME(imagickdraw, getbordercolor, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function getBorderColor(): ImagickPixel {}

//	PHP_ME(imagickdraw, setbordercolor, imagickdraw_setbordercolor_args, ZEND_ACC_PUBLIC)
    public function setBorderColor(ImagickPixel|string $color): bool {}
#endif


#if MagickLibVersion >= 0x693
//	PHP_ME(imagickdraw, setdensity, imagickdraw_setdensity_args, ZEND_ACC_PUBLIC)
    public function setDensity(string $density): bool {}

//	PHP_ME(imagickdraw, getdensity, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function getDensity(): ?string {}
#endif

#if MagickLibVersion >= 0x692
//	PHP_ME(imagickdraw, gettextdirection, imagickdraw_zero_args, ZEND_ACC_PUBLIC)
    public function getTextDirection(): int {}
//	PHP_ME(imagickdraw, settextdirection, imagickdraw_settextdirection_args, ZEND_ACC_PUBLIC)
    public function setTextDirection(int $direction): bool {}
#endif
}
