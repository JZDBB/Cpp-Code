#include"Search.h"

// 153. 寻找旋转排序数组中的最小值
int findMin(vector<int>& nums) {
	int lo = 0;
	int hi = nums.size() - 1;
	while (lo < hi) {
		int mi = lo + (hi - lo) / 2;
		if (nums[mi] >= nums[lo] && nums[mi] >= nums[hi]) lo = mi + 1;
		else if (nums[mi] <= nums[hi] && nums[mi] <= nums[lo]) hi = mi;
		else if (nums[mi] >= nums[lo] && nums[mi] <= nums[hi]) return nums[lo];
	}
	return nums[lo];
}