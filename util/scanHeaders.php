<?php

// A simple tool to scan for missed enum entries in the ImageMagick header files.

$directory = false; 
// Either pass in the directory to scan or set it here.
// $directory = "/home/github/BastionRPM/zips/ImageMagick/ImageMagick-7.0.1-9";

if ($directory) {
	$pathToImageMagick = $directory;
}
else {
	if ($argc != 2) {
		echo "usage 'php scanHeaders.php /path/to/ImageMagick\n";
		exit(-1);
	}

	$pathToImageMagick = $argv[1];
}

echo "pathToImageMagick is $pathToImageMagick \n";

if (strrpos($pathToImageMagick, '/') !== 0) {
    $pathToImageMagick .= '/';
}

if (file_exists($pathToImageMagick) == false || 
	is_dir($pathToImageMagick) == false) {
	echo "Path $pathToImageMagick is not accessible.\n";
	exit(-1);
}

echo "debug 1 \n";

$includeDir = null;

$enumToCheck = [];

$im6Directory = $pathToImageMagick.'/'.'magick';
$im7Directory = $pathToImageMagick.'/'.'MagickCore';


if (file_exists($im6Directory) == true) {
	$enumToCheck = [
		'magick/compare.h' => [
			'MetricType',
		],
		'magick/colorspace.h' => [
			'ColorspaceType',
		],
		'magick/composite.h' => [
			'CompositeOperator',
		],
		'magick/compress.h' => [
			'CompressionType',
		],
		'magick/distort.h' => [
			'DistortImageMethod',
			'SparseColorMethod',
		],
		'magick/effect.h' => [
			'PreviewType',
		],
		'magick/fourier.h' => [
			// 'ComplexOperator', // used by ComplexImages - not exposed in wand api
		],
		'magick/fx.h' => [
			'NoiseType',
		],
		'magick/geometry.h' => [
			'GravityType',
		],
		'magick/image.h' => [
			'AlphaChannelType',
			'ImageType',
			'InterlaceType',
			'OrientationType',
			'ResolutionType',
			//'TransmitType',
		],
		'magick/layer.h' => [
			'DisposeType',
			'ImageLayerMethod',
		],
		'magick/magick-type.h' => [
			'ChannelType',
		],
		'magick/morphology.h' => [
			'KernelInfoType',
			'MorphologyMethod'
		],
		'magick/pixel.h' => [
			'InterpolatePixelMethod',
			// 'PixelComponent', // present in 6.9.2 but not used?
			// 'PixelIntensityMethod', //// Used by GrayscaleImage function that is not expose in wand api
		],
		'magick/profile.h' => [
			'RenderingIntent',
		],
		'magick/quantize.h' => [
			'DitherMethod',
		],
		'magick/resample.h' => [
			'FilterTypes',
		],
		'magick/resource_.h' => [
			'ResourceType'
		],
		'magick/statistic.h' => [
			'MagickEvaluateOperator',
			'MagickFunction',
			'StatisticType',
		],
		'magick/type.h' => [
			'StretchType',
			'StyleType',
		],
	];
}
else if (file_exists($im7Directory) == true) {
	$enumToCheck = [
		'MagickCore/compare.h' => [
			'MetricType',
		],
		'MagickCore/colorspace.h' => [
			'ColorspaceType',
		],
		'MagickCore/composite.h' => [
			'CompositeOperator',
		],
		'MagickCore/compress.h' => [
			'CompressionType',
		],
		'MagickCore/distort.h' => [
			'DistortMethod',
			'SparseColorMethod',
		],
		'MagickCore/effect.h' => [
			'PreviewType',
		],
		'MagickCore/fourier.h' => [
			// 'ComplexOperator', // used by ComplexImages - not exposed in wand api
		],
		'MagickCore/fx.h' => [
			'NoiseType',
		],
		'MagickCore/geometry.h' => [
			'GravityType',
		],
		'MagickCore/image.h' => [
			'AlphaChannelOption',
			'ImageType',
			'InterlaceType',
			'OrientationType',
			'ResolutionType',
			//'TransmitType',
		],
		'MagickCore/layer.h' => [
			'DisposeType',
			'LayerMethod',
		],
		'MagickCore/morphology.h' => [
			'KernelInfoType',
			'MorphologyMethod'
		],
		'MagickCore/pixel.h' => [
			'ChannelType',
			'PixelInterpolateMethod',
			// 'PixelComponent', // present in 6.9.2 but not used?
			// 'PixelIntensityMethod', //// Used by GrayscaleImage function that is not expose in wand api
		],
		'MagickCore/profile.h' => [
			'RenderingIntent',
		],
		'MagickCore/quantize.h' => [
			'DitherMethod',
		],
		'MagickCore/resample.h' => [
			'FilterType',
		],
		'MagickCore/resource_.h' => [
			'ResourceType'
		],
		'MagickCore/statistic.h' => [
			'MagickEvaluateOperator',
			'MagickFunction',
			'StatisticType',
		],
		'MagickCore/type.h' => [
			'StretchType',
			'StyleType',
		],
	];

}
else {
    echo "Failed to read header files from either [$im6Directory] or [$im7Directory]";
    exit(-1);
}

