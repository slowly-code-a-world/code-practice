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
                for (int i = 0; i<array.size()-1; i++) {
			fac *= array[i];
			ret[i+1] = fac;	
		}
		fac = 1;
		int retVal = ret[ret.size()-1];
		for (int i = array.size()-1; i>=1; i--) {
			fac *= array[i];
			ret[i-1] *= fac;
			retVal = max(retVal, ret[i-1]);
		}
		return retVal;
        }
};

int main(void) {
	Solution S;
	vector<int> test = {-1,-2,3};
	cout << S.getMaxMultiply(test) << endl;
}
