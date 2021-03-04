#ifndef coord_hpp
#define coord_hpp
#include "donnee.hpp"



/** Cree un type abstrait Coord a partir des valeurs transmises
 * @param[in] int lig: ligne 
 * @param[in] int col: colonne
 * @return Coord : les coordonnees crees
 **/
Coord creeCoord(int, int);

/** Affiche les coordonnees que comporte le type abstrait Coord
 * @param[in] Coord c: coordonnees
 **/
void afficheCoord(Coord c);

/** Renvoie l'abscisse
 * @param[in] Coord c: coordonnees
 * @return l'abscisse c.x
 **/
int getX(Coord c);

/** Renvoie l'ordonnee
 * @param[in] Coord c: coordonnees
 * @return l'ordonne c.y
 **/
int getY(Coord c);

/** Verifie si 2 coordonnees sont egaux
 * @param[in] : Coord c1: coordonnees
 * @param[in] : Coord c2: coordonnees
 * @return vrai si vrai, faux sinon
**/
bool egalCoord(Coord c1, Coord c2);

/** Affiche la direction
 * @param[in] Direction dir: direction 
 **/
void afficheDirection(Direction dir);

/** Renvoie la direction modifiee
 * @param[in] Direction d: direction a changer
 * @return Direction : direction changee
 **/
Direction aGauche(Direction dir);

/** Renvoie la direction modifiee
 * @param[in] Direction d: direction a changer
 * @return Direction : direction changee
 **/
Direction aDroite(Direction dir);

/** Renvoie les coordonnees d'en face, dans un type Coord
 * @param[in] Coord c: les coordonnees
 * @param[in] Direction d: la direction de l'objet
 * @return les coordonnees d'en face
 **/
Coord devantCoord(Coord c, Direction d);

/** Renvoie des caracteres correspondant a la direction du termite  
 * @param[in] Direction d: Direction du termite
 * @return un character, char
 **/
char afficheDirectionT(Direction);


#endif
