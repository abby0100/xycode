#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <unistd.h>
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
void printVectorArray(vector<vector<T>> vec) {
	//cout << "[-] " << __func__ << endl;
	int N =3;
	for(int i = 0; i < vec.size(); ++i) {
		for(int j = 0; j < vec[0].size(); ++j) {
			cout << vec[i][j] << " ";
			if((j + 1) % N == 0) {
				cout << "\t";
			}
		}
		cout << endl;
		if((i+1) % N == 0) {
			cout << endl;
		}
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
	bool solveSudoku(vector<vector<char>>& board) {
		int spaces = 0;
		for(auto &row : board) {
			for(auto &column : row) {
				if('.' == column) {
					++spaces;
				}
			}
		}
		//cout << "Spaces:\t" << spaces << endl;

		int currCount = spaces;
		while(spaces > 0) {
			for(int i = 0; i < board.size(); ++i) {
				for(int j = 0; j < board[0].size(); ++j) {
					if('.' != board[i][j]) {
						//cout << "---> (" << i << ", " << j << ") val:\t, continue..." << board[i][j] << endl;
						continue;
					} else {
						vector<int> sequence(9, 0);
						// check column
						for(int k = 0; k < board.size(); ++k) {
							if('.' != board[k][j]) {
								sequence[board[k][j] - '1'] = 1;
							}
						}
						// check row
						for(int m = 0; m < board[0].size(); ++m) {
							if('.' != board[i][m]) {
								sequence[board[i][m] - '1'] = 1;
							}
						}
						// check sub-boxes
						int n_i = i / 3 * 3;
						int n_j = j / 3 * 3;
						for(int p = n_i; p < n_i + 3; ++p) {
							for(int q = n_j; q < n_j + 3; ++q) {
								if('.' != board[p][q]) {
									sequence[board[p][q] - '1'] = 1;
								}
							}
						}
						// check sequence
						int count = 0;
						int position = -1;
						for(int s = 0; s < sequence.size(); ++s) {
							if(0 == sequence[s]) {
								++count;
								if (count > 1) {
									break;
								} else {
									position = s;
								}
							}
						}
						if(1 == count) {
							//cout << "Found 1 number in " << spaces << " spaces:\t" << (position + 1) << endl;
							board[i][j] = '1' + position;
							printVectorArray(board);
							--spaces;
							cout << spaces << " Spaces left" << endl;
							sleep(1);
						}
					}
				}
			}
			if(currCount > spaces) {
				currCount = spaces;
			} else {
				// Cannot fill cell now, let's guess
				
			}
		}
		return true;
	}

	bool isValidSudoku(vector<vector<char>>& board) {
		if(board.empty())
			return true;
		// validate row
		for(int i = 0; i < board.size(); ++i) {
			vector<int> sequence(10, 0);
			for(int j = 0; j < board.size(); ++j) {
				if(board[i][j] == '.')
					continue;
				int idx = board[i][j] - '0';
				if(sequence[idx] == 0) {
					sequence[idx] = 1;
				} else {
					return false;
				}
			}
		}
		// validate column
		for(int i = 0; i < board.size(); ++i) {
			vector<int> sequence(10, 0);
			for(int j = 0; j < board[0].size(); ++j) {
				if(board[j][i] == '.')
					continue;
				int idx = board[j][i] - '0';
				if(sequence[idx] == 0) {
					sequence[idx] = 1;
				} else {
					return false;
				}
			}
		}
		// validate sub-sudoku
		for(int i = 0; i < board.size() / 3; ++i) {
			for(int j = 0; j < board[0].size() / 3; ++j) {
				vector<int> sequence(10, 0);
				for(int k = 0; k < board.size(); ++k) {
					int idx_i = i*3 + k/3;
					int idx_j = j*3 + k%3;
					if(board[idx_i][idx_j] == '.')
						continue;
					int idx = board[i*3 + k/3][j*3 + k%3] - '0';
					if(sequence[idx] == 0) {
						sequence[idx] = 1;
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

	//vector<vector<char>> board = {
	//	{'5', '3', '.',		'.', '7', '.',		'.', '.', '.'},
	//	{'6', '.', '.',		'1', '9', '5',		'.', '.', '.'},
	//	{'.', '9', '8',		'.', '.', '.',		'.', '6', '.'},

	//	{'8', '.', '.',		'.', '6', '.',		'.', '.', '3'},
	//	{'4', '.', '.',		'8', '.', '3',		'.', '.', '1'},
	//	{'7', '.', '.',		'.', '2', '.',		'.', '.', '6'},

	//	{'.', '6', '.',		'.', '.', '.',		'2', '8', '.'},
	//	{'.', '.', '.',		'4', '1', '9',		'.', '.', '5'},
	//	{'.', '.', '.',		'.', '8', '.',		'.', '7', '9'},
	//};
	vector<vector<char>> board = {
		{'.','.','9',	'7','4','8',	'.','.','.'},
		{'7','.','.',	'.','.','.',	'.','.','.'},
		{'.','2','.',	'1','.','9',	'.','.','.'},

		{'.','.','7',	'.','.','.',	'2','4','.'},
		{'.','6','4',	'.','1','.',	'5','9','.'},
		{'.','9','8',	'.','.','.',	'3','.','.'},

		{'.','.','.',	'8','.','3',	'.','2','.'},
		{'.','.','.',	'.','.','.',	'.','.','6'},
		{'.','.','.',	'2','7','5',	'9','.','.'},
	};

	printVectorArray(board);

	Solution *s = new Solution();
	//bool result = s->isValidSudoku(board);
	bool result = s->solveSudoku(board);
	cout << "[+] Result:\t" << result << endl;

	delete s;
	return 0;
}
