#include<stdio.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

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
	}else{
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


int main() {
	ListNode* l1 = new ListNode(3);
	ListNode* l2 = new ListNode(9);
	ListNode* x = l1;
	x->next = new ListNode(7);
	ListNode* y = l2;
	y->next = new ListNode(2);
	ListNode* m = addTwoNumbers(l1, l2);


	return 0;
}