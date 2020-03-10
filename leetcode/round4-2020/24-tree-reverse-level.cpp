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
void printVectorVector(vector<vector<T>> vec) {
	cout << "[-] " << __func__ << "vec.size():\t" << vec.size() << endl;
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
	//cout << "[-] " << __func__ << endl;
	if(root) {
		TreeNode* node = root;
		//cout << __func__ << " node val:\t" << node->val << endl;
		freeTree(node->left);
		freeTree(node->right);
		//node = nullptr;	// not suitable for delete, only suitable for free
		delete node;
	}
}

class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		if(!root)
			return {};
		vector<vector<int>> ret{};
		queue<TreeNode*> q;

		TreeNode* node = root;
		q.push(root);
		int count = 1;
		int count_next = 0;
		vector<int> nums{};

		while(!q.empty()) {
			TreeNode* node = q.front();
			q.pop();
			nums.push_back(node->val);
			printVector(nums);
			if(node->left) {
				q.push(node->left);
				++count_next;
			}
			if(node->right) {
				q.push(node->right);
				++count_next;
			}
			if(--count == 0) {
				//cout << "count:\t" << count << endl;
				ret.push_back(nums);
				//printVector(nums);
				//printVectorVector(ret);
				nums = {};
				count = count_next;
				count_next = 0;
			}
		}
		if(!nums.empty())
			ret.push_back(nums);
		reverse(ret.begin(), ret.end());
		return ret;
	}
};

int main(int argc, char **argv) {

	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	Solution *s = new Solution();

	vector<vector<int>> result = s->levelOrderBottom(root);
	printVectorVector(result);

	freeTree(root);
	delete s;
	return 0;
}
