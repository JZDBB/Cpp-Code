#include"tree_func.h"

// 144. 二叉树的前序遍历
vector<int> preorderTraversal(TreeNode* root) {
	if (!root) return {};
	stack<TreeNode*> Stack;
	TreeNode* p = root;
	vector<int> res;
	Stack.push(root);
	while (!Stack.empty()) {
		p = Stack.top();
		Stack.pop();
		res.insert(res.end(), p->val);
		if (p->right) Stack.push(p->right);
		if (p->left) Stack.push(p->left);
	}
	return res;
}