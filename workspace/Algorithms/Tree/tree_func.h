#pragma once
#include<stdio.h>
#include<stack>
#include<queue>
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
