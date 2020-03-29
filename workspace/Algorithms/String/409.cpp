#include"string_func.h"

// 409. 最长回文串
int longestPalindrome(string s) {
	if (s.size() < 2) return s.size();
	vector<int> a(58, 0);
	for (char c : s) {
		a[c - 'A']++;
	}
	int odd = 0;
	int even = 0;
	for (int i = 0; i < a.size(); i++) {
		even += (a[i] / 2) * 2;
		if (a[i] % 2 != 0) 	odd = odd > a[i] % 2 ? odd : a[i] % 2;
	}
	return even+odd;
}