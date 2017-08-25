#!/bin/bash

echo "========================================"
echo " Cleaning the temporaries and outputs"
make clean
#compile it with c++ compiler

#mips-linux-gnu-gcc -c -S -x c  - -o -

for i in reftesting/testcases/*; do

  b=$(basename ${i});

  mkdir -p reftesting/working/$b

  echo "==========================="
  echo ""
  echo "Input file : ${i}"
  echo "Testing $b"
  rm reftesting/working/$b/*.txt

  echo "gcc $i/$b.c $i/${b}_driver.c -o $b"

  gcc $i/$b.c $i/${b}_driver.c -o reftesting/working/${b}/${b}.out #compile program
  #run
  ./reftesting/working/${b}/${b}.out

echo $? > reftesting/working/${b}/${b}_Output.txt

#echo " $i/$b.c "
#echo " $i/${b}_driver.c "
done
