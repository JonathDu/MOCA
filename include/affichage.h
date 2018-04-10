/**
 * @file affichage.h
 * @author Groupe 4
 * @date 2018
 * @brief Ce fichier contient fonctions d'affichage du programme
 */

#ifndef __AFFICHAGE__
#define __AFFICHAGE__

#include <stdio.h>
#include <stdlib.h>
#include "config.h"

/**
 * \fn void afficherBoard(Board *board)
 * \brief Fonction qui affiche le board
 *
 * \param Pointeur sur le Board
 * \return Rien
 */
void afficherBoard(Board *board);

/**
 * \fn void afficheEnteteBienvenu()
 * \brief Fonction qui affiche l'entête de bienvenu
 *
 * \return Rien
 */
void afficheEnteteBienvenue();

/**
 * \fn void afficheDemandeJoueurOuIA()
 * \brief Fonction qui affiche un texte demandant si l'utilisateur veut jouer contre un joueur ou contre une IA
 *
 * \return Rien
 */
void afficheDemandeJoueurOuIA();

/**
 * \fn void afficheScoreIA(int score1, int score2)
 * \brief Fonction qui affiche le score du joueur 1 et de l'IA
 *
 * \param Score du joueur 1
 * \param Score de l'IA
 * \return Rien
 */
void afficheScoreIA(int score1, int score2);

/**
 * \fn void afficheScorePlayer(int score1, int score2)
 * \brief Fonction qui affiche le score du joueur 1 et du joueur 2
 *
 * \param Score du joueur 1
 * \param Score du joueur 2
 * \return Rien
 */
void afficheScorePlayer(int score1, int score2);

/**
 * \fn void affichageOptionRedo()
 * \brief Fonction qui affiche le texte qui indique à l'utilisateur ce qu'il doit saisir pour redo
 *
 * \return Rien
 */
void affichageOptionRedo();

/**
 * \fn void afficheDemandeSelectionNiveau()
 * \brief Fonction qui affiche le texte qui indique à ce qu'il doit saisir pour choisir le niveau du difficulté
 *
 * \return Rien
 */
void afficheDemandeSelectionNiveau();

#endif
