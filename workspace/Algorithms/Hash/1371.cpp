#include"hash.h"

// 1371. 每个元音包含偶数次的最长子字符串
int findTheLongestSubstring(string s) {
	char vowels[] = { 'a', 'e', 'i', 'o', 'u' };
	int res = 0;
	unordered_map<int, int> m;
	int ans = 0;
	m[ans] = -1;
	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j < 5; j++) {
			if (s[i] == vowels[j]) ans ^= 1 << j;
		}
		if (m.find(ans) != m.end()) res = max(res, i - m[ans]);
		else m[ans] = i;
	}
	return res;
}