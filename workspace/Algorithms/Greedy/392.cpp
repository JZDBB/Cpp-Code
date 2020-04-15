#include"Greedy.h"

// 392. еп╤овспРап
bool isSubsequence(string s, string t) {
	int i = 0;
	int j = 0;
	while (i < s.size() && j < t.size()) {
		if (t[j] != s[i]) {
			j++;
		}
		else {
			i++;
			j++;
		}
	}
	return i == s.size();
}