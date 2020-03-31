#pragma once
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<iostream>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target);

void twoSum(vector<int>& nums, int start_index, int target, vector<vector<int>>& res);

vector<vector<int>> threeSum(vector<int>& nums);

int threeSumClosest(vector<int>& nums, int target);

vector<int> findErrorNums(vector<int>& nums);

bool searchMatrix(vector<vector<int>>& matrix, int target);

vector<int> sortArray(vector<int>& nums);

void SelectSort(vector<int>& nums, int n);