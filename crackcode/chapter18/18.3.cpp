/*
Write a method to randomly generates set of m integers from an array of size n.
Each element must have equal probability of being chosen.
*/

vector<int> get(int m, vector<int> &array) {
	vector<int> ret;
	srand(time(NULL));
	for (int i = 0; i<m; i++) {
		ret.push_back(vector[rand() % array.size()]);
	}

	return ret;
}

vector<int> get_v2(int m, vector<int> &array) {
	vector<int> ret;
	if (m > array.size()) return ret;
	if (m == array.size()) return array;
	for (int i = 0; i<m; i++)
		ret.push_back(array[i]);
	for (int i = m; i<array.size(); i++) {
		int loc = rand() % i;
		if (loc < m) 
			ret[loc] = array[i];
	}	 

	return ret;
}
