#include <stdio.h>
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
