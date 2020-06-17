#include"tree_func.h"

// 297. 二叉树的序列化与反序列化
string int2str(int i) {
	string res = "";
	while (i) {
		res.insert(res.begin(), i % 10 + '0');
		i /= 10;
	}
	return res;
}
// Encodes a tree to a single string.
string serialize(TreeNode* root) {
	if (!root) return "#";
	string left = serialize(root->left);
	string right = serialize(root->right);
	string res = int2str(root->val) + "," + left + "," + right;
	return res;
}
TreeNode* decode(const string &data, int &index) {
	if (data[index] == '#') {
		index+=2;
		return NULL;
	}
	int val = 0;
	while (index < data.size() && data[index] != ',') val = val * 10 + data[index++] - '0';
	++index;
	TreeNode* root = new TreeNode(val);
	if (index < data.size()) root->left = decode(data, index);
	if (index < data.size()) root->right = decode(data, index);
	return root;
}
// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
	int index = 0;
	return decode(data, index);
}