/**
 * https://www.cnblogs.com/kaituo/p/5021673.html
 *
**/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "xyutils/array.hpp"

using namespace std;


int XYReader::read_array(string path, vector<int>& array) {

	if (path.empty()) {
		return -1;
	}
	cout << "read array from file\t" << path << endl;

	int i = 0;
	ifstream fin;
	fin.open(path.c_str(), ios::in);
	if (! fin.is_open()) {
		cout << "open file '" << path.data() << "' failed" << endl;
		return -1;
	}

	//string elements;
	//while (getline(fin, elements)) {
	//	cout << "Get elements from file\t" << elements << endl;
	//}

	int element;
	while (fin >> element) {
		//cout << "Get element from file\t" << element << endl;
		array.push_back(element);
	}

	fin.close();
	return 0;
}
