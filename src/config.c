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


int freadInt(FILE* f, char* c, int* value, const char *name)
{
	#ifdef KLEE
		klee_make_symbolic(value, sizeof(int),name);
		return 1;
	#else
		return fscanf(f,c,value);
	#endif
}


int freadChar(FILE* f, char* c, char* value, const char *name)
{
	#ifdef KLEE
		klee_make_symbolic(value, sizeof(char),name);
		return 1;
	#else
		return fscanf(f,c,value);
	#endif
}

int freadCharInt(FILE* f, char* c, char* value1, int* value2, const char *name)
{
	#ifdef KLEE
		klee_make_symbolic(value1, sizeof(char),name);
		klee_make_symbolic(value2, sizeof(int),name);

		return 1;
	#else
		return fscanf(f,c,value1, value2);
	#endif
}

int freadIntChar(FILE* f, char* c, int* value1, char* value2, const char *name)
{
	#ifdef KLEE
		klee_make_symbolic(value1, sizeof(int),name);
		klee_make_symbolic(value2, sizeof(char),name);

		return 1;
	#else
		return fscanf(f,c,value1, value2);
	#endif
}

uint Kleerandom(){
	#ifdef KLEE
		uint *v = malloc(sizeof(uint));
		klee_make_symbolic(v, sizeof(uint), "random");
		return *v;
	#else
		return rand();
	#endif
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
	int sizeOfBoard = boardSize * sizeof(UndoTab);
	

	board->undoRedo.undoTab = (UndoTab *)malloc(sizeOfBoard);

	board->undoRedo.nbCoupJouer = 0;

	for (i = 0; i < boardSize; i++)
	{
		board->undoRedo.undoTab[i].undoCol = 0;
		board->undoRedo.undoTab[i].redoCol = 0;
		board->undoRedo.undoTab[i].undoRow = 0;
		board->undoRedo.undoTab[i].redoRow = 0;

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
	board->height=0;
	board->width=0;

	free(board->board);
	free(board);
}

void libererundoRedo(Board *board)
{
	free(board->undoRedo.undoTab);

	
}

void XMLformating(char *confFile, Board *board)
{
	char c = 0,c2 = 0,c4 = 0, c5 = 0, c6 = 0, c7 = 0, widthTag = 0, heightTag = 0, highscoresTag = 0;
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
	freadChar(file, "< Configurations %c", &c, "config");
	//fscanf(file, "< Configurations %c", &c);
	if (c == '>')
	{
		flag1 = 1;
		start = ftell(file);
	}
	else
	{



	//	while (fscanf(file, "%c", &c1) != EOF)
		while (freadChar(file, "%c", &c, "config") != EOF)

		{
			freadChar(file, "< Configurations %c", &c, "config");

			//fscanf(file, "< Configurations %c", &c2);
			if (c2 == '>')
			{
				flag1 = 1;
				start = ftell(file);
				break;
			}
		}
	}
	while (freadChar(file, "%c", &c, "config") != EOF)

	//while (fscanf(file, "%c", &c3) != EOF)
	{
		freadChar(file, "< / Configurations %c", &c4, "config");
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
		while (freadChar(file, "%c", &c5, "config") != EOF)
		{
			freadIntChar(file, "< Width >%d < / Width %c", &(board->width), &widthTag, "Config");
			if ((widthTag == '>') && (board->width >= 4) && ftell(file) < End)
			{
				widthflag = 1;
				break;
			}
		}
		fseek(file, start, SEEK_SET);
		while (freadChar(file, "%c", &c6, "config") != EOF)
		{
			freadIntChar(file, "< Height >%d < / Height %c", &(board->height), &heightTag, "config");
			if ((heightTag == '>') && (board->height >= 4) && ftell(file) < End)
			{
				heightflag = 1;
				break;
			}
		}
		fseek(file, start, SEEK_SET);
		while (freadChar(file, "%c", &c7, "conf") != EOF)
		{
			freadIntChar(file, "< Highscores >%d < / Highscores %c", &(board->highscores), &highscoresTag, "conf");
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
