/**
 * @file score.h
 * @author Groupe 4
 * @date 2018
 * @brief Ce fichier contient les fonctions sur le calcul de score
 */


#ifndef __SCORE__
#define __SCORE__

#include <stdio.h>
#include <stdlib.h>
#include "config.h"

/**
 * \fn int totalScore(Board *board, char character)
 * \brief Fonction qui calcul le score total d'un joueur passé en parametre
 *
 * \param Pointeur sur le Board
 * \param Character qui indique quel joueur c'est (O ou X)
 * \return Retourne le score
 */
int totalScore(Board *board, char character);

#endif
