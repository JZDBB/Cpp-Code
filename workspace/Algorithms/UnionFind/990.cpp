#include"unionfind_fun.h"

// 990. 等式方程的可满足性

bool equationsPossible(vector<string>& equations) {
	UnionFind u;
	for (auto s : equations) {
		if (s[1] == '=') {
			u.unite(s[0] - 'a', s[3] - 'a');
		}
	}
	for (auto s : equations) {
		if (s[1] == '!') {
			if (u.find(s[0] - 'a') == u.find(s[3] - 'a')) return false;
		}
	}
	return true;
}