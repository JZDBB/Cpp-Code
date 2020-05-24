#pragma once
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target);

void twoSum(vector<int>& nums, int start_index, int target, vector<vector<int>>& res);

vector<vector<int>> threeSum(vector<int>& nums);

int threeSumClosest(vector<int>& nums, int target);

vector<int> findErrorNums(vector<int>& nums);

bool searchMatrix(vector<vector<int>>& matrix, int target);

vector<int> sortArray(vector<int>& nums);

void SelectSort(vector<int>& nums, int n);

int numberOfSubarrays(vector<int>& nums, int k);

int reversePairs(vector<int>& nums);

vector<vector<int>> permute(vector<int>& nums);

class MountainArray {
private:
	vector<int> arr;
public:
	void init(vector<int> m) { arr = m; };
	int get(int index) { return arr[index]; };
	int length() { return arr.size(); };
};

int findInMountainArray(int target, MountainArray &mountainArr);

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);