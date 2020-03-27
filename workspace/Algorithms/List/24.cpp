#include"List_func.h"

// 24. 交换链表中的相邻结点
ListNode* swapPairs(ListNode* head) {
	// 迭代
	ListNode* p = head;
	ListNode* pre = new ListNode(-1);
	pre->next = head;
	ListNode* newHead = pre;
	while (p&&p->next) {
		ListNode* ptr = p->next;
		p->next = ptr->next;
		ptr->next = p;
		pre->next = ptr;
		pre = pre->next;
		pre = pre->next;
		p = p->next;
	}
	return newHead->next;


	// 递归
	if (head == NULL || head->next == NULL) return head;
	ListNode* ptr = head->next;
	head->next = swapPairs(ptr->next);
	ptr->next = head;

	return ptr;
}