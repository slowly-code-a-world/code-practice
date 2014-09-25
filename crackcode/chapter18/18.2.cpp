/*
Write a method to shuffle a deck of cards. It must be a perfect shuffle—in other
words, each of the 52! permutations of the deck has to be equally likely. Assume
that you are given a random number generator which is perfect.
*/

vector<int> shuffle(vector<int> cards) {
	vector<int> tmp;
	for (int i = 0; i < 52; i++) {
		int index = rand_generator() % cards.size();
		tmp.push_back(cards[index]);
		cards.erase(begin() + index);
	}	

	return tmp;
}

vector<int> shuffle_v2(vector<int> &cards, int i) {
	if (0 == i) return cards;
	shuffle_v2(cards, i - 1);
	int loc = rand_generator() % i;
	
	int tmp = cards[i];
	cards[i] = cards[loc];
	cards[loc] = tmp;

	return cards;	
}

void shuffle_v3(vector<int> &cards) {
	for (int i = 1; i < cards.size(); i++) {
		int loc = rand_generator() % i;
		int tmp = cards[i];
		cards[i] = cards[loc];
		cards[loc] = tmp;
	}
}
