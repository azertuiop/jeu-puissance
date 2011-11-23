#include "Terrain.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

void terInit(Terrain *pTer)
{
	int x,y;

	const char terrain_defaut[6][7]={
    "..##...",
	"..##...",
	"..##...",
	"..##...",
	"..##...",
	"..##..."}; //// je ne sais pas ce qu'il faut mettre !!!!!!

	pTer->dimx = 6;
	pTer->dimy = 7;

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

int terEstPositionPersoValide(const Terrain *pTer, const int x, const int y)
{
	if (x>=0 && x<pTer->dimx && y>=0 && y<pTer->dimy && pTer->tab[y][x]!='#')
		return 1;
	else
		return 0;
}


const char terGetXY(const Terrain *pTer, const int x, const int y)
{
	assert( x>=0) ;
	assert( y>=0) ;
	assert( x<pTer->dimx ) ;
	assert( y<pTer->dimy ) ;
	return pTer->tab[y][x];
}

void terSetXY(const Terrain *pTer, const int x, const int y, const char val)
{
	assert( x>=0) ;
	assert( y>=0) ;
	assert( x<pTer->dimx ) ;
	assert( y<pTer->dimy ) ;
	pTer->tab[y][x] = val;
}

const int getDimX(const Terrain *pTer)
{
	return pTer->dimx;
}

const int getDimY(const Terrain *pTer)
{
	return pTer->dimy;
}
