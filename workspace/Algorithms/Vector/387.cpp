#include"vector_func.h"

// 378. 有序矩阵中第K小的元素
int kthSmallest(vector<vector<int>>& matrix, int k) {
	if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
	if (k == 1) return matrix[0][0];
	int n = matrix.size();
	vector<int> id(n, 0);
	int res = 0;
	for (int i = 0; i < k; i++) {
		int min_ = INT_MAX;
		int index;
		for (int j = 0; j < n; j++) {
			if (id[j] == n) continue;
			if (matrix[j][id[j]] < min_) {
				min_ = matrix[j][id[j]];
				index = j;
			}
		}
		id[index]++;
		res = min_;
	}
	return res;
}