echo "debug 2 \n";

$imagickHelperContents = file_get_contents(__DIR__ . "/../imagick_helpers.c");

echo "debug 3 \n";

if ($imagickHelperContents == false) {
	echo "failed to read ../imagick_helpers.c\n";
	exit(-1);
}

echo "debug 4 \n";

// We don't use these enums currently.
$skipEnumList = [
//	'ComplexOperator', // used by ComplexImages - not exposed in wand api
//	'PixelComponent', // present in 6.9.2 but not used?
//	'PixelIntensityMethod', // Used by GrayscaleImage function that is not expose in wand api
];

$anyMissing = false;

foreach ($enumToCheck as $filename => $enums) {
	foreach ($enums as $enum) {
		if (in_array($enum, $skipEnumList)) {
			//We don't use these enums currently.
			continue;
		}

		$enumNameList = getEnumList($enum, $pathToImageMagick.$filename);
		foreach ($enumNameList as $enumName) {
			//echo "checking for $enumName\n";
			if (stripos($imagickHelperContents, $enumName) === false) {
				echo "value '$enumName' is missing for enum $enum.\n";
                $anyMissing = true;
			}
		}
	}
}

echo "debug 5 \n";

if ($anyMissing === true) {
    echo "Some enums are missing, so exiting with error.\n";
    exit(-1);
}

echo "debug 6 \n";

echo "Looks okay";

exit(0);


function getEnumList($enum, $filename)
{
	$fileContents = file_get_contents($filename);

	if ($fileContents === false) {
		echo "Could not read file $filename \n";
		exit(-1);
	}

	// These characters mess with the matching.
	$searchReplace = [
		','
	];

	$pregString = '#\{([^\{\}]*)\}\s*'.$enum.'#sU';

	preg_match($pregString, $fileContents, $matches);

	if (count($matches) == 0) {
		echo "Couldn't find enum $enum in $filename.\n";
		return [];
	}

	$match = $matches[1];

	foreach ($searchReplace as $search) {
		$match = str_replace($search, '', $match);
	}

	$match = preg_replace('#/\*.*\*/#sU', '', $match);

	$vars = explode("\n", $match);

	$trimmedVars = [];

	foreach ($vars as $var) {
		if (stripos($var, 'Undefined') !== false) {
			continue;
		}
		$equalsPosition = strpos($var, '=');
		if ($equalsPosition !== false) {
			$var = substr($var, 0, $equalsPosition);
		}

		$entry = trim($var);

		if (strlen($entry) === 0) {
			continue;
		}
		$trimmedVars[] = $entry;
	}

	return $trimmedVars;
}
