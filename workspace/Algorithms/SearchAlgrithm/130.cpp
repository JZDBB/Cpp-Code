#include"Search.h"

// 130. ±»Î§ÈÆµÄÇøÓò
void dfs(vector<vector<char>>& board, vector<vector<int>>& vec, int x, int y) {
	if (x < 0 || y < 0 || x == board.size() || y == board[0].size()) return;
	if (board[x][y] == 'O'&& vec[x][y] != 1) {
		vec[x][y] = 1;
		dfs(board, vec, x + 1, y);
		dfs(board, vec, x - 1, y);
		dfs(board, vec, x, y + 1);
		dfs(board, vec, x, y - 1);

	}
}

void solve(vector<vector<char>>& board) {
	if (board.empty()) return;
	int row = board.size();
	int col = board[0].size();
	vector<vector<int>> vec(row, vector<int>(col));
	for (int i = 0; i < row; i++) {
		if (board[i][0] == 'O') dfs(board, vec, i, 0);
		if (board[i][col - 1] == 'O') dfs(board, vec, i, col);
	}
	for (int i = 0; i < col; i++) {
		if (board[0][i] == 'O') dfs(board, vec, 0, i);
		if (board[row - 1][i] == 'O') dfs(board, vec, row - 1, i);
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (vec[i][j] != 1) board[i][j] = 'X';
		}
	}
}
