--TEST--
Test Imagick, convolveImage
--SKIPIF--
<?php
$imageMagickRequiredVersion=0x675;
$imageMagickBelowVersion=0x700;
require_once(dirname(__FILE__) . '/skipif.inc');
?>
--FILE--
<?php

$bias = 0.5;
$kernelMatrix = array (
  0 => -1,
  1 => -1,
  2 => -1,
  3 => -1,
  4 => 8,
  5 => -1,
  6 => -1,
  7 => -1,
  8 => -1,
);

function convolveImage($bias, $kernelMatrix) {
    $imagick = new \Imagick();
    $imagick->newPseudoImage(640, 480, "magick:logo");
    
    //$edgeFindingKernel = [-1, -1, -1, -1, 8, -1, -1, -1, -1,];
    
    $imagick->setImageBias($bias * \Imagick::getQuantum());
    $imagick->convolveImage($kernelMatrix);
    $bytes = $imagick->getImageBlob();
    if (strlen($bytes) <= 0) { echo "Failed to generate image.";} 
}

convolveImage($bias, $kernelMatrix) ;
echo "Ok";
?>
--EXPECTF--
Deprecated: %s Imagick::setImageBias() is deprecated in %s
Ok
