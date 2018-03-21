#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "config.h"
#include "check.h"
#include "score.h"
#include "undoRedo.h"
#include "level.h"
#include "affichage.h"

int width = 0, height = 0, highscores = 0;

void saveLoad(int *num, Board *board);
void highscore(int high);
int tourJoueur(Board *board, int numJoueur, char lettreJoueur, int *score);
void tourIA(Board *board, char lettreIA, int *score, int choixNiveau, int num);

int main(int argc, char *argv[])
{
	char playAgain;
	do
	{
		int score1 = 0;
		int score2 = 0;
		int high = 0;

		char x = 'X';
		char o = 'O';

		Board *board = initBoard(argv[1]);

		afficheEnteteBienvenu();
		int choixMode;
		do
		{
			afficheDemandeJoueurOuIA();
			readInt(&choixMode, "num"); //TODO : probleme => quand on saisi 0 1 2 ca marche
		} while ((choixMode != PLAYER && choixMode != IA) || isalpha(choixMode));

		//////////////////////////
		//PLAYER MODE ////////////
		//////////////////////////
		if (choixMode == PLAYER)
		{
			print(board);
			int j1 = 0;
			do //tant que la grille n'est pas pleine faire
			{
				j1 = !j1;
				affichageOptionRedo();

				if (j1) //si c'est au joueur 1 de jouer TODO : pas opti, a chaque fois il reparcours tout le tableau
				{
					tourJoueur(board, 1, o, &score1);
				}
				else //si c'est au joueur 2 de jouer
				{
					tourJoueur(board, 2, x, &score2);
				}
				afficheScorePlayer(score1, score2);
			} while (!checkfull(board));

			if (score2 > score1)
			{
				high = score2;
				printf("\nPLAYER 2 WINS");
			}
			else if (score1 == score2)
			{
				high = score1;
				printf("\nDRAW");
			}
			else
			{
				high = score1;
				printf("\nPLAYER 1 WINS");
			}
		}
		else
		//////////////////////////
		//IA MODE ////////////////
		//////////////////////////
		{
			int choixNiveau;
			do
			{
				afficheDemandeSelectionNiveau();
				readInt(&choixNiveau, "choixNiveau");
			} while (choixNiveau != EASY && choixNiveau != MEDIUM && choixNiveau != HARD); //TODO : marche pour 0 1 2 3

			print(board);
			do
			{
				affichageOptionRedo();
				int numSaisie = tourJoueur(board, 1, x, &score1);
				afficheScoreIA(score1, score2);

				tourIA(board, o, &score2, choixNiveau, numSaisie);
				afficheScoreIA(score1, score2);

			} while (!checkfull(board));

			if (score2 > score1)
			{
				high = score2;
				printf("\nComputer WINS\n");
			}
			else if (score1 == score2)
			{
				high = score1;
				printf("\nDRAW\n");
			}
			else
			{
				high = score1;
				printf("\nUser WINS\n");
			}
		}
		highscore(high);
		printf("\nif you you want to play again press y, else press any key\n");
		scanf("\n%c", &playAgain);
		libererBoard(board);

	} while (playAgain == 'y');

	return 0;
}

void highscore(int high) //TODO : a optimiser !!
{
	int i = 0, n = 0, temp;
	int highs[highscores];
	FILE *highsc = fopen("highscores.text", "r");
	if (highsc == NULL)
	{
		printf("Le fichier highscores.text n'a pas ete trouve\n");
		return;
	}
	fscanf(highsc, "%d", &highs[i]);
	do
	{
		i++;
		if (fscanf(highsc, "%d", &n) != EOF)
		{
			highs[i] = n;
		}
		else
			break;
	} while (i < highscores);

	while (highscores > i)
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
	highsc = fopen("highscores.text", "w");
	printf("\n\t      High Scores\n\t\t*****");
	for (i = 0; i < highscores; i++)
	{
		fprintf(highsc, "%d ", highs[i]);
		printf("\n\t\t* %d *", highs[i]);
	}
	printf("\n\t\t*****");
	fclose(highsc);
}

//si le numero passe en param est LOAD, alors on va lire dans le fichier save.txt
//si le numero passe en param est SAVE, alors on va ecrire dans le fichier save.txt
void saveLoad(int *num, Board *board)
{
	FILE *pfile;
	int r, t;
	pfile = fopen("save.txt", "r");
	if (pfile == NULL)
	{
		printf("Fichier de sauvegarde introuvable \n");
		return;
	}
	for (r = board->height - 1; r >= 0; r--)
	{
		for (t = board->width - 1; t >= 0; t--)
		{
			switch (*num)
			{
			case LOAD:
				fscanf(pfile, "%c", &(board->board[r][t]));
				break;
			case SAVE:
				fprintf(pfile, "%c", board->board[r][t]);
				break;
			}
		}
	}
	fclose(pfile);
	print(board);
}

int tourJoueur(Board *board, int numJoueur, char lettreJoueur, int *score)
{
	int num;

	int numOK = 0;

	do //tant que le numero saisi n'est pas correct
	{
		printf("\nPlayer %i : Enter number of the column : ", numJoueur);
		readInt(&num, "num");
		saveLoad(&num, board);

		if (num < 0)
		{
			//////////////////////////////
			//UNDO REDO SAVE LOAD/////////
			switch (num)
			{
			case UNDO:
				if (checkEmpty(board))
				{
					printf("\nCannot undo !");
					continue;
				}
				break;
			case REDO:
				if (board->undoRedo.redoCounter >= board->undoRedo.undoCounter)
				{
					printf("\nCannot redo !");
					continue;
				}
				break;
			case -10000000:
				printf("\nErreur");
				continue;
			}

			undoRedoLimit(num, board);
			numOK = 1;
		}
		else
		{
			//////////////////////////////
			//NUM COL/////////////////////
			if ((num < 0) || (num > board->width - 1)) //si numCol depasse le board, on resaisie
			{
				printf("\nBad num col ! Please enter a number between 1 and %d.", board->width);
				continue;
			}
			else if (checkColPleine(num, board)) //si la colonne est pleine, on resaisi
			{
				printf("\nFull col ! Please enter another num of col.");
				continue;
			}
			numOK = 1;
		}
	} while (!numOK);

	undoRedo(&lettreJoueur, board, num);
	*score = totalScore(board, lettreJoueur);

	return num;
}

void tourIA(Board *board, char lettreIA, int *score, int choixNiveau, int num)
{
	if (num >= 0) //si le numero saisie est une colonnes
	{
		switch (choixNiveau)
		{
		case EASY:
			Easy(board, &num);
			break;
		case MEDIUM:
			if (Medium(board, lettreIA, &num) == 0)
			{
				Easy(board, &num);
			}
			break;
		case HARD:
			Hard(board, &num);
			break;
		}

		board->undoRedo.compUndoCol[board->undoRedo.d++] = num - 1;
		board->undoRedo.compUndoRow[board->undoRedo.c++] = rowNum(num, board) + 1;
		board->undoRedo.compUndoCounter = 0;
	}
	if (num == UNDO)
	{
		board->undoRedo.compUndoCounter += 1;
		board->undoRedo.c--;
		board->undoRedo.d--;
		board->board[board->undoRedo.compUndoRow[board->undoRedo.c]][board->undoRedo.compUndoCol[board->undoRedo.d]] = '\0';
	}

	print(board);
	*score = totalScore(board, lettreIA);
}
