#include"Search.h"

int main() {
	/*vector<vector<int>> a = { {0, 0, 0},{1, 1, 0},{1, 1, 0} };
	int m = shortestPathBinaryMatrix(a);*/

	/*vector<string> w = { "hot", "dot", "dog", "lot", "log", "cog" };
	int a = ladderLength2("hit", "cog", w);*/
	//vector<int> a = { 10,1,2,7,6,1,5 };
	//vector<vector<int>> m = combinationSum2(a, 8);
	vector<vector<char>> board = { { '5','3','.','.','7','.','.','.','.' },
	{ '6','.','.','1','9','5','.','.','.' },
	{ '.','9','8','.','.','.','.','6','.' },
	{ '8','.','.','.','6','.','.','.','3' },
	{ '4','.','.','8','.','3','.','.','1' },
	{ '7','.','.','.','2','.','.','.','6' },
	{ '.','6','.','.','.','.','2','8','.' },
	{ '.','.','.','4','1','9','.','.','5' },
	{ '.','.','.','.','8','.','.','7','9' } };
	solveSudoku(board);
	

	return 0;
}