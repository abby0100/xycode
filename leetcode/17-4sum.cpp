#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
void printVector(vector<T> vec) {
	//cout << "[-] printVector" << endl;
	for(int i = 0; i < vec.size(); ++i) {
		cout << vec[i] << " ";
	}
	cout << endl;
}

class Solution {
public:
	vector<vector<int>> xy4sum(vector<int>& nums, int target) {
		vector<vector<int>> ret;
		if(nums.empty() || nums.size() < 4)
			return ret;
		sort(nums.begin(), nums.end());
		printVector(nums);

		for(int i = 0; i < nums.size() - 3; ) {
			for(int j = nums.size() - 1; j >= i + 3; ) {
				int m = i + 1;
				int n = j - 1;
				int temp = nums[i] + nums[j];
				while(m < n) {
					cout << "i=" << i << ", m=" << m << ", n=" << n << ", j=" << j << endl;
					if(temp + nums[m] + nums[n] == target) {
						vector<int> root;
						root.push_back(nums[i]);
						root.push_back(nums[m]);
						root.push_back(nums[n]);
						root.push_back(nums[j]);
						printVector(root);
						ret.push_back(root);
						//break;
						m++;
						while(m < n && (nums[m] == nums[m-1])) {
							m++;
						}
						n--;
						while(m < n && (nums[n] == nums[n+1])) {
							n--;
						}
					} else if(temp + nums[m] + nums[n] < target) {
						m++;
						while(m < n && (nums[m] == nums[m-1])) {
							m++;
						}
					} else if(temp + nums[m] + nums[n] > target) {
						n--;
						while(m < n && (nums[n] == nums[n+1])) {
							n--;
						}
					}
				}
				j--;
				while((i < j) && (nums[j] == nums[j+1])) {
					j--;
				}
			}
			i++;
			while((i < nums.size() - 3) && (nums[i] == nums[i-1])) {
				i++;
			}
		}
		return ret;
	}
};

int main(int argc, char **argv) {

	int target = 0;
	vector<int> test;
	//5,5,3,5,1,-5,1,-2
	test.push_back(0);
	test.push_back(0);
	test.push_back(0);
	test.push_back(0);
	//printVector(test);

	Solution *s = new Solution();

	//vector<string> result;
	vector<vector<int>> result = s->xy4sum(test, target);
	for(int i = 0; i < result.size(); ++i) {
		cout << "[+] result:\t" << endl;
		printVector(result[i]);
	}
	return 0;
}
