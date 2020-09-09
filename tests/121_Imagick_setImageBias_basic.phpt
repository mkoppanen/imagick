--TEST--
Test Imagick, setImageBias
--SKIPIF--
<?php 
    require_once(dirname(__FILE__) . '/skipif.inc'); 
    checkClassMethods('Imagick', array('setImageBias'));
?>
--FILE--
<?php

$bias = 0.5;

//requires ImageMagick version 6.9.0-1 to have an effect on convolveImage
function setImageBias($bias) {
    $imagick = new \Imagick();
    $imagick->newPseudoImage(640, 480, "magick:logo");

    $xKernel = array(
        -0.70, 0, 0.70,
        -0.70, 0, 0.70,
        -0.70, 0, 0.70
    );

    $imagick->setImageBias($bias * \Imagick::getQuantum());
    $imagick->convolveImage($xKernel, \Imagick::CHANNEL_ALL);

    $imagick->setImageFormat('png');

    $bytes = $imagick->getImageBlob();
    if (strlen($bytes) <= 0) { echo "Failed to generate image.";} 
}

setImageBias($bias) ;
echo "Ok";
?>
--EXPECTF--
Deprecated: %s Imagick::setImageBias() is deprecated in %s
Ok
