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

	int partition(vector<int>& nums, int start, int end) {
		int pivot = nums[start];
		while(start < end) {
			while(start < end && pivot <= nums[end])	--end;
			swap(nums[start], nums[end]);

			while(start < end && pivot >= nums[start])	++start;
			swap(nums[start], nums[end]);
		}
		return start;
	}

	void getLeastKSort(vector<int>& nums, vector<int>& result, int k) {
		if(nums.empty() || k <= 0)	return;
		int start = 0;
		int end = nums.size() - 1;
		int idx = partition(nums, start, end);

		while(idx != k - 1) {
			if(idx < k - 1)
				start = idx + 1;
			else
				end = idx - 1;
			idx = partition(nums, start, end);
		}

		for(int i = 0; i < k; ++i) {
			result.push_back(nums[i]);
		}
	}

	void adjustDown(vector<int>& nums, int s, int n) {
		nums[0] = nums[s];
		for(int i = 2 * s; i <= n; i *= 2) {
			if(i < n; && nums[i] < nums[i+1]) {
				i++;
			}
			if(a[0] > a[i])	break;
			else {
				a[s] = a[i];
				s = i;
			}
		}
		a[s] = a[0];
	}

	void buildMaxHeap(vector<int>& nums, int k) {
		for(int i = k/2; i > 1; --i) {
			swap(nums[1], nums[i]);
			adjustDown(nums, 1, i - 1);
		}
	}

	void getLeastKHeap(vector<int>& nums, vector<int>& result, int k) {
		buildMaxHeap(nums, k);
	}

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

	//vector<int> nums {1, 1, 2, 4, 5, 5, 8};
	vector<int> nums {5, 1, 6, 4, 9, 5, 8};
	printVector(nums, nums.size());

	Solution s;
	//int result = s.removeDuplicates(nums);
	int k = 5;
	vector<int> result;
	s.getLeastKSort(nums, result, k);
	s.getLeastKHeap(nums, result, k);

	//cout << "[-] Result:\t" << result << endl;
	printVector(result, result.size());

	return 0;
}
