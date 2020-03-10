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
	bool isValid(string s) {
		stack<char> st{};
		for (int i = 0; i < s.size(); ++i) {
			switch (s[i]) {
			case '(':
			case '[':
			case '{':
				st.push(s[i]);
				break;
			case ')':
				if(st.size() && st.top() == '(') {
					st.pop();
				} else {
					return false;
				}
				break;
			case ']':
				if(st.size() && st.top() == '[') {
					st.pop();
				} else {
					return false;
				}
				break;
			case '}':
				if(st.size() && st.top() == '{') {
					st.pop();
				} else {
					return false;
				}
				break;
			defalut:
				return false;
			}
		}

		return st.size() == 0;
	}
};

int main(int argc, char **argv) {

	//string str = "(){}[()]";
	string str = "(){}[(])";
	Solution *s = new Solution();

	bool result = s->isValid(str);
	cout << "[+] Result:\t" << result << endl;

	delete s;
	return 0;
}
