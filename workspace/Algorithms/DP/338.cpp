#include"DP.h"

// 338. 比特位计数
vector<int> countBits(int num) {
	vector<int> res(num + 1);
	res[0] = 0;
	for (int i = 0; i <= num; i++) {
		if (i % 2 == 0) res[i] = res[i / 2];
		else res[i] = res[i - 1];
	}
	return res;
}