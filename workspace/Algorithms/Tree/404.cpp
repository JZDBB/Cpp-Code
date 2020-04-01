#include"tree_func.h"

// 404. 左叶子之和
int sumOfLeftLeaves(TreeNode* root) {
	int sum = 0;
	if (!root) return 0;
	if (!root->left && !root->right) return root->val;
	TreeNode* p;
	queue<pair<TreeNode*, bool>> Queue;
	Queue.push(pair<TreeNode*, bool>(root, 0));
	while (!Queue.empty()) {
		int size = Queue.size();
		for (int i = 0; i < size; i++) {
			p = Queue.front().first;
			if (Queue.front().second == 0 && !p->left && !p->right) sum += p->val;
			else {
				if (p->left) Queue.push(pair<TreeNode*, bool>(p->left, 0));
				if (p->right) Queue.push(pair<TreeNode*, bool>(p->right, 1));
			}
			Queue.pop();
		}
	}
	return sum;

	// 递归方法
	if (!root) return 0;
	if (root->left != NULL && root->left->right == NULL && root->left->left == NULL) return sumOfLeftLeaves(root->right) + root->left->val;
	else return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}