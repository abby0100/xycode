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
		if(nums.size() <= 1) {
			return nums.size();
		}
		int key = nums[0];
		int index = 1;
		for(int i = 1; i < nums.size(); ++i) {
			if(nums[i] != key) {
				nums[index++] = nums[i];
				key = nums[i];
			}
		}
		printVector(nums);
		return index;
	}
};

int main(int argc, char **argv) {

	vector<int> vec;
	vec.push_back(0);
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(3);
	vec.push_back(4);
	printVector(vec);

	Solution *s = new Solution();
	int result = s->removeDuplicates(vec);
	cout << "result: " << result << endl;

	delete s;
	return 0;
}
