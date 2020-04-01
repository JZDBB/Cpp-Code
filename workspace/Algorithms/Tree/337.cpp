#include"tree_func.h"

// 337. 打家劫舍 III —— 动态规划 ？？？未解决
int rob(TreeNode* root) {
	if (!root) return 0;
	queue<TreeNode*> Queue;
	int first = 0;
	int second = 0;
	bool flag = 0;
	Queue.push(root);
	while (!Queue.empty()) {
		int size = Queue.size();
		int total = 0;
		for (int i = 0; i < size; i++) {
			TreeNode* p = Queue.front();
			if(p) total += p->val;
			if (p->left) Queue.push(p->left);
			if (p->right) Queue.push(p->right);
			Queue.pop();
		}
		if (!flag) first += total;
		else second += total;
		flag = !flag;
	}
	return first > second ? first : second;
}