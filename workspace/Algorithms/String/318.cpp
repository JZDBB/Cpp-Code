#include"string_func.h"


// 
int maxProduct(vector<string>& words) {
	int res = 0;
	for (int i = 0; i < words.size() - 1; i++) {
		unordered_set<char> m;
		m.insert(words[i].begin(), words[i].end());
		for (int j = i + 1; j < words.size(); j++) {
			
		}
	}
	return res;
}