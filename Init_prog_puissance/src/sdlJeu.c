
#include <assert.h>
#include "sdlJeu.h"

void sdljeuAff_jeu(sdlJeu *pSdlJeu,int i, int j);
const int TAILLE_SPRITE=100;
const int taille_case=100;

int tour=0;
int jeuContinu=0;
int enter=0;
int scoreJoueurJ=0;
int scoreJoueurR=0;

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
    switch(jeuContinu)
    {
        case 0:
        {
            pSdlJeu->surface_puissance = SDL_load_image("data/images/acc3.bmp");
            if (pSdlJeu->surface_puissance==NULL)
                pSdlJeu->surface_puissance = SDL_load_image("data/images/acc3.bmp");
            assert( pSdlJeu->surface_puissance!=NULL);
        }
        break;
        case 1:
        {
            pSdlJeu->surface_puissance = SDL_load_image("data/images/gagnantrouge.bmp");
            if (pSdlJeu->surface_puissance==NULL)
                pSdlJeu->surface_puissance = SDL_load_image("data/images/gagnantrouge.bmp");
            assert( pSdlJeu->surface_puissance!=NULL);
        }
        break;
        case 2:
        {
            pSdlJeu->surface_puissance = SDL_load_image("data/images/gagnantjaune.bmp");
            if (pSdlJeu->surface_puissance==NULL)
                pSdlJeu->surface_puissance = SDL_load_image("data/images/gagnantjaune.bmp");
            assert( pSdlJeu->surface_puissance!=NULL);
        }
        break;
        case 3:
        {
            pSdlJeu->surface_puissance = SDL_load_image("data/images/acc2.bmp");
            if (pSdlJeu->surface_puissance==NULL)
                pSdlJeu->surface_puissance = SDL_load_image("data/images/acc2.bmp");
            assert( pSdlJeu->surface_puissance!=NULL);
        }
        break;
    }


/**    AFFICHAGE DE TERRAIN AVEC DES CASES VIDES        */
	pSdlJeu->surface_case = SDL_load_image("data/images/casevide.bmp");
	if (pSdlJeu->surface_case==NULL)
		pSdlJeu->surface_case = SDL_load_image("data/images/casevide.bmp");
	assert( pSdlJeu->surface_case!=NULL);
/**    AFFICHAGE ZONE DE PLACEMENT DES PIONS          */
	pSdlJeu->surface_placement = SDL_load_image("data/images/casejaune.bmp");
	if (pSdlJeu->surface_placement==NULL)
		pSdlJeu->surface_placement = SDL_load_image("data/images/casejaune.bmp");
	assert( pSdlJeu->surface_placement!=NULL);

/**    AFFICHAGE MENU POUR LE COMPTAGE DE SCORE    DE JOUEUR 1      */
	/*pSdlJeu->surface_menu_joueur1 = SDL_load_image("data/images/score0.bmp");
	if (pSdlJeu->surface_menu_joueur1==NULL)
		pSdlJeu->surface_menu_joueur1 = SDL_load_image("data/images/score0.bmp");
	assert( pSdlJeu->surface_menu_joueur1!=NULL);
*/
/**    AFFICHAGE MENU POUR LE COMPTAGE DE SCORE    DE JOUEUR 2      */
/*	pSdlJeu->surface_menu_joueur2 = SDL_load_image("data/images/score0rouge.bmp");
	if (pSdlJeu->surface_menu_joueur2==NULL)
		pSdlJeu->surface_menu_joueur2 = SDL_load_image("data/images/score0rouge.bmp");
	assert( pSdlJeu->surface_menu_joueur2!=NULL);*/
