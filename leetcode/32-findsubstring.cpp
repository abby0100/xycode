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
	vector<string> findSubstring(string str, vector<string> words) {
		vector<string> ret;
		if(str.empty() || words.empty())
			return ret;

		cout << __func__ << " str:\t" << str << endl;
		cout << __func__ << " words:\t" << words[0] << endl;
		cout << __func__ << " words:\t" << words[1] << endl;

		char *cptr = str;
		for(int i = 0; i < str.size() - 1; ++i) {
			while(*cptr) {
				for(int j = 0; j < words[0 ].size() - 1; ++j) {
					if(*cptr == words[k][j]) 
				}
			}
		}
		return ret;
	}
};

int main(int argc, char **argv) {

	string str = "barfoothefoobarman";
	vector<string> words;
	words.push_back("foo");
	words.push_back("bar");

	Solution *s = new Solution();
	vector<string> result = s->findSubstring(str, words);

	delete s;
	return 0;
}
