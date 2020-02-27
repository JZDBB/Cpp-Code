#pragma once
template <class T>
class Node
{
public:
	T data;

	Node(const T &item, Node<T>* next=0);
	~Node();

	void insertAfter(Node<T> *p);
	Node<T> *deleteAafter();
	Node<T> *nextNode();
	Node<T> *nextNode() const;

private:
	Node<T> *next;
};

