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

int XYArray::sort(vector<int>& array, int start, int end) {

	binary_sort(array, start, end);

	cout << endl << " ---> sort result" << endl;
	for (int i = 0; i < array.size(); ++i) {
		cout << array[i] << " ";
	}
	cout << endl << endl;
	return 0;
}

int XYArray::binary_search(vector<int>& array, int start, int end, int target) {

	if (start > end) {
		return -1;
	} else if (start == end) {
		return target == array[end] ? end : -1;
	} else {
		//cout << endl << "binary search target\t" << target << endl;

		int mid = (start + end) / 2;
		//cout << endl << "binary search mid value\t" << array[mid] << endl;

		if (array[mid] == target) {
			cout << "binary search target at\t" << mid << endl;
			return mid;
		} else if (array[mid] < target) {
			return binary_search(array, mid + 1, end, target);
		} else {
			return binary_search(array, start, mid - 1, target);
		}
	}

	return -1;
}

int XYArray::remove_array_duplicates(vector<int>& array) {

	int size = array.size();
	if(size <= 0) {
		return -1;
	}
	int target = array[size / 2];

	sort(array, 0, size - 1);

/**
 * remove duplicated elements
 */
	// allow a element occurs 2 times
	int tolerance = 2;

	int current = array[0];
	int times = 0;
	//cout << "remove_array_duplicates current\t" << current << endl << endl;
	
	for (int i = 0; i < array.size(); ++i) {
		//cout << "current\t" << array[i] << endl;

		if (current == array[i]) {
			times++;

			if (times > tolerance) {
				// occurs $tolerance times
				array.erase(array.begin() + i);
				i--;
			}
		} else {
			// the first time this element occurs
			times = 1;
			current = array[i];
		}
	}
	
	cout << endl << " ---> remove_array_duplicates result" << endl;
	for (int i = 0; i < array.size(); ++i) {
		cout << array[i] << " ";
	}
	cout << endl << endl;

	binary_search(array, 0, array.size() - 1, target);


	return 0;
}
