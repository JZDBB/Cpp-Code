#include"Search.h"

// 77. ×éºÏ
void dfs(int n, vector<int> select, vector<vector<int>> &ans, int k, int m) {
	int len = select.size();
	if (len == k) {
		ans.push_back(select);
		return;
	}

	for (int i = m; i <= n; i++) {
		select.push_back(i);
		dfs(n, select, ans, k, i + 1);
		select.pop_back();
	}
}
vector<vector<int>> combine(int n, int k) {
	vector<vector<int>> res;
	if (n >= k) {
		dfs(n, {}, res, k, 1);
	}
	return res;
}