/*
3.1	 Describe how you could use a single array to implement three stacks.
*/

#include <iostream>

using namespace std;

#define SIZE	1024
class Solution {
private:
	int array[SIZE];
	int lefttop;
	int rightmiddle;
	int rightbottom;
public:
	Solution() {
		lefttop = -1;
		rightbottom = SIZE;
		rightmiddle = 2*SIZE/3;
	}		

	void push(int element, int stack) {
		if (0 == stack) {
			if (lefttop == SIZE/3) {
				cout << "left stack has been full" << endl;
				return;
			}

			lefttop++;
			array[lefttop] = element;

			return;
		}
	
		if (1 == stack) {
			if (rightmiddle == SIZE/3) {
				cout << "middle stack has been full" << endl;
				return;
			}

			rightmiddle --;
			array[rightmiddle] = element;

			return;
		}	

		if (2 == stack) {
			if (rightbottom == 2*SIZE/3) {
				cout << "right stack has been full" << endl;
				return;
			} 
			rightbottom --; 
			array[rightbottom] = element;
		}
	}

	int* pop(int stack) {
		if (0 == stack) {
			if (-1 == lefttop) {
				cout << "no element to pop" << endl;
				return NULL;
			}
			lefttop--;
			return &array[lefttop + 1];
		}

		if (1 == stack) {
			if (2*SIZE/3 == rightmiddle) {
				cout << "no element to pop" << endl;
				return NULL;
			}
			rightmiddle++;
			return &array[rightmiddle-1];
		}

		if (2 == stack) {
			if (SIZE == rightbottom) {
				cout << "no element to pop" << endl;
				return NULL;
			}
			rightbottom++;
			return &array[rightbottom-1];	
		}
	}
};

