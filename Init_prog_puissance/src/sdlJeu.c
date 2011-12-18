
#include <assert.h>
#include "sdlJeu.h"
void sdljeuAff_jeu(sdlJeu *pSdlJeu,int i, int j);
const int TAILLE_SPRITE=100;
const int taille_case=100;

int tour=0;

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

	pSdlJeu->surface_ecran = SDL_SetVideoMode(   dimx, dimy, 32, SDL_HWSURFACE);
	assert( pSdlJeu->surface_ecran!=NULL);
	SDL_WM_SetCaption( "Puissance 4", NULL );

/**     AFFICHAGE ECRAN D'ACCUEIL DU JEU                */
	pSdlJeu->surface_puissance = SDL_load_image("data/images/acc1.bmp");
	if (pSdlJeu->surface_puissance==NULL)
		pSdlJeu->surface_puissance = SDL_load_image("data/images/acc1.bmp");
    assert( pSdlJeu->surface_puissance!=NULL);

/**    AFFICHAGE DE TERRAIN AVEC DES CASES VIDES        */
	pSdlJeu->surface_case = SDL_load_image("data/images/casevide.bmp");
	if (pSdlJeu->surface_case==NULL)
		pSdlJeu->surface_case = SDL_load_image("data/images/casevide.bmp");
	assert( pSdlJeu->surface_case!=NULL);
/**    AFFICHAGE ZONE DE PLACEMENT DES PIONS          */
	pSdlJeu->surface_placement = SDL_load_image("data/images/bidon.bmp");
	if (pSdlJeu->surface_placement==NULL)
		pSdlJeu->surface_placement = SDL_load_image("data/images/bidon.bmp");
	assert( pSdlJeu->surface_placement!=NULL);

/**    AFFICHAGE MENU POUR LE COMPTAGE DE SCORE    DE JOUEUR 1      */
	pSdlJeu->surface_menu_joueur1 = SDL_load_image("data/images/score0.bmp");
	if (pSdlJeu->surface_menu_joueur1==NULL)
		pSdlJeu->surface_menu_joueur1 = SDL_load_image("data/images/score0.bmp");
	assert( pSdlJeu->surface_menu_joueur1!=NULL);

/**    AFFICHAGE MENU POUR LE COMPTAGE DE SCORE    DE JOUEUR 2      */
	pSdlJeu->surface_menu_joueur2 = SDL_load_image("data/images/score0rouge.bmp");
	if (pSdlJeu->surface_menu_joueur2==NULL)
		pSdlJeu->surface_menu_joueur2 = SDL_load_image("data/images/score0rouge.bmp");
	assert( pSdlJeu->surface_menu_joueur2!=NULL);

/**    PION JAUNE      */
	pSdlJeu->surface_joueur1 = SDL_load_image("data/images/casejaune.bmp");
	if (pSdlJeu->surface_joueur1==NULL)
		pSdlJeu->surface_joueur1 = SDL_load_image("data/images/casejaune.bmp");
	assert( pSdlJeu->surface_joueur1!=NULL);

/**    PION ROUGE      */
	pSdlJeu->surface_joueur2 = SDL_load_image("data/images/caserouge.bmp");
	if (pSdlJeu->surface_joueur2==NULL)
		pSdlJeu->surface_joueur2 = SDL_load_image("data/images/caserouge.bmp");
	assert( pSdlJeu->surface_joueur2!=NULL);
}



