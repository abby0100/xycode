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
	int romanToInt(string s) {
		int length = s.size();
		int i = 0, ret = 0;

		while(i < length) {
			if (s[i] == 'M') {
				ret += 1000;
				i++;
			} else if (s[i] == 'D') {
				ret += 500;
				i++;
			} else if (s[i] == 'C') {
				i++;
				if(i < length) {
					if (s[i] == 'M') {
						ret += 900;
						i++;
					} else if (s[i] == 'D') {
						ret += 400;
						i++;
					} else {
						ret += 100;
					}
				} else {
					ret += 100;
				}
			} else if (s[i] == 'L') {
				ret += 50;
				i++;
			} else if (s[i] == 'X') {
				i++;
				if(i < length) {
					if (s[i] == 'C') {
						ret += 90;
						i++;
					} else if (s[i] == 'L') {
						ret += 40;
						i++;
					} else {
						ret += 10;
					}
				} else {
					ret += 10;
				}
			} else if (s[i] == 'V') {
				ret += 5;
				i++;
			} else if (s[i] == 'I') {
				i++;
				if (i < length) {
					if (s[i] == 'V') {
						ret += 4;
					} else if (s[i] == 'X') {
						ret += 9;
					} else {
						ret += 2;
						while(++i < length) {
							ret += 1;
						}
					} 
					i++;
				} else {
					ret += 1;
				}
			}

		}
		return ret;
	}
};

int main(int argc, char **argv) {


/*
 * I, V, X, L,   C, D, M
 * 1, 5, 10,50,100,500,1000
 */

	//string valStr = "MCMXCIV";
	//string valStr = "III";
	string valStr = "DCXXI";
	Solution *s = new Solution();

	int result = s->romanToInt(valStr);
	cout << "[+] Result:\t" << result << endl;

	delete s;
	return 0;
}
