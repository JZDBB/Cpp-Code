#include"tree_func.h"

// 617. 合并二叉树
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
	// 递归
	TreeNode* cur = t1;
	if (t2 == NULL) return t1;
	if (t1 == NULL) return t2;
	cur->val = t1->val + t2->val;
	cur->left = mergeTrees(t1->left, t2->left);
	cur->right = mergeTrees(t1->right, t2->right);
	return cur;


	// 迭代
	if (!t1 && !t2) return t1;
	if (!t1 || !t2) return !t1 ? t2 : t1;
	queue<TreeNode*> Queue, R;
	TreeNode* root = new TreeNode(t1->val+t2->val);
	Queue.push(t1);
	Queue.push(t2);
	R.push(root);
	while (!Queue.empty()) {
		int size = R.size();
		for (int i = 0; i < size; i++) {
			TreeNode* p = Queue.front();
			Queue.pop();
			TreeNode* q = Queue.front();
			Queue.pop();
			TreeNode* r = R.front();
			R.pop();
			if (q->left && p->left) {
				r->left = new TreeNode(p->left->val + q->left->val);
				Queue.push(p->left);
				Queue.push(q->left);
				R.push(r->left);
			}
			if (!q->left || !p->left) {
				r->left = !q->left ? p->left : q->left;
			}
			if (q->right && p->right) {
				r->right = new TreeNode(p->right->val + q->right->val);
				Queue.push(p->right);
				Queue.push(q->right);
				R.push(r->right);
			}
			if (!q->right || !p->right) {
				r->right = !q->right ? p->right : q->right;
			}
		}
	}
	return root;
}