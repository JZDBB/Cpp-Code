#include"List_func.h"

ListNode* swapPairs(ListNode* head) {
	ListNode* newHead = head;
	ListNode* p = head;
	ListNode* pre = new ListNode(-1);
	pre->next = head;
	while (p&&p->next) {
		ListNode* ptr = p->next;
		p->next = ptr->next;
		ptr->next = p;
		pre->next = ptr;
		pre = pre->next;
		pre = pre->next;
		p = p->next;
	}
	return newHead;
}