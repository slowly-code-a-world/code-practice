/*
Problem

There exists a straight line along which cities are built.

Each city is given a number starting from 1. So if there are 10 cities, city 1 has a number 1, city 2 has a number 2,... city 10 has a number 10.

Different buses (named GBus) operate within different cities, covering all the cities along the way. The cities covered by a GBus are represented as 'first_city_number last_city_number' So, if a GBus covers cities 1 to 10 inclusive, the cities covered by it are represented as '1 10'

We are given the cities covered by all the GBuses. We need to find out how many GBuses go through a particular city.
Input

The first line contains the number of test cases (T), after which T cases follow each separated from the next with a blank line.
For each test case,
The first line contains the number of GBuses.(N)
Second line contains the cities covered by them in the form
a1 b1 a2 b2 a3 b3...an bn
where GBus1 covers cities numbered from a1 to b1, GBus2 covers cities numbered from a2 to b2, GBus3 covers cities numbered from a3 to b3, upto N GBuses.
Next line contains the number of cities for which GBus count needs to be determined (P).
The below P lines contain different city numbers.
Output

For each test case, output one line containing "Case #Ti:" followed by P numbers corresponding to the number of cities each of those P GBuses goes through.

Limits

1 <= T <= 10
ai and bi will always be integers.
Small dataset

1 <= N <= 50
1 <= ai <= 500, 1 <= bi <= 500
1 <= P <= 50
Large dataset

1 <= N <= 500
1 <= ai <= 5000, 1 <= bi <= 5000
1 <= P <= 500
Sample

Input
  	

2
4
15 25 30 35 45 50 10 20
2
15
25

10
10 15 5 12 40 55 1 10 25 35 45 50 20 28 27 35 15 40 4 5
3
5
10
27



Output
 

Case #1: 2 1
Case #2: 3 3 4



Explanation for case 1:
2 GBuses go through city 15 (GBus1 [15 25] and GBus4 [10 20])
1 GBus goes through city 25 (GBus1 [15 25]) 
*/
#include <iostream>
#include <vector>
#include <string>
#include <tr1/unordered_map>

using namespace std;
using namespace std::tr1;

class Solution {
private:
	unordered_map<int, int> map;
public:
	int build(vector<pair<int, int>> &buses) {
		map.clear();
		for (int i = 0; i<buses.size(); i++) {
			pair<int, int> tmp = buses[i];
			for (int j = tmp.first; j<=tmp.second; j++)
				map[j]++;
		}
	}

	int search(int city) {
		return map[city];
	}
};

int main(void) {
	int cases, busCnt, searches;
	Solution S;
	cin >> cases;
	vector<pair<int, int>> buses;
	for (int i = 0; i<cases; i++) {
		buses.clear();
		cin >> busCnt;
		pair<int, int> tmp;
		for (int j = 0; j<busCnt; j++) {
			cin >> tmp.first >> tmp.second;
			buses.push_back(tmp);
		}
		//for (int j = 0; j<busCnt; j++) {
		//	cout << buses[i].first << " " << 
		//}
		S.build(buses);
		cin >> searches;
		cout << "Case #" << i + 1 << ": ";
		int city;
		for (int j = 0; j<searches-1; j++) {
			cin >> city;
			cout << S.search(city) << " "; 
		}
		cin >> city;
		cout << S.search(city) << endl;
	}
}




