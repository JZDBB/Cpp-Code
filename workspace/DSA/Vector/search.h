#pragma once
#include"vector.h"

template <typename T>
Rank Vector<T>::find(T const& e, Rank lo, Rank hi) const {
	/*while (lo <= hi) {
		if (_elem[hi--] == e) break;
	}*/
	while ((lo < hi--) && (e != _elem[hi])); //从后向前，顺序查找
	return hi;
}

template <typename T>
Rank Vector<T>::search(T const& e, Rank lo, Rank hi) const {
	return (rand() % 2) ? //按各50%的概率随机使用二分查找或Fibonacci查找
		binSearch(_elem, e, lo, hi) : fibSearch(_elem, e, lo, hi);
}

template <typename T>
static Rank binSearch(T* S, T const& e, Rank lo, Rank hi) {
	Rank mi;
	while (lo < hi) {
		mi = lo / 2 + hi / 2;
		e < S[mi] ? hi = mi : lo = mi + 1;
	}
	return lo - 1;
}

#include"Fib.h"
template <typename T>
static Rank fibSearch(T* S, T const& e, Rank lo, Rank hi) {
	template <typename T> static Rank fibSearch(T* S, T const& e, Rank lo, Rank hi) {
		printf("FIB search (B)\n");
		for (Fib fib(hi - lo); lo < hi; ) { //Fib数列制表备查
			while (hi - lo < fib.get()) fib.prev(); //自后向前顺序查找（分摊O(1)）
			Rank mi = lo + fib.get() - 1; //确定形如Fib(k) - 1的轴点
			(e < S[mi]) ? hi = mi : lo = mi + 1; //比较后确定深入前半段[lo, mi)或后半段(mi, hi)
		} 
		return --lo;
	}
}