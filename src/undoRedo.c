#include "undoRedo.h"



//?????????
void undoRedo(char *x, Board* board, int num)
{
	static int ccounter = 0, dcounter = 0;
	if(num != UNDO && !checkColPleine(num, board) && num != REDO && !(num<REDO) && !(num>board->width) && !(num == SAVE))
	{
		//Sauvegarde du numero de colonne du dernier jeton placer
		board->undoRedo.undoCol[board->undoRedo.nbCoupJouer] = num;
		board->undoRedo.k = rowNum(num, board);
		board->undoRedo.undoRow[board->undoRedo.nbCoupJouer] = board->undoRedo.k;


		//Sauvegarde du numero de ligne du dernier jeton placer
		board->undoRedo.redoCol[board->undoRedo.nbCoupJouer] = num;
		board->undoRedo.l = rowNum(num, board);
		board->undoRedo.redoRow[board->undoRedo.nbCoupJouer] = board->undoRedo.l;
	}
	//Si on veux annuler le dernier coup, on place \0 au dernier endroit sauvegarder dans la structure
	if(num == UNDO)
	{
		ccounter +=1;
		board->board[board->undoRedo.undoRow[(board->undoRedo.nbCoupJouer-1)]][board->undoRedo.undoCol[(board->undoRedo.nbCoupJouer-1)]] = '\0';
		print(board);
		board->undoRedo.nbCoupJouer-=1;
	}
	else if(num == REDO)
	{
		dcounter += 1;
		if((dcounter <= ccounter))
		{
			board->board[board->undoRedo.redoRow[board->undoRedo.nbCoupJouer]][board->undoRedo.redoCol[board->undoRedo.nbCoupJouer]] = *x;
			print(board);
			board->undoRedo.nbCoupJouer+=1;			
			board->undoRedo.undoCol[board->undoRedo.nbCoupJouer] = board->undoRedo.redoCol[board->undoRedo.nbCoupJouer];
			board->undoRedo.undoRow[board->undoRedo.nbCoupJouer] = board->undoRedo.redoRow[board->undoRedo.nbCoupJouer];
		}
	}
	else if(num == LOAD)
	{
		printf("Game Loaded Successfully");
	}
	else if(num == SAVE)
	{
		printf("Game saved Successfully");
		print(board);
	}
	//On ajoute le pions dans le board
	else{
		board->undoRedo.nbCoupJouer+=1;	
		player(board,num,*x);
		ccounter = 0;
		dcounter = 0;
	}
}


void undoRedoLimit(int num, Board* board)
{
	if(num == UNDO)
	{
		board->undoRedo.undoCounter += 1;
	}
	else if(num == REDO)
	{
		board->undoRedo.redoCounter += 1;
	}
	else{
		board->undoRedo.undoCounter = 0;
		board->undoRedo.redoCounter = 0;
	}
}
