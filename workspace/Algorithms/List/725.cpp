#include"List_func.h"
#include<vector>


// 725. 分隔链表
vector<ListNode*> splitListToParts(ListNode* root, int k) {
	// 统计长度
	int len = 0;
	for (ListNode* head = root; head; head = head->next) len++;
	int l = len / k;
	int r = len % k;
	vector<ListNode*> ans(k, nullptr);
	ListNode* ptr = root;
	ListNode* prev = nullptr;
	for (int i = 0; i < k; i++, r--) {
		ans[i] = ptr;
		for (int j = 0; j < l + (r > 0); j++) {
			prev = ptr;
			ptr = ptr->next;
		}
		if (prev) prev->next = nullptr;
	}
	return ans;
}