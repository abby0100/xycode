#include <iostream>
#include <vector>

using namespace std;

//template<typename T>
template<class T>
void printVector(vector<T> vec, int len) {
	if(len <= 0) return;

	for(int idx = 0; idx < len; ++idx) {
		cout << vec[idx] << " ";
	}
	cout << endl;
}

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int start = 0;
		int mid = 0;
		int end = nums.size() - 1;
		while(start <= end) {
			mid = (start + end) / 2;
			cout << "nums[" << start << "]\t" << nums[start] << endl;
			cout << "nums[" << mid << "]\t" << nums[mid] << endl;
			cout << "nums[" << end << "]\t" << nums[end] << endl;
			if(target == nums[mid])
				return mid;
			else if(nums[start] < nums[mid])
				if(nums[start] <= target && target < nums[mid])
					end = mid - 1;
				else
					start = mid + 1;
			else if(nums[start] == nums[mid])
				++start;
			else
				if(nums[mid] < target && target <= nums[end])
					start = mid + 1;
				else
					end = mid - 1;
		}
		return -1;
	}

	int removeDuplicates(vector<int>& nums, int repeat) {
		if(nums.size() <= repeat)
			return nums.size();

		int idx = 0;
		int count = 1;
		for(int curr = 1; curr < nums.size(); ++curr) {
			if(nums[idx] != nums[curr]) {
				idx += (count < repeat) ? count : repeat;
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

	//vector<int> nums {1,3,1,1,1};
	vector<int> nums {1,1,1,3,1};
	printVector(nums, nums.size());

	int repeat = 3;
	int target = 7;
	cout << "Please input the target [number] " << endl;
	cin >> target;
	cout << "[-] target:\t" << target << endl;

	Solution s;
	//int result = s.removeDuplicates(nums, repeat);
	int result = s.search(nums, target);
	cout << "[-] Result:\t" << result << endl;

	printVector(nums, result);

	return 0;
}
