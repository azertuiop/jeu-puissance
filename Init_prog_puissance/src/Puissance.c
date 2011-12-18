#include "Puissance.h"
#include <stdio.h>

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

int pionJauneValide(Terrain * pTer, Cases cases, int i, int j)
{
    printf("\nPuissance-->debut test emplacement jaune\n");
    if (terEstPositionPersoValide(pTer,cases, i,j)==1){
        terSetXY(pTer,i,j,'j');

        return 1;
    }
    else return 0;
}


int pionRougeValide(Terrain * pTer, Cases cases, int i, int j){

    printf("\nPuissance-->debut test emplacement rouge\n");
    if (terEstPositionPersoValide(pTer,cases, i,j)==1){
        terSetXY(pTer,i,j,'r');

        return 1;
    }
    else return 0;
}


