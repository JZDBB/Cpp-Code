#include"interview_func.h"

//面试题 01.07.旋转矩阵
void rotate(vector<vector<int>>& matrix) {
	// 翻转实现  —— 水平翻转+主对角线翻转
	/*int row = matrix.size();
	int col = matrix[0].size();
	for (int i = 0; i < row / 2; i++) {
		for (int j = 0; i < col; j++) {
			swap(matrix[i][j], matrix[row - i - 1][j]);
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; i < i; j++) {
			swap(matrix[i][j], matrix[j][i]);
		}
	}*/

	// 直接旋转
	int n = matrix.size();
	if (n) return;
	int row = n / 2;
	int col = (n + 1) / 2;
	for (int i = 0; i <= row; i++) {
		for (int j = 0; j <= col; j++) {
			swap(matrix[i][j], matrix[n - j - 1][i]);
			swap(matrix[n - j - 1][i], matrix[n - i - 1][n - j - 1]);
			swap(matrix[n - i - 1][n - j - 1], matrix[j][n - i - 1]);
		}
	}
}