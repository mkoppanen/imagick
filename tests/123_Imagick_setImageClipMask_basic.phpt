--TEST--
Test Imagick, setImageClipMask
--SKIPIF--
<?php
$imageMagickRequiredVersion=0x675;
require_once(dirname(__FILE__) . '/skipif.inc');
checkClassMethods('imagick', array('setImageClipMask'));

?>
--FILE--
<?php


function setImageClipMask() {
    $imagick = new \Imagick();
    $imagick->newPseudoImage(640, 480, "magick:logo");

    $width = $imagick->getImageWidth();
    $height = $imagick->getImageHeight();

    $clipMask = new \Imagick();
    $clipMask->newPseudoImage(
        $width,
        $height,
        "canvas:transparent"
    );

    $draw = new \ImagickDraw();
    $draw->setFillColor('white');
    $draw->circle(
        $width / 2,
        $height / 2,
        ($width / 2) + ($width / 4),
        $height / 2
    );
    $clipMask->drawImage($draw);
    $imagick->setImageClipMask($clipMask);

    $imagick->negateImage(false);
    $imagick->setFormat("png");

    $bytes = $imagick->getImagesBlob();
    if (strlen($bytes) <= 0) { echo "Failed to generate image.";} 
    
}

setImageClipMask() ;
echo "Ok";
?>
--EXPECTF--
Deprecated: %s Imagick::setImageClipMask() is deprecated in %s
Ok
