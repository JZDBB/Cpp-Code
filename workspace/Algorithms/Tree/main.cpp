#include"tree_func.h"


int main() {
	/*TreeNode* root1 = new TreeNode(1);
	TreeNode* p = root1;
	p->left = new TreeNode(3);
	p->right = new TreeNode(2);
	p = p->left;
	p->left = new TreeNode(5);
	p->right = new TreeNode(2);
	TreeNode* root2 = new TreeNode(2);
	p = root2;
	p->left = new TreeNode(1);
	p->right = new TreeNode(3);
	p->right->right = new TreeNode(7);
	p->left->right = new TreeNode(2);

	TreeNode* a = mergeTrees(root1, root2);*/

	TreeNode* root1 = new TreeNode(2);
	TreeNode* p = root1;
	p->left = new TreeNode(1);
	p->right = new TreeNode(3);
	/*p->right->left = new TreeNode(6);
	p->left->right = new TreeNode(2);
	p->right->right = new TreeNode(20);*/
	/*p->left->left->left = new TreeNode(3);
	p->left->left->right = new TreeNode(2);
	p->left->right->right = new TreeNode(1);*/
	bool a = isValidBST(root1);

	//vector<int> a = postorderTraversal(root1);

	/*int a[] = { -10, -3, 0, 5, 9 };
	vector<int> m(a, a + 5);
	TreeNode* p = sortedArrayToBST(m);*/

	/*ListNode* l1 = new ListNode(-10);
	ListNode* p = l1;
	p->next = new ListNode(-3);
	p = p->next;
	p->next = new ListNode(0);
	p = p->next;
	p->next = new ListNode(5);
	p = p->next;
	p->next = new ListNode(9);
	
	TreeNode* a = sortedListToBST(l1);*/


	return 0;
}