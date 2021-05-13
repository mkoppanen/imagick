
set -e
set -x

php /usr/local/lib/php/build/gen_stub.php Imagick.stub.php
php util/fixup_arginfo.php Imagick_arginfo.h

php /usr/local/lib/php/build/gen_stub.php ImagickDraw.stub.php
php util/fixup_arginfo.php ImagickDraw_arginfo.h

#php /usr/local/lib/php/build/gen_stub.php ImagickKernel.stub.php
php /usr/local/lib/php/build/gen_stub.php ImagickKernel.stub.php
php util/fixup_arginfo.php ImagickKernel_arginfo.h

php /usr/local/lib/php/build/gen_stub.php ImagickPixel.stub.php
php util/fixup_arginfo.php ImagickPixel_arginfo.h

php /usr/local/lib/php/build/gen_stub.php ImagickPixelIterator.stub.php
php util/fixup_arginfo.php ImagickPixelIterator_arginfo.h

