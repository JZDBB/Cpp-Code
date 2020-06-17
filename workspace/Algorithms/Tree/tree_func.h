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


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


int diameterOfBinaryTree(TreeNode* root);

bool isSubtree(TreeNode* s, TreeNode* t);

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2);

int pathSum(TreeNode* root, int sum);

vector<int> postorderTraversal(TreeNode* root);

TreeNode* sortedArrayToBST(vector<int>& nums);

TreeNode* sortedListToBST(ListNode* head);

bool isValidBST(TreeNode* root);
vector<int> inorderTraversal(TreeNode* root);

string serialize(TreeNode* root);
TreeNode* deserialize(string data);

