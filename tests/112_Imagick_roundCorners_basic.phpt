--TEST--
Test Imagick, roundCorners
--SKIPIF--
<?php
$imageMagickRequiredVersion=0x675;
require_once(dirname(__FILE__) . '/skipif.inc');

checkClassMethods('Imagick', array('roundCornersImage'));
?>
--FILE--
<?php


function roundCorners() {
    $imagick = new \Imagick();
    $imagick->newPseudoImage(640, 480, "magick:logo");
    $imagick->setBackgroundColor('red');

    $imagick->setbackgroundcolor('pink');

    $x_rounding = 40;
    $y_rounding = 40;
    $stroke_width = 5;
    $displace = 0;
    $size_correction = 0;

    $imagick->roundCornersImage(
            $x_rounding,
                $y_rounding,
                $stroke_width,
                $displace,
                $size_correction
    );

    $bytes = $imagick->getImageBlob();
    if (strlen($bytes) <= 0) { echo "Failed to generate image.";} 
}

roundCorners() ;
echo "Ok";
?>
--EXPECTF--
Deprecated: %s Imagick::roundCornersImage() is deprecated in %s
Ok
