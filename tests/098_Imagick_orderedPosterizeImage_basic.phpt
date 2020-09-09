--TEST--
Test Imagick, orderedPosterizeImage
--SKIPIF--
<?php
$imageMagickRequiredVersion=0x675;
require_once(dirname(__FILE__) . '/skipif.inc');

checkClassMethods('Imagick', array('orderedPosterizeImage'));
?>
--FILE--
<?php

$orderedPosterizeType = "o8x8";

function orderedPosterizeImage($orderedPosterizeType) {
    $imagick = new \Imagick();
    $imagick->newPseudoImage(640, 480, "magick:logo");
    
  
    $imagick->orderedPosterizeImage($orderedPosterizeType);
    $imagick->setImageFormat('png');
    
    $bytes = $imagick->getImageBlob();
    if (strlen($bytes) <= 0) { echo "Failed to generate image.";} 
}

orderedPosterizeImage($orderedPosterizeType) ;
echo "Ok";
?>
--EXPECTF--
Deprecated: %s Imagick::orderedPosterizeImage() is deprecated in %S
Ok
