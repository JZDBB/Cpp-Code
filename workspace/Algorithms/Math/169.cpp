#include"Math.h"

// 169. ¶àÊıÔªËØ
int majorityElement(vector<int>& nums) {
	unordered_map<int, int> m;
	int size = nums.size() / 2;
	for (auto num : nums) m[num]++;
	for (auto num : m) {
		if (m[num.first] > size) return num.first;
	}
	return 0;
}