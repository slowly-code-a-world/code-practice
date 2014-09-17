/*
How would you measure the time spent in a context switch?
*/
#include <iostream>

int main() {
	unsigned long start = time();
	for (int i = 0; i<1000000; i++)
		sleep(1);
	unsigned long interval = time() - start;
	cout << (interval/1000000 - 1000000)/2 << endl;
}
