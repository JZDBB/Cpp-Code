#include"Queue.h"
#include"Stack.h"
#include"MyStack.h"
using namespace std;

int main() {
	/*string s = "(]";
	bool a = isValid(s);*/


	/*int a[] = { 73, 74, 75, 71, 69, 72, 76, 73 };
	vector<int> T(a, a + 8);
	vector<int> m = dailyTemperatures(T);*/
	vector<vector<int>> m = { {0, 0, 0}, { 0, 1, 0 }, { 0, 0, 0 } };
	vector<vector<int>> a = updateMatrix(m);

	return 0;
}
