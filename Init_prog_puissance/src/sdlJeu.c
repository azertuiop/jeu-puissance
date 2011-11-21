
#include <assert.h>
#include "sdlJeu.h"

const int TAILLE_SPRITE=32;

SDL_Surface *SDL_load_image(const char* filename );
void SDL_apply_surface( SDL_Surface* source, SDL_Surface* destination, int x, int y );



void sdljeuInit(sdlJeu *pSdlJeu)
{
	Jeu *pJeu;
	int dimx, dimy;
	
	pJeu = &(pSdlJeu->jeu);
	jeuInit(pJeu);

	assert(   SDL_Init( SDL_INIT_EVERYTHING )!= -1 );

	dimx = getDimX( jeuGetConstTerrainPtr(pJeu) );
	dimy = getDimY( jeuGetConstTerrainPtr(pJeu) );
	dimx = dimx * TAILLE_SPRITE;
	dimy = dimy * TAILLE_SPRITE;
	pSdlJeu->surface_ecran = SDL_SetVideoMode(   dimx, dimy, 32, SDL_SWSURFACE );
	assert( pSdlJeu->surface_ecran!=NULL);
	SDL_WM_SetCaption( "Pacman v0.1", NULL );

	pSdlJeu->surface_pacman = SDL_load_image("data/***********.bmp");
	if (pSdlJeu->surface_pacman==NULL)
		pSdlJeu->surface_pacman = SDL_load_image("***********.bmp");
	assert( pSdlJeu->surface_pacman!=NULL);

	pSdlJeu->surface_mur = SDL_load_image("************.bmp");
	if (pSdlJeu->surface_mur==NULL)
		pSdlJeu->surface_mur = SDL_load_image("*************.bmp");
	assert( pSdlJeu->surface_mur!=NULL);
}



void sdljeuAff(sdlJeu *pSdlJeu)
{
	int x,y;

	const Terrain *pTer = jeuGetConstTerrainPtr(&(pSdlJeu->jeu));
	const Pacman *pPac = jeuGetConstPacmanPtr(&(pSdlJeu->jeu));

	/* Remplir l'écran de blanc */
	SDL_FillRect( pSdlJeu->surface_ecran, &pSdlJeu->surface_ecran->clip_rect, SDL_MapRGB( pSdlJeu->surface_ecran->format, 0xFF, 0xFF, 0xFF ) );

	for (x=0;x<getDimX(pTer);++x)
		for (y=0;y<getDimY(pTer);++y)
			if (terGetXY(pTer,x,y)=='#')
				SDL_apply_surface(  pSdlJeu->surface_mur, pSdlJeu->surface_ecran, x*TAILLE_SPRITE, y*TAILLE_SPRITE);

	/* Copier le sprite de Pacman sur l'écran */
	SDL_apply_surface(  pSdlJeu->surface_pacman, pSdlJeu->surface_ecran, pacGetX(pPac)*TAILLE_SPRITE,  pacGetY(pPac)*TAILLE_SPRITE );
}



void sdljeuBoucle(sdlJeu *pSdlJeu)
{
	SDL_Event event;
	int continue_boucle = 1;

	sdljeuAff(pSdlJeu);
	assert( SDL_Flip( pSdlJeu->surface_ecran )!=-1 );

	/* tant que ce n'est pas la fin ... */
	while ( continue_boucle == 1 )
	{
		/* tant qu'il y a des evenements à traiter : cette boucle n'est pas bloquante */
		
		/*	ICI , il faut intégré les actions de la sourie (insertion pion)*/
		while ( SDL_PollEvent( &event ) )
		{
			/* Si l'utilisateur a cliqué sur la croix de fermeture */
			if ( event.type == SDL_QUIT )
				continue_boucle = 0;

			/* Si l'utilisateur a appuyé sur une touche 
				il faut utiliser sourie a la place de clavier
			*/
			if ( event.type == SDL_KEYDOWN )
			{
				switch ( event.key.keysym.sym )
				{
				case SDLK_UP:
					jeuActionClavier( &(pSdlJeu->jeu), 'h');
					break;
				case SDLK_DOWN:
					jeuActionClavier( &(pSdlJeu->jeu), 'b');
					break;
				case SDLK_LEFT:
					jeuActionClavier( &(pSdlJeu->jeu), 'g');
					break;
				case SDLK_RIGHT:
					jeuActionClavier( &(pSdlJeu->jeu), 'd');
					break;
				default: break;
				}
			}

		}

		/* on affiche le jeu sur le buffer caché */
		sdljeuAff(pSdlJeu);

		/* on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans a boucle) */
		SDL_Flip( pSdlJeu->surface_ecran );
	}
}


void sdljeuDetruit( sdlJeu *pSdlJeu)
{
	SDL_FreeSurface( pSdlJeu->surface_pacman );
	SDL_FreeSurface( pSdlJeu->surface_mur );
	SDL_Quit();
}



SDL_Surface *SDL_load_image(const char* filename )
{
	/* Temporary storage for the image that's loaded */
	SDL_Surface* loadedImage = NULL;

	/* The optimized image that will be used */
	SDL_Surface* optimizedImage = NULL;

	/* Load the image */
	loadedImage = SDL_LoadBMP( filename );

	/* If nothing went wrong in loading the image */
	if ( loadedImage != NULL )
	{
		/* Create an optimized image */
		optimizedImage = SDL_DisplayFormat( loadedImage );

		/* Free the old image */
		SDL_FreeSurface( loadedImage );
	}

	/* Return the optimized image */
	return optimizedImage;
}


void SDL_apply_surface( SDL_Surface* source, SDL_Surface* destination, int x, int y )
{
	/* Make a temporary rectangle to hold the offsets */
	SDL_Rect offset;

	/* Give the offsets to the rectangle */
	offset.x = x;
	offset.y = y;

	/* Blit the surface */
	SDL_BlitSurface( source, NULL, destination, &offset );
}
