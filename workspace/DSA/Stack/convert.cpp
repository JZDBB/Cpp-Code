#include"convert.h"

// Stack 应用——进制转换
string change(stack<int> & S, int num) {
	string str = "";
	int re, i = 0;
	while (num) {
		re = num % 2;
		num = num / 2;
		S.push(re);
	}
	while (!S.empty()) {
		str[i++] = char(S.top());
		S.pop();
	}
	return str;
}