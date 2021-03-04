#include <iostream>

using namespace std;

enum b{live=1, die};

int const num = 100000;

void func(int c, bool array[num]){
	for(int i = c; i < num; i++)
		cout << array[i] << ' ';
}

int main(){
	bool array[num];
	func(0, array);
	cout << '\n';
	return 0;
}
