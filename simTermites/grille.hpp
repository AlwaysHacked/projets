#ifndef grille_hpp
#define grille_hpp
#include "coord.hpp"



// Constructeur :

/** Initialise une grille vide: brandille=0, idTermite=-1
 * @param[out] Griile g: la grille a 'vider' 
 **/
void initialiseGrilleVide(Grille &g);



// Accès à une case de la grille : 

/** Verifie si la case donnee est vide  
 * @param[in] Grille g: la grille
 * @param[in] Coord c: les coordonnees a verifier
 * @return vrai si la case estVide, faux sinon
 **/
bool estVide(Grille g, Coord c);

 /** Verifie si les coordonnees donnes sont dans la grille  
 * @param[in] Grille g: la grille
 * @param[in] Coord c: les coordonnees a verifier
 * @return vrai si les coordonnees sont dans la grille, faux sinon
 **/
bool dansGrille(Grille g, Coord c);

/** Verifie si la case donnee contient une brindille 
 * @param[in] Grille g: la grille
 * @param[in] Coord c: les coordonnees a verifier
 * @return vrai s'il y a une brindille, faux sinon
 **/
bool contientBrindille(Grille g, Coord c);

/** Renvoie le numero du termite sur la case donnee 
 * @param[in] Grille g: la grille
 * @param[in] Coord c: la case a verifier
 * @return short : le numero du termite(idT), -1 s'il n'y en a pas
 **/
short numeroTermite(Grille g, Coord c);



// Modiﬁcations d’une case de la grille : 

/** Pose une brindille sur la case donne si celle-ci estVide
 * @param[in/out] Grille g: la grille
 * @param[in] Coord c: la case ou l'on met une brindille
 **/
void poseBrindille(Grille &g, Coord c);

/** Enleve la brindille d'une case si elle en contient une
 * @param[in/out] Grille g: la grille
 * @param[in]     Coord c: la case a modifier (ou pas)
 **/
void enleveBrindille(Grille &g, Coord c);

/*Pose une termite dans la case donnee si celle-ci estVide
 * @param[in/out] Grille g: la grille
 * @param[in]     Coord c: la case a verifier
 * @param[in]     short idT: le numero du termite a poser
 **/
void poseTermite(Grille &g, Coord c, short);

/** Enleve le termite de la case donnee
 * @param[in/out] Grille g: la grille
 * @param[in]     Coord c: la case a modifier (ou pas)
 **/
void enleveTermite(Grille &g, Coord c);



#endif