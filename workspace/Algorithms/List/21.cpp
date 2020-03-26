#include"List_func.h"

// 21. 合并两个有序链表
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode* newhead = new ListNode(-1);
	ListNode* p = newhead;
	ListNode* node;
	while (l1&&l2) {
		if (l1->val <= l2->val) {
			node = l1;
			l1 = l1->next;
		}else{
			node = l2;
			l2 = l2->next;
		}
		p->next = node;
		p = p->next;
	}
	/*while (l1) {
		node = l1;
		p->next = node;
		p = p->next;
		l1 = l1->next;
	}
	while (l2) {
		node = l2;
		p->next = node;
		p = p->next;
		l2 = l2->next;
	}*/
	// 改
	p->next = l1 ? l1 : l2;
	
	return newhead->next;
}