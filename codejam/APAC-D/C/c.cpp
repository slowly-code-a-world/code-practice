/*Problem

Once upon a day, Mary bought a one-way ticket from somewhere to somewhere with some flight transfers.

For example: SFO->DFW DFW->JFK JFK->MIA MIA->ORD.

Obviously, transfer flights at a city twice or more doesn't make any sense. So Mary will not do that.

Unfortunately, after she received the tickets, she messed up the tickets and she forgot the order of the ticket.

Help Mary rearrange the tickets to make the tickets in correct order.
Input

The first line contains the number of test cases T, after which T cases follow.
For each case, it starts with an integer N. There are N flight tickets follow.
Each of the next 2 lines contains the source and destination of a flight ticket.
Output

For each test case, output one line containing "Case #x: itinerary", where x is the test case number (starting from 1) and itinerary is sorted list of flight tickets which represents the actual itinerary. Each flight segment in the itinerary should be outputted as pair of source-destination airport codes.
Limits

1 ≤ T ≤ 100.
For each case, the input tickets are messed up from an entire itinerary bought by Mary. In other words, it's ensured can be recovered to a valid itinerary.
Small dataset

1 ≤ N ≤ 100.
Large dataset

1 ≤ N ≤ 104.
(The segment for second case in sample can be seen as below) MIA-ORD, DFW-JFK, SFO-DFW, JFK-MIA
Sample

Input
  	
Output
 

2
1
SFO
DFW
4
MIA
ORD
DFW
JFK
SFO
DFW
JFK
MIA

	

Case #1: SFO-DFW
Case #2: SFO-DFW DFW-JFK JFK-MIA MIA-ORD
*/

#include <iostream>
#include <vector>
#include <tr1/unordered_map>
#include <string>
using namespace std;
using namespace std::tr1;

class Solution {
private:
	unordered_map<string, string> flights;
	unordered_map<string, int> cnt;

public:
	void buildmaps(vector<string> &strs) {
		flights.clear();
		cnt.clear();
		for (int i = 0; i<strs.size(); i++) {
			cnt[strs[i]] ++;
			if (i % 2 == 0)
				flights[strs[i]] = strs[i+1];
		}
	}

	string getFlights() {
		string start, end;
		for (auto it = cnt.begin(); it != cnt.end(); it++) {
			if (it->second == 1) {
				if (flights.find(it->first) != flights.end()) 
					start = it->first;
				else end = it->first;
			}
			
		}
		string ret = "";
		while (flights[start] != end) {
			ret += start;
			ret += "-";
			ret += flights[start];
			ret += " ";
			start = flights[start];
		}
		ret += start;
		ret += "-";
		ret += end;
		return ret;
	}
};

int main(void) {
	int cases, fli;
	cin >> cases;
	vector<string> flights;
	Solution S;
	for (int i = 0; i<cases; i++) {
		cin >> fli;
		flights.clear();
		for (int j = 0; j<2*fli; j++) {
			string tmp;
			cin >> tmp;
			flights.push_back(tmp);
		}
		S.buildmaps(flights);
		string ret = S.getFlights();
		cout << "Case #" << i+1 << ": " << ret << endl;
	}
}
