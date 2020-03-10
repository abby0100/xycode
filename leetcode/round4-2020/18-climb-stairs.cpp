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
	int climbStairs(int n) {
		if(n <= 2)
			return n;

		int ret = 0;
		int min_1 = 1;
		int min_2 = 2;

		for(int i = 3; i <= n; ++i) {
			ret = min_1 + min_2;
			min_1 = min_2;
			min_2 = ret;
		}
			
		return ret;
	}
};

int main(int argc, char **argv) {

	int n = 12;
	Solution *s = new Solution();

	int result = s->climbStairs(n);
	cout << "[+] Result:\t" << result << endl;

	delete s;
	return 0;
}
