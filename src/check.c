#include "check.h"

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


int checkColVide(Board *board, int numCol, int numOfrow)
{
	if (numOfrow == (board->height - 1) && board->board[numOfrow][numCol] == '\0')
		return 1;
	else if (numOfrow != (board->height - 1) && board->board[numOfrow + 1][numCol] != '\0' && board->board[numOfrow][numCol] == '\0') //????????
		return 1;

	return 0;
}

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

/*
int checknum(int numCol, Board *board)
{
	while ((numCol < 0) || (numCol > board->width - 1))
	{
		print(board);
		printf("\nPlease enter a number between 1 and %d :", board->width);
		readInt(&numCol, "num");
	}
	return numCol;
}
*/

int getLigneLibre(Board *board, int numCol)
{
	/*if (checkColPleine(numCol, board) == 1)
	{
		return -2;
	}*/
	for (int i = board->height - 1; i >= 0; i--)
	{
		if (board->board[i][numCol] == '\0')
		{
			return i;
		}
	}
	return -2;
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
