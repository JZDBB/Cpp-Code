#include"DP.h"

// 5. 最长回文子串
vector<int> countLength(string s, int left, int right) {
	while (left >= 0 && right < s.size() && s[left] == s[right]) {
		left--;
		right++;
	}
	return { right - left - 1, left + 1 };
}
string longestPalindrome(string s) {
	if (s.size() < 2) return s;

	// DP
	int n = s.size();
	vector<vector<bool>> dp(n, vector<bool>(n, false));
	string ans;
	for (int l = 0; l < n; ++l) {
		for (int i = 0; i + l < n; ++i) {
			int j = i + l;
			if (l == 0) {
				dp[i][j] = 1;
			}
			else if (l == 1) {
				dp[i][j] = (s[i] == s[j]);
			}
			else {
				dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
			}
			if (dp[i][j] && l + 1 > ans.size()) {
				ans = s.substr(i, l + 1);
			}
		}
	}

	// 中心扩展
	int len = 1;
	string res;
	for (int i = 1; i < s.size(); i++) {
		vector<int> v1 = countLength(s, i - 1, i + 1);
		vector<int> v2;
		if (s[i - 1] == s[i]) v2 = countLength(s, i - 1, i);
		else if (s[i + 1] == s[i])v2 = countLength(s, i, i + 1);
		else v2 = {0, 0};
		if (v1[0] < v2[0]) swap(v1, v2);
		if (len < v1[0]) {
			len = v1[0];
			res = s.substr(v1[1], v1[0]);
		}
	}
	return res;
}