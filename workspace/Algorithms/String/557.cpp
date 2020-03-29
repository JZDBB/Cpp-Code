#include"string_func.h"

// 557. 反转字符串中的单词 III
string reverseWords2(string s) {
	int start = 0;
	int end = s.size() - 1;
	while (s[start] == ' ' && start < s.size()) start++;
	while (s[end] == ' '&& end > 0) end--;

	for (int left = start, right = start; right <= end;) {
		while (s[right] != ' '&& right <= end) right++;
		reverse(s.begin() + left, s.begin() + right);
		left = right;
		while (s[left] == ' '&& left <= end) left++;
		right = left;
	}
	
	int new_index = start;
	for (int i = start; i <= end; i++) {
		if (s[i] == ' ' && s[i - 1] == ' ') continue;
		s[new_index++] = s[i];
	}
	return s.substr(start, new_index - start);
}