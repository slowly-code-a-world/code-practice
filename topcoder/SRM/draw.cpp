#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Target {
public:
	void draw_details(int n, int ltx, int lty, int rbx, int rby, vector<string> &ret) {
		for (int i = lty; i<rby; i++)
			ret[ltx][i] = '#';
		for (int i = ltx; i<rbx; i++)
			ret[i][rby] = '#';
		for (int i = rby; i>lty; i--)
			ret[rbx][i] = '#';
		for (int i = rbx; i>ltx; i--)
			ret[i][lty] = '#';
		if (n == 5) {
			ret[(ltx + rbx)/2][(lty + rby)/2] = '#';
			return;
		}	
		draw_details(n-4, ltx+2, lty + 2, rbx - 2, rby-2, ret);
	
	}
	vector<string> draw(int n) {
		vector<string> ret;
		string tmp = "";
		for (int i = 0; i<n; i++) 
			tmp+=' ';
		for (int i = 0; i<n; i++)
			ret.push_back(tmp);		
		draw_details(n, 0, 0, n-1, n-1, ret);
		return ret;
	}	
};
