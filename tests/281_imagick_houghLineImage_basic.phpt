--TEST--
Test Imagick, houghLineImage
--SKIPIF--
<?php
require_once(dirname(__FILE__) . '/skipif.inc');
checkClassMethods('Imagick', array('houghLineImage'));
?>
--FILE--
<?php


function houghLineImage() {
    $path = realpath(__DIR__ . '/houghline_input_image.png');

    if ($path === false) {
        echo "Image is not readable.\n";
        exit(-1);
    }

    $imagick = new \Imagick();
    $imagick->readImage($path);
    $imagick->setbackgroundcolor('rgb(64, 64, 64)');
    $imagick->houghLineImage(20,40, 40);
    $imagick->writeImage(__DIR__ . '/houghline_output_image.png');
}

houghLineImage() ;
echo "Ok";
?>
--CLEAN--
<?php
$f = __DIR__ . '/houghline_output_image.png';
if (file_exists($f)) unlink($f);
?>
--EXPECTF--
Ok
