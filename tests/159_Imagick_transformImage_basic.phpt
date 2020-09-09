--TEST--
Test Imagick, transformImage
--SKIPIF--
<?php
$imageMagickRequiredVersion=0x675;
require_once(dirname(__FILE__) . '/skipif.inc');
checkClassMethods('Imagick', array('transformimage'));
?>
--FILE--
<?php


function transformimage() {
    $imagick = new \Imagick();
    $imagick->newPseudoImage(640, 480, "magick:logo");
    $newImage = $imagick->transformImage("400x600", "200x300");
    $bytes = $newImage->getImageBlob();
    if (strlen($bytes) <= 0) { echo "Failed to generate image.";} 
}

transformimage() ;
echo "Ok";
?>
--EXPECTF--
Deprecated: %s Imagick::transformImage() is deprecated in %s
Ok
