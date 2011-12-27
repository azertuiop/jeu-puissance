
#ifndef _SDLJEU_H
#define _SDLJEU_H

#include <SDL/SDL.h>
#include "Jeu.h"


typedef struct{
	Jeu jeu;
	SDL_Surface* surface_ecran;
	SDL_Surface* surface_puissance;
	SDL_Surface* surface_case;
	SDL_Surface* surface_placement;
	SDL_Surface* surface_menu_joueur1;
	SDL_Surface* surface_menu_joueur2;
	SDL_Surface* surface_joueur1;
	SDL_Surface* surface_joueur2;
	SDL_Surface* surface_exit;
} sdlJeu;

void sdljeuInit(sdlJeu *);
void sdljeuBoucle(sdlJeu *);
void sdljeuLibere(sdlJeu *);
void sdljeuDetruit(sdlJeu *);

#endif
