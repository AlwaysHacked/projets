#include <iostream>
#include "termite.hpp"
using namespace std;


// Il est possible d'afficher une grille qui répresente ce test.
// Pour le faire, il suffit d'enlever '//' des lignes qui font appel à la fonction afficheGrille(). 


void testTermite(){

    Termite tab[tailleTabIdT];
    initialiseTabIdVide(tab);
    creeTermite(creeCoord(0, 0), tab, 0);
    Grille g;                                                                  
    initialiseGrilleVide(g);
    
    poseBrindille(g, {X-1, 1});
    poseTermite(g, {0, 0}, 0);                                                              // afficheGrille(g, tab);
                                                                                         
    tab[0].d = E;                                                                           // afficheGrille(g, tab);
    ASSERT (egalCoord(devantTermite(tab[0]), creeCoord(1, 0)));                            
    for (int i=1; i<X; i++){ 
        avanceTermite(g, tab[0]);
    }                                                                                       // afficheGrille(g, tab);
                          
    ASSERT (!(dansGrille(g, devantTermite(tab[0]))));
    ASSERT (!(laVoieEstLibre(g, tab[0])));
    ASSERT (!(brindilleEnFace(g, tab[0])));
    ASSERT (!(porteBrindille(tab[0])));
                                                                                  
    tourneADroite(tab[0]); tourneADroite(tab[0]);                     
                                                                                            // afficheGrille(g, tab);
    ASSERT (dansGrille(g, devantTermite(tab[0])));
    ASSERT (!(laVoieEstLibre(g, tab[0])));
    ASSERT (brindilleEnFace(g, tab[0]));    
    ASSERT (pasEnferme(g, tab[0]));
                                                                           
    chargeTermite(g, tab[0]);
                                                                                            // afficheGrille(g, tab);      
    ASSERT (porteBrindille(tab[0]));
    ASSERT (laVoieEstLibre(g, tab[0]));
    ASSERT (!(brindilleEnFace(g, tab[0])));
    
    poseBrindille(g, {X-1, 1});
    poseBrindille(g, {X-2, 1});
    tourneADroite(tab[0]); tourneADroite(tab[0]);
                                                                                            // afficheGrille(g, tab);
    ASSERT (laVoieEstLibre(g, tab[0]));
    ASSERT (!(pasEnferme(g, tab[0])));
                                                        
    tourneAGauche(tab[0]);
    
    ASSERT (!(laVoieEstLibre(g, tab[0])));
    ASSERT (brindilleEnFace(g, tab[0]));
                                                                                            // afficheGrille(g, tab);
    enleveBrindille(g, {X-2, 1});
    creeTermite(creeCoord(X-2, 1), tab, 1);
    poseTermite(g, creeCoord(X-2, 1), 1);
    tab[1].d = tab[0].d;                                                                    // afficheGrille(g, tab);
    
    tourneAGauche(tab[0]);tourneAGauche(tab[0]);tourneAGauche(tab[0]);tourneAGauche(tab[0]);
    tourneAGauche(tab[0]);tourneAGauche(tab[0]);tourneAGauche(tab[0]);tourneAGauche(tab[0]);
    
    ASSERT (directionTermite(tab[0])==directionTermite(tab[1]));
    ASSERT (!(laVoieEstLibre(g, tab[0])));

    tourneAleat(tab[1]);                                                                    // afficheGrille(g, tab);
    ASSERT (!(directionTermite(tab[0])==directionTermite(tab[1])));
    marcheAleatoire(g, tab[1]);
    ASSERT (laVoieEstLibre(g, tab[0]));                                                     // afficheGrille(g, tab);
    tab[0].sablier = 0;
    dechargeTermite(g, tab[0]);                                                             // afficheGrille(g, tab);
    ASSERT (!(pasEnferme(g, tab[0])));
    tourneADroite(tab[0]);                                                                  // afficheGrille(g, tab); 
    marcheAleatoire(g, tab[0]);                                                             // afficheGrille(g, tab);
    ASSERT (pasEnferme(g, tab[0]));
    poseBrindille(g, creeCoord(X-3, 0));                                                    // afficheGrille(g, tab);
    ASSERT (!(pasEnferme(g, tab[0])));
                                                                                            // afficheGrille(g, tab);
    Coord c1 = devantTermite(tab[0]);
    Coord c2 = tab[0].c;
    marcheAleatoire(g, tab[0]);                                                             // afficheGrille(g, tab);
    ASSERT (!(egalCoord(c1, devantTermite(tab[0]))));
    ASSERT (egalCoord(c2, tab[0].c));    
}

int main(){
    testTermite();
    
    return 0;
}
