#ifndef _JOUEUR_H
#define _JOUEUR_H

#include <stdio.h>


#include "deplacement_pion.h"
#include "initialisation.h"
#include "interface_graphique.h"


unsigned char alternancejoueur(unsigned char tour,SDL_Surface *ecran,SDL_Surface *imageDeFond,SDL_Rect positionFond,FSOUND_SAMPLE *pion) ;

void affichage_gagnant(SDL_Surface *ecran,SDL_Surface *petite_fenetre,unsigned char compteur,unsigned char tour,FSOUND_SAMPLE *pion) ;


#endif
