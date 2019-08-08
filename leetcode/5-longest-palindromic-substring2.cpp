#include <iostream>
#include <string>

using namespace std;

class Solution {
	public:
		string longestPalindrome(string s) {
			string ret = "";
			int size = s.size();

			// 1. find *@*
			for(int i = 0; i < size; ++i) {
				// let's find a palindrome (larger than 1 character)
				int left, right;
				left = right = i;

				while (left > 0 && right < size - 1) {
					left--;
					right++;
					if (s[left] != s[right]) {
						left++;
						right--;
						break;
					}
				}
				if(right - left >= 0) {
					// find a palindrome
					cout << "[-] find a palindrome:\t" << s.substr(left, right - left + 1) << endl;

				       	if(right - left + 1 > ret.size()) {
						// update the palindrome
						ret = s.substr(left, right - left + 1);
					}
				}
			}

			// 2. find *@@*
			for(int i = 0, j = 1; j < size; ++i, ++j) {
				// let's find a palindrome (like *@@*)
				int left, right;
				left = i;
				right = j;

				while (left >= 0 && right <= size - 1) {
					if(s[left] != s[right]) {
						left++;
						right--;
						break;
					}
					if(left == 0 || right == size - 1) {
						break;
					}
					left--;
					right++;
				}
				if(right - left >= 1) {
					// find a palindrome
					cout << "[-] find a palindrome:\t" << s.substr(left, right - left + 1) << endl;

				       	if(right - left + 1 > ret.size()) {
						// update the palindrome
						ret = s.substr(left, right - left + 1);
					}
				}
			}

			//return s.substr(0, size);
			return ret;
		}
};

int main(int argc, char **argv) {

	string test = "rsdfabddbafsdbaweacveaegeafsdavaerherkojasdgdfegsdfh";
	cout << "[#] orig:\t" << test << endl;

	string ret;
	Solution *s = new Solution();

	ret = s->longestPalindrome(test);
	cout << "[-] ret:\t" << ret << endl;

	return 0;
}
