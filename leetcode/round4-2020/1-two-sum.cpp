#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

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
	vector<int> twoSum_array(vector<int>& nums, int target) {
		vector<int> ret{};
		if (nums.size() < 2)
			return ret;

		vector<int> source(nums);
		printVector(source);

		std::sort(source.begin(), source.end());
		int i = 0, j = source.size() - 1;
		while (i < j) {
			if(source[i] + source[j] < target)
				i++;
			else if (source[i] + source[j] == target) {
				for(int k = 0; k < nums.size(); ++k) {
					if (source[i] == nums[k] || source[j] == nums[k])
						ret.push_back(k);
				}
				break;
			} else {
				j--;
			}
		}

		return ret;
	}

	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ret{};
		int length = nums.size();
		if (length < 2)
			return ret;

		unordered_map<int, int> map{};
		for (int i = 0; i < length; ++i) {
			if (map.find(target - nums[i]) == map.end()) {
				map[nums[i]] = i;
			} else if (map[target - nums[i]] == i) {
				continue;
			} else {
				ret.push_back(i);
				ret.push_back(map[target - nums[i]]);
			}
		}
		return ret;
	}
};

int main(int argc, char **argv) {

	vector<int> nums{3,2,4};
	//int target = 16;

	Solution *s = new Solution();
	//vector<int> result = s->twoSum(nums, target);

	if (argc > 1) {
		cout << "[+] target:\t" << atoi(argv[1]) << endl;
		vector<int> result = s->twoSum(nums, atoi(argv[1]));
		printVector(result);
	}

	delete s;
	return 0;
}
