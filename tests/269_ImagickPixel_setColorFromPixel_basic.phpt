--TEST--
Test ImagickPixel, setColor
--SKIPIF--
<?php
require_once(dirname(__FILE__) . '/skipif.inc');
checkClassMethods('ImagickPixel', array('setColorFromPixel'));
?>
--FILE--
<?php


$backgroundColor = new \ImagickPixel('green');

$red = new \ImagickPixel('red');

$backgroundColor->setColorFromPixel($red);

$expected = array(
  "r" => 255,
  "g" => 0,
  "b" => 0,
  "a" => 1
);

$actualColor = $backgroundColor->getColor();

if ($actualColor != $expected) {
	echo "Not as expected :\n";
	var_dump($actualColor);
}


echo "Ok";
?>
--EXPECTF--
Ok