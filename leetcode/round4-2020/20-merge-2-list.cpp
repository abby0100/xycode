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
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = m - 1, j = n - 1;
		for(int k = m + n - 1; k >= 0; --k) {
			if(i < 0) {
				nums1[k] = nums2[j--];
				continue;
			} else if(j < 0) {
				nums1[k] = nums1[i--];
				continue;
			}
			if(nums1[i] >= nums2[j]) {
				nums1[k] = nums1[i--];
			} else {
				nums1[k] = nums2[j--];
			}
		}
	}
};

int main(int argc, char **argv) {

	int x = 123;
	Solution *s = new Solution();

	int result = s->reverse(x);
	cout << "[+] Result:\t" << result << endl;

	delete s;
	return 0;
}
