#include<vector>
using namespace std;
#include"SumSolutions.h"



int main() {
	SumSolutions s = SumSolutions();
	int a[6] = { -1,0,1,2,-1,-4 };
	vector<int> nums(a, a+6);
	vector<vector<int>> result = s.threeSum(nums);

	return 0;
}