#include"tree_func.h"


int main() {

	TreeNode* root = new TreeNode(1);
	TreeNode* p = root;
	p->left = new TreeNode(2);
	p->right = new TreeNode(3);
	p = p->left;
	p->left = new TreeNode(4);
	p->left = new TreeNode(5);

	int a = diameterOfBinaryTree(root);

	return 0;
}