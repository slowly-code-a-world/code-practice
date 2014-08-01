/*
Given an image represented by an NxN matrix, where each pixel in the image is 4
bytes, write a method to rotate the image by 90 degrees. Can you do this in place?
*/

#include <iostream>
#include <limits.h>
#include <time.h>
#include <vector>
#include <stdlib.h>

using namespace std;

class Matrix {
private:
	int N;
public:
	vector<vector<int> > data;
	Matrix(int size) {
		setSize(size);
		vector<int> tmp(getSize());
		for (int i = 0; i < getSize(); i++) data.push_back(tmp);
		srand(time(NULL));
		for (int i = 0; i < getSize(); i++) 
		for (int j = 0; j < getSize(); j++) 
			data[i][j] = rand() % 10;		 
	}
 
	void printMatrix(void);	
	int getSize(void) {
		return N;
	}	
	void setSize(int size) {
		N = size;
	}	
};

void Matrix::printMatrix(void) {
	for (int i = 0; i < getSize(); i++) {
		for (int j = 0; j < getSize(); j++) {
			cout << data[i][j] << "\t";
		}
		cout << endl;
	}	
	cout << endl;	
}

class Solution {
public:
	void rotate(Matrix &matrix, int size) {
		if (0 == size || 1 == size) return;
		int s = (matrix.getSize() - size)/2;
		for (int delta = 0; delta < matrix.getSize() - 2*s - 1; delta++) {
			int tmp = matrix.data[matrix.getSize() - 1 - s - delta][s];
			matrix.data[matrix.getSize() - 1 - s - delta][s] = matrix.data[matrix.getSize() - 1 - s][matrix.getSize() - 1 - s - delta];
			matrix.data[matrix.getSize() - 1 - s][matrix.getSize() - 1 - s - delta] = matrix.data[s + delta][matrix.getSize() - 1 - s];
			matrix.data[s + delta][matrix.getSize() - 1 - s] = matrix.data[s][s + delta];
			matrix.data[s][s + delta] = tmp;
		}
		rotate(matrix, size - 2);
	}
};

int main(void) {

	Solution S;
	Matrix m(5); 
	m.printMatrix();
	S.rotate(m, m.getSize());
	m.printMatrix();	
}

