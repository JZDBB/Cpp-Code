#include"hash.h"

// 594. 最长和谐子序列
int findLHS(vector<int>& nums) {

	// 常规
	int size = nums.size();
	int temp = 0;
	int i = 0;
	sort(nums.begin(), nums.end());
	for (int j = 1; j < size; ++j) {
		while (i < size && nums[j] - nums[i] > 1) {
			++i;
		}
		if (nums[j] - nums[i] == 1) {
			temp = max(temp, j - i + 1);
		}
	}
	return temp;

	// 两次遍历
	unordered_map<int, int> map1;
	int res = 0;
	for (int i = 0; i < nums.size(); i++) map1[nums[i]] += 1;
	for (const auto n : map1) {
		int m = map1[n.first];
		if (map1.find(n.first + 1) != map1.end()) m += map1[n.first + 1];
		else m = 0;
		res = m > res ? m : res;
	}
	return res;

	// 单次遍历
	unordered_map<int, int> map;
	res = 0;
	for (int i = 0; i < nums.size(); i++) {
		map[nums[i]] += 1;
		if (map.find(nums[i] + 1) != map.end()) res = res > (map[nums[i] + 1] + map[nums[i]]) ? res : (map[nums[i] + 1] + map[nums[i]]);
		if (map.find(nums[i] - 1) != map.end()) res = res > (map[nums[i] - 1] + map[nums[i]]) ? res : (map[nums[i] - 1] + map[nums[i]]);
	} 
	return res;
}