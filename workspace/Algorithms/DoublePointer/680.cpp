#include"doublePointer.h"

// 680. 验证回文字符串 Ⅱ 给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
bool isPalindrome(string s, int i, int j) {
	while (i <= j) {
		if (s[i++] != s[j--])  return false;
	}
	return true;
}

bool validPalindrome(string s) {
	// 判断回文字符串 I
	/*int left = 0;
	int right = s.size() - 1;
	while (left <= right) { // <= 需注意
		if (s[left] != s[right]) return false;
		left++;
		right--;
	}
	return true;*/

	// 判断回文字符串 I —— me
	// 问题：如何判断删掉双指针中哪一个所指的元素
	/*int left = 0;
	int right = s.size() - 1;
	bool flag = 0;
	while (left <= right) {
		if (s[left] != s[right]) {
			if (flag) return false;
			if (s[left + 1] == s[right]) { // 错误在于：先判断的先删除，没有和后面一起结合考虑
				flag = 1;
				left++;
			} else if (s[left] == s[right - 1]) {
				flag = 1;
				right--;
			}
			else return false;
		}
		left++;
		right--;
	}
	return true;*/

	// 改正版
	// 解决方法：两边都删除看看——不过这个方法需要判断两次，可能耗费时间多
	int left = 0;
	int right = s.size() - 1;
	while (left <= right) {
		if (s[left] != s[right]) {
			return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
		}
		left++;
		right--;
	}
	return true;
}