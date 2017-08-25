#!/bin/bash

echo "========================================"
echo " Cleaning the temporaries and outputs"
make clean
mkdir -p OUTPUT
for i in OUTPUT/*; do
rm $i
done
echo " Force building compiler (just in case)"
make -B bin/c_compiler
if [[ "$?" -ne "0" ]]; then
    echo "Error while building compiler."
    exit 1;
fi
NUMBER=0

for i in INPUTS/*; do
  NUMBER=$((NUMBER+1))
  b=$(basename ${i});
  echo "============================================================================================"
  echo ""
  echo "Input file : ${i}"
  echo "Testing $b, [${NUMBER}th test]"
  echo ""
    echo "===========================INPUT $b==========================="
  cat $i
  echo ""
  echo "===========================OUTPUT $b==========================="
  cat $i | bin/c_compiler
  cat $i | bin/c_compiler > OUTPUT/${b}_out.s
done
