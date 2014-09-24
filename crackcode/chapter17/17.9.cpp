/*Design a method to find the frequency of occurrences of any given word in a
book.*/

// use hash map;

void construct_hash(unordered_map<string, int> &map, vector<string>& books) {
	for (int i = 0; i < books.size(); i++) {
		map[books[i]]++;
	}
}
