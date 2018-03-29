#!/bin/sh
`afl-fuzz -i -n afl_in/ -o afl_out/ ./bin/afl < $1  @@`