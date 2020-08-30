<?php

/** @generate-function-entries */

class ImagickPixel
{
    public function __construct(?string $color) {}

    public function clear(): bool {}

    /** @alias ImagickPixel::clear */
    public function destroy(): bool {}

    public function getColor(int $normalized = 0): array {}

    public function getColorAsString(): string {}

    public function getColorCount(): int {}

    public function getColorQuantum(): array {}

    public function getColorValue(int $color): IMAGICK_QUANTUM_TYPE {}

    /**
     * @param int $color
     * @return mixed
     * - Float if IM compiled with HDRI
     * - int if IM compiled with fixed point math
     */
    public function getColorValueQuantum(int $color): IMAGICK_QUANTUM_TYPE {}

    public function getHSL(): array {}

    public function getIndex(): int {}

    public function isPixelSimilar(ImagickPixel|string $color, float $fuzz): bool {}

    public function isPixelSimilarQuantum(ImagickPixel|string $color, float $fuzz): bool {}

    /** @alias ImagickPixel::isPixelSimilarQuantum */
    public function isSimilar(ImagickPixel|string $color, float $fuzz ): bool{}

    public function setColor(string $color): bool {}

    public function setColorCount(int $colorCount): bool {}

    public function setColorValue(int $color, float $value): bool {}

    /**
     * @param int $color
     * @param mixed $value
     * @return bool
     *
     * Type of value depends on how ImageMagick was compiled.
     * - Float if IM compiled with HDRI
     * - int if IM compiled with fixed point math
     *
     */
    public function setColorValueQuantum(int $color, IMAGICK_QUANTUM_TYPE $value): bool{}

    public function setHSL(float $hue, float $saturation , float $luminosity): bool{}

    public function setIndex(int $index): bool {}

    //// Not in docs.
#if MagickLibVersion >= 0x693
    public function setColorFromPixel(ImagickPixel $srcPixel): bool {}
#endif
}



