/*
Given an array of integers, write a method to find indices m and n such that if you
sorted elements m through n, the entire array would be sorted. Minimize n - m
(that is, find the smallest such sequence).
EXAMPLE
Input: 1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19
Output: (3, 9)
*/

pair<int, int> find(vector<int> array) {
	pair<int, int> ret = make_pair(-1, -1);
	if (array.size() <= 1) 
		return res;

	vector<int> tmp = array;
	sort(tmp.begin(), tmp.end());
	int m = 0, n = array.size() - 1;
	while (m < array.size() && tmp[m] == array[m]) m++;
	if (m == array.size()) return ret;

	while (n >=0 && tmp[n] == array[n]) n--;
	if (n < 0) return ret;

	assert(m < n);
	return make_pair(m, n);	
}
