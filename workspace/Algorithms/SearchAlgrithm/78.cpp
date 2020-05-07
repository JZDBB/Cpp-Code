#include"Search.h"

// 78. ×Ó¼¯
void dfs78(vector<int>& nums, vector<int> subset, vector<vector<int>> &ans, int start) {
	if (subset.size() == nums.size()) {
		ans.push_back(subset);
		return;
	}
	ans.push_back(subset);
	for (int i = start; i < nums.size(); i++) {
		subset.push_back(nums[i]);
		dfs78(nums, subset, ans, i + 1);
		subset.pop_back();
	}
}
vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> res;
	dfs78(nums, {}, res, 0);
	return res;
}