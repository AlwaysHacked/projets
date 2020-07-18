//~ void greetings(string name){
	//~ if(name == "")
		//~ name = "User";
	//~ cout 	<< "Welcome "<< name <<" ,\n"
			//~ << "Glad to see you here!\n"
			//~ << "

#include "tools.hpp"
#include "pg1pg2.hpp"
#include "pg3pg4.hpp"

bool on = true;

string key;
vector<string> passes = {}, sites = {};


void choice(short n = 0){
	if(n == 0)
		n = getNum(1,7);

	page(n);
	
	switch(n){
		case 1: pg1Add();	break;
		case 2:	pg2Show();	break;
		case 3:	pg3Change();break;
		case 4:	pg4Del();	break;
		//~ case 5:	pg5Gen();	break;
		//~ case 6:	pg7
		case 7: on = 0;		break;
	}
}


void menu(){
	vector<string> menu = {	"======== Menu ========\t|",
							"1.Add a password\t|",
							"2.Show a password\t|",
							"3.Change a password\t|",
							"4.Delete a password\t|",
							"5.Password Generator\t|",
							"6.Instructions\t\t|",
							"7.Exit\t\t\t|"				};

	unsigned short maxSize = max(passes.size(), menu.size());
	for(int i(0); i < maxSize; i++){
		if(menu.size() > i)		cout << menu[i];	
		if(sites.size() <= i)	cout << endl;
		
		if(menu.size() <= i)	cout << "\t\t\t|";
		if(sites.size() > i)	cout << LBLUE << sites[i] << RESET << '\n';
	}
}


int main(){
	system("clear");
	key = "bro";
	key = getpass("Enter your key to acces the menu");
	system("clear");	

	
	get();

	while(on){
		system("clear");
		menu();
		choice();
		
	}
	cout << "\nBye! Don't forget the " << BLUE << "key" << RESET << "!!\n";
	return 0;
}
