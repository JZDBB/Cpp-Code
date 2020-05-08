#include"DP.h"

// 518. 零钱兑换 II
int change(int amount, vector<int>& coins) {
	
	int n = coins.size();

	//vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
	//for (int i = 0; i <= n; i++) dp[i][0] = 1; // 边界问题
	//for (int i = 1; i <= n; i++) {
	//	for (int j = 1; j <= amount; j++) {
	//		if (j - coins[i - 1] >= 0) dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]]; // 两种之和
	//		else dp[i][j] = dp[i - 1][j];
	//	}
	//}
	//return dp[coins.size()][amount];

	// 简化 ——dp 数组的转移只和 dp[i][..] 和 dp[i-1][..] 有关
	vector<int> dp(amount + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= amount; j++) {
			if (j - coins[i] >= 0) dp[j] = dp[j] + dp[j - coins[i]];
		}
	}
	return dp[amount];
}