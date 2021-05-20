--TEST--
Test Imagick, setImageMask basic
--SKIPIF--
<?php
$imageMagickRequiredVersion=0x709;
require_once(dirname(__FILE__) . '/skipif.inc');
?>
--FILE--
<?php

// TODO - this doesn't really test that it works...

$imagick = new \Imagick();
$imagick->newPseudoImage(640, 480, "magick:logo");

$default_mask = $imagick->getImageMask(Imagick::PIXELMASK_READ);

if ($default_mask !== null) {
	echo "Default mask is not null but\n";
	var_dump($default_mask);
}

$mask = new Imagick();
$mask->newPseudoImage(480, 640, "gradient:black-white");
$mask->transposeImage();

$imagick->setImageMask($mask, Imagick::PIXELMASK_READ);

$mask = $imagick->getImageMask(Imagick::PIXELMASK_READ);
$mask->setImageFormat('png');
//$mask->writeImage(__DIR__ . "/i_am_a_mask.png");
//if ( !== Imagick::PIXELMASK_READ) {
//    echo "Failed to set/get Imagick::PIXELMASK_READ";
//};

$imagick->setImageMask($mask, Imagick::PIXELMASK_WRITE);

//$imagick->blurImage(15, 4);
//$imagick->writeImage(__DIR__ . "/mask_test.png");

//if ($imagick->getImageMask() !== Imagick::PIXELMASK_WRITE) {
//        echo "Failed to set/get Imagick::PIXELMASK_WRITE";
//    };

$imagick->setImageMask($mask, Imagick::PIXELMASK_COMPOSITE);
//if ($imagick->getImageMask() !== Imagick::PIXELMASK_COMPOSITE) {
//    echo "Failed to set/get Imagick::PIXELMASK_COMPOSITE";
//};

$imagick->setImageMask($mask, -1);
// $unknown_result = $imagick->getImageMask(Imagick::PIXELMASK_READ);
// todo echo "not sure what -1 should be: $unknown_result \n";

echo "Ok";
?>
--EXPECTF--
Ok