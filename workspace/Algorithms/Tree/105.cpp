#include"tree_func.h"

// 105. 从前序与中序遍历序列构造二叉树
TreeNode* Tree(vector<int>& preorder, vector<int>& inorder, int left1, int right1, int left2, int right2) {
	TreeNode* root;
	if (left1 > right1) {
		return NULL;
	}
	root = new TreeNode(preorder[left1]);
	int i;
	for (i = left2; i < right2; i++) {
		if (inorder[i] == preorder[left1]) break;
	}
	root->left = Tree(preorder, inorder, left1 + 1, left1 + i - left2, left2, i - 1);
	root->right = Tree(preorder, inorder, left1 + i - left2 + 1, right1, i + 1, right2);
	return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	if (preorder.size() == 0 || inorder.size() == 0) return NULL;
	return Tree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}