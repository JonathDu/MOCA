#include "check.h"

//Retourne 1 si la grille est vide, 0 sinon
int checkEmpty(Board *board)
{
	int n, m;
	for (n = 0; n < board->height; n++)
	{
		for (m = 0; m < board->width; m++)
		{
			if (board->board[n][m] != '\0')
				return 0;
		}
	}
	return 1;
}

//Check si la colonne est vide
int checkColVide(Board *board, int numCol, int numOfrow)
{
	if (numOfrow == (board->height - 1) && board->board[numOfrow][numCol] == '\0')
		return 1;
	else if (numOfrow != (board->height - 1) && board->board[numOfrow + 1][numCol] != '\0' && board->board[numOfrow][numCol] == '\0') //????????
		return 1;

	return 0;
}

//Renvoie 1 si la colonne est pleine, 0 si vide, -1 si numCol en dehors des limites
int checkColPleine(int numCol, Board *board)
{
	if (numCol < 0 || numCol >= board->width)
	{
		return -1;
	}
	for (int i = board->height - 1; i >= 0; --i)
	{
		if (board->board[i][numCol] == '\0')
		{
			return 0;
		}
	}

	return 1;
}

int getLigneLibre(Board *board, int numCol)
{
	if (checkColPleine(numCol, board) == 1)
	{
		return -2;
	}
	for (int i = board->height - 1; i >= 0; i--)
	{
		if (board->board[i][numCol] == '\0')
		{
			return i;
		}
	}
	return -1;
}

int getNbColonneVide(Board *board)
{
	int compteur = 0;
	for (int i = 0; i < board->width; i++)
	{
		if (checkColPleine(i, board) == 0)
		{
			compteur++;
		}
	}
	return compteur;
}

//Retourne 0 si la grille est pleine, 1 sinon
int checkfull(Board *board)
{
	int i, j;
	for (i = 0; i < board->height; i++)
	{
		for (j = 0; j < board->width; j++)
		{
			if (board->board[i][j] == '\0')
			{
				return 0;
			}
		}
	}
	return 1;
}

//Verifie si le numero de colonne en entree est bon, sinon redemande la saisie
int checknum(int num, Board *board)
{
	while ((num < 0) || (num > board->width - 1))
	{
		print(board);
		printf("\nPlease enter a number between 1 and %d :", board->width);
		readInt(&num, "num");
	}
	return num;
}
