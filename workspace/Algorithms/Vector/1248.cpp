#include"vector_func.h"

// 1248. 统计「优美子数组」
int numberOfSubarrays(vector<int>& nums, int k) {
	int n = (int)nums.size();
	int ans = 0, cnt = 0;
	vector<int> odd(n + 2, 0);
	for (int i = 0; i < n; ++i) {
		if (nums[i] & 1) odd[++cnt] = i;
	}
	odd[0] = -1, odd[++cnt] = n;
	for (int i = 1; i + k <= cnt; ++i) {
		ans += (odd[i] - odd[i - 1]) * (odd[i + k] - odd[i + k - 1]);
	}
	return ans;
}