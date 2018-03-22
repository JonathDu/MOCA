#include "level.h"

int numColonneVide(Board *board, int numero)
{
	int indiceColonneVide = 0;
	int indiceColonne = 0;
	while (indiceColonneVide <= numero && indiceColonne < board->width)
	{
		if (checkColPleine(indiceColonne, board) == 0)
		{
			indiceColonneVide++;
		}
		indiceColonne++;
	}
	return indiceColonne - 1;
}

void Easy(Board *board, int *num)
{
	
	int numCol;
	int nbColVide = getNbColonneVide(board);
	numCol = rand() % nbColVide; //Choisi une colonne au hasard
	numCol = numColonneVide(board, numCol);
	int ligne = getLigneLibre(board, numCol);
	board->board[ligne][numCol] = 'O';
	*num = numCol;
}

int Medium(Board *board, char character, int *num)
{
	int scoreAncien;
	int scoreNouveau;
	for (int i = 0; i < board->width; i++)
	{
		int ligne = getLigneLibre(board, i);
		if (ligne == -1 || ligne == -2)
		{
			continue;
		}

		scoreAncien = totalScore(board, character);
		board->board[ligne][i] = character;
		scoreNouveau = totalScore(board, character);
		if (scoreAncien < scoreNouveau)
		{
			board->board[ligne][i] = 'O';
			*num = i;
			return 1;
		}
		else
		{
			board->board[ligne][i] = '\0';
		}
	}
	return 0;
}

void Hard(Board *board, int *num)
{
	char x = 'X', o = 'O';
	if (Medium(board, x, num) == 1)
		return;
	if (Medium(board, o, num) == 1)
		return;
	for (int i = 0; i < board->width; i++)
	{
		int ligne = getLigneLibre(board, i);
		if (ligne == -1 || ligne == -2)
		{
			continue;
		}
		board->board[ligne][i] = o;
		if (Medium(board, x, num) == 1)
		{
			board->board[getLigneLibre(board, *num) + 1][*num] = '\0';
			*num = i;
			return;
		}
		else
		{
			board->board[ligne][i] = '\0';
		}
	}
	Easy(board, num);
}
