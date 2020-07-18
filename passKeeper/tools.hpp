#ifndef tools_hpp
#define tools_hpp

#include <iostream>
#include <unistd.h>	//getpass(), sleep()
#include <fstream>
#include <vector>
#include <limits>
#include <string>

#define BLUE	"\033[1;34m"
#define LBLUE	"\033[0;34m"
#define RESET	"\033[1;0m"
#define RED		"\033[1;31m"
#define UNDRLN	"\033[4;0m"

#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ \
                     << " line " << __LINE__ << ": " #test << endl

#define SEC	"#!/bin/bash\n chmod 600 .p\nsudo chown root:root .p\n"	//in `main.cpp`

using namespace std;

extern string key;
extern vector<string> passes, sites;

void page(short);

short getNum(short, short);

void get();

void showSites();

void fill();

string encrypt(string &,  string &);

string decrypt(short, string, string &);

void showPass(short);

string enterPass();

void add();

fstream& GotoLine(fstream&, short);

#endif
