#include"Greedy.h"

// 452. 用最少数量的箭引爆气球

//struct coordinate {
//	int x;
//	int y;
//	bool operator < (coordinate point) const {
//		if (this->x < point.x) return true;
//		else if(this->x < point.x) return this->y < point.y;
//	}
//	coordinate(int _x, int _y) : x(_x), y(_y) {}
//};
//
//int findMinArrowShots(vector<vector<int>>& points) {
//	priority_queue<coordinate, vector<coordinate>, greater<coordinate> > Q;
//	for (int i = 0; i < points.size(); i++) {
//		Q.push(coordinate(points[i][1], points[i][0]));
//	}
//	int count = 0;
//	int start = Q.top().y;
//	int end = Q.top().x;
//	Q.pop();
//	count++;
//	while (!Q.empty()) {
//		int s0 = Q.top().y;
//		int e0 = Q.top().x;
//		Q.pop();
//		if (s0 <= end) continue;
//		else {
//			count++;
//			start = s0;
//			end = e0;
//		}
//	}
//	return count;
//}

int findMinArrowShots2(vector<vector<int>>& points) {
	if (points.size() == 0) return 0;

	// sort by x_end
	sort(begin(points), end(points),
		[](const vector<int> &o1, const vector<int> &o2) {
		return (o1[1] < o2[1]);
	});

	int arrows = 1;
	int xStart, xEnd, firstEnd = points[0][1];
	for (auto p : points) {
		xStart = p[0];
		xEnd = p[1];
		if (firstEnd < xStart) {
			arrows++;
			firstEnd = xEnd;
		}
	}
	return arrows;
}
