#include"vector_func.h"

// 974. 和可被 K 整除的子数组
int subarraysDivByK(vector<int>& A, int K) {
	unordered_map<int, int> record = { {0, 1} };
	int sum = 0, ans = 0;
	for (int elem : A) {
		sum += elem;
		// 注意 C++ 取模的特殊性，当被除数为负数时取模结果为负数，需要纠正
		int modulus = (sum % K + K) % K;
		if (record.count(modulus)) {
			ans += record[modulus];
		}
		++record[modulus];
	}
	return ans;
}