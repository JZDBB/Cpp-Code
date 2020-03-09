#pragma once

template <typename T>
void Vector<T>::expand() {
	if (_size < _capacity) return; //尚未满员时，不必扩容
	if (_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY; //不低于最小容量
	T* old_elem = &_elem;
	_elem = new T[_capacity <<= 1];
	for (int i = 0; i < _size; i++){
		_elem[i] = old_elem[i];
	}
	delete [] old_elem; // 释放空间！！
}

template <typename T>
void Vector<T>::shrink() {
	if (_capacity < DEFAULT_CAPACITY << 1) return; //不致收缩到DEFAULT_CAPACITY以下
	if (_size << 2 > _capacity) return; //以25%为界
	T* old_elem = &_elem;
	_elem = new T[_capacity >>= 1];
	for (int i = 0; i < _capacity; i++) {
		_elem[i] = old_elem[i];
	}
	delete[] old_elem;
}
