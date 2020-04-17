#include"Math.h"

// 172. 阶乘后的零 —— 5的公倍数多少个
int trailingZeroes(int n) {
	int count = 0;
	// 超时版

	//for (int i = 0; i <= n; i += 5) {
	//	int N = i; // i不能随意改动
	//	while (N) {
	//		if (N % 5 == 0) {
	//			count++;
	//			N /= 5;
	//		}
	//		else break;
	//	}
	//}

	// 改进版 
	// count = n/5+n/25+n/125...;每一个5的倍数周期出现一次5。
	while (n) {
		count += n / 5;
		n = n / 5;
	}

	return count;
}