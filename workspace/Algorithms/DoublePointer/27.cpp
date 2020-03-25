#include"doublePointer.h"

// 27. ÒÆ³ıÔªËØ
int removeElement(vector<int>& nums, int val) {
	int flag = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] != val) swap(nums[flag++], nums[i]);
	}
	return flag;
}