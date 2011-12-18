#ifndef _PUISSANCE_H
#define _PUISSANCE_H

#include "Terrain.h"


/**
 * @fn struct Puissance
 * @brief Gestion des coordonnées x et y
 *
 * Les coordonnées x et y sont utilisées dans
  la gestion de positionnement des pions
 *
 */
typedef struct{
	int x,y;
} Puissance;

/**
 * @fn void puiInit(Puissance *);
 * @brief initialisation x et y à 0
 *
 * @param[in, out] Pointeur de type Puissance
 */
void puiInit(Puissance *);
void puiGauche(Puissance *, const Terrain *);
void puiDroite(Puissance *, const Terrain *);
void puiHaut(Puissance *, const Terrain *);
void puiBas(Puissance *, const Terrain *);

/**
 * @fn int puiGetX(const Puissance *);
 * @brief Renvoi la valeur de x
 *
 * @param[in, out] Pointeur de type Puissance en mode donnée
 * @return la valeur de x
 */
int puiGetX(const Puissance *);
/**
 * @fn int puiGetX(const Puissance *);
 * @brief Renvoi la valeur de y
 *
 * @param[in, out] Pointeur de type Puissance en mode donnée
 * @return la valeur de y
 */
int puiGetY(const Puissance *);
/**
 * @fn int pionJauneValide(Terrain *, Cases cases, int i, int j);
 * @brief traitement de places libres pour les pions jaunes
 *
 * @param[in, out] Pointeur Terrain, coordonnées du pointeur de la sourie
 * @return 1 si tout est OK
 */
int pionJauneValide(Terrain *, Cases cases, int i, int j);

/**
 * @fn int pionRougeValide(Terrain *, Cases cases, int i, int j);
 * @brief traitement de places libres pour les pions rouges
 *
 * @param[in, out] Pointeur Terrain, coordonnées du pointeur de la sourie
 * @return 1 si tout est OK
 */
int pionRougeValide(Terrain *, Cases cases, int i, int j);

#endif
