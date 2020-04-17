#include"Math.h"

// 238. 除自身以外数组的乘积
vector<int> productExceptSelf(vector<int>& nums) {
	vector<int> res;
	int left = 1;
	for (int i = 0; i < nums.size(); i++) {
		res.push_back(left);
		left *= nums[i];
	}
	int right = 1;
	int size = nums.size()-1;
	for (int i = size; i >=0; i--) {
		res[i] = right * res[i];
		right *= nums[i];
	}
	return res;
}