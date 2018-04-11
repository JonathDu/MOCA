/**
 * @file utils.h
 * @author Groupe 4
 * @date 2018
 * @brief Ce fichier contient fonctions "outils" du programme
 */

#ifndef __UTILS__
#define __UTILS__

#include "config.h"
#include "affichage.h"

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
 * \fn int checkColPleine(int numCol, Board* board)
 * \brief Fonction qui indique si la colonne numCol est plein
 *
 * \param Numero de la colonne
 * \param Pointeur sur le Board
 * \return Retourne 1 si la colonne numCol est pleine, -1 si numCol est en dehors des limites, 0 sinon
 */
int checkColPleine(int numCol, Board* board);

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

/**
 * \fn void highscore(int high)
 * \brief Fonction qui enregistre le highscore dans un fichier texte
 *
 * \param Le meilleur score
 * \return Retourne rien
 */
void highscore(int high);

/**
 * \fn void player(Board* board, int numCol, char character)
 * \brief Fonction qui ajoute le pion dans la grille, et affiche la grille
 *
 * \param Pointeur sur le Board
 * \param Numéro de colonne dans laquelle insérer
 * \param Character qui va être insérer dans le tableau (X ou O)
 * \return Rien
 */
void player(Board* board, int numCol, char character);


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
