/*
5.2 Given a real number between 0 and 1 (e.g., 0.72) that is passed in as a double,
   print the binary representation. If the number cannot be represented accurately
  in binary with at most 32 characters, print "ERROR."
*/

#include <iostream>

class Solution {
private:
	vector<char> results;
public:
	void convert(double real) {
		while (real > 0) {
			if (32 == results.size()) {
				std::cout << "ERROR" << endl;
				return;
			}

			real = 2 * real;
			if (real >= 1) { 
				results.push_back('1');
				real -= 1;
			} else result.push_back('0');
						
		}

		std::cout << "0." ;
		for (int i = 0; i < results.size(); i++)
			std::cout << results[i];
		
		std::cout << std::endl;
	}

	void convert_v2(double real) {
		double fac = 0.5;

		while (real > 0) {
			if (results.size() == 32) {
				std::cout << "ERROR" << std::endl;
				break;
			}

			if (real >= fac) 
				results.push_back(1);
			else results.push_back(0);
			fac = fac / 2;
		}
	}		
};
