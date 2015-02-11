#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int totalSum (int n) {
		return (n+1)*n/2;
	}
	bool canRepresent(int n) {
		for (int i = n; i>=1; i--) {
			for (int j=1; j<i; j++) {
				if (totalSum(i) - totalSum(j) == n)
					return true;
			}
		}
		return false;
	}
};
