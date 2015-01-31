#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
        int getMaxMultiply(vector<int>&array) {
                if (array.size() == 0) return 0;
                if (array.size() == 1) return array[0];
		vector<int> ret(array.size(), 1); 
		int fac = 1;
                for (int i = 1; i<array.size(); i++) {
			fac *= array[i-1];
			ret[i] *= fac;	
		}
		fac = 1;
		for (int i = array.size()-2; i>=0; i--) {
			fac *= array[i+1];
			ret[i] *= fac;
		}
		int retVal = INT_MIN;
		for (int i = 0; i<ret.size(); i++)
			retVal = max(ret, ret[i]);
		return retVal;
        }
};

