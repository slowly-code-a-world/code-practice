/*
Implement a method rand7() given rand5().That is, given a method that
generates a random number between 0 and 4 (inclusive), write a method that
generates a random number between 0 and 6 (inclusive).
*/
int rand7() {
	while (1) {
		int num = 5*rand5() + rand5();
		if (num < 21) 
			return num % 7;
	}
}

int rand7_v2() {
	while (1) {
		int r1 = 2*rand5();
		int r2 = rand5();
		if (r2 != 4) {
			int rand1 = r2%2;
			int num = r1 + rand1;
			if (num < 7) return num;
		}
	}
}
