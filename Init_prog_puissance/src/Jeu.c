
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

 Terrain *jeuGetModifTerrainPtr( Jeu *pJeu)
{
	return &(pJeu->ter);
}


const Puissance *jeuGetConstPuissancePtr(const Jeu *pJeu)
{
	return &(pJeu->pui);
}

/*
void jeuActionClavier(Jeu *pJeu, const char touche) // a adapter pour l'utilisation de la souris
{
	switch(touche)
	{
		case 'q' :
				puiGauche(&(pJeu->pui), &(pJeu->ter));
				break;
		case 'd' :
				puiDroite(&(pJeu->pui), &(pJeu->ter));
				break;
		case 'z' :
				puiHaut(&(pJeu->pui), &(pJeu->ter));
				break;
		case 's' :
				puiBas(&(pJeu->pui), &(pJeu->ter));
				break;
	}
}
*/
