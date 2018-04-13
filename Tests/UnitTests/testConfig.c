#include "CuTest.h"
#include "IA.h"
#include "utilTest.h"
#include "undoRedo.h"

void TestRowNum(CuTest *tc)
{
    Board *board = init();
    for (int i = board->height - 1; i >= 0; i--)
    {
        board->board[i][0] = 'X';
    }
    for (int i = board->height - 1; i > 0; i--)
    {
        board->board[i][1] = 'X';
    }

    CuAssertIntEquals(tc, rowNum(0, board), -1);
    CuAssertIntEquals(tc, rowNum(2, board), 2);
    CuAssertIntEquals(tc, rowNum(1, board), 0);
}

void TestPlayer(CuTest *tc)
{
    Board *board = init();
    player(board, 0, 'X');
    CuAssertIntEquals(tc, rowNum(0, board), 1);
    player(board, 2, 'X');
    CuAssertIntEquals(tc, rowNum(2, board), 1);
    player(board, 2, 'X');
    player(board, 2, 'X');
    CuAssertIntEquals(tc, rowNum(2, board), -1);
}

void TestInitBoard(CuTest *tc)
{
    Board *board1 = initBoard("config1.xml");
    CuAssertIntEquals(tc, board1->width, 7);
    CuAssertIntEquals(tc, board1->height, 6);

    Board *board2 = initBoard("config2.xml");
    CuAssertIntEquals(tc, board2->width, 7);
    CuAssertIntEquals(tc, board2->height, 7);
}

void TestPurge(CuTest *tc)
{
    int a;
    readInt(&a, "");
    CuAssertIntEquals(tc, a, -10000000);
    readInt(&a, "");
    CuAssertIntEquals(tc, a, 6);
}
void TestEasy(CuTest *tc)
{
    Board *board = init2();
    int num = 0;
    Easy(board, 'O', &num);
    CuAssertIntEquals(tc, checkEmpty(board), 0);
}

void TestMedium(CuTest *tc)
{
    Board *board = init2();
    board->board[board->height - 1][1] = 'O';
    board->board[board->height - 2][1] = 'O';
    board->board[board->height - 3][1] = 'O';

    for (int i = 0; i < board->height; i++)
    {
        board->board[i][0] = 'X';
    }

    int num = 0;
    Medium(board, 'X', 'O', &num);
    afficherBoard(board);
    CuAssertIntEquals(tc, num, 1);
    CuAssertIntEquals(tc, board->board[board->height - 4][1] != '\0', 1);
}

void TestHard(CuTest *tc)
{
    Board *board = init2();
    board->board[board->height - 1][2] = 'O';
    board->board[board->height - 2][2] = 'O';
    for (int i = 0; i < board->height; i++)
    {
        board->board[i][0] = 'X';
    }
    int num = 0;
    Hard(board, 'O', 'X', &num);
    printf("bite\n");
    afficherBoard(board);
    CuAssertIntEquals(tc, num, 2);
    CuAssertIntEquals(tc, board->board[board->height - 3][2] != '\0', 1);

    board->board[board->height - 1][3] = 'X';
    board->board[board->height - 2][3] = 'X';
    board->board[board->height - 3][3] = 'X';
    Hard(board, 'O', 'X', &num);
    CuAssertIntEquals(tc, num, 3);
    CuAssertIntEquals(tc, board->board[board->height - 4][3] == 'O', 1);
    afficherBoard(board);

    Board *board2 = init2();
    board2->board[board2->height - 1][4] = 'O';
    board2->board[board2->height - 2][4] = 'O';
    board2->board[board2->height - 3][4] = 'O';
    Hard(board2, 'O', 'X', &num);
    CuAssertIntEquals(tc, num, 4);
    CuAssertIntEquals(tc, board2->board[board2->height - 4][4] == 'O', 1);
    afficherBoard(board2);

    Board *board3 = init2();
    Hard(board3, 'O', 'X', &num);
    CuAssertIntEquals(tc, checkEmpty(board), 0);
    afficherBoard(board3);
}

void TestScore(CuTest *tc)
{
    Board *board = init2();
    for (int i = board->height - 1; i >= 2; i--)
    {
        for (int j = 0; j < 4; j++)
        {
            board->board[i][j] = 'O';
        }
    }
    CuAssertIntEquals(tc, totalScore(board, 'O'), 10);
    for (int i = board->height - 1; i >= 2; i--)
    {
        board->board[i][4] = 'O';
    }
    CuAssertIntEquals(tc, totalScore(board, 'O'), 17);
    board->board[3][1] = 'X';
    CuAssertIntEquals(tc, totalScore(board, 'O'), 13);
}

void TestUndoRedo(CuTest *tc)
{
    Board *board = init2();
    char x = 'X';
    undoRedo(&x, board, 2);
    CuAssertIntEquals(tc, getLigneLibre(board, 2), 4);
    undoRedo(&x, board, -1);
    CuAssertIntEquals(tc, getLigneLibre(board, 2), 5);
    undoRedo(&x, board, -4);
    CuAssertIntEquals(tc, getLigneLibre(board, 2), 4);
    undoRedo(&x, board, -1);
    CuAssertIntEquals(tc, getLigneLibre(board, 2), 5);
    undoRedo(&x, board, -2);
    undoRedo(&x, board, -3);
}

CuSuite *testConfigGetSuite()
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, TestRowNum);
    SUITE_ADD_TEST(suite, TestPlayer);
    SUITE_ADD_TEST(suite, TestInitBoard);
    SUITE_ADD_TEST(suite, TestPurge);
    SUITE_ADD_TEST(suite, TestEasy);
    SUITE_ADD_TEST(suite, TestMedium);
    SUITE_ADD_TEST(suite, TestHard);
    SUITE_ADD_TEST(suite, TestScore);
    SUITE_ADD_TEST(suite, TestUndoRedo);

    return suite;
}
