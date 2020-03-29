#include"string_func.h"

//9. 回文数
bool isPalindrome(int x) {
	if (x < 0) return false;
	int rev = 0;
	int pre = x;
	while (x) {
		int num = x % 10;
		x = x / 10;
		if (rev > INT_MAX / 10 || (rev == INT_MAX && num > INT_MAX % 10)) // 防止整形计算溢出
			return false;
		rev = rev * 10 + num;
	}
	if (rev == pre) return true;
	else return false;
}