#include"Search.h"

// 540. 有序数组中的单一元素
int singleNonDuplicate(vector<int>& nums) {
	int lo = 0;
	int hi = nums.size() - 1;
	while (lo < hi) {
		int mi = lo + (hi - lo) / 2;
		if ((mi % 2 == 0 && nums[mi] == nums[mi + 1]) || (mi % 2 == 1 && nums[mi] == nums[mi - 1])) lo = mi + 1;
		else hi = mi;
	}
	return nums[lo];

	// 仅对偶数索引进行搜索
	/*int lo = 0;
	int hi = nums.size() - 1;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (mid % 2 == 1) mid--;
		if (nums[mid] == nums[mid + 1]) {
			lo = mid + 2;
		}
		else {
			hi = mid;
		}
	}
	return nums[lo];*/
}