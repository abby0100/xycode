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
	int lengthOfLastWord(string s) {
		//cout << "lengthOfLastWord s:\t" << s << endl;
		if(s.size() == 0)
			return 0;

		if(s[s.size() - 1] == ' ')
			return lengthOfLastWord(s.substr(0, s.size() - 1));

		//cout << "lengthOfLastWord length:\t" << s.size() << endl;
		for(int i = s.size() - 1; i >= 0; --i) {
			//cout << "lengthOfLastWord i:\t" << i << endl;
			//cout << "lengthOfLastWord s[i]:\t" << s[i] << endl;
			if(s[i] == ' ')
				return s.size() - 1 - i;
			if(i == 0)
				return s.size();
		}

		//cout << "lengthOfLastWord return 0" << endl;
		return 0;
	}
};

int main(int argc, char **argv) {

	//string str = "Hello World";
	string str = "a ";
	Solution *s = new Solution();

	int result = s->lengthOfLastWord(str);
	cout << "[+] Result:\t" << result << endl;

	delete s;
	return 0;
}
