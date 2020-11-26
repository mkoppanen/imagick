<?php

declare(strict_types = 1);


$classes = [
    'Imagick',
    'ImagickDraw',
    'ImagickPixel',
    'ImagickKernel'
];


foreach ($classes as $class) {
    $nameCounts = [];


    echo "class = $class \n";

    $classReflection = new ReflectionClass($class);
    $classMethods = $classReflection->getMethods();

    foreach ($classMethods as $imagickMethod) {
        $parameters = $imagickMethod->getParameters();
        foreach ($parameters as $parameter) {
            $name = $parameter->getName();
            $nameCounts[$name] = ($nameCounts[$name] ?? 0) + 1;
        }
    }


    arsort($nameCounts);

    foreach ($nameCounts as $name => $count) {
        echo "$name: $count \n";
    }

    echo "\n\n";

}

