#include"doublePointer.h"

// 633. 平方数之和
bool judgeSquareSum(int c) {
	// 蛮力 时间复杂度 O(sqrt(n)) 事实上会快一些
	for (int i = 1; pow(i, 2) <= c / 2; i++) {
		double diff = c - pow(i, 2);
		if (sqrt(diff) - int(sqrt(diff)) == 0) return true;
	}
	return false;

	// 双指针 时间复杂度 O(sart(n))
	int left = 0;
	int right = (int)sqrt(c);
	while (left < right) { // 相等情况
		long sum = pow(left, 2) + pow(right, 2); // 长整型防溢出 —— 64位编译系统：int占四字节，long占8字节，long数据范围变为：-2^63~2^63-1
		if (sum < c) left++;
		else if (sum > c)right--;
		else return true;
	}
	return false;

}