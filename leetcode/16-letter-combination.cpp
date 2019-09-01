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
	vector<string> letterCombinations(string digits) {
		vector<string> ret;
		ret.push_back("");

		for(int i = 0; i < digits.size(); ++i) {
			cout << "digit:\t" << digits[i] << endl;

			vector<string> temp;
			for(int j = 0; j < ret.size(); ++j) {
				cout << "ret:\t" << ret[j] << endl;

				switch(digits[i] - 48) {
				case 2:
					temp.push_back(ret[j] + "a");
					temp.push_back(ret[j] + "b");
					temp.push_back(ret[j] + "c");
					break;
				case 3:
					temp.push_back(ret[j] + "d");
					temp.push_back(ret[j] + "e");
					temp.push_back(ret[j] + "f");
					break;
				case 4:
					temp.push_back(ret[j] + "g");
					temp.push_back(ret[j] + "h");
					temp.push_back(ret[j] + "i");
					break;
				case 5:
					temp.push_back(ret[j] + "j");
					temp.push_back(ret[j] + "k");
					temp.push_back(ret[j] + "l");
					break;
				case 6:
					temp.push_back(ret[j] + "m");
					temp.push_back(ret[j] + "n");
					temp.push_back(ret[j] + "o");
					break;
				case 7:
					temp.push_back(ret[j] + "p");
					temp.push_back(ret[j] + "q");
					temp.push_back(ret[j] + "r");
					temp.push_back(ret[j] + "s");
					break;
				case 8:
					temp.push_back(ret[j] + "t");
					temp.push_back(ret[j] + "u");
					temp.push_back(ret[j] + "v");
					break;
				case 9:
					temp.push_back(ret[j] + "w");
					temp.push_back(ret[j] + "x");
					temp.push_back(ret[j] + "y");
					temp.push_back(ret[j] + "z");
					break;
				default:
					break;
				}
				printVector(temp);
			}
			ret.swap(temp);
		}
		return ret;
	}
};

int main(int argc, char **argv) {

	string test = "234";

	Solution *s = new Solution();

	//vector<string> result;
	vector<string> result = s->letterCombinations(test);
	printVector(result);
	//cout << "[+] result:\t" << result << endl;

	return 0;
}
