#include"Search.h"

int main() {
	/*vector<vector<int>> a = { {0, 0, 0},{1, 1, 0},{1, 1, 0} };
	int m = shortestPathBinaryMatrix(a);*/

	/*vector<string> w = { "hot", "dot", "dog", "lot", "log", "cog" };
	int a = ladderLength2("hit", "cog", w);*/

	vector<vector<int>> matrix = { {1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1} };
	int m = maxAreaOfIsland(matrix);
	

	return 0;
}