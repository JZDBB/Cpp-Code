#include"vector_func.h"

//287. 寻找重复数
int findDuplicate(vector<int>& nums) {
	vector<int> a(nums.size());
	for (int i = 0; i < nums.size(); i++) {
		a[nums[i]]++;
	}
	int max = 0;
	int num;
	for (int i = 0; i < a.size(); i++) {
		if (max < a[i]) {
			num = i;
			max = a[i];
		}
	}
	return num;
}

// 判环问题
int findDuplicateII(vector<int>& nums) {
	if (nums.size() == 0) return 0;
	int slow = nums[0];
	int fast = nums[nums[0]];
	while (slow != fast) {
		slow = nums[slow];
		fast = nums[nums[fast]];
	}
	fast = 0;
	while (slow != fast) {
		fast = nums[fast];
		slow = nums[slow];
	}
	return slow;
}