#include"List_func.h"
#include<stack>

// 445. 两数相加 II
ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
	// me 超出内存限制
	/*stack<int> s1, s2, s;
	int mi = 0;
	while (l1) {
		s1.push(l1->val);
		l1 = l1->next;
	}
	while (l2) {
		s2.push(l2->val);
		l2 = l2->next;
	}

	while (!s1.empty() && !s2.empty()) {
		int sum = s1.top() + s2.top() + mi;
		s.push(sum % 10);
		mi = sum / 10;
		s1.pop();
		s2.pop();
	}
	while (!s1.empty()) {
		int sum = s1.top() + mi;
		s.push(sum % 10);
		mi = sum / 10;
		s1.pop();
	}
	while (!s2.empty()) {
		int sum = s2.top() + mi;
		s.push(sum % 10);
		mi = sum / 10;
		s2.pop();
	}
	ListNode*  res = new ListNode(-1);
	ListNode* p = res;
	while (!s.empty()) {
		p->next = new ListNode(s.top());
		p = p->next;
		s.pop();
	}
	while (mi != 0) p->next = new ListNode(mi);
	return res->next;*/

	// 改进版 —— 减少一个栈
	stack<int> s1, s2;
	while (l1) {
		s1.push(l1->val);
		l1 = l1->next;
	}
	while (l2) {
		s2.push(l2->val);
		l2 = l2->next;
	}
	int carry = 0;
	ListNode* pre = nullptr;
	ListNode* node = nullptr;

	while (!s1.empty() || !s2.empty() || carry) {
		int x = s1.empty() ? 0 : s1.top();
		int y = s2.empty() ? 0 : s2.top();
		if (!s1.empty()) s1.pop();
		if (!s2.empty()) s2.pop();

		int sum = x + y + carry;
		carry = sum / 10;
		// 头结点插入
		pre = node;
		node = new ListNode(sum % 10);
		node->next = pre;
	}
	return node;
}

ListNode *reverseList1(ListNode *head) {
	ListNode *prev = NULL;
	ListNode *cur = head;
	ListNode *next = NULL;
	while (cur) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}

ListNode* addTwoNumbers3(ListNode* l1, ListNode* l2) {
	if (l1 == NULL && l2 == NULL) {
		return NULL;
	}
	ListNode *head1 = reverseList1(l1);
	ListNode *head2 = reverseList1(l2);
	int flag = 0;
	ListNode dummy(-1);
	ListNode *prev = &dummy;
	while (head1 || head2) {
		int val1 = head1 ? head1->val : 0;
		int val2 = head2 ? head2->val : 0;
		int result = (val1 + val2 + flag);
		flag = result / 10;
		ListNode *node = new ListNode(result % 10);
		prev->next = node;
		prev = prev->next;
		head1 = head1 ? head1->next : NULL;
		head2 = head2 ? head2->next : NULL;
	}
	if (flag) {
		prev->next = new ListNode(flag);
	}
	return reverseList1(dummy.next);
}

