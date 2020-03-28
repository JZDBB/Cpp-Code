#include"Stack.h"

// 20. 有效的括号 —— 需要注意一些特殊情况（见注释）
bool isValid(string s) {
	if (s.size() % 2 != 0) return false; // 减少很多计算量呢~
	stack<char> arm;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(' || s[i] == '{' || s[i] == '[') arm.push(s[i]);
		else {
			if (arm.empty()) return false; // 防 "}{"
			switch (s[i]) {
			case ')': if (arm.top() != '(') return false; break; // break很重要！！
			case '}': if (arm.top() != '{') return false; break;
			case ']': if (arm.top() != '[') return false; break;
			}
			arm.pop();
		}
	}
	if (!arm.empty()) return false; // 防"(("
	return true;
}