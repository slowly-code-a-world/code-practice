/*
Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
column is set to 0.
*/

#include "matrix.h"

class Solution {
public:
	void setToZero(Matrix &m) {
		bool should_zero_col0 = false, should_zero_row0 = false; 
		for (int i = 0; i < m.getRow(); i++) {
			if (0 == m.data[i][0]) {
				should_zero_col0 = true;
				break;
			}
		}
		
		for (int i = 0; i < m.getCol(); i++) {
			if (0 == m.data[0][i]) {
				should_zero_row0 = true;
				break;
			}
		}

		for (int i = 1; i < m.getRow(); i++) {
			for (int j = 1; j < m.getCol(); j++) {
				if (0 == m.data[i][j]) {
					m.data[i][0] = 0; m.data[0][j] = 0;
				}
			}
		}

		for (int i = 1; i < m.getRow(); i++) {
			if (0 == m.data[i][0]) {
				for (int j = 1; j < m.getCol(); j++) m.data[i][j] = 0;
			}
		}	

		for (int j = 1; j < m.getCol(); j++) {
			if (0 == m.data[0][j]) {
				for (int i = 1; i < m.getRow(); i++) m.data[i][j] = 0;
			}
		}

		if (should_zero_col0) {
			for (int i = 0; i<m.getRow(); i++) m.data[i][0] = 0;
		}

		if (should_zero_row0) {
			for (int j = 0; j<m.getCol(); j++) m.data[0][j] = 0;
		}
	}
};

int main(void) {
	Matrix m(5, 6);
	Solution S;
	m.printMatrix();
	S.setToZero(m);	
	m.printMatrix();
}	
