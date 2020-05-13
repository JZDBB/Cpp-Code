#include"Search.h"

// 491. ЕндізгађСа
void dfs(vector<int>& nums, vector<int> subset, vector<vector<int>> &ans, int start) {
	if (start == nums.size()) return;
	unordered_set<int> m;
	for (int i = start; i < nums.size(); i++) {
		if (m.find(nums[i]) != m.end()) continue;
		if (subset.size() == 0) {
			subset.push_back(nums[i]);
			dfs(nums, subset, ans, i + 1);
			subset.pop_back();
		}
		else {
			if (subset.back() <= nums[i]) {
				subset.push_back(nums[i]);
				ans.push_back(subset);
				dfs(nums, subset, ans, i + 1);
				subset.pop_back();
			}
		}
		m.insert(nums[i]);
	}
}

vector<vector<int>> findSubsequences(vector<int>& nums) {
	if (nums.size() == 0) return {};
	vector<vector<int>> res;
	dfs(nums, {}, res, 0);
	return res;
}