#!/bin/bash

COMPILER=bin/c_compiler

TESTDIR=$1

mkdir -p working

EXPECTED="IFT  IFF IFELSET  IFELSEF  WHILE0   WHILEN    RECURSION   GLOBAL   MAIN    ATOI"


for NAME in $EXPECTED ; do
    
    >&2 echo "-----------------------------------------------------"    
    >&2 echo "Looking for user test case $NAME"

    if [[ ! -f test_deliverable/testcases/test_${NAME}.c ]] ; then
        >&2 echo "ERROR: Missing test file test_deliverable/testcases/test_${NAME}.c"
        continue
    fi

    if [[ ! -f test_deliverable/testcases/test_${NAME}_driver.c ]] ; then
        >&2 echo "ERROR: Missing test driver file test_deliverable/testcases/test_${NAME}_driver.c"
        continue
    fi
    
    # Compile driver with normal GCC
    gcc $DRIVER -o $TESTDIR/${NAME}  test_deliverable/testcases/test_${NAME}.c  test_deliverable/testcases/test_${NAME}_driver.c  2> $TESTDIR/${NAME}.compile.stderr
    if [[ $? -ne 0 ]]; then
        >&2 echo "ERROR: Couldn't compile testcase using GCC."
        continue
    fi
    
    # Run the actual executable
    $TESTDIR/${NAME}
    RES=$?
    if [[ $RES -ne 0 ]]; then
        >&2 echo "ERROR: Testcase returned $RES, but expected 0."
        continue
    fi

    >&2 echo "pass (in that it compiles and runs, not that it necessarily tests the feature)"
    >&2 echo ""
done
