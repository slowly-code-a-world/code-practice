/*
7.7
Design an algorithm to find the kth number such that the only prime factors are
3,5, and 7.
*/

#include <iostream>

struct compare {
	bool operator(int i, int j) {
		return i < j;	
	}		
};

class Solution {
public:
	int find_kth(int k) {
		if (k <= 0) {
			std::cout << "ERROR" << std::endl;
			return -1;
		}

		if (1 == k) return 3*5*7;
		int cnt = 1; int start = 3*5*7;
		while (cnt < k) {
			start ++;
			if (0 == start % 3*5*7) {
				int left = start / (3*5*7);
				while (0 == left % 3) 
					left /= 3;
				if (1 == left) { 
					cnt ++;
					continue;
				}

				while (0 == left % 5)
					left /= 5;
				if (1 == left) {
					cnt ++;
					continue;
				}

				while (0 == left % 7)
					left /= 7;
				if (1 == left) {
					cnt ++;
					continue;
				}
			}
		}
		return start;		
	}

	void add_products(priority_queue<int> &queue, int tmp) {
		queue.push(tmp * 3);
		queue.push(tmp * 5);
		queue.push(tmp * 7);
	}
	
	int find_kth_v2(int k) {
		if (k <= 0) {
			std::cout << "ERROR" << endl;
			return 0;
		}

		priority_queue<int, std::vector<int>, compare> queue;
		queue.push_back(1);
		int tmp;
		for (int i = 0; i < k; i++) {
			tmp = queue.top();
			queue.pop();
			add_products(queue, tmp);
		}

		return tmp*3*5*7;
	}

	int find_kth_v3(int k) {
		if (k < 0) {
			std::cout << "ERROR" << endl;
			return 0;
		}

		vector<int> queue3, queue5, queue7;
		queue3.push(1);
		int tmp;
		for (int i = 0; i <= k; i++) {
			tmp = getmin(queue3, queue5, queue7);
			if (queue3.size() != 0 && tmp == queue3[0]) {
				queue3.push_back(3*tmp);
				queue5.push_back(5*tmp);
				queue7.push_back(7*tmp);
				queue3.erase(queue3.begin());
			} else if (queue5.size() != 0 && tmp == queue5[0]) {
				queue5.push_back(5*tmp);
				queue7.push_back(7*tmp);
				queue5.erase(queue5.begin());
			} else {
				queue7.push_back(7*tmp);
				queue7.erase(queue7.begin());
			}
		}
		return tmp*3*5*7;
	}		
};
