#include"tree_func.h"

// 124. 二叉树中的最大路径和
int traverse124(TreeNode* root, int & sum) {
	if (!root) return 0;
	int sumL = traverse124(root->left, sum);
	int sumR = traverse124(root->right, sum);

	int ans = max(sumL + root->val, sumR + root->val);
	sum = max(sum, ans);
	sum = max(sum, sumL + sumR + root->val);
	return max(ans, root->val);
}
int maxPathSum(TreeNode* root) {
	if (!root) return 0;
	int res = root->val;
	traverse124(root, res);
	return res;
}