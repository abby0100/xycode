#include <iostream>
#include <unistd.h>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};
ListNode* head;

int mylog(string info) {

        cout << endl << "[+] " << info << endl;
}

int init() {

	ListNode *lx = new ListNode(247);
	head = lx;
	cout << "ListNode lx->val: " << lx->val  << endl;

	for(int i = 0; i < 10; ++i) {
		lx->next = new ListNode(i);
		lx = lx->next;
	}
	lx->next = head->next;
}

void print_list() {

	ListNode *p = head->next;
	while(p != nullptr) {
		cout << p->val << " ";
		if (p->val == 9) {
			cout << endl;
			sleep(1);
		}
		p = p->next;
	}
	cout << endl;
}

int main(int argc, char** argv) {

	mylog("main");

	init();

	print_list();

	return 0;
}
