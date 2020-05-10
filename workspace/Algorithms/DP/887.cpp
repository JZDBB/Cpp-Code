#include"DP.h"

// 887. 鸡蛋掉落
int superEggDrop(int K, int N) { // 超时
	vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
	for (int i = 0; i <= N; i++) dp[i][1] = i;
	for (int i = 1; i <= N; i++) {
		for (int k = 2; k <= K; k++) {
			int res = INT_MAX;
			for (int j = 1; j <= i; j++) {
				res = min(res, max(dp[j - 1][k - 1], dp[i - j][k]) + 1);
			}
			dp[i][k] = res;
		}
	}
	return dp[N][K];
}
	

// min(max(dp[i-1][k-1], dp[N-i][k]))
// dp[i-1][k-1]函数单调递增，并且最小值为dp[0][k-1]为0，最大值为dp[N-1][k-1]
// dp[N-i][k]函数单调递减，并且最小值为dp[0][k]为0，最大值为dp[N-1][k]
// 上述两个函数一定在区间[1,N]内一定存在交点，但交点不一定是整数交点，如果非整数交点，则需要
int superEggDropBS(int K, int N) {
	if (K == 1) return N;
	if (N == 1) return 1;
	vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
	for (int i = 1; i <= N; i++) dp[i][1] = i;
	for (int k = 1; k <= K; k++) dp[1][k] = 1;

	for (int i = 2; i <= N; i++) {
		for (int k = 2; k <= K; k++) {
			// 这一段改用二分查找，而不从1枚举到i
			int start = 1, end = i, mid;
			int res = INT_MAX;
			while (start <= end) {
				mid = start + (end - start) / 2;
				if (dp[mid - 1][k - 1] == dp[i - mid][k]) {
					res = min(res, dp[mid - 1][k - 1] + 1);
					break;
				}
				else if (dp[mid - 1][k - 1] > dp[i - mid][k]) {
					end = mid - 1;
					res = min(res, dp[mid - 1][k - 1] + 1);
				}
				else {
					start = mid + 1;
					res = min(res, dp[i - mid][k] + 1);
				}
			}
			dp[i][k] = res;
		}
	}
	return dp[N][K];
}

// 动态规划的dp定义和子问题定义确定了dp递推公式，不同的角度可能有不同的dp解法
// 并且存在时间复杂度、空间复杂度上的差异
// 这种dp反正我是想不到的，题解中的大佬牛逼
// 这里给出这种的dp角度的问题求解
//
// 1、无论你在哪层楼扔鸡蛋，鸡蛋只可能摔碎或者没摔碎，碎了的话就测楼下，没碎的话就测楼上。
// 2、无论你上楼还是下楼，总的楼层数 = 楼上的楼层数 + 楼下的楼层数 + 1（当前这层楼）。
// 根据这个特点，可以写出下面的状态转移方程：
// dp[k][m] = dp[k][m - 1] + dp[k - 1][m - 1] + 1
// dp[k][m - 1] 就是楼上的楼层数，因为鸡蛋个数 k 不变，也就是鸡蛋没碎，扔鸡蛋次数 m 减一；
// dp[k - 1][m - 1] 就是楼下的楼层数，因为鸡蛋个数 k 减一，也就是鸡蛋碎了，同时扔鸡蛋次数 m 减一。
// 上述递推公式可以这样理解，一次扔鸡蛋至少能推测1层楼，剩余m-1次扔鸡蛋则分别可以推测dp[k-1][m-1]和dp[k][m-1]层楼
// dp[k-1][m-1]表示如果这次扔鸡蛋破了，那么只剩下k-1个鸡蛋和m-1次扔鸡蛋的机会可以探测到的最高楼层数
// dp[k][m-1]表示这次扔鸡蛋没有婆，还剩下k个鸡蛋和m-1次扔鸡蛋机会可以探测到的最高楼层数
// 同时还有本身扔鸡蛋的这一层楼
// 一共能够推测的楼层就是上述三者之和

int superEggDropDP2(int K, int N) {
	vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));
	int m = 0;
	for (; dp[K][m] < N;) {
		m++;
		for (int k = 1; k <= K; k++)
			dp[k][m] = 1 + dp[k - 1][m - 1] + dp[k][m - 1];
	}
	return m;
}