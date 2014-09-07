/*
9.1 A child is running up a staircase with n steps, and can hop either 1 step, 2 steps,
   or 3 steps at a time. Implement a method to count how many possible ways the
  child can run up the stairs.
*/

#include <iostream>
#include <tr1/unordered_map>

using namespace std::tr1;
using namespace std;

class Solution {
public:
	int count_ways(int n) {
		if (n <= 0) return 0;
		if (1 == n) return 1;
		if (2 == n) return 2;
		if (3 == n) return 4;
		return count_ways(n-1) + count_ways(n-2) + count_ways(n-3);	
	}	
		
	int count_ways_v2(int n, unordered_map<int, int>& map) {
		if (0 == map[n]) 
			map[n] = count_ways_v2(n-1, map) + count_ways_v2(n-2, map) + count_ways_v2(n-3, map);
		
		return map[n];
	}
};

int main(void) {
	unordered_map<int, int> map;
	map[1] = 1; map[2] = 2; map[3] = 4;
	Solution S;
	cout << S.count_ways_v2(10, map) << endl;	
	cout << S.count_ways(10) << endl;

	return 0;		
}
