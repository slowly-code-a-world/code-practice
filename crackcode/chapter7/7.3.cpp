/*
7.3 Given two lines on a Cartesian plane, determine whether the two lines would
intersect.
*/

#include <iostream>

class Solution {
public:
	bool intersect(double a1, double b1, double c1, double a2, double b2, double c2) {
		if ((a1 == 0 && b1 == 0) || (a2 == 0 && b2 == 0)) {
			std::cout << "ERROR" << std::endl;
			return;
		}	

		if ((b1 == 0 && b2 != 0) || (b1 != 0 && b2 == 0)) 
			return true;

		if (b1 == 0 && b2 == 0) {
			if (c1/a1 == c2/a2) return true;
			return false;
		}

		if (a1/b1 != a2/b2) return true;
		if (c1/b1 == c2/b2) return true;
		return false;
	}
};
