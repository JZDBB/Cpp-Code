#include"tree_func.h"

// 671. 二叉树中第二小的节点
int findSecondMinimumValue(TreeNode* root) {
	if (!root) return -1;
	queue<TreeNode*> Queue;
	Queue.push(root);
	int min = root->val;
	int min2 = root->val;
	while (!Queue.empty()) {
		int size = Queue.size();
		for (int i = 0; i < size; i++) {
			TreeNode* p = Queue.front();
			if (p->val > min) {
				if (min == min2) min2 = p->val;
				else min2 = min2 < p->val ? min2 : p->val;
			}

			if (p->left) Queue.push(p->left);
			if (p->right) Queue.push(p->right);
			Queue.pop();
		}
	}
	return min2 > min ? min2 : -1;
}