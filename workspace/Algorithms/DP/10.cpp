#include"DP.h"

// 10. 正则表达式匹配

bool isMatch(string s, string p) {
	// 递归版
	/*if (p.empty()) return s.empty();
	auto first_match = !s.empty() && (s[0] == p[0] || p[0] == '.');
	if (p.length() >= 2 && p[1] == '*') {
		return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
	}
	else return first_match && isMatch(s.substr(1), p.substr(1));*/

	// 迭代版

	int m = s.size();
	int n = p.size();
	vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
	dp[0][0] = true;
	for (int i = 0; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (j > 1 && p[j - 1] == '*') {
				bool first_match = i>0&&(s[i - 1] == p[j - 2] || p[j - 2] == '.');
				dp[i][j] = dp[i][j - 2] || (first_match &&dp[i - 1][j]);
			}
			else dp[i][j] = i>0&&dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
		}
	}
	return dp[m][n];
}