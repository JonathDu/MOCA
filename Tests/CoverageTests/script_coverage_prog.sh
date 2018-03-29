#!/bin/sh
`../../bin/connect4TheWin ../../config1.xml < $1 > /dev/null`
`mv ../../src/*.gcno .`
`mv ../../src/*.gcda .`
`lcov --base-directory . --directory . -c -o rap.info`
`genhtml rap.info --output-directory html`