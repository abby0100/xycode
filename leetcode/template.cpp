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
		sort(nums.begin(), nums.end());
		printVector(nums);
		return ret;
	}
};

int main(int argc, char **argv) {

	int target = 0;
	vector<int> test;
	test.push_back(1);
	test.push_back(0);
	test.push_back(-1);
	test.push_back(0);
	test.push_back(-2);
	test.push_back(2);
	printVector(test);

	Solution *s = new Solution();

	//vector<string> result;
	vector<vector<int>> result = s->xy4sum(test, target);
	for(int i = 0; i < result.size(); ++i) {
		printVector(result[i]);
		//cout << "[+] result:\t" << result << endl;
	}
	return 0;
}
