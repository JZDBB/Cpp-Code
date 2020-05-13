#include"DP.h"


int main() {
	/*vector<int> nums = { 1,3,6,7,9,4,10,5,6 };
	int m = lengthOfLIS(nums);*/
	vector<vector<int>> pairs = { {-6,9},{1,6},{8,10},{-1,4},{-6,-2},{-9,8},{-5,3},{0,3} };
	int m = findLongestChain(pairs);
	return 0;
}