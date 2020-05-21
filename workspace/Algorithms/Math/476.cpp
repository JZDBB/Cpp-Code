#include"Math.h"

// 476. Êý×ÖµÄ²¹Êý
int findComplement(int num) {
	int temp = num, c = 0;
	while (temp > 0) {
		temp >>= 1;
		c = (c << 1) + 1;
	}
	return num ^ c;
}