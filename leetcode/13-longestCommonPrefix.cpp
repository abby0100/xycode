#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printVector(vector<string> vec) {
	cout << "[-] printVector" << endl;
	for(int i = 0; i < vec.size(); ++i) {
		cout << vec[i] << " ";
	}
	cout << endl;
}

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string ret = "";
		if(strs.empty()) {
			return ret;
		}
		int size = strs.size();
		int length = strs[0].size();
		if(size == 0 || length == 0) {
			return ret;
		}
		for(int i = 0; i < strs.size(); ++i) {
			length = (strs[i].size() < length) ? strs[i].size() : length;
			cout << "length:\t" << length << endl;
		}
		int i = 0;
		int j = 0;
		while(j < length) {
			while(i < size && strs[i][j] == strs[0][j]) {
				i++;
			}
			if(i == size) {
				ret += strs[0][j];
				cout << "ret:\t" << ret << endl;
				i = 0;
				j++;
			} else {
				break;
			}
		}
		return ret;
	}
};

int main(int argc, char **argv) {

	vector<string> test;
	test.push_back("xyhello");
	test.push_back("xyworld");
	test.push_back("xyard");
	printVector(test);

	Solution *s = new Solution();

	string result = s->longestCommonPrefix(test);
	cout << "[+] result:\t" << result << endl;

	return 0;
}
