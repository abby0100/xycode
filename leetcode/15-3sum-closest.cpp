#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
void printVector(vector<T> vec) {
	cout << "[-] printVector" << endl;
	for(int i = 0; i < vec.size(); ++i) {
		cout << vec[i] << " ";
	}
	cout << endl;
}

class Solution {
public:
	int xy3retClosest(vector<int>& nums, int target) {
		//int ret = ~(1 << 31);
		int ret = ~(1 << 31) - target;
		cout << "xy3retClosest INT_MAX:\t" << ret << endl;

		sort(nums.begin(), nums.end());

		for(int i = 0; i < nums.size() - 2; ++i) {
			cout << "i:\t" << i << endl;

			if(i != 0 && nums[i] == nums[i-1])	continue;

			int k = i + 1;
			int j = nums.size() - 1;
			while(k < j) {
				cout << "k:\t" << k << endl;
				cout << "j:\t" << j << endl;
				int sum = nums[i] + nums[k] + nums[j];
				cout << "sum:\t" << sum << endl;
				if(sum == target)	return sum;
				if(abs(ret - target) < abs(sum - target))	ret = sum;
				if(sum < target)
					++k;
				else
					--j;
			}
		}
		return ret;
	}
};

int main(int argc, char **argv) {

	int target = 82;
	vector<int> test;
	// [4,0,5,-5,3,3,0,-4,-5]
	// [1,2,4,8,16,32,64,128]
	test.push_back(1);
	test.push_back(2);
	test.push_back(4);
	test.push_back(8);
	test.push_back(16);
	test.push_back(32);
	test.push_back(64);
	test.push_back(128);
	printVector(test);

	Solution *s = new Solution();

	int result = s->xy3retClosest(test, target);
	cout << "[+] result:\t" << result << endl;

	return 0;
}
