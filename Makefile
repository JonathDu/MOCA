CC=gcc
CC_AFL=afl-gcc
CFLAGS= -Iinclude -Wall -g -fprofile-arcs -ftest-coverage
LDFLAGS = -pg -lgcov --coverage

PATH_SRC=src/
PATH_UNIT_TEST=Tests/UnitTests/
PATH_COV_TEST=Tests/CoverageTests/
PATH_EXEC=bin/

#export AFL=1
#CFLAGS += -DAFL=$(AFL)


COMM=$(PATH_SRC)check.o $(PATH_SRC)config.o $(PATH_SRC)level.o $(PATH_SRC)score.o $(PATH_SRC)undoRedo.o $(PATH_SRC)affichage.o

MAINCTW=$(PATH_SRC)connect4TheWin.o

MAINTESTS=$(PATH_UNIT_TEST)testCheck.o $(PATH_UNIT_TEST)testConfig.o $(PATH_UNIT_TEST)CuTest.o $(PATH_UNIT_TEST)AllTests.o

OBJS=$(COMM) $(MAINCTW)

FIC_TESTS=$(MAINTESTS) $(COMM)

GCNO=$(PATH_SRC)check.gcno $(PATH_SRC)config.gcno $(PATH_SRC)level.gcno $(PATH_SRC)score.gcno $(PATH_SRC)undoRedo.gcno $(PATH_SRC)affichage.gcno $(PATH_SRC)connect4TheWin.gcno $(PATH_TEST)testCheck.gcno $(PATH_TEST)testUndoRedo.gcno $(PATH_TEST)testConfig.gcno $(PATH_TEST)CuTest.gcno $(PATH_TEST)AllTests.gcno

GCDA=$(PATH_SRC)check.gcda $(PATH_SRC)config.gcda $(PATH_SRC)level.gcda $(PATH_SRC)score.gcda $(PATH_SRC)undoRedo.gcda $(PATH_SRC)affichage.gcda $(PATH_SRC)connect4TheWin.gcda $(PATH_TEST)testCheck.gcda $(PATH_TEST)testUndoRedo.gcda $(PATH_TEST)testConfig.gcda $(PATH_TEST)CuTest.gcda $(PATH_TEST)AllTests.gcda


EXEC=$(PATH_EXEC)connect4TheWin
TESTS=$(PATH_EXEC)test
EXECPROFILE=$(PATH_EXEC)profile
AFL=$(PATH_EXEC)afl

all: $(EXEC)

tests : $(TESTS)

profiling : $(EXECPROFILE)

klee :
	./Tests/Klee/cl.sh

afl : $(AFL)

clean :
	rm $(EXEC) $(TESTS) $(EXECPROFILE) $(COMM) $(GCNO) $(MAINCTW) $(MAINTESTS) $(GCDA) $(PATH_UNIT_TEST)*.gcno $(PATH_UNIT_TEST)*.gcda


$(EXEC) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC); mv $(PATH_SRC)*.o $(PATH_EXEC)

$(TESTS) : $(FIC_TESTS)
	$(CC) $(CFLAGS) $(FIC_TESTS) -o $(TESTS)

$(EXECPROFILE): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(EXECPROFILE)

$(AFL) : $(OBJS)
	$(CC_AFL) $(CFLAGS) $(OBJS) -o $(AFL)
