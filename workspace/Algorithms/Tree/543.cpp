#include"tree_func.h"

// 543. 二叉树的直径
int height(TreeNode* root) {
	if (!root) return 0;
	return max(height(root->left), height(root->right)) + 1;
}
int length = 0;
int len(TreeNode* root) {
	if (!root) return 0;
	int L = len(root->left);
	int R = len(root->right);
	length = max(L + R, length);
	return max(L, R) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
	// 递归搜索
	/*if (!root) return 0;
	int max = 0;
	stack<TreeNode*> Stack;
	TreeNode* p = root;
	Stack.push(root);
	while (!Stack.empty()) {
		p = Stack.top();
		int length = height(p->left) + height(p->right);
		if (length > max) max = length;
		Stack.pop();
		if (p->right) Stack.push(p->right);
		if (p->left) Stack.push(p->left);		
	}
	return max;*/

	// 优化的递归搜索
	// 时间复杂度：O(N)，每个结点只被访问一次。
	// 空间复杂度：O(Height)，其中 Height 为二叉树的高度。
	// 由于递归函数在递归过程中需要为每一层递归函数分配栈空间，
	// 所以这里需要额外的空间且该空间取决于递归的深度，而递归的深度显然为二叉树的高度，
	// 并且每次递归调用的函数里又只用了常数个变量，所以所需空间复杂度为 O(Height) 。
	len(root);
	return length;
}