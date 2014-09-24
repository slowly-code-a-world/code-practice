/*
Write a function that adds two numbers. You should not use + or any arithmetic
operators.
*/

int sum(int a, int b) {
	int ret = 0;
	int carry = 0
	while (a != 0 && b != 0) {
		if ((a & 1) && (b & 1)) {
			if (0 == carry)  carry = 1;
			else {
				carry = 1;
				ret |= 1 << loc;
			}
		} else if ((a & 1) || (b & 1)) {
			if (0 == carry) 
				ret |= 1 << loc;
			else 
				carry = 1;
		} else {
			if (1 == carry) {
				carry = 0;
				ret |= 1 << loc;
			}
		}
		a >>= 1;
		b >>= 1;
	}
	return ret;
}
