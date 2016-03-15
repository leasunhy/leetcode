#!/bin/bash

set -e

test $# -lt 2 && exit 1

EXT="cpp"
NUMBER=$1
TITLE=$2
PROBLEM="$NUMBER.$TITLE"
FN="$PROBLEM.$EXT"

echo "// Date: $(date -I)" >> "$FN"
vim "$FN"
dos2unix "$FN"
git add "$FN"
git commit -m "$PROBLEM"

