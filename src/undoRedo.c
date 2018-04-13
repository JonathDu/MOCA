#include "undoRedo.h"

void undoRedo(char *x, Board *board, int num)
{
	static int ccounter = 0, dcounter = 0;
	if (num != UNDO && !checkColPleine(num, board) && num != REDO && !(num < REDO) && !(num > board->width) && !(num == SAVE))
	{
		//Sauvegarde du numero de colonne du dernier jeton placer
		board->undoRedo.undoTab[board->undoRedo.nbCoupJouer].undoCol = num;
		board->undoRedo.undoTab[board->undoRedo.nbCoupJouer].undoRow = num;
		//board->undoRedo.undoCol[board->undoRedo.nbCoupJouer] = num;
		//board->undoRedo.undoRow[board->undoRedo.nbCoupJouer] = rowNum(num, board);

		//Sauvegarde du numero de ligne du dernier jeton placer
		board->undoRedo.undoTab[board->undoRedo.nbCoupJouer].redoCol = num;
		board->undoRedo.undoTab[board->undoRedo.nbCoupJouer].redoRow = num;
		//board->undoRedo.redoCol[board->undoRedo.nbCoupJouer] = num;
		//board->undoRedo.redoRow[board->undoRedo.nbCoupJouer] = rowNum(num, board);
	}
	//Si on veux annuler le dernier coup, on place \0 au dernier endroit sauvegarder dans la structure
	if (num == UNDO)
	{
		ccounter += 1;

		board->board[board->undoRedo.undoTab[(board->undoRedo.nbCoupJouer - 1)].undoRow][board->undoRedo.undoTab[(board->undoRedo.nbCoupJouer - 1)].undoCol] = '\0';
		//board->board[board->undoRedo.undoRow[(board->undoRedo.nbCoupJouer - 1)]][board->undoRedo.undoCol[(board->undoRedo.nbCoupJouer - 1)]] = '\0';
		afficherBoard(board);
		board->undoRedo.nbCoupJouer -= 1;
		board->undoRedo.undoCounter += 1;

	}
	else if (num == REDO)
	{
		dcounter += 1;
		if ((dcounter <= ccounter))
		{
			board->board[board->undoRedo.undoTab[board->undoRedo.nbCoupJouer].redoRow][board->undoRedo.undoTab[board->undoRedo.nbCoupJouer].redoCol] = *x;
			//board->board[board->undoRedo.redoRow[board->undoRedo.nbCoupJouer]][board->undoRedo.redoCol[board->undoRedo.nbCoupJouer]] = *x;


			afficherBoard(board);
			board->undoRedo.nbCoupJouer += 1;



			board->undoRedo.undoTab[board->undoRedo.nbCoupJouer].undoCol = 	board->undoRedo.undoTab[board->undoRedo.nbCoupJouer].redoCol;
			board->undoRedo.undoTab[board->undoRedo.nbCoupJouer].undoRow = board->undoRedo.undoTab[board->undoRedo.nbCoupJouer].redoRow;

			//board->undoRedo.undoCol[board->undoRedo.nbCoupJouer] = 	board->undoRedo.redoCol[board->undoRedo.nbCoupJouer];
			//board->undoRedo.undoRow[board->undoRedo.nbCoupJouer] = 	board->undoRedo.redoRow[board->undoRedo.nbCoupJouer];

			board->undoRedo.redoCounter += 1;

		}
	}
	else if (num == LOAD)
	{
		printf("Game Loaded Successfully");
	}
	else if (num == SAVE)
	{
		printf("Game saved Successfully");
		afficherBoard(board);
	}
	//On ajoute le pions dans le board
	else
	{
		board->undoRedo.nbCoupJouer += 1;
		player(board, num, *x);
		ccounter = 0;
		dcounter = 0;
	}
}

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
				//fscanf(pfile, "%c", &(board->board[r][t]));
				break;
			case SAVE:
				fprintf(pfile, "%c", board->board[r][t]);
				break;
			}
		}
	}
	fclose(pfile);
	afficherBoard(board);
}
