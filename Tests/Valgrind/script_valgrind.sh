#!/bin/sh
`valgrind --track-origins=yes --log-file=log.txt --leak-check=full ../../bin/connect4TheWin ../../config1.xml < $1 > /dev/null`