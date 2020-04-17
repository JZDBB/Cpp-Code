#include"Math.h"

// 415. ×Ö·û´®Ïà¼Ó
string addStrings(string num1, string num2) {
	int p1 = num1.size() - 1;
	int p2 = num2.size() - 1;
	int carry = 0;
	string res = "";
	while (p1>=0|| p2>=0 || carry) {
		int n1 = p1 < 0 ? 0 : int(num1[p1]-'0');
		int n2 = p2 < 0 ? 0 : int(num2[p2]-'0');
		p1--;
		p2--;
		int num = n1 + n2 + carry;
		carry = num / 10;
		res.insert(res.begin(), char(num % 10 + '0'));
	}
	return res;
}