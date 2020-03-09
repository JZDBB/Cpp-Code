#pragma once
template <typename T>
T Vector<T>::remove(Rank r){
	T e = _elem[r]; //备份被删除元素
	remove(r, r + 1); //调用区间删除算法，等效于对区间[r, r + 1)的删除
	return e; //返回被删除元素
}

template <typename T>
int Vector<T>::remove(Rank lo, Rank hi) {
	if (lo == hi) return 0; //出于效率考虑，单独处理退化情况，比如remove(0, 0)
	while (hi < _size) _elem[lo++] = _elem[hi++];
	_size = lo; //更新规模，直接丢弃尾部[lo, _size = hi)区间
	shrink();
	return hi - lo; //返回被删除元素的数目
}


template <typename T>
Rank Vector<T>::insert(Rank r, T const& e) {
	expand();
	_size++;
	while (_size > r) _elem[_size--] = _elem[(_size--) - 1];
	_elem[r] = e;
	return r;
}

template <typename T> // 无序去重
int Vector<T>::deduplicate() {
	int oldSize = _size;
	Rank i = 1;
	while (i < _size)
		if (find(_elem[i], 0, i) < 0)
			i++;
		else
			remove(i);
	return oldSize - _size;
}

template <typename T> //有序去重
int Vector<T>::uniquify() {
	Rank i = 0, j = 0;
	while (++j < _size)
		if (_elem[i] != _elem[j])
			_elem[++i] = _elem[j];
	_size = ++i; shrink();
	return j - i;
}
