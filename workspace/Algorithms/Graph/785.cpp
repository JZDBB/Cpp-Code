#include"graph.h"

// 785. ÅÐ¶Ï¶þ·ÖÍ¼
bool dfs(vector<int> &colors, vector<vector<int>>& graph, int i, int color) {
	colors[i] = color;
	for (auto j : graph[i]) {
		if (colors[j] == colors[i]) return false;
		if (colors[j] == 0 && !dfs(colors, graph, j, -color)) return false;
	}
	return true;
}

bool isBipartite(vector<vector<int>>& graph) {
	vector<int> colors(graph.size(), 0);
	for (int i = 0; i < graph.size(); i++) {
		if (colors[i] == 0&&!dfs(colors, graph, i, 1)) return false;
	}
	return true;
}