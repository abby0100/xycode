#include <iostream>
#include <string>

using namespace std;

class Solution {
	public:
		string convert(string s, int numRows) {
			int index = 0;
			int circle = numRows * 2 - 2;
			int size = s.size();
			char element[size] = {0};

			for(int i = 0; i < numRows; ++i) {
				for(int j = 0; j <= size / circle; ++j) {
					// only 1 character
					if(i == 0 || i == numRows - 1) {
						int ref = j * circle + i;
						if(ref < size) {
							cout << "s[" << ref << "]:\t" << s[ref] << endl;
							cout << "element[" << index << "]:\t" << s[ref] << endl;
							element[index++] = s[ref];
							//cout << "i,j: " << i << "," << j << " : " << element[index] << endl;
						}
					} else {
					// 2 characters
						int ref = j * circle + i;
						if(ref < size) {
							cout << "s[" << ref << "]:\t" << s[ref] << endl;
							cout << "element[" << index << "]:\t" << s[ref] << endl;
							element[index++] = s[ref];
							//cout << "i,j: " << i << "," << j << " : " << element[index] << endl;
						}

						ref = (j + 1) * circle - i;
						if(ref < size) {
							cout << "s[" << ref << "]:\t" << s[ref] << endl;
							cout << "element[" << index << "]:\t" << s[ref] << endl;
							element[index++] = s[ref];
							//cout << "i,j: " << i << "," << j << " : " << element[index] << endl;
						}
					}
				}
			}

			string ret = string(element);
			return ret;
		}
};

int main(int argc, char **argv) {

	int rows = 3;
	//int rows = 4;
	string test = "AB";
	//string test = "PAYPALISHIRING";
	cout << "test:\t" << test << endl;

	Solution *s = new Solution();

	string convertion = s->convert(test, rows);
	cout << "[-] convertion\t" << convertion << endl;

	return 0;
}
