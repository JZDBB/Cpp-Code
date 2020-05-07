#include"Search.h"

// 37. 解数独
vector<vector<int>> row_, col_, box_;
bool backward(vector<vector<char>>& board, int x, int y) {
	if (x == 9)
		return true;

	int ny = (y + 1) % 9;
	int nx = (ny == 0) ? x + 1 : x;

	if (board[x][y] != '.') return backward(board, nx, ny);

	for (int i = 1; i <= 9; i++) {
		int bx = x / 3;
		int by = y / 3;
		int box_key = bx * 3 + by;
		if (!row_[x][i] && !col_[y][i] && !box_[box_key][i]) {
			row_[x][i] = 1;
			col_[y][i] = 1;
			box_[box_key][i] = 1;
			board[x][y] = i + '0';
			if (backward(board, nx, ny)) return true;
			board[x][y] = '.';
			box_[box_key][i] = 0;
			col_[y][i] = 0;
			row_[x][i] = 0;
		}
	}
	return false;
}
void solveSudoku(vector<vector<char>>& board) {
	row_ = vector<vector<int>>(9, vector<int>(10));
	col_ = vector<vector<int>>(9, vector<int>(10));
	box_ = vector<vector<int>>(9, vector<int>(10));
	//预先设置剪枝条件
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			const char c = board[i][j];
			if (c != '.') {
				int n = c - '0';
				int bx = i / 3;
				int by = j / 3;
				row_[i][n] = 1;
				col_[j][n] = 1;
				box_[bx * 3 + by][n] = 1;
			}
		}
	}
	backward(board, 0, 0);
}
