#include <iostream>
#include <vector>

#include "xyutils/array.hpp"

using namespace std;


int XYArray::binary_sort(vector<int>& array, int start, int end) {

	int i = start;
	int j = end;
	if (i >= j) {
		return 0;
	}
	
	int pivot = array[j];

	while (i < j) {
		while (i < j && array[i] <= pivot) {
			i++;
		}
		if (i < j) {
			array[j] = array[i];
			j--;
		}

		while (i < j && array[j] >= pivot) {
			j--;
		}
		if (j > i) {
			array[i] = array[j];
			i++;
		}
	}

	array[j] = pivot;
	
	//cout << "binary sort: pivot\t" << pivot << endl;
	//for (int i = 0; i < array.size(); ++i) {
	//	cout << array[i] << " ";
	//}
	//cout << endl;

	binary_sort(array, start, j - 1);
	binary_sort(array, j, end);
	return 0;
}

int XYArray::sort(vector<int>& array) {

	int size = array.size();
	if(size <= 0) {
		return -1;
	}

	binary_sort(array, 0, size - 1);

	cout << endl << "sort result" << endl;
	for (int i = 0; i < array.size(); ++i) {
		cout << array[i] << " ";
	}
	cout << endl << endl;
	return 0;
}

int XYArray::remove_array_duplicates(vector<int>& array) {
	
	int size = array.size();
	if(size <= 0) {
		return -1;
	}

	sort(array);

	int current = array[0];
	//cout << "remove_array_duplicates current\t" << current << endl << endl;
	for (int i = 1; i < array.size(); ++i) {
		//cout << "current\t" << array[i] << endl;
		if (current == array[i]) {
			array.erase(array.begin() + i);
			i--;
		} else {
			current = array[i];
		}
	}
	
	cout << endl << "remove_array_duplicates result" << endl;
	for (int i = 0; i < array.size(); ++i) {
		cout << array[i] << " ";
	}
	cout << endl << endl;

	return 0;
}
