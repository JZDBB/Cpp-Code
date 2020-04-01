#include"tree_func.h"

// 687. 最长同值路径
int max_len = 0;
int traverse(TreeNode* root, int ans) {
	if (!root) return 0;
	int L = traverse(root->left, ans);
	int R = traverse(root->right, ans);
	if (root->left && root->right) {
		if (root->left->val == root->val && root->right->val == root->val) return L + R + 1;
		else
		{

		}
	}
	return max(L, R);
}
int longestUnivaluePath(TreeNode* root) {
	if (!root) return 0;
	return traverse(root, root->val);
}