#include"tree_func.h"

// 653. 两数之和 IV - 输入 BST
bool findTarget(TreeNode* root, int k) {
	unordered_map<int, int> m;
	if (!root) return root;
	TreeNode* p = root;
	stack<TreeNode*> s;
	while (p || !s.empty()) {
		while (p) {
			s.push(p);
			p = p->left;
		}
		p = s.top();
		if (m.find(k - p->val) != m.end()) return true;
		m[p->val]++;
		s.pop();
		p = p->right;
	}
	return false;
}