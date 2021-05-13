--TEST--
Test Imagick::getConfigureOptions
--SKIPIF--
<?php

require_once(dirname(__FILE__) . '/skipif.inc');

checkClassMethods('Imagick', array('getconfigureoptions'));


?>
--FILE--
<?php

$allOptions = Imagick::getConfigureOptions();

if (!is_array($allOptions)) {
	echo "Failed to return array".PHP_EOL;
	var_dump($options);
}
else if (count($allOptions) == 0) {
	echo "allOptions is empty".PHP_EOL;
}


$optionsStartingWithC = Imagick::getConfigureOptions("C*");

if (!is_array($optionsStartingWithC)) {
	echo "Failed to return array".PHP_EOL;
	var_dump($optionsStartingWithC);
}
else if (count($optionsStartingWithC) == 0) {
	echo "optionsStartingWithC is empty".PHP_EOL;
}

//Example output on Debian
//
//array(38) {
//  ["CC"]=>
//  string(3) "gcc"
//  ["CFLAGS"]=>
//  string(186) "-I/usr/include/libxml2 -I/usr/include/libpng16 -I/usr/include/freetype2  -fopenmp -Wall -g -O2 -mtune=core2 -fexceptions -pthread -DMAGICKCORE_HDRI_ENABLE=1 -DMAGICKCORE_QUANTUM_DEPTH=16"
//  ["CODER_PATH"]=>
//  string(56) "/usr/local/lib/ImageMagick-7.0.11/modules-Q16HDRI/coders"
//  ["CONFIGURE"]=>
//  string(155) "./configure  '--with-quantum-depth=16' '--with-magick-plus-plus=no' '--without-perl' '--disable-static' '--disable-docs' '--with-jpeg=yes' '--with-png=yes'"
//  ["CONFIGURE_PATH"]=>
//  string(29) "/usr/local/etc/ImageMagick-7/"
//  ["COPYRIGHT"]=>
//  string(46) "Copyright (C) 1999-2021 ImageMagick Studio LLC"
//  ["CPPFLAGS"]=>
//  string(34) "-I/usr/local/include/ImageMagick-7"
//  ["CXX"]=>
//  string(3) "g++"
//  ["CXXFLAGS"]=>
//  string(9) " -pthread"
//  ["DEFS"]=>
//  string(15) "-DHAVE_CONFIG_H"
//  ["DELEGATES"]=>
//  string(33) "freetype jng jpeg png ps xml zlib"
//  ["DISTCHECK_CONFIG_FLAGS"]=>
//  string(217) " --disable-deprecated  --with-quantum-depth=16  --with-jemalloc=no  --with-umem=no  --with-autotrace=no  --with-fftw=no  --with-gslib=no  --with-fontpath=  --with-jxl=no  --with-rsvg=no  --with-wmf=no  --with-perl=no "
//  ["DOCUMENTATION_PATH"]=>
//  string(34) "/usr/local/share/doc/ImageMagick-7"
//  ["EXEC-PREFIX"]=>
//  string(10) "/usr/local"
//  ["EXECUTABLE_PATH"]=>
//  string(14) "/usr/local/bin"
//  ["FEATURES"]=>
//  string(22) "DPC HDRI Cipher OpenMP"
//  ["FILTER_PATH"]=>
//  string(57) "/usr/local/lib/ImageMagick-7.0.11/modules-Q16HDRI/filters"
//  ["GIT_REVISION"]=>
//  string(24) "18571:309fcfa1c:20210328"
//  ["HOST"]=>
//  string(19) "x86_64-pc-linux-gnu"
//  ["INCLUDE_PATH"]=>
//  string(32) "/usr/local/include/ImageMagick-7"
//  ["LDFLAGS"]=>
//  string(17) "-L/usr/local/lib "
//  ["LIB_VERSION"]=>
//  string(5) "0x70B"
//  ["LIB_VERSION_NUMBER"]=>
//  string(8) "7,0,11,6"
//  ["LIBRARY_PATH"]=>
//  string(33) "/usr/local/lib/ImageMagick-7.0.11"
//  ["LIBS"]=>
//  string(96) "    -lfreetype  -ljpeg    -lpng16                       -lxml2  -lz     -lm    -lpthread  -lgomp"
//  ["MAGICK_TEMPORARY_PATH"]=>
//  string(4) "/tmp"
//  ["NAME"]=>
//  string(11) "ImageMagick"
//  ["PCFLAGS"]=>
//  string(65) "-fopenmp -DMAGICKCORE_HDRI_ENABLE=1 -DMAGICKCORE_QUANTUM_DEPTH=16"
//  ["PREFIX"]=>
//  string(10) "/usr/local"
//  ["QuantumDepth"]=>
//  string(2) "16"
//  ["RELEASE_DATE"]=>
//  string(10) "2021-03-28"
//  ["SHARE_PATH"]=>
//  string(30) "/usr/local/share/ImageMagick-7"
//  ["SHAREARCH_PATH"]=>
//  string(48) "/usr/local/lib/ImageMagick-7.0.11/config-Q16HDRI"
//  ["TARGET_CPU"]=>
//  string(6) "x86_64"
//  ["TARGET_OS"]=>
//  string(9) "linux-gnu"
//  ["TARGET_VENDOR"]=>
//  string(2) "pc"
//  ["VERSION"]=>
//  string(6) "7.0.11"
//  ["WEBSITE"]=>
//  string(23) "https://imagemagick.org"
//}



// Examples of output on nixos
//array(5) {
//  ["DELEGATES"]=>
//  string(102) "bzlib cairo djvu fontconfig freetype heic jng jp2 jpeg lcms lzma openexr png rsvg tiff webp x xml zlib"
//  ["FEATURES"]=>
//  string(28) "Cipher DPC HDRI OpenMP(4.5) "
//  ["MAGICK_TEMPORARY_PATH"]=>
//  string(4) "/tmp"
//  ["NAME"]=>
//  string(11) "ImageMagick"
//  ["QuantumDepth"]=>
//  string(3) "Q16"
//}








if (!(count($optionsStartingWithC) < count($allOptions))) {
	echo "";
	var_dump($optionsStartingWithC);
	var_dump($allOptions);
}

foreach ($optionsStartingWithC as $key => $value) {
	$key = strtolower($key);

	if (strpos($key, "c") !== 0) {
		echo "key $key does not start with c".PHP_EOL;
	}
}

echo "Ok";

?>
--EXPECTF--
Ok