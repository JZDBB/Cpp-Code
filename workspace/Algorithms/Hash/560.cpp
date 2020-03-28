#include"hash.h"

// 560.和为K的子数组
int subarraySum(vector<int>& nums, int k) {
	// 蛮力
	/*int count = 0;
	for (int i = 0; i < nums.size(); i++) {
		int sum = nums[i];
		if (sum == k) count++;
		for (int j = i+1; j < nums.size(); j++) {
			sum += nums[j];
			if (sum == k) count++;
		}
	}*/

	// 哈希
	int count = 0;
	int sum = 0;
	unordered_map<int, int> m;
	m[0] = 1;

	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
		if (m.find(sum - k) != m.end()) count += m[sum - k];
		m[sum] ++;
	}
	return count;
}