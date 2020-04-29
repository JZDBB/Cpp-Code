#include"Search.h"

// 695. 岛屿的最大面积
void dfs(vector<vector<int>>& grid, int x, int y, vector<vector<int>> &visit, int &count) {
	if (x < 0 || y < 0 || x == grid.size() || y == grid[0].size() || visit[x][y]) return;
	if (grid[x][y] == 1) {
		visit[x][y] = 1;
		dfs(grid, x + 1, y, visit, count);
		dfs(grid, x - 1, y, visit, count);
		dfs(grid, x, y + 1, visit, count);
		dfs(grid, x, y - 1, visit, count);
		count++;
	}
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
	if (grid.empty()) return 0;
	int row = grid.size();
	int col = grid[0].size();
	vector<vector<int>> visit(row, vector<int>(col));
	int res = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (grid[i][j] == 1 && visit[i][j] == 0) {
				int count = 0;
				dfs(grid, i, j, visit, count);
				res = res > count ? res : count;
			}
		}
	}
	return res;
}
