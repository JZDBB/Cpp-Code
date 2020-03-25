#include"doublePointer.h"

//167. 两数之和 II - 输入有序数组
vector<int> twoSum(vector<int>& numbers, int target) {
	// 双指针——削减搜索空间
	int index1 = 1, index2 = numbers.size();
	while (index1 < index2) {
		int sum = numbers[index1 - 1] + numbers[index2 - 1];
		if (sum == target) return vector<int>{index1, index2};
		else if (sum > target) index2--;
		else index1++;
	}
	return {};
}