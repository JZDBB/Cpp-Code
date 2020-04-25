#include"Search.h"

// 1091. 二进制矩阵中的最短路径
vector<vector<int>>dir = { {0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1} };
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
	if (grid[0][0] == 1) return -1;
	int row = grid.size();
	int col = grid[0].size();
	queue<vector<int>> Q;
	Q.push({ 0, 0 });
	int len = 0;
	grid[0][0] = 2;
	while (!Q.empty()) {
		int size = Q.size();
		len++;
		for (int i = 0; i < size; i++) {
			auto point = Q.front();
			Q.pop();
			if (point[0] == row - 1 && point[1] == col - 1) return len;
			for (int j = 0; j < 8; j++) {
				int x = point[0] + dir[j][0];
				int y = point[1] + dir[j][1];
				if (x < 0 || y < 0 || x >= row || y >= col || grid[x][y]) continue;
				grid[x][y] = 2;
				Q.push({ x, y });
			}
		}
	}
	return -1;
}