#include"tree_func.h"

//104. Maximum Depth of Binary Tree
int maxDepth(TreeNode* root) {
	// 递归算法 —— 缺点在于如果层级过深，会报错过多临时变量，导致栈溢出。
	/*if (!root) return 0;
	return maxDepth(root->left) + 1 > maxDepth(root->right) + 1 ? maxDepth(root->left) + 1 : maxDepth(root->right) + 1;*/

	// DFS —— 像一个中序遍历（栈遍历）
	if (root == NULL) return 0;
	stack<pair<TreeNode*, int>> Stack;
	TreeNode* p = root;
	int res = 0;
	int deep = 0;
	while (!Stack.empty() || p != NULL) {
		while (p != NULL) { // 先一直访问左子树，存入栈中
			Stack.push(pair<TreeNode*, int>(p, ++deep));
			p = p->left;
		}
		p = Stack.top().first; // 记录根节点，和左子树深度
		deep = Stack.top().second;
		if (res < deep) res = deep;
		Stack.pop(); // 弹出根节点
		p = p->right; // 访问右子树
	}
	return res;

	// BFS —— 队列遍历
	/*if (root == NULL) return 0;
	queue<TreeNode*> Queue;
	TreeNode* p = root;
	Queue.push(root);
	int res = 0;
	while (!Queue.empty()) {
		res++;
		int size = Queue.size();
		for (int i = 0; i < size; i++) {
			TreeNode* p = Queue.front();
			Queue.pop();
			if (p->left) Queue.push(p->left);
			if (p->right) Queue.push(p->right);
		}
	}
	return res;*/
}
