#include <iostream>
#include "termite.hpp"
using namespace std;


void initialiseRand(Grille &g, Termite (&tab)[tailleTabIdT], short &nbTermite, short &nbBrindille){
    initialiseGrilleVide(g);
    initialiseTabIdVide(tab);
    nbTermite = 0;
    nbBrindille = 0;
    for (int j=0; j < Y; j++){
        for (int i=0; i < X; i++){

            short ranNum = rand()%100 + 1;
            Coord c = creeCoord(i, j);

            if(ranNum <= proba_b){
                poseBrindille(g, c);
                nbBrindille++;    // Pour compter le nombre de brindilles.
            } else if (ranNum > 100-proba_t){
                creeTermite(c, tab, nbTermite);
                poseTermite(g, c, nbTermite);
                nbTermite++;     // Pour compter le nombre de termites.
            }
        }
    }
}

void passe(Grille &g, Termite (&tab)[tailleTabIdT], short nbTermite){

    for (int i = 0; i < nbTermite; i++){
        tab[i].sablier--;

        if (chargePossible(g, tab[i])){
            chargeTermite(g, tab[i]);

        } else if (pretADecharger(g, tab[i])){
            tourneADroite(tab[i]);
            tab[i].tourneSurPlace = 1;

        } else if (dechargePossible(g, tab[i])){
            dechargeTermite(g, tab[i]);
            tab[i].tourneSurPlace = 0;

        } else if (tab[i].tourneSurPlace){
            tourneAleat(tab[i]);

        } else {
            marcheAleatoire(g, tab[i]);
        }
    }
}


int main(){

    unsigned long iter = 1; unsigned short m = 1;    // iteration, multiplicateur
    srand (time(NULL));
    char c;
    short nbTermite = 0;
    short nbBrindille = 0;

    Grille g; Termite tabIdT[tailleTabIdT];
    initialiseRand(g, tabIdT, nbTermite, nbBrindille);
    cout << message << endl;
    c = getchar();
    system("clear");

    while(1){
        cout << "Nombre d'iterations : " << iter << endl;
        cout << "Vitesse : " << m << endl;
        cout << "nbTermite " << GREEN << "/" << WHITE << " : " << nbTermite << endl;
        cout << "nbBrindille "<< YELLOW << "*" << WHITE << " : " << nbBrindille << endl;

        for(int k=0; k != m; k++){
            passe(g, tabIdT, nbTermite);
        }
        afficheGrille(g, tabIdT);
        cout << instruc << endl;

        c = getchar();

        if(c == '*'){
            m *= 2;
            if(m == 0) m = 1;
        }
        else if(c == '/'){
            m /= 2;
            if(m == 0) m = 1;
        }
        else if(c == '.'){
            break;
        }
        iter += m;
        system("clear");
    }
    cout << "Vous avez mis fin a la simulation." << endl;
    return 0;
}
