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

class Solution {
public:
	bool isBalanced(TreeNode* root) {
		if(!root)
			return true;
		int left = getLength(root->left);
		cout << "isBalanced left:\t" << left << endl;
		if(left == -1)
			return false;
		int right= getLength(root->right);
		cout << "isBalanced right:\t" << right << endl;
		if(right == -1)
			return false;
		cout << "isBalanced abs:\t" << abs(left-right) << endl;
		if(abs(left-right) <= 1)
			return true;
		else
			return false;
	}
	int getLength(TreeNode* node) {
		if(!node)
			return 0;
		int left = getLength(node->left);
		if(left == -1)
			return -1;
		int right= getLength(node->right);
		if(right == -1)
			return -1;
		if(abs(left-right) > 1)
			return -1;
		else
			return left > right ? left + 1 : right + 1;
	}
};

int main(int argc, char **argv) {

	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right= new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	Solution *s = new Solution();

	bool result = s->isBalanced(root);

	delete s;
	return 0;
}
