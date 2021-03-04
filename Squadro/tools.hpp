#ifndef tools_hpp
#define tools_hpp

/*         foreground background
black        30         40
red          31         41
green        32         42
yellow       33         43
blue         34         44
magenta      35         45
cyan         36         46
white        37         47

reset             0  (everything back to normal)
bold/bright       1  (often a brighter shade of the same colour)
underline         4
inverse           7  (swap foreground and background colours)
bold/bright off  21
underline off    24
inverse off      27

Ex: bold blue	\033[1;34m	
	reset		\033[0;0m*/

#include <iostream>
#include <fstream>
#include <iomanip>	//setw
#include <string>

#define BLUE	"\033[1;34m"
#define LB		"\033[0;34m"
#define RESET	"\033[0;0m"
#define GREEN	"\033[1;32m"
#define YELLOW	"\033[1;33m"
#define RED		"\033[1;31m"
#define UNDRLN	"\033[4;0m"

#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ \
                     << " line " << __LINE__ << ": " #test << endl


using namespace std;

extern string pl1, pl2;
extern char tab[7][7];
static int step1[] = {1,3,2,3,1}, step2[] = {3,1,2,1,3};
//~ static char onetwothree[] = {'1','2','3','4','5'};

bool includes(char);

void askNames(); 

#endif
