<?php

declare(strict_types = 1);


if ($argc !== 2) {
    fwrite(STDERR, "usage php fixup_arginfo.php \$arginfo_filename\n");
    exit(-1);
}

$filename = $argv[1];

echo "Fixing $filename\n";

$input_lines = file($filename);

$output_lines = [];

$search = [];
$replace = [];

$search[] = "#ZEND_ARG_OBJ_INFO\(0, (\w*), IMAGICK_QUANTUM_TYPE, 0\)#iu";
$replace[] = "
#if MAGICKCORE_HDRI_ENABLE 
	ZEND_ARG_TYPE_INFO(0, $1, IS_DOUBLE, 0)
#else
	ZEND_ARG_TYPE_INFO(0, $1, IS_LONG, 0)
#endif
";

$search[] = "#.*Stub hash: (.*) .*/#iu";
$replace[] = "* Stub hash: always needs regen */";


$search[] = "#ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX\((\w*), 0, 1, IMAGICK_QUANTUM_TYPE, 0\)#iu";
$replace[] = "
#if MAGICKCORE_HDRI_ENABLE 
	ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX($1, 0, 0, IS_DOUBLE, 0)
#else
	ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX($1, 0, 0, IS_LONG, 0)
#endif
";


foreach ($input_lines as $input_line) {
    $input_line = rtrim($input_line);
    $input_line = preg_replace($search, $replace, $input_line);

    $output_lines[] = $input_line;
}

file_put_contents($filename, implode("\n", $output_lines));
