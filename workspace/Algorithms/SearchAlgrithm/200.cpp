#include"Search.h"

// 200. µ∫”Ï ˝¡ø
void dfs(vector<vector<char>>& grid, int x, int y, vector<vector<int>> &visit) {
	if (x < 0 || y < 0 || x == grid.size() || y == grid[0].size()&&visit[x][y]) return;
	if (grid[x][y] == '1') {
		visit[x][y] = 1;
		dfs(grid, x + 1, y, visit);
		dfs(grid, x - 1, y, visit);
		dfs(grid, x, y + 1, visit);
		dfs(grid, x, y - 1, visit);
	}
}

int numIslands(vector<vector<char>>& grid) {
	if (grid.empty()) return 0;
	int row = grid.size();
	int col = grid[0].size();
	vector<vector<int>> visit(row, vector<int>(col));
	int res = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (grid[i][j] == '1' && visit[i][j] == 0) {
				res++;
				dfs(grid, i, j, visit);
			}
		}
	}
	return res;
}