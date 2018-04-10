/**
 * @file check.h
 * @author Groupe 4
 * @date 2018
 * @brief Ce fichier contient fonctions de check
 */

#ifndef __CHECK__
#define __CHECK__

#include <stdio.h>
#include <stdlib.h>
#include "config.h"



/**
 * \fn int checkfull(Board* board)
 * \brief Fonction qui indique si la grille est pleine
 *
 * \param Pointeur sur le Board
 * \return Retourne 1 si la grille est pleine, 0 sinon
 */
int checkfull(Board* board);

/**
 * \fn int checkEmpty(Board* board)
 * \brief Fonction qui indique si la grille est vide
 *
 * \param Pointeur sur le Board
 * \return Retourne 1 si la grille est vide, 0 sinon
 */
int checkEmpty(Board* board);

/**
 * \fn int checkColVide(Board* board,int numCol,int numOfrow)
 * \brief Fonction qui indique si la colonne numCol est vide
 *
 * \param Pointeur sur le Board
 * \param Numero de la colonne
 * \param Numero de la ligne
 * \return Retourne 1 si la colonne numCol est vide, 0 sinon
 */
int checkColVide(Board* board,int numCol,int numOfrow);

/**
 * \fn int checkColPleine(int numCol, Board* board)
 * \brief Fonction qui indique si la colonne numCol est plein
 *
 * \param Numero de la colonne
 * \param Pointeur sur le Board
 * \return Retourne 1 si la colonne numCol est pleine, -1 si numCol est en dehors des limites, 0 sinon
 */
int checkColPleine(int numCol, Board* board);

/**
 * \fn int checknum(int numCol, Board* board)
 * \brief Fonction qui vérifie si le numéro de colonne en entrée est bon, sinon redemande la saisie
 *
 * \param Numero de la colonne
 * \param Pointeur sur le Board
 * \return Retourne un numéro de colonne valide
 */
//int checknum(int numCol, Board* board);

/**
 * \fn int getLigneLibre( Board* board, int numCol)
 * \brief Fonction qui renvoi le numéro de ligne libre de la colonne numCol
 *
 * \param Pointeur sur le Board
 * \param Numero de la colonne
 * \return Retourne -2 si la colonne est pleine, sinon retourne la ligne libre
 */
int getLigneLibre( Board* board, int numCol);

/**
 * \fn int getNbColonneVide(Board* board)
 * \brief Fonction qui calcul le nombre de colonnes vide dans le tableau
 *
 * \param Pointeur sur le Board
 * \return Retourne le nombre de colonnes vide
 */
int getNbColonneVide(Board* board);

#endif
