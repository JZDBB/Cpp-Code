#include"vector_func.h"

//287. Ñ°ÕÒÖØ¸´Êı
int findDuplicate(vector<int>& nums) {
	vector<int> a(nums.size());
	for (int i = 0; i < nums.size(); i++) {
		a[nums[i]]++;
	}
	int max = 0;
	int num;
	for (int i = 0; i < a.size(); i++) {
		if (max < a[i]) {
			num = i;
			max = a[i];
		}
	}
	return num;
}