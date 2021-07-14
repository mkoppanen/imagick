--TEST--
Imagick::setImageAlpha
--SKIPIF--
<?php 
$imageMagickRequiredVersion=0x700;
require_once(dirname(__FILE__) . '/skipif.inc'); 
?>
--FILE--
<?php

require_once __DIR__ . "/../util/functions.php";



$imagick = new Imagick();
$imagick->newPseudoImage(256, 256, 'xc:purple');
$imagick->setImageAlpha(0.5);

$imagick->setImageFormat('png');
$imagick->writeImage(__DIR__ . "/setAlphaTest.png");

$pixelTypes = array(
	Imagick::PIXEL_CHAR => array(128, 0, 128, 128),
	Imagick::PIXEL_FLOAT => array(0.50196081399918, 0, 0.50196081399918, 0.5),
    Imagick::PIXEL_DOUBLE => array(0.50196078431373, 0, 0.50196078431373, 0.5),
	Imagick::PIXEL_SHORT => array(32896, 0, 32896, 32768),
);

function getColorError($type, $expected, $actual) {

    if ($type == Imagick::PIXEL_CHAR ||
        $type == Imagick::PIXEL_SHORT) {
        $string  = "Expected: " . $actual . "\n";
        $string .= "Actual  : " . $actual . "\n";

        return $string;
    }

    if ($type == Imagick::PIXEL_FLOAT) {
        return float_compare_32($expected, $actual);
    }

    if ($type == Imagick::PIXEL_DOUBLE) {
        return float_compare($expected, $actual);
    }

    echo "Unknown type: $type \n";
    exit(-1);

}


foreach ($pixelTypes as $pixelType => $expectedValues) {
	$pixels = $imagick->exportImagePixels(0, 0, 1, 1, "RGBA", $pixelType);
	$channelNames = ['R', 'G', 'B', 'A'];

	// Loop over the colours
	for ($channel=0; $channel<4; $channel++) {
		$actual = $pixels[$channel];
		$expected = $expectedValues[$channel];
		if (abs($actual - $expected) > 0.0000001) {
		    $channelName = $channelNames[$channel];

			echo "Pixel values appear incorrect for pixelType $pixelType channel:$channelName\n";
            echo getColorError($pixelType, $expected, $actual);
			break;
		}
	}
}

echo "Ok";

?>
--CLEAN--
<?php
$f = __DIR__ . '/setAlphaTest.png';
if (file_exists($f)) unlink($f);
?>
--EXPECTF--
Ok
