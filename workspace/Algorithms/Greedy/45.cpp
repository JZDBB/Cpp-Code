#include"Greedy.h"

// 45. ÌøÔ¾ÓÎÏ· II
int jump(vector<int>& nums) {
	if (nums.size() < 2) return 0;
	int count = 0;
	int index = 0;
	while (index < nums.size()) {
		int max_index = index+1;
		int max_step = nums[index];
		for (int i = 1; i <= nums[index]; i++) {
			if (index + i >= nums.size() - 1) return count + 1;
			int step = i + nums[index + i];
			if (step > max_step) {
				max_step = step;
				max_index = index + i;
			}
		}
		count++;
		index = max_index;
	}
	return count;
}