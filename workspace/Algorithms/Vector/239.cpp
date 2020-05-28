#include"vector_func.h"

// 
vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
	if (num.empty() || size > num.size() || size < 1) return {};
	vector<int> s;
	vector<int> res;
	int count = size;
	for (int i = 0; i < num.size(); i++) {
		if (count > 0) {
			if (s.empty()) s.push_back(num[i]);
			else {
				while (s.size() >= 1 && s.back() < num[i]) {
					s.pop_back();
				}
				s.push_back(num[i]);
			}
			count--;
		}
		else {
			res.push_back(s[0]);
			if (num[i - size] == s[0]) {
				s.erase(s.begin());
			}
			while (s.size() >= 1 && s.back() < num[i]) {
				s.pop_back();
			}
			s.push_back(num[i]);
		}
	}
	res.push_back(s[0]);
	return res;
}