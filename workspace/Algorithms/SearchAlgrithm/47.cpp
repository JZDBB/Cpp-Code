#include"Search.h"

// 47. х╚ееап II
void dfs(vector<int> nums, vector<int> select, vector<vector<int>> &ans) {
	int len = nums.size();
	if (len == 0) {
		ans.push_back(select);
		return;
	}
	unordered_set<int> m;
	for (int i = 0; i < nums.size(); i++) {
		int a = nums[i];
		if (m.find(a) == m.end()) {
			select.push_back(a);
			nums.erase(nums.begin() + i);
			dfs(nums, select, ans);
			nums.insert(nums.begin() + i, a);
			select.pop_back();
			m.insert(nums[i]);
		}
	}
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
	vector<vector<int>> res;
	if (nums.size() != 0) {
		dfs(nums, {}, res);
	}
	return res;
}