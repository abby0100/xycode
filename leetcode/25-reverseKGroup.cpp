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
	ListNode* reverseKGroup(ListNode* head, int k) {
		if(head == nullptr || k <= 1)
			return head;
		ListNode* temp = head;
		stack<ListNode*> st;
		for(int i = 0; i < k; ++i) {
			if(head == nullptr)
				return temp;
			st.push(head);
			head = head->next;
		}
		ListNode* dummy = new ListNode(0);
		ListNode* ret = dummy;
		dummy->next = st.top();
		st.pop();
		dummy = dummy->next;
		ListNode* next_head = dummy->next;
		while(!st.empty()) {
			dummy->next = st.top();
			st.pop();
			dummy = dummy->next;
		}
		dummy->next = reverseKGroup(next_head, k);
		return ret->next;
	}
};

int main(int argc, char **argv) {

	ListNode *l1 = new ListNode(1);

	l1->next = new ListNode(2);
	l1->next->next = new ListNode(3);
	l1->next->next->next = new ListNode(4);
	l1->next->next->next->next = new ListNode(5);
	printList(l1);

	Solution *s = new Solution();
	ListNode* result = s->reverseKGroup(l1, 2);

	delete s;
	freeList(l1);
	return 0;
}
