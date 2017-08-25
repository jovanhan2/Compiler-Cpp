#!/bin/bash
echo `make clean`
echo `make bin/c_compiler`


if [[ -z "$1" ]]; then
    COMPILER=bin/c_compiler
else
    COMPILER=$1
fi

mkdir -p working
declare -i var1   # var1 is an integer.
var1=0
declare -i pass
pass=0
for DRIVER in test_deliverable/testcases/*_driver.c ; do
  var1=var1+1
    NAME=$(basename $DRIVER _driver.c)
    TESTCODE=test_deliverable/testcases/$NAME.c

    >&2 echo "Test case $NAME"

    # Compile driver with normal GCC
    mips-linux-gnu-gcc -c $DRIVER -o working/${NAME}_driver.o 2> working/${NAME}_driver.compile.stderr
    if [[ $? -ne 0 ]]; then
        >&2 echo "ERROR : Couldn't compile driver program using GCC."
        continue
    fi

    # Compile test function with compiler under test to assembly

    cat $TESTCODE | $COMPILER > working/$NAME.s  2> working/${NAME}.compile.stderr
    if [[ $? -ne 0 ]]; then
        >&2 echo "ERROR : Compiler returned error message."
        continue
    fi

    # Link driver object and assembly into executable
    mips-linux-gnu-gcc -static working/${NAME}.s working/${NAME}_driver.o -o working/${NAME}.elf 2> working/${NAME}.link.stderr
    if [[ $? -ne 0 ]]; then
        >&2 echo "ERROR : Linker returned error message."
        continue
    fi

    # Run the actual executable
    qemu-mips working/${NAME}.elf
    if [[ $? -ne 0 ]]; then
        >&2 echo "ERROR : Testcase returned ${?}, but expected 0."
        pass=pass-1
    fi

    echo "pass"
    pass=pass+1
    echo "======================================================="
done
echo "${pass} test passed out of $var1"