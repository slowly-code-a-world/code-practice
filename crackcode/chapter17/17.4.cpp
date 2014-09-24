/*
Write a method which finds the maximum of two numbers. You should not use
if-else or any other comparison operator.
*/

int find_max(int a, int b) {
	return (abs(a - b) + a + b)/2;
}

int find_min(int a, int b) {
	return (a + b - abs(a - b))/2;
}

int flip(int bit) { return 1 ^ bit; }
int sign(int a) { return flip((a >> 31) & 1) }
int find_max(int a, int b) {
	int c = a - b;
	int sa = sign(a);
	int sb = sign(b);
	int sc = sign(c);

	int use_sign_of_a = sa ^ sb;
	int use_sign_of_c = flip(sa ^ sb);
	int k = use_sign_of_a * sa + use_sign_of_c * sc;
	return a * k + b * flip(k);	
}
