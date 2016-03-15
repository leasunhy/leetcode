#!/bin/bash

set -e

test $# -lt 2 && exit 1

EXT="cpp"
NUMBER=$1
TITLE=$2
PROBLEM="$NUMBER.$TITLE"
FN="$PROBLEM.$EXT"

echo -e "// Date: $(date -I)\n\n" >> "$FN"
vim "$FN"
dos2unix "$FN"
git add "$FN"
git commit -m "$PROBLEM"

