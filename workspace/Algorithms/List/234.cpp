#include"List_func.h"
#include<vector>

// 234. 回文链表
bool isPalindrome(ListNode* head) {
	// 开销过大
	/*ListNode* newlist = reverseList(head);
	while (head) {
		if (newlist->val != head->val) return false;

	}
	return true;*/

	// 存放在数组内判断
	/*vector<int> a;
	while (head) {
		a.insert(a.end(), head->val);
		head = head->next;
	}
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != a[a.size() - i - 1]) return false;
	}
	return true;*/

	// 中点反转
	if (head->next == NULL) return true;
	ListNode* pre = NULL;
	ListNode* slow = head;
	while (head&&head->next) { // 找中点的同时翻转前半段
		head = head->next->next;
		ListNode* next = slow->next;
		slow->next = pre;
		pre = slow;
		slow = next;
	}
	//单数链表和双数链表不一样!!!
	if (head) {
		slow = slow->next;
	}
	while (slow&& pre) {
		if (head->val != slow->val) return false;
		head = head->next;
		slow = slow->next;
	}
	return true;

}