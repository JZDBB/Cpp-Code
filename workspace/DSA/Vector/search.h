#pragma once
#include<vector>
using namespace std;

template <typename T>
int Bisearch(vector<T> V, T const target, int lo, int hi) {
	int mi;
	while (lo < hi) {
		mi = lo / 2 + hi / 2;
		V[mi] > target ? hi = mi : lo = mi + 1;
	}
	return --lo;
}

template <typename T>
int Fibsearch(vector<T> V, T target, int lo, int hi) {
	int mi;
	while (lo < hi) {
		mi = 0.66 * lo + (1 - 0.66) * hi;
		if (V[mi] > target) hi = mi;
		else if (V[mi] > target) lo = mi;
		else return mi;
	}
	return --lo;
}