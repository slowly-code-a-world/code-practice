#include <string>
#include <vector>
using namespace std;

class FourStrings{
public:
	string getLeftCombine(string a, string b) {
		int minlen = min(a.size(), b.size());
		for (int index = minlen; index >=1; index--) {
			if (a.substr(a.size()-index, index) == b.substr(0, index)) {
				return a + b.substr(index);
			}
		}
		return a + b;
	}
	string getRightCombine(string a, string b) {
		return getLeftCombine(b, a);
	}
	string getMinLenCombine(string a, string b) {
		string left = getLeftCombine(a,b), right = getRightCombine(a,b);
		if (left.size() < right.size()) return left;
		return right;
	}
	
	int realwork(vector<string> tasks) {
		if (tasks.size() == 0) return 0;
		if (tasks.size() == 1) return tasks[0].size();
		if (tasks.size() == 2) return getMinLenCombine(tasks[0], tasks[1]).size();
		int ret = 1000000;
		for (int i = 0; i < tasks.size()-1; i++) {
		for (int j = i+1; j<tasks.size(); j++) {
			vector<string> tmp = tasks;
			string leftcombine = getLeftCombine(tasks[i], tasks[j]);
			tmp[i] = leftcombine; 
			tmp[j] = tmp[tmp.size()-1];
			tmp.pop_back();
			tmp = removesubstr(tmp);
			ret = min(ret, realwork(tmp));
			tmp = tasks;
			string rightcombine = getRightCombine(tasks[i], tasks[j]);
			tmp[i] = rightcombine;
			tmp[j] = tmp[tmp.size()-1];
			tmp.pop_back();
			tmp = removesubstr(tmp);
			ret = min(ret, realwork(tmp));
		}}
		return ret;
	}
	
	vector<string> removesubstr(vector<string> tasks) {
		for (int i = 0; i<tasks.size()-1;i++) {
		for (int j = i+1; j<tasks.size();j++) {
			if (tasks[i] == "X" || tasks[j] == "X") continue;
			if (tasks[i].size() <= tasks[j].size()) {
				if (tasks[j].find(tasks[i])!=string::npos) 
					tasks[i] = "X";
			} else {
				if (tasks[i].find(tasks[j])!=string::npos)
					tasks[j] = "X";
			}
		}}
		vector<string> res;
		for (int i = 0; i<tasks.size(); i++) {
			if (tasks[i] != "X") 
				res.push_back(tasks[i]);
		}
		return res;
	}
 	int shortestLength(string a, string b, string c, string d) {
		vector<string> tasks;
		tasks.push_back(a); tasks.push_back(b); tasks.push_back(c); tasks.push_back(d);
		vector<string> res = removesubstr(tasks);
		return realwork(res);
	}
};
