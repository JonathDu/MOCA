#include "config.h"



#ifdef AFL
	FILE * file;
#endif

void purge(void)
{
	int c;
	while ((c = fgetc(stdin)) != '\n' && c != EOF)
	{
	}
}

void readInt(int *val, const char *name)
{
#ifdef KLEE
	klee_make_symbolic(val, sizeof(int), name);
#else
	#ifdef AFL
		if (fscanf(file, "%d", val) != 1)
		{
			*val = -10000000;
			purge();
		}
		if (*val > 0)
		{
			*val = *val - 1;
		}
	#else
		if (scanf("%d", val) != 1)
		{
			*val = -10000000;
			purge();
		}
		if (*val > 0)
		{
			*val = *val - 1;
		}
	#endif
#endif


}

void initTableau(Board *board)
{
	int i = 0;
	int j = 0;
	int boardSize = board->height * board->width;
	int sizeOfBoard = boardSize * sizeof(int);

	board->undoRedo.undoCol = (int *)malloc(sizeOfBoard);
	board->undoRedo.redoCol = (int *)malloc(sizeOfBoard);
	board->undoRedo.undoRow = (int *)malloc(sizeOfBoard);
	board->undoRedo.redoRow = (int *)malloc(sizeOfBoard);
	board->undoRedo.nbCoupJouer = 0;

	for (i = 0; i < boardSize; i++)
	{
		board->undoRedo.undoCol[i] = 0;
		board->undoRedo.redoCol[i] = 0;
		board->undoRedo.undoRow[i] = 0;
		board->undoRedo.redoRow[i] = 0;
	}
	board->board = (char **)malloc(board->height * sizeof(char *));
	for (int i = 0; i < board->height; i++)
	{
		board->board[i] = malloc(board->width * sizeof(char));
	}

	for (i = 0; i < board->height; i++)
	{
		for (j = 0; j < board->width; j++)
		{
			board->board[i][j] = '\0';
		}
	}
}

Board *initBoard(char *confFile)
{
	Board *board = malloc(sizeof(Board));
	XMLformating(confFile, board);
	initTableau(board);
	return board;
}

void libererBoard(Board *board)
{
	#ifdef AFL
		fclose(file);
	#endif
	libererundoRedo(board);
	for (int i = 0; i < board->height; i++)
	{
		free(board->board[i]);
	}
	free(board->board);
	free(board);
}

void libererundoRedo(Board *board)
{
	free(board->undoRedo.undoCol);
	free(board->undoRedo.redoCol);
	free(board->undoRedo.undoRow);
	free(board->undoRedo.redoRow);
	free(board->undoRedo.compUndoCol);
	free(board->undoRedo.compUndoRow);
}

void XMLformating(char *confFile, Board *board)
{
	char c = 0, c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0, c7 = 0, widthTag = 0, heightTag = 0, highscoresTag = 0;
	int start = 0, End = 0, flag1 = 0, flag2 = 0, widthflag = 0, heightflag = 0, highscoresflag = 0;

	#ifdef AFL
	file = fopen(confFile, "r");
	#else
	FILE *file = fopen(confFile, "r");
	#endif

	if (file == NULL)
	{
		printf("Erreur lors de l'ouverture du fichier\n");
		exit(1);
	}

	fscanf(file, "< Configurations %c", &c);
	if (c == '>')
	{
		flag1 = 1;
		start = ftell(file);
	}
	else
	{
		while (fscanf(file, "%c", &c1) != EOF)
		{
			fscanf(file, "< Configurations %c", &c2);
			if (c2 == '>')
			{
				flag1 = 1;
				start = ftell(file);
				break;
			}
		}
	}
	while (fscanf(file, "%c", &c3) != EOF)
	{
		fscanf(file, "< / Configurations %c", &c4);
		if (c4 == '>')
		{
			flag2 = 1;
			End = ftell(file);
			break;
		}
	}
	if (flag1 == 1 && flag2 == 1)
	{
		fseek(file, start, SEEK_SET);
		while (fscanf(file, "%c", &c5) != EOF)
		{
			fscanf(file, "< Width >%d < / Width %c", &(board->width), &widthTag);
			if ((widthTag == '>') && (board->width >= 4) && ftell(file) < End)
			{
				widthflag = 1;
				break;
			}
		}
		fseek(file, start, SEEK_SET);
		while (fscanf(file, "%c", &c6) != EOF)
		{
			fscanf(file, "< Height >%d < / Height %c", &(board->height), &heightTag);
			if ((heightTag == '>') && (board->height >= 4) && ftell(file) < End)
			{
				heightflag = 1;
				break;
			}
		}
		fseek(file, start, SEEK_SET);
		while (fscanf(file, "%c", &c7) != EOF)
		{
			fscanf(file, "< Highscores >%d < / Highscores %c", &(board->highscores), &highscoresTag);
			if ((highscoresTag == '>') && (board->highscores >= 4) && ftell(file) < End)
			{
				highscoresflag = 1;
				break;
			}
		}
	}
	if (board->width == 0 || widthflag == 0)
	{
		board->width = 7;
		printf("Incorrect file format, default value of width (7) is loaded\n");
	}
	if (board->height == 0 || heightflag == 0)
	{
		board->height = 6;
		printf("Incorrect file format, default value of height (6) is loaded\n");
	}
	if (board->highscores == 0 || highscoresflag == 0)
	{
		board->highscores = 5;
		printf("Incorrect file format, default value of highscore list (5) is loaded\n");
	}
	#ifdef AFL
	fseek(file, 104, SEEK_SET);
	#else
	fclose(file);
	printf("ya\n");
	#endif
}

void print(Board *board)
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
	print(board);
}

int rowNum(int num, Board *board)
{
	int i = 0;
	for (i = 0; i < board->height; i++)
	{
		if (board->board[i][num] != '\0')
			break;
	}
	return i - 1;
}
