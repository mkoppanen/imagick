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



# function join_by { local d=$1; shift; echo -n "$1"; shift; printf "%s" "${@/#/$d}"; }


function join_by { local IFS="$1"; shift; echo "$*"; }

cflagsArray=()

if [[ "${TRAVIS_PHP_VERSION}" == "5.4" || "${TRAVIS_PHP_VERSION}" == "5.5"  ]]; then
	cflagsArray+=("-Wno-deprecated-declarations")
elif [[ "${TRAVIS_PHP_VERSION}" == "5.6" ]]; then
	CFLAGS="-Wno-deprecated-declarations -Werror -Wall -Wimplicit-function-declaration";
else
    cflagsArray+=("-Wall")
    cflagsArray+=("-Wdeclaration-after-statement")
    #cflagsArray+=("-Wbool-conversion")
    cflagsArray+=("-Wduplicate-enum")
    cflagsArray+=("-Wenum-compare")
    cflagsArray+=("-Wempty-body")
    cflagsArray+=("-Werror")
    cflagsArray+=("-Wextra")
    #cflagsArray+=("-Wformat-security")
    #cflagsArray+=("-Wformat-nonliteral")
    #cflagsArray+=("-Wheader-guard")
    cflagsArray+=("-Wimplicit-function-declaration")
    #cflagsArray+=("-Wimplicit-fallthrough")
    #cflagsArray+=("-Winit-self")
    cflagsArray+=("-Wmaybe-uninitialized")
    #cflagsArray+=("-Wmissing-format-attribute")
    #cflagsArray+=("-Wlogical-not-parentheses")
    #cflagsArray+=("-Wlogical-op")
    #cflagsArray+=("-Wlogical-op-parentheses")
    #cflagsArray+=("-Wloop-analysis")
    #cflagsArray+=("-Wno-variadic-macros")
    #cflagsArray+=("-Wno-sign-compare")
    cflagsArray+=("-Wno-deprecated-declarations")
    #cflagsArray+=("-Wparentheses
    #cflagsArray+=("-Wpointer-bool-conversion
    #cflagsArray+=("-Wsizeof-array-argument
    #cflagsArray+=("-Wstring-conversion
    #cflagsArray+=("-Wwrite-strings
fi


if [[ "${IMAGEMAGICK_VERSION}" == "6.8.7-0" ]]; then
    cflagsArray+=("-Wno-sign-compare")
    cflagsArray+=("-Wno-unused-parameter")
elif [[ "${TRAVIS_PHP_VERSION}" == "6.9.2-0" ]]; then
    cflagsArray+=("-Wno-unused-parameter")
fi




CFLAGS=$(IFS=" " ; echo "${cflagsArray[*]}")

-Werror=sign-compare



echo "Setting CFLAGS to ${CFLAGS}";

export CFLAGS=$CFLAGS;


#-fsanitize-address
#-fno-omit-frame-pointer
#-fno-optimize-sibling-calls
#-fstack-protector
#-fno-exceptions

#-Wno-unused-parameter
#-Wno-unused-but-set-variable
#-Wno-missing-field-initializers
