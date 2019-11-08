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
	int searchInsert(vector<int>& nums, int target) {
		int ret = 0;
		if(nums.empty())
			return ret;
		for(int i = 0; i < nums.size(); ++i) {
			if(target <= nums[i]) {
				return i;
			}
			if(i == nums.size() - 1) {
				return nums.size();
			}
		}
		return ret;
	}
};

int main(int argc, char **argv) {

	Solution *s = new Solution();

	{
		vector<int> vec = {1, 3, 5, 6};
		int target = 5;
		int result = s->searchInsert(vec, target);
		cout << "[+] Result:\t" << result << endl;
	}
	{
		vector<int> vec = {1, 3, 5, 6};
		int target = 2;
		int result = s->searchInsert(vec, target);
		cout << "[+] Result:\t" << result << endl;
	}
	{
		vector<int> vec = {1, 3, 5, 6};
		int target = 7;
		int result = s->searchInsert(vec, target);
		cout << "[+] Result:\t" << result << endl;
	}
	{
		vector<int> vec = {1, 3, 5, 6};
		int target = 0;
		int result = s->searchInsert(vec, target);
		cout << "[+] Result:\t" << result << endl;
	}

	delete s;
	return 0;
}
