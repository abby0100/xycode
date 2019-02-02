#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <unistd.h>

#define N	9
#define UNSOLVED	-1
using namespace std;

int array[N][N];
int sequence[N][N][N];
int row[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

int solve_sudoku();

int mylog(string info) {

	cout << endl << "[+] " << info << endl;
}

void print_array() {

	// sleep
	usleep(1000);
	// clean screen
	cout << "\033[2J \033[0m" << endl;

	for(int i = 0; i < N; ++i){
		if( i == 0 || i == 3 || i == 6) {
			cout << "-------------------" << endl;
		}
		for(int j = 0; j < N; ++j){
			if(j == 3 || j == 6) {
				cout << "|";
			}

			// print except "UNSOLVED"
			if (array[i][j] > UNSOLVED) {
				cout << array[i][j] << " ";
			} else {
				cout << " " << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

void print_sequence() {
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			if(sequence[i][j][0] > 0) {
				cout << "array[" << i << "][" << j << "] : ";
				for(int k = 0; k < N; ++k) {
					if(sequence[i][j][k] > 0) {
						cout << sequence[i][j][k] << " ";
					}
				}
				cout << endl;
			}
		}
	}
}

void init_row() {

	int random;
	int temp;
	for(int i = 0; i < 9; ++i) {
		random = rand() % 9;
		temp = row[i];
		row[i] = row[random];
		row[random] = temp;

		//for(int i = 0; i < 9; ++i) {
		//	cout << row[i] << " ";
		//}
		//cout << endl;
	}
}

void init() {

	mylog("init");
	init_row();

	cout << "\t" << "https://gamedev.stackexchange.com/questions/56149/how-can-i-generate-sudoku-puzzles" << endl << endl;

	// shift 1, 3, 3
	for(int i = 0; i < N; ++i){
		array[0][i] = row[i];
	}
	for(int i = 0; i < N; ++i){
		array[1][i] = row[(i + 3) % N];
	}
	for(int i = 0; i < N; ++i){
		array[2][i] = row[(i + 6) % N];
	}

	// shift 1, 3, 3
	for(int i = 0; i < N; ++i){
		array[3][i] = row[(i + 1) % N];
	}
	for(int i = 0; i < N; ++i){
		array[4][i] = row[(i + 4) % N];
	}
	for(int i = 0; i < N; ++i){
		array[5][i] = row[(i + 7) % N];
	}

	// shift 1, 3, 3
	for(int i = 0; i < N; ++i){
		array[6][i] = row[(i + 2) % N];
	}
	for(int i = 0; i < N; ++i){
		array[7][i] = row[(i + 5) % N];
	}
	for(int i = 0; i < N; ++i){
		array[8][i] = row[(i + 8) % N];
	}

	cout << "Init sudoku" << endl;
	print_array();

	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			for(int k = 0; k < N; ++k) {
				sequence[i][j][k] = 0;
			}
		}
	}
}

int generate_sudoku() {

	mylog("generate sudoku");
	int random;

	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			random = rand() % 9;
			if(random <= 5) {
				array[i][j] = UNSOLVED;
			}
		}
	}

	cout << "Generate sudoku" << endl;
	print_array();
}

int solve_one(int i, int j) {

	// record all the possible answer number: 1~9
	for(int k = 0; k < N; ++k) {
		sequence[i][j][k] = k + 1;
	}

	for(int m = 0; m < N; ++m) {
		// colume
		if(array[i][m] > 0) {
			sequence[i][j][array[i][m] - 1] = 0;
		}
		// row
		if(array[m][j] > 0) {
			sequence[i][j][array[m][j] - 1] = 0;
		}
		// sub sudoku
		int startx = i / 3 * 3;
		int starty = j / 3 * 3;
		int endx   = startx + 3;
		int endy   = starty + 3;
		for(int ii = startx; ii < endx; ++ii) {
			for(int jj = starty; jj < endy; ++jj) {
				if(array[ii][jj] > 0) {
					sequence[i][j][array[ii][jj] - 1] = 0;
				}
			}
		}
	}

	//array[i][j] = 0;
	print_array();

	int number = 0;
	int temp;

	// rearrange the sequence array
	for(int n = 0; n < N; ++n) {
		if(sequence[i][j][n] > 0) {
			temp = sequence[i][j][n];
			sequence[i][j][n] = 0;
			sequence[i][j][number] = temp;

			number++;
		}
	}

	if(number <= 0) {
		//cout << "Not right! Reset array[" << i << "][" << j << "]" << endl;
		array[i][j] = UNSOLVED;
		print_array();
		return -1;
	} else {
		while(number > 0) {
			//print_sequence();

			number--;
			array[i][j] = sequence[i][j][number];

			if(solve_sudoku() == -1) {
				//cout << "array[" << i << "][" << j << "] try " << sequence[i][j][number] << " failed! Try next?" << endl;
				sequence[i][j][number] = 0;
				array[i][j] = UNSOLVED;
				print_array();
			} else {
				return 0;
			}
		}
		return -1;
	}

	//return 0;
}

int solve_sudoku() {

	//mylog("solve sudoku");

	int result;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			if(array[i][j] == UNSOLVED) {
				result = solve_one(i, j);

				// failed
				if(result == -1) {
					return -1;
				} else {
					return 0;
				}
			}
		}
	}

	// all solved
	return 0;
}

int main(int argc, char** argv) {

	mylog("main");

	init();

	generate_sudoku();

	cout << "[+] solve sudoku" << endl;
	int result = solve_sudoku();
	if(result == 0) {
		print_array();
		cout << "Congratulations, you solved the sudoku!" << endl;
	}
}
