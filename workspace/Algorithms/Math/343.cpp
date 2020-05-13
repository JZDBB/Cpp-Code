#include"Math.h"

// 343. ÕûÊı²ğ·Ö
int integerBreak(int n) {
	if (n < 2) return n;
	if (n < 4) return n - 1;
	int dif = n % 3;
	int nums = n / 3;
	if (dif == 0) { return pow(3, nums); }
	else if (dif == 1) return pow(3, nums - 1) * 4;
	else return pow(3, nums)*dif;
}