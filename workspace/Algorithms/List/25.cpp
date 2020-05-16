#include"List_func.h"

// 25. K 个一组翻转链表
vector<ListNode*> reverse(ListNode* head, ListNode* tail) {
	ListNode* prev = tail->next;
	ListNode* p = head;
	while (prev != tail) {
		ListNode* next = p->next;
		p->next = prev;
		prev = p;
		p = next;
	}
	return { tail, head };
}
ListNode* reverseKGroup(ListNode* head, int k) {
	ListNode*  h = new ListNode(0);
	h->next = head;
	ListNode* p = h;

	while (head) {
		ListNode* tail = p;
		for (int i = 0; i < k; i++) {
			tail = tail->next;
			if (!tail) return h->next;
		}
		ListNode* next = tail->next;
		vector<ListNode*> res = reverse(head, tail);
		p->next = res[0];
		res[1]->next = next;
		p = res[1];
		head = res[1]->next;
	}
	return h->next;
}