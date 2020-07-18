#include "pg3pg4.hpp"

/*////////////////////////////////////////////////                                          
/* pg3Change								//////
/*////////////////////////////////////////////////       


void pg3Change(){
	//~ cout<<
	cout<<"Which account's password do you want to change?\n";
			
	showSites();
	short num = getNum(1, short(sites.size()));
	if(num == 0)	return;
	passes[num-1] = enterPass();
}
/*////////////////////////////////////////////////                                          
/* pg4Del									//////
/*////////////////////////////////////////////////       

void del(short num){
	sites.erase(sites.begin()+num);
	passes.erase(passes.begin()+num);
}

void pg4Del(){
	cout<<"Which site's password do you want to delete?\n";
	
	showSites();
	short num = getNum(1, short(sites.size()));
	if(num == 0)	return;
	del(num-1);	fill();
	cout<<"\nDone! Redirecting you to menu.\n";
	sleep(2);
}

