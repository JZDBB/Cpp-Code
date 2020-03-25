#include"doublePointer.h"

// 283. 移动零
void moveZeroes(vector<int>& nums) {

	// me: 多了一个置为0的操作
	int head = 0, tailer = 0;
	for (; tailer < nums.size(); tailer++) {
		if (nums[tailer] != 0) nums[head++] = nums[tailer];
	}
	for (; head < nums.size(); head++) {
		nums[head] = 0;
	}

	// 改进版：直接交换将0逐渐后移
	int flag = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] != 0) swap(nums[flag++], nums[i]);
	}
}