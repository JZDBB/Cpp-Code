#include"doublePointer.h"

// 524. 通过删除字母匹配到字典里最长单词
bool isSubsequence(string s, string d) { // 判断s是不是包含d的子序列
	int j = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == d[j]) j++;
	}
	return d.size() == j; // 注意最后得到的是什么含义
}

bool isSmaller(string s1, string s2) {
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] > s2[i]) return false;
		else if (s1[i] < s2[i]) return true;
	}
	return false;
}

string findLongestWord(string s, vector<string>& d) {
	// me 问题：没有按照字典顺序排序 + 设置子函数会使代码更清晰哦！
	/*sort(d.begin(), d.end());
	int max = 0;
	int flag = 0;
	bool flag1;
	int s1 = 0, s2 = 0;
	for (int i = 0; i < d.size(); i++) {
		flag1 = false;
		s1 = s2 = 0;
		while (s2 < d[i].size()) {
			if (s1 > s.size()) { flag1 = false; break; }
			if (s[s1] == d[i][s2]) {
				s1++; s2++;
				flag1 = true;
			}
			else s1++;
		}
		if (flag1 && d[i].size() > max) {
			flag = i;
			max = d[i].size();
		}
	}
	if (max == 0) return "";
	return d[flag];*/


	// 改进版
	string result;
	for (string str : d) { // 遍历数组中的元素
		if (isSubsequence(s, str)) {
			if (str.size() > result.size()) result = str;
			else if (str.size() == result.size()) {
				if (isSmaller(str, result)) result = str;
			}
		}
	}
	if (result.empty()) return "";
	return result;

}
