#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <time.h>
#include <fmod.h>
#define taille_image        95 // Taille d'une image (carré) en pixels //
#define lignes              6   //nombre de lignes//
#define colone              8   //nombre de colones//
#define largeur_fenetre     colone * taille_image  //taille proportionnel a l'image et au tableau//
#define hauteur_fenetre     lignes * taille_image
#define CASEVIDE            1
#define casejaune           2
#define caserouge           3

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void remplissagecarte(SDL_Surface *ecran,SDL_Surface *imageDeFond,SDL_Rect positionFond,unsigned short carte[][colone],unsigned char scorejaune,unsigned char scorerouge );
void deplacementpionjaune(SDL_Surface *ecran,SDL_Surface *imageDeFond,SDL_Rect positionFond,unsigned short carte[][colone],unsigned short i,unsigned short j );
void deplacementpionrouge(SDL_Surface *ecran,SDL_Surface *imageDeFond,SDL_Rect positionFond,unsigned short carte[][colone],unsigned short i,unsigned short j );
unsigned short carte[lignes][colone]= {CASEVIDE} ;//variable globale
unsigned char alternancejoueur(unsigned char tour,SDL_Surface *ecran,SDL_Surface *imageDeFond,SDL_Rect positionFond,FSOUND_SAMPLE *pion) ;
/*unsigned char balayage_lignes(unsigned short carte[][colone]) ;
unsigned char balayage_colones(unsigned short carte[][colone]) ;
unsigned char balayage_diagonale_haut(unsigned short carte[][colone]) ;*/
unsigned char balayage_diagonale_haut_bis(unsigned short carte[][colone]) ;
void affichage_gagnant(SDL_Surface *ecran,SDL_Surface *petite_fenetre,unsigned char compteur,unsigned char tour,FSOUND_SAMPLE *pion) ;
unsigned char menu(unsigned short carte[][colone],SDL_Surface *imageDeFond,SDL_Surface *ecran,unsigned char page_acceuil,SDL_Event event,SDL_Rect positionFond) ;
void reinitialisation_des_scores(unsigned char tour,unsigned char scorerouge,unsigned char scorejaune,SDL_Surface *imageDeFond,SDL_Surface *ecran,SDL_Rect positionFond);

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

