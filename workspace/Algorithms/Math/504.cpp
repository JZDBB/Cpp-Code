#include"Math.h"

// 504. Æß½øÖÆÊý	
string convertToBase7(int num) {
	bool flag = true;
	if (num < 0) {
		num = -num;
		flag = false;
	}
	stack<int> s;
	while (num >= 7) {
		s.push(num % 7);
		num /= 7;
	}
	s.push(num % 7);
	string res = "";
	if (!flag) res.push_back('-');
	while (!s.empty()) {
		res.push_back(char(s.top()+48));
		s.pop();
	}
	return res;
}