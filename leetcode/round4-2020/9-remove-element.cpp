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
	int removeElement(vector<int>& nums, int val) {
		if(nums.size() == 0)
			return nums.size();
		else if(nums.size() == 1 && nums[0] == val)
			return 0;

		int i = 0, j = nums.size() - 1;
		while(i < j) {
			while(nums[i] != val)
				if(++i > j)
					return i;
			while(nums[j] == val)
				if(--j < i)
					return i;
			if(i < j) {
				swap(nums[i], nums[j]);
				++i;
				--j;
			}
		}
		if(i == j) {
			if (nums[i] == val)
				return i;
			else
				return ++i;
		} else {
			return i;
		}
	}
};

int main(int argc, char **argv) {

	//vector<int> nums{0,1,2,2,3,0,4,2};
	vector<int> nums{1};
	Solution *s = new Solution();

	int result = s->removeElement(nums, 2);
	cout << "[+] Result:\t" << result << endl;

	delete s;
	return 0;
}
