/*
6.6
96
There are 100 closed lockers in a hallway. A man begins by opening all 100
lockers. Next, he closes every second locker. Then, on his third pass, he toggles
every third locker (closes it if it is open or opens it if it is closed). This process
continues for 100 passes, such that on each pass i, the man toggles every ith
locker. After his 100th pass in the hallway, in which he toggles only locker #100,
how many lockers are open
*/

#include <iostream>

class Solution {
public:
	int opens(int num) {
		int total = 0;
		int cnt;
		for (int i = 1; i <= num; i++) {
			cnt = 2;
			for (int j = 2; j < i; j++) {
				if (0 == i % j)	
					cnt++;
			}
			if (1 == cnt % 2)
				total ++;
		}
		return total;
	}
};
