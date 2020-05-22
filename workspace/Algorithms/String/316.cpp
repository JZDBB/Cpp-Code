#include"string_func.h"

// 316. È¥³ıÖØ¸´×ÖÄ¸ 
// https://leetcode-cn.com/problems/remove-duplicate-letters/solution/zhan-by-liweiwei1419/
string removeDuplicateLetters(string s) {
	vector<int> V(26);
	string res = "";
	for (int i = 0; i < s.size(); i++) V[s[i] - 'a'] = i;
	unordered_set<char> sets;
	for (int i = 0; i < s.size(); i++) {
		if (sets.count(s[i])) continue;
		while (res !="" && res.back()>=s[i]) {
			if (V[res.back() - 'a'] >= i) {
				sets.erase(res.back());
				res.pop_back();
			}
			else break;
		}
		res.push_back(s[i]);
		sets.insert(s[i]);
	}
	return res;
}