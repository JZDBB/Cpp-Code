#include"DivideConquer.h"

// 241. 为运算表达式设计优先级
// 回溯搜索。该问题牵涉到括号的组合问题，一般使用递归+回溯的思想
// string substr (size_t pos = 0, size_t len = npos) const;
vector<int> diffWaysToCompute(string input) {
	vector<int> res;
	for (int i = 0; i < input.size(); ++i) {
		char c = input[i];
		if (c == '+' || c == '-' || c == '*') {
			auto res1 = diffWaysToCompute(input.substr(0, i));
			auto res2 = diffWaysToCompute(input.substr(i + 1));
			for (auto r1 : res1) {
				for (auto r2 : res2) {
					if (c == '+') {
						res.push_back(r1 + r2);
					}
					else if (c == '-') {
						res.push_back(r1 - r2);
					}
					else if (c == '*') {
						res.push_back(r1 * r2);
					}
				}
			}
		}
	}
	if (res.empty()) {
		res.push_back(stoi(input));
	}
	return res;
}