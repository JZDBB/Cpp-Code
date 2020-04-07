#include"tree_func.h"

// 538. 把二叉搜索树转换为累加树
TreeNode* convertBST(TreeNode* root) {
	if (!root) return root;
	TreeNode* p = root;
	stack<TreeNode*> s;
	int sum = 0;
	while (p || !s.empty()) {
		while (p) {
			s.push(p);
			p = p->right;
		}
		p = s.top();
		p->val += sum;
		sum = p->val;
		s.pop();
		p = p->left;
	}
	return root;
}