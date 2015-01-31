#include <iostream>
#include <vector>
#include <string>
using namespace std;
class BuildingTowers {
public:
	vector<long long> fill(long long lastVal, int s, int e, long long limit, long long LK) {
		long long maxVal = 0, newLast;
		if (s == 0) {
			long long dis = e - s;
			newLast = min(limit, dis*LK);
			for (int i = s+1; i<=e; i++) {
				dis = i - s;
				long long tmp = dis*LK; 
				dis = e - i;
				tmp = min(tmp, limit - dis*LK);
				maxVal = max(maxVal, tmp);
			}
			return {maxVal, newLast};
		}
		if (e == -1) {
			long long dis = e - s + 1;
			return {dis*LK + lastVal, 0};
		}
		long long dis = e - s + 1;
		newLast = min(limit, dis*LK);
		for (int i = s; i<=e; i++) {
			dis = i - s + 1;
			long long tmp = dis*LK;
			dis = e - i;
			tmp = min(tmp, limit - dis*LK);
			maxVal = max(maxVal, tmp);
		}
		return {maxVal, newLast};
	}
	long long maxHeight(int N, int K, vector <int> x, vector <int> t) {
		long long LN = N, LK = K;
		if (x.size() == 0) return (LN-1)*LK;
		long long ret = 0;
		vector<long long> tmp;
		for (int i = 0; i<x.size(); i++) {
			if (i == 0) {
				tmp = fill(0, 0, x[i], t[i], LK);
				ret = max(ret, tmp[0]);
			} else {
				tmp = fill(tmp[1], x[i-1]+1, x[i], t[i], LK);
				ret = max(ret, tmp[0]);
			}	
		}	
		int size = x.size();
		tmp = fill(tmp[1], x[size-1]+1, N, -1, LK);
		ret = max(ret, tmp[0]);
		return ret;
	}
};
