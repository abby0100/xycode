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
	int strStr(string haystack, string needle) {
		if(haystack.empty() || needle.empty() || haystack.size() < needle.size()) {
			return -1;
		}

		int haystack_len = haystack.size();
		int needle_len = needle.size();
		for(int i = 0; i < haystack_len; ++i) {
			cout << __func__ << " i: " << i << endl;

			if(haystack_len - i < needle_len) {
				cout << " i: " << i << endl;
				return -1;
			}
			for(int j = 0; j < needle_len; ++j) {
				cout << __func__ << " j: " << j << endl;

				if(haystack[i + j] != needle[j]) {
					cout << " i: " << i << " j: " << j << endl;
					break;
				}
				if(j == needle_len - 1) {
					cout << " find, i: " << i << " j: " << j << endl;
					return i;
				}
			}
		}
		return -1;
	}
};

int main(int argc, char **argv) {

	string haystack("aaaaa");
	string needle("aaa");
	//string needle("bba");

	Solution *s = new Solution();
	int result = s->strStr(haystack, needle);
	cout << "Result: " << result << endl;

	delete s;
	//freeList(l1);
	return 0;
}
