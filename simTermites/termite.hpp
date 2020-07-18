#ifndef termite_hpp
#define termite_hpp
#include "grille.hpp"


/** Renvoie la direction du termite
 * @param[in] Termite t: le termite
 * @return Direction: la direction du type abstrait Termite
**/
Direction directionTermite(Termite t);

/** Renvoie les coordonnees de la case d'en face du termite
 * @param[in] Termite t: le termite
 * @return Coord 
 **/
Coord devantTermite(Termite t);

/** Vérifie si un termite port une brindille
 * @param[in]  Termite t
 * @return True si il porte une brindille, False sinon
 **/
bool porteBrindille(Termite t);

/** Tourne le termite a gauche 
 * @param[in/out] Termite t
 **/
void tourneAGauche(Termite &t);

/** Tourne le termite a droite
 * @param[in/out] Termite T
 **/
void tourneADroite(Termite &t);

/** Tourne le termite a gauche ou a droite
 * @param[in/out] Termite
 **/
void tourneAleat(Termite &t);

/** Verifie s'il n'y a ni de brindille ni de termite en face
 * @param[in] Grille
 * @param[in] Termite
 * @return vrai si la voie est libre, faux sinon
 **/
bool laVoieEstLibre(Grille g, Termite t);

/** Verifie s'il y a une brindille devant
 * @param[in] Grille
 * @param[in] Termite: celui qui avance
 * @return vrai s'il y en a une, faux sinon :
 **/
bool brindilleEnFace(Grille g, Termite t);

/** Verifie que le termite ne soit pas enferme s'il pose sa brindille dans la case donnee
 * @param[in] Grille
 * @param[in] Termite: les coordonnees da la case d'en face
 * @return vrai si le termite ne s'enferme pas, faux sinon
 **/
bool pasEnferme(Grille g, Termite t);

 /** Fait avancer le termite si possible, sinon le fait tourner
 * @param[in/out] Grille 
 * @param[in/out] Termite
 **/
void avanceTermite(Grille &g, Termite &t);

/** Un ensemble de conditons a verifier pour que le termite commence a chercher une place libre a cote d'une brindille
 * @param[in] Grille 
 * @param[in] Termite
 * @return vrai si les conditions sont respectees faux sinon
 **/
bool pretADecharger(Grille g, Termite t);

/** Fait le termite deposer la brindille devant lui
 * @param[in/out] Grille
 * @param[in/out] Termite
 **/
void dechargeTermite(Grille &g, Termite &t);

/** Fait le termite prendre la brindille d'en face
 * @param[in/out] Grille
 * @param[in/out] Termite
 **/
void chargeTermite(Grille &g, Termite &t);

 /** Des conditions a verifier pour deposer la brindille apres avoir trouve une place 
 * @param[in] Grille 
 * @param[in] Termite
 * @return vrai si les conditions sont respectees 
 **/
bool dechargePossible(Grille g, Termite t);

/** Des conditions a verifier pour prendre une brindille 
 * @param[in] Grille 
 * @param[in] Termite
 * @return vrai si les conditions sont respectees 
 **/
bool chargePossible(Grille g, Termite t);

/** Fait avancer le termite avec une probabilite de 90% et tourne aleatoirement avec celle de 10%
 * @param[in/out] Grille 
 * @param[in/out] Termite
 **/
void marcheAleatoire(Grille &g, Termite &t);

/** Initialise le tableau de termites: idT=-1
 * @param[out] Termite tab[]: tableau de termites
 **/
void initialiseTabIdVide(Termite (&tab)[tailleTabIdT]);

/** Cree un termite avec les donnees d'initialisation choisies
 * @param[in]  Coord c1: les coordonnees de la case ou le termite se trouve
 * @param[out] Termite tab[]: le tableau des termites
 * @param[in]  short: le numero (id) du termite 
 **/
void creeTermite(Coord c1, Termite (&tab)[tailleTabIdT], short id);

/** Affiche une case
 * @param[in]  Grille g : la grille
 * @param[in] Termite tab[]: le tableau des termites
 * @param[in]  int : l'abscisse
 * @param[in]  int : l'ordonnée
 **/
void afficheCase(Grille g, Termite (tab)[tailleTabIdT], int i, int j);

/** Affiche une grille 
 * @param[in]  Grille g : la grille
 * @param[in] Termite tab[] : le tableau des termites
 **/
void afficheGrille(Grille g, Termite (tab)[tailleTabIdT]); 


#endif