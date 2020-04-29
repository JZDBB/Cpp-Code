#include"Search.h"

// 547. ≈Û”—»¶
void dfs(vector<vector<int>>& M, int index, vector<int> &visit) {
	for (int i = 0; i < M.size(); i++) {
		if (M[index][i] == 1 && visit[i] == 0) {
			visit[i] = 1;
			dfs(M, i, visit);
		}
	}
}

int findCircleNum(vector<vector<int>>& M) {
	if (M.empty()) return 0;
	vector<int> visit(M.size());
	int res = 0;
	for (int i = 0; i < M.size(); i++) {
		if (visit[i]==0) {
			res++;
			dfs(M, i, visit);
		}
	}
	return res;
}