#include"Math.h"

// 67. 二进制求和
string addBinary(string a, string b) {
	stack<int> s1;
	stack<int> s2;
	while (!a.empty()) {
		s1.push(int(a[0] - '0'));
		a.erase(a.begin());
	}
	while (!b.empty()) {
		s2.push(int(b[0] - '0'));
		b.erase(b.begin());
	}
	int carry = 0;
	string res = "";
	while (!s1.empty() || !s2.empty() || carry) {
		int num1 = s1.empty() ? 0 : s1.top();
		int num2 = s2.empty() ? 0 : s2.top();
		if (!s1.empty()) s1.pop();
		if (!s2.empty()) s2.pop();
		int num = num1 + num2 + carry;
		carry = num / 2;
		res.insert(res.begin(), char(num % 2 + '0'));
	}
	return res;
}