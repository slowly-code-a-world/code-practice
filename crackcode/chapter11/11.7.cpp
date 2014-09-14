/*
11.7 A circus is designing a tower routine consisting of people standing atop one
    another's shoulders. For practical and aesthetic reasons, each person must be
   both shorter and lighter than the person below him or her. Given the heights
  and weights of each person in the circus, write a method to compute the largest
 possible number of people in such a tower.
EXAMPLE:
Input (ht,wt): (65, 100) (70, 150) (56, 90) (75, 190) (60, 95)
(68, 110)
Output:The longest tower is length 6 and includes from top to bottom:
(56, 90) (60,95) (65,100) (68,110) (70,150) (75,190)
*/

#include <iostream>

class Solution {
public:
	bool canbe_above(person bottom, person above) {
		return (bottom.height > above.height && bottom.weight > above.weight);
	}	

	int longest(vector<person>& group, person bottom, unordered_map<person, int>& map) {
		if (0 != map[bottom]) return map[bottom];
		int max = 0;
		for (int i = 0; i<group.size(); i++) {
			if (canbe_above(bottom, group[i])) {
				tmp = longest(group, group[i], map);
				if (tmp > max) max = tmp;
			}
		}
		map[bottom] = max + 1;
		return max + 1;	 
	}
	int get_longest(vector<person>& group) {
		if (0 == group.size()) return 0;
		if (1 == group.size()) return 1;
		unordered_map<person, int> map;
		int max = 0;
		for (int i = 0; i<group.size(); i++) {
			int tmp = longest(group, group[i], map) > max
			if (tmp > max) max = tmp;	 
		}

		return max;
	}

	int get_longest_v2(vector<person>& group) {
		if (0 == group.size()) return 0;
		if (1 == group.size()) return 1;
		sort(group.begin(), group.end(), compare);
		vector<int> table(group.size(), 1);
		for (int i = 1; i < group.size(); i++) {
			for (int j = 0; j<i; j++) {
				if (group[i].height > group[j].height)
					table[i] = max(table[i], table[j] + 1);
			}
		}
		int max = 1;
		for (int i = 0; i< table.size(); i++) 
			if (table[i] > max) max = table[i];

		return max;	
	}	
};

bool compare(person p1, person p2) {
	return p1.weight < p2.weight;	
}	
