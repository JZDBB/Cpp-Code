#include"Search.h"

// 127. µ¥´Ê½ÓÁú
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	int len = wordList[0].size();
	int layers = 1;
	queue<pair<string, unordered_map<string, int> > > Q;
	unordered_map<string, int> m;
	for (int i = 0; i < wordList.size(); i++) m[wordList[i]] = 0;
	if (m.find(endWord) == m.end()) return 0;
	m[beginWord] = 1;
	Q.push(pair<string, unordered_map<string, int> >(beginWord, m));
	while (!Q.empty()) {
		layers++;
		int size = Q.size();
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < len; j++) {
				for (char k = 'a'; k <= 'z'; k++) {
					string w = Q.front().first;
					unordered_map<string, int> map = Q.front().second;
					w[j] = k;
					if (w == endWord) return layers;
					if (map.find(w) != map.end() && map[w] == 0) {
						map[w] = 1;
						Q.push(pair<string, unordered_map<string, int> >(w, m));
					}
				}
			}
			Q.pop();
		}
	}
	return 0;
}