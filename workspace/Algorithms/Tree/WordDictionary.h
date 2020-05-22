#pragma once
#include"tree_func.h"

class WordDictionary {
public:
	struct node {
		bool isEnd;
		unordered_map<char, node*> child;
		node() { isEnd = false; }
	};
	/** Initialize your data structure here. */
	node* root;
	WordDictionary() {
		root = new node();
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		auto p = root;
		for (auto c : word) {
			if (!p->child.count(c))p->child.insert({ c,new node() });
			p = p->child[c];
		}
		p->isEnd = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		auto p = root;
		return help(p, word.begin(), word.end());
	}
	template<typename it>
	bool help(node* root, it l, it r) {
		if (l == r)return root->isEnd;
		if (*l == '.')
			for (auto t : root->child)
				if (help(t.second, l + 1, r))return true;
		if (root->child.count(*l))return help(root->child[*l], l + 1, r);
		return false;
	}
};