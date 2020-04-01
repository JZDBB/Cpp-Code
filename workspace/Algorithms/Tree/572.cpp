#include"tree_func.h"

// 572. 另一个树的子树
bool isSame(TreeNode* s, TreeNode* t) {
	if (s == NULL && t == NULL) return true;
	if (s == NULL) return false;
	if (t == NULL) return false;
	return s->val == t->val&&isSame(s->left, t->left) && isSame(s->right, t->right);
}
bool isSubtree(TreeNode* s, TreeNode* t) {
	if (s == NULL && t == NULL) return true;
	if (s == NULL) return false;
	if (t == NULL) return false;

	return isSame(s, t)
		|| isSubtree(s->left, t) || isSubtree(s->right, t);
}



