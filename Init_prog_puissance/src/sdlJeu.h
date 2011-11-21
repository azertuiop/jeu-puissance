
#ifndef _SDLJEU_H
#define _SDLJEU_H

#include <SDL/SDL.h>
#include "Jeu.h"


typedef struct 
{
	Jeu jeu;
	SDL_Surface* surface_ecran;
	SDL_Surface* surface_pacman;
	SDL_Surface* surface_mur;
} sdlJeu;

void sdljeuInit(sdlJeu *);
void sdljeuBoucle(sdlJeu *);
void sdljeuLibere(sdlJeu *);
void sdljeuDetruit(sdlJeu *);

#endif
