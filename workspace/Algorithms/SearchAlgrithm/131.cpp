#include"Search.h"

// 131. ·Ö¸î»ØÎÄ´®
bool ispart(string s) {
	int l = 0;
	int r = s.length()-1;
	while (l <= r) {
		if (s[l++] != s[r--]) return false;
	}
	return true;
}
void dfs131(string s, vector<string> set, vector<vector<string>> &ans) {
	int len = s.length();
	if (len == 0) {
		ans.push_back(set);
		return;
	}
	for (int i = 1; i <= s.length(); i++) {
		string ss = s.substr(0, i);
		if (ispart(ss)) {
			set.push_back(ss);
			dfs131(s.substr(i), set, ans);
			set.pop_back();
		}
	}
}
vector<vector<string>> partition(string s) {
	vector<vector<string>> res;
	if (s.length()) {
		dfs131(s, {}, res);
	}
	return res;
}