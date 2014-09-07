/*
9.10 You have a stack of n boxes, with widths wi, heights hi and depths di. The boxes
    cannot be rotated and can only be stacked on top of one another if each box
   in the stack is strictly larger than the box above it in width, height, and depth.
  Implement a method to build the tallest stack possible, where the height of a
 stack is the sum of the heights of each box.
*/

#include <iostream>

class Solution {
public:
	bool can_put(vector<box> &solution, box b) {
		assert(solution.size() >= 1);
		int size = solution.size();
		return b.width < solution[size - 1].width && b.height < solution[size - 1].height && b.depth < solution[size - 1].depth;
	}	
	void get_max(vector<box> &boxes, vector<bool> &visited, vector<box> &solution, int &max) {
		bool found = false;
		for (int i = 0; i<boxes.size(); i++) {
			if (false == visited[i] && can_put(solution, boxes[i])) {
				visited[i] = true;
				solution.push_back(boxes[i]);
				get_max(boxes, visited, solution, max);
				solution.pop_back();
				visited[i] = false;		
				if (false == found) found = true;
			}
		}

		if (false == found) {
			int sum = 0;
			for (int i = 0; i<solution.size(); i++)
				sum+= solution[i].height;
			if (sum > max) max = sum;
		}
	}	
	int max_height(vector<box> boxes) {
		if (0 == boxes.size()) return 0;
		if (1 == boxes.size()) return boxes[0].height;
		vector<bool> visited(boxes.size(), false);
		int max = 0, tmp;
		vector<box> solution;
		for (int i = 0; i<boxes.size(); i++) {
			tmp = 0;
			solution.clear();
			solution.push_back(boxes[i]);
			visited[i] = true;
			get_max(boxes, visited, solution, tmp);
			if (tmp > max) max = tmp;
		}

		return max;	
	}
};

