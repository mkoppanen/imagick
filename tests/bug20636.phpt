--TEST--
Test PECL bug #20636
--SKIPIF--
<?php

$imageMagickRequiredVersion=0x680;

require_once(dirname(__FILE__) . '/skipif.inc'); 

checkClassMethods('Imagick', array('roundCorners'));

?>
--FILE--
<?php
// This test fails to work as expected on 32bit Ubuntu. Instead of the
// image being created and then roundCorners failing, instead the image
// fails to be created with the error message "unable to acquire cache 
// view `No such file or directory' @ 
// fatal/cache-view.c/AcquireAuthenticCacheView/121"

$image = new Imagick();
$image->newImage(0, 0, '#dddddd', 'png' );

try {
    $image->roundCorners(5, 5);
    echo "fail\n";
} catch (ImagickException $e) {
    echo "success\n";
}

?>
--EXPECTF--
Deprecated: %s Imagick::roundcorners() is deprecated in %s
success
