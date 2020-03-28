#include"hash.h"

// 128.最长连续序列
int longestConsecutive(vector<int>& nums) {
	// 复杂度O(nlgn)+O(n)
	/*if (nums.size() < 2) return nums.size();
	sort(nums.begin(), nums.end());
	int res = 0;
	int len = 0;
	for (int i = 1; i < nums.size(); i++) {
		if (i < nums.size() && nums[i] - nums[i - 1] == 1) len++;
		else if (nums[i] != nums[i - 1]) len = 0;
		res = res > (len + 1) ? res : (len + 1);
	}
	return res;*/

	// 哈希1
	unordered_map<int, int> m;
	int res = 0;
	for (int num : nums) {
		if (m.count(num)) continue;
		
		auto it_l = m.find(num - 1);
		auto it_r = m.find(num + 1);
		int l = it_l != m.end() ? it_l->second : 0;
		int r = it_r != m.end() ? it_r->second : 0;
		int t = l + r + 1;
		m[num] = m[num - l] = m[num + r] = t; // 中间插入，更新最左边和最右边的值

		res = res > t ? res : t;
	}
	return res;

	// 哈希2 
	unordered_map<int, int> m1;
	res = 0;
	for (auto num : nums) {
		if (!m1.count(num)) {
			int len = 0;
			while (m1.count(num++)) ++len;
			res = res > len ? res : len;
		}
	}
	return res;
}