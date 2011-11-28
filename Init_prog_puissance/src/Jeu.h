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
 */

typedef struct
{
	Terrain ter;    /**Données  du  terrain*/
	Puissance pui;  /**Données  du  jeu puissance */
} Jeu;

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

/**
 * @fn const Puissance *jeuGetConstPuissancePtr(const Jeu *);
 * @brief retourn   l'adresse   du  pointeur de type Puissance pJeu->ter
 *
 * @param[in, out] Pointeur de la  structure   Jeu.
 * @return adresse  du  pointeur
 */
const Puissance *jeuGetConstPuissancePtr(const Jeu *);

/* ************************************************************************ */
/*           Procédure gestion de la souris                                 */
/* ************************************************************************ */


/**
 * @fn void jeuActionSouris(Jeu *j, const char);
 * @brief Gestion de l'utilisation de la souris
 *
 * @param[in, out] Pointeur de la  structure   Jeu.
 * @param[in] Entier pour sauvegarder l'action de la souris.
 * @return 0 si tout est OK
 */
void jeuActionSouris(Jeu *j, const char);


#endif