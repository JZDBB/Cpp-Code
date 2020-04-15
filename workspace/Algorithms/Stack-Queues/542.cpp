#include"Queue.h"

// 542. 01 æÿ’Û
vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
	int index_x[] = { 0, 0, -1, 1 };
	int index_y[] = { -1, 1, 0, 0 };
	int row = matrix.size();
	int col = matrix[0].size();
	vector<vector<int>> travered(row, vector<int>(col, 0));
	vector<vector<int>> res(row, vector<int>(col, 0));
	queue<pair<int, vector<int>>> Q;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (matrix[i][j] == 0) {
				Q.push(pair<int, vector<int>>(0, { i, j }));
				travered[i][j] = 1;
				res[i][j] = 0;
			}
		}
	}
	while (!Q.empty()) {
		int size = Q.size();
		for (int i = 0; i < size; i++) {
			int len = Q.front().first;
			int x = Q.front().second[0];
			int y = Q.front().second[1];
			Q.pop();
			for (int j = 0; j < 4; j++) {
				int dx = x + index_x[j];
				int dy = y + index_y[j];
				if (dx < 0 || dx >= row || dy < 0 || dy >= col) continue;
				if (travered[dx][dy]) continue;
				else {
					travered[dx][dy] = 1;
					res[dx][dy] = len + 1;
					Q.push(pair<int, vector<int>>(len + 1, { dx, dy }));
				}
			}
		}
	}
	return res;
}