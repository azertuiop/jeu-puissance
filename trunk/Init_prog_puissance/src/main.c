#include <stdlib.h>
#include <stdio.h>
#include "deplacement_pion.h"
#include "initialisation.h"
#include "joueur.h"
#include "interface_graphique.h"
/*
	IL FAUT PENSER A INSERER LES BIBLIO SDL
*/

/**
* Définition des variables globales
*/
#define taille_image        95 		// Taille d'une image (carré) en pixels //
#define lignes              6   	//nombre de lignes//
#define colone              8   	//nombre de colones//
#define largeur_fenetre     colone * taille_image  //taille proportionnel a l'image et au tableau//
#define hauteur_fenetre     lignes * taille_image
#define CASEVIDE            1
#define casejaune           2
#define caserouge           3

int main()
{
      unsigned short i,j;
      unsigned char continuer = 1,tour=0,compteur=0,page_acceuil=1,scorerouge=0,scorejaune=0,nbreset=0;


      SDL_Surface *ecran = NULL, *imageDeFond = NULL,*petite_fenetre= NULL ;                           //declaration des différentes sur face a afficher //
      SDL_Rect positionFond ;					// fiche pour rentrer les coordonées en pixel pour positioner une image//
      SDL_Event event;						// varaible d'évenement //
      FSOUND_SAMPLE *pion = NULL;				// variable pour le son //


	while((scorejaune!=3)&& (scorerouge!=3))			// tant que aucun joueur n'a atteint le score 3 //
	{
		continuer=1 ;
		compteur =0 ;
		tour=0 ;


	      if((scorejaune==0)&&(scorerouge==0)&&(nbreset==0))
	      {
		 continuer = menu(carte,imageDeFond,ecran,page_acceuil,event,positionFond) ;//page d'acceuil tant que l'on a pas cliquer sur jouer//
	      }



	     if(continuer!=0)
	     {
	       SDL_Init(SDL_INIT_VIDEO);
	       SDL_WM_SetIcon(SDL_LoadBMP("icone.bmp"), NULL);                                                 //met une icone pour la fenetre //
	       ecran = SDL_SetVideoMode(largeur_fenetre,hauteur_fenetre, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);  //caractéristique de la fenetre principale //
	       SDL_WM_SetCaption("puissance 4 !!!", NULL); 	// met un titre a la fenetre //

	       remplissagecarte(ecran,imageDeFond,positionFond,carte,scorejaune,scorerouge) ; 	 //remplit la fenetre avec des cases vides //

	       SDL_Flip(ecran); 	//rafraichit l' écran ///
	       SDL_FreeSurface(imageDeFond);


	     }


	    while(continuer){ 	 //continuité du prog //

		SDL_WaitEvent(&event); 	 //bibliothèque d'evennement //
		   switch(event.type)
		   {
		       case SDL_QUIT:
		       continuer = 0;	//si on clique sur la croix le prog s'arrete //
		       break;

		       case SDL_MOUSEBUTTONDOWN: 	//Clic de la souris //

		       if (event.button.button == SDL_BUTTON_LEFT) 	//si clic gauche //

		           {
		                i= event.button.y / taille_image;       //position du click de la souris dans le tableau//
		                j= event.button.x / taille_image ;      //on recupère la ligne et la colone //

		            if((j==7)&& ((i==4)||(i==5))) 	 // si il y a reset alors on arret et on réinitialise les scores //
		            {
		                nbreset++ ;
		                continuer=0 ;
		                scorejaune=0 ;
		                scorerouge=0 ;
		                reinitialisation_des_scores(tour,scorerouge,scorejaune,imageDeFond,ecran,positionFond) ;
		            }


		            if((carte[i][j]!=casejaune)&&(carte[i][j]!=caserouge)&&(j!=7)&&(continuer==1)) //fait la suite seulement si la case cliquée est vide et si reset n'est pas cliqué//
		            {

		                if(tour==0)//le joueur 1 qui joue//
		                 {
		                    deplacementpionjaune(ecran,imageDeFond,positionFond,carte,i,j) ;//carte=tableau//

		                  }

		                if(tour== 1)//c'est le tour du joueur 2//
		                 {
		                    deplacementpionrouge(ecran,imageDeFond,positionFond,carte,i,j) ;

		                 }

		                 tour = alternancejoueur(tour,ecran,imageDeFond,positionFond,pion) ;     //la variable tour alterne entre 1 et 0 //


		                 continuer = balayage_lignes(carte) ;

		                 if(continuer!=0)
		                  {
		                    continuer=  balayage_colones(carte) ;             //si il y a dejà 4 pour une ligne alors on ne fait pas les colones//
		                  }


		                 if(continuer!=0)
		                 {
		                   continuer= balayage_diagonale_haut(carte) ;            //si il y a dejà 4 pour une ligne alors on ne fait pas les diagonales//
		                 }


		                 if(continuer!=0)
		                 {

		                     continuer=balayage_diagonale_haut_bis(carte) ;
		                 }



		                 compteur ++ ;   // permet de compter le nombre de tour joués et donc voir si la grille est pleine ou pas //
		                 if(continuer==0)  // si un joueur a gagné //
		                 {

		                     if(tour==1)
		                     {
		                       scorejaune++;    // on incremente le score du joueur jaune //
		                     }

		                      if(tour==0)
		                     {
		                       scorerouge++;    // on incremente le score du joueur rouge //
		                     }



		                }


		                 if((continuer==0)||(compteur==42))       //si un joueur fait 4 ou que la grille est pleine et qu'un joueur atteind le score 3 //
		                 {
		                     if((scorejaune==3) || (scorerouge==3))
		                     {
		                      SDL_Delay(2000) ;                                               //tempo de 2 seconde //
		                      affichage_gagnant(ecran,petite_fenetre,compteur,tour,pion) ;  // affiche une image et met du son  a voir //
		                      SDL_Delay(12000) ;                                            //tempo de 12 seconde le temps que le son se termine //
		                    }
		                 }




		          }
		        }

		       break;



	     }

	  }
	}
}

