#include "tools.hpp"

void page(short n){
	system("clear");
	cout << BLUE << "\tMenu/";
	switch (n) {
		case 1:	cout << "Add a password";		break;
		case 2:	cout << "Show a password";		break;
		case 3:	cout << "Change a password";	break;
		case 4:	cout << "Delete a password";	break;
		case 5:	cout << "Password generator";	break;
		case 6:	cout << "Instructions";			break;
		//~ case 7:	cout << "";	break;
	}
	cout << RESET << "\n\n";
	cout << "Type" << RED <<" 0" << RESET <<" to go back to Menu\n\n";
}


short getNum(short f, short s){ 	//first second
	short num, c = 0;
	if(f == s){
		sleep(1);
		return f;
	}
	cout<<"Please write a number between "<< f <<" and "<< s <<" :";
	while(c==0){
			if (cin>>num)
				if((num >= f and num <= s) or num == 0)
					c++;
	 
				else{
					cout<< RED <<"\nERROR "<< RESET <<" The number is incorrect\n";
					cout<<"Please write a number between "<< f <<"  and "<< s <<": ";
				}
			else{
				cout<< RED <<"\nERROR "<< RESET <<"Enter a" << UNDRLN <<" number "<< RESET <<"please: ";
				cin.clear();
				cin.ignore(100, '\n');
			}
		}
	return num;
}


void get(){	
	string word;
	int c = 0, i = 0;
	ifstream pass(".p");
	while(getline(pass,word)){
		i++;							//====type====
		if(c == 0)						//site's name
			sites.push_back(word);		//password
		else if(c == 1){				//============
			passes.push_back(word);
			c = -1;
		}
		c++;
	}
	pass.close();
	///////////////////////
	if(i==0){
		ASSERT(sites.size() == 0);
		ASSERT(passes.size() == 0);
	}
	else if(i > 0){
		ASSERT(sites.size() != 0);
		ASSERT(passes.size() != 0);
	}
	///////////////////////
}


void showSites(){
	for (int i(0); i < sites.size(); i++)
		cout << BLUE << sites[i] << RESET <<" ("<< i+1 <<")" << "\n";
}


void fill(){	//A MODIFIER write after the text and not replace it
	ofstream pass(".p");
	for(int i=0; i < sites.size(); i++)
		pass << sites[i] <<"\n"<< passes[i]<<"\n";
	pass.close();
	system(SEC);	//**sudo** cat only
}


string encrypt(string &pass, string &enc){
	int size = pass.size();
	for(int i = 0, j = 0; i < size; i++, j++){		//encrypting
                if(j == key.size()-1)				//j = key's size, if j points to the last digit, restart the key
                        j=0;
                enc += pass[0] ^ (int(key[j])+1) % 20;
        	pass.erase(pass.begin()+0);				//destroying the password
	}
	return enc;
}


string decrypt(short k,/* string key*/ string &dec){
	for(int i = 0, j = 0; i < passes[k].size(); i++,j++){	//decrypting
                if(j == key.size()-1)
                        j=0;
                dec += passes[k][i] ^ (int(key[j])+1) % 20;
        }

	return dec;
}


void showPass(short siteNum){
	string dec;
		
	cout << "I will show your password for "<< BLUE << sites[siteNum] << RESET <<" for 3 seconds..."<<endl;
	sleep(1);

	cout << decrypt(siteNum	/*, key*/, dec) << endl;sleep(3);
	system("clear");
	cout << "That's it!\n";

}


string enterPass(){
	string enc, pass, pass1;
	do{
		pass = getpass("Enter your password: ");
		pass1 = getpass("Repeat the password: "); 
		
		if(pass1 != pass){
			system("clear");
			cout << "Passwords do not match, try again please.\n";
		}
	}while(pass != pass1);
	pass1 = "";									//don't leave any traces... (`pass` +is erased in `encrypt`)
	return encrypt(pass, enc);
}


void add(){
	string site;
	cout << "Enter the site's name: "; cin>>site;//getline
	sites.push_back(site);
	
	
	passes.push_back(enterPass());
	fill();
}


fstream& GotoLine(fstream& file, short num){
    file.seekg(ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    return file;
}


