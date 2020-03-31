#include"vector_func.h"

// 697. 数组的度
int findShortestSubArray(vector<int>& nums) {
	unordered_map<int, vector<int>> m;
	for (int i = 0; i < nums.size(); i++) {
		if (m.find(nums[i]) == m.end()) m[nums[i]] = {1, i, 0};
		else {
			m[nums[i]][0]++;
			m[nums[i]][2] = i;
		}
	}
	int max = 0;
	int len = 0;
	for (auto key : m) {
		if (key.second[0] > max) {
			max = key.second[0];
			len = key.second[2] - key.second[1];
		}
		else if (key.second[0] == max) {
			len = key.second[2] - key.second[1] < len ? key.second[2] - key.second[1] : len;
		}
	}
	return len;
}