#pragma once
#include"solution.h"

class LRUCache {
private:
	unordered_map<int, Node*> map;
	int cap;
	Node* head;
	Node* tailer;

public:
	LRUCache(int capacity) {
		cap = capacity;
		head = new Node(-1, -1);
		tailer = new Node(-1, -1);
		head->next = tailer;
		tailer->pre = head;
	}

	int get(int key) {
		if (map.find(key) != map.end()) {
			Node* cur = map[key];
			remove(map[key]);
			insert(map[key]);
			return map[key]->value;
		}
		else return -1;
	}

	void put(int key, int value) {
		if (map.find(key) != map.end()) {
			Node* node = map[key];
			node->value = value;
			remove(node);
			insert(node);
		}
		else {
			Node* node = new Node(key, value);
			if (map.size() == cap) {
				Node* thr = tailer->pre;
				remove(thr);
				map.erase(thr->key);
			}
			map[key] = node;
			insert(node);
		}
	}
	void insert(Node* n) {
		Node* nextNode = head->next;
		head->next = n;
		nextNode->pre = n;
		n->next = nextNode;
		n->pre = head;
	}

	void remove(Node* n) {
		Node* preNode = n->pre;
		Node* nextNode = n->next;
		preNode->next = nextNode;
		nextNode->pre = preNode;
	}
};