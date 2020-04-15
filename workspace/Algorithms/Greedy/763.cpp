#include"Greedy.h"

// 763. 划分字母区间
vector<int> partitionLabels(string S) {
	unordered_map<char, vector<int>> map;
	for (int i = 0; i < S.size(); i++) {
		if (map.find(S[i]) == map.end()) map[S[i]] = { i, i };
		else map[S[i]][1] = i;
	}
	vector<int> res;
	priority_queue<pair<int, int>> Q;
	for (auto key : map) {
		Q.push(pair<int, int>(-key.second[0], key.second[1]));
	}
	int start = - Q.top().first;
	int end = Q.top().second;
	Q.pop();
	while (!Q.empty()) {
		int s0 = -Q.top().first;
		int e0 = Q.top().second;
		Q.pop();
		if (s0 < end) {
			end = e0 > end ? e0 : end;
		}
		else {
			res.push_back(end - start+1);
			start = s0;
			end = e0;
		}
	}
	res.push_back(end - start + 1);
	return res;
}