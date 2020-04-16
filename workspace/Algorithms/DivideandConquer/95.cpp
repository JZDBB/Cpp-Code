#include"DivideConquer.h"

// 95. 不同的二叉搜索树 II
vector<TreeNode*> generateTrees(int begin, int end) {
	vector<TreeNode*> res;
	if (begin > end) {
		res.push_back(NULL);
		return res;
	}
	for (int i = begin; i <= end; i++) {
		TreeNode* node = new TreeNode(i);
		auto res1 = generateTrees(begin, i - 1);
		auto res2 = generateTrees(i + 1, end);
		for (auto r1 : res1) {
			for (auto r2 : res2) {
				node->left = r1;
				node->right = r2;
				res.push_back(node);
			}
		}
	}
	return res;
}
vector<TreeNode*> generateTrees(int n) {
	if (n == 0) return { NULL };
	return generateTrees(1, n);
}