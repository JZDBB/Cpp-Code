#include"tree_func.h"

// 109. 有序链表转换二叉搜索树
TreeNode* sortedListToBST(ListNode* head) {
	// 找链表中点递归 —— 时间复杂度：O(NlogN)。
	if (!head) return nullptr;
	ListNode* fast = head;
	ListNode* slow = head;
	ListNode* pre = slow;
	while (fast && fast->next) {
		fast = fast->next->next;
		pre = slow;
		slow = slow->next;
	}
	TreeNode* root = new TreeNode(slow->val);
	root->right = sortedListToBST(slow->next);
	pre->next = NULL;
	if (head != slow) root->left = sortedListToBST(head);

	return root;

	// 
}