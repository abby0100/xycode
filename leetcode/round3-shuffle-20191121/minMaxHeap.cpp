#include <iostream>
#include <vector>

using namespace std;

//template<typename T>
template<class T>
void printVector(vector<T> vec, size_t len) {
	if(vec.empty() || vec.size() < len)
		return;
	for(int idx = 0; idx < len; ++idx) {
		cout << vec[idx] << " ";
	}
	cout << endl;
}

template<class T>
void printArray(T* array, int len) {
	if(!array || len <= 0)
		return;
	for(int i = 0; i != len; ++i) {
		cout << array[i] << " ";
	}
	cout << endl;
}

struct MaxHeap {
	int *element;
	int size;
	int max;
};

class Solution {
public:
	void initHeap(struct MaxHeap& heap) {
		for(int i = heap.size / 2; i >= 1; --i) {
			cout << "Save heap element[" << i << "]:\t" << heap.element[i] << endl;
			heap.element[0] = heap.element[i];
			int son = i << 1;
			while(son <= heap.size) {
				cout << "Handle heap element[" << son << "]:\t" << heap.element[son] << endl;
				if(son + 1 <= heap.size) {
					cout << "Handle heap element[" << son+1 << "]:\t" << heap.element[son+1] << endl;
					if(heap.element[son] < heap.element[son + 1])
						son++;
				}
				if(heap.element[son] > heap.element[i]) {
					heap.element[i] = heap.element[son];
					heap.element[son] = heap.element[0];
					//heap.element[son / 2] = heap.element[0];
					son *= 2;
				}
				printArray(heap.element, heap.size);
			}
			heap.element[son / 2] = heap.element[0];
		}
	}
};

int main(int argc, char **argv) {

	//vector<int> nums {1, 1, 2, 4, 5, 5, 8};
	vector<int> nums {5, 1, 6, 4, 9, 2, 7, 3, 8};
	printVector(nums, nums.size());

	MaxHeap heap;
	heap.size = nums.size();
	heap.element = new int[heap.size + 1];
	for(int i = 1; i <= heap.size; ++i) {
		heap.element[i] = nums[i-1];
	}
	heap.element[0] = 0;
	printArray(heap.element, heap.size + 1);

	Solution s;
	s.initHeap(heap);
	printArray(heap.element, heap.size + 1);

	//cout << "[-] Result:\t" << result << endl;
	//printVector(result, result.size());

	delete [] heap.element;
	return 0;
}
