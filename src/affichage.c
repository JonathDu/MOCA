#include "affichage.h"

void afficherBoard(Board *board)
{
	int i, j;
	for (i = 0; i < board->height; i++)
	{
		printf("\n+");
		for (j = 0; j < board->width; j++)
		{
			printf("---+");
		}
		printf("\n|");
		for (j = 0; j < board->width; j++)
		{
			if (board->board[i][j] == '\0')
			{
				printf("   |");
			}
			else
			{
				printf(" %c |", board->board[i][j]);
			}
		}
	}
	printf("\n+");
	for (i = 0; i < board->width; i++)
	{
		printf("---+");
	}
	printf("\n");
	for (i = 1; i <= board->width; i++)
	{
		printf("   %d", i);
	}
	printf("\n\n\n");
}

void afficheEnteteBienvenue()
{
    printf("\n\n                     **** WELCOME TO THE GAME ****\n\n");
}

void afficheDemandeJoueurOuIA()
{
    printf("Enter 1 or 2\n");
    printf("Player1 vs Player2: press 1 \n\nPlayer vs Computer: press 2 \n\n");
}

void afficheDemandeSelectionNiveau()
{
    printf("\nEasy (press 1), Medium (press 2), Hard (press 3)\n");
}

void afficheScoreIA(int score1, int score2){
    printf("\n***************************************************");
    printf("\n***************************************************");
    printf("\n**                      **                       **");
    printf("\n** player1 score : %d    **   Computer score  : %d  **", score1, score2);
    printf("\n**                      **                       **");
    printf("\n***************************************************");
    printf("\n***************************************************");
}

void afficheScorePlayer(int score1, int score2){
    printf("\n***************************************************");
    printf("\n***************************************************");
    printf("\n**                      **                       **");
    printf("\n** player1 score : %d    **   player2 score  : %d  **", score1, score2);
    printf("\n**                      **                       **");
    printf("\n***************************************************");
    printf("\n***************************************************");
}

void affichageOptionRedo(){
    printf("\nif you want to undo, press -1\n");
    printf("if you want to redo, press -4, to load, press -2, to save, press -3\n");
}
