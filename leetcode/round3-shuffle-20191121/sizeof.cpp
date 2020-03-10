#include <iostream>

using namespace std;

int main() {

	cout << "sizeof char:\t" << sizeof(char) << endl;
	cout << "sizeof int:\t" << sizeof(int) << endl;
	cout << "sizeof char*:\t" << sizeof(char*) << endl;
	cout << "sizeof int*:\t" << sizeof(int*) << endl;

	char chars[10];
	cout << "sizeof chars[10]:\t" << sizeof(chars) << endl;
	int array[10];
	cout << "sizeof array[10]:\t" << sizeof(array) << endl;

	char* ch = new char[10];
	cout << "sizeof ch[10]:\t" << sizeof(ch) << endl;
	delete [] ch;
	int* p = new int[10];
	cout << "sizeof p[10]:\t" << sizeof(p) << endl;
	delete [] p;

	return 0;
}
