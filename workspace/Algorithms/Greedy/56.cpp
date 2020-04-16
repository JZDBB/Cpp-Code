#include"Greedy.h"

// 56. 合并区间
vector<vector<int>> merge(vector<vector<int>>& intervals) {
	if (intervals.size() < 1) return {};
	sort(begin(intervals), end(intervals), 
		[](const vector<int> &o1, const vector<int> &o2) {
		return o1[0] < o2[0];
	});
	vector<vector<int>> res;
	int start = intervals[0][0];
	int end = intervals[0][1];
	for (int i = 1; i < intervals.size(); i++) {
		if (intervals[i][0] <= end) {
			end = intervals[i][1] > end ? intervals[i][1] : end;
			continue;
		}else {
			res.push_back({ start, end });
			start = intervals[i][0];
			end = intervals[i][1];
		}
	}
	res.push_back({ start, end });
	return res;
}