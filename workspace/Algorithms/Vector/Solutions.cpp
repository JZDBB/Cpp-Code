#include "Solutions.h"



Solutions::Solutions()
{
}


Solutions::~Solutions()
{
}

vector<int> Solutions::twoSum(vector<int>& nums, int target)
{
	// 蛮力
	/*for (int i = 0; i < nums.size(); i++) {
		int sub = target - nums[i];
		for (int j = i+1; j < nums.size(); j++) {
			if ((j != i) && (nums[j] == sub)) return { i, j };
		}
	}*/

	// 哈希
	unordered_map<int, int> m;

	for (int i = 0; i < nums.size(); i++)
	{
		if (m.find(target - nums[i]) != m.end())       //m中存在对应的键值
			return { m[target - nums[i]] , i };         //因为i为较大的元素，此时添加进去的键值都还小于i，所以i在后面

		m[nums[i]] = i;       //向map中添加元素
	}

	return {};
}


vector<vector<int>> Solutions::threeSum(vector<int>& nums) {
	vector<vector<int>> res;
	if (nums.size() <= 2) return res;

	sort(nums.begin(), nums.end());

	
	return res;
}