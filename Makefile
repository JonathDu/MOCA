CC=gcc
CFLAGS= -Iinclude -Wall -g -fprofile-arcs -ftest-coverage
LDFLAGS = -pg -lgcov --coverage

PATH_SRC=src/
PATH_UNIT_TEST=Tests/UnitTests/
PATH_COV_TEST=Tests/CoverageTests/
PATH_EXEC=bin/


#Decommenter pour utiliser AFL
#export AFLAGS=1
#CFLAGS += -DAFL=$(AFLAGS)
#export AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1
#export AFL_SKIP_CPUFREQ=1

COMM=$(PATH_SRC)IA.o $(PATH_SRC)config.o $(PATH_SRC)undoRedo.o $(PATH_SRC)affichage.o $(PATH_SRC)deroulementJeu.o $(PATH_SRC)utils.o

MAINCTW=$(PATH_SRC)connect4TheWin.o

MAINTESTS=$(PATH_UNIT_TEST)testConfig.o $(PATH_UNIT_TEST)testCheck.o $(PATH_UNIT_TEST)CuTest.o $(PATH_UNIT_TEST)AllTests.o

OBJS=$(COMM) $(MAINCTW)

FIC_TESTS=$(MAINTESTS) $(COMM)

GCNO=$(PATH_SRC)utils.gcno $(PATH_SRC)config.gcno $(PATH_SRC)IA.gcno $(PATH_SRC)score.gcno $(PATH_SRC)undoRedo.gcno $(PATH_SRC)affichage.gcno $(PATH_SRC)connect4TheWin.gcno $(PATH_SRC)deroulementJeu.gcno $(PATH_TEST)testCheck.gcno $(PATH_TEST)testUndoRedo.gcno $(PATH_TEST)testConfig.gcno $(PATH_TEST)CuTest.gcno $(PATH_TEST)AllTests.gcno

GCDA=$(PATH_SRC)utils.gcda $(PATH_SRC)config.gcda $(PATH_SRC)IA.gcda $(PATH_SRC)score.gcda $(PATH_SRC)undoRedo.gcda $(PATH_SRC)affichage.gcda $(PATH_SRC)connect4TheWin.gcda $(PATH_SRC)deroulementJeu.gcda $(PATH_TEST)testCheck.gcda $(PATH_TEST)testUndoRedo.gcda $(PATH_TEST)testConfig.gcda $(PATH_TEST)CuTest.gcda $(PATH_TEST)AllTests.gcda


EXEC=$(PATH_EXEC)connect4TheWin
TESTS=$(PATH_EXEC)test
EXECPROFILE=$(PATH_EXEC)profile
AFL=$(PATH_EXEC)afl

exec=exec pour compiler le programme

all: info

info:
	@echo "Cible disponible:"
	@echo "  exec				: Creer les binaires dans le dossier bin/"
	@echo "  tests				: Creer les binaires des fichiers de tests et les éxécute"
	@echo "  profiling CONF= args=		: Creer les binaires et execute le fichier args passer en paramètres"
	@echo "  afl CC=afl-gcc		: Compile avec afl et lance le fuzzing sur le fichier dans Tests/AFL/afl_in (make infoAfl pour plus d'info)"
	@echo "  valgrind CONF= args=		: Lance Valgrind avec le fichier args en entrée, et ecrit dans le fichier Tests/Valgrind/log.txt"
	@echo "  cache_miss CONF= args=	: Lance perf avec le fichier CONF comme fichier de configuration, et args en entrée"



infoAfl:
	@echo "Pour lancer AFL, il faut decommenter les lignes 12 à 15 sur un ordinateur sans accèes root, et 12 à 13 avec accès root, du Makefile"


exec: $(EXEC)

tests :
	./Tests/UnitTests/executeTest.sh

testsCompil : $(TESTS)

profiling : $(EXECPROFILE)

doxygen :
	doxygen Doxygen/conf

klee :
	./Tests/Klee/cl.sh $(args)

afl : $(AFL)

valgrind : $(EXEC)
	./Tests/Valgrind/script_valgrind.sh $(CONF) $(args)

cache_miss: $(EXEC)
	sudo perf stat -e cache-misses,cache-references ./bin/connect4TheWin $(CONF) < $(args) > /dev/null


clean :
	rm $(EXEC) $(TESTS) $(EXECPROFILE) $(COMM) $(GCNO) $(MAINCTW) $(MAINTESTS) $(GCDA) $(PATH_UNIT_TEST)*.gcno $(PATH_UNIT_TEST)*.gcda; rm -r Doxygen/html Doxygen/latex; rm Tests/Klee/*.bc

$(EXEC) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC); mv $(PATH_SRC)*.o $(PATH_EXEC)

$(TESTS) : $(FIC_TESTS)
	$(CC) $(CFLAGS) $(FIC_TESTS) -o $(TESTS)

$(EXECPROFILE): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(EXECPROFILE); mv $(PATH_SRC)*.o $(PATH_EXEC)
	./bin/profile $(CONF) < $(args)
	gprof bin/profile > Tests/ProfilingTests/resGprof

$(AFL) : $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(AFL); mv $(PATH_SRC)*.o $(PATH_EXEC)
	#./Tests/AFL/script_afl.sh
