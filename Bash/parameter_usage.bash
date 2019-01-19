#!/usr/bin/env bash

## Some tests taken from: https://wiki.bash-hackers.org/

PARAM='This Is Some Text'

echo "Original Text:          ${PARAM}"
echo "Double Quotes:         \"${PARAM}\""

## PARAMETERS EXPANSION
printf "\n\t== Parameter Expansion ==\n"
echo "Lower Case 1st char:    ${PARAM,}"
echo "Lower Case all chars:   ${PARAM,,}"
echo "Upper Case 1st char:    ${PARAM^}"
echo "Upper Case all chars:   ${PARAM^^}"
echo "Reverse Case all:       ${PARAM~~}" 

## ARRAYS
printf "\n\t== Arrays ==\n"
array=(${PARAM})
echo "Use Text as Array:      ${array[@],}"
echo "Change the 2nd element:      ${array[1]^^}"
echo "Change all elements:    ${array[@]^^}"

## Variable Name Expansion
printf "\n\t== Variable Name Expansion ==\n"
echo "All variables BASH*:    ${!BASH*}"
echo "All variables BASH@:    ${!BASH@}"

## INDIRECTION ##
# read -rep 'Which variable do you want to inspect? ' look_var
# printf 'The value of "%s" is: "%s"\n' "$look_var" "${!look_var}" 


