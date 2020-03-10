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
void printVectorVector(vector<vector<T>> vec) {
	//cout << "[-] " << __func__ << endl;
	for(int i = 0; i < vec.size(); ++i) {
		for(int j = 0; j < vec[i].size(); ++j)
			cout << vec[i][j] << " ";
		cout << endl;
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

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
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

void freeTree(TreeNode* root) {
	cout << "[-] " << __func__ << endl;
	if(root) {
		TreeNode* node = root;
		cout << __func__ << " node val:\t" << node->val << endl;
		freeTree(node->left);
		freeTree(node->right);
		//node = nullptr;	// not suitable for delete, only suitable for free
		delete node;
	}
}

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
	vector<int> nums{};
    
    void push(int x) {
		nums.push_back(x);
    }
    
    void pop() {
		if(nums.empty())
			return;
		//vector.erase(nums.end() - 1);
		nums.erase(nums.end() - 1);
    }
    
    int top() {
		if(nums.empty())
			return -1;
		return nums[nums.size() - 1];
    }
    
    int getMin() {
		if(nums.empty())
			return -1;
		int min = nums[0];
		for(int i = 0; i < nums.size(); ++i)
			if(nums[i] < min)
				min = nums[i];
		return min;
    }
};

class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		unsigned int val = 0;
		unsigned int temp = 0;
		for(int i = 0; i < 32; ++i) {
			temp = n & 0x01;
			cout << "reverseBits temp[" << i << "]:\t" << temp << endl;
			val = val << 1;
			cout << "reverseBits val1:\t" << val << endl;
			val = val | temp;
			cout << "reverseBits val2:\t" << val << endl;
			n >>= 1;
		}
		return val;
	}
};

int main(int argc, char **argv) {

	Solution *s = new Solution();

	uint32_t result = s->reverseBits(43261596);

	delete s;
	return 0;
}
