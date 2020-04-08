#include"tree_func.h"

// 783. 二叉搜索树结点最小距离
int minDiffInBST(TreeNode* root) {
	if (!root) return 0;
	int min = INT_MAX;
	int temp = INT_MAX;
	TreeNode* p = root;
	stack<TreeNode*> s;
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