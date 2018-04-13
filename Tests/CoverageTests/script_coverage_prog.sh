#!/bin/sh
`bin/connect4TheWin config1.xml < $1 > /dev/null`
`mv src/*.gcno Tests/CoverageTests/`
`mv src/*.gcda Tests/CoverageTests/`
`cd Tests/CoverageTests; lcov --base-directory . --directory . -c -o rap_Programme.info`
`cd Tests/CoverageTests; genhtml rap_Programme.info --output-directory html_Programme`