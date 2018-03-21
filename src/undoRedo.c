#include "undoRedo.h"



//?????????
void undoRedo(char *x, Board* board, int num)
{
	static int ccounter = 0, dcounter = 0;
	if(num != UNDO && !checkColPleine(num, board) && num != REDO && !(num<REDO) && !(num>board->width) && !(num == SAVE))
	{
		board->undoRedo.undoCol[board->undoRedo.q] = num;
		board->undoRedo.k = rowNum(num, board);
		board->undoRedo.undoRow[board->undoRedo.q] = board->undoRedo.k;
	}
	if(num != UNDO && !checkColPleine(num, board) && num != REDO && !(num<REDO) && !(num>board->width) && !(num == SAVE))
	{
		board->undoRedo.redoCol[board->undoRedo.z] = num;
		board->undoRedo.l = rowNum(num, board);
		board->undoRedo.redoRow[board->undoRedo.z] = board->undoRedo.l;
		board->undoRedo.z+=1;
	}
	if(num == UNDO)
	{
		ccounter +=1;
		board->board[board->undoRedo.undoRow[(board->undoRedo.q-1)]][board->undoRedo.undoCol[(board->undoRedo.q-1)]] = '\0';
		print(board);
		board->undoRedo.q-=1;
		board->undoRedo.z-=1;
	}
	else if(num == REDO)
	{
		dcounter += 1;
		if((dcounter <= ccounter))
		{
			board->board[board->undoRedo.redoRow[board->undoRedo.z]][board->undoRedo.redoCol[board->undoRedo.z]] = *x;
			print(board);
			board->undoRedo.q+=1;
			board->undoRedo.undoCol[board->undoRedo.q] = board->undoRedo.redoCol[board->undoRedo.z+1];
			board->undoRedo.undoRow[board->undoRedo.q] = board->undoRedo.redoRow[board->undoRedo.z+1];
			board->undoRedo.z+=1;
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
	else{
		board->undoRedo.q+=1;
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
