#include"Search.h"

// 面试题12. 矩阵中的路径
bool dfs(vector<vector<char>>& board, string word, int x, int y, int index) {
	if (x < 0 || y < 0 || x == board.size() || y == board[0].size()||board[x][y]!=word[index]) return false;
	if (index == word.size() - 1) return true;
	char tmp = board[x][y];
	board[x][y] = '/';
	bool res = dfs(board, word, x, y - 1, index + 1) || 
				dfs(board, word, x, y + 1, index + 1) || 
				dfs(board, word, x - 1, y, index + 1) || 
				dfs(board, word, x + 1, y, index + 1);
	board[x][y] = tmp;
	return res;
}

bool exist(vector<vector<char>>& board, string word) {
	int row = board.size();
	int col = board[0].size();
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (dfs(board, word, i, j, 1)) return true;
		}
	}
	return false;
}

