#!/bin/sh

VER=0$(php-config --vernum 2>/dev/null)

if [ $VER -lt 70100 ]; then

	echo "You need php >= 7.1 to run this script"

elif [ ! -f build/gen_stub.php ]; then

	echo "You need to run phpize once with PHP 8 to get gen_stub.php script"

else

	set -e
	set -x

	php build/gen_stub.php Imagick.stub.php
	php util/fixup_arginfo.php Imagick_arginfo.h

	php build/gen_stub.php ImagickDraw.stub.php
	php util/fixup_arginfo.php ImagickDraw_arginfo.h

	php build/gen_stub.php ImagickKernel.stub.php
	php util/fixup_arginfo.php ImagickKernel_arginfo.h

	php build/gen_stub.php ImagickPixel.stub.php
	php util/fixup_arginfo.php ImagickPixel_arginfo.h

	php build/gen_stub.php ImagickPixelIterator.stub.php
	php util/fixup_arginfo.php ImagickPixelIterator_arginfo.h

fi
