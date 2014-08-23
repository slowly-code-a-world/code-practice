/*
3.4	
In the classic problem of the Towers of Hanoi, you have 3 rods and N disks of different
sizes which can slide onto any tower. The puzzle starts with disks sorted in ascending
order of size from top to bottom (e.g., each disk sits on top of an even larger one). You
have the following constraints:	
(A) Only one disk can be moved at a time.
(B) A disk is slid off the top of one rod onto the next rod.
(C) A disk can only be placed on top of a larger disk.
Write a program to move the disks from the first rod to the last using Stacks.
*/

#include <iostream>

class Solution {
public:
	void move(int n, char start, char help, char dest) {
		if (1 == n) {
			std::cout << "move disk " << n << " from " << start << " to " << dest << std::endl;
			return;
		}

		move(n-1, start, dest, help);
		std::cout << "move disk " << n << " from " << start << " to " << dest << std::endl;
		move(n-1, help, start, dest);
		
	}		
};

int main(void) {

	Solution S;
	S.move(3, 'A', 'B', 'C');

	return 0;
}
