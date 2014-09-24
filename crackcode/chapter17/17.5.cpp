/*
The Game of Master Mind is played as follows:
The computer has four slots, and each slot will contain a ball that is red (R), yellow
(Y), green (G) or blue (B). For example, the computer might have RGGB {Slot #1 is
red, Slots #2 and #3 are green, Slot #4 is blue).
You, the user, are trying to guess the solution. You might, for example, guess
YRGB.
When you guess the correct color for the correct slot, you get a "hit." If you guess
a color that exists but is in the wrong slot, you get a "pseudo-hit." Note that a slot
that is a hit can never count as a pseudo-hit.
For example, if the actual solution is RGBY and you guess GGRR, you have one
hit and one pseudo-hit.
Write a method that, given a guess and a solution, returns the number of hits
and pseudo-hits.
*/

vector<int> count(vector<char> solution, vector<char> guess) {
	vector<int> ret;
	if (0 == solution.size()) 
		return ret;
	assert(solution.size() == guess.size());
	int hits = 0, pseudo = 0;
	for (int i = 0; i<solution.size(); i++) {
		if (solution[i] == guess[i]) {
			hits ++;
			solution[i] = guess[i] = 'X';
		}
	}

	for (int i = 0; i < guess.size(); i++) {
		if ('X' != guess[i]) {
			for (int j = 0; j < solution.size(); j++) {
				if (guess[i] == solution[j]) {
					pseudo ++;
					guess[i] = 'X';
					solution[j] = 'X';
				}
			}
		}
	}

	ret.push_back(hits);
	ret.push_back(pseudo);
	
	return ret;	
}
