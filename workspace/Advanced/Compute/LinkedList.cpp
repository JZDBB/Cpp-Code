#include "LinkedList.h"


template<class T>
LinkedList<T>::LinkedList()
{
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& L)
{
}

template<class T>
LinkedList<T>::~LinkedList()
{
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& L)
{
	// TODO: 在此处插入 return 语句
}

template<class T>
int LinkedList<T>::getSize() const
{
	return 0;
}

template<class T>
bool LinkedList<T>::isEmpty() const
{
	return false;
}

template<class T>
void LinkedList<T>::reset(int pos)
{
}

template<class T>
void LinkedList<T>::next()
{
}

template<class T>
bool LinkedList<T>::endOfList() const
{
	return false;
}

template<class T>
int LinkedList<T>::currentPosition() const
{
	return 0;
}

template<class T>
void LinkedList<T>::insertFront(const T & item)
{
}

template<class T>
void LinkedList<T>::insertRear(const T & item)
{
}

template<class T>
void LinkedList<T>::insertBefore(const T & item)
{
}

template<class T>
void LinkedList<T>::insertAfter(const T & item)
{
}

template<class T>
T LinkedList<T>::deleteFront()
{
	return T();
}

template<class T>
void LinkedList<T>::deleteCurr()
{
}

template<class T>
T & LinkedList<T>::data()
{
	// TODO: 在此处插入 return 语句
}

template<class T>
const T & LinkedList<T>::data() const
{
	// TODO: 在此处插入 return 语句
}

template<class T>
void LinkedList<T>::clear()
{
}

template<class T>
Node<T>* LinkedList<T>::newNode(const T & item, Node<T>* ptrNext)
{
	return nullptr;
}

template<class T>
void LinkedList<T>::freeNode(Node<T>* p)
{
}

template<class T>
void LinkedList<T>::copy(const LinkedList<T>& L)
{
}
