#include"SortSolution.h"

// 347. 前 K 个高频元素
//void build_heap(vector<pair<int, int>> &Heap, int index, int len) {
//	int left = 2 * index + 1;
//	int right = 2 * index + 2;
//	int max = index;
//	if (left<len&&Heap[left].second > Heap[max].second) max = left;
//	if (right<len&&Heap[right].second > Heap[max].second) max = right;
//	if (index != max) {
//		swap(Heap[index], Heap[max]);
//		build_heap(Heap, max, len);
//	}
//	int max = index;
//	if (left<len&&Heap[left].first < Heap[max].first) max = left;
//	if (right<len&&Heap[right].second < Heap[max].second) max = right;
//	if (index != max) {
//		swap(Heap[index], Heap[max]);
//		build_heap(Heap, max, len);
//	}
//}
vector<int> topKFrequent(vector<int>& nums, int k) {
	vector<int> ret;
	unordered_map<int, int> m;
	priority_queue<pair<int, int>> pq; // 降序队列
	// 升序队列
	// priority_queue <int, vector<int>, greater<int> > q;
	// 降序队列
	// priority_queue <int, vector<int>, less<int> >q;

	for (auto i : nums) m[i]++;
	for (auto p : m) {
		pq.push(pair<int, int>(-p.second, p.first));
		if (pq.size() > k) pq.pop();
	}
	while (k--) {
		ret.push_back(pq.top().second);
		pq.pop();
	}
	return ret;
}