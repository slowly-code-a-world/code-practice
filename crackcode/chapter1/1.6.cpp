/*
Given an image represented by an NxN matrix, where each pixel in the image is 4
bytes, write a method to rotate the image by 90 degrees. Can you do this in place?
*/

#include <iostream>
#include <limits.h>
#include <time.h>
#include <vector>
#include <stdlib.h>
#include "matrix.h"

class Solution {
public:
	void rotate(Matrix &matrix, int size) {
		if (0 == size || 1 == size) return;
		int s = (matrix.getRow() - size)/2;
		for (int delta = 0; delta < matrix.getRow() - 2*s - 1; delta++) {
			int tmp = matrix.data[matrix.getRow() - 1 - s - delta][s];
			matrix.data[matrix.getRow() - 1 - s - delta][s] = matrix.data[matrix.getRow() - 1 - s][matrix.getRow() - 1 - s - delta];
			matrix.data[matrix.getRow() - 1 - s][matrix.getRow() - 1 - s - delta] = matrix.data[s + delta][matrix.getRow() - 1 - s];
			matrix.data[s + delta][matrix.getRow() - 1 - s] = matrix.data[s][s + delta];
			matrix.data[s][s + delta] = tmp;
		}
		rotate(matrix, size - 2);
	}
};

int main(void) {

	Solution S;
	Matrix m(5, 5); 
	m.printMatrix();
	S.rotate(m, m.getRow());
	m.printMatrix();	
}

