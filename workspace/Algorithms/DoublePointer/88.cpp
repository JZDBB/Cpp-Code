#include"doublePointer.h"

// 88. 合并两个有序数组 ——需要注意归并数组提前清空的问题
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	// 第一版
	/*int last = (m--) + (n--) - 1;
	while (n >= 0) {
		nums1[last--] = m >= 0 && nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
	}*/

	// 0ms 版 —— 或计算比与计算一般来说要减少一定的耗时，m和n的自增自减也耗时
	int last = m + n - 1;
	while (n) {
		nums1[last--] = m == 0 || nums1[m - 1] <= nums2[n - 1] ? nums2[--n] : nums1[--m];
	}
}