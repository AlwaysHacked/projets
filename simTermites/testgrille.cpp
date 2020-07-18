#include <iostream>
#include "grille.hpp"
using namespace std;

void testGrille1(){    // marche sous la condition que X et Y soient toujours >1
    Grille g;
    initialiseGrilleVide(g);
        
    for (int j=0; j<Y; j++){
        for (int i=0; i<X; i++){       
            ASSERT (estVide(g, creeCoord(i, j)));
        }
    }
    ASSERT (!(dansGrille(g, creeCoord(X, Y-1))));
    ASSERT (!(dansGrille(g, creeCoord(X-1, Y)))); 
    ASSERT (!(dansGrille(g, creeCoord(-1, Y-1))));
    ASSERT (!(dansGrille(g, creeCoord(X-1, -1))));
    ASSERT (dansGrille(g, creeCoord(0, 0)));
    ASSERT (dansGrille(g, creeCoord(1, 1)));
    ASSERT (dansGrille(g, creeCoord(0, Y-2)));
    ASSERT (dansGrille(g, creeCoord(X-1, Y-1)));
}

void testGrille2(){    // marche sous la condition que X et Y soient toujours >1
    Grille g;
    initialiseGrilleVide(g);
       
    poseBrindille(g, creeCoord(X-1, Y-1));
    poseTermite(g, creeCoord(0, 0), 5);
    
    ASSERT (!(estVide(g, creeCoord(0, 0))));
    ASSERT (!(estVide(g, creeCoord(X-1, Y-1))));
    ASSERT (numeroTermite(g, creeCoord(X-1, Y-1))==-1);
    ASSERT (numeroTermite(g, creeCoord(0, 0))==5);
    ASSERT (!(contientBrindille(g, creeCoord(0, 0))));
    ASSERT (contientBrindille(g, creeCoord(X-1, Y-1)));
    
    enleveBrindille(g, creeCoord(X-1, Y-1)); 
    enleveTermite(g, creeCoord(0, 0));
    
    for (int j=0; j<Y; j++){
        for (int i=0; i<X; i++){       
            ASSERT (estVide(g, creeCoord(i, j)));
        }
    }
    ASSERT (numeroTermite(g, creeCoord(0, 0))==-1);
    ASSERT (!(contientBrindille(g, creeCoord(X-1, Y-1))));   
    
    poseBrindille(g, creeCoord(0, 1));
    poseTermite(g, creeCoord(0, 1), 0);
    poseTermite(g, creeCoord(1, 0), 0);
    poseBrindille(g, creeCoord(1, 0));
   
    ASSERT (numeroTermite(g, creeCoord(0, 1))==-1);
    ASSERT (contientBrindille(g, creeCoord(0, 1)));
    ASSERT (!(contientBrindille(g, creeCoord(1, 0))));
    ASSERT (numeroTermite(g, creeCoord(1, 0))==0);
    
    enleveBrindille(g, creeCoord(0, 1)); 
    enleveTermite(g, creeCoord(1, 0));
    
    ASSERT (estVide(g, creeCoord(0, 1)));
    ASSERT (estVide(g, creeCoord(1, 0)));
}


int main(){   
    testGrille1();
    testGrille2();
    
    return 0;
}
