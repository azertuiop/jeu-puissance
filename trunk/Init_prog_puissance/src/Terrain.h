#ifndef _TERRAIN_H
#define _TERRAIN_H

/**
 * @struct Cases
 * @brief Structure utilisée pour la gestion des dimensions de remplissage du terrain avec des cases.
 *
 * cette structure est utilisée dans la définition de l'espace du jeu
 qui contient les cases
 */
typedef struct{
    int xmin; /**Données de X min*/
    int xmax; /**Données de X max*/
    int ymin; /**Données de Y min*/
    int ymax; /**Données de Y max*/
}Cases;


/**
 * @struct Terrain
 * @brief Structure utilisée pour la gestion du Terrain globale.
 *
 * Cette structure est utilisée dans la construction du Terrain
 du jeu avec les dimensions x et y
 */
typedef struct{
	int dimx; /**Données de dimension X*/
	int dimy; /**Données de dimension Y*/
	Cases cases;
	char **tab; /**Pointeur utilisé dans la construction du Terrain avec dimx et dimy*/
} Terrain;



/**
 * @fn void terInit(Terrain *);
 * @brief Initialise le terrain .
 *
 * @param[in, out] Pointeur pour initialiser la structure Jeu.
 * @return pas de valeur de retour
 */
void terInit(Terrain *);



/**
 * @fn void terLibere(Terrain *);
 * @brief Liberer le Terrain qui est déjà initialisé
 *
 * @param[in, out] Pointeur de type Terrain.
 * @return 0 si tout est OK
 */
void terLibere(Terrain *);
//int terEstPositionPersoValide(const Terrain *, const int x, const int y);

/**
 * @fn int terEstPositionPersoValide(const Terrain *, Cases , const int , const int );
 * @brief Teste si la position de la case choisie est libre
 *
 * @param[in, out] Pointeur de type Terrain et Cases, les coordonnées de la case selectionnée.
 * @return 1 si tout est OK
 */
int terEstPositionPersoValide(const Terrain *, const int , const int );

/**
 * @fn const char terGetXY(const Terrain *, const int x, const int y);
 * @brief Accesseur: Récuperer les données du Terrain selon les coordonnées x et y
 *
 * @param[in, out] Pointeur Terrain en mode donnée, entier x et y en mode donnée.
 * @return pTer->tab[y][x]
 */
const char terGetXY(const Terrain *, const int x, const int y);

/**
 * @fn void terSetXY(const Terrain *, const int x, const int y, const char);
 * @brief Mutateur: Modifier les données du Terrain selon les coordonnées x et y
 *
 * @param[in, out] Pointeur Terrain, entier x et y, caractère à insérer (en mode donnée)
 * @return 0 si tout est OK
 */
void terSetXY(const Terrain *, const int x, const int y, const char);

/**
 * @fn const int getDimX(const Terrain *);
 * @brief Obtenir la valeur de dimx
 *
 * @param[in, out] Pointeur Terrain en mode donnée
 * @return la valdue de dimx
 */
const int getDimX(const Terrain *);

/**
 * @fn void jeuInit (Jeu *) ;
 * @brief Obtenir la valeur de dimy
 *
 * @param[in, out] Pointeur Terrain en mode donnée
 * @return la valeur de dimy
 */
const int getDimY(const Terrain *);

#endif
