#include"List_func.h"

// 2. 两数相加
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	int mi = 0;

	ListNode* res = new ListNode(-1);
	ListNode* p = res;
	ListNode* x = l1;
	ListNode* y = l2;
	p->val = (x->val + y->val + mi) % 10;
	mi = (x->val + y->val) / 10;
	x = x->next;
	y = y->next;

	while ((x != NULL) && (y != NULL)) {
		p->next = new ListNode((x->val + y->val + mi) % 10);
		mi = (x->val + y->val + mi) / 10;
		x = x->next;
		y = y->next;
		p = p->next;
	}
	if (x == NULL) {
		while (y != NULL) {
			p->next = new ListNode((mi + y->val) % 10);
			mi = (mi + y->val) / 10;
			y = y->next;
			p = p->next;
		}
	}
	else {
		while (x != NULL) {
			p->next = new ListNode((mi + x->val) % 10);
			mi = (mi + x->val) / 10;
			x = x->next;
			p = p->next;
		}
	}
	if (mi) p->next = new ListNode(1);

	return res;
}