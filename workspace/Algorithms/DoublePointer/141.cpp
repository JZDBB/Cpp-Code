#include"doublePointer.h"


// 141. 环形链表 —— 快慢指针应用
bool hasCycle(ListNode *head) {
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow) return true;
	}
	return false;
}


// 142. 环形链表 II
//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
//为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 
//如果 pos 是 - 1，则在该链表中没有环。
//说明：不允许修改给定的链表。
ListNode *detectCycle(ListNode *head) {
	if (head == NULL) return NULL;
	if (head->next == NULL) return NULL;
	ListNode* fast = head;
	ListNode* slow = head;
	int len = 0;
	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow) {
			slow = head;
			while (slow != fast) {
				slow = slow->next;
				fast = fast->next;
			}
			return slow;
		}
	}
	return NULL;
}

