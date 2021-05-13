--TEST--
Imagick don't borg the error handler
--SKIPIF--
<?php require_once(dirname(__FILE__) . '/skipif.inc'); ?>
--FILE--
<?php
error_reporting( E_ALL ); 

ini_set( "display_errors", true );

try {
    $f = new Imagick('http://any/url/here');
}
catch(ImagickException $ie) {
    echo "Normal exception".PHP_EOL;
}

try {
	$x = @file ('non_existent_file');
	echo "Normal warning is suppressed".PHP_EOL;
}
catch(\Exception $e) {
	echo "Abnormal exception of type: ".get_class($e)."\n";
	echo $e->getMessage();
}

?>
--EXPECTF--
Normal exception
Normal warning is suppressed