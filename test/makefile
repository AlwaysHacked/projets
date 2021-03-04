
# Le compilateur à utiliser
CXX = g++ 
# Les options du compilateur 
CXXFLAGS = -Wall -std=c++11 -g


# Les programmes principaux 
########################### 
projet: projet.cpp coord.o grille.o termite.o 

testcoord: testcoord.cpp coord.o
testgrille: testgrille.cpp grille.o coord.o
testtermite: testtermite.cpp grille.o coord.o termite.o


# Les différents composants 
########################### 
coord.o: coord.cpp coord.hpp donnee.hpp
grille.o: grille.cpp grille.hpp coord.hpp
termite.o: termite.cpp termite.hpp grille.hpp coord.hpp


# Pour faire le ménage
clean:
	rm -f testcoord testgrille testtermite projet *.o 
    
    
    
    
    