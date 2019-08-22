#include <iostream>
#include <string>

using namespace std;
#define INT_MAX	(1 << 31 - 1)
#define INT_MIN	(1 << 31)

class Solution {
	public:
		int reverse_int(int x) {
        		long ret = 0;
        		while(x != 0) {
        		    if(ret > INT_MAX/10 || ret < INT_MIN/10) {
        		        return 0;
        		    }
        		    ret = ret * 10 + x % 10;
				cout << "[-] ret:\t" << ret << endl;
        		    x /= 10;
        		}
        		return ret;
	}
};

int main(int argc, char **argv) {

	//int test = 0;
	//int test = 20;
	//int test = 20;

	//int test = 123;
	//int test = 204;
	//int test = 2040;
	//int test = -2040;
	//int test = -20408;
	//int test = 20408;

	int test = -2147483648;
	//int test = 1 << atoi(argv[1]) - 1;
	cout << "[+] test:\t" << test << endl;

	Solution *s = new Solution();

	int result = s->reverse_int(test);
	cout << "[+] ret:\t" << result << endl;

	return 0;
}
