CXX = g++
CXXFLAGS = -Wall -std=c++11 -g


projet: projet.cpp coord.o grille.o termite.o 

testcoord: testcoord.cpp coord.o
testgrille: testgrille.cpp grille.o coord.o
testtermite: testtermite.cpp grille.o coord.o termite.o


coord.o: coord.cpp coord.hpp donnee.hpp
grille.o: grille.cpp grille.hpp coord.hpp
termite.o: termite.cpp termite.hpp grille.hpp coord.hpp


clean:
	rm -f testcoord testgrille testtermite projet *.o
