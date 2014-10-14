#include <iostream>
#include <vector>
#include <string>
using namespace std;
class SortishDiv2 {
public:
	int count(vector<int> &seq) {
		int cnt = 0;
		for (int i = 0; i<seq.size(); i++) {
			for (int j = i+1; j<seq.size(); j++) {
				if (seq[i] < seq[j]) 
					cnt++;
			}
		}
		return cnt;
	}
	void get_all(vector<int> &solution, vector<int> &mark, vector<vector<int> >&ret, int zeros) {
		if (0 == zeros) {
			ret.push_back(solution);
			return;
		}
		for (int i = 0; i<solution.size(); i++) {
			if (0 == solution[i]) {
				int fill = -1;
				for (int j = 0; j<solution.size(); j++) {
					if (mark[j] == 0) {
						mark[j] = 1;
						fill = j + 1;
						break;
					}
				}
				 
				solution[i] = fill;
				get_all(solution, mark, ret, zeros - 1);
				solution[i] = 0;
				mark[fill - 1] = 0;
			}
		}
	}
	int ways(int sortedness, vector<int> seq) {
		bool found = false;
		for (int i = 0; i<seq.size(); i++) {
			if (seq[i] == 0) {
				found = true;
				break;
			}
		}
		if (!found) {
			int tmp = count(seq);
			if (tmp == sortedness) return 1;
			return 0;
		}
		vector<int> mark(seq.size(), 0);
		vector<int> solution = seq;
		int zeros = 0;
		for (int i = 0; i<seq.size(); i++) { 
			if (seq[i] != 0) mark[seq[i] - 1] = 1;
			else zeros++;	
		}
		vector<vector<int> > ret;
		get_all(solution, mark, ret, zeros);
		for (int i = 0; i<ret.size(); i++) {
			for (int j = 0; j<ret[i].size(); j++) 
				cout << ret[i][j] << " ";
			cout <<endl;
		}
		int cnt = 0;
		for (int i = 0; i<ret.size(); i++) {
			int tmp = count(ret[i]);
			if (tmp == sortedness) 
				cnt++;
		} 
		return cnt;
	}
};

int main(void) {
	SortishDiv2 S;
	vector<int> seq;
	seq.push_back(4);
	seq.push_back(0);
	seq.push_back(0);
	seq.push_back(2);
	seq.push_back(0);
	S.ways(5, seq);
}
