#include"DP.h"

// 152. 乘积最大子数组
int maxProduct(vector<int>& nums) {
	int imax = 1;
	int imin = 1;
	int max_ = INT_MIN;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] < 0) {
			swap(imax, imin);
		}
		imax = max(imax*nums[i], nums[i]);
		imin = min(imin*nums[i], nums[i]);
		max_ = max(max_, imax);
	}
	return max_;
}
