#include"vector_func.h"

// 240. 搜索二维矩阵 II
bool searchMatrix(vector<vector<int>>& matrix, int target) {
	// 1. 改良暴力
	int r = matrix.size();
	int c = matrix[0].size();
	int m = 0, n = r;
	while (m<r && matrix[m][c - 1] < target) m++;
	while (n>=0 && matrix[n - 1][0] > target) n--;
	if (m > n) return false;
	for (int i = m; i < n; i++) {
		for (int j = 0; j < c; j++) {
			if (matrix[i][j] == target) return true;
		}
	}
	return false;

	// 排序算法 —— 超时
	

	//
}