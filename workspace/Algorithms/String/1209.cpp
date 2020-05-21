#include"string_func.h"

// 1209. 删除字符串中的所有相邻重复项 II
string removeDuplicates(string s, int k) {
	if (k == 1) return "";

	// 超时
	/*string ans = "";
	while (true) {
		for (int i = 0; i < s.size()-1; i++) {
			if (s[i] == s[i + 1]) {
				int m = i;
				while (m < s.size() && s[m] == s[i]) m++;
				if (m - i >= k) {
					ans = s.substr(0, i) + s.substr(i + k);
					break;
				}
			}
		}
		if (ans=="") break;
		else {
			s = ans;
			ans = "";
		}
	}
	return s;*/

	// 计数器
	vector<int> count(s.size());
	for (int i = 0; i < s.size(); i++) {
		if (i == 0 || s[i - 1] != s[i]) count[i] = 1;
		else {
			count[i] = count[i - 1] + 1;
			if (count[i] == k) {
				s.erase(i - k + 1, k);
				i = i - k;
			}
		}
	}
	return s;
}