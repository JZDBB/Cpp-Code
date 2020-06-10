#pragma once
#include"unionfind_fun.h"
#include<vector>
#include<unordered_set>
#include<string>
#include<unordered_map>
#include<numeric>
using namespace std;

int longestConsecutive(vector<int>& nums);

class UnionFind{
public:
	UnionFind() {
		parent.resize(26);
		iota(parent.begin(), parent.end(), 0);
	}
	int find(int index) {
		if (index == parent[index]) {
			return index;
		}
		parent[index] = find(parent[index]);
		return parent[index];
	}

	void unite(int index1, int index2) {
		parent[find(index1)] = find(index2);
	}

private:
	vector<int> parent;
};