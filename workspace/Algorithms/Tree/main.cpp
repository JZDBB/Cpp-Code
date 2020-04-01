#include"tree_func.h"


int main() {

	TreeNode* root = new TreeNode(3);
	TreeNode* p = root;
	p->left = new TreeNode(4);
	p->right = new TreeNode(5);
	p = p->left;
	p->left = new TreeNode(1);
	p->right = new TreeNode(2);

	TreeNode* t = new TreeNode(4);
	t->left = new TreeNode(1);
	t->right = new TreeNode(2);

	bool a = isSubtree(root, t);

	return 0;
}