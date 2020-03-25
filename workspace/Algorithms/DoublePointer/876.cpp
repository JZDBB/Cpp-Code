#include"doublePointer.h"

// 876. 链表的中间结点
ListNode* middleNode(ListNode* head) {
	if (head == NULL) return NULL;
	ListNode* slow = head;
	ListNode* fast = head;
	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}