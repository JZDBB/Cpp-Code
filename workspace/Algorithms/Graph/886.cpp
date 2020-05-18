#include"graph.h"

// 886. 可能的二分法
bool dfs(vector<vector<int>>& members, vector<int>& group, int id, int group_name) {
	if (group[id]) return group[id] == group_name;
	group[id] = group_name;
	for (auto j : members[id]) {
		if (!dfs(members, group, j, -group_name)) return false;
	}
	return true;
}
bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
	vector<vector<int>> members = vector<vector<int>>(N);
	for (auto d : dislikes) {
		members[d[0] - 1].push_back(d[1] - 1);
		members[d[1] - 1].push_back(d[0] - 1);
	}
	vector<int> group(N, 0);
	for (int i = 0; i < N; i++) {
		if (!group[i] && !dfs(members, group, i, 1)) return false;
	}
	return true;
}