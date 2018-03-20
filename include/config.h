/**
 * @file config.h
 * @author Groupe 4
 * @date 2018
 * @brief Ce fichier contient les structures utilisées par ce programme, ainsi que toute les fonctions "outils" du programme. 
 */


#ifndef __CONFIG__
#define __CONFIG__

#include <stdio.h>
#include <stdlib.h>

#ifdef KLEE
#include "klee/klee.h"
#endif



#ifdef KLEE
static inline void readInt(int* val, const char* name)
{

	klee_make_symbolic(val, sizeof(int), name);
}

#else
static inline void readInt(int* val, const char* name)
{
	scanf("%d", val);
	if(*val > 0){
		*val = *val - 1;
	}
}
#endif

#define UNDO -1
#define LOAD -2
#define SAVE -3
#define REDO -4

#define IA 1
#define PLAYER 0

#define EASY 0
#define MEDIUM 1
#define HARD 2


/**
 * \enum UndoRedo
 * @brief Structure utilisée dans l'autre structure Board, qui concerne uniquement les mécanisme des undo/redo
 */
typedef struct {
	int *redoCol; /**< c'est quoi ???  1. */
	int *undoCol; /**< c'est quoi ???  2. */
	int *compUndoCol; /**< c'est quoi ???  3. */

	int redoCounter; /**< c'est quoi ???  4. */
	int undoCounter; /**< c'est quoi ???  5. */
	int compUndoCounter; /**< c'est quoi ???  6. */

	int *redoRow; /**< c'est quoi ???  7. */
	int *undoRow; /**< c'est quoi ???  8. */
	int *compUndoRow; /**< c'est quoi ???  9. */

	int k; /**< c'est quoi ???  10. */
	int l; /**< c'est quoi ???  11. */
	int z; /**< c'est quoi ???  12. */
	int q; /**< c'est quoi ???  13. */
	int c; /**< c'est quoi ???  14. */
	int d; /**< c'est quoi ???  15. */
} UndoRedo;

/**
 * \enum Board
 * @brief Structure utilisée dans dans tout le projet
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


/**
 * \fn Board* initBoard(char *confFile)
 * \brief Fonction d'initialisation de la structure Board en focntion du fichier de config.
 *
 * \param Nom du fichier de configuration
.
 * \return le tableau initialisé 
 */
Board* initBoard(char *confFile);
void libererBoard(Board* board);
void XMLformating(char *confFile, Board* board);
void print(Board* board);

int rowNum(int num, Board* board);
void player(Board* board, int num, char character);

#endif
