#include"string_func.h"

// 647. 回文子串 —— 中心扩散法
int count(string s, int l, int r) {
	int res = 0;
	while (l >= 0 && r < s.size() && s[l--] == s[r++]) res++;
	return res;
}

int countSubstrings(string s) {
	int res = 0;
	for (int i = 0; i < s.size(); i++) {
		res += count(s, i, i);
		res += count(s, i, i + 1);
	}
	return res;
}