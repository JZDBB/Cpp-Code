#include"Math.h"

// 136. ֻ����һ�ε�����
int singleNumber(vector<int>& nums) {
	int res = 0;
	for (int i : nums) res ^= i;
	return res;
}