#include"tree_func.h"

// 669. ÐÞ¼ô¶þ²æËÑË÷Ê÷
TreeNode* trimBST(TreeNode* root, int L, int R) {
	if (!root) return root;
	if (root->val > R) return trimBST(root->left, L, R);
	if (root->val < L) return trimBST(root->right, L, R);

	root->left = trimBST(root->left, L, R);
	root->right = trimBST(root->right, L, R);
	
	return root;
}