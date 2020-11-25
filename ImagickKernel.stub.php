<?php

/** @generate-function-entries */

#ifdef IMAGICK_WITH_KERNEL
class ImagickKernel
{
    public function addKernel(ImagickKernel $kernel): void {}

    public function addUnityKernel(float $scale): void {}

    public static function fromBuiltin(int $kernel_type, string $kernelString): ImagickKernel {}

    public static function fromMatrix(array $matrix, ?array $origin): ImagickKernel {}

    public function getMatrix(): array {}


    /**
     * @param float $scale
     * @param Imagick::NORMALIZE_KERNEL_NONE|Imagick::NORMALIZE_KERNEL_VALUE|Imagick::NORMALIZE_KERNEL_CORRELATE|Imagick::NORMALIZE_KERNEL_PERCENT $normalize_type
     */
    public function scale(float $scale, ?int $normalize_type): void {}

    public function separate(): array {}
}


*







#endif

