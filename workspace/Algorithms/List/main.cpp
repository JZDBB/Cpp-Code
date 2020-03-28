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
	p->next = new ListNode(3);
	p = p->next;
	p->next = new ListNode(4);
	p = p->next;
	p->next = new ListNode(4);
	p = p->next;
	p->next = new ListNode(5);

	ListNode* head = deleteDuplicates(l1);

	//ListNode* m = oddEvenList(l1);

	//ListNode* l2 = new ListNode(5);
	//p = l2;
	//p->next = new ListNode(6);
	//p = p->next;
	//p->next = new ListNode(4);

	//ListNode* m = addTwoNumbers2(l1, l2);
	//ListNode* m = swapPairs(l1);
	//bool a = isPalindrome(l1);


	return 0;
}