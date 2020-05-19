#include"graph.h"

// 210. 课程表 II
// 存储有向图
vector<vector<int>> edges;
vector<int> visited;// 标记每个节点的状态：0=未搜索，1=搜索中，2=已完成
vector<int> result;// 用数组来模拟栈，下标 0 为栈底，n-1 为栈顶
bool invalid;// 判断有向图中是否有环
void dfs(int i) {
	visited[i] = 1;
	for (int j : edges[i]) {
		if (visited[j] == 0) {
			dfs(j);
			if (invalid) return;
		}
		if (visited[j] == 1) {
			invalid = true;
			return;
		}
	}
	visited[i] = 2;
	result.push_back(i);
}
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
	edges = vector<vector<int>>(numCourses);
	visited = vector<int>(numCourses, 0);
	invalid = false;
	for (auto p : prerequisites) edges[p[1]].push_back(p[0]);
	for (int i = 0; i < numCourses; i++) {
		if (!visited[i]) {
			dfs(i);
		}
	}
	if (invalid) return {};
	reverse(result.begin(), result.end());
	return result;
}