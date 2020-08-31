<?php


// Run with something like:
// export CLFAGS=$(php util/calculate_cflags.php "8.0" "7.0.1-0")

if ($argc !== 3) {
    fwrite(STDERR, "usage php calculate_cflags.php \$PHP_VERSION \$IMAGEMAGICK_VERSION \n");
    exit(-1);
}

$TRAVIS_PHP_VERSION = $argv[1];
$IMAGEMAGICK_VERSION = $argv[2];

$message = sprintf(
    "Calculating for PHP_VERSION [%s] IMAGEMAGICK_VERSION [%s]\n",
    $TRAVIS_PHP_VERSION,
    $IMAGEMAGICK_VERSION
);
fwrite(STDERR, $message);

$CFLAGS = array(
    "-Wno-deprecated-declarations",
    "-Wdeclaration-after-statement",
    "-Werror",
    "-Wall",
    "-Wextra",
    "-Wimplicit-function-declaration",
    "-Wno-variadic-macros",
    "-Wno-sign-compare",

    //Errors in IM6.9.2-0
    "-Wno-error=unused-parameter",
);





if ($TRAVIS_PHP_VERSION == "5.4" || $TRAVIS_PHP_VERSION == "5.5") {
    $CFLAGS = array("-Wno-deprecated-declarations");
}
else if ($TRAVIS_PHP_VERSION == "5.6") {
    $CFLAGS = array(
        "-Wno-deprecated-declarations",
        "-Wno-declaration-after-statement",
        "-Werror",
        "-Wall",
        "-Wimplicit-function-declaration"
    );
}

$result = implode(" ", $CFLAGS);
echo $result;
fwrite(STDERR, "Ok. CFLAGS are: $result\n");
