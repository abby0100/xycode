#ifndef _XY_ARRAY_H_
#define _XY_ARRAY_H_

#include <string>
#include <vector>

using namespace std;

class XYArray {
public:
        static int sort(vector<int>& array);
        static int remove_array_duplicates(vector<int>& array);
private:
	static int binary_sort(vector<int>& array, int start, int end);
};

class XYReader {
public:
	static int read_array(string path, vector<int>& array);
};

#endif
