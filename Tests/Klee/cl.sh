`clang -Iinclude -I${KLEE}/include -Wall -Werror -DKLEE -emit-llvm -g -c  src/utils.c`
`clang -Iinclude -I${KLEE}/include -Wall -Werror -DKLEE -emit-llvm -g -c  src/IA.c`
`clang -Iinclude -I${KLEE}/include -Wall -Werror -DKLEE -emit-llvm -g -c  src/config.c`
`clang -Iinclude -I${KLEE}/include -Wall -Werror -DKLEE -emit-llvm -g -c  src/undoRedo.c`
`clang -Iinclude -I${KLEE}/include -Wall -Werror -DKLEE -emit-llvm -g -c  src/affichage.c`
`clang -Iinclude -I${KLEE}/include -Wall -Werror -DKLEE -emit-llvm -g -c  src/connect4TheWin.c`
`clang -Iinclude -I${KLEE}/include -Wall -Werror -DKLEE -emit-llvm -g -c  src/deroulementJeu.c`

`llvm-link utils.bc affichage.bc config.bc IA.bc undoRedo.bc deroulementJeu.bc connect4TheWin.bc -o appli.bc`

`mv *.bc Tests/Klee`

`cd Tests/Klee; chemin=../../; klee appli.bc $chemin$1 > /dev/null`
