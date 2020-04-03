#pragma once
#include<stdio.h>
#include<stack>
#include<queue>
#include<unordered_map>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int diameterOfBinaryTree(TreeNode* root);

bool isSubtree(TreeNode* s, TreeNode* t);

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2);

int pathSum(TreeNode* root, int sum);

vector<int> postorderTraversal(TreeNode* root);
