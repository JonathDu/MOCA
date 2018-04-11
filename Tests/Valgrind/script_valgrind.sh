#!/bin/sh
`valgrind --track-origins=yes --log-file=Tests/Valgrind/log.txt --leak-check=full bin/connect4TheWin $1 < $2 > /dev/null`
