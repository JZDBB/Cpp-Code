#include"graph.h"

int main() {
	vector<vector<int>> edges = { {1,2}, {2,3}, {3,4}, {1,4}, {1,5} };
	vector<int> a = findRedundantConnection(edges);
	return 0;
}