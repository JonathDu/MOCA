#!/bin/sh
`bin/test config1.xml < $1 > /dev/null`
`mv src/*.gcno Tests/CoverageTests/`
`mv src/*.gcda Tests/CoverageTests/`

`mv Tests/UnitTests/*.gcno Tests/CoverageTests/.`
`mv Tests/UnitTests/*.gcda Tests/CoverageTests/.`

`cd Tests/CoverageTests;lcov --base-directory . --directory . -c -o rap_Unit_Test.info`
`cd Tests/CoverageTests; genhtml rap_Unit_Test.info --output-directory html_Unit_test`
