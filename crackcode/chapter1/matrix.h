#ifndef __MATRIX__
#define __MATRIX__

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Matrix {
private:
        int M, N;
public:
        vector<vector<int> > data;
        Matrix(int row, int col) {
                setSize(row, col);
                vector<int> tmp(getCol());
                for (int i = 0; i < getRow(); i++) data.push_back(tmp);
                srand(time(NULL));
                for (int i = 0; i < getRow(); i++)
                for (int j = 0; j < getCol(); j++)
                        data[i][j] = rand() % 10;
        }

        void printMatrix(void);
        int getRow(void) {
                return M;
        }
	int getCol(void) {
		return N;
	}
        void setSize(int row, int col) {
        	M = row; N = col;
        }
};

void Matrix::printMatrix(void) {
        for (int i = 0; i < getRow(); i++) {
                for (int j = 0; j < getCol(); j++) {
                        std::cout << data[i][j] << "\t";
                }
                std::cout << endl;
        }
        std::cout << endl;
}

#endif
