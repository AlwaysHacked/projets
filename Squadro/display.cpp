#include "display.hpp"

void display(int i){
	cout << setw(2) << i;
}
void display(char i){
	cout << setw(2) << i;
}
void space(int k){
	for(int i = 0; i < k; i++)
		display(' ');
}

void showOneTwoHor(short spcNb){
	space(spcNb);
	cout << RED;
	
	for(int i = 1; i <= 5; i++)
		display(i);
	cout << RESET << '\n';
}

/*///////////////////////////////////////////////////////
/* shows line numbers and corresponding step number /////
/*///////////////////////////////////////////////////////
void showOneTwoVer(short lineNum, short step){
	display(lineNum);
	
	if (step == 1)
		display(step1[step]);
	else
		display(step2[step]);
	}
}	


void showStep(int i, short spcNb){
	cout << BLUE;
	space(spcNb);

	if(i == 1)
		for(int i : step1)
			cout <<  setw(2) << i;
	else
		for(int i : step2)
			cout << setw(2) <<  i;
			
	cout << '\n';
}

void pawnColor(int j, int i){
	if(tab[j][i] == '>' or tab[j][i] == '<')
		cout << GREEN;
	
	else if (tab[j][i] == 'v' or tab[j][i] == '^')
		cout << YELLOW;
}			

void showTab(){
	for(int j = 0; j < 7; j++){					//j line
		for(int i = 0; i < 7; i++){				//i column
			pawnColor(j, i);
			display(tab[j][i]);
			cout << RESET;
		}
	cout << '\n';
	}
}

void show(){
	short spcNb = 1;			//set to 1 by default
	if(includes('>'))			//if includes '>' than more spaces
		spcNb = 3;
	
	showStep(1, spcNb);
	showOneTwoHor(spcNb);
	
	showTab();
	
	showOneTwoHor(spcNb);
	showStep(2, spcNb);
}
