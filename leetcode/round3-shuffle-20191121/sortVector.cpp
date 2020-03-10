#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//template<typename T>
template<class T>
void printVector(vector<T> vec, size_t len) {
	if(vec.empty() || vec.size() < len)
		return;
	for(int idx = 0; idx < len; ++idx) {
		cout << vec[idx] << " ";
	}
	cout << endl;
}

struct HeapStruct {
	int* element;
	int size;
	int capacity;
};

class Solution {
public:

};

int main(int argc, char **argv) {

	vector<int> nums {5, 1, 6, 4, 9, 2, 7, 3, 8};
	printVector(nums, nums.size());

	sort(nums.begin(), nums.end());
	printVector(nums, nums.size());

	reverse(nums.begin(), nums.end());
	printVector(nums, nums.size());

	Solution s;

	//cout << "[-] Result:\t" << result << endl;

	return 0;
}
