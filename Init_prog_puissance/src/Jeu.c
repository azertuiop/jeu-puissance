#include <stdio.h>
#include "Jeu.h"


void jeuInit(Jeu *pJeu)
{
	puiInit(&(pJeu->pui));
	terInit(&(pJeu->ter));
    (pJeu->cases).xmin=0;
    (pJeu->cases).xmax=6;
    (pJeu->cases).ymin=1;
    (pJeu->cases).ymax=6;
	casesInit((pJeu->cases));
    /*printf("cases jeu.c\n");
	printf("%d\n",(pJeu->cases).xmin);
    printf("%d\n",(pJeu->cases).xmax);
    printf("%d\n",(pJeu->cases).ymin);
    printf("%d\n",(pJeu->cases).ymax);*/

    /*printf("%d\n",c.xmin);
    printf("%d\n",c.xmax);
    printf("%d\n",c.ymin);
    printf("%d\n",c.ymax);*/
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

Cases jeuGetConstCasesPtr( Jeu *pJeu)
{
    /*printf("jeuGetConstCasesPtr\n");
	printf("%d\n",(pJeu->cases).xmin);
    printf("%d\n",(pJeu->cases).xmax);
    printf("%d\n",(pJeu->cases).ymin);
    printf("%d\n",(pJeu->cases).ymax);*/
	return (pJeu->cases);
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
