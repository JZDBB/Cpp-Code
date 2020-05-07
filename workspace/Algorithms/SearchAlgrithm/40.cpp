#include"Search.h"

// 40. 组合总和 II
void dfs(vector<int>& candidates, int target, vector<int> sellected, vector<vector<int>> &ans, int start) {
	if (target == 0) {
		ans.push_back(sellected);
		return;
	}
	for (int i = start; i < candidates.size() && candidates[i] <= target; i++) {
		if (i > start&&candidates[i] == candidates[i - 1]) continue;
		sellected.push_back(candidates[i]);
		dfs(candidates, target - candidates[i], sellected, ans, i + 1);
		sellected.pop_back();
	}
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	vector<vector<int>> res;
	sort(candidates.begin(), candidates.end());
	dfs(candidates, target, {}, res, 0);
	return res;
}