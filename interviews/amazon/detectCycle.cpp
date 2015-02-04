#include <iostream>
#include <vector>
#include <string>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;

struct Node {
	int val;
	vector<Node*> connections;
	Node(int val) { 
		this->val = val; 
		connections.clear();
	}
};
class Solution {
public:
	bool detectCycle(Node* start, unordered_map<Node*, bool> &record) {
		if (start == NULL) return false;
		if (start->connections.size() == 0) return false;
		if (record[start]) return true;
		record[start] = true;
		for (int i = 0; i<start->connections.size(); i++) {
			bool ret = detectCycle(start->connections[i], record);
			if (ret) return true;
		}
		return false;
	}

	void cycleCounts(Node* start, unordered_map<Node*, bool> &record, int &cnt) {
		if (start == NULL) return;
		if (start->connections.size() == 0) return;
		if (record[start]) {
			cnt++;
			return;
		}
		record[start] = true;
		for (int i = 0; i<start->connections.size(); i++) 
			cycleCounts(start->connections[i], record, cnt);
	}
};

int main(void) {
	Solution S;
	Node *n0 = new Node(0);
	Node *n1 = new Node(1);
	Node *n2 = new Node(2);
	Node *n3 = new Node(3);
	n0->connections.push_back(n1);
	n0->connections.push_back(n2);
	n1->connections.push_back(n2);
	n2->connections.push_back(n0);
	n2->connections.push_back(n3);
	n3->connections.push_back(n3);
	unordered_map<Node*, bool> record;
	int ret = 0;	
	S.cycleCounts(n0, record, ret);
	cout << ret << endl;
}