//    sdljeuscore(pSdlJeu,'j',0);
//    sdljeuscore(pSdlJeu,'r',0);
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
//	SDL_FillRect( pSdlJeu->surface_placement, &pSdlJeu->surface_placement->clip_rect, SDL_MapRGB( pSdlJeu->surface_placement->format,  0, 42, 224 ) );	for (x=0;x<getDimX(pTer);++x)
	for (x=0;x<getDimX(pTer);++x)
	{
		for (y=0;y<getDimY(pTer);++y)
		{
            if((x==0)&&(y==0))
                SDL_apply_surface(  pSdlJeu->surface_placement, pSdlJeu->surface_ecran, x*TAILLE_SPRITE, y*TAILLE_SPRITE);
		    if((x<=getDimX(pTer)-2)&&(y>=1)&&(y<=getDimY(pTer)-1))
                SDL_apply_surface(  pSdlJeu->surface_case, pSdlJeu->surface_ecran, x*TAILLE_SPRITE, y*TAILLE_SPRITE);
            if((x==getDimX(pTer)-1)&&(y==2))
                SDL_apply_surface(  pSdlJeu->surface_menu_joueur1, pSdlJeu->surface_ecran, x*TAILLE_SPRITE, y*TAILLE_SPRITE);
            if((x==getDimX(pTer)-1)&&(y==3))
                SDL_apply_surface(  pSdlJeu->surface_menu_joueur2, pSdlJeu->surface_ecran, x*TAILLE_SPRITE, y*TAILLE_SPRITE);
            if (terGetXY(pTer,x,y)=='j')
                SDL_apply_surface(  pSdlJeu->surface_joueur1, pSdlJeu->surface_ecran, x*TAILLE_SPRITE, y*TAILLE_SPRITE);
            if (terGetXY(pTer,x,y)=='r')
                SDL_apply_surface(  pSdlJeu->surface_joueur2, pSdlJeu->surface_ecran, x*TAILLE_SPRITE, y*TAILLE_SPRITE);
		}
	}

    if(enter==0)
    SDL_apply_surface(  pSdlJeu->surface_puissance, pSdlJeu->surface_ecran, 0, 0);
    else
	SDL_apply_surface(  pSdlJeu->surface_placement, pSdlJeu->surface_ecran, puiGetX(pPui)*TAILLE_SPRITE,  puiGetY(pPui)*TAILLE_SPRITE );
}



