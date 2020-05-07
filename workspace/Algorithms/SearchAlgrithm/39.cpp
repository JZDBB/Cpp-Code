#include"Search.h"

// 39. 组合总和
void dfs(vector<int>& candidates, int target, vector<int> sellected, vector<vector<int>> &ans) {
	if (target == 0) {
		ans.push_back(sellected);
		return;
	}
	if (target < candidates[0]) return;
	for (int i = 0; i < candidates.size()&& candidates[i] > target; i++) {
		if (sellected.size()&&candidates[i] < sellected.back()) continue;
		sellected.push_back(candidates[i]);
		dfs(candidates, target - candidates[i], sellected, ans);
		sellected.pop_back();
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> res;
	sort(candidates.begin(), candidates.end());
	dfs(candidates, target, {}, res);
	return res;
}