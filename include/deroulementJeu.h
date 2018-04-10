#ifndef __DEROULEMENT_JEU__
#define __DEROULEMENT_JEU__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "config.h"
#include "utils.h"
#include "score.h"
#include "undoRedo.h"
#include "IA.h"
#include "affichage.h"

void jouer(Board *board);
int tourJoueur(Board *board, int numJoueur, char lettreJoueur, int *score);
void tourIA(Board *board, char lettreIA, int *score, int choixNiveau, int num);

#endif