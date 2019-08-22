#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if(x < 0) {
			return false;
		}
		int value = x;
		long long y = 0;
		while (value) {
			y = y * 10 + value % 10;
			value /= 10;
		}
		return (y == x) ? true : false;
	}
};

int main(int argc, char **argv) {

	int test = 42;
	cout << "[+] test:\t" << test << endl;

	Solution *s = new Solution();

	bool result = s->isPalindrome(test);
	cout << "[+] result:\t" << result << endl;

	return 0;
}
