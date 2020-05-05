#include"tree_func.h"

// 98. ÑéÖ¤¶þ²æËÑË÷Ê÷
bool isValidBST(TreeNode* root) {
	if (!root) return true;
	stack<TreeNode*> s;
	TreeNode* p = root;
	vector<int> nums;
	while (p||!s.empty()) {
		while (p) {
			s.push(p);
			p = p->left;
		}
		p = s.top();
		s.pop();
		nums.push_back(p->val);
		p = p->right;
	}

	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] <= nums[i - 1]) return false;
	}
	return true;
}