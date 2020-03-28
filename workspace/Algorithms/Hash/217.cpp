#include"hash.h"

// 217.´æÔÚÖØ¸´ÔªËØ
bool containsDuplicate(vector<int>& nums) {
	// hash
	if (nums.size() < 2) return false;
	unordered_map<int, int> map;
	for (int i = 0; i < nums.size(); i++) {
		if (map.find(nums[i]) != map.end()) {
			return true;
		}
		map[nums[i]] = i;
	}
	return false;

	// ÅÅĞò
	/*if (nums.size() < 2)
		return false;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size() - 1; i++)
		if (nums[i] == nums[i + 1])
			return true;
	return false;*/
}