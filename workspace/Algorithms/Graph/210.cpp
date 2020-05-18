#include"graph.h"

// 210. 课程表 II
// 存储有向图
vector<vector<int>> edges;
vector<int> visited;// 标记每个节点的状态：0=未搜索，1=搜索中，2=已完成
vector<int> result;// 用数组来模拟栈，下标 0 为栈底，n-1 为栈顶
bool invalid;// 判断有向图中是否有环
void dfs(int u) {
	visited[u] = 1;
	for (int v : edges[u]) {
		// 如果「未搜索」那么搜索相邻节点
		if (visited[v] == 0) {
			dfs(v);
			if (invalid) {
				return;
			}
		}
		// 如果「搜索中」说明找到了环
		else if (visited[v] == 1) {
			invalid = true;
			return;
		}
	}
	// 将节点标记为「已完成」
	visited[u] = 2;
	// 将节点入栈
	result.push_back(u);
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
	edges.resize(numCourses);
	visited.resize(numCourses);
	for (const auto& info : prerequisites) {
		edges[info[1]].push_back(info[0]);
	}
	// 每次挑选一个「未搜索」的节点，开始进行深度优先搜索
	for (int i = 0; i < numCourses && !invalid; ++i) {
		if (!visited[i]) {
			dfs(i);
		}
	}
	if (invalid) {
		return {};
	}
	// 如果没有环，那么就有拓扑排序
	// 注意下标 0 为栈底，因此需要将数组反序输出
	reverse(result.begin(), result.end());
	return result;
}