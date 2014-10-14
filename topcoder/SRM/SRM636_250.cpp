#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class GameOfStones {
public:
	int count(vector<int> stones) {
		if (0 == stones.size()) return 0;
		int sum = 0;
		for (int i = 0; i<stones.size(); i++) 
			sum+=stones[i];
		if (sum % stones.size() != 0) return -1;
		int avg = sum / stones.size();
		int total = 0;
		for (int i = 0; i<stones.size(); i++) {
			int test = abs(stones[i] - avg);
			if (test % 2 != 0) return -1;
			if (stones[i] > avg)
			total += stones[i] - avg;
		}	
		return total/2;
	}
};
int main(void) {
	GameOfStones S;
	vector<int> stones;
	stones.push_back(7);
	stones.push_back(15);
	stones.push_back(9);
	stones.push_back(5);
	cout << S.count(stones) << endl;
}
