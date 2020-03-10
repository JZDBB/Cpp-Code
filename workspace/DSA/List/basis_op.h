#pragma once

#include"list.h"

template <typename T>
List<T>::List(List<T> const& L) {
	copyNodes(L.first(), L._size);
}

template <typename T>
List<T>::List(List<T> const& L, Rank r, int n) {
	ListNodePosi(T) p = L.first();
	while (0 < r--) p = p->succ;
	copyNodes(p, n);
}

template <typename T>
List<T>::List(ListNodePosi(T) p, int n) {
	copyNodes(p, n);
}

template <typename T>
List<T>::~List() {
	clear(); delete header; delete trailer;
}

template<typename T>
void List<T>::init() {
	header = new ListNode<T>;
	trailer = new ListNode<T>;
	header->succ = trailer;
	header->pred = nullptr;
	trailer->pred = header;
	trailer->succ = nullptr;
	_size = 0;
}

template <typename T>
int List<T>::clear() {
	int oldSize = _size;
	while (0 < _size) remove(header->succ); //反复删除首节点，直至列表变空
	return oldSize;
}

template <typename T>
void List<T>::copyNodes(ListNodePosi(T) p, int n) {
	init();
	while (n--) { insertAsLast(p->data); p = p->succ; }
}

template <typename T>
T& List<T>::operator[] (Rank r) const {
	ListNodePosi(T) p = L.first();
	while (0 < r--) p = p->succ;
	return p->data;
}

template <typename T>
ListNodePosi(T) List<T>::insertAsFirst(T const& e) {
	_size++;
	return header->insertAsSucc(e);
}

template <typename T>
ListNodePosi(T) List<T>::insertAsLast(T const& e){
	_size++; 
	return trailer->insertAsPred(e);
}

template <typename T>
ListNodePosi(T) List<T>::insertA(ListNodePosi(T) p, T const& e) {
	_size++;
	return p->insertAsSucc(e);
}


template <typename T>
ListNodePosi(T) List<T>::insertB(ListNodePosi(T) p, T const& e) {
	_size++;
	return p->insertAsPred(e);
}


template <typename T>
T List<T>::remove(ListNodePosi(T) p) {
	T e = p->data;
	p->pred->succ = p->succ;
	p->succ->pred = p->pred;
	delete p;
	_size--;
	return e;
}

template <typename T>
int List<T>::deduplicate() {
	if (_size < 2) return 0;
	int oldSize = _size; ListNodePosi(T) p = first();
	for (Rank r = 0; p != trailer; p = p->succ) //O(n)
		if (ListNodePosi(T) q = find(p->data, r, p))
			remove(q);
		else r++;
	return oldSize - _size;
}

template <typename T>
int List<T>::uniquify() {
	if (_size < 2) return 0;
	int oldSize = _size;
	ListNodePosi(T) p = first(); // 各个区段期间
	ListNodePosi(T) q; // 后继指针
	while (trailer != (q = p->succ))
		if (p->data != q->data) p = q;
		else remove(q);
	return oldSize - _size;
}


// 只交换数据不交换地址
/*template <typename T> void List<T>::reverse() { //前后倒置
	ListNodePosi(T) p = header; ListNodePosi(T) q = trailer;
	for (int i = 1; i < _size; i += 2)
		swap((p = p->succ)->data, (q = q->pred)->data); //交换对称节点的数据项
}*/

// 交换地址不交换数据
template <typename T>
void List<T>::reverse(){
	if (_size < 2) return;
	for (ListNodePosi(T) p = header; p; p = p->pred)
		swap(p->pred, p->succ);
	swap(header, trailer);
}