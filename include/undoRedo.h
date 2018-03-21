/**
 * @file undoRedo.h
 * @author Groupe 4
 * @date 2018
 * @brief Ce fichier contient les fonctions sur undo Redo
 */

#ifndef __UNDOREDO__
#define __UNDOREDO__

#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include "check.h"

/**
 * \fn void undoRedo(char *x, Board *board, int num)
 * \brief Fonction qui ????
 *
 * \param Param ????
 * \param Pointeur sur le Board
 * \param Param ????
 * \return Retourne le score
 */
void undoRedo(char *x, Board *board, int num);

/**
 * \fn void undoRedoLimit(int num, Board *board)
 * \brief Fonction qui ????
 *
 * \param Param ????
 * \param Pointeur sur le Board
 * \return Retourne le score
 */
void undoRedoLimit(int num, Board *board);

#endif
