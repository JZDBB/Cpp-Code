#include"tree_func.h"

// 687. 最长同值路径
int traverse(TreeNode* root, int &ans) {
	if (!root) return 0;
	int L = traverse(root->left, ans);
	int R = traverse(root->right, ans);
	
	L = (root->left && root->left->val == root->val) ? L + 1 : 0;
	R = (root->right && root->right->val == root->val) ? R + 1 : 0;

	ans = max(L + R, ans);
	return max(L, R);
}
int longestUnivaluePath(TreeNode* root) {
	int res = 0;
	traverse(root, res);
	return res;
}