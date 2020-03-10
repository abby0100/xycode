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
	int removeDuplicates(vector<int>& nums) {
		if(nums.size() < 2)
			return nums.size();

		int length = 0;
		for(int i = 1; i < nums.size(); ++i) {
			if(nums[i] != nums[length])
				nums[++length] = nums[i];
		}

		return ++length;
	}
};

int main(int argc, char **argv) {

	vector<int> nums{0,0,1,1,1,2,2,3,3,4};
	Solution *s = new Solution();

	int result = s->removeDuplicates(nums);
	cout << "[+] Result:\t" << result << endl;

	delete s;
	return 0;
}
