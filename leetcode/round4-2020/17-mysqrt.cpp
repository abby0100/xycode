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
	int mySqrt(int x) {
		if(x < 2)
			return x;
		
		int val = x, min = 0, max = 0;
		int level = 0, ret = 1;
		long long temp = 0;
		while(val) {
			level += 1;
			//cout << "level:\t" << level << endl;
			val /= 10;
		}
		while(level / 2) {
			ret *= 10;
			level -= 2;
			//cout << "ret init:\t" << ret << endl;
		}

		max = ret;
		temp = ret;
		while(true) {
			//cout << "ret:\t" << ret << endl;
			if(temp == x / ret)
				return ret;
			else if(temp > x / ret) {
				if(temp - min < 1)
					return temp -1;
				max = ret;
			} else if(temp < x / ret) {
				if(max - temp < 1)
					return temp;
				min = ret;
			}		
			temp = x / ret;
			ret = (min + max) / 2;
		}

		return ret;
	}
};

int main(int argc, char **argv) {

	int x = 123;
	Solution *s = new Solution();

	int result = s->mySqrt(x);
	cout << "[+] Result:\t" << result << endl;

	delete s;
	return 0;
}
