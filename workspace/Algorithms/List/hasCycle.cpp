#include"List_func.h"

// 链表判断是否有环 ——无环则返回false，有环则陷入死循环【需要优化】
bool hasCycle(ListNode* head) {
	while (head != NULL)
		head = head->next;
	return false;
};