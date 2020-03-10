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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if(!l1)
			return l2;
		else if(!l2)
			return l1;

		ListNode* root = nullptr;
		if(l1->val <= l2->val) {
			root = new ListNode(l1->val);
			l1 = l1->next;
		} else {
			root = new ListNode(l2->val);
			l2 = l2->next;
		}
		ListNode* ret = root;

		while(l1 && l2) {
			if(l1->val <= l2->val) {
				root->next = new ListNode(l1->val);
				l1 = l1->next;
			} else {
				root->next = new ListNode(l2->val);
				l2 = l2->next;
			}
			root = root->next;
		}

		if(l1)
			root->next = l1;
		else
			root->next = l2;

		return ret;
	}
};

int main(int argc, char **argv) {

	ListNode *l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(4);

	ListNode *l2 = new ListNode(1);
	l2->next = new ListNode(3);
	l2->next->next = new ListNode(4);

	Solution *s = new Solution();
	ListNode* result = s->mergeTwoLists(l1, l2);
	printList(result);

	delete s;
	return 0;
}
