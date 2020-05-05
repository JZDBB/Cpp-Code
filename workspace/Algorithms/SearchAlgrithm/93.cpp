#include"Search.h"

// 93. ¸´Ô­IPµØÖ· ¡ª¡ª »ØËİ¼ôÖ¦
void dfs(int d, string ip, string s, vector<string> &ans) {
	int len = s.length();
	if (d == 4) {
		if (len == 0) ans.push_back(ip);
		return;
	}

	for (int i = 1; i <= min(3, s[0] == '0' ? 1 : len); i++) {
		string ss = s.substr(0, i);
		if (i == 3 && stoi(ss) > 255) return;
		dfs(d + 1, ip + (d == 0 ? "" : ".") + ss, s.substr(i), ans);
	}
}

vector<string> restoreIpAddresses(string s) {
	vector<string> res;
	string ip;
	dfs(0, ip, s, res);
	return res;
}