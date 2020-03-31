#include"tree_func.h"

//110. Æ½ºâ¶þ²æÊ÷

//int height(TreeNode* root) {
//	if (!root) return 0;
//	return max(height(root->left) + 1, height(root->right) + 1);
//}

int checkBalanced(TreeNode* root) {
	if (!root) return 0;
	int L = checkBalanced(root->left);
	if (L < 0) return L;
	int R = checkBalanced(root->right);
	if (R < 0) return R;
	if (abs(L - R) < 2) return max(L, R) + 1;
	else return -1;
}

bool isBalanced(TreeNode* root) {
	// µÝ¹é
	/*if (!root) return true;
	return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
	*/

	// ×Ôµ×¶øÉÏÅÐ¶ÏÆ½ºâ¶þ²æÊ÷ 
	if (!root) return true;
	return checkBalanced(root) >= 0;
	
}