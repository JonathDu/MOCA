#include "IA.h"

int numColonneVide(Board *board, int numero)
{
	int indiceColonneVide = 0;
	int indiceColonne = 0;
	while (indiceColonneVide <= numero && indiceColonne < board->width)
	{
		if (checkColPleine(indiceColonne, board) == 0)
		{
			indiceColonneVide++;
		}
		indiceColonne++;
	}
	return indiceColonne - 1;
}

void Easy(Board *board, char character, int *num)
{

	int numCol;
	int nbColVide = getNbColonneVide(board);
	numCol = Kleerandom() % nbColVide; //Choisi une colonne au hasard
	//numCol = rand() % nbColVide; //Choisi une colonne au hasard
	numCol = numColonneVide(board, numCol);
	int ligne = getLigneLibre(board, numCol);
	board->board[ligne][numCol] = character;
	*num = numCol;
}

int Medium(Board *board, char characterIA, char characterJoueur, int *num) //contre le joueur si jamais il peut aligner 4 pions
{
	int scoreAncien;
	int scoreNouveau;
	for (int i = 0; i < board->width; i++) //parcours des colonnes
	{
		int ligne = getLigneLibre(board, i); //ligbe libre de la ieme colonne
		if (ligne == -1 || ligne == -2) // si la ligne libre de la ième est la 1ere ou la deuxieme, alors pas possible que le joueur aligne 4 pions
		{
			continue;
		}

		scoreAncien = totalScore(board, characterJoueur); //score ancien du joueur
		board->board[ligne][i] = characterJoueur;
		scoreNouveau = totalScore(board, characterJoueur); //score du joueur si il joue dans la ieme colonne
		if (scoreAncien < scoreNouveau) //si le fait de jouer dans cette colonne a augmenté ses points
		{
			board->board[ligne][i] = characterIA; //alors l'IA joue avant lui dans cette colonne pour contrer
			*num = i;
			return 1;
		}
		else
		{
			board->board[ligne][i] = '\0';
		}
	}
	return 0;
}

void Hard(Board *board, char characterIA, char characterJoueur, int *num)
{
	if (Medium(board, characterIA, characterJoueur, num) == 1) //essaye de contrer le joueur si jamais il a 3 pions alignés
		return;
	if (Medium(board, characterIA, characterIA, num) == 1) // essaye de gagner si jamais 3 pions sont alignés
		return;
	for (int i = 0; i < board->width; i++) //parcours des colonnes
	{
		int ligne = getLigneLibre(board, i); //ligne libre de la ieme colonne
		if (ligne == -1 || ligne == -2) // si la ligne libre de la ième est la 1ere ou la deuxieme, alors pas possible que le joueur aligne 4 pions
		{
			continue;
		}
		board->board[ligne][i] = characterIA; //l'IA rajoute un pion dans la ieme colonne
		if (Medium(board, characterJoueur, characterIA, num) == 1) //si l'IA peut gagner le tour suivant grace a ce pion rajouté
		{
			if(getLigneLibre(board, *num) < 0){
				board->board[ligne][i] = '\0';
				continue;
			}
			board->board[getLigneLibre(board, *num) + 1][*num] = '\0';
			*num = i;
			return;
		}
		else
		{
			board->board[ligne][i] = '\0';
		}
	}
	Easy(board, characterIA, num);
}
