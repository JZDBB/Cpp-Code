#include"Search.h"

int main() {
	/*vector<vector<int>> a = { {0, 0, 0},{1, 1, 0},{1, 1, 0} };
	int m = shortestPathBinaryMatrix(a);*/

	/*vector<string> w = { "hot", "dot", "dog", "lot", "log", "cog" };
	int a = ladderLength2("hit", "cog", w);*/
	//vector<int> a = { 10,1,2,7,6,1,5 };
	//vector<vector<int>> m = combinationSum2(a, 8);
	vector<vector<char>> board = { {'a','a','a','a'},{'a','a','a','a'},{'a','a','a','a'},{'a','a','a','a'},{'a','a','a','b'} };
	bool m = exist(board, "aaaaaaaaaaaaaaaaaaaa");
	

	return 0;
}