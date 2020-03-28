#include"Queue.h"

// 239. 滑动窗口最大值 —— 单调栈
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	MonotonicQueue windows;
	vector<int> res;
	for (int i = 0; i < nums.size(); i++) {
		if (i < k - 1) windows.push(nums[i]);
		else {
			windows.push(nums[i]);
			res.push_back(windows.max());
			windows.pop(nums[i - k + 1]);
		}
	}
	return res;
}