#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
using namespace std;
class Fragile2 {
public:
	void DFS(vector<string>&graph, int start, map<int, bool>&visited) {
		queue<int> Q;
		Q.push(start);
		visited[start] = true;
		while (Q.empty() == false) {
			int size = Q.size();
			for (int i = 0; i<size; i++) {
				int index = Q.front();
				for (int j = 0; j<graph.size(); j++) {
					if (graph[index][j] == 'Y' && visited[j] == false) {
						Q.push(j);
						visited[j] = true;
					}
				}
				Q.pop();
			}
		}
	}
	int CntComp(vector<string> &graph, int n1, int n2) {
		map<int, bool> visited;
		int ret = 0;
		for (int i = 0; i<graph.size(); i++) {
			if (i == n1 || i == n2) continue;
			if (visited[i] == false) {
				DFS(graph, i, visited);
				ret++;
			}
		}
		return ret;
 	}
	void remove(vector<string>&tmp, int n1, int n2) {
		for (int i = 0; i<tmp.size(); i++) {
			if (tmp[n1][i] == 'Y') 
				tmp[n1][i] = 'N';
			if (tmp[n2][i] == 'Y')
				tmp[n2][i] = 'N';
		}
		for (int i = 0; i<tmp.size(); i++) {
			if (tmp[i][n1] == 'Y')
				tmp[i][n1] = 'N';
			if (tmp[i][n2] == 'Y')
				tmp[i][n2] = 'N';
		}
	}
	int countPairs(vector <string> graph) {
		int size = graph.size();
		int cnt = CntComp(graph, -1, -1);
		if (size == cnt) return 0;
		int ret = 0;
		for (int i = 0; i<size; i++) {
		for (int j = i+1; j<size; j++) {
			vector<string> tmp = graph;
			remove(tmp, i, j);
			int tmpCnt = CntComp(tmp, i, j);
			if (tmpCnt > cnt)
				ret++;
		}}
		return ret;
	}
};
