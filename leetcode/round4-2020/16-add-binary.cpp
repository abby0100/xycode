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
	string addBinary(string a, string b) {
		string ret{""};

		int carry = 0, val = 0;
		int i = a.size() - 1;
		int j = b.size() - 1;
		for(; i >= 0 && j >= 0; --i, --j) {
			//cout << "addBinary a:\t" << a[i] << endl;
			//cout << "addBinary b:\t" << b[j] << endl;
			val = a[i] - '0' + b[j] - '0' + carry;
			//cout << "addBinary val:\t" << val << endl;
			if (val >= 2) {
				ret = to_string(val - 2) + ret;
				carry = 1;
			} else {
				ret = to_string(val) + ret;
				carry = 0;
			}
			//cout << "addBinary ret:\t" << ret << endl;
			//cout << "addBinary carry:\t" << carry << endl;
		}
		for(int k = i; k >= 0; --k) {
			val = a[k] - '0' + carry;
			if (val >= 2) {
				ret = to_string(val - 2) + ret;
				carry = 1;
			} else {
				ret = to_string(val) + ret;
				carry = 0;
			}
		}
		for(int l = j; l >= 0; --l) {
			val = b[l] - '0' + carry;
			if (val >= 2) {
				ret = to_string(val - 2) + ret;
				carry = 1;
			} else {
				ret = to_string(val) + ret;
				carry = 0;
			}
		}

		if(carry)
			ret = '1' + ret;

		return ret;
	}
};

int main(int argc, char **argv) {

	string a = "1010";
	//string b = "1011";
	string b = "1010101";
	cout << "main a:\t" << a << endl;
	cout << "main b:\t" << b << endl;
	Solution *s = new Solution();

	string result = s->addBinary(a, b);
	cout << "[+] Result:\t" << result << endl;

	delete s;
	return 0;
}
