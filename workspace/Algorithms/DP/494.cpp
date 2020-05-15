#include"DP.h"

// 494. 目标和
void dfs(int sum, vector<int>& nums, int S, int start, int &ans) {
	if (start == nums.size()) {
		if (sum == S) ans++;
		return;
	}
	dfs(sum + nums[start], nums, S, start + 1, ans);
	dfs(sum - nums[start], nums, S, start + 1, ans);
}

int findTargetSumWays(vector<int>& nums, int S) {
	// dfs
	/*int res = 0;
	dfs(0, nums, S, 0, res);
	return res;*/

	// 动态规划
	/*vector<vector<int>> dp(nums.size(), vector<int>(2001));
	if(nums[0]==0) dp[0][1000] = 2;
    else{
        dp[0][nums[0] + 1000] = 1;
        dp[0][1000 - nums[0]] = 1;
    }
	for (int i = 1; i < nums.size(); i++) {
		for (int sum = -1000; sum <= 1000; sum++) {
			if (dp[i - 1][sum + 1000] > 0) {
				dp[i][sum + nums[i] + 1000] += dp[i - 1][sum + 1000];
				dp[i][sum - nums[i] + 1000] += dp[i - 1][sum + 1000];
			}
		}
	}
	return S > 1000 ? 0 : dp[nums.size() - 1][S + 1000];*/

	// 优化空间
	vector<int> dp((2001));
	if (nums[0] == 0) dp[1000] = 2;
	else {
		dp[nums[0] + 1000] = 1;
		dp[1000 - nums[0]] = 1;
	}
	for (int i = 1; i < nums.size(); i++) {
		vector<int> ans((2001));
		for (int sum = -1000; sum <= 1000; sum++) {
			if (dp[sum + 1000] > 0) {
				ans[sum + nums[i] + 1000] += dp[sum + 1000];
				ans[sum - nums[i] + 1000] += dp[sum + 1000];
			}
		}
		dp = ans;
	}
	return S > 1000 ? 0 : dp[S + 1000];
}