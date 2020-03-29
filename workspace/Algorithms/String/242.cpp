#include"string_func.h"

// 242. 有效的字母异位词
bool isAnagram(string s, string t) {
	if (s.size() != t.size()) return false; // 判断特殊情况

	// me —— O(n^2)
	/*for (int i = 0; i < s.size(); i++) {
		int iter = t.find(s[i]); // find耗时啊
		if (iter != -1) t.erase(iter, 1);
		else return false;
	}
	if (t != "") return false;
	return true;*/

	// 排序 —— O(nlogn)
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	return s == t;

	 
	// 哈希表 O(n)
	vector<int> a(26, 0);
	for (int i = 0; i < s.size(); i++) {
		a[s[i] - 'a']++;
		a[t[i] - 'a']--;
	}
	for (int i : a) {
		if (i != 0) return false;
	}
	return true;

}