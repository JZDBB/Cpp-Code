#include"doublePointer.h"

// 26. 删除排序数组中的重复项 —— 原地修改输入数组 并在使用 O(1) 额外空间
int removeDuplicates(vector<int>& nums) {
	// me

	//if (nums.size() == 0) return 0;
	//int head = 0;
	//int tailer = 1;
	//while (tailer < nums.size()) {
	//	if (nums[head] == nums[tailer]) tailer++;
	//	else {
	//		nums[++head] = nums[tailer++];
	//	}
	//}
	//return head + 1; // 返回数组长度

	// 改进版—— 更加简洁
	if (nums.size() < 2) return nums.size();
	int head = 0;
	for (int tailer = 0; tailer < nums.size(); tailer++) {
		if (nums[head] != nums[tailer]) nums[++head] = nums[tailer];
	}
	return ++head;
}

//  删除排序数组中的重复项 II ——每个元素最多出现两次
int removeDuplicates2(vector<int>& nums) { // 详情见图解 去重II.gif
	if (nums.size() <= 2) return nums.size();
	int head = 1;
	for (int tailer = 2; tailer < nums.size(); tailer++) {
		if (nums[head - 1] != nums[tailer]) nums[++head] = nums[tailer];
	}
	return ++head;
}