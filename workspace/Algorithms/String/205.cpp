#include"string_func.h"

// 205. Í¬¹¹×Ö·û´®
bool isIsomorphic(string s, string t) {
	if (s.size() != t.size()) return false;
	unordered_map<char, char> hash1;
	unordered_map<char, char> hash2;
	for (int i = 0; i < s.size(); i++) {
		if (hash1.find(s[i]) != hash1.end()) {
			if (hash1[s[i]] != t[i]) {
				return false;
			}
		}
		else if (hash2.find(t[i]) != hash2.end()) {
			if (hash2[t[i]] != s[i]) {
				return false;
			}
		}
		else {
			hash1[s[i]] = t[i];
			hash2[t[i]] = s[i];
		}
	}
	return true;

	// ¼ò»¯°æ
	int a[128] = { 0 };
	int b[128] = { 0 };
	int c = 0, d = 0;
	int length = s.size();
	for (int i = 0; i < length; i++) {
		if (a[s[i]] == 0) a[s[i]] = ++c;
		if (b[t[i]] == 0) b[t[i]] = ++d;
		if (a[s[i]] != b[t[i]]) return false;
	}
	return true;
}