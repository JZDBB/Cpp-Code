#include"tree_func.h"

// 637. 二叉树的层平均值
vector<double> averageOfLevels(TreeNode* root) {
	if (!root) return {0};
	vector<double> a;
	queue<TreeNode*> Queue;
	TreeNode* p = root;
	Queue.push(root);
	while (!Queue.empty()) {
		double total = 0;
		int size = Queue.size();
		for (int i = 0; i < size; i++) {
			p = Queue.front();
			total += p->val;
			if (p->left) Queue.push(p->left);
			if (p->right) Queue.push(p->right);
			Queue.pop();
		}
		a.insert(a.end(), total / size);
	}
	return a;
}