void sdljeuAff(sdlJeu *pSdlJeu)
{
	int x,y;

	const Terrain *pTer = jeuGetConstTerrainPtr(&(pSdlJeu->jeu));
	const Puissance *pPui = jeuGetConstPuissancePtr(&(pSdlJeu->jeu));


	/* Remplir l'écran de bleu */
	SDL_FillRect( pSdlJeu->surface_ecran, &pSdlJeu->surface_ecran->clip_rect, SDL_MapRGB( pSdlJeu->surface_ecran->format, 0, 42, 224 ) );
	SDL_FillRect( pSdlJeu->surface_placement, &pSdlJeu->surface_placement->clip_rect, SDL_MapRGB( pSdlJeu->surface_placement->format,  0, 42, 224 ) );

	for (x=0;x<getDimX(pTer);++x)
		for (y=0;y<getDimY(pTer);++y){
		    if((x<=6)&&(y>=1)&&(y<=7))
                SDL_apply_surface(  pSdlJeu->surface_case, pSdlJeu->surface_ecran, x*TAILLE_SPRITE, y*TAILLE_SPRITE);
            if((x==7)&&(y==2))
                SDL_apply_surface(  pSdlJeu->surface_menu_joueur1, pSdlJeu->surface_ecran, x*TAILLE_SPRITE, y*TAILLE_SPRITE);
            if((x==7)&&(y==3))
                SDL_apply_surface(  pSdlJeu->surface_menu_joueur2, pSdlJeu->surface_ecran, x*TAILLE_SPRITE, y*TAILLE_SPRITE);
            if (terGetXY(pTer,x,y)=='j')
                SDL_apply_surface(  pSdlJeu->surface_joueur1, pSdlJeu->surface_ecran, x*TAILLE_SPRITE, y*TAILLE_SPRITE);
            if (terGetXY(pTer,x,y)=='r')
                SDL_apply_surface(  pSdlJeu->surface_joueur2, pSdlJeu->surface_ecran, x*TAILLE_SPRITE, y*TAILLE_SPRITE);

		}

	SDL_apply_surface(  pSdlJeu->surface_puissance, pSdlJeu->surface_ecran, puiGetX(pPui)*TAILLE_SPRITE,  puiGetY(pPui)*TAILLE_SPRITE );
}



void sdljeuBoucle(sdlJeu *pSdlJeu)
{
	SDL_Event event;

	int continue_boucle = 1, StartDetectEven=0, enter=0;

	Terrain *pTer = jeuGetModifTerrainPtr(&(pSdlJeu->jeu));
    Cases cases = jeuGetConstCasesPtr(&(pSdlJeu->jeu));
	sdljeuAff(pSdlJeu);

	assert( SDL_Flip( pSdlJeu->surface_ecran )!=-1 );

	/* tant que ce n'est pas la fin ... */
	while ( continue_boucle == 1 )
	{
    /*	ICI , il faut intégré les actions de la sourie (insertion pion)*/
		while ( SDL_PollEvent( &event ) )
		{
            //SDL_WaitEvent(&event);
			if ( event.type == SDL_QUIT )
				continue_boucle = 0;


            switch(event.type)
            {
                case SDL_QUIT:
                    continue_boucle = 0;    //si on clique sur la croix le prog s'arrete //
                break;

                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_RETURN ){
                        pSdlJeu->surface_puissance = SDL_load_image("data/images/casevide.bmp");
                        if (pSdlJeu->surface_puissance==NULL)
                            pSdlJeu->surface_puissance = SDL_load_image("data/images/casevide.bmp");
                        assert( pSdlJeu->surface_puissance!=NULL);
                        sdljeuAff(pSdlJeu);
                        printf("----------------->  enter ok\n");
                        enter=1;
                        StartDetectEven = 0;
                    }else enter=0;
                break;

                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT && enter==1){
                       /* pSdlJeu->surface_puissance = SDL_load_image("data/images/casevide.bmp");
                        if (pSdlJeu->surface_puissance==NULL)
                            pSdlJeu->surface_puissance = SDL_load_image("data/images/casevide.bmp");
                        assert( pSdlJeu->surface_puissance!=NULL);
                        sdljeuAff(pSdlJeu);*/

                        StartDetectEven = 1;
                    }

                    if(StartDetectEven == 1){
                        int j= event.button.y/taille_case; //position du click de la souris dans le tableau//
                        int i= event.button.x/taille_case;
                        printf("valeur i = %u valeur j = %u\n",i,j);
/**     */
                        if(tour==0){
                            if(pionJauneValide(pTer,cases,i,j)==1){
                                if (terGetXY(pTer,i,j)=='j'){
                                    SDL_apply_surface(  pSdlJeu->surface_joueur1, pSdlJeu->surface_case, i*TAILLE_SPRITE, j*TAILLE_SPRITE);
                                    tour=1;

                                }
                            }
                        }else{
                            if(pionRougeValide(pTer,cases,i,j)==1){
                                if (terGetXY(pTer,i,j)=='r'){
                                    SDL_apply_surface(  pSdlJeu->surface_joueur2, pSdlJeu->surface_case, i*TAILLE_SPRITE, j*TAILLE_SPRITE);
                                    tour=0;
                                }
                            }
                        }


                        /*if((i>=0)&&(i<=6)&&(j>=1)&&(j<=6)){
                            for(j=6;j>=1;j--) // limiter le Terrain
                            {
                                if((terGetXY(pTer,i,j)=='j')||(terGetXY(pTer,i,j)=='r')||(test==1)){

                                }else{
                                    if(tour==1){ //si tour joueur jaune
                                        terModifXY(pTer,i,j,'j');
                                        terModifXY(pTer,0,0,'j');
                                        tour=0;
                                        test=1;
                                    }
                                    else{ //si tour joueur rouge
                                        terModifXY(pTer,i,j,'r');
                                        terModifXY(pTer,0,0,'r');
                                        tour=1;
                                        test=1;
                                    }
                                }
                                if (terGetXY(pTer,i,j)=='j')
                                    SDL_apply_surface(  pSdlJeu->surface_joueur1, pSdlJeu->surface_case, i*TAILLE_SPRITE, j*TAILLE_SPRITE);
                                    //SDL_apply_surface(  pSdlJeu->surface_joueur1, pSdlJeu->surface_case, 0*TAILLE_SPRITE, 0*TAILLE_SPRITE);

                                if (terGetXY(pTer,i,j)=='r')
                                    SDL_apply_surface(  pSdlJeu->surface_joueur2, pSdlJeu->surface_case, i*TAILLE_SPRITE, j*TAILLE_SPRITE);
                                   // SDL_apply_surface(  pSdlJeu->surface_joueur2, pSdlJeu->surface_case, 0*TAILLE_SPRITE, 0*TAILLE_SPRITE);
                            }
                        }*/

                    }
                break;


            }

			/* Si l'utilisateur a appuyé sur une touche
				il faut utiliser sourie a la place de clavier
			*/
			/*
			if ( event.type == SDL_KEYDOWN )
			{
				switch ( event.key.keysym.sym )
				{
				case SDLK_UP:
					jeuActionClavier( &(pSdlJeu->jeu), 'z');
					break;
				case SDLK_DOWN:
					jeuActionClavier( &(pSdlJeu->jeu), 's');
					break;
				case SDLK_LEFT:
					jeuActionClavier( &(pSdlJeu->jeu), 'q');
					break;
				case SDLK_RIGHT:
					jeuActionClavier( &(pSdlJeu->jeu), 'd');
					break;
				default: break;
				}
			}
			*/

		}

		/* on affiche le jeu sur le buffer caché */
		sdljeuAff(pSdlJeu);

		/* on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans a boucle) */
		SDL_Flip( pSdlJeu->surface_ecran );
	}
}


