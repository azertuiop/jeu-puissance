
#include "Jeu.h"


void jeuInit(Jeu *pJeu)
{
	pacInit(&(pJeu->pac));
	terInit(&(pJeu->ter));
}

Terrain *jeuGetTerrainPtr(Jeu *pJeu)
{
	return &(pJeu->ter);
}

Pacman *jeuGetPacmanPtr(Jeu *pJeu)
{
	return &(pJeu->pac);
}

const Terrain *jeuGetConstTerrainPtr(const Jeu *pJeu)
{ 
	return &(pJeu->ter);
}

const Pacman *jeuGetConstPacmanPtr(const Jeu *pJeu)
{
	return &(pJeu->pac);
}


void jeuActionClavier(Jeu *pJeu, const char touche)
{
	switch(touche)
	{
		case 'g' : 
				pacGauche(&(pJeu->pac), &(pJeu->ter));
				break;
		case 'd' :
				pacDroite(&(pJeu->pac), &(pJeu->ter));
				break;
		case 'h' :
				pacHaut(&(pJeu->pac), &(pJeu->ter));
				break;
		case 'b' : 
				pacBas(&(pJeu->pac), &(pJeu->ter));
				break;
	}
}
