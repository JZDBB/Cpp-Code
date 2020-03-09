#pragma once
template <typename T>
static Rank binSearch(T* S, T const& e, Rank lo, Rank hi) {
	Rank mi;
	while (lo < hi) {
		mi = lo / 2 + hi / 2;
		e < S[mi] ? hi = mi : lo = mi + 1;
	}
	return lo - 1;
}