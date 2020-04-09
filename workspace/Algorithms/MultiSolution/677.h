#pragma once
#include"solution.h"

// 677. ¼üÖµÓ³Éä
class MapSum {
private:
	unordered_map<string, int> Map;
public:
	/** Initialize your data structure here. */
	MapSum() {
		
	}

	void insert(string key, int val) {
		Map[key] = val;
	}

	int sum(string prefix) {
		int size = prefix.size();
		int res = 0;
		for (auto item : Map) {
			if (item.first.size() > size && item.first.substr(0, size) == prefix) res += item.second;;
		}
		return res;
	}
};