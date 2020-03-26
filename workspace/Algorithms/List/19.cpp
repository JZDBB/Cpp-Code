#include"List_func.h"

ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode* newHead = new ListNode(-1);
	newHead->next = head;
	
	ListNode* pre = newHead;
	ListNode* cur = newHead;

	for (int i = 0; i < n + 1; i++) {
		pre = pre->next;
	}
	while (pre) {
		cur = cur->next;
		pre = pre->next;
	}
	ListNode* ptr = cur->next;
	cur->next = ptr->next;
	delete ptr;
	return newHead->next;
}