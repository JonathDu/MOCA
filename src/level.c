#include "level.h"



int numColonneVide(Board* board, int numero)
{
	int indiceColonneVide = 0;
	int indiceColonne = 0;
	while(indiceColonneVide <= numero && indiceColonne < board->width)
	{
		if(checkColPleine(indiceColonne, board) == 0)
		{
			indiceColonneVide++;
		}
		indiceColonne++;
	}
	return indiceColonne - 1;
}

void Easy(Board* board, int *num)
{
	int numCol;
	int nbColVide = getNbColonneVide(board);
	numCol = rand() % nbColVide; //Choisi une colonne au hasard
	numCol = numColonneVide(board, numCol);
	board->board[getLigneLibre(board, numCol)][numCol] = 'O';
	*num = numCol+1;
}


int Medium(Board* board, char character, int *num)
{
	int scoreAncien;
	int scoreNouveau;
	for(int i = 0; i < board->width; i++)
	{
		scoreAncien = totalScore(board, character);
		int ligne = getLigneLibre(board, i);
		if(ligne == -1 || ligne == -2){
			continue;
		}
		board->board[ligne][i] = character;
		scoreNouveau = totalScore(board, character);
		if(scoreAncien < scoreNouveau){

			board->board[ligne][i] = 'O';
			*num = i+1;
			return 1;
		}
		else{
			board->board[ligne][i] = '\0';
		}
	}
	return 0;
}



void Hard(Board* board, int *num)
{
	int i, j;
	char x='X',o='O';
	if(Medium(board,x,num)==1)
		return;
	if(Medium(board,o,num)==1)
		return;
	for(i=board->height-1; i>=2; i--)
	{
		for(j=0; j<board->width; j++)
		{
			if(board->board[i][j] == 'O' && board->board[i-1][j] == 'O' && board->board[i-2][j]=='\0')
			{
				board->board[i-2][j] = 'O';
				*num = j+1;
				return;
			}
		}
	}
	for(i=0;i<board->height;i++)
	{
		for(j=0;j<(board->width-2);j++)
		{
			if(board->board[i][j] == 'O' && board->board[i][j+1] == 'O' && checkColVide(board,j+2,i))
			{
				board->board[i][j+2] = 'O';
				*num = j+2+1;
				return;
			}
			if(board->board[i][j+1] == 'O' && board->board[i][j+2] == 'O' && checkColVide(board,j,i))
			{
				board->board[i][j] = 'O';
				*num = j+1;
				return;
			}
		}
	}
	for(i=board->height-1; i>=2; i--)
	{
		for(j=0;j<(board->width-2);j++)
		{
			if(board->board[i][j] == 'O' && board->board[i-1][j+1] == 'O' && checkColVide(board,j+2,i-2))
			{
				board->board[i-2][j+2] = 'O';
				*num = j+2+1;
				return;
			}
			if(board->board[i-1][j+1] == 'O' && board->board[i-2][j+2] == 'O' && checkColVide(board,j,i))
			{
				board->board[i][j] = 'O';
				*num = j+1;
				return;
			}
		}
	}
	for(i=board->height-1; i>=2; i--)
	{
		for(j=board->width-1; j>=2; j--)
		{
			if(board->board[i][j] == 'O' && board->board[i-1][j-1] == 'O' && checkColVide(board,j-2,i-2))
			{
				board->board[i-2][j-2] = 'O';
				*num = j-2+1;
				return;
			}
			if(board->board[i-1][j-1] == 'O' && board->board[i-2][j-2] == 'O' && checkColVide(board,j,i))
			{
				board->board[i][j] = 'O';
				*num = j+1;
				return;
			}
		}
	}
	Easy(board,num);
}
