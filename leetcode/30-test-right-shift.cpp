#include <algorithm>
#include <bitset>
#include <iostream>
#include <iomanip>
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


int main(int argc, char **argv) {

	int dividend = 10;
	int divisor = 3;

	int n1 = 0;

	for(int i = 0; i < 30; ++i) {
		if(dividend & 0x00000001 == 0) {
			cout << "dividend:\t" << dividend << ",\t0x" << bitset<32>(dividend) << endl;
			n1 = i;
		}
		cout << "dividend:\t" << dividend << ",\t0x" << bitset<32>(dividend) << ",\thighest 1: " << n1 << endl;
		dividend >> 1;
	}

	return 0;
}
