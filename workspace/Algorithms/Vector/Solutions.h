#pragma once
#include<vector>
#include<unordered_map>
using namespace std;

class Solutions
{
public:
	Solutions();
	~Solutions();
	vector<int> twoSum(vector<int>& nums, int target);
	vector<vector<int>> threeSum(vector<int>& nums);
};

