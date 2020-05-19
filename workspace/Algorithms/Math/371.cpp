#include"Math.h"

// 371. 两整数之和
int getSum(int a, int b) {
	if (a == 0) return b;
	if (b == 0) return a;
	uint32_t lower;
	uint32_t carry;
	while (true) {
		lower = a ^ b;
		carry = a & b;
		if (carry == 0) break;
		a = lower;
		b = carry << 1;
	}
	return int(lower);
}