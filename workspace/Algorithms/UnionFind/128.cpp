#include"unionfind_fun.h"

// 128. 最长连续序列
int longestConsecutive(vector<int>& nums) {
	if (nums.size() == 0) return 0;
	unordered_set<int> m;
	int res = 0;
	m.insert(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++) {
		if (!m.count(nums[i] - 1)) {
			int max = 1;
			int bias = 1;
			while (m.count(nums[i] + bias)) {
				max++;
				bias++;
			}
			if (res < max) res = max;
		}
	}
	return res;
}