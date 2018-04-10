#include "config.h"
#include "deroulementJeu.h"

int main(int argc, char *argv[])
{
	Board *board = initBoard(argv[1]);
	jouer(board);
	exit(0);
}


