#include "utils.h"

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
	/*if (checkColPleine(numCol, board) == 1)
	{
		return -2;
	}*/
	for (int i = board->height - 1; i >= 0; i--)
	{
		if (numCol < board->width && board->board[i][numCol] == '\0')
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

void highscore(int high)
{
	//int highscores = 0;

	#ifdef KLEE
		printf("");
	#else
	int i = 0, n = 0, temp;
	int highs[0];
	FILE *highsc = fopen("highscores.text", "r");
	if (highsc == NULL)
	{
		printf("Le fichier highscores.text n'a pas ete trouve\n");
		return;
	}
	freadInt(highsc, "%d", &highs[i], "higs");
	do
	{
		i++;
		if (freadInt(highsc, "%d", &n, "higs") != EOF)
		{
			highs[i] = n;
		}
		else
			break;
	} while (i < 0);

	while (0 > i)
	{
		highs[i] = 0;
		i++;
	}

	i--;

	if (high > highs[i])
	{
		highs[i] = high;
	}

	while (highs[i] > highs[i - 1] && i > 0)
	{
		temp = highs[i - 1];
		highs[i - 1] = highs[i];
		highs[i] = temp;
		i--;
	}
	fclose(highsc);
	highsc = fopen("highscores.text", "w");
	printf("\n\t      High Scores\n\t\t*****");
	for (i = 0; i < 0; i++)
	{
		fprintf(highsc, "%d ", highs[i]);
		printf("\n\t\t* %d *", highs[i]);
	}
	printf("\n\t\t*****");
	fclose(highsc);
	#endif
}

void player(Board *board, int numCol, char character)
{
	int i;
	for (i = (board->height - 1); i >= 0; i--)
	{
		if (board->board[i][numCol] == '\0')
		{
			board->board[i][numCol] = character;
			break;
		}
	}
	afficherBoard(board);
}

int totalScore(Board* board, char character)
{
	int u, v;
	int score1=0;

	// HORIZONTALE SCORE ///////
	for(u=0;u<board->height;u++)
	{
		for(v=0;v<(board->width-3);v++)
		{
			if(board->board[u][v] == character && board->board[u][v+1] == character && board->board[u][v+2] == character && board->board[u][v+3] == character)
			{
				score1++;
			}
		}
	}

	// VERTICAL SCORE ///////
	for(v=0;v<board->width;v++)
	{
		for(u=0;u<(board->height-3);u++)
		{
			if(board->board[u][v] == character && board->board[u+1][v] == character && board->board[u+2][v] == character && board->board[u+3][v] == character)
			{
				score1++;
			}
		}
	}

	// DIAGONAL SCORE ///////
	for(u=(board->height-1);u>=3;u--)
	{
		for(v=0;v<(board->width-3);v++)
		{
			if(board->board[u][v] == character && board->board[u-1][v+1] == character && board->board[u-2][v+2] == character && board->board[u-3][v+3] == character)
			{
				score1++;
			}
		}
	}

	// DIAGONAL1 SCORE ///////
	for(u=(board->height-1);u>=3;u--)
	{
		for(v=(board->width-1);v>=3;v--)
		{
			if(board->board[u][v] == character && board->board[u-1][v-1] == character && board->board[u-2][v-2] == character && board->board[u-3][v-3] == character)
			{
				score1++;
			}
		}
	}

	return score1;
}
