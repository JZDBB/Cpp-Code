#include"Search.h"

// 417. 太平洋大西洋水流问题
void dfs(vector<vector<int>>& m, int x, int y, int h, vector<vector<int>>& vec) {
	if (x < 0 || y < 0 || x == m.size() || y == m[0].size()) return;
	if (m[x][y] < h || vec[x][y]) return;
	vec[x][y] = 1;
	dfs(m, x + 1, y, m[x][y], vec);
	dfs(m, x - 1, y, m[x][y], vec);
	dfs(m, x, y + 1, m[x][y], vec);
	dfs(m, x, y - 1, m[x][y], vec);
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
	if (matrix.empty()) return {};
	int row = matrix.size();
	int col = matrix[0].size();
	vector<vector<int>> p(row, vector<int>(col, 0));
	vector<vector<int>> a(row, vector<int>(col, 0));
	for (int i = 0; i < col; i++) {
		dfs(matrix, 0, i, 0, p);
		dfs(matrix, row-1, i, 0, a);
	}
	for (int i = 0; i < row; i++) {
		dfs(matrix, i, 0, 0, p);
		dfs(matrix, i, col-1, 0, a);
	}
	vector<vector<int>> res;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (p[i][j] && a[i][j]) res.push_back({ i, j });
		}
	}
	return res;
}