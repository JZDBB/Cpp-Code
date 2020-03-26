#include"List_func.h"

// 160. 相交链表
// A:        a1 → a2
//					 ↘
//					   c1 → c2 → c3
//					 ↗
// B : b1 → b2 → b3
//
// a+c+b = b+c+a 交替遍历
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	ListNode* pA = headA;
	ListNode* pB = headB;
	while (pA != pB) {
		pA = pA == NULL ? headB : pA->next;
		pB = pB == NULL ? headA : pB->next;
	}
	return pA;
}