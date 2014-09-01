/*
7.4 Write methods to implement the multiply, subtract, and divide operations for
   integers. Use only the add operator.
*/

class Solution {
public:
	int sub(int A, int B) {
		int ret = 0;
		return A + (-B);
	}

	int mul(int A, int B) {
		int ret = 0;
		int pos = 0;
		if (A < 0) { pos++; A = -A; }
		if (B < 0) { pos++; B = -B; }
		if (0 == pos || 2 == pos) 
			pos = 0;
		else pos = 1;
		for (int i = 0; i < B; i++)
			ret += A;
		if (0 == pos) return ret;
		else return -ret;
	}

	int div(int A, int B) {
		int ret = 0;
		int pos = 0;
		if (A < 0) { pos++; A = -A; }
		if (B < 0) { pos++; B = -B; }
		if (0 == pos || 2 == pos)
			pos = 0;
		else pos = 1;
		if (B > A) return 0;
		int sum = 0;
		while (sum <= A) {
			sum += B;
			ret ++;
		}
		ret--;
		if (0 == pos) return ret;
		else return -ret;
	}			
}
