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
	inline ListNode* merge2(ListNode *l1, ListNode *l2) {
		printList(l1);
		printList(l2);
		ListNode dummy(0);
		ListNode *tail = &dummy;
			printList(&dummy);

		while(l1 && l2) {
			ListNode* &temp = l1->val <= l2->val ? l1 : l2;
			tail = tail->next = temp;
			temp = temp->next;
			printList(temp);
		}
		tail->next = l1 ? l1 : l2;
		return dummy.next;
	}

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if(lists.size() == 0)
			return nullptr;

		queue<ListNode*> waiting(deque<ListNode *>(lists.begin(), lists.end()));
		while(waiting.size() > 1) {
			ListNode *l1 = waiting.front();
			waiting.pop();
			ListNode *l2 = waiting.front();
			waiting.pop();

			waiting.push(merge2(l1, l2));
		}
		return waiting.front();
	}
};

int main(int argc, char **argv) {

	vector<ListNode*> test;

	ListNode *l1 = new ListNode(1);
	ListNode *l2 = new ListNode(1);
	ListNode *l3 = new ListNode(2);

	l1->next = new ListNode(4);
	l1->next->next = new ListNode(5);
	l2->next = new ListNode(3);
	l2->next->next = new ListNode(4);
	l3->next = new ListNode(6);

	test.push_back(l1);
	test.push_back(l2);
	test.push_back(l3);

	Solution *s = new Solution();

	ListNode* result = s->mergeKLists(test);
	//cout << __func__ << " Pointer result:\t" <<  result << endl;

	delete s;
	//freeList(l1);
	//freeList(l2);
	//freeList(l3);
	freeList(result);

	freeVector(test);
	return 0;
}
