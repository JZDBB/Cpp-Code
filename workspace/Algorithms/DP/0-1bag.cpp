#include"DP.h"

// 0-1±³°üÎÊÌâ
int knapsack(int W, int N, vector<int>& wt, vector<int>& val) {
	vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= W; j++) {
			if (j - wt[i] < 0) continue;
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wt[i]] + val[i]);
		}
	}
	return dp[N][W];
}