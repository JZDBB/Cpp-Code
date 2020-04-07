#include"tree_func.h"

// 235. 二叉搜索树的最近公共祖先
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	int pVal = p->val;
	int qVal = q->val;
	TreeNode* node = root;
	while (node) {
		int Val = node->val;
		if (pVal > Val && qVal > Val) node = node->right;
		else if (pVal < Val && qVal < Val) node = node->left;
		else return node;
	}
	return NULL;
}