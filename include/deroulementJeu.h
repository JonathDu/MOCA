/**
 * @file deroulementJeu.h
 * @author Groupe 4
 * @date 2018
 * @brief Ce fichier contient le mecanisme du jeu (enchainement de coups ...)
 */

#ifndef __DEROULEMENT_JEU__
#define __DEROULEMENT_JEU__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "config.h"
#include "utils.h"
#include "undoRedo.h"
#include "IA.h"
#include "affichage.h"

/**
 * \fn void jouer(Board *board)
 * \brief Fonction principale du jeu, qui rejoue tant qu'on veut
 *
 * \param Premier argument du programme
 * \return Retourne rien
 */
void jouer(char* argv1);

/**
 * \fn int tourJoueur(Board *board, int numJoueur, char lettreJoueur, int *score)
 * \brief Fonction de jeu du joueur
 *
 * \param Pointeur sur le Board
 * \param Numéro du joueur
 * \param Lettre du joueur qui va être ecrit sur le board
 * \param Score du joueur
 * \return Retourne rien
 */
int tourJoueur(Board *board, int numJoueur, char lettreJoueur, int *score);

/**
 * \fn void tourIA(Board *board, char lettreIA, int *score, int choixNiveau, int num)
 * \brief Fonction de jeu de l'IA
 *
 * \param Pointeur sur le Board
 * \param Lettre de l'IA qui va être ecrit sur le board
 * \param Lettre du joueur qui va être ecrit sur le board
 * \param Score du joueur
 * \param Niveau difficulté joueur
 * \param Numéro de colonne
 * \return Retourne rien
 */
void tourIA(Board *board, char lettreIA, char lettreJoueur, int *score, int choixNiveau, int num);

#endif
