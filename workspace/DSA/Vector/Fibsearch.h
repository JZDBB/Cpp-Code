#pragma once
#include"Fib.h"
template <typename T>
static Rank fibSearch(T* S, T const& e, Rank lo, Rank hi) {
	printf("FIB search (B)\n");
	for (Fib fib(hi - lo); lo < hi; ) { //Fib数列制表备查
		while (hi - lo < fib.get()) fib.prev(); //自后向前顺序查找（分摊O(1)）
		Rank mi = lo + fib.get() - 1; //确定形如Fib(k) - 1的轴点
		(e < S[mi]) ? hi = mi : lo = mi + 1; //比较后确定深入前半段[lo, mi)或后半段(mi, hi)
	}
	return --lo;
}