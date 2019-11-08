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
	int removeArrayElement(vector<int>& nums, int val) {
		if(nums.empty()) {
			return nums.size();
		}
		int n(nums.size());
		int i(0);
		int j(n-1);
		while(i <= j) {
			if(nums[i] == val) {
				nums[i] = nums[j];
				j--;
			} else {
				i++;
			}
		}
		return j+1;
	}
};

int main(int argc, char **argv) {

	vector<int> vec;
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(0);
	vec.push_back(4);
	vec.push_back(2);
	printVector(vec);

	Solution *s = new Solution();
	int result = s->removeArrayElement(vec, 2);
	cout << "Result: " << result << endl;
	printVector(vec);

	delete s;
	//freeList(l1);
	return 0;
}
