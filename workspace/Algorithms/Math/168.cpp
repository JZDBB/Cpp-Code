#include"Math.h"

// 168. Excel±íÁĞÃû³Æ
string convertToTitle(int n) {
	string res = "";
	while (n > 0){
		n -= 1;
		res.push_back('A' + (n % 26));
		n /= 26;
	}
	reverse(res.begin(), res.end());
	return res;
}