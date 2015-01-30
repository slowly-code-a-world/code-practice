#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;
class Solution {
public:
	int gcd(int a, int b) {
		if (a < b) return gcd(b, a);
		if (0 == b) return a;
		if (a % 2 == 0 && b % 2 == 0)
			return 2*gcd(a/2, b/2);
		else if (a % 2 == 0)
			return gcd(a/2, b);
		else if (b % 2 == 0)
			return gcd(a, b/2);
		else return gcd(b, a - b);	
	}
};

int main(void) {
	int num1, num2;
	cin >> num1 >> num2;
	Solution S;
	if (num1 >= num2) 
		cout << S.gcd(num1, num2) << endl;
	else cout << S.gcd(num2, num1) << endl;
	return 0;
}
