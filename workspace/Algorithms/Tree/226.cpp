#include"tree_func.h"

// 226. ·­×ª¶þ²æÊ÷
TreeNode* invertTree(TreeNode* root) {
	if (!root) return root;
	queue<TreeNode*> Queue;
	Queue.push(root);
	while (!Queue.empty()) {
		int size = Queue.size();
		for (int i = 0; i < size; i++) {
			TreeNode* p = Queue.front();
			TreeNode* inter = p->right;
			p->right = p->left;
			p->left = inter;
			if (p->left) Queue.push(p->left);
			if (p->right) Queue.push(p->right);
			Queue.pop();
		}
	}
	return root;
}