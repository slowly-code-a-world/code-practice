/*
给你一个很大的数据流如何track median，相信看过cracking the interview的都能答上来，两个heap 一个max 一个min。
接下来又问，如果我想得到(n/10)th element怎么办。一时糊涂脑袋没反应过来，就说加几个heap分段track。放下电话脑袋才转过来。
其实median就是求(n/2)th element。 只要改变min heap 和max heap 的size比例就可以了。让max heap的大小是min heap的1/9,就可以了。
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
class Solution {
public:
	int insert(int elem, priority_queue<int>&first, priority_queue<int,vector<int>, greater<int>>&second) {
	}
	int getMin(vector<int> &array) {
		priority_queue<int> firstHalf;
		priority_queuq<int, vector<int>, greater<int>> secondHalf;
		vector<int> ret;
		for (int i = 0; i<array.size(); i++) {
			int tmp = insert(array[i], firstHalf, secondHalf);
			ret.push_back(tmp);
		}
		return ret;	
	}
};
