#pragma once
#include<vector>
#include<list>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<list>
using namespace std;

struct Node{
	int key;
	int value;
	Node* pre;
	Node* next;
	// 构造函数初始化
	Node(int key, int value) : key(key), value(value), pre(nullptr), next(nullptr) {}
};