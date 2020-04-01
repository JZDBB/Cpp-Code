#include"tree_func.h"

// 101. ¶Ô³Æ¶þ²æÊ÷
bool Symmetric(TreeNode* s, TreeNode* t) {
	if (!s && !t) return true;
	if (!s) return false;
	if (!t) return false;
	if (t->val != s->val) return false;
	return Symmetric(s->left, t->right) && Symmetric(s->right, t->left);
}
bool isSymmetric(TreeNode* root) {

	// µÝ¹é
	if (!root) return true;
	if (!root->right && !root->left) return true;
	return Symmetric(root->left, root->right);

	// µü´ú
	queue<TreeNode*> Queue;
	Queue.push(root->left);
	Queue.push(root->right);
	while (!Queue.empty()) {
		TreeNode* p = Queue.front();
		Queue.pop();
		TreeNode* q = Queue.front();
		Queue.pop();
		if (!p && !q) continue;
		if (!p || !q) return false;
		if (p->val != q->val) return false;
		Queue.push(p->left);
		Queue.push(q->right);
		Queue.push(p->right);
		Queue.push(q->left);
	}
	return true;
}