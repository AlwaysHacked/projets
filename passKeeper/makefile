CXX = g++
CXXFLAGS = -std=c++11 -g


projet: main.cpp tools.o pg1pg2.o pg3pg4.o


tools.o: tools.cpp tools.hpp
pg1pg2.o: pg1pg2.cpp pg1pg2.hpp tools.hpp
pg3pg4.o: pg3pg4.cpp pg3pg4.hpp tools.hpp


clean:
	rm -f .projet *.o
