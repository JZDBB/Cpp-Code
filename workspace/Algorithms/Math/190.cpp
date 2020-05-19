#include"Math.h"

// 190. 颠倒二进制位
// 二进制尽量用位运算——容易解决位运算的0和复数补码的问题
uint32_t reverseBits(uint32_t n) {
	uint32_t res = 0;
	for (int i = 0; i < 32; i++) {
		res = (res << 1) | (n & 1);
		n >> 1;
	}
	return res;

	// bit 操作
	n = (n >> 16) | (n << 16);
	n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
	n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
	n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
	n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
	return n;
}