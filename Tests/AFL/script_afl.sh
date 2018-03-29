#!/bin/sh
`afl-fuzz -n -i Tests/AFL/afl_in/ -o Tests/AFL/afl_out/ bin/afl @@`
