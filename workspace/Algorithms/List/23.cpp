#include"List_func.h"

// 23. 合并K个排序链表
ListNode* mergeKLists(vector<ListNode*>& lists) {
	if (lists.size() == 0) return NULL;
	ListNode* head = new ListNode(-1);
	ListNode* cur = head;
	ListNode* p;
	int index = 0;
	p = lists[0];
	while (1) {
		for (int i = 0; i < lists.size(); i++) {
			if (p->val > lists[i]->val) {
				p = lists[i];
				index = i;
			}
		}
		cur->next = new ListNode(p->val);
		cur = cur->next;
		p = p->next;
		if (!p) lists.erase(lists.begin() + index);
		if (lists.size() == 0) break;
	}
	return head->next;
}