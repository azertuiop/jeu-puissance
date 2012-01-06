#include "Terrain.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

void terInit(Terrain *pTer)
{
	int x,y;

	const char terrain_defaut[7][8]={};

	pTer->dimx = 8;
	pTer->dimy = 7;
	pTer->cases.xmin=0;
	pTer->cases.xmax=pTer->dimx-2;
	pTer->cases.ymin=1;
	pTer->cases.ymax=pTer->dimy-1;



	pTer->tab = (char **)malloc(sizeof(char *)*pTer->dimy);
	for (y=0; y<pTer->dimy; y++)
		pTer->tab[y] = (char *)malloc(sizeof(char)*pTer->dimx);

	for(y=0;y<pTer->dimy;++y)
		for(x=0;x<pTer->dimx;++x)
			pTer->tab[y][x] = terrain_defaut[y][x];
}


void terLibere(Terrain *pTer)
{
	int y;

	for (y=0; y<pTer->dimy; y++)
		free(pTer->tab[y]);
	free(pTer->tab);

	pTer->dimx = 0;
	pTer->dimy = 0;
	pTer->tab = NULL;
}

int terEstPositionPersoValide(const Terrain *pTer, const int i, const int j){
/*    printf("\nTerrain --> test position valide\n");
    printf("    lettre dans tab -->%c\n",pTer->tab[j][i]);
    printf("    i=%d    j=%d\n",i,j);
*/
    if( (i>=pTer->cases.xmin)   &&  (i<=pTer->cases.xmax)  &&  (j>=pTer->cases.ymin)   &&  (j<=pTer->cases.ymax)  &&  (pTer->tab[j][i]!='r')  &&  (pTer->tab[j][i]!='j')    ){

        return 1;
    }
    else{
        return 0;
    }
}


const char terGetXY(const Terrain *pTer, const int x, const int y)
{
	assert( x>=0) ;
	assert( y>=0) ;
	assert( x<pTer->dimx ) ;
	assert( y<pTer->dimy ) ;
	return pTer->tab[y][x];
}

void terSetXY(const Terrain *pTer, const int x, const int y, const char pion)
{
	assert( x>=0) ;
	assert( y>=0) ;
	assert( x<pTer->dimx ) ;
	assert( y<pTer->dimy ) ;
	pTer->tab[y][x] = pion;
/*	printf("Terrain --> terSetXY: %c\n",(pTer->tab[y][x]));*/
}

const int getDimX(const Terrain *pTer)
{
	return pTer->dimx;
}

const int getDimY(const Terrain *pTer)
{
	return pTer->dimy;
}

int terPlein(const Terrain *pTer)
{
    int i, count=0;
    for(i=pTer->cases.xmax; i>=0; i--)
    if ((terGetXY(pTer,i,1)=='j')||(terGetXY(pTer,i,1)=='r'))
    {
        count++;
    }
    if (count==(pTer->cases.xmax+1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
