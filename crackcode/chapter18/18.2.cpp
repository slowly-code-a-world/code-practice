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
