#include "CuTest.h"
#include "utils.h"
#include "config.h"
#include "IA.h"
#include "utilTest.h"


char* StrToUpper(char* str) {
    return str;
}

Board* init(){
  Board* board = malloc(sizeof(Board));
  board->height = 3;
  board->width = 3;
  UndoRedo* undoRedo = malloc(sizeof(UndoRedo));
  board->undoRedo = *undoRedo;
  initTableau(board);
  return board;
}

Board* init2(){
  Board* board = malloc(sizeof(Board));
  board->height = 6;
  board->width = 7;
  UndoRedo* undoRedo = malloc(sizeof(UndoRedo));
  board->undoRedo = *undoRedo;
  initTableau(board);
  return board;
}


void TestCheckFull(CuTest *tc){
  Board* board = init();
  CuAssertIntEquals(tc,checkfull(board), 0);
  for(int i =0; i< board->height; i++){
    for(int j=0;j< board->width;j++){
      board->board[i][j] = 'O';
    }
  }

  CuAssertIntEquals(tc,checkfull(board), 1);

}

void TestCheckEmpty(CuTest *tc) {
    Board* board = init();
    CuAssertIntEquals(tc, checkEmpty(board), 1);
    board->board[0][0]='O';
    CuAssertIntEquals(tc, checkEmpty(board), 0);
    for(int i=0; i < 3; i++){
      for(int j=0; j<3; j++){
        board->board[i][j] = 'X';
      }
    }
    CuAssertIntEquals(tc, checkEmpty(board), 0);
    //libererBoard(board);
}

void TestCheckColPleine(CuTest *tc){
  Board* board = init();
  CuAssertIntEquals(tc, checkColPleine(0, board), 0);
  CuAssertIntEquals(tc, checkColPleine(-1, board), -1);
  for(int i=0; i < 3; i++){
    for(int j=0; j<3; j++){
      board->board[i][j] = 'X';
    }
  }
  CuAssertIntEquals(tc, checkColPleine(0, board), 1);
  //libererBoard(board);
}


void TestGetLigneLibre(CuTest *tc){
  Board* board = init();
  board->board[0][0] = 'X';
  board->board[1][0] = 'X';
  board->board[2][0] = 'X';
  board->board[2][2] = 'X';
  CuAssertIntEquals(tc, getLigneLibre(board, 0), -2);
  CuAssertIntEquals(tc, getLigneLibre(board, 1), 2);
  CuAssertIntEquals(tc, getLigneLibre(board, 2), 1);
  //libererBoard(board);
}

void TestGetNbColonneVide(CuTest *tc){
  Board* board = init();
  board->board[0][0] = 'X';
  board->board[1][0] = 'X';
  board->board[2][0] = 'X';
  CuAssertIntEquals(tc, getNbColonneVide(board), 2);
  board->board[1][2] = 'X';
  board->board[2][2] = 'X';
  CuAssertIntEquals(tc, getNbColonneVide(board), 2);
  board->board[0][1] = 'X';
  board->board[1][1] = 'X';
  board->board[2][1] = 'X';
  CuAssertIntEquals(tc, getNbColonneVide(board), 1);
  board->board[0][2] = 'X';
  CuAssertIntEquals(tc, getNbColonneVide(board), 0);
  //libererBoard(board);
}

void TestnumColonneVide(CuTest* tc){
  Board* board = init2();
  for(int i=0; i<board->height; i++){
    board->board[i][1] = 'X';
  }


  CuAssertIntEquals(tc, numColonneVide(board, 5), 6);

  for(int j = 0; j<board->width-1; j++){
    for(int i=0; i<board->height; i++){
      if(j < 6 || (j>6 && i >=3))
        board->board[i][j] = 'X';
    }
  }
  CuAssertIntEquals(tc, numColonneVide(board, 0), 6);


  libererBoard(board);
}



CuSuite* StrUtilGetSuite() {
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, TestCheckEmpty);
    SUITE_ADD_TEST(suite, TestCheckColPleine);
    SUITE_ADD_TEST(suite, TestGetNbColonneVide);
    SUITE_ADD_TEST(suite, TestnumColonneVide);

    return suite;
}
