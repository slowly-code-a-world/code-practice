/*
Write a method to count the number of 2s that appear in all the numbers
between 0 and n (inclusive).
EXAMPLE
Input: 25
Output: 9 (2,12,20,21,22,23, 24 and 25. Note that 22 counts for two 2s.)
*/

int count_twos(int n) {
	if (n <= 1) return 0;
	int cnt = 0;
	for (int i = 2; i<=n; i++) {
		int tmp = i;
		while (tmp > 0) {
			if (2 == tmp % 10) 
				cnt++;
			tmp = tmp / 10;
		}
	}
		
	return cnt;
}
