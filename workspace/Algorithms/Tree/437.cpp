#include"tree_func.h"

// 437. 路径总和 III —— **

// 递归

//int path(TreeNode* root, int sum) {
//	if (!root) return 0;
//	return (root->val == sum) + path(root->left, sum - root->val) + path(root->right, sum - root->val);
//}
//int pathSum(TreeNode* root, int sum) {
//	if (!root) return 0;
//	return path(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
//}

// 哈希表解法 —— 有问题
void traverse(TreeNode* root, unordered_map<int, int>& hash, int total) {
	hash[total + root->val]++;
	if (root->left) {
		traverse(root->left, hash, total + root->val);
		traverse(root->left, hash, 0);
	}
	if (root->right) {
		traverse(root->right, hash, total + root->val);
		traverse(root->right, hash, 0);
	}
}

int pathSum(TreeNode* root, int sum) {
	if (!root) return 0;
	unordered_map<int, int> map;
	traverse(root, map, 0);
	
	return map[sum];
}


// 参考

//int pathSum(TreeNode* root, int sum) {
//	if (!root) return 0;
//	vector<int>prefixSum(1, 0);
//	int count = 0;
//	helperCountPathSum(root, sum, prefixSum, count);
//	return count;
//}
//void helperCountPathSum(TreeNode* node, int& sum, vector<int>& prefixSum, int& count) {
//	prefixSum.push_back(prefixSum.back() + node->val);
//	if (node->left)
//		helperCountPathSum(node->left, sum, prefixSum, count);
//	if (node->right)
//		helperCountPathSum(node->right, sum, prefixSum, count);
//	int back = prefixSum.back();
//	for (int i = prefixSum.size() - 2; i >= 0; i--)
//		if (back - prefixSum[i] == sum) count++;
//	prefixSum.pop_back();
//}
