#include"hash.h"


// 不重复最长子序列
//int lengthOfLongestSubstring(string s) {
//
//}


int main() {
	
	int a[9] = { 100,4,200,1,3,2 };
	vector<int> nums(a, a + 6);
	int i = longestConsecutive(nums);

	/*string s = "aabbccccaab";
	int a = lengthOfLongestSubstring(s);*/

	return 0;
}