void sdljeuBoucle(sdlJeu *pSdlJeu)
{
	SDL_Event event;

	int continue_boucle = 1, StartDetectEven=0;

	Terrain *pTer = jeuGetModifTerrainPtr(&(pSdlJeu->jeu));
//	Joueur *pJou = jeuGetJoueurPtr(&(pSdlJeu->jeu));

	sdljeuAff(pSdlJeu);

	assert( SDL_Flip( pSdlJeu->surface_ecran )!=-1 );

	/* tant que ce n'est pas la fin ... */
	while ( continue_boucle == 1 )
	{
    /*	ICI , il faut intégré les actions de la sourie (insertion pion)*/
		while ( SDL_PollEvent( &event ) )
		{
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
                        sdljeutour(pSdlJeu);
                        sdljeuAff(pSdlJeu);
                        sdljeuscore(pSdlJeu,'j',0);
                        sdljeuscore(pSdlJeu,'r',0);
                        printf("----------------->  enter ok\n");
                        enter=1;
                        StartDetectEven = 0;
                    }else enter=0;
                break;

                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT && enter==1){

                        StartDetectEven = 1;
                    }

                    if(StartDetectEven == 1){
                        int j= event.button.y/taille_case; //position du click de la souris dans le tableau//
                        int i= event.button.x/taille_case;
                        printf("valeur i = %u valeur j = %u\n",i,j);

/**     */              j= positionDePion(pTer, i, j);
                        printf("valeur i = %u valeur j = %u\n",i,j);

                        if(tour==0){
                            if(pionJauneValide(pTer,i,j)==1){
                                printf("i : %d  j : %d \n", i, j);
                                if (terGetXY(pTer,i,j)=='j'){
                                    SDL_apply_surface(  pSdlJeu->surface_joueur1, pSdlJeu->surface_case, i*TAILLE_SPRITE, j*TAILLE_SPRITE);
                                    tour=1;
                                    sdljeutour(pSdlJeu);
                                        if(balayage(pTer,i,j,'j')==1)
                                        {
                                            /*jeuContinu = 3;
//                                            printf("scoreJoueurJ %d\n",scoreJoueurJ);
//                                            printf("jaune est ganiee \n");
                                            sdljeuInit(pSdlJeu);
                                            sdljeuAff(pSdlJeu);
                                            sdljeuscore(pSdlJeu,'j',1);
                                            enter=0;*/
                                            StartDetectEven=0;
                                            sdljeuRecommence(pSdlJeu, 3, 0, 'j');
                                            continue;
                                        }

                                }
                            }
                        }else{
                            if(pionRougeValide(pTer,i,j)==1){
                                if (terGetXY(pTer,i,j)=='r'){
                                    SDL_apply_surface(  pSdlJeu->surface_joueur2, pSdlJeu->surface_case, i*TAILLE_SPRITE, j*TAILLE_SPRITE);
                                    tour=0;
                                    sdljeutour(pSdlJeu);
                                        if(balayage(pTer,i,j,'r')==1)
                                        {
//                                            printf("scoreJoueurR %d\n",scoreJoueurR);
//                                            printf("rouge est ganiee \n");
                                            /*jeuContinu = 3;
                                            enter=0;
                                            StartDetectEven=0;
                                            sdljeuInit(pSdlJeu);
                                            sdljeuAff(pSdlJeu);
                                            sdljeuscore(pSdlJeu,'r',1);*/
                                            StartDetectEven=0;
                                            sdljeuRecommence(pSdlJeu, 3, 0, 'r');
                                        }
                                }
                            }
                        }
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


void sdljeuRecommence(sdlJeu *pSdlJeu,const int jeuCont, const int ent, const char c)
{
    jeuContinu = jeuCont;
    enter=ent;
    sdljeuInit(pSdlJeu);
    sdljeuAff(pSdlJeu);
    sdljeuscore(pSdlJeu,c,1);


    if((c=='j')&&(scoreJoueurJ==3))
    {
//        tour=1;
        jeuContinu =2;
        enter=ent;


        sdljeuInit(pSdlJeu);
        scoreJoueurJ=0;
        scoreJoueurR=0;
        sdljeuAff(pSdlJeu);
//        sdljeuscore(pSdlJeu,c,1);
    }

    else if((c=='r')&&(scoreJoueurR==3))
    {
//        tour=0;
        jeuContinu =1;
        enter=ent;
        scoreJoueurJ=0;
        scoreJoueurR=0;
        sdljeuInit(pSdlJeu);
        sdljeuAff(pSdlJeu);
        //sdljeuscore(pSdlJeu,c,1);
    }
    /*else
    {
        jeuContinu = jeuCont;
        enter=ent;
        sdljeuInit(pSdlJeu);
        sdljeuAff(pSdlJeu);
        sdljeuscore(pSdlJeu,c,1);
    }*/
}

void sdljeuscore(sdlJeu *pSdlJeu, const char c,const int ajout)
{
    if(ajout==1)
    {
        if(c=='j')
            scoreJoueurJ++;
        else
            scoreJoueurR++;
    }

    if(c=='j')
    {
        if(scoreJoueurJ==0)
        {
            /**    AFFICHAGE MENU POUR LE COMPTAGE DE SCORE    DE JOUEUR 1      */
            pSdlJeu->surface_menu_joueur1 = SDL_load_image("data/images/score0.bmp");
            if (pSdlJeu->surface_menu_joueur1==NULL)
                pSdlJeu->surface_menu_joueur1 = SDL_load_image("data/images/score0.bmp");
            assert( pSdlJeu->surface_menu_joueur1!=NULL);
        }
        else if(scoreJoueurJ==1)
        {
            /**    AFFICHAGE MENU POUR LE COMPTAGE DE SCORE    DE JOUEUR 1      */
            pSdlJeu->surface_menu_joueur1 = SDL_load_image("data/images/score1.bmp");
            if (pSdlJeu->surface_menu_joueur1==NULL)
                pSdlJeu->surface_menu_joueur1 = SDL_load_image("data/images/score1.bmp");
            assert( pSdlJeu->surface_menu_joueur1!=NULL);
        }
        else if(scoreJoueurJ==2)
        {
            /**    AFFICHAGE MENU POUR LE COMPTAGE DE SCORE    DE JOUEUR 1      */
            pSdlJeu->surface_menu_joueur1 = SDL_load_image("data/images/score2.bmp");
            if (pSdlJeu->surface_menu_joueur1==NULL)
                pSdlJeu->surface_menu_joueur1 = SDL_load_image("data/images/score2.bmp");
            assert( pSdlJeu->surface_menu_joueur1!=NULL);
        }
        else if(scoreJoueurJ==3)
        {
            /**    AFFICHAGE MENU POUR LE COMPTAGE DE SCORE    DE JOUEUR 1      */
            pSdlJeu->surface_menu_joueur1 = SDL_load_image("data/images/score3.bmp");
            if (pSdlJeu->surface_menu_joueur1==NULL)
                pSdlJeu->surface_menu_joueur1 = SDL_load_image("data/images/score3.bmp");
            assert( pSdlJeu->surface_menu_joueur1!=NULL);
        }
    }
    else
    {
        if(scoreJoueurR==0)
        {
            /**    AFFICHAGE MENU POUR LE COMPTAGE DE SCORE    DE JOUEUR 2      */
            pSdlJeu->surface_menu_joueur2 = SDL_load_image("data/images/score0rouge.bmp");
            if (pSdlJeu->surface_menu_joueur2==NULL)
                pSdlJeu->surface_menu_joueur2 = SDL_load_image("data/images/score0rouge.bmp");
            assert( pSdlJeu->surface_menu_joueur2!=NULL);
        }
        else if(scoreJoueurR==1)
        {
            /**    AFFICHAGE MENU POUR LE COMPTAGE DE SCORE    DE JOUEUR 2      */
            pSdlJeu->surface_menu_joueur2 = SDL_load_image("data/images/score1rouge.bmp");
            if (pSdlJeu->surface_menu_joueur2==NULL)
                pSdlJeu->surface_menu_joueur2 = SDL_load_image("data/images/score1rouge.bmp");
            assert( pSdlJeu->surface_menu_joueur2!=NULL);
        }
        else if(scoreJoueurR==2)
        {
            /**    AFFICHAGE MENU POUR LE COMPTAGE DE SCORE    DE JOUEUR 2      */
            pSdlJeu->surface_menu_joueur2 = SDL_load_image("data/images/score2rouge.bmp");
            if (pSdlJeu->surface_menu_joueur2==NULL)
                pSdlJeu->surface_menu_joueur2 = SDL_load_image("data/images/score2rouge.bmp");
            assert( pSdlJeu->surface_menu_joueur2!=NULL);
        }
        else if(scoreJoueurR==3)
        {
            /**    AFFICHAGE MENU POUR LE COMPTAGE DE SCORE    DE JOUEUR 2      */
            pSdlJeu->surface_menu_joueur2 = SDL_load_image("data/images/score3rouge.bmp");
            if (pSdlJeu->surface_menu_joueur2==NULL)
                pSdlJeu->surface_menu_joueur2 = SDL_load_image("data/images/score3rouge.bmp");
            assert( pSdlJeu->surface_menu_joueur2!=NULL);
        }
    }
}





void sdljeutour(sdlJeu *pSdlJeu)
{
    if(tour==0)
    {
        pSdlJeu->surface_placement = SDL_load_image("data/images/casejaune.bmp");
        if (pSdlJeu->surface_placement==NULL)
            pSdlJeu->surface_placement = SDL_load_image("data/images/casejaune.bmp");
        assert( pSdlJeu->surface_placement!=NULL);
    }
    else
    {
    	pSdlJeu->surface_placement = SDL_load_image("data/images/caserouge.bmp");
        if (pSdlJeu->surface_placement==NULL)
            pSdlJeu->surface_placement = SDL_load_image("data/images/caserouge.bmp");
        assert( pSdlJeu->surface_placement!=NULL);
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

