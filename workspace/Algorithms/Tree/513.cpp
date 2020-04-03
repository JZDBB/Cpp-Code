#include"tree_func.h"

// 513. ÕÒÊ÷×óÏÂ½ÇµÄÖµ
int findBottomLeftValue(TreeNode* root) {
	if (!root) return 0;
	int m;
	queue<TreeNode*> Queue;
	TreeNode* p = root;
	Queue.push(root);
	while (!Queue.empty()) {
		m = Queue.front()->val;
		int size = Queue.size();
		for (int i = 0; i < size; i++) {
			p = Queue.front();
			if (p->left) Queue.push(p->left);
			if (p->right) Queue.push(p->right);
			Queue.pop();
		}
	}
	return m;
}