/*
There are n coins in a line. Two players take turns to take a coin from one of the 
ends of the line until there are no more coins left. The player with the larger 
amount of money wins. Assume that you go first, describe an algorithm to compute 
the maximum amount of money you can win. */

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
class Solution {
public:
	int getMax(vector<int> coins, int s, int e, map<pair<int, int>, int> &cache) {
		if (s == e) return coins[s];
		if (e == s + 1) return max(coins[s], coins[e]);
		if (cache[make_pair(s, e)] !=0)
			return cache[make_pair(s, e)];
		int part1 = coins[s] + min(getMax(coins, s+2, e, cache), getMax(coins, s+1, e-1, cache));
		int part2 = coins[e] + min(getMax(coins, s+1, e-1, cache), getMax(coins, s, e-2, cache));
		cache[make_pair(s, e)] = max(part1, part2);
		return cache[make_pair(s, e)];
	}
};

int main(void) {
	Solution S;
	vector<int> coins = {8, 15, 3, 7};
	int size = coins.size();
	map<pair<int, int>, int> cache;
	cout << S.getMax(coins, 0, size - 1, cache) << endl;
}
