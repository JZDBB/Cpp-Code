#include"Greedy.h"

int main() {
	/*vector<int> a = { 10,9,8,7 };
	vector<int> b = { 5,6,7,8 };
	vector<vector<int>> c = { {1,2},{2,3},{3,4},{0,3} };
	int count = eraseOverlapIntervals(c);*/

	// vector<int> b = partitionLabels("ababcbacadefegdehijhklij");
	vector<vector<int>> c = { {10, 16},{2, 8},{1, 6},{1, 5}, {7, 12} };
	sort(begin(c), end(c),
		[](const vector<int> &o1, const vector<int> &o2) {
		return (o1[0] < o2[0])|| (o1[0] == o2[0] && o1[1]<o2[1]);
	});

	return 0;
}