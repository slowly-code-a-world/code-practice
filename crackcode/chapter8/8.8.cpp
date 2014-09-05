/*
8.8 Othello is played as follows: Each Othello piece is white on one side and black
   on the other. When a piece is surrounded by its opponents on both the left and
  right sides, or both the top and bottom, it is said to be captured and its color is
 flipped. On your turn, you must capture at least one of your opponent's pieces.
The game ends when either user has no more valid moves. The win is assigned
to the person with the most pieces. Implement the object-oriented design for
Othello.
*/

#include <iostream>

class board {
private:
	int unplaced;
	vector<vector<int> > map;
public:
	board() {
		for (int i = 0; i<map.size(); i++) 
			for (int j = 0; j<map[i].size(); j++)
				map[i][j] = 0;
		unplaced = map.size() * map[0].size();
	}

	void place(bool isblack, int i, int j) {
		if (i < 0 || i >= map.size()) {
			std::cout << "wrong place" << std::endl;
			return;
		}

		if (j < 0 || j >= map[0].size()) {
			std::cout << "wrong place" << std::endl;
			return;
		}

		if (0 != map[i][j]) {
			std::cout << "wrong place" << std::endl;
			return;
		}	

		if (isblack) map[i][j] = 1;
		else map[i][j] = 2;
		unplaced--;
		
		change_board(isblack, i, j);
		if (0 == unplaced) 
			std::cout << "completed" << std::endl;
	}	

	void change_board(bool isblack, int i, int j) {
		/*	
		int pieces = 0;
		for (int k = j-1; i>=0; i--) {
			if (3 != map[i][k] + map[i][j])
				break;		
		}
		if (map[i][k] == map[i][j]) {
			for (int l = k+1; l < j; l++)
				map[i][l] = isblack ? 1:2;
		} 

		for (int k = j+1; k < map[0].size(); k++) {
			if (3 != map[i][k] + map[i][j])
				break;
		}
		if (map[i][k] == map[i][j]) {
			for (int l = j+1; l < k; l++)
				map[i][l] = isblack? 1:2;
		}
		*/
	}
};

class player {
private:
	bool isblack;
public:
	bool get_color() { return isblack; }
	void set_color(bool isblack) { this->isblack = isblack; }
	void move_to (int i, int j, board& b) 
		b.place(isblack, i, j);
	bool iswin(board& b) {
		int blacks = 0, whites = 0;	
		for (int i = 0; i<b.map.size(); i++) 
			for (int j = 0; j < b.map[0].size(); j++)
				if (1 == map[i][j])
					blacks++;
				else whites++;
		if (blacks == whites) {
			std::cout << "no one wins" << std::endl;
			return false;
		}
		if (isblack)
			return blacks > whites;
		else return whites > blacks;
	}		
};

