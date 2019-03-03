#include <iostream>
#include <unistd.h>
#include <queue>

#define N	132
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
struct TreeNode {
	int val;
	int seq;
	int leftHeight;
	int rightHeight;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), seq(-1), leftHeight(0), rightHeight(0), left(nullptr), right(nullptr) {}
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

	//cout << "update_tree_seq " << endl;
	int n = shift;
	if(root == nullptr) {
		return n;
	}

	if(root->left) {
		n = update_tree_seq(root->left, n);
		n++;
	}
	cout << root->val << ":" << n << " (" << root->leftHeight << ", " << root->rightHeight << ")" << endl;
	//cout << "update_tree_seq " << endl;
	root->seq = n;

	if(root->right) {
		n = update_tree_seq(root->right, n + 1);
	}

	return n;
}

void print_tree() {

	//cout << "print_tree " << endl;
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

	//cout << "print_tree_hierarchy " << root->val << endl;

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

int subtreeDepth(TreeNode *root) {

	if(root == nullptr) {
		return 0;
	}

	int leftHeight = 0;
	int rightHeight = 0;

	if(root->left) {
		leftHeight = subtreeDepth(root->left);
	}
	if(root->right) {
		rightHeight = subtreeDepth(root->right);
	}

	root->leftHeight = leftHeight;
	root->rightHeight = rightHeight;

	if(leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) {
		return -1;
	} else {
		return leftHeight >= rightHeight ? leftHeight + 1 : rightHeight + 1;
	}
}

bool isBalancedTree(TreeNode *root) {

	cout << root->val << " Is balanced tree: ";

	if(subtreeDepth(root) == -1) {
		cout << "no" << endl;
	} else {
		cout << "yes" << endl;
	}

}

void init() {

	mylog("init");

	ListNode *p = new ListNode(-1);
	for(int i = 0; i < N; ++i) {
		p->next = new ListNode(rand() % 100);
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
		isBalancedTree(th);
		print_tree_hierarchy(th);
		p = p->next;
	}
}

vector<TreeNode *> generate_tree_all(int start, int end) {

	vector<TreeNode *> subtree;

	if(start > end) {
		subtree.push_back(nullptr);
		return subtree;
	}

	for(int i = start; i <= end; ++i) {

		cout << "i: " << i << endl;

		vector<TreeNode *> leftSubTree  = generate_tree_all(start, i - 1);
		vector<TreeNode *> rightSubTree = generate_tree_all(i + 1, end);

		for(auto left : leftSubTree) {
			for(auto right : rightSubTree) {
				TreeNode *root = new TreeNode(i);
				root->left = left;
				root->right = right;
				subtree.push_back(root);

				cout << "root: " << root->val << endl;
				cout << "leftHeight: " << root->leftHeight << endl;
				cout << "rightHeight: " << root->rightHeight << endl;
				cout << "left: " << (left != nullptr) << endl;
				cout << "right: " << (right != nullptr) << endl;
				print_tree_hierarchy(root);
			}
		}
	}

	return subtree;
}

void generate_tree2(TreeNode*& root, int n) {

	cout << "generate_tree2 for " << n << endl;
	if(n <= 0) {
		return;
	}

	generate_tree_all(1, n);

	//int start = 1;
	//int end = n;

	//for(int i = start; i <= end; ++i) {
	//	cout << "pivot: " << i << endl;
	//	root = new TreeNode(i);
	//	generate_tree_all(root->left, start, i - 1);
	//	generate_tree_all(root->right, i + 1, end);
	//	print_tree_hierarchy(th);
	//}
}

int main(int argc, char** argv) {

	mylog("main");

	init();

	//generate_tree();
	generate_tree2(th, 3);
	return 0;
}
