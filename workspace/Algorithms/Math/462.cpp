#include"Math.h"

// 462. 最少移动次数使数组元素相等 II
int minMoves2(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int count = 0;
	int target = nums[nums.size() / 2];
	for (int num : nums) {
		count += abs(target - num);
	}
	return count;
}