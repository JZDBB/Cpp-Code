#include"tree_func.h"

// 1367. 二叉树中的列表
bool dfs(ListNode* head, TreeNode* root) {
	if (head == NULL) return true;
	if (root == NULL) return false;
	if (head->val != root->val) return false;
	return dfs(head->next, root->left) || dfs(head->next, root->right);
}

bool isSubPath(ListNode* head, TreeNode* root) {
	if (root == NULL) return false;
	return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
}