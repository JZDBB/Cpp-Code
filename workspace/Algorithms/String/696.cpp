#include"string_func.h"

// 696. 计数二进制子串
int countBinarySubstrings(string s) {

	// O(n^2)
	/*int left = 0, right = 0;
	int flag = s[0];
	int index = 0;
	int res = 0;
	while (index < s.size()) {
		if (s[index] == flag) index++;
		else {
			right = index;
			while (s[index] == s[right]) right++;
			res += (index - left) < (right - index) ? (index - left) : (right - index);
			left = index;
			flag = s[index];
		}
	}
	return res;*/

	// O(n)
	int left = 0, right = 0;
	int flag = s[0];
	int index = 0;
	int res = 0;
	int mi = 0;
	while (index <= s.size()) {
		if (index<s.size() && s[index] == flag) index++;
		else {
			right = index - mi;
			res += left < right ? left : right;
			left = right;
			mi = index;
			flag = s[index];
			if (index == s.size()) break;
		}
	}
	return res;


}