#include"SortSolution.h"

// 451. 根据字符出现频率排序
string frequencySort(string s) {
	unordered_map<int, int> m;
	priority_queue<pair<int, int>> q;
	for (char c : s) m[c]++;
	for (auto key : m) q.push(pair<int, char>(key.second, key.first));
	string res;
	while (!q.empty()) {
		int t = q.top().first;
		char c = q.top().second;
		while (t--) {
			res.push_back(c);
		}
		q.pop();
	}
	return res;
}