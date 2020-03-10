#include <iostream>
#include <vector>

using namespace std;

//template<typename T>
template<class T>
void printVector(vector<T> vec, size_t len) {
	for(int idx = 0; idx < len; ++idx) {
		cout << vec[idx] << " ";
	}
	cout << endl;
}

class Solution {
public:
	int removeDuplicates(vector<int>& nums, int arrow) {
		if(nums.size() <= arrow)
			return nums.size();

		int idx = 0;
		int count = 1;
		for(int curr = 1; curr < nums.size(); ++curr) {
			if(nums[idx] != nums[curr]) {
				//idx += (count < 2) ? count : 2;
				idx += (count < arrow) ? count : arrow;
				nums[idx] = nums[curr];
				count = 1;
			} else {
				++count;
			}
		}
		return idx+1;
	}
};

int main(int argc, char **argv) {

	vector<int> nums {1, 1, 1, 1, 2, 4, 5, 5, 8, 8, 8, 9};
	printVector(nums, nums.size());

	int arrow = 3;
	Solution s;
	int result = s.removeDuplicates(nums, arrow);

	cout << "[-] Result:\t" << result << endl;
	printVector(nums, result);

	return 0;
}
