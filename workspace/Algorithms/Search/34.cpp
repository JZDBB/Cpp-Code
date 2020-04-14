#include"Search.h"

// 34. 在排序数组中查找元素的第一个和最后一个位置 —— ***
vector<int> searchRange(vector<int>& nums, int target) {
	if (nums.size() == 0) return { -1, -1 };
	if (nums.size() == 1) {
		if (nums[0] == target) return{ 0,0 };
		return { -1, -1 };
	}
	int lo = 0;
	int hi = nums.size();
	while (lo < hi) {
		int mi = lo / 2 + hi / 2;
		target < nums[mi] ? hi = mi : lo = mi + 1;
	}
	int right = lo - 1;
	lo = 0;
	hi = nums.size() - 1;
	while (lo < hi) {
		int mi = lo / 2 + hi / 2;
		target - 1 < nums[mi] ? hi = mi : lo = mi + 1;
	}
	int left = lo;
	if (left >= right && nums[left] != target) return { -1, -1 };
	return { left, right };
}