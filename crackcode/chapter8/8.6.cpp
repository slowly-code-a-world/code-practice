/*
8.6 Implement a jigsaw puzzle. Design the data structures and explain an algorithm
   to solve the puzzle. You can assume that you have a fitsWith method which,
  when passed two puzzle pieces, returns true if the two pieces belong together
*/

#include <iostream>

class jigsaw_pieces {
private:
	int id;
public:
	int getid() { return id; }
};

void solve(vector<jigsaw_pieces> jp) {
	for (int i = 0; i < jp.size(); i++) {
		for (int j = 0; j < jp.size(); j++) {
			if (fitsWith(jp[i], jp[j]) && 0 == put_together(jp[i], jp[j]))
				put_together(jp[i], jp[j]);
		}
	}

}
