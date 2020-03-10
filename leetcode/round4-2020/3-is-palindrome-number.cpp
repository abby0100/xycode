#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define INT_MAX ((1 << 31) - 1)
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
	bool isPalindrome(int x) {
		if (x < 0)
			return false;

		int num1 = x, num2 = 0;
		while (num1) {
			if (num2 > (INT_MAX / 10))
				return false;
			num2 = num2 * 10 + num1 % 10;
			num1 /= 10;
		}

		return x == num2;
	}
};

int main(int argc, char **argv) {

	cout << "[+] main INT_MAX:\t" << INT_MAX << endl;

	int x = 12321;
	Solution *s = new Solution();

	bool result = s->isPalindrome(x);
	cout << "[+] Result:\t" << result << endl;

	delete s;
	return 0;
}
