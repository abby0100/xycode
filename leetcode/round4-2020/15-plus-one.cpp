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
	vector<int> plusOne(vector<int>& digits) {
		int carry = 1;
		for(int i = digits.size() - 1; i >= 0; --i) {
			digits[i] += carry;
			carry = 0;
			if(digits[i] >= 10) {
				digits[i] -= 10;
				carry = 1;
			}
		}

		if(carry) {
			digits.insert(digits.begin(), 1);
		}
		return digits;
	}
};

int main(int argc, char **argv) {

	vector<int> digits{4,3,2,1};
	Solution *s = new Solution();

	vector<int> result = s->plusOne(digits);
	printVector(result);

	delete s;
	return 0;
}
