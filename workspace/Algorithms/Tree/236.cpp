#include"tree_func.h"

// 236. 二叉树的最近公共祖先 —— ***
bool isAncestor(TreeNode* root, TreeNode* p) {
	if (!root) return false;
	if (root->left == p || root->right == p) return true;
	return isAncestor(root->left, p) || isAncestor(root->right, p);
}

bool getPath(TreeNode* root, TreeNode* p, vector<char>& v)
{
	if (root == nullptr)
		return false;
	if (root == p)
		return true;

	v.push_back('L');
	bool flag = getPath(root->left, p, v);
	if (flag == true)
		return true;
	else
	{
		v.pop_back();
		v.push_back('R');
		flag = getPath(root->right, p, v);
		if (flag == true)
			return true;
		else
		{
			v.pop_back();
			return false;
		}
	}
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	// 递归方法
	if (!root || root == p || root == q) return root;
	TreeNode* left = lowestCommonAncestor(root->left, p, q);
	TreeNode* right = lowestCommonAncestor(root->right, p, q);
	if (left && right) return root;
	return left ? left : right;

	// 递归遍历
	/*if (root == nullptr || root == p || root == q)
		return root;

	vector<char> pathp, pathq;
	getPath(root, p, pathp);
	getPath(root, q, pathq);

	TreeNode* rec = root;
	for (int i = 0; i < pathp.size() && i < pathq.size(); i++)
	{
		if (pathp[i] == 'L' && pathq[i] == 'L')
			rec = rec->left;
		else if (pathp[i] == 'R' && pathq[i] == 'R')
			rec = rec->right;
		else
			break;
	}
	return rec;*/

	// 迭代方法

}