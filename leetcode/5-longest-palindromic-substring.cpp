#include <iostream>
#include <string>

using namespace std;

class Solution {
	public:
		string longestPalindrome(string s) {
			int size = s.size();
			cout << "[+] size:\t" << size << endl;

			int start = 0, end = size - 1;
			string ret = "";
			
			while(start <= end) {
			// start++
				int m = start, n = end;

				while(m <= n) {
				// n--
					int i = m, j = n;

					while(i <= j) {
					// i++, j--

						if(s[i] == s[j]) {
							//cout << i << " vs " << j << endl;
							//cout << s[i] << " vs " << s[j] << endl;
							if (j - i >= 2) {
								// need to continue check
								i++;
								j--;
							} else {
								// we found a palindrome
								//cout << "m: " << m << ", n: " << n << endl;
								cout << "[-] found a palindroime:\t" << s.substr(m, n - m + 1) << endl;
								if(ret.size() < (n - m + 1)) {
									ret = s.substr(m, n - m + 1);
								}
								break;
							}
						} else {
							// not a palindroime
							//cout << i << " vs " << j << endl;
							//cout << s[i] << " vs " << s[j] << endl;
							//cout << " no matched, skip searching... " << endl;
							break;
						}
					}

					// not [start, end (i, j)], maybe (start, end - 1)
					//j--;
					n--;
				}

				// start from next value
				start++;
			}

			return ret;
		}
};

int main(int argc, char **argv) {

	//string test = "a";
	//string test = "aa";
	//string test = "ab";
	//string test = "aba";
	//string test = "abab";
	//string test = "rabdba";
	string test = "rsdfabdfsdbaweacveaegeafsdavaerherkojasdgdfegsdfh";
	cout << "[+] orig:\t" << test << endl;

	Solution *s = new Solution();
	string res = s->longestPalindrome(test);

	cout << "[-] res:\t" << res << endl;
	return 0;
}
