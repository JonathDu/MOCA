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
#include "utils.h"
#include "affichage.h"


/**
 * \fn void undoRedo(char *x, Board *board, int num)
 * \brief Fonction qui enregistre le coup joué ou annule le dernier coup ou rejoue le dernier coup annulé
 *
 * \param Caractère du joueur
 * \param Pointeur sur le Board
 * \param Numéro entrée par le joueur
 * \return Retourne le score
 */
void undoRedo(char *x, Board *board, int num);

/**
 * \fn void saveLoad(int *num, Board *board)
 * \brief Fonction qui save ou qui load
 *
 * \param Numéro qui est soit LOAD soit SAVE
 * \param Pointeur sur le Board
 * \return Retourne rien
 */
void saveLoad(int *num, Board *board);

#endif
