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
	bool isValidSudoku(vector<vector<char>>& board) {
		if(board.empty())
			return true;
		
	}
};

int main(int argc, char **argv) {

	vector<vector<char>> board = {
		'5', '3', '.',		'.', '7', '.',		'.', '.', '.',
		'6', '.', '.',		'1', '9', '5',		'.', '.', '.',
		'.', '9', '8',		'.', '.', '.',		'.', '6', '.',

		'8', '.', '.',		'.', '6', '.',		'.', '.', '3',
		'4', '.', '.',		'8', '.', '3',		'.', '.', '1',
		'7', '.', '.',		'.', '2', '.',		'.', '.', '6',

		'.', '6', '.',		'.', '.', '.',		'2', '8', '.',
		'.', '.', '.',		'4', '1', '9',		'.', '.', '5',
		'.', '.', '.',		'.', '8', '.',		'.', '7', '9',
	};
	//printVector()



	Solution *s = new Solution();
	bool result = s->isValidSudoku(board);
	cout << "[+] Result:\t" << result << endl;

	delete s;
	return 0;
}
