#!/bin/bash
#
# Set CFLAGS to be strict for supported versions on Travis

#containsElement () {
#  local e
#  for e in "${@:2}"; do [[ "$e" == "$1" ]] && return 0; done
#  return 1
#}


# Bash return statements are not useful. You have to echo the value
# and then capture it by calling the function with $( foo )
function contains() {
    local n=$#
    local value=${!n}
    for ((i=1;i < $#;i++)) {
        if [ "${!i}" == "${value}" ]; then
            echo "1"
            return 0
        fi
    }
    echo "0"
    return 0
}

#
#superWeakPHPVersions=()
#superWeakPHPVersions+=("5.4")
#superWeakPHPVersions+=("5.5")
#
#weakPHPVersions=()
#weakPHPVersions+=("5.6")
#
##strictPHPVersions+=("7")
##strictPHPVersions+=("7.0")
##strictPHPVersions+=("7.1")
#
#weakImageMagickVersions=()
##strictImageMagickVersions+=("dev")
##strictImageMagickVersions+=("6.8.7-0")
##strictImageMagickVersions+=("6.7.5-3")
##strictImageMagickVersions+=("6.6.0-9")
##strictImageMagickVersions+=("7.0.8-4")
##strictImageMagickVersions+=("7.0.1-0")


echo "TRAVIS_PHP_VERSION is ${TRAVIS_PHP_VERSION}"
echo "IMAGEMAGICK_VERSION is ${IMAGEMAGICK_VERSION}"

#weakImageMagick=$(contains "${weakImageMagickVersions[@]}" "${IMAGEMAGICK_VERSION}" )
#superWeakPHP=$(contains "${superWeakPHPVersions[@]}" "${TRAVIS_PHP_VERSION}" )
#weakPHP=$(contains "${weakPHPVersions[@]}" "${TRAVIS_PHP_VERSION}" )
#
#echo "weakImageMagick is ${weakImageMagick}"
#echo "superWeakPHPVersion is ${superWeakPHPVersion}"
#echo "weakPHP is ${weakPHP}"


# TODO - test if this flag is usable for the tests on all appropriate platforms
# -Wmaybe-uninitialized

if [[ "${TRAVIS_PHP_VERSION}" == "5.4" || "${TRAVIS_PHP_VERSION}" == "5.5"  ]]; then
	CFLAGS="-Wno-deprecated-declarations";
elif [[ "${TRAVIS_PHP_VERSION}" == "5.6" ]]; then
	CFLAGS="-Wno-deprecated-declarations -Wdeclaration-after-statement -Werror -Wall -Wimplicit-function-declaration";
else
    CFLAGS="-Wno-deprecated-declarations -Wdeclaration-after-statement -Werror -Wall -Wextra -Wimplicit-function-declaration";
fi

echo "Setting CFLAGS to ${CFLAGS}";

export CFLAGS=$CFLAGS;
