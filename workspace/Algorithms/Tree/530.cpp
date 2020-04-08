#include"tree_func.h"

// 530. 二叉搜索树的最小绝对差
int getMinimumDifference(TreeNode* root) {
	TreeNode* p = root;
	stack<TreeNode*> s;
	int temp;
	int min = INT_MAX;
	while (p || !s.empty()) {
		while (p) {
			s.push(p);
			p = p->left;
		}
		p = s.top();
		min = abs(p->val - temp) < min ? abs(p->val - temp) : min;
		temp = p->val;
		s.pop();
		p = p->right;
	}
	return min;
}