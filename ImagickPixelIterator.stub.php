<?php

/** @generate-function-entries */


//static
//zend_function_entry php_imagickpixeliterator_class_methods[] =
//{
//	PHP_ME(imagickpixeliterator, __construct, imagickpixeliterator_construct_args, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
//	PHP_ME(imagickpixeliterator, newpixeliterator, imagickpixeliterator_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickpixeliterator, newpixelregioniterator, imagickpixeliterator_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickpixeliterator, getiteratorrow, imagickpixeliterator_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickpixeliterator, setiteratorrow, imagickpixeliterator_setiteratorrow_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickpixeliterator, setiteratorfirstrow, imagickpixeliterator_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickpixeliterator, setiteratorlastrow, imagickpixeliterator_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickpixeliterator, getpreviousiteratorrow, imagickpixeliterator_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickpixeliterator, getcurrentiteratorrow, imagickpixeliterator_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickpixeliterator, getnextiteratorrow, imagickpixeliterator_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickpixeliterator, resetiterator, imagickpixeliterator_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickpixeliterator, synciterator, imagickpixeliterator_zero_args, ZEND_ACC_PUBLIC)
//	ZEND_MALIAS(imagickpixeliterator, destroy, clear, imagickpixeliterator_zero_args, ZEND_ACC_PUBLIC)
//	PHP_ME(imagickpixeliterator, clear, imagickpixeliterator_zero_args, ZEND_ACC_PUBLIC)
//
//	PHP_ME(imagickpixeliterator, getpixeliterator,       imagickpixeliterator_getpixeliterator_args, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
//	PHP_ME(imagickpixeliterator, getpixelregioniterator, imagickpixeliterator_getpixelregioniterator_args, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
//
//	/* Iterator interface */
//	PHP_MALIAS(imagickpixeliterator, key, getiteratorrow, imagickpixeliterator_zero_args, ZEND_ACC_PUBLIC)
//	PHP_MALIAS(imagickpixeliterator, next, getnextiteratorrow, imagickpixeliterator_zero_args, ZEND_ACC_PUBLIC)
//	PHP_MALIAS(imagickpixeliterator, rewind, resetiterator, imagickpixeliterator_zero_args, ZEND_ACC_PUBLIC)
//	PHP_MALIAS(imagickpixeliterator, current, getcurrentiteratorrow, imagickpixeliterator_zero_args, ZEND_ACC_PUBLIC)
//

//};

class ImagickPixelIterator {
    public function __construct( Imagick $wand ) {}

    public function clear(): bool {}

    public static function getPixelIterator(Imagick $source) : ImagickPixelIterator {}

    public static function getPixelRegionIterator(
        Imagick $source,
        int $x,
        int $y,
        int $columns,
        int $rows): ImagickPixelIterator {}


    /** @alias ImagickPixelIterator::clear */
    public function destroy(): bool {}

    public function getCurrentIteratorRow(): array {}

    public function getIteratorRow(): int {}

    public function getNextIteratorRow(): array {}

    public function getPreviousIteratorRow(): array {}

    /** @alias ImagickPixelIterator::getIteratorRow */
    public function key(): int {}

    /** @alias ImagickPixelIterator::getNextIteratorRow */
    public function next(): array {}

    /** @alias ImagickPixelIterator::resetIterator */
    public function rewind(): bool {}

    /** @alias ImagickPixelIterator::getCurrentIteratorRow */
    public function current(): array {}

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

    public function valid(): bool {}
}