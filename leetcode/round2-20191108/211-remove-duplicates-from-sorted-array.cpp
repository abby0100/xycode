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
	int removeDuplicates(vector<int>& nums) {
		if(nums.empty())
			return 0;

		int idx = 0;
		for(int curr = 1; curr < nums.size(); ++curr) {
			if(nums[idx] != nums[curr]) {
				nums[++idx] = nums[curr];
			}
		}
		return idx+1;
	}
};

int main(int argc, char **argv) {

	vector<int> nums {1, 1, 2, 4, 5, 5, 8};
	printVector(nums, nums.size());

	Solution s;
	int result = s.removeDuplicates(nums);

	cout << "[-] Result:\t" << result << endl;
	printVector(nums, result);

	return 0;
}
