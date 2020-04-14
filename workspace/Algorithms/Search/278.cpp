#include"Search.h"

// 278. 第一个错误的版本
bool isBadVersion(int n) {
	if (n > 3) return true;
	return false;
}
int firstBadVersion(int n) {
	int lo = 1;
	int hi = n;
	while (lo < hi) {
		int mi = lo / 2 + hi / 2;
		isBadVersion(mi) ? hi = mi: lo = mi + 1;
	}
	return lo;
}