/*
5.2 Given a real number between 0 and 1 (e.g., 0.72) that is passed in as a double,
   print the binary representation. If the number cannot be represented accurately
  in binary with at most 32 characters, print "ERROR."
*/

#include <iostream>
#define DELTA	0.0000001

class Solution {
private:
	vector<char> results;
public:
	void convert(double real) {
		for (int i = 0; i < 32; i++) {
			real = 2*real;
			if (real >= 1.0) {
				results.push_back(1);
				real -= 1.0;	
				if (real < DELTA)
					break;
			} else results.push_back(0);
		}
		if (real > DELTA) {
			std::cout << "ERROR" << std::endl;
			return;
		}

		std::cout << 0. ;
		for (int i = results.size()-1; i >=1; i--) 
			if ('0' != results[i]) 
				break;
		int size = results.size() - 1 - i;
		for (int j = 0; j < size; j++)
			results.pop_back();

		for (int i = 0; i < results.size(); i++)
			std::cout << results[i];

		std::cout << std::endl;
	}	
};
