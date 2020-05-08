#include"Search.h"

// 221. 最大正方形
int maximalSquare(vector<vector<char>>& matrix) {
	if (matrix.size() < 1) return 0;
	if (matrix[0].size() < 1) return 0;
	int row = matrix.size();
	int col = matrix[0].size();
	int res = 0;
	for (int x = 1;x < row; x++) {
		for (int y = 1; y < col; y++) {
			if (matrix[x - 1][y - 1]!='0' && matrix[x - 1][y]!='0' && matrix[x][y - 1]!='0'&&matrix[x][y]!='0') {
				matrix[x][y] = matrix[x - 1][y - 1] + 1;
			}
			res = matrix[x][y]-'0' > res ? matrix[x][y]-'0' : res;
		}
	}
	return res * res;
}