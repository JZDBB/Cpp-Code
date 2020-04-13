#include"SortSolution.h"

// 215. 数组中的第K个最大元素
int partion(vector<int> &nums, int low, int high) {
	int refer = nums[low];
	while (low < high) {
		if (low<high && nums[high] >= refer)high--;
		nums[low] = nums[high];
		if (low<high && nums[low] <= refer) low++;
		nums[high] = nums[low];
	}
	nums[low] = refer;
	return low;
}
int QuickSort(vector<int> &nums, int left, int right, int k) {
	if (left >= right) return nums[left];
	int res;
	int index = partion(nums, left, right);
	if (index == k) return nums[index];
	if (index > k) res = QuickSort(nums, left, index - 1, k);
	else res = QuickSort(nums, index + 1, right, k);
	return res;
}
int findKthLargest(vector<int>& nums, int k) {
	int size = nums.size();
	return QuickSort(nums, 0, size - 1, size - k);
}