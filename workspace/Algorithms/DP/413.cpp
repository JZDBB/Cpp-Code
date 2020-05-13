#include"DP.h"

// 413. 等差数列划分
int numberOfArithmeticSlices(vector<int>& A) {
	int dp = 0;
	int total = 0;
	for (int i = 2; i < A.size(); i++) {
		if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
			dp++;
		}
		else {
			dp = 0;
		}
		total += dp;
	}
	return total;
}