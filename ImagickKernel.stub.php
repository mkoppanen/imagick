<?php

/** @generate-function-entries */

#ifdef IMAGICK_WITH_KERNEL
class ImagickKernel
{
    public function addKernel(ImagickKernel $ImagickKernel): void {}

    public function addUnityKernel(float $scale): void {}

    public static function fromBuiltin(int $kernelType, string $kernelString): ImagickKernel {}

    public static function fromMatrix(array $matrix, ?array $origin): ImagickKernel {}

    public function getMatrix(): array {}

    public function scale(float $scale, ?int $normalizeFlag): void {}

    public function separate(): array {}
}

#endif

