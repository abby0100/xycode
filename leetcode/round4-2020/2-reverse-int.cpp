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
	int reverse_int(int x) {
		const int INT_MIN = -(1 << 31);
		const int INT_MAX = ((1 << 31) - 1) / 10;

		if (x == INT_MIN)
			return 0;
		int num = x < 0 ? -x : x;

		cout << "INT_MIN:\t" << INT_MIN << endl;
		cout << "INT_MAX:\t" << INT_MAX << endl;
		int ret = 0, ones = 0;
		while (num) {
			cout << "num:\t" << num << endl;
			if ( ret > INT_MAX )
				return 0;
			ones = num % 10;
			ret = ret * 10 + ones;
			num /= 10;
		}

		return ret = x < 0 ? -ret : ret;
	}

	int reverse(int x) {
		long num = x < 0 ? -x : x;

		long ret = 0;
		while (num) {
			cout << "num:\t" << num << endl;
			ret = ret * 10 + num % 10;
			cout << "ret:\t" << ret << endl;
			num /= 10;
		}

		ret = x < 0 ? -ret : ret;
		if (ret > ((1 << 31) - 1) || ret < -(1 << 31))
			return 0;
		return ret;
	}
};

int main(int argc, char **argv) {

	//int x = 1534236469;
	int x = -2147483648;
	Solution *s = new Solution();

	int result = s->reverse(x);
	cout << "[+] Result:\t" << result << endl;

	delete s;
	return 0;
}
