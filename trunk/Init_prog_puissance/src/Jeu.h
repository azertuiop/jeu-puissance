
#ifndef _JEU_H
#define _JEU_H

#include "Puissance.h"
#include "Terrain.h"

/**
 * @struct Jeu
 * @brief Structure utilisée pour la gestion du jeu.
 *
 * Cette structure est utilisée pour gérer le   terrain et  le  jeu.
 Les champs de cette structures doivent être modifiés ou lus
 par les accesseurs et mutateurs.
 Gestion des limites du terrain est traitée aussi
 */
typedef struct
{
	Terrain ter;    /**Données  du  terrain*/
	Puissance pui;  /**Données  du  jeu puissance */

}Jeu;

/**
 * @fn void jeuInit (Jeu *) ;
 * @brief Initialise le terrain et  le  jeu.
 *
 * @param[in, out] Pointeur pour initialiser la structure Jeu.
 * @return 0 si tout est OK
 */
void jeuInit(Jeu *);

/* ************************************************************************ */
/*           Accesseurs et Mutateurs de la structure Jeu                    */
/* ************************************************************************ */

/**
 * @fn Terrain *jeuGetTerrainPtr(Jeu *);
 * @brief retourn   l'adresse   du  pointeur de type Terrain pJeu->ter
 *
 * @param[in, out] Pointeur de la  structure   Jeu.
 * @return adresse  du  pointeur
 */
Terrain *jeuGetTerrainPtr(Jeu *);

/**
 * @fn Puissance *jeuGetPuissancePtr(Jeu *);
 * @brief retourn   l'adresse   du  pointeur de type Puissance pJeu->ter
 *
 * @param[in, out] Pointeur de la  structure   Jeu.
 * @return adresse  du  pointeur
 */
Puissance *jeuGetPuissancePtr(Jeu *);

/**
 * @fn const Terrain *jeuGetConstTerrainPtr(const Jeu *);
 * @brief retourn   l'adresse   du  pointeur de type Puissance pJeu->ter
 *
 * @param[in, out] Pointeur de la  structure   Jeu.
 * @return adresse  du  pointeur
 */
const Terrain *jeuGetConstTerrainPtr(const Jeu *);

Terrain *jeuGetModifTerrainPtr(Jeu *pJeu);

/**
 * @fn const Puissance *jeuGetConstPuissancePtr(const Jeu *);
 * @brief retourn   l'adresse   du  pointeur de type Puissance pJeu->ter
 *
 * @param[in, out] Pointeur de la  structure   Jeu.
 * @return adresse  du  pointeur
 */
const Puissance *jeuGetConstPuissancePtr(const Jeu *);

#endif
