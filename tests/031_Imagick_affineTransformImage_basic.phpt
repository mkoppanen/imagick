--TEST--
Test Imagick, affineTransformImage
--SKIPIF--
<?php
$imageMagickRequiredVersion=0x675;
require_once(dirname(__FILE__) . '/skipif.inc');
?>
--XFAIL--
I don't understand what values are returned in which elements of getImageChannelStatistics
--FILE--
<?php


function checkAllStatsAreValue($channelStatistics, $value) {

    if ($channelStatistics[Imagick::CHANNEL_RED]['mean'] != $value) {
        echo "Channel red is wrong " . $channelStatistics[Imagick::CHANNEL_RED]['mean'] . " vs " . $value. "\n";
    }
    if ($channelStatistics[Imagick::CHANNEL_GREEN]['mean'] != $value) {
        echo "Channel green is wrong " . $channelStatistics[Imagick::CHANNEL_GREEN]['mean'] . " vs " . $value. "\n";
    }
    if ($channelStatistics[Imagick::CHANNEL_BLUE]['mean'] != $value) {
        echo "Channel blue is wrong " . $channelStatistics[Imagick::CHANNEL_BLUE]['mean'] . " vs " . $value. "\n";
    }

    echo "Stats checked\n";
}

function affineTransformImage() {
    $imagick = new \Imagick();
    $imagick->newPseudoImage(640, 640, "xc:black");
    $draw = new \ImagickDraw();

    $angle = deg2rad(45);
    //$angle = deg2rad(3);

    $draw->setFillColor('white');
    $draw->setStrokeColor('white');
    $draw->setStrokeWidth(10.0);
    $draw->setStrokeLineCap(Imagick::LINECAP_SQUARE);
    $draw->setStrokeLineJoin(Imagick::LINEJOIN_BEVEL);

    $draw->line(
        $start_x = -50,
        $start_y = -50,
        $end_x = 690,
        $end_y = 690
    );

    $imagick->drawImage($draw);

    $draw = new \ImagickDraw();

    $affineRotate = array(
        "sx" => cos($angle), "sy" => cos($angle), 
        "rx" => sin($angle), "ry" => -sin($angle), 
        "tx" => 0, "ty" => 0,
    );

    $draw->affine($affineRotate);

    $imagick->setImageVirtualPixelMethod(Imagick::VIRTUALPIXELMETHOD_BLACK);
    $imagick->affineTransformImage($draw);
    $imagick->setImagePage($imagick->getimageWidth(), $imagick->getimageheight(), 0, 0);

    $imagick->cropImage(
        $imagick->getImageWidth() - 40,
        $imagick->getImageHeight() - 40,
        20,
        20
    );

    $imagick->setImageFormat('png');
    $imagick->writeImage(__DIR__ . '/test_031.png');


    $lineCheckBlack = clone $imagick;
    $blackout = new \ImagickDraw();
    $blackout->setStrokeColor('black');
    $blackout->setFillColor('black');
    $blackout->rectangle(
        ($lineCheckBlack->getImageWidth() / 2) - 20,
        0,
        ($lineCheckBlack->getImageWidth() / 2) + 20,
        $lineCheckBlack->getImageHeight()
    );

    $lineCheckBlack->drawImage($blackout);
    // $lineCheckBlack->writeImage(__DIR__ . '/test_031_blank.png');

    $whiteout = new \ImagickDraw();
    $lineCheckWhite = clone $imagick;
    $whiteout->setStrokeColor('white');
    $whiteout->setFillColor('white');
    $whiteout->rectangle(
        ($lineCheckBlack->getImageWidth() / 2) - 4,
        0,
        0,
        $lineCheckBlack->getImageHeight()
    );
    $whiteout->rectangle(
        ($lineCheckWhite->getImageWidth() / 2) + 4,
        0,
        $lineCheckWhite->getImageWidth(),
        $lineCheckWhite->getImageHeight()
    );

    $lineCheckWhite->drawImage($whiteout);
    // $lineCheckWhite->writeImage(__DIR__ . '/test_031_white.png');

    $channelStatistics = $lineCheckWhite->getImageChannelStatistics();

    echo "Checking white\n";
    checkAllStatsAreValue($channelStatistics, Imagick::getQuantum());


    $channelStatistics = $lineCheckBlack->getImageChannelStatistics();
//    var_dump(
//        "lineCheckBlack channel stats are:",
//        $channelStatistics
//    );

    echo "Checking black\n";
    checkAllStatsAreValue($channelStatistics, 0);

    $bytes = $imagick->getImageBlob();
    if (strlen($bytes) <= 0) { echo "Failed to generate image.";}
}

affineTransformImage() ;
echo "Ok";
?>
--CLEAN--
<?php
$f = __DIR__ . "/test_031.png";
if (file_exists($f)) unlink($f);
?>
--EXPECTF--
Checking white
Stats checked
Checking black
Stats checked
Ok
