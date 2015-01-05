#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cassert>
using namespace std;
class Sort {
private:
	vector<int> array;
public:
	Sort(vector<int> input) 
	{
		array.clear();
		array = input;
	}
	Sort() { array.clear();	}
	void bubbleSort() {
		if (array.size() <= 1) return;
		for (int i = 0; i<array.size()-1; i++) {
		for (int j = array.size()-1; j>=i+1; j--) {
			if (array[j] < array[j-1]) {
				int tmp = array[j];
				array[j] = array[j-1];
				array[j-1] = tmp;
			}
		}}
	}
	void mergeSort(int s, int e) {
		if (s >= e) return;
		int m = (s + e)/2;
		mergeSort(s, m);
		mergeSort(m+1, e);
		vector<int> tmp;
		int iter1 = s, iter2 = m+1;
		while (iter1 <= m && iter2 <= e) {
			if (array[iter1] <= array[iter2]) {
				tmp.push_back(array[iter1]);
				iter1 ++;
			} else {
				tmp.push_back(array[iter2]);
				iter2 ++;
			}
		}
		while (iter1 <= m) {
			tmp.push_back(array[iter1]);
			iter1 ++;
		}
		while (iter2 <= e) {
			tmp.push_back(array[iter2]);
			iter2 ++;
		}
		assert(tmp.size() == e - s + 1);
		for (int i = 0; i<tmp.size(); i++) 
			array[s + i] = tmp[i];
	}
	int partition(vector<int>&array, int s, int e) {
		int val = array[s];
		int ss = s, ee = e;
		while (ss < ee) {
			while (ss < ee && array[ss]<=val) ss++;
			if (ss >= ee) break;
			while (ss < ee && array[ee] > val) ee--;
			if (ss >= ee) break;
			int tmp = array[ss];
			array[ss] = array[ee];
			array[ee] = tmp;
		}
		for (int i = e; i>=s; i--) {
			if (array[i] <= val) {
				array[s] = array[i];
				array[i] = val;
				return i;
			} 
		}
	}
	void quickSort(int s, int e) {
		if (s >= e) return;
		int index = partition(array, s, e);
		quickSort(s, index-1);
		quickSort(index + 1, e);
	}
	void print() {
		for (int i = 0; i<array.size(); i++)
			cout << array[i] << " ";
		cout << endl;
	}
};

int main(void) {
	vector<int> array;
	srand(time(0));
	for (int i = 0; i<10; i++) {
		array.push_back(rand()%10);
	}
	Sort test(array);
	test.print();
	test.quickSort(0, array.size()-1);
	test.print();
}
