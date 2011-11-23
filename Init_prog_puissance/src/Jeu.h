
#ifndef _JEU_H
#define _JEU_H

#include "Puissance.h"
#include "Terrain.h"

typedef struct
{
	Terrain ter;
	Puissance pui;
} Jeu;

void jeuInit(Jeu *);
Terrain *jeuGetTerrainPtr(Jeu *);
Puissance *jeuGetPuissancePtr(Jeu *);
const Terrain *jeuGetConstTerrainPtr(const Jeu *);
const Puissance *jeuGetConstPuissancePtr(const Jeu *);

void jeuActionClavier(Jeu *j, const char);


#endif
