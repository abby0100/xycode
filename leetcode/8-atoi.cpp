#include <iostream>
#include <string>

using namespace std;
#define INT_MAX	((1 << 31) - 1)
#define INT_MIN	(1 << 31)

class Solution {
	public:
		int xy_atoi(string str) {
			long long ret = 0;
        		bool allow_space = true;
        		bool negative = false;
        		bool start = false;
        		for(int i = 0; i < str.size(); ++i) {
        		    if(str[i] == ' ') {
        		        if(allow_space)                  
        		            continue;
        		        else
        		            break;
        		    }
        		    allow_space = false;

        		    if(str[i] == '-') {
        		        if(start)
        		            return negative ? -ret : ret;
        		        else
        		            negative = true;
        		    } else if(str[i] == '+') {
        		        if(start)
        		            return negative ? -ret : ret;
        		        else
        		            negative = false;
        		    } else if(str[i] >= '0' && str[i] <= '9') {
                		ret = ret * 10 + (str[i] - '0');
				cout << "ret:\t" << ret << endl;
				cout << "INT_MAX:\t" << INT_MAX << endl;
				cout << "INT_MIN:\t" << INT_MIN << endl;
                		if(!negative && ret > INT_MAX) {
                		    return INT_MAX;
                		} else if(negative && -ret < INT_MIN) {
                		    return INT_MIN;
                		}
        		    } else {
        		            break;
        		    }
        		    start = true;
        		}
        		return negative ? -ret : ret;

		}
};

int main(int argc, char **argv) {

	string test = "-5-";
	//string test = "42";
	//string test = "-42";
	//string test = "4193 with words";
	//string test = "words and 987";

	//string test = "-91283472332";
	//string test = "2147483646";
	cout << "[+] test:\t" << test << endl;

	Solution *s = new Solution();

	int result = s->xy_atoi(test);
	cout << "[+] result:\t" << result << endl;

	return 0;
}