int main()
{




      unsigned short i,j;
      unsigned char continuer = 1,tour=0,compteur=0,page_acceuil=1,scorerouge=0,scorejaune=0,nbreset=0;


      SDL_Surface *ecran = NULL, *imageDeFond = NULL,*petite_fenetre= NULL ;                           //declaration des différentes sur face a afficher //
      SDL_Rect positionFond ;                                                                          // fiche pour rentrer les coordonées en pixel pour positioner une image//
      SDL_Event event;                                                                                // varaible d'évenement //
      FSOUND_SAMPLE *pion = NULL;                                                                     // variable pour le son //


while((scorejaune!=3)&& (scorerouge!=3))                                                          // tant que aucun joueur n'a atteint le score 3 //
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
       SDL_WM_SetCaption("puissance 4 !!!", NULL);                                                   // met un titre a la fenetre //

       remplissagecarte(ecran,imageDeFond,positionFond,carte,scorejaune,scorerouge) ;               //remplit la fenetre avec des cases vides //

       SDL_Flip(ecran);                                                                             //rafraichit l' écran ///
       SDL_FreeSurface(imageDeFond);


     }






    while(continuer)                                                                           //continuité du prog //
   {

        SDL_WaitEvent(&event);                                                                   //bibliothèque d'evennement //
           switch(event.type)
           {
               case SDL_QUIT:
               continuer = 0;                                                                    //si on clique sur la croix le prog s'arrete //
               break;

               case SDL_MOUSEBUTTONDOWN:                                                         //Clic de la souris //

               if (event.button.button == SDL_BUTTON_LEFT)                                       //si clic gauche //

                   {
                        i= event.button.y / taille_image;       //position du click de la souris dans le tableau//
                        j= event.button.x / taille_image ;      //on recupère la ligne et la colone //

                    if((j==7)&& ((i==4)||(i==5)))             // si il y a reset alors on arret et on réinitialise les scores //
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
}}

void remplissagecarte(SDL_Surface *ecran,SDL_Surface *imageDeFond,SDL_Rect positionFond,unsigned short carte[][colone],unsigned char scorejaune,unsigned char scorerouge )
{
   unsigned short i,j ;

   for(i=0;i<lignes;i++)    //fonction qui affiche le puissance 4 vide//
    {

        for(j=0;j<colone;j++)
        {
            positionFond.x = j*taille_image;
            positionFond.y = i*taille_image;


            imageDeFond = SDL_LoadBMP("casevide.bmp");
            carte[i][j]= CASEVIDE ;


            if(j==7)
            {
               imageDeFond = SDL_LoadBMP("casebleu.bmp");  //affichage personnalisé pour chaque case de la dernière colone //
            }

            if((j==7)&&(i==2))
            {
                imageDeFond = SDL_LoadBMP("casejaune.bmp");

            }

            if((j==7)&&(i==1))                                      //affichage selon le score des joueurs //
            {
                if(scorejaune==0)
                {
                  imageDeFond = SDL_LoadBMP("score0.bmp");
                }
                if(scorejaune==1)
                {
                  imageDeFond = SDL_LoadBMP("score1.bmp");
                }
                if(scorejaune==2)
                {
                  imageDeFond = SDL_LoadBMP("score2.bmp");
                }
                if(scorejaune==3)
                {
                  imageDeFond = SDL_LoadBMP("score3.bmp");
                }

            }
            if((j==7)&&(i==3))
            {
                if(scorerouge==0)
                {
                  imageDeFond = SDL_LoadBMP("score0rouge.bmp");
                }
                if(scorerouge==1)
                {
                  imageDeFond = SDL_LoadBMP("score1rouge.bmp");
                }
                if(scorerouge==2)
                {
                  imageDeFond = SDL_LoadBMP("score2rouge.bmp");
                }
                if(scorerouge==3)
                {
                  imageDeFond = SDL_LoadBMP("score3rouge.bmp");
                }
            }

            if((j==7)&&(i==4))
            {
                imageDeFond = SDL_LoadBMP("reset.bmp");
            }
            if((j==7)&&(i==5))
            {
                imageDeFond = NULL;
            }
            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // colle l'image a l'écran //
            SDL_Flip(ecran);                                       // libert la surface //

        }




     }


}



void deplacementpionrouge(SDL_Surface *ecran,SDL_Surface *imageDeFond,SDL_Rect positionFond,unsigned short carte[][colone],unsigned short a,unsigned short j )
{
    unsigned short i ;

    i=5 ; // on démarre a la dernière ligne puis on monte les pions//


        if((carte[a][j]!= casejaune)&& (carte[a][j]!= caserouge))  //si la case choisit ne contient rien alors on replit//
        {

                while((carte[i][j]== casejaune) || (carte[i][j]== caserouge)) // si la case choisit est dejà remplit alors on monte d'une ligne //
                {
                    i--;
                }

                carte[i][j]= caserouge ;


                positionFond.x = j*taille_image ;  // position l'image //
                positionFond.y = i*taille_image ;

                imageDeFond = SDL_LoadBMP("caserouge.bmp") ;
                SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

                SDL_Flip(ecran);
                SDL_FreeSurface(imageDeFond);

        }

}





void deplacementpionjaune(SDL_Surface *ecran,SDL_Surface *imageDeFond,SDL_Rect positionFond,unsigned short carte[][colone],unsigned short a,unsigned short j )
{
    unsigned short i ;

    i=5 ; // on démarre a la dernière ligne puis on monte les pions//

        if((carte[a][j]!= casejaune)&& (carte[a][j]!= caserouge))  //si la case choisit ne contient rien alors on replit//
         {

                while((carte[i][j]== casejaune) || (carte[i][j]== caserouge)) // si la case choisit est dejà remplit alors on monte d'une ligne //
                {
                    i--;
                }

                carte[i][j]= casejaune ;

                positionFond.x = j*taille_image ;  //position l'image //
                positionFond.y = i*taille_image ;

                imageDeFond = SDL_LoadBMP("casejaune.bmp") ;
                SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

                SDL_Flip(ecran);
                SDL_FreeSurface(imageDeFond);

        }

}



unsigned char alternancejoueur(unsigned char tour,SDL_Surface *ecran,SDL_Surface *imageDeFond,SDL_Rect positionFond,FSOUND_SAMPLE *pion)
{

    tour ++ ;
    unsigned char i,j ;
    i=2 ;
    j=7 ;

    if( tour<2)
    {
                 // tour = 0 ou 1 //

    }

     else
     {
         tour = 0 ;
     }


     if(tour==0)
     {
        imageDeFond = SDL_LoadBMP("casejaune.bmp"); //pour l'image avec le pion de droite indicant qui doit jouer //
     }

     else
     {
        imageDeFond = SDL_LoadBMP("caserouge.bmp");
     }


     positionFond.x = j*taille_image ;
     positionFond.y = i*taille_image ;
     FSOUND_Init(44100, 32, 0);         /* Initialisation de FMOD */
     pion = FSOUND_Sample_Load(FSOUND_FREE, "212.mp3", 0, 0, 0);  //met du son pour chaqure pion joué //
     FSOUND_PlaySound(FSOUND_FREE,pion);
     SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

     SDL_Flip(ecran);
     SDL_FreeSurface(imageDeFond);

     return tour ;


}

unsigned char balayage_lignes(unsigned short carte[][colone])
{

    unsigned short rouge,jaune ;
    signed char lign,col,a ;
    unsigned char continuer= 1 ;


    rouge=0 ;
    jaune=0 ;
    a=0 ;



    for(lign=0;lign<=5;lign++)
    {
         rouge=0;
         jaune=0 ;

         for(col=0;col<6;a++)   //reste dans la boucle tant que col <6 //
         {




             if((carte[lign][col]!= casejaune) && (carte[lign][col]!= caserouge) ) // si il y a une case vide entre deux pleines alors on remet tout a zero//
               {

                   rouge=0 ;
                   jaune=0 ;
                   col++ ;

               }

             while((carte[lign][col]== caserouge )&&(rouge!=4)&&(col<=6)&&(jaune!=4))//incremente rouge tant qu'il y a une case rouge//
                {
                     jaune = 0;
                     rouge++ ;
                     col++ ;

                }



             while((carte[lign][col]==casejaune )&&(jaune!=4)&&(rouge!=4) && (col<=6))//increment jaune tant qu'il y a une case jaune//
                 {
                    rouge = 0;
                    jaune ++ ;
                    col++ ;

                 }




            if((rouge==4) || (jaune==4))     //si il y a 4 rouge ou jaune on affiche une image et on renvoie continue=0 mais avant on remonte au 1er for mais quelque soit la suite continuer
                                                       // =0 donc on revoit a la fin de la boucle la femeture du programme//
            {
              continuer = 0 ;                //renvoie zero pour eteindre le prog//
              col=6 ;                      //on sort directement de la foncion sinon bug //

            }




        }



   }


return continuer ;

}



unsigned char balayage_colones(unsigned short carte[][colone])
{

    unsigned short rouge,jaune ;
    signed char lign,col,a ;
    unsigned char continuer= 1 ;


    rouge=0 ;
    jaune=0 ;
    a=0 ;



    for(col=0;col<=6;col++)
    {
         rouge=0;
         jaune=0 ;

         for(lign=0;lign<5;a++)   //reste dans la boucle tant que lign <=5 //
         {



             if(carte[lign][col]!= casejaune && carte[lign][col]!= caserouge ) // si il y a une case vide entre deux pleines alors on remet tout a zero//
               {

                   rouge=0 ;
                   jaune=0 ;
                   lign++ ;

               }
             while((carte[lign][col]== caserouge )&&(rouge!=4)&&(lign<=5)&&(jaune!=4))     //incremente rouge tant qu'il y a une case rouge//
                {
                      jaune = 0;
                      rouge++ ;
                      lign++ ;

                }



             while((carte[lign][col]==casejaune )&&(jaune!=4)&&(rouge!=4) && (lign<=5))   //increment jaune tant qu'il y a une case jaune//
                 {
                    rouge = 0;
                    jaune ++ ;
                    lign++ ;

                 }




             if((rouge==4) || (jaune==4))            //si il y a 4 rouge ou jaune on affiche une image et on renvoie continue=0 mais avant on remonte au 1er for mais quelque soit la suite continuer
                                                    // =0 donc on revoit a la fin de la boucle la femeture du programme//
              {
                  continuer = 0 ;                   //renvoie zero pour eteindre le prog//
                  lign=5 ;                         //arret directement la fonction sinon bug//

              }




        }



   }


return continuer ;

}


unsigned char balayage_diagonale_haut(unsigned short carte[][colone])
{

    unsigned short rouge,jaune ;
    signed char lign,col,a,b,c ;
    unsigned char continuer= 1 ;

    rouge=0 ;
    jaune=0 ;
    c=0 ;

for(b=0;b<=2;b++)
{
    for(a=0;a<=3;a++)                                               //jusqu'a trois car après il n'est plus possible de faire 4 en diagonal //
    {
       c++ ;
       if(c<=4)
       {
         col=a ;
         lign= 0 ;
       }
       else
       {
            col=0 ;
            lign=b ;
       }

      while((col<=6)&& (continuer!=0))                                     //si on a atteint 4 ce n'est plus la peine de parcourir la grille//
      {


          while((carte[lign][col]!= casejaune) &&(carte[lign][col]!= caserouge)&& (col<=6)&&(rouge!=4) && (jaune!=4)) // si il y a une case vide entre deux pleines alors on remet tout a zero//
               {

                   rouge=0 ;
                   jaune=0 ;
                   lign++ ;
                   col++ ;

               }

          while((carte[lign][col]==caserouge) && (col<=6)&&(rouge!=4)&&(jaune!=4) )

              {
                   jaune = 0 ;
                   rouge ++ ;
                   col++ ;
                   lign++ ;


              }



          while((carte[lign][col]==casejaune) && (col<=6)&& (jaune!=4)&&(rouge!=4))
              {

                 rouge=0 ;
                 jaune ++ ;
                 col++ ;
                 lign++ ;

              }


          if((rouge==4) || (jaune==4))              //si il y a 4 rouge ou jaune on affiche une image et on renvoie continue=0 mais avant on remonte au 1er for mais quelque soit la suite continuer
                                                   // =0 donc on revoit a la fin de la boucle la femeture du programme//
            {
               continuer=0 ;                          //renvoie zero pour eteindre le prog//


            }

       }}
    }


return continuer ;

}



unsigned char balayage_diagonale_haut_bis(unsigned short carte[][colone])
{

    unsigned short rouge,jaune ;
    signed char lign,col,a,c,b ;
    unsigned char continuer= 1 ;

    rouge=0 ;
    jaune=0 ;
    c=0 ;

 for(b=0;b<=3;b++)
 {

    for(a=6;a>=3;a--)//jusqu'a trois car après il n'est plus possible de faire 4 en diagonal //
    {

       c++;
       if(c<=4)
       {
          col= a ;
          lign= 0 ;
       }
       else
       {
           col=6 ;
           lign=b ;
       }

          while((col>=0)&& (continuer!=0))//si on a atteint 4 ce n'est plus la peine de parcourir la grille//
            {


                 while((carte[lign][col]!= casejaune) &&(carte[lign][col]!= caserouge)&& (col>=0)&&(rouge!=4) && (jaune!=4)) // si il y a une case vide entre deux pleines alors on remet tout a zero//
                    {
                         rouge=0 ;
                         jaune=0 ;
                         lign++ ;
                         col-- ;

                    }

                while((carte[lign][col]==caserouge) && (col>=0)&&(rouge!=4)&&(jaune!=4) )

                    {
                         jaune = 0 ;
                         rouge ++ ;
                         col--;
                         lign++ ;


                    }



                while((carte[lign][col]==casejaune) && (col>=0)&& (jaune!=4)&&(rouge!=4))
                  {
                        rouge=0 ;
                        jaune ++ ;
                        col-- ;
                         lign++ ;

                  }


               if((rouge==4) || (jaune==4))                               //si il y a 4 rouge ou jaune on affiche une image et on renvoie continue=0 mais avant on remonte au 1er for mais quelque soit la suite continuer
                                                                         // =0 donc on revoit a la fin de la boucle la femeture du programme//
                 {
                     continuer=0 ;                                       //renvoie zero pour eteindre le prog//

                 }

       }    }
}


return continuer ;

}



void affichage_gagnant(SDL_Surface *ecran,SDL_Surface *petite_fenetre,unsigned char compteur,unsigned char tour,FSOUND_SAMPLE *pion)
{



    petite_fenetre = SDL_SetVideoMode(493,613, 32, SDL_HWSURFACE | SDL_DOUBLEBUF); // nouvelle fenetre pour afficher l'image du gagnant //
    SDL_WM_SetCaption(" GAGNE !!!", NULL);

    if(tour==1)
    {
      petite_fenetre = SDL_LoadBMP("gagnantjaune.bmp") ;  // image selon gagnant //
    }

      if(tour==0)
    {
      petite_fenetre = SDL_LoadBMP("gagnantrouge.bmp") ;
    }



    if(compteur==42)
    {
         petite_fenetre = SDL_SetVideoMode(496,639, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);  //si la grille est plein et donc aucun joueur n'a gagné //
         petite_fenetre = SDL_LoadBMP("matchnul.bmp") ;
         SDL_WM_SetCaption(" MATCH NUL !!!", NULL);
         pion = FSOUND_Sample_Load(FSOUND_FREE, "3979.mp3", 0, 0, 0);
         FSOUND_PlaySound(FSOUND_FREE,pion);  // son pour match nu //

    }

    if(compteur!=42)
    {
       pion = FSOUND_Sample_Load(FSOUND_FREE, "3659.mp3", 0, 0, 0);
       FSOUND_PlaySound(FSOUND_FREE,pion);    // son pour un gagnant //

    }


       SDL_BlitSurface(petite_fenetre, NULL,ecran,0);
       SDL_Flip(ecran);
       SDL_Flip(petite_fenetre);
       SDL_FreeSurface(petite_fenetre);




}


unsigned char menu(unsigned short carte[][colone],SDL_Surface *imageDeFond,SDL_Surface *ecran,unsigned char page_acceuil,SDL_Event event,SDL_Rect positionFond) // menu page d'accueil //
{
     unsigned char i,j,lign,col,a ;
    /* unsigned short tab[13][9] ;
      lign = 13 ;
      col = 9;*/


      SDL_Init(SDL_INIT_VIDEO);
      SDL_WM_SetIcon(SDL_LoadBMP("icone.bmp"), NULL);                                                 //met une icone pour la fenetre //
      ecran = SDL_SetVideoMode(487,630, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);                          //caractéristique de la fenetre principale //
      SDL_WM_SetCaption("puissance 4 !!!", NULL);                                                   // met un titre a la fenetre //
      imageDeFond = SDL_LoadBMP("acceuil1.bmp") ;
      SDL_BlitSurface(imageDeFond, NULL, ecran,NULL);
      SDL_Flip(ecran);
      SDL_FreeSurface(imageDeFond);


     /* for(i=0;i<lign;i++)
    {

        for(j=0;j<col;j++)
        {
            positionFond.x = j*54;
            positionFond.y = i*49;


            imageDeFond = SDL_LoadBMP("bidon.bmp");

            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
            SDL_Flip(ecran);

        }

    }*/

       while (page_acceuil)                                                                           //continuite du prog //
        {

           SDL_WaitEvent(&event);                                                                   //bibliothèque d'evennement //
           switch(event.type)
           {
               case SDL_QUIT:
               page_acceuil = 0;
               a= 2 ;                                                                    //si on clique sur la croix le prog s'arrete //
               break;


              case SDL_MOUSEBUTTONDOWN:                                                         //Clic de la souris //

               if (event.button.button == SDL_BUTTON_LEFT)                                       //si clic gauche //

                {

                        i= event.button.y / 49; //position du click de la souris dans le tableau//
                        j= event.button.x / 54 ; //on recupère la ligne et la colone //


                        if(((10==i)&&(j==3))||((10==i)&&(j==4))||((10==i)&&(j==5))||((11==i)&&(j==3))||((11==i)&&(j==4))||((11==i)&&(j==5)))
                        {

                            /*imageDeFond = SDL_LoadBMP("icone.bmp") ;
                            SDL_BlitSurface(imageDeFond, NULL, ecran,&positionFond);
                            SDL_Flip(ecran);
                            SDL_FreeSurface(imageDeFond);*/
                            page_acceuil= 0 ;
                            a=0 ;

                        }




                }

        }


        }

      if(a==0)
      {
        return 1 ;
      }
      else
      {
          return 0 ;
      }

}


void reinitialisation_des_scores(unsigned char tour,unsigned char scorerouge,unsigned char scorejaune,SDL_Surface *imageDeFond,SDL_Surface *ecran,SDL_Rect positionFond) // reset des scores //
{


                                 imageDeFond = SDL_LoadBMP("score0.bmp");// réaffiche 0 pour jaune//


                                 positionFond.x = 7*taille_image;
                                 positionFond.y = 1*taille_image;
                                 SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                                 SDL_Flip(ecran);
                                 SDL_Delay(1000) ;




                                 imageDeFond = SDL_LoadBMP("score0rouge.bmp"); // réaffiche 0 pour rouge //


                                 positionFond.x = 7*taille_image;
                                 positionFond.y = 3*taille_image;
                                 SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                                 SDL_Flip(ecran);
                                 SDL_Delay(1000) ;











}
