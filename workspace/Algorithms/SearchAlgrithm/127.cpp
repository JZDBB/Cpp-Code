#include"Search.h"

// 127. µ¥´Ê½ÓÁú
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	unordered_set<string> dict(wordList.begin(), wordList.end());
	if (!dict.count(endWord)) return 0;
	unordered_set<string> q1{ beginWord };
	unordered_set<string> q2{ endWord };
	int l = beginWord.length();
	int step = 0;
	while (!q1.empty() && !q2.empty()) {
		step++;
		if (q1.size() > q2.size()) swap(q1, q2);
		unordered_set<string> q;
		for (string w : q1) {
			for (int i = 0; i < l; i++) {
				char c = w[i];
				for (char j = 'a'; j <= 'z'; j++) {
					w[i] = j;
					if (q2.count(w)) return step + 1;
					if (!dict.count(w)) continue;
					dict.erase(w);
					q.insert(w);
				}
				w[i] = c;
			}
		}
		swap(q, q1);
	}
	return 0;
}