#include"Search.h"

// 90. ×Ó¼¯ II
void dfs(vector<int>& nums, vector<int> subset, vector<vector<int>> &ans, int start) {
	if (subset.size() == nums.size()) {
		ans.push_back(subset);
		return;
	}
	ans.push_back(subset);
	unordered_set<int> m;
	for (int i = start; i < nums.size(); i++) {
		if (m.find(nums[i]) != m.end()) {
			subset.push_back(nums[i]);
			dfs(nums, subset, ans, i + 1);
			subset.pop_back();
			m.insert(nums[i]);
		}
	}
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	vector<vector<int>> res;
	dfs(nums, {}, res, 0);
	return res;
}