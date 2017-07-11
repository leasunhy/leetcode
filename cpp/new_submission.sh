#!/bin/bash

set -e

test $# -lt 2 && exit 1

EXT="cpp"
NUMBER=$1
TITLE=$2
PROBLEM="$NUMBER.$TITLE"
FN="$PROBLEM.$EXT"

echo -e "// Date: $(date -I)\n\n" >> "$FN"

if [[ "x$EDITOR" == "x" ]]; then
    vim "$FN"
else
    $EDITOR "$FN"
fi

dos2unix "$FN"

while true; do
    read -p "Ready to commit? [y/n]" yn
    case $yn in
        [Nn]* ) exit;;
        [Yy]* ) git add "$FN";
                git commit -e -m "$PROBLEM";
                break;;
        *     ) echo "Please answer yes or no."
    esac
done

