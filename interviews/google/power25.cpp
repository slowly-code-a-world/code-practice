#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;
struct node {
	int cost;
};
bool operator<(node n1, node n2) {return n1.cost > n2.cost;}
class Solution {
public:
	vector<int> getTopk(int k) {
		if (k == 0) return {};
		if (k == 1) return {1};
		priority_queue<node> PQ;
		unordered_map<int, bool> visited;
		visited[1] = true;
		node start;
		start.cost = 1;
		PQ.push(start);
		vector<int> ret;
		for (int i = 0; i<k; i++) {
			node top = PQ.top();
			if (!visited[top.cost*2]) {
				node n;
				n.cost = top.cost*2;
				PQ.push(n);
				visited[top.cost*2] = true;
			}
			if (!visited[top.cost*5]) {
				node n;
				n.cost = top.cost*5;
				PQ.push(n);
				visited[top.cost*5] = true;
			}
			ret.push_back(top.cost);
			PQ.pop();
		}
		return ret;
	}
};
int main(void) {
	Solution S;
	vector<int> ret = S.getTopk(10);
	for (int i = 0; i<10; i++)
		cout << ret[i] << " ";
	cout << endl;	
}
