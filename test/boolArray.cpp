#include <iostream>

using namespace std;

enum b{live=1, die};

int const num = 100000;

void func(int c, b array[num]){
	if (c == num)	return ;
	else	cout << array[c] << ' '; func(c+1, array);
}

int main(){
	//short c=1000000;
	b array[num];
	func(0, array);
	return 0;
}
