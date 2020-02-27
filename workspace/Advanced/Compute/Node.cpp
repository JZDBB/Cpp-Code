#include "Node.h"


template <class T>
Node<T>::Node(const T &item, Node<T>* next)
{
}

template <class T>
Node<T>::~Node()
{
}

template <class T>
void Node<T>::insertAfter(Node<T> *p) {
	p->next = next; // 先落实后继结点
	next = p;
}
template<class T>
Node<T>* Node<T>::deleteAafter()
{
	Node<T> *temp = next;
	if (next == 0)
		return 0;
	next = temp->next;
	return temp; // 指向删除的结点，防止后续有操作
}

template<class T>
Node<T>* Node<T>::nextNode()
{
	return next;
}

template<class T>
Node<T>* Node<T>::nextNode() const
{
	return next;
}
