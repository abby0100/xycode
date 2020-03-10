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
	string countAndSay(int n) {
		if(n <= 0)
			return "";
		if(n == 1)
			return "1";

		string ret{""};

		string temp = countAndSay(n-1);
		//cout << "lenght:\t" << temp.size() << ", temp:\t" << temp << endl;

		int i = 0;
		char val = temp[0];
		//cout << "countAndSay temp[0]:\t" << val << endl;

		int count = 0;
		while(i < temp.size()) {
			//cout << "countAndSay i:\t" << i << endl;
			if(temp[i] == val) {
				++count;
				//cout << "count " << val << ":\t" << count << endl;
				if(i == temp.size() - 1) {
					//cout << "last item" << endl;
					ret += to_string(count) + val;
					//cout << "return ret:\t" << ret << endl;
					return ret;
				}
			} else {
				//cout << "countAndSay new val:\t" << temp[i] << endl;
				ret += to_string(count) + val;
				//cout << "count " << val << ":\t" << count << endl;
				val = temp[i];
				count = 1;
			}
			++i;
			//cout << "countAndSay ++i:\t" << i << endl;
		}
		if(count)
			ret += to_string(count) + val;
		//cout << "return ret:\t" << ret << endl;
		return ret;
	}
};

int main(int argc, char **argv) {

	int x = 123;
	Solution *s = new Solution();

	for(int k = 0; k < 10; ++k) {
	string result = s->countAndSay(k);
	cout << "[+] countAndSay " << k << " result:\t" << result << endl;
	}

	delete s;
	return 0;
}
