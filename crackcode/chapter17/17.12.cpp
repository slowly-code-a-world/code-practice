/*
Design an algorithm to find all pairs of integers within an array which sum to a
specified value.
*/

vector<vector<int> > find_all(vector<int> array, int sum) {
	vector<vector<int> > ret;
	if (array.size() <= 1) return ret;
	sort(array.begin(), array.end());
	int start = 0, end = array.size() - 1;
	while (start < end) {
		if (array[start] + array[end] == sum) {
			vector<int> tmp;
			tmp.push_back(start);
			tmp.push_back(end);
			ret.push_back(tmp);
			tmp.clear();
		} else if (array[start] + array[end] > sum) 
			end--;
		else start ++;	
	}

	return ret;
}
