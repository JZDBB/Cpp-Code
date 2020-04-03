#include"tree_func.h"

// 145. 二叉树的后序遍历 —— ？？？
void traverse(TreeNode* root, vector<int> &res) {
	if (!root) return;
	traverse(root->left, res);
	traverse(root->right, res);
	res.insert(res.end(), root->val);
}
vector<int> postorderTraversal(TreeNode* root) {
	if (!root) return {};
	vector<int> res;
	// 递归
	// traverse(root, res);

	// 迭代 —— 将前序遍历顺序转换为root->right->left的顺序，随后翻转。

	//stack<TreeNode*> s;
	//TreeNode *cur = root;
	//while (cur || !s.empty()) {
	//	while (cur) {
	//		res.push_back(cur->val);
	//		s.push(cur);
	//		cur = cur->right;         //修改1，先遍历右子树
	//	}
	//	cur = s.top()->left;          //修改2，再遍历左子树
	//	s.pop();
	//}
	//reverse(res.begin(), res.end());

	// 迭代2 —— 建立一个指向前一节点的指针，标记右孩子是否被访问
	TreeNode* cur = root;
	TreeNode* pre = NULL;
	stack<TreeNode*> s;
	while (cur || !s.empty()) {
		while (cur) {
			s.push(cur);
			cur = cur->left;
		}
		cur = s.top();
		if (!cur->right || cur->right == pre) {
			res.push_back(cur->val);
			s.pop();
			pre = cur->right;
			cur = NULL;
		}
		else cur = cur->right;
	}

	return res;
}