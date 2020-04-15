#include"Greedy.h"

// 435. 无重叠区间
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
	if (intervals.size() < 2) return 0;
	// 排序，在所有区间里面结束最早的到最晚
	priority_queue<pair<int, int>> Q;
	for (int i = 0; i < intervals.size(); i++) {
		Q.push(pair<int, int>(-intervals[i][1], -intervals[i][0]));
	}
	int count = 0;
	int start = -Q.top().second;
	int end = -Q.top().first;
	Q.pop();
	while (!Q.empty()) {
		int s0 = -Q.top().second;
		int e0 = -Q.top().first;
		Q.pop();
		if (s0 < end) count++;
		else{
			start = s0;
			end = e0;
		}
	}
	return count;
}