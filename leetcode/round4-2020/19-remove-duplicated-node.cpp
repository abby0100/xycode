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
	ListNode* deleteDuplicates(ListNode* head) {
		if(!head)
			return head;

		ListNode* root = head;
		int val = root->val;
		ListNode* curr = root->next;
		while(curr) {
			if(curr->val == val) {
				ListNode* temp = curr;
				root->next = curr->next;
				curr = curr->next;
				delete temp;
			} else {
				val = curr->val;
				root->next = curr;
				root = root->next;
				curr = curr->next;
			}
		}
		return head;
	}
};

int main(int argc, char **argv) {

	ListNode *head = new ListNode(1);
	head->next = new ListNode(1);
	head->next->next = new ListNode(2);
	head->next->next->next = new ListNode(3);
	head->next->next->next->next = new ListNode(3);

	Solution *s = new Solution();

	ListNode* result = s->deleteDuplicates(head);
	printList(result);

	freeList(result);
	//freeList(head);

	delete s;
	return 0;
}
