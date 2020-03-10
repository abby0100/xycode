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
	bool isPalindrome(string s) {
		if(s.empty())
			return true;
		int i = 0, j = s.size() - 1;
		while(i <= j) {
			if(i > s.size() - 1)
				return true;
			if(j < 0)
				return true;
			if(!(s[i] >= '0' && s[i] <= '9') && !(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= 'A' && s[i] <= 'Z') ) {
				++i;
				continue;
			}
			if(!(s[i] >= '0' && s[i] <= '9') && !(s[j] >= 'a' && s[j] <= 'z') && !(s[j] >= 'A' && s[j] <= 'Z') ) {
				--j;
				continue;
			}

			cout << "s[i]:\t" << s[i] << endl;
			cout << "s[j]:\t" << s[j] << endl;

			if(s[i] >= 'A' && s[i] <= 'Z')
				s[i] += 'a' - 'A';
			if(s[j] >= 'A' && s[j] <= 'Z')
				s[j] += 'a' - 'A';

			cout << "s[i]:\t" << s[i] << endl;
			cout << "s[j]:\t" << s[j] << endl;
			if( s[i++] != s[j--])
				return false;
		}
		return true;
	}
};

int main(int argc, char **argv) {

	//string str = "A man, a plan, a canal: Panama";
	string str = "0p";
	cout << "str:\t" << str << endl;

	Solution *s = new Solution();

	bool result = s->isPalindrome(str);
	cout << "result:\t" << result << endl;

	delete s;
	return 0;
}
