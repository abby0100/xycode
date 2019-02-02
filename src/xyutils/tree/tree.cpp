#include <iostream>
#include <unistd.h>
#include <queue>

#define N	137
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
struct TreeNode {
	int val;
	int seq;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), seq(-1), left(nullptr), right(nullptr) {}
};

ListNode *lh;
TreeNode *th;

queue<TreeNode*> q;
vector<TreeNode *> line;
vector<vector<TreeNode *>> treeNodes;

int mylog(string info) {

        cout << endl << "[+] " << info << endl;
}

void print_list() {

	ListNode *p = lh;
	while(p != nullptr) {
		if(p == lh) {
			cout << "# " << p->val;
		} else {
			cout << " -> " << p->val;
		}
		p = p->next;
	}
	cout << endl;
}

int update_tree_seq(TreeNode *root, int shift) {

	int n = shift;
	if(root->left) {
		n = update_tree_seq(root->left, n);
		n++;
	}
	if(root->right) {
		update_tree_seq(root->right, n + 1);
	}

	cout << root->val << ":" << n << endl;
	root->seq = n;

	return n;
}

void print_tree() {

	int blanks = 0;
	update_tree_seq(th, 0);

	int rows = treeNodes.size();
	for(int i = 0; i < rows; ++i) {
		int columns = treeNodes[i].size();

		int k = 0;
		for(int j = 0; j < columns; ++j) {
			for(; k < treeNodes[i][j]->seq; ++k) {
				cout << " ";
			}
			cout << treeNodes[i][j]->val;
			k++;
		}
		cout << endl;

		vector<TreeNode *>().swap(treeNodes[i]);
	}
	vector<vector<TreeNode *>>().swap(treeNodes);
}

void print_tree_hierarchy(TreeNode *root) {

	if(root == nullptr) {
		return;
	}

	int currentLevel = 0;
	int nextLevel = 0;

	TreeNode *p = root;

	queue<TreeNode*> q;
	q.push(p);
	currentLevel++;

	while(!q.empty()) {
		TreeNode* node = q.front();

		if(node->left) {
			//cout << " ";
			q.push(node->left);
			nextLevel++;
		}
		if(node->right) {
			q.push(node->right);
			nextLevel++;
		}

		line.push_back(node);
		q.pop();
		currentLevel--;

		if(currentLevel == 0) {
			//cout << endl;
			currentLevel = nextLevel;
			nextLevel = 0;

			treeNodes.push_back(line);
			//line.clear();
			vector<TreeNode *>().swap(line);
		}
	}

	print_tree();
	return;
}

void init() {

	mylog("init");

	ListNode *p = new ListNode(-1);
	for(int i = 0; i < N; ++i) {
		p->next = new ListNode(rand() % 10);
		p = p->next;
		if(lh == nullptr) {
			lh = p;
		}
	}

	print_list();
}

/*
 * * : pointer
 * *&: change pointer(root) itself
 *
 */
void insert_list_to_tree(TreeNode*& root, int number) {

	if(root == nullptr) {
		root = new TreeNode(number);
		cout << "create a new tree node: " << number << endl;
	} else if(number == root->val) {
		cout << number << " already existed, skip..." << endl;
	} else if(number < root->val) {
		insert_list_to_tree(root->left, number);
	} else {
		insert_list_to_tree(root->right, number);
	}
}

int generate_tree() {

	ListNode *p = lh;
	while(p != nullptr) {
		insert_list_to_tree(th, p->val);
		print_tree_hierarchy(th);
		p = p->next;
	}
}

int main(int argc, char** argv) {

	mylog("main");

	init();

	generate_tree();
	return 0;
}
