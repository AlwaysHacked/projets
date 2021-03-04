# Le compilateur à utiliser
CXX = g++ 
# Les options du compilateur 
CXXFLAGS = -Wall -std=c++11 -g


# Les programmes principaux 
########################### 
main: main.cpp tools.o display.o

tools.o: tools.cpp tools.hpp
display.o: display.cpp display.hpp
 
# Pour faire le ménage
clear:
	rm -f main projet *.o 
