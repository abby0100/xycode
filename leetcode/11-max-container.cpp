#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printVector(vector<int> vec) {
	for(int i = 0; i < vec.size(); ++i) {
		cout << vec[i] << " ";
	}
	cout << endl;
}

class Solution {
public:
	int maxArea(vector<int>& height) {
		int ret = 0;
		int area = 0;
		bool increase = true;
		int i = 0, j = height.size() - 1;
		while(i<j) {
			increase = (height[i] <= height[j]);
			if(increase) {
				area = height[i] * (j - i);
				i++;
			} else {
				area = height[j] * (j - i);
				j--;
			}
			ret = (area > ret) ? area : ret;
		}
		return ret;
	}
};

int main(int argc, char **argv) {

	vector<int> test = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	cout << "[+] test:\n" << endl;
	printVector(test);

	Solution *s = new Solution();

	int result = s->maxArea(test);
	cout << "[+] result:\t" << result << endl;

	return 0;
}
