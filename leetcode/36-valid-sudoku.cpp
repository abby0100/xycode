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
		// validate row
		for(int i = 0; i < board.size(); ++i) {
			vector<int> seqence(10, 0);
			//printVector(seqence);
			for(int j = 0; j < board.size(); ++j) {
				if(board[i][j] == '.')
					continue;
				int idx = board[i][j] - '0';
				//cout << "isValidSudoku (" << i << ", " << j << "), idx " << idx << " seqence[idx]: " << seqence[idx] << endl;
				if(seqence[idx] == 0) {
					seqence[idx] = 1;
				} else {
					return false;
				}
			}
		}
		// validate column
		for(int i = 0; i < board.size(); ++i) {
			vector<int> seqence(10, 0);
			for(int j = 0; j < board[0].size(); ++j) {
				if(board[j][i] == '.')
					continue;
				int idx = board[j][i] - '0';
				//cout << "isValidSudoku (" << j << ", " << i << "), idx " << idx << " seqence[idx]: " << seqence[idx] << endl;
				if(seqence[idx] == 0) {
					seqence[idx] = 1;
				} else {
					return false;
				}
			}
		}
		// validate sub-sudoku
		for(int i = 0; i < board.size() / 3; ++i) {
			for(int j = 0; j < board[0].size() / 3; ++j) {
				vector<int> seqence(10, 0);
				for(int k = 0; k < board.size(); ++k) {
					int idx_i = i*3 + k/3;
					int idx_j = j*3 + k%3;
					if(board[idx_i][idx_j] == '.')
						continue;
					//cout << "isValidSudoku (" << idx_i << ", " << idx_j << "), idx " << " board[][]: " << board[idx_i][idx_j] << endl;
					int idx = board[i*3 + k/3][j*3 + k%3] - '0';
					//cout << "isValidSudoku (" << j << ", " << i << "), idx " << idx << " seqence[idx]: " << seqence[idx] << endl;
					if(seqence[idx] == 0) {
						seqence[idx] = 1;
					} else {
						return false;
					}
				}					
			}
		}
		return true;
	}
};

int main(int argc, char **argv) {

	vector<vector<char>> board = {
		{'5', '3', '.',		'.', '7', '.',		'.', '.', '.'},
		{'6', '.', '.',		'1', '9', '5',		'.', '.', '.'},
		{'.', '9', '8',		'.', '.', '.',		'.', '6', '.'},

		{'8', '.', '.',		'.', '6', '.',		'.', '.', '3'},
		{'4', '.', '.',		'8', '.', '3',		'.', '.', '1'},
		{'7', '.', '.',		'.', '2', '.',		'.', '.', '6'},

		{'.', '6', '.',		'.', '.', '.',		'2', '8', '.'},
		{'.', '.', '.',		'4', '1', '9',		'.', '.', '5'},
		{'.', '.', '.',		'.', '8', '.',		'.', '7', '9'},
	};
	for(auto item : board) {
		printVector(item);
	}

	Solution *s = new Solution();
	bool result = s->isValidSudoku(board);
	cout << "[+] Result:\t" << result << endl;

	delete s;
	return 0;
}
