#include <stdlib.h>
#include <stdio.h>

int power(int m, int n) {
	if (n == 0) return 1;
	if (m == 0) return 0;
	if (m == 1) return 1;
	if (n == 1) return m;
	if (n % 2 == 0) {
		int tmp = power(m, n/2);
		return tmp*tmp;
	}
	int tmp = power(m, (n-1)/2);
	return tmp*tmp*m;
}
