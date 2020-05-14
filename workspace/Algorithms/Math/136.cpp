#include"Math.h"

// 136. 只出现一次的数字
int singleNumber(vector<int>& nums) {
	int res = 0;
	for (int i : nums) res ^= i;
	return res;
}