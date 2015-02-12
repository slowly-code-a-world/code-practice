/*
一个字符串转成float,字符串可能是负的一百点三还有个指数E-09这样的
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
	float toFloat(string str) {
		int pos = 1;
		int firstPart = secondPart = thirdPart = -1;
		int index = pointer = 0;
		while (index < str.size()) {
			if (index == 0 && str[index] == '-') {
				pos = 0;
				pointer ++;
				index++;
			} else if (str[index == '.']) {
				firstPart = stoi(str.substr(0, index - pointer));
				index++;
				pointer = index;
			} else if (str[index] == 'E' || str[index] == 'e') {
				if (firstPart == -1) 
					firstPart = stoi(str.substr(pointer, index - pointer));
				else secondPart = stoi(str.substr(pointer, index - pointer));
				thirdPart = stoi(str.substr(index+1));
				break;
			} else index++:
		}
		if (firstPart == -1) firstPart = stoi(pointer);
		else if (secondPart == -1) secondPart = stoi(pointer);
		float ret = (float)firstPart;
		if (secondPart != -1) {
			float tmp = secondPart;
			while (tmp >= 1) tmp /= 10;
			ret += tmp;
		}	
		if (thirdPart!=-1) {
			int fac = 1;
			int times = (thirdPart > 0)? thirdPart:-thirdPart;
			for (int i = 0; i<times; i++)
				fac*=10;
			if (thirdPart > 0) ret = ret*thirdPart;
			else ret = ret/(float)thirdPart; 
		}
		return pos*ret;
		
	}
};
