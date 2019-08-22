#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		int n = s.size();
        	int m = p.size();
        	vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        	dp[0][0] = 1;
        	s = " " + s;
        	p = " " + p;
        	for (int i = 0; i <= n; ++i) {
        	    for (int j = 1; j <= m; ++j) {
        	        if (p[j] != '*' && p[j] != '.') {
        	            if (i >= 1 && s[i] == p[j]) 
        	                dp[i][j] = dp[i - 1][j - 1];
				cout << "s[" << i << "]:\t" << s[i] << endl;
				cout << "p[" << j << "]:\t" << p[j] << endl;
				cout << "---> dp[" << i << "][" << j << "]:\t" << dp[i][j] << endl;
        	        }
        	        else if (i >= 1 && p[j] == '.') {
        	                dp[i][j] = dp[i - 1][j - 1];
				cout << "s[" << i << "]:\t" << s[i] << endl;
				cout << "p[" << j << "]:\t" << p[j] << endl;
				cout << "---> dp[" << i << "][" << j << "]:\t" << dp[i][j] << endl;
        	        }
        	        else if (p[j] == '*') {
        	            if (j >= 2) dp[i][j] = max(dp[i][j], dp[i][j - 2]);
        	            if (i >= 1 && (p[j - 1] == s[i] || p[j - 1] == '.')) {
        	                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        	            }

				cout << "s[" << i << "]:\t" << s[i] << endl;
				cout << "p[" << j << "]:\t" << p[j] << endl;
				cout << "---> dp[" << i << "][" << j << "]:\t" << dp[i][j] << endl;
        	        } else {
				cout << "s[" << i << "]:\t" << s[i] << endl;
				cout << "p[" << j << "]:\t" << p[j] << endl;
				cout << "---> dp[" << i << "][" << j << "]:\t" << dp[i][j] << endl;
			}
        	    }
        	}
        	return dp[n][m] >  0;
	}
};

int main(int argc, char **argv) {

	string test = "misssssp";
	string pattern = "mis*.p";
	cout << "[+] test:\t" << test << endl;
	cout << "[+] pattern:\t" << pattern << endl;

	Solution *s = new Solution();

	bool result = s->isMatch(test, pattern);
	cout << "[+] result:\t" << result << endl;

	return 0;
}
