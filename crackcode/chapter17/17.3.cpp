/*
Write an algorithm which computes the number of trailing zeros in n factorial
*/

int factorial(int n, unordered_map<int, int> &map) {
	if (0 == n || 1 == n) return 1;
	if (0 != map[n]) return map[n];
	map[n] = n*factorial(n-1);

	return map[n];
}

int count_zero(int n) {
	unordered_map<int, int> map;
	int tmp = factorial(n, map);
	int cnt = 0;
	while (0 == tmp % 10) {
		tmp /= 10;
		cnt++;
	}	

	return cnt;
}

int count_zero_v2(int n) {
	int cnt5 = 0;
	for (int i = 2; i <= n; i++) {
		int tmp = i;
		while (0 == tmp % 5) {
			cnt5++;
			tmp /= 5;
		}
	}

	return cnt5;
}

int count_zero_v3(int n) {
	int cnt = 0;	
	if (n < 0) return -1;
	for (int i = 5; n/i > 0; i = i*5) {
		cnt += n/i;
	}

	return cnt;
}

