#include"graph.h"

// 684. 冗余连接

// DFS
// 因为没有提供节点数量难以做邻接矩阵初始化，因此采用哈希表
unordered_map<int, vector<int>> graph; 
bool dfs(int cur, int goal, unordered_set<int>& visited) {
	if (cur == goal) return true;
	visited.insert(cur);
	if (!graph.count(cur) || !graph.count(goal)) return false;
	for (int next : graph.at(cur)) {
		if (visited.count(next)) continue;
		if (dfs(next, goal, visited)) return true;
	}
	return false;
}
vector<int> findRedundantConnection_DFS(vector<vector<int>>& edges) {
	for (auto edge : edges) {
		int u = edge[0];
		int v = edge[1];
		unordered_set<int> visited;
		if (dfs(u, v, visited)) return edge;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	return {};
}

// Union Find
int find(int u, vector<int>& parent) {
	while (parent[u] != u) {
		parent[u] = parent[parent[u]];
		u = parent[u];
	}
	return u;
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
	vector<int> parent = vector<int>(edges.size() + 1, 0);
	vector<int> size(edges.size() + 1, 1);
	for (const auto& edge : edges) {
		int u = edge[0];
		int v = edge[1];
		if (!parent[u]) parent[u] = u;
		if (!parent[v]) parent[v] = v;
		int pu = find(u, parent);
		int pv = find(v, parent);
		if (pu == pv) return edge;
		if (size[pv] > size[pu]) swap(pu, pv);
		parent[pv] = pu;
		size[pu] += size[pv];
	}
	return {};
}