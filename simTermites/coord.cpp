#include <iostream>
#include "coord.hpp"
using namespace std;


Coord creeCoord(int lig, int col){
    Coord c;
    c.x = lig;
    c.y = col;
    return c;
}
void afficheCoord(Coord c){
    cout << "(" << c.x << "," << c.y << ")" << endl;
}
int getX(Coord c){
    return c.x;
}
int getY(Coord c){
    return c.y;
}
bool egalCoord(Coord c1, Coord c2) {
    return (c1.x==c2.x and c1.y==c2.y);
}
void afficheDirection(Direction d){
    if (d==0) cout << "nord-ouest" << endl;
    if (d==1) cout << "nord" << endl;
    if (d==2) cout << "nord-est" << endl;
    if (d==3) cout << "est" << endl;
    if (d==4) cout << "sud-est" << endl;
    if (d==5) cout << "sud" << endl;
    if (d==6) cout << "sud-ouest" << endl;
    if (d==7) cout << "ouest" << endl;
}
Direction aGauche(Direction d){
    if (d>=1 and d<=7){
        return Direction(d-1);
    }
    if (d==0) {
        return Direction(7);
    }else{
        cout << "ERROR : Direction doit être entre 0 et 7" << endl;
    }  
    return d;
}
Direction aDroite(Direction d){
    if (d>=0 and d<=6){
        return Direction(d+1);
    }
    if (d==7) {
        return Direction(0);
    }else{
        cout << "ERROR : Direction doit être entre 0 et 7" << endl;
    }
    return d;
}
Coord devantCoord(Coord c, Direction d){
    switch(d){
        case N : c.y--; break;
        case S : c.y++; break;
        case E : c.x++; break;
        case O : c.x--; break;
        case SE: c.x++; c.y++; break;
        case NO: c.x--; c.y--; break;
        case NE: c.x++; c.y--; break;
        case SO: c.x--; c.y++; break;
    }
    return c;
}
              
char afficheDirectionT(Direction d){
    switch(d){
        case nordOuest : 
        case sudEst :    return '\\'; break;
        case nord :      
        case sud :       return '|';  break;
        case nordEst :   
        case sudOuest :  return '/';  break; 
        case est :       
        case ouest :     return '-';  break;
    }          
    return '?';     //pour savoir directement qu'il y a un problème.
}