void sdljeuDetruit( sdlJeu *pSdlJeu)
{
	SDL_FreeSurface( pSdlJeu->surface_puissance );
	SDL_FreeSurface( pSdlJeu->surface_case );
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

void sdljeuAff_jeu(sdlJeu *pSdlJeu, int i, int j)
{/*
	int x,y;

	const Terrain *pTer = jeuGetConstTerrainPtr(&(pSdlJeu->jeu));
	//const Puissance *pPui = jeuGetConstPuissancePtr(&(pSdlJeu->jeu));

	SDL_FillRect( pSdlJeu->surface_ecran, &pSdlJeu->surface_ecran->clip_rect, SDL_MapRGB( pSdlJeu->surface_ecran->format, 0, 42, 224 ) );
	SDL_FillRect( pSdlJeu->surface_placement, &pSdlJeu->surface_placement->clip_rect, SDL_MapRGB( pSdlJeu->surface_placement->format,  0, 42, 224 ) );

	for (x=0;x<getDimX(pTer);++x)
		for (y=0;y<getDimY(pTer);++y){
			if ((terGetXY(pTer,x,y)=='*')&&(x==j)&&(y==i)){
				SDL_apply_surface(  pSdlJeu->surface_joueur1, pSdlJeu->surface_case, 4*TAILLE_SPRITE, 4*TAILLE_SPRITE);
                printf("x=  %u      y=  %u  \n",i,j);

			}
		}

    SDL_apply_surface(  pSdlJeu->surface_joueur1, pSdlJeu->surface_case, 4*TAILLE_SPRITE,  4*TAILLE_SPRITE );
    */
}

