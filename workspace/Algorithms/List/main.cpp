#include<stdio.h>
using namespace std;
#include"List_func.h"


int main() {
	/*ListNode* l1 = new ListNode(-9);
	ListNode* l2 = new ListNode(5);
	ListNode* x = l1;
	x->next = new ListNode(3);
	ListNode* y = l2;
	y->next = new ListNode(7);
	ListNode* m = mergeTwoLists(l1, l2);*/

	ListNode* l1 = new ListNode(1);
	ListNode* p = l1;
	p->next = new ListNode(2);
	p = p->next;
	p->next = new ListNode(3);
	p = p->next;
	p->next = new ListNode(4);
	/*p = p->next;
	p->next = new ListNode(5);*/
	ListNode* m = swapPairs(l1);


	return 0;
}