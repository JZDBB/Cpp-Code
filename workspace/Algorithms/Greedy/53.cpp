#include"Greedy.h"

// 53. 最大子序和
int maxSubArray(vector<int>& nums) {
	int max = nums[0];
	int curr_max = nums[0];
	for (int i = 1; i < nums.size(); i++) {
		int sum = curr_max + nums[i];
		curr_max = sum > nums[i] ? sum : nums[i];
		max = curr_max > max ? curr_max : max;
	}
	return max;
}
