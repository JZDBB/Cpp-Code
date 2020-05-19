#include"Math.h"

// 268. È±Ê§Êý×Ö

int missingNumber(vector<int>& nums) {
	int len = nums.size();
	unordered_set<int> sets;
	for (int i = 0; i <= len; i++) sets.insert(i);
	for (int i : nums) {
		if (sets.count(i)) sets.erase(i);
	}
	return *sets.begin();
}
// Òì»òËã·¨
int missingNumber2(vector<int>& nums) {
	int miss = nums.size();
	for (int i = 0; i < nums.size(); i++) {
		miss ^= (i^nums[i]);
	}
	return miss;
}