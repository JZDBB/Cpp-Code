#include"solution.h"

// 42. 接雨水
int trap(vector<int>& height) {
	if (height.size() < 2) return 0;

	// 动态编程
	int left_max = 0;
	int right_max = height.size() - 1;
	int max = 0;
	int left = 0;
	int right = 0;
	for (int i = 0; i < height.size(); i++) {
		left += height[i] > height[left_max] ? height[i] : height[left_max];
		left_max = height[i] > height[left_max] ? i : left_max;
	}
	for (int i = height.size() - 1; i >= 0; i--) {
		right += height[i] > height[right_max] ? height[i] : height[right_max];
		right_max = height[i] > height[right_max] ? i : right_max;
	}
	int sub = 0;
	for (int i = 0; i < height.size(); i++) sub += height[i];
	int total = height.size() * height[left_max];
	return left + right - total - sub;

	// 双指针
	int left = 0;
	int right = height.size() - 1;
	int left_max = 0;
	int right_max = 0;
	int res = 0;
	while (left < right) {
		if (height[left] < height[right]) {
			if (height[left] < left_max) res += left_max - height[left];
			else left_max = height[left];
			left++;
		}
		else {
			if (height[right] < right_max) res += right_max - height[right];
			else right_max = height[right];
			right--;
		}
	}
	return res;
}