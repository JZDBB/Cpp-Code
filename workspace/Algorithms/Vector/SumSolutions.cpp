#include "SumSolutions.h"



SumSolutions::SumSolutions()
{
}


SumSolutions::~SumSolutions()
{
}

vector<int> SumSolutions::twoSum(vector<int>& nums, int target)
{
	// 蛮力
	/*for (int i = 0; i < nums.size(); i++) {
		int diff = target - nums[i];
		for (int j = i+1; j < nums.size(); j++) {
			if ((j != i) && (nums[j] == diff)) return { i, j };
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


void SumSolutions::twoSum(vector<int>& nums, int start_index, int target, vector<vector<int>>& res) {

	int left = start_index;
	int right = (int)nums.size() - 1;

	while (left < right){
		int diff = target - nums[right];
		if (diff == nums[left]){
			res.push_back(vector<int>{-target, nums[left], nums[right]});

			//去重
			while (left < right && nums[left] == diff) ++left;
			int right_val = nums[right];
			while (left < right && nums[right] == right_val) --right;
		}
		else if (diff < nums[left]) --right;
		else ++left;
	}
}

vector<vector<int>> SumSolutions::threeSum(vector<int>& nums) {
	vector<vector<int>> res;
	if (nums.size() <= 2) return res;

	sort(nums.begin(), nums.end());

	int last_num = 1;
	for (int i = 0; i < nums.size()-2; i++) {
		if (nums[i] > 0) break;
		if (last_num == nums[i]) continue; // 去重
		last_num = nums[i];
		
		twoSum(nums, i + 1, -nums[i], res);
	}
	return res;
}

int SumSolutions::threeSumClosest(vector<int>& nums, int target) {
	int ans = nums[0] + nums[1] + nums[2];
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size()-2; i++) {
		int start = i + 1;
		int end = nums.size() - 1;
		while (start < end) {
			int sum = nums[i] + nums[start] + nums[end];
			if (abs(sum - target) < abs(ans-target)) ans = sum;
			if (sum < target) ++start;
			else if (sum > target) --end;
			else return ans;
		}
	}
	return ans;

}