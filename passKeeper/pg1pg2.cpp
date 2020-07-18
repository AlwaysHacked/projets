#include "pg1pg2.hpp"

/*////////////////////////////////////////////////
/* pg1Add									//////
/*////////////////////////////////////////////////

void pg1Add(){
	page(1);
	add();
}

/*////////////////////////////////////////////////
/* pg2Show									//////
/*////////////////////////////////////////////////

int passNb(){
	int num = passes.size();
	if 		(num == 0){	cout << "no passwords saved.\nTime to add some!\n";	return 0;}
	else if (num == 1){	cout << "1 saved password !\n";						return 1;}
	else if (num > 1 ){	cout << num <<" saved passwords !\n";				return 1;}
	return 0;
}


void pg2Show(){
	cout<<"Currently you have ";
	
	if(passNb() == 0){
		cout<<"Redirecting you to"<<BLUE<<" Add password\n"<<RESET;
		sleep(6);
		pg1Add();
		return;
	}

	cout<<"Choose which site's password to show\n";
	showSites();
	short num = getNum(1, short(sites.size()));
	
	if(num == 0)	return;
	showPass(num-1);
}
