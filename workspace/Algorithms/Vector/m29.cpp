#include"vector_func.h"

// 面试题29. 顺时针打印矩阵
vector<int> spiralOrder(vector<vector<int>>& matrix) {
	if (matrix.size() == 0 || matrix[0].size() == 0) return {};
	int left = 0;
	int right = matrix[0].size() - 1;
	int top = 0;
	int bottom = matrix.size() - 1;
	vector<int> res;
	while (1) {
		for (int i = left; i <= right; i++) res.push_back(matrix[top][i]);
		top++;
		if (top > bottom) break;
		for (int i = top; i <= bottom; i++) res.push_back(matrix[i][right]);
		right--;
		if (left > right) break;
		for (int i = right; i >= left; i--) res.push_back(matrix[bottom][i]);
		bottom--;
		if (top > bottom) break;
		for (int i = bottom; i >= top; i--) res.push_back(matrix[i][left]);
		left++;
		if (left > right) break;
	}
	return res;
}