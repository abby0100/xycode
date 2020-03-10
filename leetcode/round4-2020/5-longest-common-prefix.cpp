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
	string longestCommonPrefix(vector<string>& strs) {
		string ret{""};

		if(strs.size() > 0) {
			for(int i = 0; i < strs[0].size(); ++i) {
				for(int j = 0; j < strs.size(); ++j) {
					if(strs[j][i] != strs[0][i])
						return ret;
						//return strs[0].substr(0, i);
				}
				//ret += p;
				ret += strs[0][i];
			}
			//return strs[0].substr(0, i);
		}

		return ret;
		//return "";
	}
};

int main(int argc, char **argv) {

	vector<string> strs{"flower", "flow", "flight"};
	Solution *s = new Solution();

	string result = s->longestCommonPrefix(strs);
	cout << "[+] Result:\t" << result << endl;

	delete s;
	return 0;
}
