/*
写一个函数实现两个整数相除，不用"/"和"%"，返回商和余数
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	vector<int> divide(int a, int b) {
		assert(b != 0 && a >=0 && b >= 0);
		int pos = 1;
		if (a > 0 && b < 0 || a < 0 && b > 0) 
			pos = 0;
		if (a == 0) return {0, 0};
		if (a < 0) a = -a;
		if (b < 0) b = -b;
		if (a < b) return {0, a};
		if (a == b) return {pos, 0};
		int start = 1;
		while (b*start <= a) 
			start++;
		start--;
		return {start, a - b*start}
	}
};
