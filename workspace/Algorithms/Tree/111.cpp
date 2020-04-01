#include"tree_func.h"

// 111. 二叉树的最小深度 —— 层次遍历
int minDepth(TreeNode* root) {
	if (!root) return 0;
	int deep = 0;
	queue<TreeNode*> Queue;
	TreeNode* p = root;
	Queue.push(root);
	while (!Queue.empty()) {
		deep++;
		int size = Queue.size();
		for (int i = 0; i < size; i++) {
			p = Queue.front();
			if (p->left == NULL && p->right == NULL) return deep;
			else {
				if (p->left) Queue.push(p->left);
				if (p->right) Queue.push(p->right);
			}
			Queue.pop();
		}
	}
	return 0;
}