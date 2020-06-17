#include"tree_func.h"


int main() {

	TreeNode* root1 = new TreeNode(1);
	TreeNode* p = root1;
	p->left = new TreeNode(2);
	p->right = new TreeNode(3);
	p->right->left = new TreeNode(4);
	p->right->right = new TreeNode(5);
	
	string s = serialize(root1);
	TreeNode* root2 = deserialize(s);


	return 0;
}