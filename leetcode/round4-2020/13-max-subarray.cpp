#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <queue>

using namespace std;

template<typename T>
void printVector(vector<T> vec) {
	//cout << "[-] " << __func__ << endl;
	for(int i = 0; i < vec.size(); ++i) {
		cout << vec[i] << " ";
	}
	cout << endl;
}

template<typename T>
void freeVector(vector<T> vec) {
	cout << "[-] " << __func__ << endl;
	if(!vec.empty()) {
		vec.clear();
		vector<T>().swap(vec);
	}
}

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(nullptr) {};
};

void printList(ListNode *head) {
	//cout << "[-] " << __func__ << endl;
	while(head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

void freeList(ListNode *head) {
	cout << "[-] " << __func__ << endl;
	while(head) {
		ListNode *p = head;
		cout << head->val << " ";
		head = head->next;
		delete p;
	}
	cout << endl;
}

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int ret = 0, max = nums[0];

		for(int i = 0; i < nums.size(); ++i) {
			max = nums[i] > max ? nums[i] : max;
		}
		cout << "maxSubArray max:\t" << max << endl;

		for(int i = 0; i < nums.size(); ++i) {
			ret += nums[i];
			if (ret <= 0)
				ret = 0;
			else if (ret > max)
				max = ret;
			//cout << "maxSubArray max:\t" << max << endl;
		}
		return max;
	}
};

int main(int argc, char **argv) {

	vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
	Solution *s = new Solution();

	int result = s->maxSubArray(nums);
	cout << "[+] Result:\t" << result << endl;

	delete s;
	return 0;
}
