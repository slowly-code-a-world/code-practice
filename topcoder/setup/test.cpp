#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>

using namespace std;
class BusinessTasks {
public: 
	void removeOne(list<string> &newList, int n, list<string>::iterator& start) {
		int cnt = 1;
		while (cnt < n) {
			start++;
			if (start == newList.end())
				start = newList.begin();
			cnt++;
			if (cnt == n) {
				newList.erase(start);
				if (start == newList.end())
					start = newList.begin();
				return; 
			}	
		}
	}
	string getTask(vector<string> list, int n) {
		if (1 == list.size()) return list[0];
		if (1 == n) return list[list.size()-1];
		
		std::list<string> XX;
		/*
		for (int i = 0; i<list.size(); i++)
			newList.push_back(list[i]);
		list<string>::iterator start = newList.begin();
		for (;;) {
			 removeOne(newList, n, start);
			 if (newList.size() == 1)
			 	return *newList.begin();
		} */
	}
};

int main(void) {
}
