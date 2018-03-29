`clang -I../../include -I${KLEE}/include  -Wall -Werror -DKLEE -emit-llvm -g -c ../../src/check.c`
`clang -I../../include -I${KLEE}/include -Wall -Werror -DKLEE -emit-llvm -g -c  ../../src/config.c`
`clang -I../../include -I${KLEE}/include -Wall -Werror -DKLEE -emit-llvm -g -c  ../../src/level.c`
`clang -I../../include -I${KLEE}/include -Wall -Werror -DKLEE -emit-llvm -g -c  ../../src/score.c`
`clang -I../../include -I${KLEE}/include -Wall -Werror -DKLEE -emit-llvm -g -c  ../../src/undoRedo.c`
`clang -I../../include -I${KLEE}/include -Wall -Werror -DKLEE -emit-llvm -g -c  ../../src/affichage.c`
`clang -I../../include -I${KLEE}/include -Wall -Werror -DKLEE -emit-llvm -g -c  ../../src/connect4TheWin.c`

`llvm-link check.bc affichage.bc config.bc level.bc score.bc undoRedo.bc connect4TheWin.bc -o appli.bc`
