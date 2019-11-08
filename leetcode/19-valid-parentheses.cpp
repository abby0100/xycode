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
	bool isValid(string s) {
		bool ret = true;
		if(s.empty() || s.size() == 0)
			return ret;

		stack<char> st;
		for(int i = 0; i < s.size(); ++i) {
			if(st.empty()) {
				st.push(s[i]);
				continue;
			}
			if( (st.top() == '(' && s[i] == ')') || (st.top() == '[' && s[i] == ']') || (st.top() == '{' && s[i] == '}') ) {
				st.pop();
			} else {
				st.push(s[i]);
			}
		}

		if(!st.empty())
			return false;
		return ret;
	}
};

int main(int argc, char **argv) {

	string test = "()[{]}";
	//string test = "()[]{}";
	cout << "[+] test:\t" << test << endl;

	Solution *s = new Solution();

	//vector<string> result;
	bool result = s->isValid(test);
	cout << "[+] result:\t" << result << endl;

	delete s;
	return 0;
}
