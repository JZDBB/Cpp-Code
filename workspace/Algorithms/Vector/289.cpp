#include"vector_func.h"

// 289. 生命游戏
void gameOfLife(vector<vector<int>>& board) {
	int neighbors[3] = { 0, 1, -1 };
	for (int r = 0; r < board.size(); r++) {
		for (int c = 0; c < board[0].size(); c++) {
			int count = 0;
			// 八邻域解法
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (!(neighbors[i] == 0 && neighbors[j] == 0)) {
						int R = (r + neighbors[i]);
						int C = (c + neighbors[j]);

						if ((R < r && R >= 0) && (C < c && C >= 0) && (abs(board[R][C]) == 1)) {
							count += 1;
						}
					}
				}
			}
			// 规则 1 或规则 3 
			if ((board[r][c] == 1) && (count < 2 || count > 3)) {
				// -1 代表这个细胞过去是活的现在死了
				board[r][c] = -1;
			}
			// 规则 4
			if (board[r][c] == 0 && count == 3) {
				// 2 代表这个细胞过去是死的现在活了
				board[r][c] = 2;
			}

		}
	}

	for (int row = 0; row < board.size(); row++) {
		for (int col = 0; col < board[0].size(); col++) {
			if (board[row][col] > 0) board[row][col] = 1;
			else board[row][col] = 0;
		}
	}

}

