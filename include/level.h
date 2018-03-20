#ifndef __LEVEL__
#define __LEVEL__

#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include "check.h"
#include "score.h"


void Easy(Board* board, int *num);
int Medium(Board* board, char character, int *num);
void Hard(Board* board, int *num);
int numColonneVide(Board* board, int numero);

#endif
