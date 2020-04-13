#include"SortSolution.h"

// 75. ÑÕÉ«·ÖÀà
void sortColors(vector<int>& nums) {
	if (nums.size() < 2) return;
	int cur = 0;
	int p2 = nums.size() - 1;
	int p0 = 0;
	while (cur <= p2) {
		if (nums[cur] == 0) {
			swap(nums[p0], nums[cur]);
			p0++;
			cur++;
		}
		else if (nums[cur] == 2) {
			swap(nums[p2], nums[cur]);
			p2--;
		}
		else cur++;
	}
}