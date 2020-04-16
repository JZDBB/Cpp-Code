#pragma once
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<string>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};