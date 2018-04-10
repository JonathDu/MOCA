/**
 * @file IA.h
 * @author Groupe 4
 * @date 2018
 * @brief Ce fichier contient les fonctions d'IA
 */

#ifndef __IA__
#define __IA__

#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include "utils.h"
#include "score.h"

/**
 * \fn int numColonneVide(Board *board, int numero)
 * \brief Fonction qui calcul le numero de colonne de la kieme colonne vide
 *
 * \param Pointeur sur le Board
 * \param Numero qui correpond a la kieme colonne vide
 * \return Retourne le nombre de colonnes vide
 */
int numColonneVide(Board *board, int numero);

/**
 * \fn void Easy(Board *board, int *num)
 * \brief Fonction IA en niveau EASY
 *
 * \param Pointeur sur le Board
 * \param Numero entre entrée/sortie de la fonction qui est la colonne choisit par l'IA
 * \return Rien
 */
void Easy(Board *board, int *num);

/**
 * \fn int Medium(Board *board, char character, int *num)
 * \brief Fonction IA en niveau MEDIUM
 *
 * \param Pointeur sur le Board
 * \param Character à insérer sur le Board (X ou O)
 * \param Numero entre entrée/sortie de la fonction qui est la colonne choisit par l'IA
 * \return Retourne 1 si un coup est possible, 0 sinon
 */
int Medium(Board *board, char character, int *num);

/**
 * \fn void Hard(Board *board, int *num)
 * \brief Fonction IA en niveau HARD
 *
 * \param Pointeur sur le Board
 * \param Numero entre entrée/sortie de la fonction qui est la colonne choisit par l'IA
 * \return Rien
 */
void Hard(Board *board, int *num);

#endif
