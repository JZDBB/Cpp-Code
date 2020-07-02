
#include"tree_func.h"

// 1028. 从先序遍历还原二叉树
TreeNode* recoverFromPreorder(string S) {
	stack<TreeNode*> s;
	int top = 0;
	while (top < S.size()) {
		int level = 0;
		while (S[top] == '-') {
			level++;
			top++;
		}
		int val = 0;
		while (S[top] >= '0'&&S[top] <= '9') {
			val += val * 10 + S[top] - '0';
			top++;
		}
		TreeNode* node = new TreeNode(val);
		if (level == s.size()) {
			if (!s.empty()) s.top()->left = node;
		}
		else {
			while (level != s.size()) s.pop();
			s.top()->right = node;
		}
		s.push(node);
	}
	while (s.size() > 1) s.pop();
	return s.top();
}