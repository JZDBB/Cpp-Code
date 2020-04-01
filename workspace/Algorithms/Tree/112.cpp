#include"tree_func.h"

// 112. Â·¾¶×ÜºÍ

bool tra_total(TreeNode* root, int total, int sum) {
	if (!root) return false;
	total += root->val;
	if (!root->left && !root->right) {
		if (total == sum) return true;
		else return false;
	}
	return tra_total(root->left, total, sum) || tra_total(root->right, total, sum);
}
bool hasPathSum(TreeNode* root, int sum) {
	if (!root) return false;
	return tra_total(root, 0, sum);
}