#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <map>

using namespace std;
class Solution {
public:
	void realGet(vector<int> &array, map<int, vector<int>>&record, int start, int end) {
		if (start >= end) return;
		int middle = (start + end)/2;
		realGet(array, record, start, middle);
		realGet(array, record, middle+1, end);
		vector<int> buffer(end - start + 1, 0);
		int index1 = start, index2 = middle +1;
		int index3 = 0;
		while (index1 <= middle && index2 <= end) {
			if (array[index1] <= array[index2]) {
				if (array[index1] < array[index2]) {
					for (int i = index2; i<=end; i++)
						record[array[index1]].push_back(array[i]);
				}
				buffer[index3++] = array[index1++];
			} else buffer[index3++] = array[index2++];
		}
		while (index1 <= middle)
			buffer[index3++] = array[index1++];
		while (index2 <= end)
			buffer[index3++] = array[index2++];
		for (int i = 0; i<buffer.size(); i++)
			array[start+i] = buffer[i];
	}
		
	int getMaxReverseCnt(vector<int> &array) {
		if (array.size() <= 1) return 0;
		map<int, vector<int>> record;
		realGet(array, record, 0, array.size()-1);
		int retVal = INT_MIN;
		for (auto it = record.begin(); it!=record.end(); it++) {
			cout << it->first << " " << it->second.size() << endl;
			for (int i = 0; i<it->second.size(); i++)
				cout << it->second[i] << " ";
			cout << endl;
			int size = it->second.size();
			retVal = max(retVal, size);
		}
		return retVal;
	}
};

int main(void) {
	Solution S;
	vector<int> test = {33, 25, 26, 58, 41, 59};
	cout << S.getMaxReverseCnt(test) << endl;
	for (int i = 0; i<test.size(); i++)
		cout << test[i] << " ";
	cout << endl;
}
