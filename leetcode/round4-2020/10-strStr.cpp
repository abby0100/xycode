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
		if(needle.size() == 0)
			return 0;
		if(haystack.size() == 0 || haystack.size() < needle.size())
			return -1;

		for(int i = 0; i <= haystack.size() - needle.size(); ++i) {
			int temp = i;
			for(int j = 0; j < needle.size(); ++j) {
				if(needle[j] == haystack[temp])
					++temp;
				else
					break;

				if(j == needle.size() -1)
					return i;
			}
		}
		return -1;
	}
};

int main(int argc, char **argv) {

	string haystack = "aaaaa";
	string needle = "bba";

	Solution *s = new Solution();

	int result = s->strStr(haystack, needle);
	cout << "[+] Result:\t" << result << endl;

	delete s;
	return 0;
}
