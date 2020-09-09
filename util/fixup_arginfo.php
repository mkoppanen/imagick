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

$search[] = "#.*Stub hash: (.*) .*/#iu";
$replace[] = "* Stub hash: regen with 'sh regen_arginfo.sh' */";

$search[] = "#ZEND_ARG_OBJ_INFO\(0, (\w*), IMAGICK_QUANTUM_TYPE, 0\)#iu";
$replace[] = "
#if MAGICKCORE_HDRI_ENABLE 
	ZEND_ARG_TYPE_INFO(0, $1, IS_DOUBLE, 0)
#else
	ZEND_ARG_TYPE_INFO(0, $1, IS_LONG, 0)
#endif
";


// ZEND_ARG_TYPE_INFO(pass_by_ref, name, type_hint, allow_null)
// ZEND_ARG_INFO(pass_by_ref, name)

$search[] = "#ZEND_ARG_TYPE_INFO\((\w*), (\w*), (\w*), (\w*)\)#iu";
$replace[] = "
#if PHP_VERSION_ID >= 80000
    ZEND_ARG_TYPE_INFO($1, $2, $3, $4)
#else
    ZEND_ARG_INFO($1, $2)
#endif";


$search[] = "#ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX\((\w*), 0, 1, IMAGICK_QUANTUM_TYPE, 0\)#iu";
$replace[] = "
#if MAGICKCORE_HDRI_ENABLE 
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX($1, 0, 0, IS_DOUBLE, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX($1, 0, 0, IS_LONG, 0)
#endif
";


//ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(name, return_reference, required_num_args, type, allow_null)
#define ZEND_BEGIN_ARG_INFO_EX(name, _unused, return_reference, required_num_args)
$search[] = "#ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX\((\w*), (\w*), (\w*), (\w*), (\w*)\)#iu";
$replace[] = "
#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX($1, $2, $3, $4, $5)
#else
ZEND_BEGIN_ARG_INFO_EX($1, 0, $2, $3)
#endif
";

//ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(name, return_reference, required_num_args, class_name, allow_null)

$search[] = "#ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX\((\w*), (\w*), (\w*), (\w*), (\w*)\)#iu";
$replace[] = "
#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX($1, $2, $3, $4, $5)
#else
ZEND_BEGIN_ARG_INFO_EX($1, 0, $2, $3)
#endif
";


foreach ($input_lines as $input_line) {
    $input_line = rtrim($input_line);
    $input_line = preg_replace($search, $replace, $input_line);

    $output_lines[] = $input_line;
}

file_put_contents($filename, implode("\n", $output_lines));
