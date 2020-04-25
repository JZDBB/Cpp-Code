#include"string_func.h"

// 466. 统计重复个数

//int getMaxRepetitions(string s1, int n1, string s2, int n2) {
//	int p1 = 0;
//	int p2 = 0;
//	int copy = 0;
//	string s = "";
//	for (int i = 0; i < n2; i++) s += s2;
//	while (n1) {
//		if (s1[p1] == s[p2]) {
//			p1++;
//			p2++;
//		}
//		else p1++;
//		if (p2 == s.size()) {
//			copy++;
//			p2 = 0;
//		}
//		if (p1 == s1.size()) {
//			p1 = 0;
//			n1--;
//		}
//	}
//	return copy;
//}

// 找到循环节
int getMaxRepetitions(string s1, int n1, string s2, int n2) {
	vector<int> repeatCnt(102, 0);
	vector<int> nextIdx(102, -1);
	int j = 0, cnt = 0;
	for (int k = 1; k <= n1; ++k) {
		int tag = 0;
		for (int i = 0; i < s1.size(); ++i) {
			if (s1[i] == s2[j]) {
				++j;
				tag = 1;
				if (j == s2.size()) {
					j = 0;
					++cnt;
				}
			}
		}
		if (tag == 0)return 0;
		repeatCnt[k] = cnt;
		if (nextIdx[j] != -1) {
			int start = nextIdx[j];
			int interval = k - start;
			int repeat = (n1 - start) / interval;
			int patternCnt = (repeatCnt[k] - repeatCnt[start]) * repeat;
			int remainCnt = repeatCnt[start + (n1 - start) % interval];
			return (patternCnt + remainCnt) / n2;
		}
		else nextIdx[j] = k;
	}
	return repeatCnt[n1] / n2;
}