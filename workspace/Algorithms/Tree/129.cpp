#include"tree_func.h"

// 129. 求根到叶子节点数字之和
int total = 0;
void compute(TreeNode* root, int ans) {
	if (!root->left && !root->right) total += ans * 10 + root->val;
	if (root->left) compute(root->left, ans * 10 + root->val);
	if (root->right) compute(root->right, ans * 10 + root->val);
}
int sumNumbers(TreeNode* root) {
	if (!root) return 0;
	compute(root, 0);
	return total;
}