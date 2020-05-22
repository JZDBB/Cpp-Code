#include"vector_func.h"

// 565. Êı×éÇ¶Ì×
int arrayNesting(vector<int>& nums) {
	vector<int> visit(nums.size());
	int res = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (!visit[i]) {
			int count = 0;
			int index = i;
			while (1) {
				if (nums[index] > nums.size()) {
					visit[index] = 1;
					count = 0;
					break;
				}
				else {
					if (visit[index]) {
						res = res > count ? res : count;
						break;
					}
					visit[index] = 1;
					index = nums[index];
					count++;
				}
			}
		}
	}
	return res;
}