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

int pionJauneValide(Terrain * pTer, int i, int j)
{
    printf("\nPuissance-->debut test emplacement jaune\n");
    if (terEstPositionPersoValide(pTer, i, j)==1){
        terSetXY(pTer,i,j,'j');

        return 1;
    }
    else return 0;
}


int pionRougeValide(Terrain * pTer, int i, int j){

    printf("\nPuissance-->debut test emplacement rouge\n");
    if (terEstPositionPersoValide(pTer, i,j)==1){
        terSetXY(pTer,i,j,'r');

        return 1;
    }
    else return 0;
}

int positionDePion(const Terrain *pTer, const int x, const int y){

    int i;
//    for(i=c.ymax; i>=c.ymin; i--)
    for(i=pTer->cases.ymax; i>=1; i--)
    if (terEstPositionPersoValide(pTer, x, i)==1){
        return i;
    }
    return 0;
}


int balayage(const Terrain *pTer, const int x,const int y,const char val)
{
    int i;
    int count=0;

    /*balayage ligne*/
    for(i=0;i<=getDimX(pTer)-2;i++)
    {
        if(terGetXY(pTer,i,y) == val)
        {
            count++;
            if(count >= 4)
                return 1;
        }

        else
            count=0;
//        printf("ligne   x: %d y: %d i: %d count: %d \n", x, y, i, count);
    }


    /*balayage colonne*/
    count =0;
    for(i=y;i<=getDimY(pTer)-1;i++)
    {
        if(terGetXY(pTer,x,i) == val)
        {
            count++;
            if(count >= 4)
                return 1;
        }
        else
            count=0;
//        printf("colonne    x: %d y: %d i: %d count: %d \n", x, y, i, count);
    }


    /*balayage diagonale haut*/

    int xMax, yMax, xMin, yMin ;

    xMax=xMin=x;
    yMax=yMin=y;
//    printf("BAS \n");
	while((xMin>0)&&(yMax<getDimY(pTer)-1))
	{
		xMin--;
		yMax++;
	}

//printf("HAUT \n");
	while(((xMax<getDimX(pTer)-2)&&(yMin>1)))
	{
		xMax++;
		yMin--;
	}


    count = 0;
    for(i=xMin;i<=xMax;i++)
    {
        if(terGetXY(pTer,xMin,yMax) == val)
        {
            count++;
            if(count >= 4)
                return 1;
        }
        else
            count=0;

//        printf("diagonale gauch    xMin: %d yMax: %d xMax: %d i: %d count: %d val: %c\n",
//                xMin, yMax, xMax, i, count, val);
        yMax--;
        xMin++;
    }




    /*balayage diagonale bas*/
    xMax=xMin=x;
    yMax=yMin=y;
	while((xMax<getDimX(pTer)-1)&&(yMax<getDimY(pTer)-1))
	{
		xMax++;
		yMax++;
	}

//printf("HAUT \n");
	while(((xMin>0)&&(yMin>1)))
	{
		xMin--;
		yMin--;
	}

    count=0;
    for(i=xMax;i>=xMin;i--)
    {
//        printf("diagonale dorat    xMin: %d yMax: %d xMax: %d yMin: %d i: %d count: %d val: %c\n",
//                xMin, yMax, xMax, yMin, i, count, val);
        if(terGetXY(pTer,xMax,yMax) == val)
        {
            count++;
            if(count >= 4)
                return 1;
        }
        else
            count=0;
        yMax--;
        xMax--;
    }



    return 0;

}



