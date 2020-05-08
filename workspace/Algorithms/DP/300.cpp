#include"DP.h"

// 300. 最长上升子序列
int lengthOfLIS(vector<int>& nums) {
	vector<int> dp(nums.size());
	int res = 0;
	dp[0] = 1;
	for (int i = 1; i < dp.size(); i++) {
		int index = i - 1;
		while (index >= 0) {
			if (nums[index] < nums[i]) {
				dp[i] = max(dp[index] + 1, dp[i]);
			}
			index--;
		}
		dp[i] = max(1, dp[i]);
		res = res < dp[i] ? dp[i] : res;
	}
	return res;
	
	// 拓展——扑克牌思想
	vector<int> top(nums.size());
	int piles = 0;
	for (int i = 0; i < nums.size(); i++) {
		// 要处理的扑克牌
		int poker = nums[i];
		/***** 搜索左侧边界的二分查找 *****/
		int left = 0, right = piles;
		while (left < right) {
			int mid = (left + right) / 2;
			if (top[mid] > poker) {
				right = mid;
			}
			else if (top[mid] < poker) {
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		// 没找到合适的牌堆，新建一堆
		if (left == piles) piles++;
		// 把这张牌放到牌堆顶
		top[left] = poker;
	}
	// 牌堆数就是 LIS 长度
	return piles;
	
}


