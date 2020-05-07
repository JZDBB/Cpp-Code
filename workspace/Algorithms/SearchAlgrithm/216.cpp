#include"Search.h"

// 216. 组合总和 III
void dfs(int k, int target, vector<int> sellected, vector<vector<int>> &ans, int start) {
	if (target == 0 && sellected.size() == k) {
		ans.push_back(sellected);
		return;
	}
	for (int i = start; i < 10 && i <= target; i++) {
		sellected.push_back(i);
		dfs(k, target - i, sellected, ans, i + 1);
		sellected.pop_back();
	}
}
vector<vector<int>> combinationSum3(int k, int n) {
	vector<vector<int>> res;
	dfs(k, n, {}, res, 1);
	return res;
}