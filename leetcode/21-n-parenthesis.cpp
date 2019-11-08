#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

template<typename T>
void printVector(vector<T> vec) {
	cout << "[-] " << __func__ << endl;
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
	vector<string> generateParenthesis(int n) {
		vector<string> ret;

		if(n == 0) {
			ret.push_back("");
		} else {
			for(int i = 0; i < n; ++i) {
				for(string left : generateParenthesis(i)) {
					for(string right : generateParenthesis(n-1-i)) {
						ret.push_back(string("(") + left + ")" + right);
					}
				}
			}
		}

		printf("---> generateParenthesis n = %d\n", n);
		printVector(ret);
		return ret;
	}
};

int main(int argc, char **argv) {

	//int test = 1;
	int test = atoi(argv[1]);
	cout << "[+] test:\t" << test << endl;

	Solution *s = new Solution();

	vector<string> result = s->generateParenthesis(test);
	printVector(result);

	delete s;
	return 0;
}
