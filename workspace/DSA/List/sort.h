#pragma once
template <typename T>
void List<T>::sort(ListNodePosi(T) p, int n) {
	switch (rand() % 3) { 
	case 1:  insertionSort(p, n); break;
	case 2:  selectionSort(p, n); break;
	default: mergeSort(p, n); break;
	}
}

template <typename T>
void List<T>::merge(ListNodePosi(T)& p, int n, List<T>& L, ListNodePosi(T) q, int m) {
	ListNodePosi(T) pp = p->pred;
	while (0 < m)
		if ((0 < n) && (p->data <= q->data)){
			if (q == (p = p->succ)) break; n--;
		} else {
			insertB(p, L.remove((q = q->succ)->pred)); m--;
		} 
	p = pp->succ;
}

template <typename T>
void List<T>::mergeSort(ListNodePosi(T)& p, int n) {
	if (n < 2) return;
	int m = n >> 1;
	ListNodePosi(T) q = p; for (int i = 0; i < m; i++) q = q->succ;
	mergeSort(p, m); mergeSort(q, n - m);
	merge(p, m, *this, q, n - m);
}

template <typename T>
void List<T>::selectionSort(ListNodePosi(T) p, int n) {
	ListNodePosi(T) head = p->pred; ListNodePosi(T) tail = p;
	for (int i = 0; i < n; i++) tail = tail->succ;
	while (1 < n) {
		ListNodePosi(T) max = selectMax(head->succ, n);
		insertB(tail, remove(max));
		tail = tail->pred; n--;
	}
}

template <typename T>
void List<T>::insertionSort(ListNodePosi(T) p, int n) {
	for (int r = 0; r < n; r++) {
		insertA(search(p->data, r, p), p->data);
		p = p->succ; remove(p->pred);
	}
}