#include"tree_func.h"

// 501. 二叉搜索树中的众数
vector<int> findMode(TreeNode* root) {
	if (!root) return {};
	vector<int> res;
	int ans = 0;
	int max = 0;
	int temp = INT_MAX;
	TreeNode* p = root;
	stack<TreeNode*> s;
	while (p || !s.empty()) {
		while (p) {
			s.push(p);
			p = p->left;
		}
		p = s.top();
		if (temp == p->val) ans++;
		else ans = 0;
		if (ans == max)  res.push_back(p->val);
		else if (ans > max) {
			max = ans;
			res.clear();
			res.push_back(p->val);
		}
		temp = p->val;
		s.pop();
		p = p->right;
	}
	return res;
}