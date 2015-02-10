/*
判断一个数字的二进制表示中，1的个数是不是质数
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
	int getCnt(int num) {
		int cnt = 0;
		while (num != 0) {
			if (num & 1) cnt++;
			num >>= 1;
		}
		return cnt;
	}
	bool realJudge(int num) {
		if (num <= 1) return false;
		if (num == 2) return true;
		for (int i = 2; i<=sqrt(num); i++) {
			if (num % i == 0) return false;
		}
		return true;
	}
	bool isPrime(int input) {
		int cnt = getCnt(input);
		return realJudge(cnt);
	}
};

int main(void) {
	Solution S;
	cout << S.isPrime(15) << endl;
}
