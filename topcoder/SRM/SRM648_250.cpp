#include <iostream>
#include <vector>
#include <string>
using namespace std;
class KitayutaMart2 {
public:
	int get(int cnt, int K) {
		if (cnt == 0) return K;
		int fac = 1;
		for (int i = 0; i<cnt; i++)
			fac *= 2;
		return fac*K;	
	}
	int numBought(int K, int T) {
		if (K == T) return 1;
		int cnt = 0, sum = 0;
		while (sum < T) {
			sum += get(cnt, K);
			cnt++;
		}
		return cnt;
	}
};
