#include"interview_func.h"

// 面试题13. 机器人的运动范围 —— 棋盘问题
int get(int x) {
	int res = 0;
	for (; x; x /= 10) res += x % 10;
	return res;
}
int movingCount(int m, int n, int k) {
	// 暴力搜索 O(n^2)

	// 广度优先搜索
	if (!k) return 1;
	queue<pair<int, int>> Q;
	int dx[2] = { 0,1 };
	int dy[2] = { 1,0 };
	vector<vector<int>> V(m, vector<int>(n, 0));
	Q.push(pair<int, int>(0, 0));
	V[0][0] = 1;
	int ans = 1;
	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		for (int i = 0; i < 2; i++) {
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (tx < 0 || tx >= m || ty<0 || ty >= n || V[tx][ty] || get(tx) + get(ty)>k) continue;
			Q.push(pair<int, int>(tx, ty));
			V[tx][ty] = 1;
			ans++;
		}

	}
	return ans;
}