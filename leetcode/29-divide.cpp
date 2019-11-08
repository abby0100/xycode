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

class Solution {
public:
	int divide(int dividend, int divisor) {
		int n1 = 0;
		int n2 = 0;
		if(divisor) {
			for(int i = 0; i < 30; ++i) {
				if(dividend & 0x01 == 1) {
					n1 = i;
				}
				cout << "dividend:\t" << dividend << ",\t0x" << bitset<32>(dividend) << ",\thighest 1: " << n1 << endl;
				dividend >> 1;
			}
			for(int i = 0; i < 30; ++i) {
				if(divisor & 0x01 == 1) {
					n2 = i;
				}
				divisor >> 1;
			}
			//cout << "dividend:\t" << dividend << ",\t0x" << bitset<32>(dividend) << ",\thighest 1: " << n1 << endl;
			//cout << "divisor:\t" << divisor << ",\t0x" << bitset<32>(divisor) << ",\thighest 1: " << n2 << endl;
		}
		return 1 << (n1 - n2);
	}
};

int main(int argc, char **argv) {

	int dividend = 10;
	int divisor = 3;

	Solution *s = new Solution();
	int result = s->divide(dividend, divisor);
	cout << "result: " << result << endl;

	delete s;
	return 0;
}
