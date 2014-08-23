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
#include <stack>

struct node {
	int n;
	int id;
	char start;
	char help;
	char dest;
};

class Solution {
private:
	std::stack<struct node> s;
		
public:
	void move(int n, char start, char help, char dest) {
		struct node tmp;
		tmp.n = n; 		tmp.start = start;
		tmp.help = help; 	tmp.dest = dest;
		s.push(tmp);
		while (0 == s.empty()) {
			tmp = s.top();
			s.pop();
			int current_n = tmp.n;

			if (1 == current_n) {
				std::cout << "move disk " << tmp.id << " from " << tmp.start << " to " << tmp.dest << std::endl;
			} else {
				struct node pa, pb, pc;

	                        pa.n = current_n-1;
				pa.id = current_n-1;
	                        pa.start = tmp.help;
                                pa.help = tmp.start;
                                pa.dest = tmp.dest;
                                s.push(pa);

				pb.n = 1;
				pb.id = current_n;
				pb.start = tmp.start;
				pb.help = tmp.help;
				pb.dest = tmp.dest;
				s.push(pb);

	                        pc.n = current_n-1;
				pc.id = current_n-1;
                                pc.start = tmp.start;
                                pc.help = tmp.dest;
                                pc.dest = tmp.help;
				s.push(pc);
			}
		}
	}
};

int main(void) {

	Solution S;
	S.move(3, 'A', 'B', 'C');

	return 0;
}
