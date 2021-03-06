#pragma once
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<iostream>
#include<queue>
#include<unordered_set>
#include<stack>
#include<string>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int lengthOfLIS(vector<int>& nums);

int superEggDrop(int K, int N);

int findLongestChain(vector<vector<int>>& pairs);

bool isMatch(string s, string p);

int findTargetSumWays(vector<int>& nums, int S);

bool wordBreak(string s, vector<string>& wordDict);

int findMaxForm(vector<string>& strs, int m, int n);