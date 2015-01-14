#include <iostream>
#include <vector>
#include <string>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;

class Solution {
public:
	bool isWinning(int count, unordered_map<int, bool>&cache) {
		if (count == 0) return false;
		if (count == 1 || count == 2 || count == 3) return true;
		if (cache.find(count)!= cache.end()) return cache[count];
		if (count - 1>=0 && !isWinning(count - 1, cache)) {
			cache[count] = true;
			return true;		
		}		
		if (count - 2>=0 && !isWinning(count - 2, cache)) {
			cache[count] = true;
			return true;
		}
		if (count - 3>=0 && !isWinning(count - 3, cache)) {
			cache[count] = true;
			return true;
		}
		cache[count] = false;
		return false;
	}
};

int main(void) {
	Solution S;
	unordered_map<int, bool> cache;
	for (int i = 0; i<20; i++) {
		if (S.isWinning(i, cache))
			cout << "W ";
		else cout << "L ";
	}
	cout << endl;
}
