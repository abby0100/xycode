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
	ListNode* swapPairs(ListNode* head) {
		ListNode *l = head;
		if(head == nullptr) {
			cout << "not handle " << __func__ << endl;
			return head;
		} else {
			cout << "handle " << __func__ << endl;
		}
		int temp = 0;
		ListNode *p = head;
		ListNode *q;
		while(head) {
			p = head;
			head = head->next;
			q = head;
			if(p && q) {
				temp = p->val;
				p->val = q->val;
				q->val = temp;
			}
			if(head)
				head = head->next;
		}
		return l;
	}
};

int main(int argc, char **argv) {

	ListNode *l;
	if(l == nullptr) {
		cout << "not handle " << __func__ << endl;
		return -1;
	} else {
		cout << "handle " << __func__ << endl;
		//cout << "val " << l->val << endl;
	}
//	ListNode *l1 = new ListNode(1);
//	l1->next = new ListNode(2);
//	l1->next->next = new ListNode(3);
//	l1->next->next->next = new ListNode(4);
//	printList(l1);

	Solution *s = new Solution();
	ListNode* result = s->swapPairs(l);
	//ListNode* result = s->swapPairs(l1);
	printList(result);

	delete s;
	//freeList(l1);
	freeList(result);
	return 0;
}
