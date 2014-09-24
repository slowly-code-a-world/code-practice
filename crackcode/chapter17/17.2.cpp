/*
Design an algorithm to figure out if someone has won a game of tic-tac-toe.
win return 1, lose return -1, otherwise return 0
*/

 win(vector<vector<char> >&board, int player_id) {
	assert(3 == board.size());
	assert(3 == board[0].size());
	for (int i = 0; i < 3; i++) {
		if ('o' == board[i][0] && 'o' == board[i][1] && 'o' == board[i][2])
			return (0 == player_id)? 1 : -1;
		if ('x' == board[i][0] && 'x' == board[i][1] && 'x' == board[i][2])
			return (0 == player_id)? -1 : 1;
	}

	for (int i = 0; i < 3; i++) {
		if ('o' == board[0][i] && 'o' == board[1][i] && 'o' == board[2][i])
			return (0 == player_id)? 1 : -1;
		if ('x' == board[0][i] && 'x' == board[1][i] && 'x' == board[2][i])
			return (0 == player_id)? -1 : 1;
	}

	if ('o' == board[0][0] && 'o' == board[1][1] && 'o' == board[2][2])
		return (0 == player_id)? 1 : -1;
	if ('x' == board[0][0] && 'x' == board[1][1] && 'x' == board[2][2])
		return (0 == player_id)? -1 : 1;

	if ('o' == board[2][0] && 'o' == board[1][1] && 'o' == board[0][2])
		return (0 == player_id)? 1 : -1;
	if ('x' == board[2][0] && 'x' == board[1][1] && 'x' == board[0][2])
		return (0 == player_id)? -1 : 1;

	return 0;
}
