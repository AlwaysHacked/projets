#include <iostream>
#include "termite.hpp"
using namespace std;


Direction directionTermite(Termite t){
    return t.d;
}

Coord devantTermite(Termite t){
    return devantCoord(t.c, t.d);
}

bool porteBrindille(Termite t){
    return t.brin;
}

void tourneADroite(Termite &t){
    t.d = aDroite(t.d);
}

void tourneAGauche(Termite &t){
    t.d = aGauche(t.d);
}

void tourneAleat(Termite &t){
    short n = rand()%2;
    if (n==0){
        tourneAGauche(t);
    } else {
        tourneADroite(t);
    }
}

bool laVoieEstLibre(Grille g, Termite t){
    return (dansGrille(g, devantTermite(t))) and (estVide(g, devantTermite(t)));
}

bool brindilleEnFace(Grille g, Termite t){
    return (dansGrille(g, devantTermite(t))) and (contientBrindille(g, devantTermite(t)));
}

bool pasEnferme(Grille g, Termite t){
    int vide = 0;
    for(short i = 0; i < 8; i++){
        if (dansGrille(g, devantCoord(t.c, Direction(i))) and estVide(g, devantCoord(t.c, Direction(i)))){ 
            vide++;                                                                                      //compte le nombre de cases vides
        }
    }
    return vide >= 2;
}

void avanceTermite(Grille &g, Termite &t){
    if (laVoieEstLibre(g, t)){
        enleveTermite(g, t.c);
        t.c = devantTermite(t);
        poseTermite(g, t.c, t.idT);
    }
}

bool pretADecharger(Grille g, Termite t){
    return (brindilleEnFace(g, t)) and (t.sablier <= 0) and (t.brin);     
    // Lorsque le termite trouve devant lui une brindille, et alors, il va tourner sur place pour déposer sa brindille.
}

bool dechargePossible(Grille g, Termite t){
    return (laVoieEstLibre(g, t) and (t.sablier <= 0) and (t.brin) and (t.tourneSurPlace) and (pasEnferme(g, t)));
    // Lorsque le termite peut déposer sa brindille sur la grille.
}

bool chargePossible(Grille g, Termite t){
    return (brindilleEnFace(g, t)) and (t.sablier <= 0) and (!t.brin);
}

void dechargeTermite(Grille &g, Termite &t){
    poseBrindille(g, devantTermite(t));
    t.brin = 0;
    t.sablier = tempsVide;
}

void chargeTermite(Grille &g, Termite &t){
    t.brin = 1;
    enleveBrindille(g, devantTermite(t));
    t.sablier = tempsVide;
}

void marcheAleatoire(Grille &g, Termite &t){
    int proba = rand()%10;
    if (laVoieEstLibre(g, t) and proba < 8){
        avanceTermite(g, t);
    } else if (laVoieEstLibre(g, t) and proba >= 8){
        tourneAleat(t);
        avanceTermite(g, t);
    } else {    
        tourneAleat(t);
    }
}

void initialiseTabIdVide(Termite (&tab)[tailleTabIdT]){
     for(int i=0; i<tailleTabIdT; i++)            // initialise les id des termites a 0 
        tab[i].idT=-1;
}

void afficheTermite(Termite tab[tailleTabIdT], short nT){
    for(int i=0; i< tailleTabIdT; i++){
        if(tab[i].idT==nT){
            cout<<"id : "<<tab[i].idT<<endl;
            cout<<"coord : ";afficheCoord(tab[i].c);
            cout<<"sablier : "<<tab[i].sablier<<endl;  
            cout<<"brin : "<<tab[i].brin<<endl;
            cout<<"direction : ";afficheDirection(tab[i].d);cout<<endl;
            cout<<"tourneSurPlace : "<<tab[i].tourneSurPlace<<endl;
            return;
        }
    }
}

void creeTermite(Coord c1, Termite (&tab)[tailleTabIdT], short id){
    for(int i=0; i<tailleTabIdT; i++){
        if(tab[i].idT==-1){ 
            tab[i].idT=id;
            tab[i].c=c1;
            tab[i].sablier=6;  
            tab[i].brin=0;
            tab[i].d=Direction(rand()%7);
            tab[i].tourneSurPlace=0;
            return;
        }
    }
}      
   
void afficheCase(Grille g, Termite (tab)[tailleTabIdT], int i, int j){
    Case c = g.tab[i][j];                       
    if (estVide(g, creeCoord(i, j))){
        cout << " ";
    }
    else if (c.brindille == 1){
        cout << YELLOW << "*" << WHITE;
    } else {
        if (tab[c.idT].brin){
            cout << RED << afficheDirectionT(tab[c.idT].d) << WHITE;
        } else {
            cout << GREEN <<afficheDirectionT(tab[c.idT].d) << WHITE;
        }      
    }                 
}

void afficheGrille(Grille g, Termite (tab)[tailleTabIdT]){ 

    cout << "@";                        
    for(int i=0; i < X; i++){      
        cout << WHITE << "--" ;       // L'affichage des bords
    }
    cout << "@" << endl;
    for (int j=0; j<Y; j++){
        cout << "|";
        for (int i=0; i<X; i++){
        
            afficheCase(g, tab, i, j);
            cout << " ";
        }
        cout << "|" << endl;
    }
    cout << "@";
    for(int i=0; i < X; i++){
        cout << WHITE << "--" ;      // L'affichage des bords
    }
    cout << "@" << endl;
}
