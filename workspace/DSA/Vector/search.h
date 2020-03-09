#pragma once
#include"Fibsearch.h"
#include"Binsearch.h"

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