#include <iostream>
#include "grille.hpp"
using namespace std;

void initialiseGrilleVide(Grille &g){
    for (int j=0; j<Y; j++){
        for (int i=0; i<X; i++){
            g.tab[i][j].brindille = 0;
            g.tab[i][j].idT = -1;
        }
    }
}   

bool estVide(Grille g, Coord c){
    return (!g.tab[getX(c)][getY(c)].brindille) and (g.tab[getX(c)][getY(c)].idT == -1);
}

bool dansGrille(Grille g, Coord c){
    return (getX(c) < X) and (getY(c) < Y) and (getX(c) >= 0) and (getY(c) >= 0);
}

bool contientBrindille(Grille g, Coord c){
    return g.tab[getX(c)][getY(c)].brindille;
}

short numeroTermite(Grille g, Coord c){
    return g.tab[getX(c)][getY(c)].idT;
}

void poseBrindille(Grille &g, Coord c){
    if (estVide(g, c))
        g.tab[getX(c)][getY(c)].brindille = 1;
}

void enleveBrindille(Grille &g, Coord c){
    if (g.tab[getX(c)][getY(c)].brindille==1)
        g.tab[getX(c)][getY(c)].brindille = 0;
}

void poseTermite(Grille &g, Coord c, short idT){
    if (estVide(g, c))
        g.tab[getX(c)][getY(c)].idT = idT;
}

void enleveTermite(Grille &g, Coord c){
    g.tab[getX(c)][getY(c)].idT = -1;
}
        