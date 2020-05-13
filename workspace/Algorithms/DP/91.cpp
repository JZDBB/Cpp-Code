#include"DP.h"

// 91. ½âÂë·½·¨
int numDecodings(string s) {
	int n = s.length();
	if (s[0] == '0') return 0;
	if (n < 2) return n;
	vector<int> dp(n + 1);
	dp[0] = 1; dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (s[i - 1] == '0') {
			if (s[i - 2] == '1' || s[i - 2] == '2') dp[i] = dp[i - 2];
			else return 0;
			continue;
		}
		if ((s[i - 2] < '2' || (s[i - 2] == '2' && s[i - 1] <= '6')) && s[i - 2] != '0') dp[i] += dp[i - 2];
		dp[i] += dp[i - 1];
	}
	return dp[n];
}