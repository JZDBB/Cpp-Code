#pragma once

template <typename T>
void Vector<T>::copyFrom(T const* A, Rank lo, Rank hi) {
	_size = 0;
	_elem = new T[_capacity = 2 * (hi - lo)];
	while (lo < hi) {
		_elem[_size++] = A[lo++];
	}
}