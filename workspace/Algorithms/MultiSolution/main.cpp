#include"solution.h"

int main() {
	
	int a[] = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	vector<int> m(a, a + 12);
	int res = trap(m);

	return 0;
}