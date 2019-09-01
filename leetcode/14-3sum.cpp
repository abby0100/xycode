#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(vector<int> vec) {
	cout << "[-] printVector" << endl;
	for(int i = 0; i < vec.size(); ++i) {
		cout << vec[i] << " ";
	}
	cout << endl;
}

class Solution {
public:
	vector<vector<int>> xy3sum(vector<int>& nums) {
		vector<vector<int>> ret;
		if(nums.empty() || nums.size() == 0) {
			return ret;
		}
		sort(nums.begin(), nums.end());
		//printVector(nums);

		int i = 0;
		int j = nums.size() - 1;
		while(i <= j - 2) {
			int k = i + 1;
			int val = nums[i] + nums[j];
			while(k < j) {
				if(nums[k] + val < 0) {
					k++;
				} else if(nums[k] + val == 0) {
					vector<int> vec;
					vec.push_back(nums[i]);
					vec.push_back(nums[k]);
					vec.push_back(nums[j]);
					ret.push_back(vec);
					i++;
					break;
				} else {
					j--;
					break;
				}
			}
		}
		return ret;
	}
};

int main(int argc, char **argv) {

	vector<int> test;
	test.push_back(-1);
	test.push_back(0);
	test.push_back(1);
	test.push_back(-1);
	test.push_back(2);
	test.push_back(4);
	test.push_back(8);
	printVector(test);

	Solution *s = new Solution();

	vector<vector<int>> result = s->xy3sum(test);
	//cout << "[+] result:\t" << result << endl;
	for(int i = 0; i < result.size(); ++i) {
		printVector(result[i]);
	}

	return 0;
}
