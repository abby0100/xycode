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
	int search(vector<int> nums, int target) {
		int ret = -1;
		if (nums.size() == 0)
			return ret;

		int start = 0;
		int end = nums.size() - 1;
		int mid = (start + end) / 2;
		if (start == end) {
			return target == nums[start] ? 0 : ret;
		}

		while (start < end) {
			cout << "----------------------------------------------" << endl;
			cout << "start num[" << start << "]\t" << nums[start] << endl;
			cout << "mid   num[" << mid << "]\t" << nums[mid] << endl;
			cout << "end   num[" << end << "]\t" << nums[end] << endl;
			if (target > nums[mid]) {
				if (nums[mid] > nums[start]) {
					start = mid + 1;
					mid = (start + end) / 2;
				} else if (nums[mid] < nums[start]) {
					if (target < nums[start]) {
						start = mid + 1;
						mid = (start + end) / 2;
					} else if (target == nums[start]) {
						return start;
					} else if (target > nums[start]) {
						start = start + 1;
						end = mid - 1;
						mid = (start + end) / 2;
					}
				}
			} else if (target == nums[mid]) {
				return mid;
			} else {
				if (nums[mid] > nums[start]) {
					if (target < nums[start]) {
						start = mid + 1;
						mid = (start + end) / 2;
					} else if (target == nums[start]) {
						return start;
					} else if (target > nums[start]){
						start = start + 1;
						end = mid - 1;
						mid = (start + end) / 2;
					}
				} else {
					start = start + 1;
					end = mid - 1;
					mid = (start + end) / 2;
				}
			}
		}
		return ret;
	}
};

int main(int argc, char **argv) {

	vector<int> nums;
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(7);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(2);
	printVector(nums);

	//int target = 0;
	int target = 3;
	cout << "[+] target: " << target << endl;

	Solution *s = new Solution();
	int result = s->search(nums, target);
	cout << "[+] result: " << result << endl;

	delete s;
	return 0;
}
