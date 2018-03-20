#ifndef __CHECK__
#define __CHECK__

#include <stdio.h>
#include <stdlib.h>
#include "config.h"




int checkfull(Board* board);
int checkEmpty(Board* board);
int checkColVide(Board* board,int num,int numOfrow);
int checkColPleine(int numCol, Board* board);
int checknum(int num, Board* board);
int getLigneLibre( Board* board, int numCol);
int getNbColonneVide(Board* board);
void initTableau(Board* board);

#endif
