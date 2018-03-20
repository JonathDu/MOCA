#include "score.h"

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
