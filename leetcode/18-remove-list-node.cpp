#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
void printVector(vector<T> vec) {
	//cout << "[-] printVector" << endl;
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
	ListNode* removeNthFromEnd(ListNode* &head, int n) {
		int i = 0;
		ListNode *post = head;
		ListNode *curr = nullptr;
		ListNode *prev = nullptr;

		for(; post; ) {
			i++;
			post = post->next;
			if(i == n) {
				curr = head;
				cout << "find curr" << endl;
			} else if(i == n + 1) {
				cout << "find prev" << endl;
				curr = curr->next;
				prev = head;
			} else if(i > n + 1) {
				curr = curr->next;
				prev = prev->next;
			}
		}
		if(prev) {
			cout << "prev\t" << prev->val << endl;
			prev->next = curr->next;
		} else if(curr) {
			cout << "curr\t" << curr->val << endl;
			head = curr->next;
			printList(head);
		}
		return head;
	}
};

int main(int argc, char **argv) {

	// init
	int target = 2;
	ListNode *test = new ListNode(1);

	//ListNode *p = new ListNode(2);
	//test->next = p;
	//p = new ListNode(3);
	//test->next->next = p;
	//p = new ListNode(4);
	//test->next->next->next = p;
	//p = new ListNode(5);
	//test->next->next->next->next = p;
	printList(test);

	// solution
	Solution *s = new Solution();

	//vector<string> result;
	ListNode *result = s->removeNthFromEnd(test, target);
	printList(result);
//	printList(test);

	// release
	delete s;
	freeList(test);

	return 0;
}
