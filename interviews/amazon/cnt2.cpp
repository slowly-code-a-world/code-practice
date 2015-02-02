#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	int twoCnts(int m) {
		int ret = 0;
		while (m > 0) {
			if (m % 10 == 2) ret++;
			m /= 10;
		}
	}
	int getTwos(int n) {
		int ret = 0;
		for (int i = 1; i<=n; i++) {
			ret += twoCnts(i);
		}
		return ret;
	}
};
