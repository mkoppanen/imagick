<?php

/** @generate-function-entries */

class ImagickPixelIterator {
    public function clear(): bool {}
    public function __construct( Imagick $wand ) {}
    public function destroy(): bool {}
    public function getCurrentIteratorRow(): array {}
    public function getIteratorRow(): int {}
    public function getNextIteratorRow(): array {}
    public function getPreviousIteratorRow(): array {}
    public function newPixelIterator(Imagick $wand ): bool {}
    public function newPixelRegionIterator(
        Imagick $wand,
        int $x,
        int $y,
        int $columns,
        int $rows ): bool {}
    public function resetIterator(): bool {}
    public function setIteratorFirstRow(): bool {}
    public function setIteratorLastRow(): bool {}
    public function setIteratorRow( int $row ): bool {}
    public function syncIterator(): bool {}
}