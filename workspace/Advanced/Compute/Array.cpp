#include "Array.h"
#include<assert.h>


template <class T> Array<T>::Array(int s) {
	assert(s >= 0);
	size = s;
	list = new T[size];

}
template <class T> Array<T>::Array(const Array<T> &a){
	size = a.size;
	list = new T[size];
	for (int i = 0; i < size; i++)
	{
		list[i] = a.list[i]; // 深层复制
	}
	}


template <class T> Array<T>::~Array()
{
	delete[]list;
}


template <class T> 
Array<T> & Array<T>::operator = (const Array<T> &rhs) {
	if (&rhs != this){
		if (size != rhs.size) {
			delete[] list;
			size = rhs.size;
			list = new T[size];
		}
		for (int i = 0; i < size; i++){
			list[i] = rhs.list[i];
		}
	}
	return *this;
}
template <class T>
T & Array<T>::operator [] (int i) {
	assert(i >= 0 && i < size);
	return list[i];
}
template <class T> 
const T & Array<T>::operator [] (int i) const { // 常引用（只读）
	assert(i >= 0 && i < size);
	return list[i];
}
template <class T> 
Array<T>::operator T * () {
	return list; // 返回指向该数组的指针即可
}
template <class T> 
Array<T>::operator const T * () const {
	return list;
}
template <class T> 
int Array<T>::getSize() const {
	return size;
}
template <class T> 
void Array<T>::resize(int s) {
	assert(s >= 0);
	if (s == size) return;
	T* newlist = new T[s];
	int n = (s < size) ? s : size;
	for (int i = 0; i < n; i++)
	{
		newlist[i] = list[i];
	}
	delete[] list;
	list = newlist;
	size = s;
}