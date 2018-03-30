#!/bin/sh
`../../bin/test ../../config1.xml < $1 > /dev/null`
`mv ../../src/*.gcno .`
`mv ../../src/*.gcda .`
`mv ../../Tests/UnitTests/*.gcno .`
`mv ../../Tests/UnitTests/*.gcda .`
`lcov --base-directory . --directory . -c -o rap.info`
`genhtml rap.info --output-directory html`
