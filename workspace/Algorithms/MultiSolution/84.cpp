#include"solution.h"

// 84. 柱状图中最大的矩形

// 分治法——超时
int searchArea(vector<int>& heights, int lo, int hi) {
	if (lo >= hi) {
		if (lo >= heights.size()) return heights[hi];
		else return heights[lo];
	}
	int h = heights[hi];
	int index = hi;
	for (int i = lo; i < hi; i++) {
		if (h > heights[i]) {
			h = heights[i];
			index = i;
		}
	}
	int res = h * (hi - lo + 1);
	int left = searchArea(heights, lo, index - 1);
	int right = searchArea(heights, index + 1, hi);
	res = res > left ? res : left;
	res = res > right ? res : right;
	return res;
}
int largestRectangleArea(vector<int>& heights) {
	stack<int> h;
	int res = 0;
	h.push(-1); // 记住index
	for (int i = 0; i < heights.size(); i++) {
		while (h.top() != -1 && heights[h.top()] >= heights[i]) {
			int index = h.top();
			h.pop();
			res = max(res, heights[index] * (i - h.top() - 1));
		}
		h.push(i);
	}
	while (h.top() != -1) {
		int index = h.top();
		h.pop();
		int area = heights[index] * (heights.size() - h.top() - 1);
		res = max(res, area);
	}
	return res;
}