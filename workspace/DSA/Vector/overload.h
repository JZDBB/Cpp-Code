#pragma once
template <typename T>
T& Vector<T>::operator[] (Rank r) {
	return _elem[r];
}// assert: 0 <= r < _size

template <typename T>
const T& Vector<T>::operator[] (Rank r) const {
	return _elem[r];
}// assert: 0 <= r < _size

template <typename T>
Vector<T> & Vector<T>::operator= (Vector<T> const& V) {
	if (_elem) delete[] _elem;
	copyFrom(V._elem, 0, V._size);
	return *this; // 返回当前指针
}
