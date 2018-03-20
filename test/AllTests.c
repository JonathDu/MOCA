

/* This is auto-generated code. Edit at your own peril. */
#include <stdio.h>
#include <stdlib.h>

#include "CuTest.h"


extern void TestCheckEmpty(CuTest*);
extern void TestCheckFull(CuTest*);
extern void TestCheckColPleine(CuTest*);
extern void TestGetLigneLibre(CuTest*);
extern void TestGetNbColonneVide(CuTest*);
extern void TestnumColonneVide(CuTest*);


void RunAllTests(void) 
{
    CuString *output = CuStringNew();
    CuSuite* suite = CuSuiteNew();


    SUITE_ADD_TEST(suite, TestCheckEmpty);
    SUITE_ADD_TEST(suite, TestCheckFull);
    SUITE_ADD_TEST(suite, TestCheckColPleine);
    SUITE_ADD_TEST(suite, TestGetLigneLibre);
    SUITE_ADD_TEST(suite, TestGetNbColonneVide);
    SUITE_ADD_TEST(suite, TestnumColonneVide);

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

