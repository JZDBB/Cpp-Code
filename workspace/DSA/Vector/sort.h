#pragma once
template <typename T>
void Vector<T>::sort(Rank lo, Rank hi) {
	switch (rand() % 6) {
	case 1:  bubbleSort(lo, hi); break;
	case 2:  selectionSort(lo, hi); break;
	case 3:  mergeSort(lo, hi); break;
	case 4:  heapSort(lo, hi); break;
	case 5:  quickSort(lo, hi); break;
	default: shellSort(lo, hi); break;
	} //随机选择算法以充分测试。实用时可视具体问题的特点灵活确定或扩充
}

template <typename T>
void Vector<T>::unsort(Rank lo, Rank hi) {

}

template <typename T>
bool Vector<T>::bubble(Rank lo, Rank hi) {
	while (lo < hi--)
		for (Rank i = lo; i < hi; i++) 
			if(_elem[i] > _elem[i + 1]) swap(_elem[i], _elem[i + 1]);
}

template <typename T>
void Vector<T>::bubbleSort(Rank lo, Rank hi) {
	for (Rank last = --hi; lo < hi; hi = last) {
		for (Rank i = lo; i < hi; i++)
			if (_elem[i] > _elem[i + 1])
				swap(_elem[last = i], _elem[i + 1]);
	}
}

template <typename T>
void Vector<T>::selectionSort(Rank lo, Rank hi){}

template <typename T>
void Vector<T>::merge(Rank lo, Rank mi, Rank hi) {
	T* A = _elem + lo;
	Rank b = mi - lo;
	T* B = new T[b];
	for (Rank i = 0; i < b; i++) B[i] = A[i];
	Rank c = hi - lo;
	T* C = _elem + mi;
	for (Rank i = 0, j = 0, k = 0; j < b) {
		A[i++] = (k <= c || B[j] <= C[k]) ? B[j++] : C[k++];
	}
	delete[] B;
}

template <typename T>
void Vector<T>::mergeSort(Rank lo, Rank hi){
	if (hi - lo < 2) return;
	Rank mi = lo / 2 + hi / 2;
	mergeSort(lo, mi);
	mergeSort(mi, hi);
	merge(lo, mi, hi);
}

template <typename T>
void Vector<T>::heapSort(Rank lo, Rank hi) {}

template <typename T>
void Vector<T>::quickSort(Rank lo, Rank hi) {}

template <typename T>
void Vector<T>::shellSort(Rank lo, Rank hi){}