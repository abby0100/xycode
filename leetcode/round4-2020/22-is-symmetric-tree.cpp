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

class Solution {
public:
	//bool isMirror(TreeNode* p, TreeNode* q) {
	//	if(!p && !q)
	//		return true;
	//	if(!p || !q)
	//		return false;
	//	return p->val == q->val && isMirror(p->left, q->right) && isMirror(p->right, q->left);
	//}

	//bool isSymmetric(TreeNode* root) {
	//	if(!root)
	//		return true;
	//	else
	//		return isMirror(root->left, root->right); 
	//}

	bool isSymmetric(TreeNode* root) {
		if(!root)
			return true;
		stack<TreeNode*> st;
		st.push(root->left);
		st.push(root->right);

		TreeNode* p;
		TreeNode* q;
		while(st.size() >= 2) {
			//cout << "isSymmetric stack size:\t" << st.size() << endl;
			p = st.top();
			st.pop();
			q = st.top();
			st.pop();
			if(!p && !q)
				continue;
			if(!p || !q)
				return false;
			if(p->val != q->val)
				return false;
			st.push(p->left);
			st.push(q->right);
			st.push(p->right);
			st.push(q->left);
		}
		if(st.size() == 0)
			return true;
		else
			return false;
	}
};

int main(int argc, char **argv) {

	TreeNode* p = new TreeNode(1);

	Solution *s = new Solution();

	bool result = s->isSymmetric(p);
	cout << "[+] Result:\t" << result << endl;

	delete s;
	return 0;
}
