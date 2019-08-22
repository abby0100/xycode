#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string int2Roman(int num) {
		cout << "-------------------------------" << endl;

		string ret = "";
		int thousands	= num / 1000;
		int hundreds	= (num - thousands * 1000) / 100;
		int tens	= (num - thousands * 1000 - hundreds * 100) / 10;
		int singles	= num - thousands * 1000 - hundreds * 100 - tens * 10;
		cout << "[-] thousands:\t" << thousands << endl;
		cout << "[-] hundreds:\t" << hundreds << endl;
		cout << "[-] tens:\t" << tens << endl;
		cout << "[-] singles:\t" << singles << endl;

		while(thousands > 0) {
			ret += "M";
			thousands--;
		}

		while(hundreds > 0) {
			if(hundreds == 9) {
				ret += "CM";
				break;
			} else if(hundreds >= 5) {
				hundreds -= 5;
				ret += "D";
			//	while(hundreds > 0){
			//		ret += "C";
			//		hundreds--;
			//	}
			} else if(hundreds == 4) {
				ret += "CD";
				break;
			} else {
				ret += "C";
				hundreds--;
			}
		}

		while(tens > 0) {
			if(tens == 9) {
				ret += "XC";
				break;
			} else if(tens >= 5) {
				tens -= 5;
				ret += "L";
			} else if(tens == 4) {
				ret += "XL";
				break;
			} else {
				ret += "X";
				tens--;
			}
		}

		while(singles > 0) {
			if(singles == 9) {
				ret += "IX";
				break;
			} else if(singles >= 5) {
				singles -= 5;
				ret += "V";
			} else if(singles == 4) {
				ret += "IV";
				break;
			} else {
				ret += "I";
				singles--;
			}
		}

		cout << "[-] ret:\t" << ret << endl;
		return ret;
	}
};

int main(int argc, char **argv) {

	int test = 13;
	string result = "";
	cout << "[+] test:\t" << test << endl;

	Solution *s = new Solution();

	result = s->int2Roman(3);
	result = s->int2Roman(4);
	result = s->int2Roman(9);
	result = s->int2Roman(58);
	result = s->int2Roman(1994);

	return 0;
}
