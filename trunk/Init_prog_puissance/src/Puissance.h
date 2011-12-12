#ifndef _PUISSANCE_H
#define _PUISSANCE_H

#include "Terrain.h"

typedef struct
{
	int x,y;
} Puissance;


void puiInit(Puissance *);
void puiGauche(Puissance *, const Terrain *);
void puiDroite(Puissance *, const Terrain *);
void puiHaut(Puissance *, const Terrain *);
void puiBas(Puissance *, const Terrain *);
int puiGetX(const Puissance *);
int puiGetY(const Puissance *);

void pionJaune(Puissance *, const Terrain *);

#endif
