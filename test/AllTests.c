

/* This is auto-generated code. Edit at your own peril. */
#include <stdio.h>
#include <stdlib.h>

#include "CuTest.h"


extern void TestCheckFull(CuTest*);
extern void TestCheckEmpty(CuTest*);
extern void TestCheckColPleine(CuTest*);
extern void TestGetLigneLibre(CuTest*);
extern void TestGetNbColonneVide(CuTest*);
extern void TestnumColonneVide(CuTest*);
extern void TestRowNum(CuTest*);
extern void TestPlayer(CuTest*);
extern void TestInitBoard(CuTest*);
extern void TestPurge(CuTest*);
extern void TestEasy(CuTest*);
extern void TestMedium(CuTest*);
extern void TestHard(CuTest*);
extern void TestScore(CuTest*);


void RunAllTests(void) 
{
    CuString *output = CuStringNew();
    CuSuite* suite = CuSuiteNew();


    SUITE_ADD_TEST(suite, TestCheckFull);
    SUITE_ADD_TEST(suite, TestCheckEmpty);
    SUITE_ADD_TEST(suite, TestCheckColPleine);
    SUITE_ADD_TEST(suite, TestGetLigneLibre);
    SUITE_ADD_TEST(suite, TestGetNbColonneVide);
    SUITE_ADD_TEST(suite, TestnumColonneVide);
    SUITE_ADD_TEST(suite, TestRowNum);
    SUITE_ADD_TEST(suite, TestPlayer);
    SUITE_ADD_TEST(suite, TestInitBoard);
    SUITE_ADD_TEST(suite, TestPurge);
    SUITE_ADD_TEST(suite, TestEasy);
    SUITE_ADD_TEST(suite, TestMedium);
    SUITE_ADD_TEST(suite, TestHard);
    SUITE_ADD_TEST(suite, TestScore);

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
    CuStringDelete(output);
    CuSuiteDelete(suite);
}

int main(void)
{
    RunAllTests();
}

