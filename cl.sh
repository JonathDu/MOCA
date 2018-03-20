`clang -Iinclude -I${KLEE}/include  -Wall -Werror -DKLEE -emit-llvm -g -c src/check.c`
`clang -Iinclude -I${KLEE}/include -Wall -Werror -DKLEE -emit-llvm -g -c  src/config.c`
`clang -Iinclude -I${KLEE}/include -Wall -Werror -DKLEE -emit-llvm -g -c  src/level.c`
`clang -Iinclude -I${KLEE}/include -Wall -Werror -DKLEE -emit-llvm -g -c  src/score.c`
`clang -Iinclude -I${KLEE}/include -Wall -Werror -DKLEE -emit-llvm -g -c  src/undoRedo.c`
`clang -Iinclude -I${KLEE}/include -Wall -Werror -DKLEE -emit-llvm -g -c  src/connect4TheWin.c`

`llvm-link check.bc config.bc level.bc score.bc undoRedo.bc connect4TheWin.bc -o appli.bc`
