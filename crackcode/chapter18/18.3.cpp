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
