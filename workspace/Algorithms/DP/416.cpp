#include"DP.h"

// 416. 分割等和子集
bool canPartition(vector<int>& nums) {
	int sum = 0;
	for (int i : nums) sum += i;
	if (sum % 2 != 0) return false;
	int all = sum / 2;
	int n = nums.size();
	vector<vector<bool>> dp(n + 1, vector<bool>(all + 1, false));
	for (int i = 0; i <= n; i++) dp[i][0] = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= all; j++) {
			if (j - nums[i - 1] < 0) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
		}
	}
	return dp[n][all];
}