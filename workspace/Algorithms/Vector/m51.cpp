#include"vector_func.h"

// 面试题51. 数组中的逆序对
int mergeSort_r(vector<int>& nums, int lo, int hi) {
	if (lo >= hi) return 0;
	int mi = lo + (hi - lo) / 2;
	int count = mergeSort_r(nums, lo, mi) + mergeSort_r(nums, mi + 1, hi);
	vector<int> tmp(nums);
	/*tmp.insert(nums.begin(), nums.begin + mi);*/
	int i = lo;
	int p = lo;
	int j = mi + 1;
	while (i <= mi && j <= hi) {
		if (tmp[i] > tmp[j]) {
			count += mi - i + 1;
			nums[p++] = tmp[j++];
		}
		else {
			nums[p++] = tmp[i++];
		}
	}
	while (i <= mi) nums[p++] = tmp[i++];
	while (j <= hi) nums[p++] = tmp[j++];
	return count;
}

int reversePairs(vector<int>& nums) {
	return mergeSort_r(nums, 0, nums.size() - 1);
}