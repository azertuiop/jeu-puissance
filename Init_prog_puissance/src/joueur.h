#ifndef _JOUEUR_H
#define _JOUEUR_H

#include <stdio.h>


//enum typeJoueur {J=0 , R=1}; /*type de jeoueur J=Jaune , R=Rouge*/
/*
typedef struct
{
	int x,y;
    enum typeJoueur tpj;
} Puissance;
*/

typedef struct{
	int scoreJoueurJ;
	int scoreJoueurR;
	char joueurgagnant;
} Joueur;


void joueurInit(Joueur *);
void joueurLibere(Joueur *);
const int getScoreJoueurJ(const Joueur *);
const int getScoreJoueurR(const Joueur *);
void setScoreJoueurR(Joueur *, const int );
void setScoreJoueurR(Joueur *, const int );
const char getjoueurgagnant(const Joueur *);
void setjoueurgagnant(Joueur *, const char );

#endif
