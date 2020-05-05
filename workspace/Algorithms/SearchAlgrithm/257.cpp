#include"Search.h"

// 257. 二叉树的所有路径
string to_str(int nums) {
	bool flag = false;
	if (nums < 0) { flag = true; nums = -nums; }
	string s = "";
	while (nums) {
		s.insert(s.begin(), nums % 10 + '0');
		nums /= 10;
	}
	if (flag) s.insert(s.begin(), '-');
	return s;
}

// 递归

//vector<string> binaryTreePaths(TreeNode* root) {
//	if (!root) return {};
//	vector<string> res;
//	if (!root->left && !root->right) return { to_str(root->val) };
//	else {
//		vector<string> l, r;
//		l = binaryTreePaths(root->left);
//		r = binaryTreePaths(root->right);
//		for (auto l0 : l) res.push_back(to_str(root->val) + "->" + l0);
//		for (auto l0 : r) res.push_back(to_str(root->val) + "->" + l0);
//	}
//	return res;
//}

// 迭代
vector<string> binaryTreePaths(TreeNode* root) {
	vector<string> res;
	queue<pair<TreeNode*, string>> Q;
	Q.push(pair<TreeNode*, string>(root, to_str(root->val)));
	while (!Q.empty()) {
		for (int i = Q.size(); i > 0; i--) {
			TreeNode* p = Q.front().first;
			string s = Q.front().second;
			Q.pop();
			if (!p->left && !p->right) res.push_back(s);
			if (p->left) Q.push(pair<TreeNode*, string>(p->left, s + "->" + to_str(p->left->val)));
			if (p->right) Q.push(pair<TreeNode*, string>(p->right, s + "->" + to_str(p->right->val)));
		}
	}
	return res;
}