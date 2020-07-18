#include <iostream>

using namespace std;

bool convert(string time){
	short num;
	if(time.size()==1)
		num = int(time[0])-30;
	else if(time[0]==1)
		num = 10 + int(time[1])-30;
	else num = 20 + int(time[1])-30;

	return num;
}

bool separator(short &sec, short &min, short &hour, string time){
	string cutTime;
	for(int i = 0; i < time.size(); i++){
		for(int j = i; j < time.size(); j++){
			


int main(){
	short sec, min, hour;
	cout<<"Hello, please enter in format hh:mm:ss\nFor example: 2h3m5s\n Your turn: "
	string time; getline(cin, time);
	
