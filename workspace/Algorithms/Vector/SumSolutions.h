#pragma once
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class SumSolutions
{
public:
	SumSolutions();
	~SumSolutions();
	vector<int> twoSum(vector<int>& nums, int target);
	void twoSum(vector<int>& nums, int start_index, int target, vector<vector<int>>& res);
	vector<vector<int>> threeSum(vector<int>& nums);
	int threeSumClosest(vector<int>& nums, int target);
};

