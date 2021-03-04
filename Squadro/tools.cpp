#include "tools.hpp"

bool includes(char k){
	for(int i = 0; i < 7; i++)
		for(char j : tab[i])
			if(j == k)
				return 1;
	return 0;
}

void askNames(){
	cout << "Hello!\nPlayer 1 write your name: "; cin>>pl1;
	cout << "Player 2 write your name: "; cin>>pl2;
}
