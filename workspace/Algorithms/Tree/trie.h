#pragma once
#include"tree_func.h"

#define ALPHABET_SIZE 26

class TrieNode {
public:
	TrieNode* next[ALPHABET_SIZE];
	bool isword;
	TrieNode() {
		memset(next, NULL, sizeof(next));
		isword = false;
	}
	~TrieNode() {
		for (int i = 0; i < ALPHABET_SIZE; i++)if (next[i])delete next[i];
	}
};
class Trie {
private:
	TrieNode* root;
public:
	/** Initialize your data structure here. */
	Trie() {
		root = new TrieNode();
	}
	~Trie() {
		delete root;
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		TrieNode* p = root;
		for (int i = 0; i < word.size(); i++) {
			if (p->next[word[i] - 'a'] == NULL) p->next[word[i] - 'a'] = new TrieNode();
			p = p->next[word[i] - 'a'];
		}
		p->isword = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		TrieNode* p = root;
		for (int i = 0; i < word.size(); i++) {
			if (p->next[word[i] - 'a'] == NULL) break;
			p = p->next[word[i] - 'a'];
		}
		return p && p->isword;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		TrieNode*p = root;
		for (int i = 0; i < (int)prefix.size() && p; i++) {
			p = p->next[prefix[i] - 'a'];
		}
		return p;
	}
};