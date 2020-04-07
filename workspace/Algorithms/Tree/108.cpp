#include"tree_func.h"

// 108. 将有序数组转换为二叉搜索树
TreeNode* sortedArrayToBST(vector<int>& nums) {
	int n = nums.size();
	if (n == 0) return nullptr;
	TreeNode* root = new TreeNode(nums[n / 2]);
	vetor<int> left;
	root->left = sortedArrayToBST();
}