#include <iostream>
#include <string>
#include "coord.hpp"
using namespace std;

void testEgalCoord(){
    ASSERT( egalCoord(creeCoord(5, 6), creeCoord(5, 6)));
    ASSERT(!egalCoord(creeCoord(3, 5), creeCoord(4, 5)));
    ASSERT(!egalCoord(creeCoord(1, 19), creeCoord(19, 1)));
}

void testEgalDirection(){
    ASSERT(aGauche(aDroite(O))== O);
    ASSERT(aGauche(aDroite(NO))== NO);
    ASSERT(aGauche(aDroite(S))== S);
    ASSERT(aGauche(aGauche(aGauche(aGauche(aGauche(aGauche(aGauche(aGauche(N))))))))==N);
    ASSERT(aDroite(aDroite(aDroite(aDroite(aDroite(aDroite(aDroite(aDroite(SE))))))))==SE);
}

void testDevantCoord(){
    ASSERT(egalCoord(devantCoord(creeCoord(2,1), N), creeCoord(2,0)));
    ASSERT(egalCoord(devantCoord(creeCoord(5,5), NE), creeCoord(6,4)));
    ASSERT(egalCoord(devantCoord(creeCoord(100,100), SO), creeCoord(99,101)));
    ASSERT(egalCoord(devantCoord(creeCoord(0,0), S), creeCoord(0,1)));
    ASSERT(egalCoord(creeCoord(7,11),devantCoord(devantCoord(creeCoord(7,11),NE),aDroite(aDroite(aDroite(aDroite(NE))))))); // On vérifie qu'en partant d’une coordonnée dans n’importe quelle direction, si l’on avance, puis tourne 4 fois à droite, puis avance encore, on revient à la coordonnée de départ.
}
           

int main(){   
    
    testEgalCoord();    
    testEgalDirection();
    testDevantCoord();
        
    return 0;
} 