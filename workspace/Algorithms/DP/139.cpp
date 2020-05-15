#include"DP.h"

// 139. 单词拆分
unordered_set<string> wdict;
bool dfs(int u, string s) {
	if (u == s.size()) return true;
	for (int i = u; i < s.size(); i++)
		if (wdict.count(s.substr(u, i - u + 1)) && dfs(i + 1, s))
			return true;
	return false;
}
bool wordBreak(string s, vector<string>& wordDict) {
	if (s == "") return false;
	for (auto i : wordDict) wdict.insert(i);
	// dfs 超时
	return dfs(0, s);

	// 动态规划
	vector<bool> dp(s.size() + 1, false);
	dp[0] = true;
	for (int i = 1; i <= s.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (dp[j]&&wdict.find(s.substr(j, i-j)) != wdict.end()) {
				dp[i] = true; // substr用法,s.substr(pos, n), n为长度
				break;
			}
		}
	}
	return dp[s.size()];
}