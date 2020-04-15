#include"Greedy.h"

// 665. 非递减数列
// 在出现 nums[i] < nums[i - 1] 时，需要考虑的是应该修改数组的哪个数，
// 使得本次修改能使 i 之前的数组成为非递减数组，并且**不影响后续的操作** 。
bool checkPossibility(vector<int>& nums) {
	int count = 0;
	for (int i = 1; i < nums.size() && count < 2; i++) {
		if (nums[i] >= nums[i - 1]) continue;
		count++;
		if (i - 2 >= 0 && nums[i] < nums[i - 2]) nums[i] = nums[i - 1];
		else nums[i - 1] = nums[i];
	}
	return count <= 1;
}