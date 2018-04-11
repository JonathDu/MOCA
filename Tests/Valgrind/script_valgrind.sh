#!/bin/sh
`valgrind --track-origins=yes --log-file=Tests/Valgrind/log.txt --leak-check=full bin/connect4TheWin config1.xml < $1 > /dev/null`
