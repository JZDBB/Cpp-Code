#include"Math.h"

// 二进制中1的个数
int  NumberOf1(int n) {
	int cnt = 0;
	while (n) {
		cnt++;
		n &= (n - 1); // 清除最低位的1
	}
	return cnt;
}