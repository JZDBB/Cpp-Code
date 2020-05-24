#include"Stack.h"

// 227. 基本计算器 II
//224. 基本计算器
int calculate(int i, int j, char c) {
	switch (c) {
	case '+': return i + j;
	case '-': return i - j;
	case '*': return i * j;
	case '/': return i / j;
	default: break;
	}
	return 0;
}

int calculate(string s) {
	stack<char> op;
	stack<int> nums;
	int i = 0;
	unordered_map<char, int> m;
	m['*'] = 1;
	m['/'] = 1;
	m['+'] = 0;
	m['-'] = 0;
	int num = 0;
	bool flag = true;
	while (i <= s.length()) {
		if (s[i] == ' ') {
			i++;
			continue;
		}
		if (s[i] >= '0'&&s[i] <= '9') {
			num = 0;
			while (s[i] >= '0'&&s[i] <= '9') {
				num = num * 10 + (s[i] - '0');
				i++;
			}
			nums.push(num);
		}
		else if (s[i] == '(') {
			int begin = i;
			int count = 0;
			i++;
			while (s[i] != ')'|| count!=0) {
				if (s[i] == ')') count--;
				if (s[i] == '(') count++;
				i++;
			}
			string str = s.substr(begin + 1, i - begin - 1);
			num = calculate(s.substr(begin + 1, i - begin - 1));
			nums.push(num);
			i++;
		}
		else {
			while (!op.empty()){
				int x = m[op.top()];
				int y = m[s[i]];
				if (i==s.length()||m[op.top()] >= m[s[i]]) {
					int a = nums.top();
					nums.pop();
					int b = nums.top();
					nums.pop();
					num = calculate(b, a, op.top());
					op.pop();
					nums.push(num);
				}
				else break;
			}
			if (op.empty() && i == s.length()) break;
			if (i == s.length()) continue;
			op.push(s[i]);
			i++;
		}
	}
	return nums.top();
}