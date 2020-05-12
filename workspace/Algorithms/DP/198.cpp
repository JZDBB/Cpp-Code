#include"DP.h"

// 198. 打家劫舍
int rob(vector<int>& nums) {
	int n = nums.size();
	if (n == 0) return 0;
	if (n == 1) return nums[0];
	vector<int> dp(n + 1);
	dp[0] = 0;
	dp[1] = nums[0];
	for (int i = 2; i <= n; i++) {
		dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
	}
	return dp[n];
}

// 213. 打家劫舍 II
int robRange(vector<int>& nums, int start, int end) {
	int dp_0 = 0;
	int dp_1 = 0;
	int dp_2 = 0;
	for (int i = start; i <= end; i++) {
		dp_2 = max(dp_1, dp_0 + nums[i]);
		dp_0 = dp_1;
		dp_1 = dp_2;
	}
	return dp_2;
}

int rob2(vector<int>& nums) {
	int n = nums.size();
	if (n == 0) return 0;
	if (n == 1) return nums[0];
	return max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
}

// 337. 打家劫舍 III
unordered_map<TreeNode*, int> map;
int rob3(TreeNode* root) {
	if (!root) return 0;
	if (map.find(root) != map.end()) return map[root];
	int do_it = root->val + (root->left ? rob3(root->left->left) + rob3(root->left->right) : 0) + (root->right ? rob3(root->right->left) + rob3(root->right->right) : 0);
	int not_do = rob3(root->left) + rob3(root->right);
	int res = max(do_it, not_do);
	map[root] = res;
	return res;
}


// 337. 打家劫舍 III-2
vector<int> dp(TreeNode* root) {
	if (!root) return { 0, 0 };
	vector<int> left = dp(root->left);
	vector<int> right = dp(root->right);
	int do_it = root->val + left[0] + right[0];
	int not_do = max(left[0], left[1]) + max(right[1], right[0]);
	return { not_do, do_it };
}
int rob(TreeNode* root) {
	vector<int> res = dp(root);
	return max(res[0], res[1]);
}

