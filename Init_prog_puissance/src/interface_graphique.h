#ifndef _INTERFACE_H
#define _INTERFACE_H

#include <stdio.h>
/*
	ajouter SDL
*/

#include "deplacement_pion.h"
#include "initialisation.h"
#include "joueur.h"

void remplissagecarte(SDL_Surface *ecran,SDL_Surface *imageDeFond,SDL_Rect positionFond,unsigned short terrin[][colone],unsigned char score);

unsigned char menu(unsigned short carte[][colone],SDL_Surface *imageDeFond,SDL_Surface *ecran,unsigned char page_acceuil,SDL_Event event,SDL_Rect positionFond);

#endif
