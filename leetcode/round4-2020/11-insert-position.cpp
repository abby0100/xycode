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
	int searchInsert(vector<int>& nums, int target) {
		if(nums.size() == 0)
			return 0;

		for(int i = 0; i < nums.size(); ++i) {
			if(nums[i] >= target)
				return i;

			if(i == nums.size() - 1)
				return ++i;
		}
		return -1;
	}
};

int main(int argc, char **argv) {

	vector<int> nums{1,3,5,6};
	Solution *s = new Solution();

	int result = s->searchInsert(nums, 2);
	cout << "[+] Result:\t" << result << endl;

	delete s;
	return 0;
}
