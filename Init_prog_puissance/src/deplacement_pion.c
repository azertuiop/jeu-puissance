#include <stdio.h>
#include "deplacement_pion.h"



unsigned short position_pion(SDL_Surfece *ecran, SDL_Surfece *imageFond, SDL_Rect positionFond, unsigned short terrin[][colonne]);
unsigned char balayage_lignes(unsigned short carte[][colone]) ;
unsigned char balayage_colones(unsigned short carte[][colone]) ;
unsigned char balayage_diagonale_haut(unsigned short carte[][colone]);
void deplacementPion(Couleur *couleur, SDL_Surface *ecran,SDL_Surface *imageDeFond,SDL_Rect positionFond,unsigned short carte[][colone],unsigned short i,unsigned short j );

