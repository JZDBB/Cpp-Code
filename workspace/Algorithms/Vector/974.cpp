#include"vector_func.h"

// 974. 和可被 K 整除的子数组
int subarraysDivByK(vector<int>& A, int K) {
	int sum = 0;
	vector<int> m(K);
	int res = 0;
	m[0] = 1;
	for (int i = 0; i < A.size(); i++) {
		sum += A[i];
		res += m[sum % K];
		m[sum%K]++;
	}
	return res;
}