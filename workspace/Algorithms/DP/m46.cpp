#include"DP.h"

// °ÑÊý×Ö·­Òë³É×Ö·û´®
int translateNum(int num) {
	if (num < 10) return 1;
	int n = num;
	vector<int> nums;
	while (n) {
		nums.insert(nums.begin(), n % 10);
		n /= 10;
	}
	vector<int> dp(nums.size() + 1, 0);
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i < dp.size(); i++) {
		if (nums[i] + nums[i - 1] * 10 <= 25) dp[i] += dp[i - 2];
		dp[i] += dp[i - 1];
	}
	return dp[dp.size() - 1];
}