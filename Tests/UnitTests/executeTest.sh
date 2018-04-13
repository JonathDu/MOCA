#!/bin/sh
`cd Tests/UnitTests; ./make-tests.sh > AllTests.c`
make testsCompil
./bin/test < Tests/UnitTests/testPurge
