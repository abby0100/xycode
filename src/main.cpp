#include <iostream>
#include <string>
#include <vector>

#include "xyutils/array.hpp"
#include "xyutils/logger.hpp"

using namespace std;

const string PROJECT_TAG = " **** **** xycode **** **** ";

int test_2_1_1() {

	vector<int> array;
	int read = XYReader::read_array("src/data/sorted-array.txt", array);

	cout << "orig array:" << endl;
	for (int i = 0; i < array.size(); ++i) {
		cout << array[i] << " ";
	}
	cout << endl << endl;

	int ret = XYArray::remove_array_duplicates(array);	
}

int main(int argc, char** argv) {

	cout << endl << PROJECT_TAG << endl;
	cout << "log level\t" << get_log_level() << endl;

	test_2_1_1();
	return 0;
}
