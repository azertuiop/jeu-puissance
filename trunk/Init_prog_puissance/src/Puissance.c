#include "Puissance.h"


void puiInit(Puissance *pPui)
{
	pPui->x=pPui->y=0;
}
/*
void puiGauche(Puissance *pPui, const Terrain *pTer)
{
	if (terEstPositionPersoValide( pTer, pPui->x-1, pPui->y))
		pPui->x--;
}

void puiDroite(Puissance *pPui, const Terrain *pTer)
{
	if (terEstPositionPersoValide( pTer, pPui->x+1, pPui->y))
		pPui->x++;
}

void puiHaut(Puissance *pPui, const Terrain *pTer)
{
	if (terEstPositionPersoValide( pTer, pPui->x, pPui->y-1))
		pPui->y--;
}

void puiBas(Puissance *pPui, const Terrain *pTer)
{
	if (terEstPositionPersoValide( pTer, pPui->x, pPui->y+1))
		pPui->y++;
}
*/
int puiGetX(const Puissance *pPui)
{
	return pPui->x;
}

int puiGetY(const Puissance *pPui)
{
	return pPui->y;
}
/*
void pionJaune(Puissance *, const Terrain *){
    if (terEstPositionPersoValide( pTer, pPui->x, pPui->y)){

    }
}
*/
