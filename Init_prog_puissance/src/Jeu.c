
#include "Jeu.h"


void jeuInit(Jeu *pJeu)
{
	puiInit(&(pJeu->pui));
	terInit(&(pJeu->ter));
}

Terrain *jeuGetTerrainPtr(Jeu *pJeu)
{
	return &(pJeu->ter);
}

Puissance *jeuGetPuissancePtr(Jeu *pJeu)
{
	return &(pJeu->pui);
}

const Terrain *jeuGetConstTerrainPtr(const Jeu *pJeu)
{
	return &(pJeu->ter);
}

const Puissance *jeuGetConstPuissancePtr(const Jeu *pJeu)
{
	return &(pJeu->pui);
}


void jeuActionClavier(Jeu *pJeu, const char touche)
{
	switch(touche)
	{
		case 'g' :
				puiGauche(&(pJeu->pui), &(pJeu->ter));
				break;
		case 'd' :
				puiDroite(&(pJeu->pui), &(pJeu->ter));
				break;
		case 'h' :
				puiHaut(&(pJeu->pui), &(pJeu->ter));
				break;
		case 'b' :
				puiBas(&(pJeu->pui), &(pJeu->ter));
				break;
	}
}
