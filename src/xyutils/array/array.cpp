#include <iostream>
#include <vector>
#include <string>

using namespace std;

int mylog(string info) {

	cout << endl << "[+] " << info << endl;
}

void print_array(vector<int> array) {

	int N = array.size();
	cout << "\t";
	for (int i = 0; i < N; ++i) {
		cout << array[i] << "\t";
	}
	cout << endl;
}

void print_arrow(vector<int> array, int idx1, int idx2, int idx3) {

	print_array(array);

	int N = array.size();
	cout << "\t";
	for (int i = 0; i < N; ++i) {
		if(i == idx1 || i == idx2 || i == idx3) {
			cout << "^" << "\t";
		} else {
			cout << " " << "\t";
		}
	}
	cout << endl;
}

int binary_sort(vector<int>& array, int start, int end) {

	//mylog("binary sort array");

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
	//print_array(array);
        
        binary_sort(array, start, j - 1);
        binary_sort(array, j, end);

        return 0;
}

int sort_array(vector<int>& array, int start, int end) {

	mylog("sort array");
	print_arrow(array, start, end, -1);

        binary_sort(array, start, end);

	print_array(array);
	return 0;
}

int reverse_array(vector<int>& array, int start, int end) {

	//mylog( "reverse array, start: " + to_string(start) + "; end: " + to_string(end) + ".");

	int i = start, j = end;
	int temp;
	for(; i < j; ++i, --j) {
		//cout << "i: " << i << "; j: " << j << endl;
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}

	//print_array(array);
	return 0;
}

int rotate_array(vector<int>& array, int start, int end, int pivot) {

	mylog("rotate array");
	print_arrow(array, start, end, pivot);

	reverse_array(array, start, pivot);
	reverse_array(array, pivot + 1, end);
	reverse_array(array, start, end);

	print_array(array);
	return 0;
}

int search_array(vector<int> array, int start, int end, int target) {

	mylog("search array");
	print_arrow(array, start, end, -1);
	cout << " ---> target: "  << target <<  endl;

	int mid;

	while(start < end) {
		mid = (start + end) / 2;
		print_arrow(array, start, end, mid);

		if(array[mid] == target) {
			cout << " ---> find target at array: " << mid << "[" << array[mid] << "]" << endl;
			return 0;
		}

		if(array[start] <= array[mid]) {
			if(array[start] <= target && target < array[mid]) {
				end = mid;
			} else {
				start = mid + 1;
			}
		}
		if(array[mid] <= array[end]) {
			if(array[mid] < target && target <= array[end]) {
				start = mid + 1;
			} else {
				end = mid;
			}
		}
	}

	cout << " ---> not find target at array" << endl;
	return -1;
}

int main(int argc, char** argv) {

	mylog("main");

	//vector<int> array;
	//array.push_back(-2);
	vector<int> array = {1, -3, 8, -2, 4, -8, 34, -45, 9, -2, -54, 8, 43, 93};

	//cout << "Orig array" << endl;
	//print_array(array);

	sort_array(array, 0, array.size() - 1);

	int pivot = 4;
	rotate_array(array, 0, array.size() - 1, pivot);

	int target = -4;
	search_array(array, 0, array.size() - 1, target);


}
