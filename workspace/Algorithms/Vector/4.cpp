#include"vector_func.h"

// 4. 寻找两个正序数组的中位数
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	if (nums1.size() > nums2.size()) swap(nums1, nums2);
	int m = nums1.size();
	int n = nums2.size();
	
	int total = (m + n + 1) / 2;
	int left = 0;
	int right = m;

	while (left < right) {
		int i = left + (right - left + 1) / 2; // 防止下标越界 i-1
		int j = total - i;
		if (nums1[i - 1] > nums2[j]) right = i - 1;
		else left = i;
	}
	int i = left;
	int j = total - i;
	int Leftmax1 = i == 0 ? INT_MIN : nums1[i - 1];
	int Rightmin1 = i == m ? INT_MAX : nums1[i];
	int Leftmax2 = j == 0 ? INT_MIN : nums2[j - 1];
	int Rightmin2 = j == n ? INT_MAX : nums2[j];
	if ((m + n) % 2 == 1) {
		return double(max(Leftmax1, Leftmax2));
	}
	else {
		return (double(max(Leftmax1, Leftmax2)) + double(min(Rightmin1, Rightmin2))) / 2.0;
	}
}