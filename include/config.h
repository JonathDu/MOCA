/**
 * @file config.h
 * @author Groupe 4
 * @date 2018
 * @brief Ce fichier contient les structures utilisées par ce programme.
 */


#ifndef __CONFIG__
#define __CONFIG__

#include <stdio.h>
#include <stdlib.h>
#ifdef KLEE
#include "klee/klee.h"
#endif

/**
 * @defgroup GROUPE_UNDO_REDO Constantes de saisie de valeurs à saisir
 *
 * @{
 */
/** Entier qui definit  ce que l'utilisateur doit saisir pour faire un UNDO */
#define UNDO -1
/** Entier qui definit  ce que l'utilisateur doit saisir pour faire un LOAD */
#define LOAD -2
/** Entier qui definit  ce que l'utilisateur doit saisir pour faire un SAVE */
#define SAVE -3
/** Entier qui definit  ce que l'utilisateur doit saisir pour faire un REDO */
#define REDO -4
/** @} */

/** Entier qui definit que l'utilisateur va jouer contre un autre joueur */
#define PLAYER 0
/** Entier qui definit que l'utilisateur va jouer contre une IA */
#define IA 1

/**
 * @defgroup GROUPE_NIVEAUX Constantes de niveaux
 *
 * @{
 */
/** Entier representant le niveau facile */
#define EASY 0
/** Entier representant le niveau moyen */
#define MEDIUM 1
/** Entier representant le niveau difficile */
#define HARD 2
/** @} */

typedef struct {
	int redoCol;
	int undoCol;
	int redoRow;
	int undoRow;
} UndoTab;

/**
 * \enum UndoRedo
 * @brief Structure utilisée dans la structure Board. Elle concerne uniquement les mécanisme pour undo/redo
 */
typedef struct {
	UndoTab* undoTab;
	//int *redoCol; /**< Tableau contenant tous les numeros de colonne des coups annulés*/
	//int *undoCol; /**< Tableau contenant tous les numeros de colonne des coups joués*/

	int redoCounter; /**< Nombre de coup annulés qui ont été rejoué*/
	int undoCounter; /**< Nombre de coup annulés*/

	//int *redoRow; /**< Tableau contenant tous les numeros de ligne des coups annulés*/
	//int *undoRow; /**< Tableau contenant tous les numeros de ligne des coups joués*/

	int nbCoupJouer;

} UndoRedo;

/**
 * \enum Board
 * @brief Structure qui contient toute les informations du tableau de jeu
 *
 * Il faut l'utilisé en passage par référence afin d'avoir qu'une seule instance de cette structure.
 */
typedef struct {
	char** board; /**< Grille du tableau de jeu. */
	int width; /**< Largeur du tableau de jeu */
	int height; /**< Hauteur du tableau de jeu */
	int highscores; /**< Meilleur score */
	UndoRedo undoRedo; /**< Structure pour gérer les undo redo */
} Board;


int freadInt(FILE* f, char* c, int* value, const char *name);
int freadChar(FILE* f, char* c, char* value, const char *name);
int freadCharInt(FILE* f, char* c, char* value1, int* value2, const char *name);
uint Kleerandom();

/**
 * \fn void readInt(int* val, const char* name)
 * \brief Fonction qui lis un entier sur l'entrée standard
 *
 * \param Pointeur sur l'entier a modifier
 * \param Nom de l'entier a modifier
 * \return Rien
 */
void readInt(int* val, const char* name);

/**
 * \fn Board* initBoard(char *confFile)
 * \brief Fonction d'initialisation de la structure Board grace au fichier de config.
 *
 * \param Nom du fichier de configuration
 * \return le tableau initialisé
 */
Board* initBoard(char *confFile);

/**
 * \fn void initTableau(Board *board)
 * \brief Fonction d'initialisation des tableaux contenu dans Board
 *
 * \param Pointeur sur la structure Board
 */
void initTableau(Board *board);

/**
 * \fn void libererBoard(Board* board)
 * \brief Fonction qui libère en mémoire un Board
 *
 * \param Pointeur sur la structure Board à libérer
 * \return Rien
 */
void libererBoard(Board* board);

/**
 * \fn void libererundoRedo(Board* board)
 * \brief Fonction qui libère en mémoire un Board
 *
 * \param Pointeur sur la structure Board qui contient une structure UndoRedo à libérer
 * \return Rien
 */
void libererundoRedo(Board* board);

/**
 * \fn void XMLformating(char *confFile, Board* board)
 * \brief Fonction qui rempli la structure Board un fichier de config
 *
 * \param Nom du fichier de config
 * \param Pointeur sur le Board à remplir
 * \return Rien
 */
void XMLformating(char *confFile, Board* board);

/**
 * \fn int rowNum(int num, Board* board)
 * \brief Fonction qui prend en entrée un numero de colonne, et renvoie le numéro de la 1ere ligne libre dans la colonne numéro num
 *
 * \param Numéro de ligne
 * \param Pointeur sur le Board
 * \return Numéro de la 1ere ligne libre dans la colonne numéro num
 */
int rowNum(int num, Board* board);






#endif
