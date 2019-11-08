#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

template<typename T>
void printVector(vector<T> vec) {
	cout << "[-] " << __func__ << endl;
	for(int i = 0; i < vec.size(); ++i) {
		cout << vec[i] << " ";
	}
	cout << endl;
}

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(nullptr) {};
};

void printList(ListNode *head) {
	cout << "[-] " << __func__ << endl;
	while(head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

void freeList(ListNode *head) {
	cout << "[-] " << __func__ << endl;
	ListNode *p = head;
	while(head) {
		cout << head->val << " ";
		head = head->next;
	}
	delete p;
	cout << endl;
}

class Solution {
public:
	ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
		ListNode *ret;
		if(!l1)
			return l2;
		else if(!l2)
			return l1;
		
		ListNode *l;
		if(l1->val <= l2->val) {
			l = l1;
			l1 = l1->next;
		//} else if(l1->val == l2->val) {
		//	l = l1;
		//	l1 = l1->next;
		//	l2 = l2->next;
		} else {
			l = l2;
			l2 = l2->next;
		}
		ret = l;
		//printList(l1);
		//printList(l2);
		//printList(ret);

		while(l1 && l2) {
			cout << "-----------------------------------------" << endl;
			if(l1->val <= l2->val) {
				l->next = l1;
				l = l->next;
				l1 = l1->next;
			//} else if(l1->val == l2->val) {
			//	l1 = l1->next;
			} else {
				l->next = l2;
				l = l->next;
				l2 = l2->next;
			}
			//printList(l1);
			//printList(l2);
			//printList(ret);
		}
		if(l1)
			l->next = l1;
		else if(l2)
			l->next = l2;


		return ret;
	}
};

int main(int argc, char **argv) {

	ListNode *l1 = new ListNode(1);
	ListNode *l2 = new ListNode(1);

	ListNode* p = new ListNode(2);
	l1->next = p;
	p = new ListNode(3);
	l2->next = p;
	p = new ListNode(4);
	l1->next->next = p;
	p = new ListNode(4);
	l2->next->next = p;

	l2->next->next->next = new ListNode(9);

	Solution *s = new Solution();

	ListNode* result = s->merge2Lists(l1, l2);
	printList(result);

	delete s;
	freeList(l1);
	freeList(l2);
	return 0;
}
