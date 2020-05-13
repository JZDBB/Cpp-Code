#include"DP.h"

// 646. 最长数对链
int findLongestChain(vector<vector<int>>& pairs) {
	if (pairs.size() < 2) return pairs.size();
	sort(pairs.begin(), pairs.end(), [](vector<int> &o1, vector<int> &o2) {
		return o1[1] < o2[1] || (o1[1] == o2[1] && o1[0] < o2[0]); });
	int count = 1;
	int end = pairs[0][1];
	for (int i = 1; i < pairs.size(); i++) {
		if (pairs[i][0] > end) {
			count++;
			end = pairs[i][1];
		}
	}
	return count;
}