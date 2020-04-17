#include"vector_func.h"

// 55. ÌøÔ¾ÓÎÏ·
bool canJump(vector<int>& nums, int begin, int end) {
	if (begin == end) return true;
	for (int i = end-1; i >= begin; i--) {
		if (nums[i] >= end - i) {
			return canJump(nums, begin, i);
		}
	}
	return false;
}

bool canJump(vector<int>& nums) {
	return canJump(nums, 0, nums.size() - 1);
}