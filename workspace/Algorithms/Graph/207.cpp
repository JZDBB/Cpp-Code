#include"graph.h"

// 207. ¿Î³Ì±í
// visit = 0 -> not visit
// visit = 1 -> visited
// visit = 2 -> visiting
bool dfs(vector<vector<int>>& relation, vector<int>& visit, int i) {
	if (visit[i] == 2) return false;
	visit[i] = 2;
	for (int j : relation[i]) {
		if (!dfs(relation, visit, j)) return false;
	}
	visit[i] = 1;
	return true;
}
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
	vector<vector<int>> relation = vector<vector<int>>(numCourses);
	vector<int> visit(numCourses);
	for (auto p : prerequisites) relation[p[1]].push_back(p[0]);
	for (int i = 0; i < numCourses; i++) {
		if (!visit[i] && !dfs(relation, visit, i)) return false;
	}
	return true;
}