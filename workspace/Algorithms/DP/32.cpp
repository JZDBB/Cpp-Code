#include"DP.h"

// 32. 最长有效括号
int longestValidParentheses(string s) {
	// stack
	stack<int> S;
	int len = 0;
	S.push(-1);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') S.push(i);
		else {
			S.pop();
			if (S.empty()) S.push(i);
			else len = max(len, i - S.top());
		}
	}
	return len;

}